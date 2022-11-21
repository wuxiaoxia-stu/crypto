using System;
using System.Collections.Generic;
using System.Xml;
using System.Text;
using System.IO;
using Netca.Pki;
using Netca.Pki.XmlSecurity;

namespace XMLSign
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.WriteLine("Usage:XMLSign xmlTemplateFileName refUri xmlSignatureFileName");
                return ;
            }

            string xmlTemplateFileName = args[0];
            string refUri = args[1];
            string xmlSignatureFileName = args[2];
            Certificate cert = null;
            XML.Init();
            try
            {
                XmlDocument doc = new XmlDocument();
                doc.PreserveWhitespace = true;
                doc.Load(xmlTemplateFileName);
                cert = Certificate.SelectCert("Signature", null);
                if (cert == null)
                {
                    Console.WriteLine("no sign cert");
                    return;
                }
                XmlNodeList signNodeList = doc.GetElementsByTagName("Signature","http://www.w3.org/2000/09/xmldsig#");
                if (signNodeList.Count == 0)
                {
                    Console.WriteLine("bad xmlTemplateFileName no xml signature node");
                    return;
                }

                XmlElement signNode = (XmlElement)signNodeList[0];
                XMLSignatureBuilder buider = new XMLSignatureBuilder();

                Reference refObj = new Reference(Reference.Sha256, refUri);
                buider.AddReference(refObj);
                int algo = GetXMLSignatureAlgorithm(cert);
                if (algo == -1)
                {
                    Console.WriteLine("bad cert");
                    return;
                }
                buider.SetSignatureMethod(algo);
                buider.SetCanonicalizationMethod(XMLSignature.C14N);
                byte[] xmlData=buider.SignToByteArray(signNode, cert);
                using (FileStream outStream = new FileStream(xmlSignatureFileName, FileMode.Create, FileAccess.Write))
                {
                    outStream.Write(xmlData, 0, xmlData.Length);
                }
                Console.WriteLine("Success");
            }
            finally
            {
                if (cert != null)
                {
                    cert.Dispose();
                }
                XML.End();
            }

        }

        static int GetXMLSignatureAlgorithm(Certificate cert)
        {
            if (cert.Match("Algorithm='SM2'"))
            {
                return XMLSignature.Sm2Sm3;
            }
            else if (cert.Match("Algorithm='RSA'"))
            {
                return XMLSignature.RsaSha256;
            }
            else if (cert.Match("Algorithm='ECC'"))
            {
                return XMLSignature.EcdsaSha1;
            }
            else
            {
                return -1;
            }
             
        }
    }
}
