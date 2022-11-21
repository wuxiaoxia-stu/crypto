using System;
using System.IO;
using Netca.Pki;

namespace VerifyCertByCRL2
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: VerifyCertByCRL2 cert crl");
                return;
            }
            using (Certificate cert = GetCert(args[0]))
            {
                byte[] crl;
                int len;
                using (FileStream inStream = new FileStream(args[1], FileMode.Open, FileAccess.Read))
                {
                    crl = new byte[1024 * 1024 * 30];
                    len = inStream.Read(crl, 0, crl.Length);
                }
                int rv;
                RevokedInfo info;

                rv = cert.VerifyRevokeWithCrl(crl, 0, len, out info);
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
            FileStream inStream = new FileStream(fileName, FileMode.Open, FileAccess.Read);
            byte[] data = new byte[8192];
            int len = inStream.Read(data, 0, data.Length);
            inStream.Close();

            return new Certificate(data, 0, len);
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
    }
}
