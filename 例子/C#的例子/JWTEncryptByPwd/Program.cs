using System;
using System.Text;
using System.IO;
using Netca.Pki;

namespace JWTEncryptByPwd
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length < 2 || args.Length % 2 != 1)
            {
                Console.WriteLine("Usage: JWTEncryptByPwd  pwd claimName1 claimValue1 ... claimNameN claimValueN");
                return;
            }
            string pwd = args[0];
            using (Jwt jwtObj = new Jwt(Jwt.JWEType))
            {
                for (int i = 1; i < args.Length; i += 2)
                {
                    jwtObj.SetClaim(args[i], args[i + 1]);
                }
                int cekAlgo = Algorithm.JWEAlgorithmAes256Gcm;
                
                int kekAlgo = Algorithm.JWEAlgorithmPbes2HmacSha512Aes256Keywrap;
                byte[] salt = Util.GenerateRandom(32);
                UTF8Encoding encode = new UTF8Encoding();
                byte[] key = encode.GetBytes(pwd);
                string outData= jwtObj.EncryptByPbes2(cekAlgo,key,kekAlgo,salt,8192);
                Console.WriteLine(outData);
            }
        }
    }
}
