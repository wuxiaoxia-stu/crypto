using System;
using System.IO;
using Netca.Pki;

namespace RSADecrypt
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Usage: RSADecrypt cert cipher clear");
                return;
            }
            using (Certificate cert = GetCert(args[0]))
            {
                byte[] data;
                int len;
                using (FileStream inStream = new FileStream(args[1], FileMode.Open, FileAccess.Read))
                {
                    data = new byte[8192];
                    len = inStream.Read(data, 0, data.Length);
                }

               byte[] clear = cert.Decrypt(Netca.Pki.Algorithm.EncryptAlgorithmRsaPkcs1V1_5Enc,
                    data,0,len, Certificate.SearchKeyPairFlagDevice, null);

                using (FileStream outStream = new FileStream(args[2], FileMode.Create, FileAccess.Write))
                {
                    outStream.Write(clear, 0, clear.Length);
                }

                Console.WriteLine("Success");
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
