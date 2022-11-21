using System;
using System.IO;
using Netca.Pki;

namespace AttachTimeStamp
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Usage: AttachTimeStamp oldSignFile url newSignFile");
                return;
            }
            string oldSignFileName = args[0];
            string url = args[1];
            string newSignFileName = args[2];
            byte[] outData;
            using (SignedData s = new SignedData(false))
            {
                s.SetMultipleSign();
                s.VerifyInit();

                using (FileStream inStream = new FileStream(oldSignFileName, FileMode.Open, FileAccess.Read))
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
                        s.VerifyUpdate(inData, 0, len);
                    }
                }
                s.VerifyFinal();
                AttachTimeStamp(s,url);
                outData=s.Encode();
                using (FileStream outStream = new FileStream(newSignFileName, FileMode.Create, FileAccess.Write))
                {
                    outStream.Write(outData, 0, outData.Length);
                }

                Console.WriteLine("Success");
            }
        }

        private static void AttachTimeStamp(SignedData s,string url)
        {
            string hexSignValue = s.GetStringAttribute(SignedData.SignedDataAttributeSignatureValue, 0);
            byte[] signValue=HexDecode(hexSignValue);
            byte[] token=GetTimeStampToken(signValue,url);
            byte[] attrValue=Util.EncodeSetOf(token);
            s.AddUnsignedAttribute(0,"1.2.840.113549.1.9.16.2.14",attrValue);
        }

        private static byte[] GetTimeStampToken(byte[] data, string url)
        {
            using (TimeStamp ts = new TimeStamp())
            {
                ts.TsaURL = new Uri(url);
                int algo = Netca.Pki.Algorithm.HashAlgorithmSha1;
                ts.HashAlgorithm = algo;
                ts.MessageImprint = Hash.ComputeHash(algo, data);
                int status = ts.GetResponse();
                if (status != TimeStamp.TimeStampRespStatusGranted
                    && status != TimeStamp.TimeStampRespStatusGrantedWithMods)
                {
                    Console.WriteLine("获取TSA响应失败({0})", status);
                    throw new Exception("获取TSA响应失败");
                }

                Console.WriteLine("时间戳时间：{0}", ts.GetTime().ToLocalTime());
                return ts.Token;
           }

        }

        private static byte[] HexDecode(string str)
        {
            char [] chs=str.ToCharArray();
            if (chs.Length % 2 != 0)
            {
                throw new Exception("bad hex string");
            }
            byte[] data = new byte[chs.Length / 2];
            for (int i = 0, j = 0; i < chs.Length; i+=2, j ++)
            {
                data[j] = HexDecodeOneByte(chs[i], chs[i+1]);
            }
            return data;
        }

        private static byte HexDecodeOneByte(char highChar, char lowChar)
        {
            int high = HexDecodeHalfByte(highChar);
            int low = HexDecodeHalfByte(lowChar);
            return (byte)((high << 4) | low);
        }

        private static int HexDecodeHalfByte(char ch)
        {
            if (ch >= '0' && ch <= '9')
            {
                return ch - '0';
            }
            else if (ch >= 'a' && ch <= 'f')
            {
                return ch - 'a'+10;
            }
            else if (ch >= 'A' && ch <= 'F')
            {
                return ch - 'A' + 10;
            }
            else
            {
                throw new Exception("bad hex string");
            }
        }
    }
}

