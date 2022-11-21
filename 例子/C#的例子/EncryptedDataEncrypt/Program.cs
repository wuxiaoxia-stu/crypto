using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace EncryptedDataEncrypt
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 5)
            {
                Console.WriteLine("Usage: EncryptedDataEncrypt pwd aes-128|sm4 sha256|sm3 clearFile cipherFile");
                return;
            }
            string pwd = args[0];
            string encAlgoStr = args[1].ToLower();
            int encAlgo = GetEncAlgo(encAlgoStr);
            if (encAlgo == -1)
            {
                Console.WriteLine("不支持的加密算法");
                return;
            }
            string hashAlgoStr = args[2].ToLower();
            int hashAlgo = GetHashAlgo(hashAlgoStr);
            if (hashAlgo == -1)
            {
                Console.WriteLine("不支持的Hash算法");
                return;
            }
            byte[] clear = GetFileContent(args[3]);
            byte[] cipher=EncryptedData.EncryptByPkcs5Pwd(0, encAlgo, hashAlgo, 32, 4096, Encoding.UTF8.GetBytes(pwd), clear);
            using (FileStream outStream = new FileStream(args[4], FileMode.Create, FileAccess.Write))
            {
                outStream.Write(cipher, 0, cipher.Length);
            }
            Console.WriteLine("Success");
        }

        private static int GetHashAlgo(string hashAlgoStr)
        {
            if (hashAlgoStr == "sha1" || hashAlgoStr == "sha-1")
            {
                return Algorithm.HashAlgorithmSha1;
            }
            else if (hashAlgoStr == "sha224" || hashAlgoStr == "sha-224")
            {
                return Algorithm.HashAlgorithmSha224;
            }
            else if (hashAlgoStr == "sha256" || hashAlgoStr == "sha-256")
            {
                return Algorithm.HashAlgorithmSha256;
            }
            else if (hashAlgoStr == "sha384" || hashAlgoStr == "sha-384")
            {
                return Algorithm.HashAlgorithmSha384;
            }
            else if (hashAlgoStr == "sha512" || hashAlgoStr == "sha-512")
            {
                return Algorithm.HashAlgorithmSha512;
            }
            else if (hashAlgoStr == "sha512/224" || hashAlgoStr == "sha-512/224")
            {
                return Algorithm.HashAlgorithmSha512_224;
            }
            else if (hashAlgoStr == "sha512/256" || hashAlgoStr == "sha-512/256")
            {
                return Algorithm.HashAlgorithmSha512_256;
            }
            else if (hashAlgoStr == "sha3-224")
            {
                return Algorithm.HashAlgorithmSha3_224;
            }
            else if (hashAlgoStr == "sha3-256")
            {
                return Algorithm.HashAlgorithmSha3_256;
            }
            else if (hashAlgoStr == "sha3-384")
            {
                return Algorithm.HashAlgorithmSha3_384;
            }
            else if (hashAlgoStr == "sha3-512")
            {
                return Algorithm.HashAlgorithmSha3_512;
            }
            else
            {
                return -1;
            }
        }

        private static int GetEncAlgo(string encAlgoStr)
        {
            if(encAlgoStr=="3des")
            {
                return Algorithm.EncryptedDataAlgorithm3desCbc;
            }
            else if(encAlgoStr=="aes-128")
            {
                return Algorithm.EncryptedDataAlgorithmAes128Cbc;
            }
            else if (encAlgoStr == "aes-192")
            {
                return Algorithm.EncryptedDataAlgorithmAes192Cbc;
            }
            else if (encAlgoStr == "aes-256")
            {
                return Algorithm.EncryptedDataAlgorithmAes256Cbc;
            }
            else if (encAlgoStr == "sm4")
            {
                return Algorithm.EncryptedDataAlgorithmSm4Cbc;
            }
            else
            {
                return -1;
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
