using System;
using System.IO;
using Netca.Pki;

namespace HmacFile
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Usage: HmacFile hmac-sha1|hmac-sha256|hmac-sm3 key FileName");
                return;
            }

            int algo;
            string algoStr = args[0].ToLower();
            if (algoStr == "hmac-md5")
            {
                algo = Netca.Pki.Algorithm.MacAlgorithmHmacMd5;
            }
            else if (algoStr == "hmac-sha1")
            {
                algo = Netca.Pki.Algorithm.MacAlgorithmHmacSha1;
            }
            else if (algoStr == "hmac-sha224")
            {
                algo = Netca.Pki.Algorithm.MacAlgorithmHmacSha224;
            }
            else if (algoStr == "hmac-sha256")
            {
                algo = Netca.Pki.Algorithm.MacAlgorithmHmacSha256;
            }
            else if (algoStr == "hmac-sha384")
            {
                algo = Netca.Pki.Algorithm.MacAlgorithmHmacSha384;
            }
            else if (algoStr == "hmac-sha512")
            {
                algo = Netca.Pki.Algorithm.MacAlgorithmHmacSha512;
            }
            else if (algoStr == "hmac-sm3")
            {
                algo = Netca.Pki.Algorithm.MacAlgorithmHmacSm3;
            }
            else if (algoStr == "hmac-sha512/224")
            {
                algo = Netca.Pki.Algorithm.MacAlgorithmHmacSha512_224;
            }
            else if (algoStr == "hmac-sha512/256")
            {
                algo = Netca.Pki.Algorithm.MacAlgorithmHmacSha512_256;
            }
            else if (algoStr == "hmac-sha3_224")
            {
                algo = Netca.Pki.Algorithm.MacAlgorithmHmacSha3_224;
            }
            else if (algoStr == "hmac-sha3_256")
            {
                algo = Netca.Pki.Algorithm.MacAlgorithmHmacSha3_256;
            }
            else if (algoStr == "hmac-sha3_384")
            {
                algo = Netca.Pki.Algorithm.MacAlgorithmHmacSha3_384;
            }
            else if (algoStr == "hmac-sha3_512")
            {
                algo = Netca.Pki.Algorithm.MacAlgorithmHmacSha3_512;
            }
            else
            {
                Console.WriteLine("Usage: HmacFile hmac-sha1|hmac-sha256|hmac-sm3 key FileName");
                return;
            }

            using (Mac mac = new Mac(algo, HexDecode(args[1])))
            {
                using (FileStream inStream = new FileStream(args[2], FileMode.Open, FileAccess.Read))
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
                        mac.Update(data, 0, len);
                    }

                    byte[] hmac = mac.Final();
                    Console.WriteLine(BitConverter.ToString(hmac).Replace("-", ""));
                }
            }
        }

        static byte[] HexDecode(string hex)
        {
            if (hex.Length % 2 != 0)
            {
                throw new InvalidDataException();
            }

            byte[] data = new byte[hex.Length/2];
            for (int i = 0, j = 0; i < hex.Length; i += 2, j++)
            {
                data[j] = (byte)Convert.ToChar(Int32.Parse(hex.Substring(i, 2), System.Globalization.NumberStyles.HexNumber));
            }
            return data;
        }
    }
}
