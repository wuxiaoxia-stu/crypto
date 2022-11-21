using System;
using System.IO;
using Netca.Pki;

namespace RsaPssSignP10
{
    class Program
    {
        private static KeyPair keypair;
        static void Main(string[] args)
        {
            if (args.Length != 6)
            {
                Console.WriteLine("Usage: RsaPssSignP10 deviceType deviceSn enc|sign label pwd p10File");
                return;
            }

            int deviceType = int.Parse(args[0]);
            string deviceSn = args[1];
            string keypairTypeSn = args[2].ToLower();
            int keypairType;
            if (keypairTypeSn == "enc")
            {
                keypairType = KeyPair.KeyPairTypeEncrypt;
            }
            else if (keypairTypeSn == "sign")
            {
                keypairType = KeyPair.KeyPairTypeSignature;
            }
            else if (keypairTypeSn == "keyagreement")
            {
                keypairType = KeyPair.KeyPairTypeKeyAgreement;
            }
            else
            {
                Console.WriteLine("Usage: SignP10 deviceType deviceSn enc|sign label pwd p10File");
                return;
            }
            string label = args[3];
            string pwd = args[4];
            string outFile = args[5];

            keypair = KeyPair.FindKeyPair(deviceType, deviceSn, Device.DeviceFlagSlient, pwd, keypairType, label);
            if (keypair == null)
            {
                Console.WriteLine("没有该密钥对");
                return;
            }
            if (keypair.Algorithm != Algorithm.PublicKeyAlgorithmRsa)
            {
                keypair.Dispose();
                Console.WriteLine("不是RSA密钥对");
                return;
            }
            using (keypair)
            {
                
                
                using (PublicKey publicKey = keypair.GetPublicKey())
                {
                    byte[] spki = publicKey.ExportSubjectPublicKeyInfo();
                    using (CertReq certReq = new CertReq())
                    {
                        certReq.Subject = "CN=TestPSS,C=CN";

                        byte[] p10Data = certReq.RSAPSSSign(Algorithm.MgfAlgorithmPkcs1Mgf1Sha256, 32, Algorithm.HashAlgorithmSha256, spki, SignHashCallback);
                        
                        using (FileStream outStream = new FileStream(outFile, FileMode.Create, FileAccess.Write))
                        {
                            outStream.Write(p10Data, 0, p10Data.Length);
                        }

                        Console.WriteLine("Success");
                    }
                }
            }
        }

        private static byte[] SignHashCallback(int algo, object param, byte[] hashValue)
        {
            if (algo == Algorithm.SignatureAlgorithmRsaPss)
            {
                PSSParam pss = (PSSParam)param;
                return Signature.RSAPSSSignHash(keypair, pss.mgfalgo, pss.saltlen, pss.hashalgo, hashValue);
            }
            else
            {
                return Signature.SignHash(keypair, algo, hashValue);
            }
        }
    }
}
