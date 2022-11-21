using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace JWSVerify
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3 && args.Length != 4)
            {
                Console.WriteLine("Usage: JWSVerify [-compact] certFileName payLoad jws");
                return;
            }
            int type;
            string certFileName;
            string payLoad;
            string jwsString;

            if (args.Length == 4)
            {
                if (args[0] != "-compact")
                {
                    Console.WriteLine("Usage: JWSVerify [-compact] certFileName payLoad jws");
                    return;
                }
                type = Jws.CompactSerialization;
                certFileName = args[1];
                payLoad = args[2];
                jwsString = args[3];
            }
            else
            {
                type = Jws.JsonSerialization;
                certFileName = args[0];
                payLoad = args[1];
                jwsString = args[2];
            }

            using (Jws jwsObj = new Jws(type, jwsString))
            {
                using (Certificate cert = GetCert(certFileName))
                {
                    if (jwsObj.VerifySignature(0, cert) == false)
                    {
                        Console.WriteLine("verfiy fail");
                    }
                    else
                    {
                        Console.WriteLine("verfiy ok");
                     }
                }
                UTF8Encoding encode = new UTF8Encoding();
                                
                byte[] payLoad2 = encode.GetBytes(payLoad);
                byte[] payLoad3 = jwsObj.GetPayload();

                
                if (ByetArrayEquals(payLoad2, payLoad3) == false)
                {
                    Console.WriteLine("payload mismatch");
                }
            }

        }

        static bool ByetArrayEquals(byte[] b1, byte[] b2)
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

        static byte[] GetFileContent(string fileName)
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

        static Certificate GetCert(string fileName)
        {
            return new Certificate(GetFileContent(fileName));
        }
    }
}
