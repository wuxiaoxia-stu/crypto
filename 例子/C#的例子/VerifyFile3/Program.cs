using System;
using System.IO;
using Netca.Pki;

namespace VerifyFile3
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Usage: VerifyFile3 signCertFile signFile tbsFile");
                return;
            }
            using (Certificate cert = GetCert(args[0]))
            {
                using (SignedData s = new SignedData(false))
                {
                    s.AddCertificate(cert);
                    s.VerifyInit();
                    byte[] outData;
                    using (FileStream inStream = new FileStream(args[1], FileMode.Open, FileAccess.Read))
                    {
                        using (FileStream outStream = new FileStream(args[2], FileMode.Create, FileAccess.Write))
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
                                outData = s.VerifyUpdate(inData, 0, len);
                                if (outData.Length > 0)
                                {
                                    outStream.Write(outData, 0, outData.Length);
                                }
                            }
                        }
                    }
                    s.VerifyFinal();
                    Console.WriteLine("验证成功");
                    using (Certificate signCert = s.GetSignCertificate(0))
                    {
                        Console.WriteLine("签名证书的主体：{0}", signCert.Subject);
                    }
                }
            }

        }

        private static Certificate GetCert(String fileName)
        {
            FileStream inStream = new FileStream(fileName, FileMode.Open, FileAccess.Read);
            byte[] data = new byte[8129];
            int len = inStream.Read(data, 0, data.Length);
            inStream.Close();

            return new Certificate(data, 0, len);
        }
    }
}
