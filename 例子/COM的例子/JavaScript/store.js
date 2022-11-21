var NETCAPKI_CERT_STORE_TYPE_CURRENT_USER	  =0;
var NETCAPKI_CERT_STORE_TYPE_LOCAL_MACHINE    =1;

var NETCAPKI_CERT_STORE_NAME_MY = "my";
var NETCAPKI_CERT_STORE_NAME_OTHERS = "others";
var NETCAPKI_CERT_STORE_NAME_CA = "ca";
var NETCAPKI_CERT_STORE_NAME_ROOT = "root";


var NETCAPKI_KEYUSAGE_DIGITALSIGNATURE      = 1;
var NETCAPKI_KEYUSAGE_CONTENTCOMMITMENT     = 2;
var NETCAPKI_KEYUSAGE_KEYENCIPHERMENT       = 4;
var NETCAPKI_KEYUSAGE_DATAENCIPHERMENT      = 8;
var NETCAPKI_KEYUSAGE_KEYAGRESSMENT         = 16;
var NETCAPKI_KEYUSAGE_KEYCERTSIGN           = 32;
var NETCAPKI_KEYUSAGE_CRLSIGN               = 64;
var NETCAPKI_KEYUSAGE_ENCIPHERONLY          = 128;
var NETCAPKI_KEYUSAGE_DECIPHERONLY          = 256;

var certobj;
var storeobj;
var now;
var count;
var i;

storeobj=new ActiveXObject("NetcaPki.Store");
now=new Date();

storeobj.Open(NETCAPKI_CERT_STORE_TYPE_CURRENT_USER,NETCAPKI_CERT_STORE_NAME_MY);
count=storeobj.GetCertificateCount();

for(i=1;i<=count;i++)
{
    certobj=storeobj.GetCertificate(i);
    if(certobj.ValidFromDate<=now && certobj.ValidToDate>=now 
    && (certobj.KeyUsage &(NETCAPKI_KEYUSAGE_DIGITALSIGNATURE|NETCAPKI_KEYUSAGE_CONTENTCOMMITMENT))!=0 )
    {
        certobj.Display();
    }
}
storeobj.Close();
