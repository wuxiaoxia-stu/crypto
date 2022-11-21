using System;
using System.Text;
using System.IO;
using Netca.Pki;

namespace JWEDecryptByCert
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 1 && args.Length != 2)
            {
                Console.WriteLine("Usage: JWEDecryptByCert [-compact] jwe");
                return;
            }
            int type;
            string jweString;
            
            if (args.Length == 2)
            {
                if (args[0] != "-compact")
                {
                    Console.WriteLine("Usage: JWEDecryptByCert [-compact] jwe");
                    return;
                }
                type = Jwe.CompactSerialization;
                jweString = args[1];
                
            }
            else
            {
                type = Jwe.JsonSerialization;
                jweString = args[0];
                
            }

            using (Jwe jweObj = new Jwe(type, jweString))
            {
                using (Certificate cert = Certificate.GetUserCertByConfig(Certificate.GetUserCertTypeEncrypt))
                {
                    jweObj.SetDecryptCert(0, cert);
                }
                byte[] clear = jweObj.Decrypt();
                UTF8Encoding encode = new UTF8Encoding();
                Console.WriteLine(encode.GetString(clear));
            }

        }
    }
}
