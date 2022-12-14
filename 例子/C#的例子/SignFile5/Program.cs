using System;
using System.IO;
using Netca.Pki;

namespace SignFile5
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Usage: SignFile5 cert inFile outFile");
                return;
            }

            using (Certificate cert = GetCert(args[0]))
            {
                using (SignedData s = new SignedData(true))
                {
                    s.IsDetached = false;

                    s.SetSignCallback(SignHashCallback);

                    s.SetSignCertificate(cert, null);
                    s.SetSignatureAlgorithm(0, GetSignAlgorithm(cert));

                    byte[] outData = s.SignInit();
                    using (FileStream outStream = new FileStream(args[2], FileMode.Create, FileAccess.Write))
                    {
                        outStream.Write(outData, 0, outData.Length);

                        using (FileStream inStream = new FileStream(args[1], FileMode.Open, FileAccess.Read))
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

        private static Certificate GetCert(String fileName)
        {
            FileStream inStream = new FileStream(fileName, FileMode.Open, FileAccess.Read);
            byte[] data = new byte[8129];
            int len = inStream.Read(data, 0, data.Length);
            inStream.Close();

            return new Certificate(data, 0, len);
        }

        private static int GetSignAlgorithm(Certificate cert)
        { 
            if(cert.Match("Algorithm='RSA'"))
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSha256withRsa;
            }
            else if (cert.Match("Algorithm='SM2'"))
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSm3withSm2;
            }
            else if (cert.Match("Algorithm='ECC'"))
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha256;
            }
            else
            {
                throw new Exception("不支持的证书");
            }
        }
        private static byte[] SignHashCallback(Certificate cert, int algo, object param, byte[] hash)
        {
            
            KeyPair keypair = cert.GetKeyPair(Certificate.SearchKeyPairFlagDevice, KeyPair.KeyPairTypeSignature, null);
            if (keypair == null)
            {
                throw new Exception("没有私钥");
            }
            using (keypair)
            {
                if (algo == Algorithm.SignatureAlgorithmRsaPss)
                {
                    PSSParam pss = (PSSParam)param;
                    return Signature.RSAPSSSignHash(keypair, pss.mgfalgo, pss.saltlen, pss.hashalgo, hash);
                }
                else
                {
                    return Signature.SignHash(keypair, algo, hash);
                }
            }
            
        }

    }
}
