using System;
using Netca.Pki;

namespace Store
{
    class Program
    {
        static void Main(string[] args)
        {
            using (CertStore store = new CertStore(CertStore.CertificateStoreTypeCurrentUser,CertStore.CertificateStoreNameMy))
            {
                int count = store.GetCertificateCount();
                for (int i = 0; i < count; i++)
                { 
                    Certificate cert=store.GetCertificate(i);
                    if (cert != null)
                    {
                        using (cert)
                        {
                            Console.WriteLine(cert.Subject);
                        }
                    }
                }
            }
        }
    }
}
