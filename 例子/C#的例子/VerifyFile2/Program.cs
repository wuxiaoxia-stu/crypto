using System;
using System.IO;
using Netca.Pki;

namespace VerifyFile2
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: VerifyFile2 signFile tbsFile");
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
                using (Certificate cert = s.GetSignCertificate(0))
                {
                    Console.WriteLine("签名证书的主体：{0}", cert.Subject);
                }

                int count = s.GetSignedAttributeCount(0);
                Console.WriteLine("签名属性个数：{0}", count);
                string attrType;
                byte[] attrValue;
                for (int i = 0; i < count; i++)
                {
                    s.GetSignedAttribute(0, i, out attrType, out attrValue);
                    Console.WriteLine("第{0}个签名属性：类型：{1}，值:{2}",
                        i, attrType, BitConverter.ToString(attrValue).Replace("-", ""));
                }

                count = s.GetUnsignedAttributeCount(0);
                Console.WriteLine("不签名属性个数：{0}", count);
                for (int i = 0; i < count; i++)
                {
                    s.GetUnsignedAttribute(0, i, out attrType, out attrValue);
                    Console.WriteLine("第{0}个不签名属性：类型：{1}，值:{2}",
                        i, attrType, BitConverter.ToString(attrValue).Replace("-", ""));
                }
            }


        }

    }
}
