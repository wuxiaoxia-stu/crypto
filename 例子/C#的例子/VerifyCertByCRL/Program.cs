using System;
using System.IO;
using Netca.Pki;

namespace VerifyCertByCRL
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: VerifyCertByCRL cert crl");
                return;
            }
            using (Certificate cert = GetCert(args[0]))
            {
                byte[] crl=GetFileContent(args[1]);
                
                int rv;
                RevokedInfo info;
                using (CRL crlObj = new CRL(crl))
                {
                    rv = cert.VerifyRevokeWithCrl(crlObj, out info);
                }
                if (rv == Certificate.CertificateStatusGood)
                {
                    Console.WriteLine("证书状态正常");
                    return;
                }
                else if (rv == Certificate.CertificateStatusUnknow)
                {
                    Console.WriteLine("不能确定证书的状态");
                    return;
                }
                else if (rv == Certificate.CertificateStatusRevoked)
                {
                    Console.WriteLine("证书已经作废");
                    Console.WriteLine("作废时间: {0}", info.RevokedTime.ToLocalTime());
                    PrintReason(info.RevokedReason);
                    return;
                }
                else
                {
                    Console.WriteLine("验证证书状态时出错");
                    return;
                }


            }

        }

        static Certificate GetCert(String fileName)
        {
            return new Certificate(GetFileContent(fileName));
        }

        static void PrintReason(int reason)
        {
            switch (reason)
            {
                case -1:
                    Console.WriteLine("作废原因: 没说明作废原因");
                    return;
                case RevokedInfo.RevokedReasonUnspecified:
                    Console.WriteLine("作废原因: 未指定");
                    return;
                case RevokedInfo.RevokedReasonKeyCompromise:
                    Console.WriteLine("作废原因: 密钥泄露");
                    return;
                case RevokedInfo.RevokedReasonCACompromise:
                    Console.WriteLine("作废原因: 本身是CA证书，其密钥泄露");
                    return;
                case RevokedInfo.RevokedReasonAffiliationChanged:
                    Console.WriteLine("作废原因: 附属关系改变");
                    return;
                case RevokedInfo.RevokedReasonSuperseded:
                    Console.WriteLine("作废原因: 被取代");
                    return;
                case RevokedInfo.RevokedReasonCessationOfOperation:
                    Console.WriteLine("作废原因: 停止操作");
                    return;
                case RevokedInfo.RevokedReasonCertifateHold:
                    Console.WriteLine("作废原因: 临时作废");
                    return;
                default:
                    Console.WriteLine("作废原因: 未知的作废原因({0})", reason);
                    return;
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
