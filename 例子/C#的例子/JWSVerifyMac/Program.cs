using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace JWSVerifyMac
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3 && args.Length != 4)
            {
                Console.WriteLine("Usage: JWSVerifyMac [-compact] hexKey payLoad jws");
                return;
            }
            int type;
            string hexKey;
            string payLoad;
            string jwsString;

            if (args.Length == 4)
            {
                if (args[0] != "-compact")
                {
                    Console.WriteLine("Usage: JWSVerifyMac [-compact] hexKey payLoad jws");
                    return;
                }
                type = Jws.CompactSerialization;
                hexKey = args[1];
                payLoad = args[2];
                jwsString = args[3];
            }
            else
            {
                type = Jws.JsonSerialization;
                hexKey = args[0];
                payLoad = args[1];
                jwsString = args[2];
            }
            byte[] key = HexDecode(hexKey);
            using (Jws jwsObj = new Jws(type, jwsString))
            {
                
                if (jwsObj.VerifyMac(0, key) == false)
                {
                    Console.WriteLine("verfiy fail");
                }
                else
                {
                        Console.WriteLine("verfiy ok");
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

        static byte[] HexDecode(string hex)
        {
            if (hex.Length % 2 != 0)
            {
                throw new InvalidDataException();
            }

            byte[] data = new byte[hex.Length / 2];
            for (int i = 0, j = 0; i < hex.Length; i += 2, j++)
            {
                data[j] = (byte)Convert.ToChar(Int32.Parse(hex.Substring(i, 2), System.Globalization.NumberStyles.HexNumber));
            }
            return data;
        }
    }
}
