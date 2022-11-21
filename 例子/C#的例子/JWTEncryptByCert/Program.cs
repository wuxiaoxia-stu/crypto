using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace JWTEncryptByCert
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length <2 || args.Length % 2 != 1)
            {
                Console.WriteLine("Usage: JWTEncryptByCert certFileName claimName1 claimValue1 ... claimNameN claimValueN");
                return;
            }
            string certFileName = args[0];
            using (Jwt jwtObj = new Jwt(Jwt.JWEType))
            {
                for (int i = 1; i < args.Length; i += 2)
                {
                    jwtObj.SetClaim(args[i], args[i + 1]);
                }
                using (Certificate cert = GetCert(certFileName))
                {
                    int cekAlgo = GetCEKAlgo(cert);
                    if (cekAlgo == -1)
                    {
                        Console.WriteLine("bad cert");
                        return;
                    }
                   

                    int kekAlgo = GeKEKAlgo(cert);
                    if (cekAlgo == -1)
                    {
                        Console.WriteLine("bad cert");
                        return;
                    }
                    string outData = jwtObj.EncryptByCert(cekAlgo, cert, kekAlgo, Jwt.CertIdTypeX5T_S256);
                    Console.WriteLine(outData);
                }
                
            }
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

        private static int GetCEKAlgo(Certificate cert)
        {
            if (cert.Match("Algorithm='RSA'"))
            {
                return Algorithm.JWEAlgorithmAes256Gcm;
            }
            else if (cert.Match("Algorithm='SM2'"))
            {
                return Algorithm.JWEAlgorithmSm4CbcHmacSm3;
            }
            else
            {
                return -1;
            }
        }

        private static int GeKEKAlgo(Certificate cert)
        {
            if (cert.Match("Algorithm='RSA'"))
            {
                return Algorithm.JWEAlgorithmRsa1_5;
            }
            else if (cert.Match("Algorithm='SM2'"))
            {
                return Algorithm.JWEAlgorithmSm2;
            }
            else
            {
                return -1;
            }
        }
    }
}
