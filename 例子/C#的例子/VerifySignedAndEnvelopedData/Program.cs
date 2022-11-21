using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace VerifySignedAndEnvelopedData
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: VerifySignedAndEnvelopedData inFile outFile");
                return;
            }
            string inFileName = args[0];
            string outFileName = args[1];

            byte[] data = GetFileContent(inFileName);
            using (SignedAndEnvelopedData signedAndEnvelopedData = new SignedAndEnvelopedData(false))
            {
                byte[] clear = signedAndEnvelopedData.DecryptAndVerify(true, data);
                using (FileStream outStream = new FileStream(outFileName, FileMode.Create, FileAccess.Write))
                {
                    outStream.Write(clear, 0, clear.Length);
                }
                using (Certificate signCert = signedAndEnvelopedData.GetSignCert(0))
                {
                    Console.WriteLine("签名证书的主体：{0}", signCert.Subject);
                }

                using (Certificate encCert = signedAndEnvelopedData.GetDecryptCert())
                {
                    Console.WriteLine("加密证书的主体：{0}", encCert.Subject);
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
    }
}
