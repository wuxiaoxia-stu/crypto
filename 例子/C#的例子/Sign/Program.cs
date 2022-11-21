using System;
using System.IO;
using Netca.Pki;

namespace Sign
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 4)
            {
                Console.WriteLine("Usage: Sign sha1withRSA|sha256withRSA cert tbs signature");
                return;
            }

            int algo;
            string algoStr = args[0].ToLower();
            if (algoStr == "md5withrsa")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmMd5withRsa;
            }
            else if (algoStr == "sha1withrsa")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmSha1withRsa;
            }
            else if (algoStr == "sha224withrsa")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmSha224withRsa;
            }
            else if (algoStr == "sha256withrsa")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmSha256withRsa;
            }
            else if (algoStr == "sha384withrsa")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmSha384withRsa;
            }
            else if (algoStr == "sha512withrsa")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmSha512withRsa;
            }
            else if (algoStr == "sha512_224withrsa")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmSha512_224withRsa;
            }
            else if (algoStr == "sha512_256withrsa")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmSha512_256withRsa;
            }
            else if (algoStr == "sha3_224withrsa")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmSha3_224withRsa;
            }
            else if (algoStr == "sha3_256withrsa")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmSha3_256withRsa;
            }
            else if (algoStr == "sha3_384withrsa")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmSha3_384withRsa;
            }
            else if (algoStr == "sha3_512withrsa")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmSha3_512withRsa;
            }
            else if (algoStr == "ecdsawithsha1")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha1;
            }
            else if (algoStr == "ecdsawithsha224")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha224;
            }
            else if (algoStr == "ecdsawithsha256")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha256;
            }
            else if (algoStr == "ecdsawithsha384")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha384;
            }
            else if (algoStr == "ecdsawithsha512")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha512;
            }
            else if (algoStr == "ecdsawithsha3_224")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha3_224;
            }
            else if (algoStr == "ecdsawithsha3_256")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha3_256;
            }
            else if (algoStr == "ecdsawithsha3_384")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha3_384;
            }
            else if (algoStr == "ecdsawithsha3_512")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha3_512;
            }
            else if (algoStr == "sm3withsm2")
            {
                algo = Netca.Pki.Algorithm.SignatureAlgorithmSm3withSm2;
            }
            else
            {
                Console.WriteLine("Usage: Sign sha1withRSA|sha256withRSA cert tbs signature");
                return;
            }

            Certificate cert = GetCert(args[1]);
            KeyPair keypair = cert.GetKeyPair(Certificate.SearchKeyPairFlagDevice,Certificate.CertificatePurposeSign,null);
            cert.Dispose();
            if(keypair==null)
            {
                Console.WriteLine("No Keypair");
                return;
            }
            Signature sign = new Signature(keypair, algo);
            keypair.Dispose();

            byte[] outData;
            using (sign)
            {
                using (FileStream inStream = new FileStream(args[2], FileMode.Open, FileAccess.Read))
                {
                    byte[] inData = new byte[8192];
                    
                    int len;
                    for (; ; )
                    {
                        len = inStream.Read(inData, 0, inData.Length);
                        if (len == 0)
                        {
                            break;
                        }

                        sign.Update(inData, 0, len);
                    }
                    outData = sign.Sign();
                }

            }
            using (FileStream outStream = new FileStream(args[3], FileMode.Create, FileAccess.Write))
            {
                outStream.Write(outData, 0, outData.Length);
            }

            Console.WriteLine("Success");

        }

        static Certificate GetCert(String fileName)
        {
            FileStream inStream = new FileStream(fileName, FileMode.Open, FileAccess.Read);
            byte[] data=new byte[8129];
            int len = inStream.Read(data, 0, data.Length);
            inStream.Close();

            return new Certificate(data, 0, len);
        }
    }
}
