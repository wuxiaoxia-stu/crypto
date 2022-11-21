using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace CreateAttachment
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: CreateAttachment attachmentFileName outFileName");
                return;
            }
            string attachmentFileName = args[0];
            string outFileName = args[1];
            byte[] outData;
            using (Smime mime = new Smime(Smime.MimeTypeMultiPart))
            {
                string boundary = mime.GetBoundary();
                mime.AddHeader("Content-Type", "multipart/mixed", new string[] { "boundary=\""+boundary+"\"" });
                using (Smime contentMime = CreateContent())
                {
                    mime.AddSubEntity(contentMime);
                }
                using (Smime attachMime = Smime.NewAttach(null, IsAscii(attachmentFileName) ? null : "GBK", attachmentFileName))
                {
                    mime.AddSubEntity(attachMime);
                }
                outData = mime.Encode();
            }
            using (FileStream outStream = new FileStream(outFileName, FileMode.Create, FileAccess.Write))
            {
                outStream.Write(outData, 0, outData.Length);
            }
            Console.WriteLine("Success");
        }

        private static Smime CreateContent()
        {
            Smime mime = new Smime(Smime.MimeTypeBasic);
            try
            {
                mime.AddHeader("Content-Type", "text/plain", new string[] { "charset=\"GBK\"" });
                mime.AddHeader("Content-Transfer-Encoding", "quoted-printable");

                byte[] data = Encoding.GetEncoding("GBK").GetBytes("¸½¼þ²âÊÔ");
                byte[] body = Smime.QuotedPrintableEncode(data);
                mime.SetBody(body);
                return mime;
            }
            catch (Exception)
            {
                throw;
            }

        }

        private static bool IsAscii(string str)
        {
            foreach(char ch in str)
            {
                if(ch<0 || ch>127)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
