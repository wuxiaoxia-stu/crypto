using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace SignSESeal2
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 4)
            {
                Console.WriteLine("Usage: SignSESeal2 signCertFileName tbsFileName stampFileName sealFileName");
                return;
            }

            string signCertFileName = args[0];
            string tbsFileName = args[1];
            string stampFileName = args[2];
            string sealFileName = args[3];

            byte[] tbs = GetFileContent(tbsFileName);
            byte[] stampData = GetFileContent(stampFileName);

            using (SEStamp stamp = new SEStamp(stampData))
            {
                if (stamp.Verify() == false)
                {
                    Console.WriteLine("电子印章验证失败");
                    return;
                }
                int format = stamp.Format;
                if (format == SEStamp.FormatGbt38540)
                {
                    format = SESeal.FormatGbt38540;
                }
                else
                {
                    format = SESeal.FormatGmt0031;
                }
                using (SESeal seal = new SESeal(format))
                {
                    if (format == SESeal.FormatGmt0031)
                    {
                        seal.Version = 77;
                    }

                    seal.Stamp = stamp;

                    seal.Property = "Sign File";

                    seal.Time = DateTime.Now;

                    using (Certificate signCert = GetCert(signCertFileName))
                    {
                        if (IsGetInStamp(stamp, signCert) == false)
                        {
                            Console.WriteLine("签章证书不在电子印章中");
                            return;
                        }
                        int signAlgo = GetSignAlgorithm(signCert);
                        int hashAlgo = SESeal.GetHashAlgorithmFromSignAlgorithm(signAlgo);

                        seal.DataHash = Hash.ComputeHash(hashAlgo, tbs);

                        

                        byte[] encode = seal.Sign(signAlgo, signCert,SignCallback);
                        using (FileStream outStream = new FileStream(sealFileName, FileMode.Create, FileAccess.Write))
                        {
                            outStream.Write(encode, 0, encode.Length);
                        }
                    }
                }
            }
            Console.WriteLine("Success");
        }

        private static Certificate GetCert(String fileName)
        {
            return new Certificate(GetFileContent(fileName));
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

        private static int GetSignAlgorithm(Certificate cert)
        {
            if (cert.Match("Algorithm='RSA'"))
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSha256withRsa;
            }
            else if (cert.Match("Algorithm='SM2'"))
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSm3withSm2;
            }
            else if (cert.Match("Algorithm='ECC'"))
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha256;
            }
            else
            {
                throw new Exception("不支持的证书");
            }
        }

        private static bool IsGetInStamp(SEStamp stamp, Certificate cert)
        {
            int certListType = stamp.GetCertListType();
            if (certListType == SEStamp.CertListTypeCert)
            {
                for (int i = 0; i < stamp.GetCertCount(); i++)
                {
                    using (Certificate signCert = stamp.GetCert(i))
                    {
                        if (cert == signCert)
                        {
                            return true;
                        }
                    }
                }
                return false;
            }
            else if (certListType == SEStamp.CertListTypeCertDigest)
            {
                for (int i = 0; i < stamp.GetCertDigestCount(); i++)
                {
                    string hashType;
                    byte[] hashValue = stamp.GetCertDigest(i, out hashType);
                    int hashAlgo;
                    hashAlgo = GetHashAlgo(hashType.ToUpper());
                    if (hashAlgo != -1)
                    {
                        byte[] hashValue2 = Hash.ComputeHash(hashAlgo, cert.Encode());
                        if (ByteArrayEquals(hashValue, hashValue2))
                        {
                            return true;
                        }
                    }
                }
                return false;
            }
            else
            {
                return false;
            }
        }

        private static int GetHashAlgo(String algo)
        {

            if (algo == "SHA1" || algo == "SHA-1" || algo == "1.3.14.3.2.26")
            {
                return Algorithm.HashAlgorithmSha1;
            }
            else if (algo == "SHA224" || algo == "SHA-224" || algo == "2.16.840.1.101.3.4.2.4")
            {
                return Algorithm.HashAlgorithmSha224;
            }
            else if (algo == "SHA256" || algo == "SHA-256" || algo == "2.16.840.1.101.3.4.2.1")
            {
                return Algorithm.HashAlgorithmSha256;
            }
            else if (algo == "SHA384" || algo == "SHA-384" || algo == "2.16.840.1.101.3.4.2.2")
            {
                return Algorithm.HashAlgorithmSha384;
            }
            else if (algo == "SHA512" || algo == "SHA-512" || algo == "2.16.840.1.101.3.4.2.3")
            {
                return Algorithm.HashAlgorithmSha512;
            }
            else if (algo == "MD5" || algo == "1.2.840.113549.2.5")
            {
                return Algorithm.HashAlgorithmMd5;
            }
            else if (algo == "SHA512/224" || algo == "SHA-512/224" || algo == "2.16.840.1.101.3.4.2.5")
            {
                return Algorithm.HashAlgorithmSha512_224;
            }
            else if (algo == "SHA512/256" || algo == "SHA-512/256" || algo == "2.16.840.1.101.3.4.2.6")
            {
                return Algorithm.HashAlgorithmSha512_256;
            }
            else if (algo == "SHA3-224" || algo == "2.16.840.1.101.3.4.2.7")
            {
                return Algorithm.HashAlgorithmSha3_224;
            }
            else if (algo == "SHA3-256" || algo == "2.16.840.1.101.3.4.2.8")
            {
                return Algorithm.HashAlgorithmSha3_256;
            }
            else if (algo == "SHA3-256" || algo == "2.16.840.1.101.3.4.2.8")
            {
                return Algorithm.HashAlgorithmSha3_256;
            }
            else if (algo == "SHA3-384" || algo == "2.16.840.1.101.3.4.2.9")
            {
                return Algorithm.HashAlgorithmSha3_384;
            }
            else if (algo == "SHA3-512" || algo == "2.16.840.1.101.3.4.2.10")
            {
                return Algorithm.HashAlgorithmSha3_512;
            }
            else if (algo == "SM3" || algo == "1.2.156.10197.1.401")
            {
                return Algorithm.HashAlgorithmSm3;
            }
            else
            {
                return -1;
            }


        }

        private static bool ByteArrayEquals(byte[] b1, byte[] b2)
        {
            if (b1.Length != b2.Length)
            {
                return false;
            }

            for (int i = 0; i < b1.Length; i++)
            {
                if (b1[i] != b2[i])
                {
                    return false;
                }
            }
            return true;
        }

        private static byte[] SignCallback(Certificate cert, int algo, object param, byte[] tbs)
        {

            KeyPair keypair = cert.GetKeyPair(Certificate.SearchKeyPairFlagDevice, KeyPair.KeyPairTypeSignature, null);
            if (keypair == null)
            {
                throw new Exception("没有私钥");
            }
            using (keypair)
            {
                if (algo == Algorithm.SignatureAlgorithmRsaPss)
                {
                    PSSParam pss = (PSSParam)param;
                    using (Signature signature = new Signature(keypair, pss.mgfalgo, pss.saltlen, pss.hashalgo))
                    {
                        signature.Update(tbs);
                        return signature.Sign();
                    }

                }
                else
                {
                    using (Signature signature = new Signature(keypair, algo))
                    {
                        signature.Update(tbs);
                        return signature.Sign();
                    }
                }

            }

        }
    }
}
