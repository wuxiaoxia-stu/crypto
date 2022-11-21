using System;
using System.IO;
using Netca.Pki;

/* 用于得安加密机 */
namespace EnvelopedDataDecrypt2
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 4)
            {
                Console.WriteLine("Usage: EnvelopedDataDecrypt cert pwd infile outfile");
                return;
            }
            Certificate cert = GetCert(args[0]);
            KeyPair keypair;
            keypair = cert.GetKeyPair(Certificate.SearchKeyPairFlagDevice, Certificate.CertificatePurposeEncrypt, args[1]);
            if (keypair == null)
            {
                Console.WriteLine("No KeyPair");
                return;
            }
            /* 证书中会缓存密钥对，因此直接把获取到的keypair释放，减少其引用计数  */
            keypair.Dispose();

            using (EnvelopedData env = new EnvelopedData(false))
            {
                env.AddDecryptCertificate(cert);
                env.DecryptInit();
                using (FileStream inStream = new FileStream(args[2], FileMode.Open, FileAccess.Read))
                {
                    byte[] inData = new byte[8192];
                    int len;
                    using (FileStream outStream = new FileStream(args[3], FileMode.Create, FileAccess.Write))
                    {
                        byte[] outData;
                        for (; ; )
                        {
                            len = inStream.Read(inData, 0, inData.Length);
                            if (len == 0)
                            {
                                break;
                            }
                            outData = env.DecryptUpdate(inData, 0, len);
                            if (outData.Length > 0)
                            {
                                outStream.Write(outData, 0, outData.Length);
                            }
                        }

                    }
                    env.DecryptFinal();

                    using(Certificate cert2 = env.GetDecryptCertificate())
                    {
                        Console.WriteLine(cert2.Subject);
                    }
                    
                }
            }
            cert.Dispose();
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
