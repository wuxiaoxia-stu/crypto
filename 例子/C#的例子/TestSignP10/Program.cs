using System;
using System.IO;
using Netca.Pki;

namespace TestSignP10
{
    class Program
    {
        static void Main(string[] args)
        {
            byte[] p10Data;
            using (Device device = Device.BuiltinSoftwareDevice)
            {
                using (KeyPair keypair = device.GenerateRSAKeyPair(1024, KeyPair.KeyPairTypeSignature, "TestRSA1024KeyPair"))
                {
                    using (CertReq p10 = new CertReq())
                    {
                        p10.Subject = "C=CN,CN=测试123";
                        p10Data = p10.Sign(keypair, Netca.Pki.Algorithm.SignatureAlgorithmSha256withRsa);
                    }
                }
            }

            using (FileStream outStream = new FileStream("test.req", FileMode.Create, FileAccess.Write))
            {
                outStream.Write(p10Data, 0, p10Data.Length);
            }

            Console.WriteLine("Success");
        }
    }
}
