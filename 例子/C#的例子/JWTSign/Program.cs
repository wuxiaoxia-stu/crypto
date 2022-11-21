using System;
using System.IO;
using Netca.Pki;
using System.Text;

namespace JWTSign
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length == 0 || args.Length %2!= 0)
            {
                Console.WriteLine("Usage: JWTSign claimName1 claimValue1 ... claimNameN claimValueN");
                return;
            }

            using (Jwt jwtObj = new Jwt(Jwt.JWSType))
            {
                for (int i = 0; i < args.Length; i += 2)
                {
                    jwtObj.SetClaim(args[i], args[i + 1]);
                }
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
                    
                    string outData = jwtObj.Sign( cert,algo,Jwt.CertIdTypeX5T_S256);
                    Console.WriteLine(outData);
                }
            }
        }
        static int GetSignAlgo(Certificate cert)
        {
            int algo = cert.PublicKeyAlgorithm;
            if (algo == Algorithm.PublicKeyAlgorithmRsa)
            {
                return Algorithm.JWSAlgorithmSha256withRsa;
            }
            else if (algo == Algorithm.PublicKeyAlgorithmEcc)
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
