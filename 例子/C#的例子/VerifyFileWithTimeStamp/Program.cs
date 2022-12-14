using System;
using System.IO;
using Netca.Pki;

namespace VerifyFileWithTimeStamp
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: VerifyFileWithTimeStamp signFile tbsFile");
                return;
            }

            using (SignedData s = new SignedData(false))
            {
                s.VerifyInit();
                byte[] outData;
                using (FileStream inStream = new FileStream(args[0], FileMode.Open, FileAccess.Read))
                {
                    using (FileStream outStream = new FileStream(args[1], FileMode.Create, FileAccess.Write))
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
                int count = s.SignatureCount;
                Console.WriteLine("共{0}个签名", count);
                for (int i = 0; i < count; i++)
                {
                    using (Certificate cert = s.GetSignCertificate(i))
                    {
                        Console.WriteLine("第{0}个签名证书的主体：{1}", i + 1, cert.Subject);
                    }
                }

                for (int i = 0; i < count; i++)
                {
                    if (s.HasTsaTimeAttribute(i))
                    {
                        if (s.VerifyTsaTimeStamp(i, null) == false)
                        {
                            Console.WriteLine("第{0}个签名的时间戳签名验证失败", i + 1);
                        }
                        else
                        {
                            using (Certificate cert = s.GetTsaCertificate(i))
                            {
                                Console.WriteLine("第{0}个签名的时间戳签名证书的主体：{1}", i + 1, cert.Subject);
                            }
                            Console.WriteLine("时间戳:{0}", s.GetTsaTime(i).ToLocalTime());
                        }
                    }
                }

            }
            

        }
    }
}
