using System;
using System.IO;
using Netca.Pki;


namespace VerifyTimeStamp
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: VerifyTimeStamp infile token");
                return;
            }

            

            byte[] token=new byte[1024*16];
            int len;
            using (FileStream inStream = new FileStream(args[1], FileMode.Open, FileAccess.Read))
            {
                len = inStream.Read(token, 0, token.Length);
            }
            
            using (TimeStamp ts = new TimeStamp(token,0,len, (Certificate)null))
            {
                byte[] hash = HashData(ts.HashAlgorithm, args[0]);
                if (ts.MessageImprint.Length != hash.Length)
                {
                    Console.WriteLine("Hash值不同");
                    return;
                }
                
                for (int i = 0; i < hash.Length; i++)
                {
                    if (ts.MessageImprint[i] != hash[i])
                    {
                        Console.WriteLine("Hash值不同");
                        return;
                    }
                }
                Console.WriteLine("时间戳时间：{0}", ts.GetTime().ToLocalTime());
                using (Certificate cert = ts.GetTsaCertificate())
                {
                    Console.WriteLine("时间戳证书的主体：{0}", cert.Subject);
                }
            }
        }

        static byte[] HashData(int algo, String filename)
        {
            using (Hash hash = new Hash(algo))
            {
                using (FileStream inStream = new FileStream(filename, FileMode.Open, FileAccess.Read))
                {
                    byte[] data = new byte[8192];

                    int len;
                    for (; ; )
                    {
                        len = inStream.Read(data, 0, data.Length);
                        if (len == 0)
                        {
                            break;
                        }
                        hash.Update(data, 0, len);
                    }

                    return hash.Final();

                }
            }
        }

    }
}
