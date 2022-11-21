using System;
using System.IO;
using Netca.Pki;

namespace SM2EnvelopedDataEncrypt
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Usage: SM2EnvelopedDataEncrypt cert infile outfile");
                return;
            }

            using (EnvelopedData env = new EnvelopedData(true))
            {

                env.EncryptAlgorithm = Netca.Pki.Algorithm.EnvelopedDataEncryptAlgorithmAes256Cbc;
                using (Certificate cert = GetCert(args[0]))
                {
                    if (cert.Match("Algorithm='SM2'")==false)
                    {
                        Console.WriteLine("not sm2 cert");
                        return;
                    }
                    env.AddEncryptCertificate(cert, 0);
                }
                env.SetUseSM2Q7();

                using (FileStream outStream = new FileStream(args[2], FileMode.Create, FileAccess.Write))
                {
                    byte[] outData;
                    byte[] inData = GetFileContent(args[1]);
                    outData = env.Encrypt(inData);
                    outStream.Write(outData, 0, outData.Length);

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

        static byte[] GetFileContent(String fileName)
        {
            FileInfo f = new FileInfo(fileName);
            byte[] data = new byte[f.Length];

            using (FileStream inStream = new FileStream(fileName, FileMode.Open, FileAccess.Read))
            {
                int len;
                int pos = 0;
                for (; ; )
                {
                    len = inStream.Read(data, pos, data.Length - pos);
                    if (len == 0)
                    {
                        if (pos != data.Length)
                        {
                            throw new Exception("read file fail");
                        }
                        break;
                    }
                    pos += len;
                }
            }

            return data;
        }
    }
}
