using System;
using System.IO;
using Netca.Pki;

namespace SignFile4
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Usage: SignFile4 cert inFile outFile");
                return;
            }

            using (Certificate cert = GetCert(args[0]))
            {
                using (SignedData s = new SignedData(true))
                {
                    s.IsDetached = false;
                    s.SetSignCertificate(cert, null);
                    int algo = GetSignAlgo(cert);
                    if (algo == -1)
                    {
                        Console.WriteLine("bad cert type");
                        return;
                    }
                    s.SetSignatureAlgorithm(0, algo);

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

        static int GetSignAlgo(Certificate cert)
        {
            if (cert.Match("Algorithm='SM2'"))
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSm3withSm2;
            }
            else if (cert.Match("Algorithm='RSA'"))
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSha256withRsa;
            }
            else if (cert.Match("Algorithm='ECC'"))
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha256;
            }
            else
            {
                return -1;
            }
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
