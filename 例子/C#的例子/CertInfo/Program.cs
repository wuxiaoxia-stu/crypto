using System;
using System.IO;
using Netca.Pki;
using System.Collections;

namespace CertInfo
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 1)
            {
                Console.WriteLine("Usage: CertInfo cert");
                return;
            }

            using (Certificate cert = GetCert(args[0]))
            {
                PrintVersion(cert.Version);

                Console.WriteLine("序列号: {0}", BitConverter.ToString(cert.SerialNumber).Replace("-", ""));

                PrintSignAlgo(cert.SignatureAlgorithm);

                Console.WriteLine("颁发者: {0}", cert.Issuer);

                if (cert.IssuerC != null)
                {
                    Console.WriteLine("颁发者C: {0}", cert.IssuerC);
                }

                if (cert.IssuerST != null)
                {
                    for (int i = cert.IssuerST.Length-1; i >=0; i--)
                    {
                        Console.WriteLine("颁发者ST: {0}", cert.IssuerST[i]);
                    }
                }

                if (cert.IssuerL != null)
                {
                    for (int i = cert.IssuerL.Length - 1; i >= 0; i--)
                    {
                        Console.WriteLine("颁发者L: {0}", cert.IssuerL[i]);
                    }
                }

                if (cert.IssuerO != null)
                {
                    for (int i = cert.IssuerO.Length - 1; i >= 0; i--)
                    {
                        Console.WriteLine("颁发者O: {0}", cert.IssuerO[i]);
                    }
                }

                if (cert.IssuerOU != null)
                {
                    for (int i = cert.IssuerOU.Length - 1; i >= 0; i--)
                    {
                        Console.WriteLine("颁发者OU: {0}", cert.IssuerOU[i]);
                    }
                }

                if (cert.IssuerCN != null)
                {
                    for (int i = cert.IssuerCN.Length - 1; i >= 0; i--)
                    {
                        Console.WriteLine("颁发者CN: {0}", cert.IssuerCN[i]);
                    }
                }

                if (cert.IssuerEmail != null)
                {
                    for (int i = cert.IssuerEmail.Length - 1; i >= 0; i--)
                    {
                        Console.WriteLine("颁发者Email: {0}", cert.IssuerEmail[i]);
                    }
                }

                Console.WriteLine("有效期开始时间: {0}", cert.ValidityStart.ToLocalTime());

                Console.WriteLine("有效期结束时间: {0}", cert.ValidityEnd.ToLocalTime());

                Console.WriteLine("主体: {0}", cert.Subject);

                if (cert.SubjectC != null)
                {
                    Console.WriteLine("主体C: {0}", cert.SubjectC);
                }

                if (cert.SubjectST != null)
                {
                    for (int i = cert.SubjectST.Length - 1; i >= 0; i--)
                    {
                        Console.WriteLine("主体ST: {0}", cert.SubjectST[i]);
                    }
                }

                if (cert.SubjectL != null)
                {
                    for (int i = cert.SubjectL.Length - 1; i >= 0; i--)
                    {
                        Console.WriteLine("主体L: {0}", cert.SubjectL[i]);
                    }
                }

                if (cert.SubjectO != null)
                {
                    for (int i = cert.SubjectO.Length - 1; i >= 0; i--)
                    {
                        Console.WriteLine("主体O: {0}", cert.SubjectO[i]);
                    }
                }

                if (cert.SubjectOU != null)
                {
                    for (int i = cert.SubjectOU.Length - 1; i >= 0; i--)
                    {
                        Console.WriteLine("主体OU: {0}", cert.SubjectOU[i]);
                    }
                }

                if (cert.SubjectCN != null)
                {
                    for (int i = cert.SubjectCN.Length - 1; i >= 0; i--)
                    {
                        Console.WriteLine("主体CN: {0}", cert.SubjectCN[i]);
                    }
                }

                if (cert.SubjectEmail != null)
                {
                    for (int i = cert.SubjectEmail.Length - 1; i >= 0; i--)
                    {
                        Console.WriteLine("主体Email: {0}", cert.SubjectEmail[i]);
                    }
                }

                PrintPublicKeyAlgo(cert.PublicKeyAlgorithm);
                Console.WriteLine("公钥长度: {0}位", cert.PublicKeyBits);

                PrintKeyUsage(cert.KeyUsage);
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

        static void PrintVersion(int version)
        {
            if (version == Certificate.CertificateVersionV1)
            {
                Console.WriteLine("版本号: V1");
            }
            else if (version == Certificate.CertificateVersionV2)
            {
                Console.WriteLine("版本号: V2");
            }
            else if (version == Certificate.CertificateVersionV3)
            {
                Console.WriteLine("版本号: V3");
            }
            else
            {
                Console.WriteLine("版本号: 未知的版本号({0})",version);
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
                Console.WriteLine("签名算法: 未知签名算法({0})",algo);
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

        static void PrintKeyUsage(BitArray ku)
        { 
            if(ku[9])
            {
                Console.WriteLine("密钥用法: 没有密钥用法");
                return;
            }

            String kustr = "";
            bool first = true;

            if (ku[Certificate.KeyUsageDigitalSignature])
            {
                if (first)
                {
                    kustr += "数字签名";
                }
                else
                {
                    kustr += ",数字签名";
                }
                first = false;
            }

            if (ku[Certificate.KeyUsageNonrepudiation])
            {
                if (first)
                {
                    kustr += "不可否认";
                }
                else
                {
                    kustr += ",不可否认";
                }
                first = false;
            }

            if (ku[Certificate.KeyUsageKeyEncipherment])
            {
                if (first)
                {
                    kustr += "加密密钥";
                }
                else
                {
                    kustr += ",加密密钥";
                }
                first = false;
            }

            if (ku[Certificate.KeyUsageDataEncipherment])
            {
                if (first)
                {
                    kustr += "加密数据";
                }
                else
                {
                    kustr += ",加密数据";
                }
                first = false;
            }

            if (ku[Certificate.KeyUsageKeyAgreement])
            {
                if (first)
                {
                    kustr += "密钥协商";
                }
                else
                {
                    kustr += ",密钥协商";
                }
                first = false;
            }


            if (ku[Certificate.KeyUsageKeyCertSign])
            {
                if (first)
                {
                    kustr += "签证书";
                }
                else
                {
                    kustr += ",签证书";
                }
                first = false;
            }

            if (ku[Certificate.KeyUsageCrlSign])
            {
                if (first)
                {
                    kustr += "签CRL";
                }
                else
                {
                    kustr += ",签CRL";
                }
                first = false;
            }

            if (ku[Certificate.KeyUsageEncipherOnly])
            {
                if (first)
                {
                    kustr += "只加密";
                }
                else
                {
                    kustr += ",只加密";
                }
                first = false;
            }

            if (ku[Certificate.KeyUsageDecipherOnly])
            {
                if (first)
                {
                    kustr += "只解密";
                }
                else
                {
                    kustr += ",只解密";
                }
                first = false;
            }

            Console.WriteLine("密钥用法: {0}",kustr);
        }
    }
}
