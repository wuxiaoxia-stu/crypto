using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using Netca.Pki;
using Netca.Pki.XmlSecurity;


namespace VerifyXMLSignature
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 1)
            {
                Console.WriteLine("Usage:VerifyXMLSignature xmlSignatureFileName");
                return;
            }
            string xmlSignatureFileName = args[0];
            List<XMLSignature> xmlSignatureList = null;
            XML.Init();
            try
            {
                byte[] xmlData = File.ReadAllBytes(xmlSignatureFileName);
                xmlSignatureList = XMLSignature.GetXMLSignature(xmlData);
                if (xmlSignatureList.Count == 0)
                {
                    Console.WriteLine("not xml signature");
                    return;
                }
                int i = 1;
                foreach (XMLSignature xmlSignature in xmlSignatureList)
                {
                    if (xmlSignature.Verify(0) == false)
                    {
                        Console.WriteLine("Verify XML Signature {0} Fail",i);
                        return;
                    }
                    Console.WriteLine("Verify XML Signature {0} Success", i);
                    Certificate cert = xmlSignature.GetSignCert();
                    if (cert != null)
                    {
                        using (cert)
                        {
                            Console.WriteLine("Sign Cert: {0}", cert.Subject);
                        }
                    }
                    else
                    {
                        Console.WriteLine("no sign cert");
                    }
                    if (xmlSignature.HasSigntureTimeStemp())
                    { 
                        TimeStamp timestampObj;
                        if (xmlSignature.VerifySigntureTimeStamp(out timestampObj) == false)
                        {
                            Console.WriteLine("verify timestamp fail");
                        }
                        else
                        {
                            using (timestampObj)
                            {
                                Console.WriteLine("timestamp:{0}", timestampObj.GetTime().ToLocalTime());
                            }
                        }
                    }
                    i++;
                }
            }
            finally
            {
                if (xmlSignatureList != null)
                {
                    foreach (XMLSignature xmlSignature in xmlSignatureList)
                    {
                        xmlSignature.Dispose();
                    }
                }
                XML.End();
            }
        }
    }
}
