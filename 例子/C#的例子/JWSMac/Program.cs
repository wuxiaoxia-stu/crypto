using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace JWSMac
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3 && args.Length !=4)
            {
                Console.WriteLine("Usage: JWSMac [-compact] hmac-sha256|hmac-sm3 hexKey payLoad");
                return;
            }

            int type;
            string algoName;
            string hexKey;
            string payLoad;
            if (args.Length == 4)
            {
                if (args[0] != "-compact")
                {
                    Console.WriteLine("Usage: JWSMac [-compact] hmac-sha256|hmac-sm3 hexKey payLoad");
                    return;
                }
                type = Jws.CompactSerialization;
                algoName = args[1];
                hexKey = args[2];
                payLoad = args[3];
            }
            else
            {
                type = Jws.JsonSerialization;
                algoName = args[0];
                hexKey = args[1];
                payLoad = args[2];
            }
            byte[] key = HexDecode(hexKey);
            int algo = GetMacAlgo(algoName);
            if (algo == -1)
            {
                Console.WriteLine("bad algo");
                return;
            }
            UTF8Encoding encode = new UTF8Encoding();
            byte[] outData;
            using (Jws jwsObj = new Jws(type))
            {
                jwsObj.SetPayload(encode.GetBytes(payLoad));
                outData = jwsObj.Mac(algo, key);
            }
            Console.WriteLine(encode.GetString(outData));
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
		    if(name=="hmac-sha256")
            {
			    return  Algorithm.JWSAlgorithmHmacSha256;
		    }
            else if(name=="hmac-sha384")
            {
                return Algorithm.JWSAlgorithmHmacSha384;
		    }
            else if(name=="hmac-sha512")
            {
                return Algorithm.JWSAlgorithmHmacSha512;
		    }
            else if(name=="hmac-sm3")
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
