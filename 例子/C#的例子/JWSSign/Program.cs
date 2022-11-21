using System;
using System.IO;
using Netca.Pki;
using System.Text;
namespace JWSSign
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 1 && args.Length != 2)
            {
                Console.WriteLine("Usage: JWSSign [-compact] payLoad");
                return;
            }
            int type;
            string payLoad;
            if (args.Length == 2)
            {
                if (args[0] != "-compact")
                {
                    Console.WriteLine("Usage: JWSSign [-compact] payLoad");
                    return;
                }
                type = Jws.CompactSerialization;
                payLoad = args[1];
            }
            else
            {
                type = Jws.JsonSerialization;
                payLoad = args[0];
            }
            UTF8Encoding encode = new UTF8Encoding();
            byte[] outData;
            using (Jws jwsObj = new Jws(type))
            {
                jwsObj.SetCertIdType(Jws.CertIdTypeX5T_S256);
                
                jwsObj.SetPayload(encode.GetBytes(payLoad));
                
                using (Certificate cert = Certificate.GetUserCertByConfig(Certificate.GetUserCertTypeSign))
                {
                    if (cert == null)
                    {
                        Console.WriteLine("no sign cert");
                        return;
                    }
                    int algo;
                    algo = GetSignAlgo(cert);
                    if (algo == -1)
                    {
                        Console.WriteLine("unsupport cert");
                        return;
                    }
                    outData = jwsObj.Sign(algo, cert);
                }
             }
             Console.WriteLine(encode.GetString(outData));
        }

        static int GetSignAlgo(Certificate cert)
        {
            int algo = cert.PublicKeyAlgorithm;
            if (algo == Algorithm.PublicKeyAlgorithmRsa)
            {
                return Algorithm.JWSAlgorithmSha256withRsa;
            }
            else if(algo==Algorithm.PublicKeyAlgorithmEcc)
            {
                int curve = cert.GetIntegerAttribute(Certificate.CertificateAttributeTypePublicKeyECCCurve);
                if (curve == KeyPair.EccCurveP256)
                {
                    return Algorithm.JWSAlgorithmEcdsawithSha256;
                }
                else if (curve == KeyPair.EccCurveP384)
                {
                    return Algorithm.JWSAlgorithmEcdsawithSha384;
                }
                else if (curve == KeyPair.EccCurveP521)
                {
                    return Algorithm.JWSAlgorithmEcdsawithSha512;
                }
                else if (curve == KeyPair.EccCurveSM2)
                {
                    return Algorithm.JWSAlgorithmSm3withSm2;
                }

            }
            return -1;
        }
    }
}
