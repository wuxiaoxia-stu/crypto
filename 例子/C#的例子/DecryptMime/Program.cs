using System;
using System.IO;
using Netca.Pki;

namespace DecryptMime
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: DecryptMime infile outfile");
                return;
            }
            using (EnvelopedData env = new EnvelopedData(false))
            {
                byte[] inData = GetFileContent(args[0]);
                byte[] outData;
                using (Smime mime = new Smime(inData))
                {
                    if(mime.IsEncrypt()==false)
                    {
                        Console.WriteLine("not encrypt s/mime");
                        return;
                    }
                    outData=mime.Decrypt(env);
                }
                using (FileStream outStream = new FileStream(args[1], FileMode.Create, FileAccess.Write))
                {
                    outStream.Write(outData, 0, outData.Length);
                }
                using (Certificate cert = env.GetDecryptCertificate())
                {
                    Console.WriteLine(cert.Subject);
                }

            }

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
    }
}
