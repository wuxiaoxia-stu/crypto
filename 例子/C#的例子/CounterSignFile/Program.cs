using System;
using System.IO;
using Netca.Pki;

namespace CounterSignFile
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Usage: CounterSignFile oldsign cert newFile");
                return;
            }
            byte[] outData;
            using (SignedData s = new SignedData(false))
            {
                s.SetMultipleSign();
                s.VerifyInit();
                
                using (FileStream inStream = new FileStream(args[0], FileMode.Open, FileAccess.Read))
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
                        s.VerifyUpdate(inData, 0, len);
                    }
                }
                s.VerifyFinal();

                
                using (Certificate cert = GetCert(args[1]))
                {
                    outData = s.Countersign(0, Netca.Pki.Algorithm.SignatureAlgorithmSha1withRsa, cert, null);
                }
            }

            using (FileStream outStream = new FileStream(args[2], FileMode.Create, FileAccess.Write))
            {
                outStream.Write(outData, 0, outData.Length);
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
