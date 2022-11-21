using System;
using System.IO;
using Netca.Pki;

namespace AesFF1
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 6)
            {
                Console.WriteLine("Usage: AesFF1 -e|-d key radix tweak inFileName outFileName");
                return;
            }
            bool enc;

            if (args[0] == "-e" || args[0] == "/e")
            {
                enc = true;
            }
            else if (args[0] == "-d" || args[0] == "/d")
            {
                enc = false;
            }
            else
            {
                Console.WriteLine("Usage: AesFF1 -e|-d key radix tweak inFileName outFileName");
                return;
            }

            byte[] key = HexDecode(args[1]);
            int radix;
            if (int.TryParse(args[2], out radix) == false)
            {
                Console.WriteLine("radix不是整数");
                return;
            }
            if (radix < 2 || radix > 65535)
            {
                Console.WriteLine("radix不符合要求");
                return;
            }
            if (radix > 256)
            {
                Console.WriteLine("不支持太大的radix");
                return;
            }

            byte[] tweak = HexDecode(args[3]);

            string inFileName = args[4];
            string outFileName = args[5];
            byte[] inData = File.ReadAllBytes(inFileName);
            int algo = Netca.Pki.Algorithm.EncryptAlgorithmAesFf1;
            byte[] outData;
            using (Cipher c = new Cipher(enc, algo))
            {
                c.Key = key;
                c.SetFF1Param(radix, tweak);
                c.Init();
                outData = c.DoCipher(inData);
            }
            using (FileStream outStream = new FileStream(outFileName, FileMode.Create))
            {
                outStream.Write(outData, 0, outData.Length);
            }
            Console.WriteLine("Success");
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
