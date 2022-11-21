using System;
using System.IO;
using Netca.Pki;

namespace HashFile
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: HashFile sha1|sha256|sm3 FileName");
                return;
            }

            int algo;
            string algoStr = args[0].ToLower();
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
                Console.WriteLine("Usage: HashFile sha1|sha256|sm3 FileName");
                return;
            }

            using(Hash hash = new Hash(algo))
            {
                using(FileStream inStream = new FileStream(args[1], FileMode.Open, FileAccess.Read))
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

                    byte[] md = hash.Final();
                    Console.WriteLine(BitConverter.ToString(md).Replace("-", ""));
                }
            }
        }
    }
}
