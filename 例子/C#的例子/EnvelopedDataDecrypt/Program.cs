using System;
using System.IO;
using Netca.Pki;

namespace EnvelopedDataDecrypt
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: EnvelopedDataDecrypt infile outfile");
                return;
            }

            using (EnvelopedData env = new EnvelopedData(false))
            {
                env.DecryptInit();
                using (FileStream inStream = new FileStream(args[0], FileMode.Open, FileAccess.Read))
                {
                    byte[] inData=new byte[8192];
                    int len;
                    using (FileStream outStream = new FileStream(args[1], FileMode.Create, FileAccess.Write))
                    {
                        byte[] outData;
                        for (; ; )
                        {
                            len = inStream.Read(inData, 0, inData.Length);
                            if (len == 0)
                            {
                                break;
                            }
                            outData = env.DecryptUpdate(inData, 0, len);
                            if (outData.Length > 0)
                            {
                                outStream.Write(outData, 0, outData.Length);
                            }
                        }
                                            
                    }
                    env.DecryptFinal();

                    using(Certificate cert = env.GetDecryptCertificate())
                    {
                        Console.WriteLine(cert.Subject);
                    }
                }
            }
        }
    }
}
