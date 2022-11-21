using System;
using System.IO;
using Netca.Pki;

namespace Base64File
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Usage: Base64File -e|-d inFileName outFileName");
                return;
            }

            bool enc;
            int flag = 0;

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
                Console.WriteLine("Usage: Base64File -e|-d inFileName outFileName");
                return;
            }

            using (Base64 b64 = new Base64(enc,flag))
            {
                using (FileStream inStream = new FileStream(args[1], FileMode.Open, FileAccess.Read))
                {
                    using (FileStream outStream = new FileStream(args[2], FileMode.Create, FileAccess.Write))
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
                            if (enc)
                            {
                                outData = b64.EncodeToByteArrayUpdate(inData, 0, len);
                            }
                            else
                            {
                                outData = b64.DecodeUpdate(inData, 0, len);
                            }

                            if (outData.Length > 0)
                            {
                                outStream.Write(outData, 0, outData.Length);
                            }
                        }

                        if (enc)
                        {
                            outData = b64.EncodeToByteArrayFinal();
                            if (outData.Length > 0)
                            {
                                outStream.Write(outData, 0, outData.Length);
                            }
                        }
                        else
                        {
                            b64.DecodeFinal();
                        }
                        
                        Console.WriteLine("Success");

                    }
                }
            }

        }
    }
}

