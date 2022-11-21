using System;
using System.IO;
using Netca.Pki;

namespace EncryptMime
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Usage: EncryptMime cert infile outfile");
                return;
            }
            string certFileName = args[0];
            string inFileName = args[1];
            string outFileName = args[2];
            byte[] outData;
            using (EnvelopedData env = new EnvelopedData(true))
            {
                env.EncryptAlgorithm = Netca.Pki.Algorithm.EnvelopedDataEncryptAlgorithmAes128Cbc;
                using (Certificate cert = GetCert(certFileName))
                {
                    env.AddEncryptCertificate(cert, 0);
                }
                byte[] inData = GetFileContent(inFileName);
                
                using (Smime mime = new Smime(inData))
                {
                    using (Smime smime = mime.Encrypt(env))
                    {
                        outData=smime.Encode();
                    }
                }
            }
            using (FileStream outStream = new FileStream(outFileName, FileMode.Create, FileAccess.Write))
            {
                 outStream.Write(outData, 0, outData.Length);
            }
            Console.WriteLine("Success");
  

        }

        static byte[] GetFileContent(string fileName)
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

        static Certificate GetCert(string fileName)
        {
            return new Certificate(GetFileContent(fileName));
        }
    }
}
