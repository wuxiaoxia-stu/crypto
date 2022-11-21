using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace SignSEStamp
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 4)
            {
                Console.WriteLine("Usage: SignSEStamp issuerCertFileName signAlgo templateFileName stampFileName");
                return;
            }
            string issuerCertFileName = args[0];
            string signAlgoStr = args[1].ToLower();
            string templateFileName = args[2];
            string stampFileName = args[3];
            int signAlgo = GetSignAlgo(signAlgoStr);
            if (signAlgo == -1)
            {
                Console.WriteLine("不支持的签名算法");
                return;
            }
            using (Certificate issuerCert = GetCert(issuerCertFileName))
            {
                KeyPair keypair = issuerCert.GetKeyPair(Certificate.SearchKeyPairFlagDevice, KeyPair.KeyPairTypeSignature, null);
                if (keypair == null)
                {
                    throw new Exception("签名证书没有私钥");
                }
                keypair.Dispose();

                byte[] data = GetFileContent(templateFileName);
                Json json = Json.Parse(Encoding.UTF8.GetString(data));
                int format;
                if (json.ContainsName("format") == false)
                {
                    format = SEStamp.FormatGbt38540;

                }
                else
                {
                    string formatString = json["format"].StringValue;
                    if (formatString == "GB/T 38540")
                    {
                        format = SEStamp.FormatGbt38540;
                    }
                    else if (formatString == "GM/T 0031")
                    {
                        format = SEStamp.FormatGmt0031;
                    }
                    else
                    {
                        Console.WriteLine("不支持的电子印章格式");
                        return;
                    }
                }
                using (SEStamp stamp = new SEStamp(format))
                {
                    if (format == SEStamp.FormatGmt0031)
                    {
                        stamp.Version = (int)json["version"].NumberValue;
                    }
                    stamp.Id=json["id"].StringValue;
                    stamp.Vid = json["vid"].StringValue;
                    stamp.Type = (int)json["type"].NumberValue;
                    stamp.Name = json["name"].StringValue;
                    bool useCertDigest = false;
                    if (json["useCertDigest"] != null)
                    {
                        useCertDigest = json["useCertDigest"].IsTrue();
                    }

                    if (format == SEStamp.FormatGmt0031)
                    {
                        useCertDigest = false;
                    }
                    Json certsJson = json["certs"];
                    if (useCertDigest)
                    {
                        string hashAlgoStr = json["certDigestAlgo"].StringValue.ToUpper();
                        int hashAlgo=GetHashAlgo(hashAlgoStr);
                        if(hashAlgo==-1)
                        {
                            Console.WriteLine("不支持的Hash算法");
                            return;
                        }
                        for (int i = 0; i < certsJson.Count; i++)
                        { 
                            using(Certificate cert=new Certificate(certsJson[i].StringValue))
                            {
                                stamp.AddCertDigest(hashAlgo,cert);
                            }
                        }
                    }
                    else
                    {
                        for (int i = 0; i < certsJson.Count; i++)
                        { 
                            using(Certificate cert=new Certificate(certsJson[i].StringValue))
                            {
                                stamp.AddCert(cert);
                            }
                        }

                    }
                    
                    stamp.CreateDate = GetDateTime(json["createDate"].StringValue);
                    stamp.ValidStart = GetDateTime(json["validStart"].StringValue);
                    stamp.ValidEnd = GetDateTime(json["validEnd"].StringValue);
                    stamp.SetPicture(
                        json["picture"]["type"].StringValue,
                        Util.HexDecode(json["picture"]["data"].StringValue),
                        (int)json["picture"]["width"].NumberValue,
                        (int)json["picture"]["heigth"].NumberValue);

                    if(json.ContainsName("exts"))                             
                    {
                        Json extsJson = json["exts"];
                        for (int i = 0; i < extsJson.Count; i++)
                        { 
                            stamp.AddExtension(extsJson[i]["extnID"].StringValue,
                                extsJson[i]["critical"].IsTrue(),
                                Util.HexDecode(extsJson[i]["extnValue"].StringValue));
                        }
                    }
                    byte[] encode=stamp.Sign(signAlgo, issuerCert);
                    using (FileStream outStream = new FileStream(stampFileName, FileMode.Create, FileAccess.Write))
                    {
                        outStream.Write(encode, 0, encode.Length);
                    }

                }
            }
            Console.WriteLine("Success");
        }
        private static int GetSignAlgo(string algoStr)
        {
            
            if (algoStr == "md5withrsa")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmMd5withRsa;
            }
            else if (algoStr == "sha1withrsa")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSha1withRsa;
            }
            else if (algoStr == "sha224withrsa")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSha224withRsa;
            }
            else if (algoStr == "sha256withrsa")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSha256withRsa;
            }
            else if (algoStr == "sha384withrsa")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSha384withRsa;
            }
            else if (algoStr == "sha512withrsa")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSha512withRsa;
            }
            else if (algoStr == "sha512_224withrsa")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSha512_224withRsa;
            }
            else if (algoStr == "sha512_256withrsa")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSha512_256withRsa;
            }
            else if (algoStr == "sha3_224withrsa")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSha3_224withRsa;
            }
            else if (algoStr == "sha3_256withrsa")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSha3_256withRsa;
            }
            else if (algoStr == "sha3_384withrsa")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSha3_384withRsa;
            }
            else if (algoStr == "sha3_512withrsa")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSha3_512withRsa;
            }
            else if (algoStr == "ecdsawithsha1")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha1;
            }
            else if (algoStr == "ecdsawithsha224")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha224;
            }
            else if (algoStr == "ecdsawithsha256")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha256;
            }
            else if (algoStr == "ecdsawithsha384")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha384;
            }
            else if (algoStr == "ecdsawithsha512")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha512;
            }
            else if (algoStr == "ecdsawithsha3_224")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha3_224;
            }
            else if (algoStr == "ecdsawithsha3_256")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha3_256;
            }
            else if (algoStr == "ecdsawithsha3_384")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha3_384;
            }
            else if (algoStr == "ecdsawithsha3_512")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmEcdsawithSha3_512;
            }
            else if (algoStr == "sm3withsm2")
            {
                return Netca.Pki.Algorithm.SignatureAlgorithmSm3withSm2;
            }
            else
            {
                return -1;
            }
        }
        private static Certificate GetCert(String fileName)
        {
            return new Certificate(GetFileContent(fileName));
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

        private static int GetHashAlgo(String algo)
        {

            if (algo == "SHA1" || algo == "SHA-1" || algo == "1.3.14.3.2.26")
            {
                return Algorithm.HashAlgorithmSha1;
            }
            else if (algo == "SHA224" || algo == "SHA-224" || algo == "2.16.840.1.101.3.4.2.4")
            {
                return Algorithm.HashAlgorithmSha224;
            }
            else if (algo == "SHA256" || algo == "SHA-256" || algo == "2.16.840.1.101.3.4.2.1")
            {
                return Algorithm.HashAlgorithmSha256;
            }
            else if (algo == "SHA384" || algo == "SHA-384" || algo == "2.16.840.1.101.3.4.2.2")
            {
                return Algorithm.HashAlgorithmSha384;
            }
            else if (algo == "SHA512" || algo == "SHA-512" || algo == "2.16.840.1.101.3.4.2.3")
            {
                return Algorithm.HashAlgorithmSha512;
            }
            else if (algo == "MD5" || algo == "1.2.840.113549.2.5")
            {
                return Algorithm.HashAlgorithmMd5;
            }
            else if (algo == "SHA512/224" || algo == "SHA-512/224" || algo == "2.16.840.1.101.3.4.2.5")
            {
                return Algorithm.HashAlgorithmSha512_224;
            }
            else if (algo == "SHA512/256" || algo == "SHA-512/256" || algo == "2.16.840.1.101.3.4.2.6")
            {
                return Algorithm.HashAlgorithmSha512_256;
            }
            else if (algo == "SHA3-224" || algo == "2.16.840.1.101.3.4.2.7")
            {
                return Algorithm.HashAlgorithmSha3_224;
            }
            else if (algo == "SHA3-256" || algo == "2.16.840.1.101.3.4.2.8")
            {
                return Algorithm.HashAlgorithmSha3_256;
            }
            else if (algo == "SHA3-256" || algo == "2.16.840.1.101.3.4.2.8")
            {
                return Algorithm.HashAlgorithmSha3_256;
            }
            else if (algo == "SHA3-384" || algo == "2.16.840.1.101.3.4.2.9")
            {
                return Algorithm.HashAlgorithmSha3_384;
            }
            else if (algo == "SHA3-512" || algo == "2.16.840.1.101.3.4.2.10")
            {
                return Algorithm.HashAlgorithmSha3_512;
            }
            else if (algo == "SM3" || algo == "1.2.156.10197.1.401")
            {
                return Algorithm.HashAlgorithmSm3;
            }
            else
            {
                return -1;
            }


        }

        private static DateTime GetDateTime(string str)
        {
            int length = str.Length;
            if (length < 15)
            {
                throw new Exception("时间格式错误");
            }


            char[] data = str.ToCharArray();
            for (int i = 0; i < 14; i++)
            {
                if (data[i] > '9' || data[i] < '0')
                {
                    throw new Exception("时间格式错误");
                }
            }
            
            if (data[length - 1] != 'Z')
            {
                throw new Exception("时间格式错误");
            }
            int year = Convert.ToInt32(new String(data, 0, 4), 10);
            int month = Convert.ToInt32(new String(data, 4, 2), 10);
            int day = Convert.ToInt32(new String(data, 6, 2), 10);
            int hour = Convert.ToInt32(new String(data, 8, 2), 10);
            int minute = Convert.ToInt32(new String(data, 10, 2), 10);
            int second = Convert.ToInt32(new String(data, 12, 2), 10);

            if (length == 15)
            {
                return new DateTime(year, month, day, hour, minute, second, DateTimeKind.Utc);
            }
            if (data[14] != '.')
            {
                throw new Exception("时间格式错误");
            }

            if (length == 16)
            {
                return DateTime.MinValue;
            }

            for (int i = 15; i < length - 1; i++)
            {
                if (data[i] < '0' || data[i] > '9')
                {
                    throw new Exception("时间格式错误");
                }
            }

            int l = 0;
            int mul = 100;
            for (int i = 15; i < length - 1; i++)
            {
                l += (data[i] - '0') * mul;
                mul /= 10;
                if (mul == 0)
                {
                    break;
                }
            }
            int ms = l;
            return new DateTime(year, month, day, hour, minute, second, ms, DateTimeKind.Utc);

        }
    }
}
