using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace VerifySignedAndEnvelopedData2
{
    class Program
    {
        private static Certificate decryptCert;
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: VerifySignedAndEnvelopedData2 inFile outFile");
                return;
            }
            string inFileName = args[0];
            string outFileName = args[1];

            byte[] data = GetFileContent(inFileName);
            using (SignedAndEnvelopedData signedAndEnvelopedData = new SignedAndEnvelopedData(false))
            {
                signedAndEnvelopedData.SetDecryptKeyCallback(DecryptKeyCallback);
                byte[] clear = signedAndEnvelopedData.DecryptAndVerify(true, data);
                using (FileStream outStream = new FileStream(outFileName, FileMode.Create, FileAccess.Write))
                {
                    outStream.Write(clear, 0, clear.Length);
                }
                using (Certificate signCert = signedAndEnvelopedData.GetSignCert(0))
                {
                    Console.WriteLine("签名证书的主体：{0}", signCert.Subject);
                }

                using (decryptCert)
                {
                    Console.WriteLine("加密证书的主体：{0}", decryptCert.Subject);
                }
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
            int keypairCount = device.GetKeyPairCount();
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

        private static byte[] DecryptKeyCallback(Device device, KeyPair keypair, Certificate cert, int ridType, byte[] rid, int algo, object param, byte[] cipher)
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
            else if (algo == Algorithm.EncryptAlgorithmSm2Enc)
            {
                return keypair.SM2Decrypt(true, cipher);
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
                return ByteArrayEquals(rid, issuerAndSn);
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
    }
}
