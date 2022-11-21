using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Netca.Pki;
using System.IO;

namespace EnvelopedDataDecrypt4
{
    class Program
    {
        private static Certificate decryptCert;
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: EnvelopedDataDecrypt infile outfile");
                return;
            }

            using (EnvelopedData env = new EnvelopedData(false))
            {
                env.SetDecryptKeyCallback(DecryptKeyCallback);
                env.DecryptInit();
                using (FileStream inStream = new FileStream(args[0], FileMode.Open, FileAccess.Read))
                {
                    byte[] inData = new byte[8192];
                    int len;
                    using (FileStream outStream = new FileStream(args[1], FileMode.Create, FileAccess.Write))
                    {
                        byte[] outData;
                        for (; ; )
                        {
                            len = inStream.Read(inData, 0, inData.Length);
                            if (len == 0)
                            {
                                break;
                            }
                            outData = env.DecryptUpdate(inData, 0, len);
                            if (outData.Length > 0)
                            {
                                outStream.Write(outData, 0, outData.Length);
                            }
                        }

                    }
                    env.DecryptFinal();

                    Console.WriteLine(decryptCert.Subject);
                    decryptCert.Dispose();
                    
                }
            }
        }

        private static byte[] DecryptKeyCallback(int ridType, byte[] rid, int algo, object param, byte[] cipher)
        {
            using (DeviceSet deviceSet = new DeviceSet(Device.DeviceTypeAny, Device.DeviceCanInstallCert))
            {
                int deviceCount = deviceSet.Count;
                for (int i = 0; i < deviceCount; i++)
                {
                    using (Device device = deviceSet[i])
                    {
                        byte[] key = DecryptKeyCallback(device, ridType, rid, algo, param, cipher);
                        if (key != null)
                        {
                            return key;
                        }
                    }

                }
                return null;
            }
            
        }
        private static byte[] DecryptKeyCallback(Device device, int ridType, byte[] rid, int algo, object param, byte[] cipher)
        {
            int keypairCount=device.GetKeyPairCount();
            for (int i = 0; i < keypairCount; i++)
            {
                using (KeyPair keypair = device.GetKeyPair(i))
                {
                    byte[] key = DecryptKeyCallback(device, keypair, ridType, rid, algo, param, cipher);
                    if (key != null)
                    {
                        return key;
                    }
                }
            }
            return null;
        }

        private static byte[] DecryptKeyCallback(Device device, KeyPair keypair, int ridType, byte[] rid, int algo, object param, byte[] cipher)
        {
            int certCount = keypair.GetCertificateCount();
            for (int i = 0; i < certCount; i++)
            {
                using (Certificate cert = keypair.GetCertificate(i))
                {
                    byte[] key = DecryptKeyCallback(device, keypair, cert, ridType, rid, algo, param, cipher);
                    if (key != null)
                    {
                        return key;
                    }
                }
            }
            return null;

        }

        private static byte[] DecryptKeyCallback(Device device,KeyPair keypair, Certificate cert,int ridType, byte[] rid, int algo, object param, byte[] cipher)
        {
            if (Match(cert, ridType, rid) == false)
            {
                return null;
            }
            decryptCert = cert;


            if (algo == Algorithm.EncryptAlgorithmRsaPkcs1Oaep)
            {
                RSAPkcs1Oaep oaepParm = (RSAPkcs1Oaep)param;
                return keypair.RSAOAEPDecrypt(oaepParm.hashAlgo, oaepParm.mgfAlgo,
                    oaepParm.label, cipher);
            }
            else if (algo == Algorithm.KeyagreementAlgorithmEccdh
                || algo == Algorithm.KeyagreementAlgorithmEcdh)
            {
                byte[] spki = PublicKey.EncodeTrueECCSubjectPublicKeyInfo(keypair.GetECCCurve(), (byte[])param);
                using (PublicKey publicKey = device.ImportSubjectPublicKeyInfo(spki))
                {
                    if (algo == Algorithm.KeyagreementAlgorithmEccdh)
                    {
                        return keypair.ECCDH(publicKey);
                    }
                    else
                    {
                        return keypair.ECDH(publicKey);
                    }
                }
            }
            else if (algo == Algorithm.EncryptAlgorithmSm2Enc)
            {
                return keypair.SM2Decrypt(true,cipher);
            }
            else
            {
                return keypair.Decrypt(algo, cipher);
            }
        }

        private static bool Match(Certificate cert, int ridType, byte[] rid)
        {
            if (ridType == 1)
            {
                string hexIssuerAndSn = cert.GetStringAttribute(96);
                byte[] issuerAndSn = Util.HexDecode(hexIssuerAndSn);
                return ByteArrayEquals(rid,issuerAndSn);
            }
            else if (ridType == 2)
            {
                string hexSubjectKeyId = cert.GetStringAttribute(66);
                if (hexSubjectKeyId == null)
                {
                    return false;
                }
                byte[] subjectKeyId = Util.HexDecode(hexSubjectKeyId);
                return ByteArrayEquals(rid, subjectKeyId);
            }
            else
            {
                return false;
            }
        }

        private static bool ByteArrayEquals(byte[] b1,byte[]b2)
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
    }
}
