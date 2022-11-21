using System;
using System.IO;
using Netca.Pki;

namespace GetTimeStamp
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 4)
            {
                Console.WriteLine("Usage: GetTimeStamp url hashAlgo infile token");
                return;
            }

            
            using (TimeStamp ts = new TimeStamp())
            {
                ts.TsaURL = new Uri(args[0]);

                int algo = GetHashAlgo(args[1]);
                if (algo == -1)
                {
                    Console.WriteLine("bad hash algo");
                    return;
                }
                ts.HashAlgorithm = algo;
                ts.MessageImprint = HashData(algo, args[2]);
                int status = ts.GetResponse();
                if (status != TimeStamp.TimeStampRespStatusGranted
                    && status != TimeStamp.TimeStampRespStatusGrantedWithMods)
                {
                    Console.WriteLine("获取TSA响应失败({0})",status);
                    return;
                }

                DateTime tsaTime=ts.GetTime();
                Console.WriteLine("时间戳时间：{0}", tsaTime.ToLocalTime());
                Console.WriteLine("时间戳时间毫秒部分：{0}", tsaTime.Millisecond);
                using (Certificate cert = ts.GetTsaCertificate())
                {
                    Console.WriteLine("时间戳证书的主体：{0}", cert.Subject);
                }

                using (FileStream outStream = new FileStream(args[3], FileMode.Create, FileAccess.Write))
                {
                    byte[] token = ts.Token;
                    outStream.Write(token, 0, token.Length);
                }

            }

        }

        static byte[] HashData(int algo,String filename)
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

        static int GetHashAlgo(string name)
        {
            name = name.ToLower();
            if (name == "md5")
            {
                return Netca.Pki.Algorithm.HashAlgorithmMd5;
            }
            else if (name == "sha1" || name == "sha-1")
            {
                return Netca.Pki.Algorithm.HashAlgorithmSha1;
            }
            else if (name == "sha224" || name == "sha-224")
            {
                return Netca.Pki.Algorithm.HashAlgorithmSha224;
            }
            else if (name == "sha256" || name == "sha-256")
            {
                return Netca.Pki.Algorithm.HashAlgorithmSha256;
            }
            else if (name == "sha384" || name == "sha-384")
            {
                return Netca.Pki.Algorithm.HashAlgorithmSha384;
            }
            else if (name == "sha512" || name == "sha-512")
            {
                return Netca.Pki.Algorithm.HashAlgorithmSha512;
            }
            else if (name == "sm3")
            {
                return Netca.Pki.Algorithm.HashAlgorithmSm3;
            }
            else if (name == "sha512/224" || name == "sha-512/224")
            {
                return  Netca.Pki.Algorithm.HashAlgorithmSha512_224;
            }
            else if (name == "sha512/256" || name == "sha-512/256")
            {
                return Netca.Pki.Algorithm.HashAlgorithmSha512_256;
            }
            else if (name == "sha3_224" || name == "sha3-224")
            {
                return Netca.Pki.Algorithm.HashAlgorithmSha3_224;
            }
            else if (name == "sha3_256" || name == "sha3-256")
            {
                return Netca.Pki.Algorithm.HashAlgorithmSha3_256;
            }
            else if (name == "sha3_384" || name == "sha3-384")
            {
                return Netca.Pki.Algorithm.HashAlgorithmSha3_384;
            }
            else if (name == "sha3_512" || name == "sha3-512")
            {
                return Netca.Pki.Algorithm.HashAlgorithmSha3_512;
            }
            else
            {
                return -1;
            }
        }
    }
}
