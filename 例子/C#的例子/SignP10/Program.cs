using System;
using System.IO;
using Netca.Pki;

namespace SignP10
{
    class Program
    {
        private static KeyPair keypair;
        static void Main(string[] args)
        {
            if (args.Length != 6)
            {
                Console.WriteLine("Usage: SignP10 deviceType deviceSn enc|sign label pwd p10File");
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
            using (keypair)
            {
                int signAlgo;
                if (keypair.Algorithm == Algorithm.PublicKeyAlgorithmRsa)
                {
                    signAlgo = Algorithm.SignatureAlgorithmSha256withRsa;
                }
                else if (keypair.Algorithm == Algorithm.PublicKeyAlgorithmEcc)
                {
                    int curve = keypair.GetECCCurve();
                    if (curve == KeyPair.EccCurveSM2)
                    {
                        signAlgo = Algorithm.SignatureAlgorithmSm3withSm2;
                    }
                    else
                    {
                        signAlgo = Algorithm.SignatureAlgorithmEcdsawithSha256;
                    }
                }
                else
                {
                    Console.WriteLine("不支持的密钥对");
                    return;
                }
                using(PublicKey publicKey=keypair.GetPublicKey())
                {
                    byte[] spki = publicKey.ExportSubjectPublicKeyInfo();
                    using (CertReq certReq = new CertReq())
                    {
                        certReq.Subject = "CN=TestCN,C=CN";

                        byte[] p10Data = certReq.Sign(signAlgo, spki, SignHashCallback);
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
