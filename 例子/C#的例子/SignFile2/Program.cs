using System;
using System.IO;
using Netca.Pki;

/* 用于得安加密机 */
namespace SignFile2
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 4)
            {
                Console.WriteLine("Usage: SignFile cert pwd inFile outFile");
                return;
            }
            KeyPair keypair;
            using (Certificate cert = GetCert(args[0]))
            {
                keypair = cert.GetKeyPair(Certificate.SearchKeyPairFlagDevice, Certificate.CertificatePurposeSign, args[1]);
                if (keypair == null)
                {
                    Console.WriteLine("No KeyPair");
                    return;
                }
                /* 证书中会缓存密钥对，因此直接把获取到的keypair释放，减少其引用计数  */
                keypair.Dispose();

                using (SignedData s = new SignedData(true))
                {
                    s.IsDetached = false;
                    s.SetSignCertificate(cert, null);
                    s.SetSignatureAlgorithm(0, Netca.Pki.Algorithm.SignatureAlgorithmSha256withRsa);

                    byte[] outData = s.SignInit();
                    using (FileStream outStream = new FileStream(args[3], FileMode.Create, FileAccess.Write))
                    {
                        outStream.Write(outData, 0, outData.Length);

                        using (FileStream inStream = new FileStream(args[2], FileMode.Open, FileAccess.Read))
                        {
                            byte[] inData = new byte[8192];

                            int len;
                            for (; ; )
                            {
                                len = inStream.Read(inData, 0, inData.Length);
                                if (len == 0)
                                {
                                    break;
                                }

                                outData = s.SignUpdate(inData, 0, len);
                                if (outData.Length > 0)
                                {
                                    outStream.Write(outData, 0, outData.Length);
                                }
                            }
                        }

                        outData = s.SignFinal();
                        if (outData.Length > 0)
                        {
                            outStream.Write(outData, 0, outData.Length);
                        }
                    }
                }
            }

            Console.WriteLine("Success");
        }

        static Certificate GetCert(String fileName)
        {
            FileStream inStream = new FileStream(fileName, FileMode.Open, FileAccess.Read);
            byte[] data = new byte[8129];
            int len = inStream.Read(data, 0, data.Length);
            inStream.Close();

            return new Certificate(data, 0, len);
        }
    }
}
