using System;
using System.IO;
using Netca.Pki;

namespace SM2SignFile
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Usage: SM2SignFile cert inFile outFile");
                return;
            }

            using (Certificate cert = GetCert(args[0]))
            {
                using (SignedData s = new SignedData(true))
                {
                    s.IsDetached = false;
                    s.SetSignCertificate(cert, null);
                    if (cert.Match("Algorithm='SM2'") == false)
                    {
                        Console.WriteLine("not sm2 cert");
                        return;
                    }
                    int algo = Netca.Pki.Algorithm.SignatureAlgorithmSm3withSm2;
                    s.SetSignatureAlgorithm(0, algo);
                    s.SetSM2Q7(0);
                    byte[] inData = GetFileContent(args[1]);
                    byte[] outData = s.Sign(inData);
                    using (FileStream outStream = new FileStream(args[2], FileMode.Create, FileAccess.Write))
                    {
                        outStream.Write(outData, 0, outData.Length);
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
