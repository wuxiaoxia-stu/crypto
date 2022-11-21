var envobj;
var cipher;
var clear;
var argobj;
var fs;

argobj= WScript.Arguments;

if(argobj.length!=1)
{
    //envelopeddata文件必须是BER编码的
	WScript.Echo("Usage: env2.js envelopeddata");
	WScript.Quit (-1);
}
fs=new ActiveXObject("LittleUtils.BinaryFile");
cipher=fs.Read(argobj(0));
fs=null;

envobj=new ActiveXObject("NetcaPki.EnvelopedData");

clear=envobj.Decrypt(cipher);

envobj.GetDecryptCertificate().Display();

