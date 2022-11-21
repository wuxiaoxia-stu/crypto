using System;
using System.IO;
using Netca.Pki;

namespace AesGcm
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 6 && args.Length != 7)
            {
                Console.WriteLine("Usage: AesGcm -e|-d key iv tLen [aad] inFileName outFileName");
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
                Console.WriteLine("Usage: AesGcm -e|-d key iv tLen [aad] inFileName outFileName");
                return;
            }

            byte[] key = HexDecode(args[1]);
            byte[] iv = HexDecode(args[2]);
            int tLen = int.Parse(args[3]);
            byte[] aad = null;
            string inFileName;
            string outFileName;
            if (args.Length == 6)
            {
                inFileName = args[4];
                outFileName = args[5];
            }
            else
            {
                aad = HexDecode(args[4]);
                inFileName = args[5];
                outFileName = args[6];
            }

            int algo = Netca.Pki.Algorithm.EncryptAlgorithmAesGcm;

            using (Cipher c = new Cipher(enc, algo))
            {
                c.Key = key;
                if (args.Length == 6)
                {
                    c.SetGcmParam(tLen, iv);
                }
                else
                {
                    c.SetGcmParam(tLen, iv,aad);
                }

                c.Init();
                FileInfo  f = new FileInfo (inFileName);
                if (f.Length > int.MaxValue)
                {
                    Console.WriteLine("file too large");
                    return ;
                }

                using (FileStream inStream = f.OpenRead())
                {
                    byte[] inData = new byte[f.Length];
                    inStream.Read(inData, 0, inData.Length);
                    byte[] outData;

                    outData = c.DoCipher(inData);
                    using (FileStream outStream = new FileStream(outFileName, FileMode.Create, FileAccess.Write))
                    {
                        outStream.Write(outData, 0, outData.Length);
                    }

                    Console.WriteLine("Success");
                    
                }
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
    }
}
