using System;
using System.IO;
using Netca.Pki;

namespace SignMime
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3 && args.Length != 4)
            {
                Console.WriteLine("Usage: SignMime [-detached] cert infile outfile");
                return;
            }

            bool datched = false;
            int pos = 0;
            if (args.Length == 4)
            {
                if (args[0] != "-detached")
                {
                    Console.WriteLine("Usage: SignMime [-detached] cert infile outfile");
                    return;
                }
                datched = true;
                pos = 1;
            }
            string certFileName = args[pos];
            string inFileName = args[pos+1];
            string outFileName = args[pos+2];
            byte[] outData;
            using (SignedData s = new SignedData(true))
            {
                using (Certificate cert = GetCert(certFileName))
                {
                    s.SetSignCertificate(cert, null);
                }
                
                s.SetSignatureAlgorithm(0, Netca.Pki.Algorithm.SignatureAlgorithmSha256withRsa);

                byte[] inData = GetFileContent(inFileName);

                using (Smime mime = new Smime(inData))
                {
                    using (Smime smime = mime.Sign(s,datched))
                    {
                        smime.AddHeader(0, "MIME-Version:1.0");
                        outData = smime.Encode();
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
