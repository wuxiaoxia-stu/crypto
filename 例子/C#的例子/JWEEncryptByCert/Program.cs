using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace JWEEncryptByCert
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3 && args.Length != 2)
            {
                Console.WriteLine("Usage: JWEEncryptByCert [-compact] certFileName clear");
                return;
            }
            int type;
            string certFileName;
            string clear;
            
            if (args.Length == 3)
            {
                if (args[0] != "-compact")
                {
                    Console.WriteLine("Usage: JWEEncryptByCert [-compact] certFileName clear");
                    return;
                }
                type = Jwe.CompactSerialization;
                certFileName = args[1];
                clear = args[2];
                
            }
            else
            {
                type = Jwe.JsonSerialization;
                certFileName = args[0];
                clear = args[1];
            }

            using (Jwe jweObj = new Jwe(type))
            {
                using (Certificate cert = GetCert(certFileName))
                { 
                    int cekAlgo=GetCEKAlgo(cert);
			        if(cekAlgo==-1)
                    {
                        Console.WriteLine("bad cert");
				        return;
			        }
                    jweObj.SetContentEncAlgo(cekAlgo);

                    int kekAlgo = GeKEKAlgo(cert);
                    if (cekAlgo == -1)
                    {
                        Console.WriteLine("bad cert");
                        return;
                    }
                    jweObj.AddCert(kekAlgo, cert, Jwe.CertIdTypeX5T_S256);

                }
                UTF8Encoding encode = new UTF8Encoding();
                string jweString=jweObj.Encrypt(encode.GetBytes(clear));
                Console.WriteLine(jweString);
            }
        }

        static byte[] GetFileContent(string fileName)
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

        static Certificate GetCert(string fileName)
        {
            return new Certificate(GetFileContent(fileName));
        }

        private static int GetCEKAlgo(Certificate cert)
        {
		    if(cert.Match("Algorithm='RSA'"))
            {
			    return  Algorithm.JWEAlgorithmAes256Gcm;
		    }
            else if(cert.Match("Algorithm='SM2'"))
            {
			    return Algorithm.JWEAlgorithmSm4CbcHmacSm3;
		    }
            else
            {
			    return -1;
		    }
	    }
	
	    private static int GeKEKAlgo(Certificate cert)
        {
		    if(cert.Match("Algorithm='RSA'"))
            {
                return Algorithm.JWEAlgorithmRsa1_5;
		    }
            else if(cert.Match("Algorithm='SM2'"))
            {
                return Algorithm.JWEAlgorithmSm2;
			}
            else 
            {
			    return -1;
		    }
	    }
    }
}
