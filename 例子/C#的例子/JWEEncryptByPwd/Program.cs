using System;
using System.Text;
using System.IO;
using Netca.Pki;

namespace JWEEncryptByPwd
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3 && args.Length != 2)
            {
                Console.WriteLine("Usage: JWEEncryptByPwd [-compact] pwd clear");
                return;
            }
            int type;
            string pwd;
            string clear;

            if (args.Length == 3)
            {
                if (args[0] != "-compact")
                {
                    Console.WriteLine("Usage: JWEEncryptByPwd [-compact] pwd clear");
                    return;
                }
                type = Jwe.CompactSerialization;
                pwd = args[1];
                clear = args[2];

            }
            else
            {
                type = Jwe.JsonSerialization;
                pwd = args[0];
                clear = args[1];
            }

            using (Jwe jweObj = new Jwe(type))
            {
                int cekAlgo = Algorithm.JWEAlgorithmAes256Gcm;
                jweObj.SetContentEncAlgo(cekAlgo);

                int kekAlgo = Algorithm.JWEAlgorithmPbes2HmacSha512Aes256Keywrap;
                byte[] salt=Util.GenerateRandom(32);
                UTF8Encoding encode = new UTF8Encoding();
                byte[] key=encode.GetBytes(pwd);
                jweObj.AddPbes2Key(kekAlgo,key,salt,8192);
                string jweString = jweObj.Encrypt(encode.GetBytes(clear));
                Console.WriteLine(jweString);
            }
        }
    }
}
