using System;
using Netca.Pki;
using System.IO;

namespace AttachSESealTimeStamp
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 4)
            {
                Console.WriteLine("Usage: AttachSESealTimeStamp oldSealFileName tsaUrl hashAlgo newSealFileName");
                return;
            }
            string oldSealFileName = args[0];
            string tsaUrl = args[1];
            string algoStr = args[2].ToLower();
            string newSealFileName = args[3];
            int algo;
            if (algoStr == "md5")
            {
                algo = Netca.Pki.Algorithm.HashAlgorithmMd5;
            }
            else if (algoStr == "sha1" || algoStr == "sha-1")
            {
                algo = Netca.Pki.Algorithm.HashAlgorithmSha1;
            }
            else if (algoStr == "sha224" || algoStr == "sha-224")
            {
                algo = Netca.Pki.Algorithm.HashAlgorithmSha224;
            }
            else if (algoStr == "sha256" || algoStr == "sha-256")
            {
                algo = Netca.Pki.Algorithm.HashAlgorithmSha256;
            }
            else if (algoStr == "sha384" || algoStr == "sha-384")
            {
                algo = Netca.Pki.Algorithm.HashAlgorithmSha384;
            }
            else if (algoStr == "sha512" || algoStr == "sha-512")
            {
                algo = Netca.Pki.Algorithm.HashAlgorithmSha512;
            }
            else if (algoStr == "sm3")
            {
                algo = Netca.Pki.Algorithm.HashAlgorithmSm3;
            }
            else if (algoStr == "sha512/224" || algoStr == "sha-512/224")
            {
                algo = Netca.Pki.Algorithm.HashAlgorithmSha512_224;
            }
            else if (algoStr == "sha512/256" || algoStr == "sha-512/256")
            {
                algo = Netca.Pki.Algorithm.HashAlgorithmSha512_256;
            }
            else if (algoStr == "sha3_224" || algoStr == "sha3-224")
            {
                algo = Netca.Pki.Algorithm.HashAlgorithmSha3_224;
            }
            else if (algoStr == "sha3_256" || algoStr == "sha3-256")
            {
                algo = Netca.Pki.Algorithm.HashAlgorithmSha3_256;
            }
            else if (algoStr == "sha3_384" || algoStr == "sha3-384")
            {
                algo = Netca.Pki.Algorithm.HashAlgorithmSha3_384;
            }
            else if (algoStr == "sha3_512" || algoStr == "sha3-512")
            {
                algo = Netca.Pki.Algorithm.HashAlgorithmSha3_512;
            }
            else
            {
                Console.WriteLine("不支持的Hash算法");
                return;
            }

            byte[] sealData = GetFileContent(oldSealFileName);
            using (SESeal seal = new SESeal(sealData))
            {
                if (seal.Verify() == false)
                {
                    Console.WriteLine("验证电子签章失败");
                    return;
                }

                if (seal.Format != SESeal.FormatGbt38540)
                {
                    Console.WriteLine("不是GB/T 38540的电子签章不支持时间戳");
                    return;
                }

                byte[] newSealData=seal.AttachTimeStamp(algo, tsaUrl);
                using (FileStream outStream = new FileStream(newSealFileName, FileMode.Create, FileAccess.Write))
                {
                    outStream.Write(newSealData, 0, newSealData.Length);
                }

                using (TimeStamp timeStamp = seal.GetTimeStampObject())
                {
                    using (Certificate tsaCert = timeStamp.GetTsaCertificate())
                    {
                        Console.WriteLine("时间戳证书的主体:{0}", tsaCert.Subject);
                    }
                    Console.WriteLine("时间戳时间:{0}", timeStamp.GetTime().ToLocalTime());
                            
                }

                
            }
        }

        private static byte[] GetFileContent(String fileName)
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
