using System;
using System.IO;
using Netca.Pki;

namespace BuildCertPath
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 1)
            {
                Console.WriteLine("Usage: BuildCertPath cert");
                return;
            }
            Certificate cert = GetCert(args[0]);

            using (cert)
            {
                Certificate[] certs = cert.BuildCertPath();
                for (int i = 0; i < certs.Length; i++)
                {
                    Console.WriteLine(certs[i].Subject);
                    certs[i].Dispose();
                }
            }
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
