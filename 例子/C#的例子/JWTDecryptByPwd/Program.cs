using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace JWTDecryptByPwd
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: JWTDecryptByPwd pwd jwt");
                return;
            }
            string pwd = args[0];
            string jwtString = args[1];
            using (Jwt jwtObj = new Jwt(jwtString))
            {
                if (jwtObj.Type != Jwt.JWEType)
                {
                    Console.WriteLine("not encrypt jwt");
                    return;
                }
                UTF8Encoding encode = new UTF8Encoding();
                byte[] key = encode.GetBytes(pwd);
                jwtObj.DecryptByKey(key);
                
                PrintClaim(jwtObj);
            }
        }

        static void PrintClaim(Jwt jwtObj)
        {
            string value = jwtObj.GetClaimStringValue(Jwt.Issuer);
            if (value == null)
            {
                Console.WriteLine("no issuer");
            }
            else
            {
                Console.WriteLine("issuer:" + value);
            }

            value = jwtObj.GetClaimStringValue(Jwt.Subject);
            if (value == null)
            {
                Console.WriteLine("no subject");
            }
            else
            {
                Console.WriteLine("subject:" + value);
            }

            value = jwtObj.GetClaimStringValue(Jwt.JwtId);
            if (value == null)
            {
                Console.WriteLine("no jwt id");
            }
            else
            {
                Console.WriteLine("jwt id:" + value);
            }

            DateTime t;
            bool b;
            b = jwtObj.GetIssuedAt(out t);
            if (b == false)
            {
                Console.WriteLine("no issuer at");
            }
            else
            {
                Console.WriteLine("issuer at:" + t.ToLocalTime());
            }

            b = jwtObj.GetNotBefore(out t);
            if (b == false)
            {
                Console.WriteLine("no not before");
            }
            else
            {
                Console.WriteLine("not before:" + t.ToLocalTime());
            }

            b = jwtObj.GetExpirationTime(out t);
            if (b == false)
            {
                Console.WriteLine("no expiration time");
            }
            else
            {
                Console.WriteLine("expiration time:" + t.ToLocalTime());
            }

            Json aud = jwtObj.GetClaimValue(Jwt.Audience);
            if (aud == null)
            {
                Console.WriteLine("no audience");
            }
            else
            {
                if (aud.Type == Json.StringType)
                {
                    Console.WriteLine("audience:" + aud.StringValue);
                }
                else if (aud.Type == Json.ArrayType)
                {
                    for (int i = 0; i < aud.Count; i++)
                    {
                        if (aud[i].Type != Json.StringType)
                        {
                            Console.WriteLine("bad audience(" + i + ") type");
                        }
                        else
                        {
                            Console.WriteLine("audience(" + i + "):" + aud[i].StringValue);
                        }
                    }
                }
                else
                {
                    Console.WriteLine("bad audience type");
                }
            }


        }
    }
}
