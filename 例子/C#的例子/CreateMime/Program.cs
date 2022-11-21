using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using Netca.Pki;

namespace CreateMime
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: CreateMime string outFileName");
                return;
            }
            string str = args[0];
            string outFileName = args[1];
            UTF8Encoding utf8Encode=new UTF8Encoding();
            
            byte[] data = utf8Encode.GetBytes(str);
            string body = Base64.Base64Encode(0, data);

            byte[] mimeData;
            using (Smime mime = new Smime(Smime.MimeTypeBasic))
            {
                mime.AddHeader("Content-Type", "text/plain", new string[] { "charset=\"utf-8\"" });
                mime.AddHeader("Content-Transfer-Encoding", "base64");
                mime.SetBody(body);

                mimeData = mime.Encode();
            }
            using (FileStream outStream = new FileStream(outFileName, FileMode.Create, FileAccess.Write))
            {
                outStream.Write(mimeData, 0, mimeData.Length);
            }
            Console.WriteLine("Success");
        }
    }
}
