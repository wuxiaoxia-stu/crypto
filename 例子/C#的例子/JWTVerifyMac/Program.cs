using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace JWTVerifyMac
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Usage: JWTVerifyMac hexKey jwt");
                return;
            }
            string hexKey = args[0];
            string jwtString = args[1];
            byte[] key = HexDecode(hexKey);
            using (Jwt jwtObj = new Jwt(jwtString))
            {
                if (jwtObj.Type != Jwt.JWSType)
                {
                    Console.WriteLine("not sign jwt");
                    return;
                }

                if (jwtObj.VerifyMac(key) == false)
                {
                    Console.WriteLine("verify fail");
                    return;
                }
                else
                {
                     Console.WriteLine("verify ok");
                }
                
                PrintClaim(jwtObj);
            }
        }
        static byte[] HexDecode(string hex)
        {
            if (hex.Length % 2 != 0)
            {
                throw new InvalidDataException();
            }

            byte[] data = new byte[hex.Length / 2];
            for (int i = 0, j = 0; i < hex.Length; i += 2, j++)
            {
                data[j] = (byte)Convert.ToChar(Int32.Parse(hex.Substring(i, 2), System.Globalization.NumberStyles.HexNumber));
            }
            return data;
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
