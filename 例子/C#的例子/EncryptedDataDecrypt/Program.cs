using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace EncryptedDataDecrypt
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Usage: EncryptedDataDecrypt pwd cipherFile clearFile");
                return;
            }
            string pwd = args[0];
            byte[] cipher = GetFileContent(args[1]);
            byte[] clear = EncryptedData.DecryptByPwd(Encoding.UTF8.GetBytes(pwd), cipher);
            using (FileStream outStream = new FileStream(args[2], FileMode.Create, FileAccess.Write))
            {
                outStream.Write(clear, 0, clear.Length);
            }
            Console.WriteLine("Success");
        }

        private static byte[] GetFileContent(String fileName)
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
    }
}
