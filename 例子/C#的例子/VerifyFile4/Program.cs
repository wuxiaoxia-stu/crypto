using System;
using System.IO;
using Netca.Pki;

namespace VerifyFile4
{
    class Program
    {
        private static Certificate cert;
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Usage: VerifyFile4 signCertFile signFile tbsFile");
                return;
            }
            cert = GetCert(args[0]);
            using (SignedData s = new SignedData(false))
            {
                s.SetGetCertCallback(GetCertCallback);
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
                    s.VerifyFinal();
                    Console.WriteLine("验证成功");
                    using (Certificate signCert = s.GetSignCertificate(0))
                    {
                        Console.WriteLine("签名证书的主体：{0}", signCert.Subject);
                    }

                    cert.Dispose();
                    cert = null;
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

        private static Certificate[] GetCertCallback(int sidType, byte[] sid)
        {
            if (Match(cert, sidType, sid))
            {
                return new Certificate[] { cert };
            }
            else
            {
                throw new Exception("没有证书");
            }
        }

        private static bool Match(Certificate cert, int sidType, byte[] sid)
        {
            if (sidType == 1)
            {
                string hexIssuerAndSn = cert.GetStringAttribute(96);
                byte[] issuerAndSn = Util.HexDecode(hexIssuerAndSn);
                return ByteArrayEquals(sid, issuerAndSn);
            }
            else if (sidType == 2)
            {
                string hexSubjectKeyId = cert.GetStringAttribute(66);
                if (hexSubjectKeyId == null)
                {
                    return false;
                }
                byte[] subjectKeyId = Util.HexDecode(hexSubjectKeyId);
                return ByteArrayEquals(sid, subjectKeyId);
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
