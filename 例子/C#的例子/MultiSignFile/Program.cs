using System;
using System.IO;
using Netca.Pki;

namespace MultiSignFile
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Usage: MultiSignFile oldsign cert newFile");
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

                int count = s.SignatureCount;
                using (Certificate cert = GetCert(args[1]))
                {
                    s.SetSignCertificate(cert, null);
                    s.SetSignatureAlgorithm(count, Netca.Pki.Algorithm.SignatureAlgorithmSha1withRsa);
                    outData = s.CoSign();
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
