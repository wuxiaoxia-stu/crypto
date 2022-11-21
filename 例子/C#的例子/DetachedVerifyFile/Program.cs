using System;
using System.IO;
using Netca.Pki;

namespace DetachedVerifyFile
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: DetachedVerifyFile tbsFile signFile");
                return;
            }

            using (SignedData s = new SignedData(false))
            {
                byte[] signData = new byte[16 * 1024];
                int len;
                using (FileStream inStream = new FileStream(args[1], FileMode.Open, FileAccess.Read))
                {
                    len = inStream.Read(signData, 0, signData.Length);
                }
                s.DetachedVerifyInit(signData,0,len);
                using (FileStream inStream = new FileStream(args[0], FileMode.Open, FileAccess.Read))
                {
                    byte[] inData = new byte[8192];
                    for (; ; )
                    {
                        len = inStream.Read(inData, 0, inData.Length);
                        if (len == 0)
                        {
                            break;
                        }
                        s.DetachedVerifyUpdate(inData,0,len);
                    }
                }
                s.DetachedVerifyFinal();
                Console.WriteLine("验证成功");
                using (Certificate cert = s.GetSignCertificate(0))
                {
                    Console.WriteLine("签名证书的主体：{0}", cert.Subject);
                }
            }
        }
    }
}
