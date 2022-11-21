using System;
using System.Text;
using System.IO;
using Netca.Pki;

namespace JWEDecryptByPwd
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3 && args.Length != 2)
            {
                Console.WriteLine("Usage: JWEDecryptByPwd [-compact] pwd jwe");
                return;
            }
            int type;
            string pwd;
            string jweString;

            if (args.Length == 3)
            {
                if (args[0] != "-compact")
                {
                    Console.WriteLine("Usage: JWEDecryptByPwd [-compact] pwd jwe");
                    return;
                }
                type = Jwe.CompactSerialization;
                pwd = args[1];
                jweString = args[2];

            }
            else
            {
                type = Jwe.JsonSerialization;
                pwd = args[0];
                jweString = args[1];

            }

            using (Jwe jweObj = new Jwe(type, jweString))
            {
                UTF8Encoding encode = new UTF8Encoding();
                jweObj.SetKey(0, encode.GetBytes(pwd));
                byte[] clear = jweObj.Decrypt();
                Console.WriteLine(encode.GetString(clear));
            }

        }
    }
}
