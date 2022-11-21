import net.netca.pki.*;
import java.io.*;
import java.util.*;

public class GetDeviceInfo
{
	public static void main(String[] arg) throws Exception
	{
		DeviceSet deviceSet;
		int type;
		String sn;
		String pwd;
		Device device;

		if(arg.length==0)
		{
			System.out.println("java.library.path=" + System.getProperty("java.library.path"));
			System.out.println("");

			Map map=DeviceSet.getDeviceInfo();
			printDeviceInfo(map);
			return;
		}
		else if(arg.length==1)
		{
			if(arg[0].equalsIgnoreCase("-listall"))
			{
				Map map=DeviceSet.getDeviceInfo(false);
				printDeviceInfo(map);
				return;
			}
			else
			{
				type=Integer.parseInt(arg[0]);
				deviceSet=new DeviceSet(type,Device.DEVICE_FLAG_SILENT);
				printDeviceSetInfo(deviceSet);
				deviceSet.free();
				return;
			}
		}
		else if(arg.length==2)
		{
			type=Integer.parseInt(arg[0]);
			sn=arg[1];
			device=Device.findDevice(type,sn,Device.DEVICE_FLAG_SILENT);
			if(device==null)
			{
				System.out.println("No Such Device");
				return;
			}
			printDeviceInfo(device);
			device.free();
		}
		else if(arg.length==3)
		{
			type=Integer.parseInt(arg[0]);
			sn=arg[1];
			pwd=arg[2];
			device=Device.findDevice(type,sn,Device.DEVICE_FLAG_SILENT);
			if(device==null)
			{
				System.out.println("No Such Device");
				return;
			}
			printDeviceInfo(device,pwd);
			device.free();
		}
		else
		{
			System.out.println("Usage: java GetDeviceInfo [type] [sn] [pwd]");
			System.out.println("\tjava GetDeviceInfo -listall");
		}
		
	
	}

	public static void printDeviceInfo(Map map)
	{
		Iterator it;
		Map.Entry entry;
		int type;
		String name;
		it=map.entrySet().iterator();
			
		while (it.hasNext())
		{
			entry=(Map.Entry)it.next();
			type=((Integer)(entry.getKey())).intValue();
			name=(String)entry.getValue();
			System.out.println("type="+type+",\tname="+name);
		}
	}

	public static void printDeviceSetInfo(DeviceSet deviceSet) throws Exception
	{
		int i;
		int count;
		count=deviceSet.count();
		Device device;
		System.out.println("Device Count " + count);
		
		for(i=0;i<count;i++)
		{
			device=deviceSet.get(i);
			printDeviceInfo(device,i+1);
			device.free();
		}
	}

	public static void printDeviceInfo(Device device,int index) throws Exception
	{
		printDeviceInfo(device,index,"");
	}

	public static void printDeviceInfo(Device device) throws Exception
	{
		printDeviceInfo(device,-1,"");
	}


	public static void printDeviceInfo(Device device,String pwd) throws Exception
	{
		printDeviceInfo(device,-1,pwd);
	}

	public static void printDeviceInfo(Device device,int index,String pwd) throws Exception
	{
		if(index>0)
		{
			System.out.println("Device " + index);	
		}
		System.out.println("\ttype:\t" + device.getType());	
		System.out.println("\tSerialNumber:\t" + device.getSerialNumber());	
		System.out.println("\tLabel:\t" + device.getLabel());
		System.out.println("\tClass:\t" + getDeviceName(device.getDeviceClass()));
		if(device.mustLogin())
		{
			System.out.println("\tMustLgin:\tTrue");
			if(pwd.length()==0)
			{
				System.out.println("\tNo Pwd");
				System.out.println("");
				return;
			}
		}
		else
		{
			System.out.println("\tMustLgin:\tFalse");
		}

		if(pwd.length()>0)
		{
			if(device.verifyPwd(Device.USER_PWD,pwd)==false)
			{
				System.out.println("\tPwd Error");
				System.out.println("");
				return;
			}
		}

		int keypairCount=device.getKeyPairCount();
		System.out.println("\tKeyPair Count " + keypairCount);
		int i;

		KeyPair keypair;
		for(i=0;i<keypairCount;i++)
		{
			keypair=device.getKeyPair(i);
			printKeyPairInfo(keypair,i+1);
			keypair.free();
		}
		System.out.println("");
	}



	public static String getDeviceName(int deviceClass)
	{
		if(deviceClass==Device.DEVICE_CLASS_USB)
		{
			return "USB";
		}
		else if(deviceClass==Device.DEVICE_CLASS_NETWORK)
		{
			return "NETWORK";
		}
		else if(deviceClass==Device.DEVICE_CLASS_BUILDIN)
		{
			return "BUILDIN";
		}
		else if(deviceClass==Device.DEVICE_CLASS_PCI)
		{
			return "PCI";
		}
		else
		{
			return "Unknown Device Class ("+ deviceClass+")";	
		}
	}

	public static void printKeyPairInfo(KeyPair keypair,int index) throws Exception
	{
		System.out.println("\tKeyPair " + index);	
		System.out.println("\t\tType:\t" + getKeyPairType(keypair.getType()));
		System.out.println("\t\tLabel:\t" + keypair.getLabel());
		System.out.println("\t\tAlgorithm:\t" + getKeyPairAlgorithm(keypair.getAlgorithm()));
		System.out.println("\t\tBits:\t" + keypair.getBits());

		int certCount=keypair.getCertificateCount();
		System.out.println("\t\tCertificate Count " + certCount);
		/*
		Certificate cert;
		for(int i=0;i<certCount;i++)
		{
			cert=keypair.getCertificate(i);
			if(cert!=null)
			{

				cert.free();
			}
		}
		*/
	}

	public static String getKeyPairType(int type)
	{
		if(type==KeyPair.ENCRYPT)
		{
			return "ENCRYPT";
		}
		else if(type==KeyPair.SIGNATURE)
		{
			return "SIGNATURE";
		}
		else if(type==KeyPair.KEYAGREEMENT)
		{
			return "KEYAGREEMENT";
		}
		else
		{
			return "Unknown KeyPair Type ("+ type+")";	
		}
	}

	public static String getKeyPairAlgorithm(int algo)
	{
		if(algo==KeyPair.RSA)
		{
			return "RSA";
		}
		else if(algo==KeyPair.DSA)
		{
			return "DSA";
		}
		else if(algo==KeyPair.DH)
		{
			return "DH";
		}
		else if(algo==KeyPair.ECC)
		{
			return "ECC";
		}
		else
		{
			return "Unknown KeyPair Algorithm ("+ algo+")";	
		}
	}

	
}

