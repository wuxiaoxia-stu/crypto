using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace JWTMac
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length <=2 || args.Length %2!= 0)
            {
                Console.WriteLine("Usage: JWTMac hmac-sha256|hmac-sm3 hexKey claimName1 claimValue1 ... claimNameN claimValueN");
                return;
            }

            byte[] key = HexDecode(args[1]);
            int algo = GetMacAlgo(args[0]);
            if (algo == -1)
            {
                Console.WriteLine("bad algo");
                return;
            }
            using (Jwt jwtObj = new Jwt(Jwt.JWSType))
            {
                for (int i = 2; i < args.Length; i += 2)
                {
                    jwtObj.SetClaim(args[i], args[i + 1]);
                }
                string outData=jwtObj.Mac(algo, key);
                Console.WriteLine(outData);
            }
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

        private static int GetMacAlgo(string name)
        {
            if (name == "hmac-sha256")
            {
                return Algorithm.JWSAlgorithmHmacSha256;
            }
            else if (name == "hmac-sha384")
            {
                return Algorithm.JWSAlgorithmHmacSha384;
            }
            else if (name == "hmac-sha512")
            {
                return Algorithm.JWSAlgorithmHmacSha512;
            }
            else if (name == "hmac-sm3")
            {
                return Algorithm.JWSAlgorithmHmacSm3;
            }
            else
            {
                return -1;
            }
        }
    }
}
