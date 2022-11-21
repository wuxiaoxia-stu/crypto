var utilobj;
var certobj;
var certverifyobj;
var argobj;
var fs;
var cert;
var i;
var status;
var count;

argobj= WScript.Arguments;

if(argobj.length<2)
{
    WScript.Echo("Usage: signeddata1.js rootcert [cacert...] eecert");
    WScript.Quit (-1);
}

certverifyobj=new ActiveXObject("NetcaPki.CertVerify");

certverifyobj.Option=0;

fs=new ActiveXObject("LittleUtils.BinaryFile");
cert=fs.Read(argobj(0));
fs=null;

certobj=new ActiveXObject("NetcaPki.Certificate");
certobj.Decode(cert);

certverifyobj.AddRootCert(certobj);

for(i=1;i<argobj.length-1;i++)
{
    fs=new ActiveXObject("LittleUtils.BinaryFile");
    cert=fs.Read(argobj(i));
    fs=null;

    certobj=new ActiveXObject("NetcaPki.Certificate");
    certobj.Decode(cert);

    certverifyobj.AddCACert(certobj);
}

fs=new ActiveXObject("LittleUtils.BinaryFile");
cert=fs.Read(argobj(i));
fs=null;

certobj=new ActiveXObject("NetcaPki.Certificate");
certobj.Decode(cert);

status=certverifyobj.Verify(certobj);

WScript.Echo(status);

count=certverifyobj.GetCertificateCount();
for(i=1;i<=count;i++)
{
    certverifyobj.GetCertificate(i).Display();
}

