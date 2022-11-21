using System;
using System.IO;
using Netca.Pki;

namespace RSAOaepEnvelopedDataEncrypt
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Usage: RSAOaepEnvelopedDataEncrypt cert infile outfile");
                return;
            }

            using (EnvelopedData env = new EnvelopedData(true))
            {

                env.EncryptAlgorithm = Netca.Pki.Algorithm.EnvelopedDataEncryptAlgorithmAes256Cbc;
                using (Certificate cert = GetCert(args[0]))
                {
                    if (cert.Match("Algorithm='RSA'") == false)
                    {
                        Console.WriteLine("not rsa cert");
                        return;
                    }
                    env.AddEncryptCertificate(cert, 0);
                }
                env.SetAttribute(9, "{ \"mgfAlgo\":3, \"hashAlgo\":16384,\"label\":\"\" }");
                using (FileStream outStream = new FileStream(args[2], FileMode.Create, FileAccess.Write))
                {
                    byte[] outData;
                    outData = env.EncryptInit();
                    if (outData.Length > 0)
                    {
                        outStream.Write(outData, 0, outData.Length);
                    }
                    using (FileStream inStream = new FileStream(args[1], FileMode.Open, FileAccess.Read))
                    {
                        byte[] inData = new byte[8129];
                        int len;

                        for (; ; )
                        {
                            len = inStream.Read(inData, 0, inData.Length);
                            if (len == 0)
                            {
                                break;
                            }
                            outData = env.EncryptUpdate(inData, 0, len);
                            if (outData.Length > 0)
                            {
                                outStream.Write(outData, 0, outData.Length);
                            }
                        }
                        outData = env.EncryptFinal();
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
            byte[] data = new byte[8192];
            int len = inStream.Read(data, 0, data.Length);
            inStream.Close();

            return new Certificate(data, 0, len);
        }
    }
}
