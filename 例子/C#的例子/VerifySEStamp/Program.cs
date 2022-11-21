using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace VerifySEStamp
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 1)
            {
                Console.WriteLine("Usage: VerifySEStamp stampFileName");
                return;
            }
            string stampFileName = args[0];
            byte[] data = GetFileContent(stampFileName);
            using (SEStamp stamp = new SEStamp(data))
            {
                if (stamp.Verify() == false)
                {
                    Console.WriteLine("验证失败");
                }
                else
                {
                    Console.WriteLine("验证成功");
                }

                int format = stamp.Format;
                if (format == SEStamp.FormatGbt38540)
                {
                    Console.WriteLine("GB/T 38540的电子印章");
                }
                else if (format == SEStamp.FormatGmt0031)
                {
                    Console.WriteLine("GM/T 0031的电子印章");
                }
                else
                {
                    Console.WriteLine("未知格式的电子印章");
                }
                Console.WriteLine("版本号:{0}" , stamp.Version);
                Console.WriteLine("印章ID:{0}" , stamp.Id);
                Console.WriteLine("印章VID:{0}", stamp.Vid);
                Console.WriteLine("印章类型:{0}", stamp.Type);
                Console.WriteLine("印章的名称:{0}", stamp.Name);
                int certListType = stamp.GetCertListType();
                if (certListType == SEStamp.CertListTypeCert)
                {
                    int certCount = stamp.GetCertCount();
                    for (int i = 0; i < certCount; i++)
                    {
                        using(Certificate cert=stamp.GetCert(i))
                        {
                            Console.WriteLine("签章人{0}的证书:{1}",i, cert.Encode(Certificate.CertificateEncodeTypeBase64WithoutNL));
                        }
                    }
                }
                else if (certListType == SEStamp.CertListTypeCertDigest)
                {
                    int hashCount = stamp.GetCertDigestCount();
                    for (int i = 0; i < hashCount; i++)
                    {
                        byte[] hash;
                        string hashType;
                        hash = stamp.GetCertDigest(i, out hashType);
                        Console.WriteLine("签章人{0}的证书杂凑算法:{1}，杂凑值:{2}",
                            i, hashType, Util.HexEncode(true, hash));
                    }

                }
                else
                {
                    Console.WriteLine("未知的证书列表类型");
                }
                Console.WriteLine("创建时间:{0}", stamp.CreateDate.ToLocalTime());
                Console.WriteLine("有效期开始时间:{0}", stamp.ValidStart.ToLocalTime());
                Console.WriteLine("有效期结束时间:{0}", stamp.ValidEnd.ToLocalTime());

                byte[] pictureData;
                string pictureType;
                int width;
                int heigth;
                pictureData = stamp.GetPicture(out pictureType, out width, out heigth);
                Console.WriteLine("图片类型:{0}", pictureType);
                Console.WriteLine("图片宽度:{0}", width);
                Console.WriteLine("图片高度:{0}", heigth);
                //Console.WriteLine("图片内容:{0}", Util.HexEncode(true,pictureData));

                int extCount=stamp.GetExtensionCount();
                Console.WriteLine("扩展个数:{0}", extCount);
                for (int i = 0; i < extCount; i++)
                { 
                    string oid;
                    bool critical;
                    byte[] extValue;
                    extValue = stamp.GetExtension(i, out oid, out critical);
                    Console.WriteLine("第{0}个扩展:{1},OID:{2},扩展值:{3}",
                        i, critical?"关键扩展":"非关键扩展",
                        oid,Util.HexEncode(true,extValue));

                }
                Console.WriteLine("签名算法：{0}", GetSignAlgorithmName(stamp.GetSignAlgorithm()));
                using (Certificate signCert = stamp.GetSignCert())
                {
                    Console.WriteLine("制章人证书的主体:{0}", signCert.Subject);
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

        private static string GetSignAlgorithmName(int algo)
        {
            switch (algo)
            { 
                case Algorithm.SignatureAlgorithmEcdsawithSha1:
                    return "ECDSAWithSHA1";
                case Algorithm.SignatureAlgorithmEcdsawithSha224:
                    return "ECDSAWithSHA224";
                case Algorithm.SignatureAlgorithmEcdsawithSha256:
                    return "ECDSAWithSHA256";
                case Algorithm.SignatureAlgorithmEcdsawithSha384:
                    return "ECDSAWithSHA384";
                case Algorithm.SignatureAlgorithmEcdsawithSha512:
                    return "ECDSAWithSHA512";
                case Algorithm.SignatureAlgorithmEcdsawithSha3_224:
                    return "ECDSAWithSHA3-224";
                case Algorithm.SignatureAlgorithmEcdsawithSha3_256:
                    return "ECDSAWithSHA3-256";
                case Algorithm.SignatureAlgorithmEcdsawithSha3_384:
                    return "ECDSAWithSHA3-384";
                case Algorithm.SignatureAlgorithmEcdsawithSha3_512:
                    return "ECDSAWithSHA3-512";
                case Algorithm.SignatureAlgorithmSha1withRsa:
                    return "SHA1WithRSA";
                case Algorithm.SignatureAlgorithmSha224withRsa:
                    return "SHA224WithRSA";
                case Algorithm.SignatureAlgorithmSha256withRsa:
                    return "SHA256WithRSA";
                case Algorithm.SignatureAlgorithmSha384withRsa:
                    return "SHA384WithRSA";
                case Algorithm.SignatureAlgorithmSha512withRsa:
                    return "SHA512WithRSA";
                case Algorithm.SignatureAlgorithmSha512_224withRsa:
                    return "SHA512/224WithRSA";
                case Algorithm.SignatureAlgorithmSha512_256withRsa:
                    return "SHA512/256WithRSA";
                case Algorithm.SignatureAlgorithmSha3_224withRsa:
                    return "SHA3-224WithRSA";
                case Algorithm.SignatureAlgorithmSha3_256withRsa:
                    return "SHA3-256WithRSA";
                case Algorithm.SignatureAlgorithmSha3_384withRsa:
                    return "SHA3-384WithRSA";
                case Algorithm.SignatureAlgorithmSha3_512withRsa:
                    return "SHA3-512WithRSA";
                case Algorithm.SignatureAlgorithmSm3withSm2:
                    return "SM3WithSM2";
                default:
                    return "未知签名算法(" + algo + ")";
            }
        }
    }
}
