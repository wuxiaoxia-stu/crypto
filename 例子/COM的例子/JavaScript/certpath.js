var certobj;
var certpathobj;
var argobj;
var fs;
var cert;

argobj= WScript.Arguments;

if(argobj.length!=1)
{
	WScript.Echo("Usage: certpath.js cert");
    WScript.Quit (-1);
}
fs=new ActiveXObject("LittleUtils.BinaryFile");
cert=fs.Read(argobj(0));
fs=null;

certobj=new ActiveXObject("NetcaPki.Certificate");
certobj.Decode(cert);

certpathobj=new ActiveXObject("NetcaPki.CertPath");
if (certpathobj.Build(certobj) == false)
{
    WScript.Echo("构造证书链失败");
    WScript.Quit (-1);
}


var count;

count=certpathobj.GetCertificateCount();
for(var i=1;i<=count;i++)
{
    certpathobj.GetCertificate(i).Display();
}

