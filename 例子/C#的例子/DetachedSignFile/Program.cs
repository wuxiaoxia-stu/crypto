using System;
using System.IO;
using Netca.Pki;

namespace DetachedSignFile
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Usage: DetachedSignFile cert inFile outFile");
                return;
            }

            using (Certificate cert = GetCert(args[0]))
            {
                using (SignedData s = new SignedData(true))
                {
                    s.IsDetached = true;
                    s.SetSignCertificate(cert, null);
                    s.SetSignatureAlgorithm(0, Netca.Pki.Algorithm.SignatureAlgorithmSha256withRsa);

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
