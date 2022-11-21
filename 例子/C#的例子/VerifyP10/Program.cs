using System;
using System.IO;
using Netca.Pki;

namespace VerifyP10
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 1)
            {
                Console.WriteLine("Usage: VerifyP10 p10file");
                return;
            }

            byte[] data=new byte[8192];
            int len;
            using (FileStream inStream = new FileStream(args[0], FileMode.Open, FileAccess.Read))
            {
                len = inStream.Read(data, 0, data.Length);
            }

            PublicKey pubkey;
            using (CertReq p10 = new CertReq(data,0,len))
            {
                if (p10.Verify()==false)
                {
                    Console.WriteLine("验证证书请求失败");
                    return;
                }
                Console.WriteLine("验证证书请求成功");
                Console.WriteLine("主体：{0}",p10.Subject);

                if (p10.C != null)
                {
                    Console.WriteLine("主体C: {0}", p10.C);
                }

                if (p10.ST != null)
                {
                    Console.WriteLine("主体ST: {0}", p10.ST);
                }

                if (p10.L != null)
                {
                    Console.WriteLine("主体L: {0}", p10.L);
                }

                if (p10.O != null)
                {
                    Console.WriteLine("主体O: {0}", p10.O);
                   
                }

                if (p10.OU != null)
                {
                    for (int i = p10.OU.Length - 1; i >= 0; i--)
                    {
                        Console.WriteLine("主体OU: {0}", p10.OU[i]);
                    }
                }

                if (p10.CN != null)
                {
                    for (int i = p10.CN.Length - 1; i >= 0; i--)
                    {
                        Console.WriteLine("主体CN: {0}", p10.CN[i]);
                    }
                }

                if (p10.Email != null)
                {
                    Console.WriteLine("主体Email: {0}", p10.Email);
                }

                PrintSignAlgo(p10.SignAlgo);

                pubkey=p10.GetPublicKey();
                
            }

            using (pubkey)
            {
                PrintPublicKeyAlgo(pubkey.Algorithm);
                Console.WriteLine("公钥长度: {0}位", pubkey.KeyBits);
            }
        }

        static void PrintSignAlgo(int algo)
        {
            if (algo == Netca.Pki.Algorithm.SignatureAlgorithmDsawithSha1)
            {
                Console.WriteLine("签名算法: DSAWITHSHA1");
            }
            else if (algo == Netca.Pki.Algorithm.SignatureAlgorithmDsawithSha224)
            {
                Console.WriteLine("签名算法: DSAWITHSHA224");
            }
            else if (algo == Netca.Pki.Algorithm.SignatureAlgorithmDsawithSha256)
            {
                Console.WriteLine("签名算法: DSAWITHSHA256");
            }
            else if (algo == Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha1)
            {
                Console.WriteLine("签名算法: ECDSAWITHSHA1");
            }
            else if (algo == Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha224)
            {
                Console.WriteLine("签名算法: ECDSAWITHSHA224");
            }
            else if (algo == Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha256)
            {
                Console.WriteLine("签名算法: ECDSAWITHSHA256");
            }
            else if (algo == Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha384)
            {
                Console.WriteLine("签名算法: ECDSAWITHSHA384");
            }
            else if (algo == Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha512)
            {
                Console.WriteLine("签名算法: ECDSAWITHSHA512");
            }
            else if (algo == Netca.Pki.Algorithm.SignatureAlgorithmMd5withRsa)
            {
                Console.WriteLine("签名算法: MD5WITHRSA");
            }
            else if (algo == Netca.Pki.Algorithm.SignatureAlgorithmSha1withRsa)
            {
                Console.WriteLine("签名算法: SHA1WITHRSA");
            }
            else if (algo == Netca.Pki.Algorithm.SignatureAlgorithmSha224withRsa)
            {
                Console.WriteLine("签名算法: SHA224WITHRSA");
            }
            else if (algo == Netca.Pki.Algorithm.SignatureAlgorithmSha256withRsa)
            {
                Console.WriteLine("签名算法: SHA256WITHRSA");
            }
            else if (algo == Netca.Pki.Algorithm.SignatureAlgorithmSha384withRsa)
            {
                Console.WriteLine("签名算法: SHA384WITHRSA");
            }
            else if (algo == Netca.Pki.Algorithm.SignatureAlgorithmSha512withRsa)
            {
                Console.WriteLine("签名算法: SHA512WITHRSA");
            }
            else if (algo == Netca.Pki.Algorithm.SignatureAlgorithmSm3withSm2)
            {
                Console.WriteLine("签名算法: SM3WITHSM2");
            }
            else
            {
                Console.WriteLine("签名算法: 未知签名算法({0})", algo);
            }

        }

        static void PrintPublicKeyAlgo(int algo)
        {
            if (algo == Netca.Pki.Algorithm.PublicKeyAlgorithmDh)
            {
                Console.WriteLine("公钥算法: DH");
            }
            else if (algo == Netca.Pki.Algorithm.PublicKeyAlgorithmDsa)
            {
                Console.WriteLine("公钥算法: DSA");
            }
            else if (algo == Netca.Pki.Algorithm.PublicKeyAlgorithmEcc)
            {
                Console.WriteLine("公钥算法: ECC");
            }
            else if (algo == Netca.Pki.Algorithm.PublicKeyAlgorithmRsa)
            {
                Console.WriteLine("公钥算法: RSA");
            }
            else
            {
                Console.WriteLine("公钥算法: 未知公钥算法({0})", algo);
            }
        }

    }
}
