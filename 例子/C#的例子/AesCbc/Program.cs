using System;
using System.IO;
using Netca.Pki;

namespace AesCbc
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 5)
            {
                Console.WriteLine("Usage: AesCbc -e|-d key iv inFileName outFileName");
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
                Console.WriteLine("Usage: AesCbc -e|-d key iv inFileName outFileName");
                return;
            }

            byte[] key = HexDecode(args[1]);
            byte[] iv = HexDecode(args[2]);

            int algo = Netca.Pki.Algorithm.EncryptAlgorithmAesCbc;

            using (Cipher c = new Cipher(enc, algo))
            { 
                c.Key=key;
                c.IV=iv;
                c.Padding = Cipher.PaddingPKCS5;
                c.Init();

                using (FileStream inStream = new FileStream(args[3], FileMode.Open, FileAccess.Read))
                {
                    using (FileStream outStream = new FileStream(args[4], FileMode.Create, FileAccess.Write))
                    {
                        byte[] inData = new byte[8192];
                        byte[] outData;

                        int len;
                        for (; ; )
                        {
                            len = inStream.Read(inData, 0, inData.Length);
                            if (len == 0)
                            {
                                break;
                            }

                            outData = c.Update(inData, 0, len);
                            if (outData.Length > 0)
                            {
                                outStream.Write(outData, 0, outData.Length);
                            }
                        }

                        outData = c.Final();
                        if (outData.Length > 0)
                        {
                            outStream.Write(outData, 0, outData.Length);
                        }

                        Console.WriteLine("Success");
                    }
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
