using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace CreateSignedAndEnvelopedData
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 4)
            {
                Console.WriteLine("Usage: CreateSignedAndEnvelopedData enCert signCert inFile outFile");
                return;
            }
            string enCertFileName = args[0];
            string signCertFileName = args[1];
            string inFileName = args[2];
            string outFileName = args[3];

            using (Certificate enCert = GetCert(enCertFileName))
            {
                int encAlgo = GetEncAlgo(enCert);
                if (encAlgo == -1)
                {
                    Console.WriteLine("不支持的加密证书");
                    return;
                }
                using (Certificate signCert = GetCert(signCertFileName))
                {
                    int signAlgo = GetSignAlgo(signCert);
                    if (signAlgo == -1)
                    {
                        Console.WriteLine("不支持的签名证书");
                        return;
                    }
                    KeyPair keypair = signCert.GetKeyPair(Certificate.SearchKeyPairFlagDevice, KeyPair.KeyPairTypeSignature, null);
                    if (keypair == null)
                    {
                        throw new Exception("签名证书没有私钥");
                    }
                    keypair.Dispose();
                    using (SignedAndEnvelopedData signedAndEnvelopedData = new SignedAndEnvelopedData(true))
                    {
                        signedAndEnvelopedData.AddEncCert(enCert);
                        signedAndEnvelopedData.SetEncAlgorithm(encAlgo);
                        byte[] clear = GetFileContent(inFileName);
                        signedAndEnvelopedData.SetSetClearText(clear);
                        byte[] outData = signedAndEnvelopedData.SignAndEncrypt(signAlgo, signCert, SignedAndEnvelopedData.IncludeCertOptionSelf);
                        using (FileStream outStream = new FileStream(outFileName, FileMode.Create, FileAccess.Write))
                        {
                            outStream.Write(outData, 0, outData.Length);
                        }
                    }
                }
            }
            Console.WriteLine("Success");
    
        }

        private static Certificate GetCert(String fileName)
        {
            FileStream inStream = new FileStream(fileName, FileMode.Open, FileAccess.Read);
            byte[] data = new byte[8192];
            int len = inStream.Read(data, 0, data.Length);
            inStream.Close();

            return new Certificate(data, 0, len);
        }

        private static int GetEncAlgo(Certificate cert)
        {
            if (cert.Match("Algorithm='RSA'"))
            {
                return Algorithm.SignedAndEnvelopedDataEncAlgorithmAes256Cbc;
            }
            else if (cert.Match("Algorithm='SM2'"))
            {
                return Algorithm.SignedAndEnvelopedDataEncAlgorithmSm4Cbc;
            }
            else
            {
                return -1;
            }
        }

        private static int GetSignAlgo(Certificate cert)
        {
            if (cert.Match("Algorithm='RSA'"))
            {
                return Algorithm.SignatureAlgorithmSha256withRsa;
            }
            else if (cert.Match("Algorithm='SM2'"))
            {
                return Algorithm.SignatureAlgorithmSm3withSm2;
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
