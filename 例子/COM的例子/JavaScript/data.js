

var NETCAPKI_DEVICETYPE_ANY=-1;
var NETCAPKI_DEVICEFLAG_CACHE_PIN_IN_PROCESS=0;
var NETCAPKI_CP_UTF8 = 65001;

var utilobj=new ActiveXObject("NetcaPki.Utilities");
var deviceobj=new ActiveXObject("NetcaPki.Device");
var devicesetobj=new ActiveXObject("NetcaPki.DeviceSet");
var devicecount;

var dataid=10;
var datalength=1024;
var mode="04070707";
var data="���,NETCA";
var databytearray;

try
{
	devicesetobj.GetAllDevice(NETCAPKI_DEVICETYPE_ANY,NETCAPKI_DEVICEFLAG_CACHE_PIN_IN_PROCESS);//��ȡ�����豸
	devicecount=devicesetobj.Count;
	if (devicecount == 0)
	{
		WScript.Echo("������豸��");
		WScript.Quit(-1);
	}
	else if (devicecount > 1)
	{
		WScript.Echo("ֻ�ܲ���һ���豸��");
		WScript.Quit(-1);
	}

	deviceobj=devicesetobj.Item(1);//��ȡ��һ���豸
	deviceobj.CreateData(dataid,mode,datalength);
	WScript.Echo("�������ݳɹ���");
	
	databytearray=utilobj.Encode(data,NETCAPKI_CP_UTF8);
	deviceobj.WriteData(dataid,databytearray);
	WScript.Echo("д�����ݳɹ���\nд�����ݣ�"+data);
	
	databytearray=deviceobj.ReadData(dataid)
	data=utilobj.Decode(databytearray,NETCAPKI_CP_UTF8);
	WScript.Echo("��ȡ���ݳɹ���\n��ȡ���ݣ�"+data);
	
	deviceobj.DeleteData(dataid);
	WScript.Echo("ɾ�����ݳɹ���");
}
catch(e)
{
	WScript.Echo(e.message+"  ������ : "+e.number);
}
	