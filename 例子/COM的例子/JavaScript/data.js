

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
var data="你好,NETCA";
var databytearray;

try
{
	devicesetobj.GetAllDevice(NETCAPKI_DEVICETYPE_ANY,NETCAPKI_DEVICEFLAG_CACHE_PIN_IN_PROCESS);//获取所有设备
	devicecount=devicesetobj.Count;
	if (devicecount == 0)
	{
		WScript.Echo("请插入设备！");
		WScript.Quit(-1);
	}
	else if (devicecount > 1)
	{
		WScript.Echo("只能插入一个设备！");
		WScript.Quit(-1);
	}

	deviceobj=devicesetobj.Item(1);//获取第一个设备
	deviceobj.CreateData(dataid,mode,datalength);
	WScript.Echo("创建数据成功！");
	
	databytearray=utilobj.Encode(data,NETCAPKI_CP_UTF8);
	deviceobj.WriteData(dataid,databytearray);
	WScript.Echo("写入数据成功！\n写入数据："+data);
	
	databytearray=deviceobj.ReadData(dataid)
	data=utilobj.Decode(databytearray,NETCAPKI_CP_UTF8);
	WScript.Echo("读取数据成功！\n读取数据："+data);
	
	deviceobj.DeleteData(dataid);
	WScript.Echo("删除数据成功！");
}
catch(e)
{
	WScript.Echo(e.message+"  错误码 : "+e.number);
}
	