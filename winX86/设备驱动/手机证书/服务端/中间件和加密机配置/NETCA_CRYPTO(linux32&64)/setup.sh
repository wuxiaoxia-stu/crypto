#！/bin/bash
CurrentPath=$(cd "$(dirname "$0")"; pwd);
CurrentPath=$(cd "$(dirname "$0")"; pwd);
Trash=${CurrentPath}"/Trash";
libpath="";

#$1 : 32 or 64
#$2 : 2.6.18 or 2.6.32 or 3.10.0
function check_sqlite()
{
	local version="";
	local sqlite="";

	if [ "$1" == "32" ]; then
		sqlite=`rpm -qa | grep ^sqlite | grep i386`
		if [ "$sqlite" == "" ]; then
			sqlite=`rpm -qa | grep ^sqlite | grep i686`
		fi
		
		if [ "$sqlite" == "" ]; then
			if [ "$2" == "2.6.18" ]; then
				echo -e "NETCA Info: Please install sqlite.i386 or sqlite.i686 3.3.X-X\n"
			elif [ "$2" == "2.6.32" ]; then
				echo -e "NETCA Info: Please install sqlite.i386 or sqlite.i686 3.6.X-X\n"
			elif [ "$2" == "3.10.0" ]; then
				echo -e "NETCA Info: Please install sqlite.i386 or sqlite.i686 3.7.X-X\n"
			else
				echo -e "NETCA Info: not support this version\n"
			fi
			
			return 0;
		else
			version=`echo $sqlite | cut -d ' ' -f 2`;
			if [ "$2" == "2.6.18" ]; then
				if [[ $version != *3.3.*-* ]]; then
					echo -e "NETCA Info: Please install sqlite.i386 or sqlite.i686 3.3.X-X\n"
					return 0;
				fi

			elif [ "$2" == "2.6.32" ]; then
				if [[ $version != *3.6.*-* ]]; then
					echo -e "NETCA Info: Please install sqlite.i386 or sqlite.i686 3.6.X-X\n"
					return 0;
				fi
				
			elif [ "$2" == "3.10.0" ]; then
				if [[ $version != *3.7.*-* ]]; then
					echo -e "NETCA Info: Please install sqlite.i386 or sqlite.i686 3.7.X-X\n"
					return 0;
				fi
				
			else
				echo -e "NETCA Info: not support this version\n"
				return 0;
			fi
		fi

	elif [ "$1" == "64" ]; then
		sqlite=`rpm -qa | grep ^sqlite | grep x86_64`
		
		if [ "$sqlite" == "" ]; then
			if [ "$2" == "2.6.18" ]; then
				echo -e "NETCA Info: Please install sqlite.x86_64 3.3.X-X\n"
			elif [ "$2" == "2.6.32" ]; then
				echo -e "NETCA Info: Please install sqlite.x86_64 3.6.X-X\n"
			elif [ "$2" == "3.10.0" ]; then
				echo -e "NETCA Info: Please install sqlite.x86_64 3.7.X-X\n"
			else
				echo -e "NETCA Info: not support this system version\n"
			fi
			
			return 0;
		else
			version=`echo $sqlite | cut -d ' ' -f 2`;
			if [ "$2" == "2.6.18" ]; then
				if [[ $version != *3.3.*-* ]]; then
					echo -e "NETCA Info: Please install sqlite.x86_64 3.3.X-X\n"
					return 0;
				fi
				
			elif [ "$2" == "2.6.32" ]; then
				if [[ $version != *3.6.*-* ]]; then
					echo -e "NETCA Info: Please install sqlite.x86_64 3.6.X-X\n"
					return 0;
				fi
				
			elif [ "$2" == "3.10.0" ]; then
				if [[ $version != *3.7.*-* ]]; then
					echo -e "NETCA Info: Please install sqlite.x86_64 3.7.X-X\n"
					return 0;
				fi
				
			else
				echo -e "NETCA Info: not support this system version\n"
				return 0;
			fi
		fi
	fi
	
	echo "$sqlite"
	return 1;
}

#$1 : 32 or 64
#$2 : 2.6.18 or 2.6.32 or 3.10.0
function check_gmp()
{
	local version="";
	local gmp="";

	if [ "$1" == "32" ]; then
		gmp=`rpm =qa | grep ^gmp | grep i386`
		if [ "$gmp" == "" ]; then
			gmp=`rpm =qa | grep ^gmp | grep i686`
		fi
		
		if [ "$gmp" == "" ]; then
			if [ "$2" == "2.6.18" ]; then
				echo -e "NETCA Info: Please install gmp.i386 or gmp.i686 4.1.X-X\n"
			elif [ "$2" == "2.6.32" ]; then
				echo -e "NETCA Info: Please install gmp.i386 or gmp.i686 4.3.X-X\n"
			elif [ "$2" == "3.10.0" ]; then
				echo -e "NETCA Info: Please install gmp.i386 or gmp.i686 5.1.X-X\n"
			else
				echo -e "NETCA Info: not support this system version\n"
			fi
			
			return 0;
		else
			version=`echo $gmp | cut -d ' ' -f 2`;
			#echo -e "NETCA Info: You had installed ${version}"
			if [ "$2" == "2.6.18" ]; then
				if [[ $version != *4.1.*-* ]]; then
					echo -e "NETCA Info: Please install gmp.i386 or gmp.i686 4.1.X-X\n"
					return 0;
				fi

			elif [ "$2" == "2.6.32" ]; then
				if [[ $version != *4.3.*-* ]]; then
					echo -e "NETCA Info: Please install gmp.i386 or gmp.i686 4.3.X-X\n"
					return 0;
				fi
				
			elif [ "$2" == "3.10.0" ]; then
				if [[ $version != *5.1.*-* ]]; then
					echo -e "NETCA Info: Please install gmp.i386 or gmp.i686 5.1.X-X\n"
					return 0;
				fi
				
			else
				echo -e "NETCA Info: not support this system version\n"
				return 0;
			fi
		fi

	elif [ "$1" == "64" ]; then
		gmp=`rpm -qa | grep ^gmp | grep x86_64`
		
		if [ "$gmp" == "" ]; then
			if [ "$2" == "2.6.18" ]; then
				echo -e "NETCA Info: Please install gmp.x86_64 4.1.X-X\n"
			elif [ "$2" == "2.6.32" ]; then
				echo -e "NETCA Info: Please install gmp.x86_64 4.3.X-X\n"
			elif [ "$2" == "3.10.0" ]; then
				echo -e "NETCA Info: Please install gmp.x86_64 5.1.X-X\n"
			else
				echo -e "NETCA Info: not support this system version\n"
			fi
			
			return 0;
		else
			version=`echo $gmp | cut -d ' ' -f 2`;
			if [ "$2" == "2.6.18" ]; then
				if [[ $version != *4.1.*-* ]]; then
					echo -e "NETCA Info: Please install gmp.x86_64 3.3.X-X\n"
					return 0;
				fi
				
			elif [ "$2" == "2.6.32" ]; then
				if [[ $version != *4.3.*-* ]]; then
					echo -e "NETCA Info: Please install gmp.x86_64 4.3.X-X\n"
					return 0;
				fi
				
			elif [ "$2" == "3.10.0" ]; then
				if [[ $version != *5.1.*-* ]]; then
					echo -e "NETCA Info: Please install gmp.x86_64 5.1.X-X\n"
					return 0;
				fi
				
			else
				echo -e "NETCA Info: not support this system version\n"
				return 0;
			fi
		fi
	fi
	
	echo "$gmp"
	return 1;
}

#$1 : 32 or 64
#$2 : 2.6.18 or 2.6.32 or 3.10.0
function check_openldap()
{
	local version="";
	local openldap="";

	if [ "$1" == "32" ]; then
		openldap=`rpm -qa | grep ^openldap | grep i386`
		if [ "$openldap" == "" ]; then
			openldap=`rpm -qa | grep ^openldap | grep i686`
		fi
		
		if [ "$openldap" == "" ]; then
			if [ "$2" == "2.6.18" ]; then
				echo -e "NETCA Info: Please install openldap.i386 or openldap.i686 2.3.X-X\n"
			elif [ "$2" == "2.6.32" ] || [ "$2" == "3.10.0" ]; then
				echo -e "NETCA Info: Please install openldap.i386 or openldap.i686 2.4.X-X\n"
			else
				echo -e "NETCA Info: not support this system version\n"
			fi
			
			return 0;
		else
			version=`echo $openldap | cut -d ' ' -f 2`;
			if [ "$2" == "2.6.18" ]; then
				if [[ $version != *2.3.*-* ]]; then
					echo -e "NETCA Info: Please install openldap.i386 or openldap.i686 2.3.X-X\n"
					return 0;
				fi

			elif [ "$2" == "2.6.32" ] || [ "$2" == "3.10.0" ]; then
				if [[ $version != *2.4.*-* ]]; then
					echo -e "NETCA Info: Please install openldap.i386 or openldap.i686 2.4.X-X\n"
					return 0;
				fi
				
			else
				echo -e "NETCA Info: not support this system version\n"
				return 0;
			fi
		fi

	elif [ "$1" == "64" ]; then
		openldap=`rpm -qa | grep ^openldap | grep x86_64`
		
		if [ "$openldap" == "" ]; then
			if [ "$2" == "2.6.18" ]; then
				echo -e "NETCA Info: Please install openldap.x86_64 2.3.X-X\n"
			elif [ "$2" == "2.6.32" ] || [ "$2" == "3.10.0" ]; then
				echo -e "NETCA Info: Please install openldap.x86_64 2.4.X-X\n"
			else
				echo -e "NETCA Info: not support this system version\n"
			fi
			
			return 0;
		else
			version=`echo $openldap | cut -d ' ' -f 2`;
			if [ "$2" == "2.6.18" ]; then
				if [[ $version != *2.3.*-* ]]; then
					echo -e "NETCA Info: Please install openldap.x86_64 2.3.X-X\n"
					return 0;
				fi
				
			elif [ "$2" == "2.6.32" ] || [ "$2" == "3.10.0" ]; then
				if [[ $version != *2.4.*-* ]]; then
					echo -e "NETCA Info: Please install openldap.x86_64 2.4.X-X\n"
					return 0;
				fi
				
			else
				echo -e "NETCA Info: not support this system version\n"
				return 0;
			fi
		fi
	fi
	
	echo "$openldap"
	return 1;
}

#$1 : 32 or 64
#$2 : 2.6.18 or 2.6.32 or 3.10.0
function check_openssl()
{
	local version="";
	local openssl="";

	if [ "$1" == "32" ]; then
		openssl=`rpm -qa | grep ^openssl | grep i386`
		if [ "$openssl" == "" ]; then
			openssl=`rpm -qa | grep ^openssl | grep i686`
		fi
		
		if [ "$openssl" == "" ]; then
			if [ "$2" == "2.6.18" ]; then
				echo -e "NETCA Info: Please install openssl.i386 or openssl.i686 0.9.X-X\n"
			elif [ "$2" == "2.6.32" ] || [ "$2" == "3.10.0" ]; then
				echo -e "NETCA Info: Please install openssl.i386 or openssl.i686 1.0.X-X\n"
			else
				echo -e "NETCA Info: not support this system version\n"
			fi
			
			return 0;
		else
			version=`echo $openssl | cut -d ' ' -f 2`;
			if [ "$2" == "2.6.18" ]; then
				if [[ $version != *0.9.*-* ]]; then
					echo -e "NETCA Info: Please install openssl.i386 or openssl.i686 0.9.X-X\n"
					return 0;
				fi

			elif [ "$2" == "2.6.32" ] || [ "$2" == "3.10.0" ]; then
				if [[ $version != *1.0.*-* ]]; then
					echo -e "NETCA Info: Please install openssl.i386 or openssl.i686 1.0.X-X\n"
					return 0;
				fi
				
			else
				echo -e "NETCA Info: not support this system version\n"
				return 0;
			fi
		fi

	elif [ "$1" == "64" ]; then
		openssl=`rpm -qa | grep ^openssl | grep x86_64`
		
		if [ "$openssl" == "" ]; then
			if [ "$2" == "2.6.18" ]; then
				echo -e "NETCA Info: Please install openssl.x86_64 0.9.X-X\n"
			elif [ "$2" == "2.6.32" ] || [ "$2" == "3.10.0" ]; then
				echo -e "NETCA Info: Please install openssl.x86_64 1.0.X-X\n"
			else
				echo -e "NETCA Info: not support this system version\n"
			fi
			
			return 0;
		else
			version=`echo $openssl | cut -d ' ' -f 2`;
			if [ "$2" == "2.6.18" ]; then
				if [[ $version != *0.9.*-* ]]; then
					echo -e "NETCA Info: Please install openssl.x86_64 0.9.X-X\n"
					return 0;
				fi
				
			elif [ "$2" == "2.6.32" ] || [ "$2" == "3.10.0" ]; then
				if [[ $version != *1.0.*-* ]]; then
					echo -e "NETCA Info: Please install openssl.x86_64 1.0.X-X\n"
					return 0;
				fi
				
			else
				echo -e "NETCA Info: not support this system version 414\n"
				return 0;
			fi
		fi
	fi
	
	echo "$openssl"
	return 1;
}


function IsContinue()
{
	local yn="";
	read -p "Tips : Continue? (Y/N) : " yn
	while [ "$yn" != "n" ] && [ "$yn" != "N" ] && [ "$yn" != "Y" ] && [ "$yn" != "y" ]
	do
		read -p "Tips : Continue? (Y/N) : " yn
	done
	
	if [ "$yn" == "n" ] || [ "$yn" == "N" ]; then
		return 0;
	else
		return 1;
	fi
}


function select_library_path()
{
	if [ "$LD_LIBRARY_PATH" == "" ]; then
		echo -e "NETCA Info: LD_LIBRARY_PATH not be set \n"
		return 0;
	fi

	local num=`echo $LD_LIBRARY_PATH | awk -F ':' '{print NF -1}'`
	((num=$num+1))
	read -p "Tips: Please select the installation path from LD_LIBRARY_PATH=${LD_LIBRARY_PATH} : " libpath
	
	local isOK="N"
	while [ "$isOK" == "N" ]
	do
		while [ ! -d $libpath ]
		do
			read -p "Tips: Please select the installation path from LD_LIBRARY_PATH=${LD_LIBRARY_PATH} : " libpath
		done

		index=1
		while [ $index -le $num ]
		do
			path=`echo $LD_LIBRARY_PATH | cut -d ':' -f $index`
			if [ "$path" == "$libpath" ] && [ "$path" != "" ]; then
				isOK="Y"
				break
			fi
			((index=$index+1))
		done
	
		if [ "$isOK" == "N" ]; then
			read -p "Tips: Please select the installation path from LD_LIBRARY_PATH=${LD_LIBRARY_PATH} : " libpath
		fi
	done

	if [[ $libpath == */ ]]; then
		libpath=`echo ${libpath:0:(${#libpath}-1)}`
	fi
	return 1;
}

function IsInstall_crypto_x86()
{
	local so_x86=`file $1/libnetca_* | grep 32-bit`;
	if [ "$so_x86" != "" ]; then
		return 1;
	fi
	
	return 0;
}

function IsInstall_crypto_x64()
{
	local so_x64=`file $1/libnetca_* | grep 64-bit`;
	if [ "$so_x64" != "" ]; then
		return 1;
	fi
	
	return 0;
}

#$1 : library path .
#$2 : 32-bit ; 64-bit .
#$3 : move ; display .
function move_or_display_crypto()
{
	local rv=0;
	local count=`echo $1 | awk -F ':' '{print NF -1}'`
	((count=$count+1))
	local flag="";

	local i=1;
	local path="";
	while [ $i -le $count ]
	do
		path=$(echo $1 | cut -d ':' -f $i)
		if [ "$path" != "" ]; then
		
			if [[ $path == */ ]]; then
				path=`echo ${path:0:(${#path}-1)}`
			fi
			
			if [ "`file $path/libnetca_crypto* | grep $2`" != "" ]; then
				rv=1;
				if [ "$3" == "move" ]; then
					mv -f $path/libnetca_crypto* $Trash;
				else
					ls $path/libnetca_crypto*;
				fi
			fi

			if [ "`file $path/libnetca_asn1* | grep $2`" != "" ]; then
				rv=1;
				if [ "$3" == "move" ]; then
					mv -f $path/libnetca_asn1* $Trash;
				else
					ls $path/libnetca_asn1*;
				fi
			fi
			
			if [ "`file $path/libnetca_log* | grep $2`" != "" ]; then
				rv=1;
				if [ "$3" == "move" ]; then
					mv -f $path/libnetca_log* $Trash;
				else
					ls $path/libnetca_log*;
				fi
			fi

			if [ "`file $path/libnetca_util* | grep $2`" != "" ]; then
				rv=1;
				if [ "$3" == "move" ]; then
					mv -f $path/libnetca_util* $Trash;
				else
					ls $path/libnetca_util*;
				fi
			fi

			if [ "`file $path/libnetca_url* | grep $2`" != "" ]; then
				rv=1;
				if [ "$3" == "move" ]; then
					mv -f $path/libnetca_url* $Trash;
				else
					ls $path/libnetca_url*;
				fi
			fi

			if [ "`file $path/libnetca_xml* | grep $2`" != "" ]; then
				rv=1;
				if [ "$3" == "move" ]; then
					mv -f $path/libnetca_xml* $Trash;
				else
					ls $path/libnetca_xml*;
				fi
			fi
			
			if [ "`file $path/libNetcaJCrypto.so | grep $2`" != "" ]; then
				rv=1;
				if [ "$3" == "move" ]; then
					mv -f $path/libNetcaJCrypto.so $Trash;
				else
					ls $path/libNetcaJCrypto.so;
				fi
			fi
		fi
		
		((i=$i+1))
	done

	return $rv;
}

#$1 : library path .
#$2 : 32-bit ; 64-bit .
#$3 : move ; display .
function move_or_display_SJJ0929()
{
	local rv=0;
	local count=`echo $1 | awk -F ':' '{print NF -1}'`
	((count=$count+1))
	local flag="";

	local i=1;
	local path="";
	while [ $i -le $count ]
	do
		path=$(echo $1 | cut -d ':' -f $i)
		if [ "$path" != "" ]; then
			if [[ $path == */ ]]; then
				path=`echo ${path:0:(${#path}-1)}`
			fi

			if [ "`file $path/libsjj0929_dtcsp.so | grep $2`" != "" ]; then
				rv=1;
				if [ "$3" == "move" ]; then
					mv -f $path/libsjj0929_dtcsp.so $Trash;
				else
					ls $path/libsjj0929_dtcsp.so;
				fi
			fi

			if [ "`file $path/libsjj0929prov.so | grep $2`" != "" ]; then
				rv=1;
				if [ "$3" == "move" ]; then
					mv -f $path/libsjj0929prov.so $Trash;
				else
					ls $path/libsjj0929prov.so;
				fi
			fi
		fi
		
		((i=$i+1))
	done

	return $rv;
}

#$1 : library path .
#$2 : 32-bit ; 64-bit .
#$3 : move ; display .
function move_or_display_SJK1555()
{
	local rv=0;
	local count=`echo $1 | awk -F ':' '{print NF -1}'`
	((count=$count+1))
	local flag="";

	local i=1;
	local path="";
	while [ $i -le $count ]
	do
		path=$(echo $1 | cut -d ':' -f $i)
		if [ "$path" != "" ]; then
			if [[ $path == */ ]]; then
				path=`echo ${path:0:(${#path}-1)}`
			fi

			if [ "`file $path/libdtcsp.so | grep $2`" != "" ]; then
				rv=1;
				if [ "$3" == "move" ]; then
					mv -f $path/libdtcsp.so $Trash;
				else
					ls $path/libdtcsp.so;
				fi
			fi

			if [ "`file $path/libdtrtl.so | grep $2`" != "" ]; then
				rv=1;
				if [ "$3" == "move" ]; then
					mv -f $path/libdtrtl.so $Trash;
				else
					ls $path/libdtrtl.so;
				fi
			fi

			if [ "`file $path/libsjk1555_dtcsp.so | grep $2`" != "" ]; then
				rv=1;
				if [ "$3" == "move" ]; then
					mv -f $path/libsjk1555_dtcsp.so $Trash;
				else
					ls $path/libsjk1555_dtcsp.so;
				fi
			fi

			if [ "`file $path/libsjk1555prov.so | grep $2`" != "" ]; then
				rv=1;
				if [ "$3" == "move" ]; then
					mv -f $path/libsjk1555prov.so $Trash;
				else
					ls $path/libsjk1555prov.so;
				fi
			fi

			if [ "`file $path/libSJK1555KeypairManager.so | grep $2`" != "" ]; then
				rv=1;
				if [ "$3" == "move" ]; then
					mv -f $path/libSJK1555KeypairManager.so $Trash;
				else
					ls $path/libSJK1555KeypairManager.so;
				fi
			fi
		fi
		
		((i=$i+1))
	done

	return $rv;
}

#$1 : library path .
#$2 : 32-bit ; 64-bit .
#$3 : move ; display .
function move_or_display_SJJ1011()
{
	local rv=0;
	local count=`echo $1 | awk -F ':' '{print NF -1}'`
	((count=$count+1))
	local flag="";

	local i=1;
	local path="";
	while [ $i -le $count ]
	do
		path=$(echo $1 | cut -d ':' -f $i)
		if [ "$path" != "" ]; then
			if [[ $path == */ ]]; then
				path=`echo ${path:0:(${#path}-1)}`
			fi

			if [ "`file $path/libph_sdf.so | grep $2`" != "" ]; then
				rv=1;
				if [ "$3" == "move" ]; then
					mv -f $path/libph_sdf.so $Trash;
				else
					ls $path/libph_sdf.so;
				fi
			fi

			if [ "`file $path/libphsjj1011prov.so | grep $2`" != "" ]; then
				rv=1;
				if [ "$3" == "move" ]; then
					mv -f $path/libphsjj1011prov.so $Trash;
				else
					ls $path/libphsjj1011prov.so;
				fi
			fi
		fi
		
		((i=$i+1))
	done

	return $rv;
}


#$1 : x86 or x64
#$2 : 2.6.18 or 2.6.32 or 3.10.0
function install_crypto()
{
	echo -e "NETCA Info : Install NETCA CRYPTO, begin...\n"

	if [ "$1" == "x86" ]; then
		move_or_display_crypto $libpath 64-bit display;
		if [ $? == 1 ] ; then
			echo -e "NETCA Info: The files(64-bit NETCA CRYPTO) listed above will be delete!";
			echo -e	"            If needed, please backup them! Or, please select other installation path";
		
			IsContinue;
			if [ $? == 0 ] ; then
				echo -e "NETCA Info : Install NETCA CRYPTO, stop...\n"
				return ;
			fi
		
			move_or_display_crypto $libpath 64-bit move;
		fi

		move_or_display_crypto $LD_LIBRARY_PATH 32-bit display;
		if [ $? == 1 ] ; then
			echo -e "NETCA Info: The files(32-bit NETCA CRYPTO) listed above will be delete! If needed, please backup them!\n";
		
			IsContinue;
			if [ $? == 0 ] ; then
				echo -e "NETCA Info : Install NETCA CRYPTO, stop...\n"
				return ;
			fi
		
			move_or_display_crypto $LD_LIBRARY_PATH 32-bit move;
		fi
	else
		move_or_display_crypto $libpath 32-bit display;
		if [ $? == 1 ] ; then
			echo -e "NETCA Info: The files(32-bit NETCA CRYPTO) listed above will be delete!";
			echo -e	"            If needed, please backup them! Or, please select other installation path";
		
			IsContinue;
			if [ $? == 0 ] ; then
				echo -e "NETCA Info : Install NETCA CRYPTO, stop...\n"
				return ;
			fi
		
			move_or_display_crypto $libpath 32-bit move;
		fi

		move_or_display_crypto $LD_LIBRARY_PATH 64-bit display;
		if [ $? == 1 ] ; then
			echo -e "NETCA Info: The files(64-bit NETCA CRYPTO) listed above will be delete! If needed, please backup them!\n";
		
			IsContinue;
			if [ $? == 0 ] ; then
				echo -e "NETCA Info : Install NETCA CRYPTO, stop...\n"
				return ;
			fi
		
			move_or_display_crypto $LD_LIBRARY_PATH 64-bit move;
		fi
	fi

	if [ -e /etc/.NETCA/certs/trust ]; then
		mv -f /etc/.NETCA/certs/trust $Trash
	fi

	chmod 555 ./CRYPTO/$1/*.so*
	cp -p ./CRYPTO/$1/libnetca_asn1* $libpath
	cp -p ./CRYPTO/$1/libnetca_crypto* $libpath
	cp -p ./CRYPTO/$1/libnetca_log* $libpath
	cp -p ./CRYPTO/$1/libNetcaJCrypto.so $libpath
	if [ "$2" == "2.6.18" ]; then
		cp -p ./CRYPTO/$1/libnetca_url* $libpath
		cp -p ./CRYPTO/$1/libnetca_xml* $libpath
		cp -p ./CRYPTO/$1/libnetca_util* $libpath
	elif [ "$2" == "2.6.32" ]; then
		cp -p ./CRYPTO/$1/rhel6/libnetca_url* $libpath
		cp -p ./CRYPTO/$1/rhel6/libnetca_xml* $libpath
		cp -p ./CRYPTO/$1/libnetca_util* $libpath
	elif [ "$2" == "3.10.0" ]; then
		cp -p ./CRYPTO/$1/rhel6/libnetca_url* $libpath
		cp -p ./CRYPTO/$1/rhel6/libnetca_xml* $libpath
		cp -p ./CRYPTO/$1/rhel7/libnetca_util* $libpath
	fi

	cd $libpath
	for filename in `ls`
	do
		if [[ $filename == libnetca_asn1* ]]; then
			arg1=`echo $filename | cut -d "." -f 1,2,3`
			arg2=`echo $filename | cut -d "." -f 1,2`
			ln -s $filename $arg1
			ln -s $filename $arg2
		fi

		if [[ $filename == libnetca_crypto* ]]; then
			ln -s $filename libnetca_crypto.so.1
			ln -s $filename libnetca_crypto.so
		fi

		if [[ $filename == libnetca_log* ]]; then
			arg1=`echo $filename | cut -d "." -f 1,2,3`
			arg2=`echo $filename | cut -d "." -f 1,2`
			ln -s $filename $arg1
			ln -s $filename $arg2
		fi

		if [[ $filename == libnetca_url* ]]; then
			arg1=`echo $filename | cut -d "." -f 1,2,3`
			arg2=`echo $filename | cut -d "." -f 1,2`
			ln -s $filename $arg1
			ln -s $filename $arg2
		fi

		if [[ $filename == libnetca_util* ]]; then
			arg1=`echo $filename | cut -d "." -f 1,2,3`
			arg2=`echo $filename | cut -d "." -f 1,2`
			ln -s $filename $arg1
			ln -s $filename $arg2
		fi

		if [[ $filename == libnetca_xml* ]]; then
			arg1=`echo $filename | cut -d "." -f 1,2,3`
			arg2=`echo $filename | cut -d "." -f 1,2`
			ln -s $filename $arg1
			ln -s $filename $arg2
		fi
	done

	#ldd检查依赖
	cd $libpath
	echo -e "Check libnetca_crypto.so dependence"
	lib=`ldd libnetca_crypto.so | grep "not found"`
	if [ "$lib" != "" ]; then
		echo -e "NETCA Info: $lib\n"
	fi
	echo -e "Check libnetca_asn1.so dependence"
	lib=`ldd libnetca_asn1.so | grep "not found"`
	if [ "$lib" != "" ]; then
		echo -e "NETCA Info: $lib\n"
	fi
	echo -e "Check libnetca_log.so dependence"
	lib=`ldd libnetca_log.so | grep "not found"`
	if [ "$lib" != "" ]; then
		echo -e "NETCA Info: $lib\n"
	fi
	echo -e "Check libNetcaJCrypto.so dependence"
	lib=`ldd libNetcaJCrypto.so | grep "not found"`
	if [ "$lib" != "" ]; then
		echo -e "NETCA Info: $lib\n"
	fi
	echo -e "Check libnetca_url.so dependence"
	lib=`ldd libnetca_url.so | grep "not found"`
	if [ "$lib" != "" ]; then
		echo -e "NETCA Info: $lib\n"
	fi
	echo -e "Check libnetca_xml.so dependence"
	lib=`ldd libnetca_xml.so | grep "not found"`
	if [ "$lib" != "" ]; then
		echo -e "NETCA Info: $lib\n"
	fi
	echo -e "Check libnetca_util.so dependence"
	lib=`ldd libnetca_util.so | grep "not found"`
	if [ "$lib" != "" ]; then
		echo -e "NETCA Info: $lib\n"
	fi

	cd $CurrentPath;
	if [ ! -d /etc/.NETCA/certs ]; then
		mkdir -p /etc/.NETCA/certs
	fi

	chmod 644 ./CRYPTO/trust
	if [ "$1" == "x86" ]; then
		cp -p ./CRYPTO/trust /etc/.NETCA/certs/;
	else
		cp -p ./CRYPTO/trust /etc/.NETCA/certs/trust64;
	fi
	

	echo -e "NETCA Info : Install NETCA CRYPTO, Success...\n"
}


#$1 : ECC or RSA
#$2 : x86 or x64
function install_SJJ0929()
{
	echo -e "NETCA Info : Install SJJ0929, begin... \n"
	
	if [ "$2" == "x86" ]; then
		move_or_display_SJJ0929 $libpath 64-bit display;
		if [ $? == 1 ] ; then
			echo -e "NETCA Info: The files(64-bit SJJ0929) listed above will be delete!";
			echo -e	"            If needed, please backup them! Or, please select other installation path";
		
			IsContinue;
			if [ $? == 0 ] ; then
				echo -e "NETCA Info : Install SJJ0929, stop...\n"
				return ;
			fi
		
			move_or_display_SJJ0929 $libpath 64-bit move;
		fi

		move_or_display_SJJ0929 $libpath 32-bit display;
		if [ $? == 1 ] ; then
			echo -e "NETCA Info: The files(32-bit SJJ0929) listed above will be delete! If needed, please backup them!\n";
		
			IsContinue;
			if [ $? == 0 ] ; then
				echo -e "NETCA Info : Install SJJ0929, stop...\n"
				return ;
			fi
		
			move_or_display_SJJ0929 $libpath 32-bit move;
		fi
	else
		move_or_display_SJJ0929 $libpath 32-bit display;
		if [ $? == 1 ] ; then
			echo -e "NETCA Info: The files(32-bit SJJ0929) listed above will be delete!";
			echo -e	"            If needed, please backup them! Or, please select other installation path";
		
			IsContinue;
			if [ $? == 0 ] ; then
				echo -e "NETCA Info : Install SJJ0929, stop...\n"
				return ;
			fi
		
			move_or_display_SJJ0929 $libpath 32-bit move;
		fi

		move_or_display_SJJ0929 $libpath 64-bit display;
		if [ $? == 1 ] ; then
			echo -e "NETCA Info: The files(64-bit SJJ0929) listed above will be delete! If needed, please backup them!\n";
		
			IsContinue;
			if [ $? == 0 ] ; then
				echo -e "NETCA Info : Install SJJ0929, stop...\n"
				return ;
			fi
		
			move_or_display_SJJ0929 $libpath 64-bit move;
		fi
	fi
	
	
	chmod 444 ./SJJ0929/$2/libsjj0929prov.so
	chmod 444 ./SJJ0929/$2/libsjj0929_dtcsp.so
	cp -p ./SJJ0929/$2/libsjj0929prov.so $libpath
	cp -p ./SJJ0929/$2/libsjj0929_dtcsp.so $libpath

	echo -e "Check libsjj0929prov.so dependence"
	lib=`ldd $libpath/libsjj0929prov.so | grep "not found"`
	if [ "$lib" != "" ]; then
		echo -e "NETCA Info: $lib\n"
	fi
	echo -e "Check libsjj0929_dtcsp.so dependence"
	lib=`ldd $libpath/libsjj0929_dtcsp.so | grep "not found"`
	if [ "$lib" != "" ]; then
		echo -e "NETCA Info: $lib\n"
	fi
	
	local DeviceStore="DeviceStore";
	if [ "$2" == "x64" ]; then
		DeviceStore="DeviceStore64";
	fi
	local total=0;
	local SJJ0929Device="";
	local begin=0;
	local num=0;
	local count=0;
	if [ -e /etc/.NETCA/$DeviceStore ]; then
		total=$(wc -l /etc/.NETCA/$DeviceStore | cut -d ' ' -f 1)
		SJJ0929Device=$(grep -n "\[SJJ0929\]" /etc/.NETCA/$DeviceStore)
		if [ "$SJJ0929Device" != "" ]; then
			begin=$(echo $SJJ0929Device | cut -d ':' -f 1)
			num=$(($total-$begin))
			count=1
			for line in `tail -n $num /etc/.NETCA/$DeviceStore`
			do
				if [[ $line == \[PHSJJ1011\] || $line == \[SJK1555\] ]]; then
					break
				fi
				((count=$count+1))
			done
			
			for (( i=0; i<$count; i=i+1 ))
			do
				sed -i ''"$begin"'d' /etc/.NETCA/$DeviceStore
			done
		fi
	else
		if [ ! -d /etc/.NETCA ]; then
			mkdir -p /etc/.NETCA
		fi
		
		touch /etc/.NETCA/$DeviceStore
		chmod 644 /etc/.NETCA/$DeviceStore
	fi
	
	
	total=$(wc -l /etc/.NETCA/$DeviceStore | cut -d ' ' -f 1)
	if [ "$total" == "0" ]; then
		echo "[SJJ0929]" > /etc/.NETCA/$DeviceStore
		
		sed -i '1a displayName=得安加密机' /etc/.NETCA/$DeviceStore
		local signature=`cat ./SJJ0929/$2/signature`
		sed -i '1a '"$signature"'' /etc/.NETCA/$DeviceStore
		sed -i '1a Server=1' /etc/.NETCA/$DeviceStore
		sed -i '1a ECB2CTR=1' /etc/.NETCA/$DeviceStore
		sed -i '1a ECB2CBC=0' /etc/.NETCA/$DeviceStore
		sed -i '1a mustLogin=1' /etc/.NETCA/$DeviceStore
		sed -i '1a type=102' /etc/.NETCA/$DeviceStore
		sed -i '1a sopath='"$libpath"'/libsjj0929prov.so' /etc/.NETCA/$DeviceStore
		sed -i '1a class=NETWORK' /etc/.NETCA/$DeviceStore
	else
		sed -i ''"$total"'a displayName=得安加密机' /etc/.NETCA/$DeviceStore
		local signature=`cat ./SJJ0929/$2/signature`
		sed -i ''"$total"'a '"$signature"'' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a Server=1' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a ECB2CTR=1' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a ECB2CBC=0' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a mustLogin=1' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a type=102' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a sopath='"$libpath"'/libsjj0929prov.so' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a class=NETWORK' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a [SJJ0929]' /etc/.NETCA/$DeviceStore
	fi
	
	read -p "Tips: input ip : " ip
	name=""
	arg=$(echo $ip | cut -d '.' -f 1)
	name=${name}${arg}
	arg=$(echo $ip | cut -d '.' -f 2)
	name=${name}${arg}
	arg=$(echo $ip | cut -d '.' -f 3)
	name=${name}${arg}
	arg=$(echo $ip | cut -d '.' -f 4)
	name=${name}${arg}
	name=dtcrypt${name}.ini

	local SJJ0929Config="SJJ0929Config";
	if [ "$2" == "x64" ]; then
		SJJ0929Config="SJJ0929Config64";
	fi

	if [ -e /etc/.NETCA/$SJJ0929Config ]; then
		total=$(wc -l /etc/.NETCA/$SJJ0929Config | cut -d ' ' -f 1)
		SJJ0929Device=$(grep -n "\[${ip}\]" /etc/.NETCA/$SJJ0929Config)
		if [ "$SJJ0929Device" != "" ]; then
			begin=$(echo $SJJ0929Device | cut -d ':' -f 1)
			num=$(($total-$begin))
			count=1
			
			for line in `tail -n $num /etc/.NETCA/$SJJ0929Config`
			do
				if [[ $line == \[*\] ]]; then
					break
				fi
				((count=$count+1))
			done
			
			for (( i=0; i<$count; i=i+1 ))
			do
				sed -i ''"$begin"'d' /etc/.NETCA/$SJJ0929Config
			done
		fi
	else
		touch /etc/.NETCA/$SJJ0929Config
		chmod 644 /etc/.NETCA/$SJJ0929Config
	fi
	
	read -p "Tips: input serialNumber (0-9 a-z A-Z): " sn
	isValid=$(echo $sn | grep -E "^[0-9a-zA-Z:_]+$")
	while [ "$isValid" == "" ]
	do
		read -p "Tips: ${sn} is invalid, input serialNumber (0-9 a-z A-Z): " sn
		isValid=$(echo $sn | grep -E "^[0-9a-zA-Z:_]+$")
	done
	
	sn="SerialNumber="${sn}
	isRepeat=$(grep "$sn" /etc/.NETCA/$SJJ0929Config)
	while [ "$isRepeat" != "" ]
	do
		read -p "Tips: ${sn} has been alreay exist, input serialNumber (0-9 a-z A-Z): " sn
		sn="SerialNumber="${sn}
		isRepeat=$(grep "$sn" /etc/.NETCA/$SJJ0929Config)
	done
	
	cp -p ./SJJ0929/dtcrypt.ini /etc/.NETCA/${name}
	sed -i '3c SserverIpAddresses = '"$ip"';' /etc/.NETCA/${name}
	
	total=$(wc -l /etc/.NETCA/$SJJ0929Config | cut -d ' ' -f 1)
	if [ "$total" == "0" ]; then
		echo "[${ip}]" > /etc/.NETCA/$SJJ0929Config

		if [ "$1" == "ECC" ]; then
			sed -i '1a MaxOperationLen=8192' /etc/.NETCA/$SJJ0929Config
			sed -i '1a HasSSF33CBC=1' /etc/.NETCA/$SJJ0929Config
			sed -i '1a HasSM1CBC=1' /etc/.NETCA/$SJJ0929Config
			sed -i '1a HasSM1=1' /etc/.NETCA/$SJJ0929Config
			sed -i '1a HasSSF33=1' /etc/.NETCA/$SJJ0929Config
			sed -i '1a HasSM2=1' /etc/.NETCA/$SJJ0929Config
			sed -i '1a HasP256=1' /etc/.NETCA/$SJJ0929Config
			sed -i '1a HasECDSA=1' /etc/.NETCA/$SJJ0929Config
		else
			sed -i '1a MaxOperationLen=1024' /etc/.NETCA/$SJJ0929Config
			sed -i '1a HasSM1=0' /etc/.NETCA/$SJJ0929Config
			sed -i '1a HasSM2=0' /etc/.NETCA/$SJJ0929Config
		fi

		sed -i '1a ConfigFileName=/etc/.NETCA/'"$name"'' /etc/.NETCA/$SJJ0929Config
		sed -i '1a '"$sn"'' /etc/.NETCA/$SJJ0929Config
	else
		if [ "$1" == "ECC" ]; then
			sed -i ''"$total"'a MaxOperationLen=8192' /etc/.NETCA/$SJJ0929Config
			sed -i ''"$total"'a HasSSF33CBC=1' /etc/.NETCA/$SJJ0929Config
			sed -i ''"$total"'a HasSM1CBC=1' /etc/.NETCA/$SJJ0929Config
			sed -i ''"$total"'a HasSM1=1' /etc/.NETCA/$SJJ0929Config
			sed -i ''"$total"'a HasSSF33=1' /etc/.NETCA/$SJJ0929Config
			sed -i ''"$total"'a HasSM2=1' /etc/.NETCA/$SJJ0929Config
			sed -i '1a HasP256=1' /etc/.NETCA/$SJJ0929Config
		else
			sed -i ''"$total"'a MaxOperationLen=1024' /etc/.NETCA/$SJJ0929Config
			sed -i ''"$total"'a HasSM1=0' /etc/.NETCA/$SJJ0929Config
			sed -i ''"$total"'a HasSM2=0' /etc/.NETCA/$SJJ0929Config
		fi

		sed -i ''"$total"'a ConfigFileName=/etc/.NETCA/'"$name"'' /etc/.NETCA/$SJJ0929Config
		sed -i ''"$total"'a '"$sn"'' /etc/.NETCA/$SJJ0929Config
		sed -i ''"$total"'a ['"$ip"']' /etc/.NETCA/$SJJ0929Config
	fi
	
	echo -e "NETCA Info: Install SJJ0929, Success... \n"
}

#$1 : x86 or x64
function install_SJJ1011()
{
	echo -e "NETCA Info : Install SJJ1011, begin...\n"

	if [ "$1" == "x86" ]; then
		move_or_display_SJJ1011 $libpath 64-bit display;
		if [ $? == 1 ] ; then
			echo -e "NETCA Info: The files(64-bit SJJ1011) listed above will be delete!";
			echo -e	"            If needed, please backup them! Or, please select other installation path";
		
			IsContinue;
			if [ $? == 0 ] ; then
				echo -e "NETCA Info : Install SJJ1011, stop...\n"
				return ;
			fi
			
			move_or_display_SJJ1011 $libpath 64-bit move;
		fi

		move_or_display_SJJ1011 $libpath 32-bit display;
		if [ $? == 1 ] ; then
			echo -e "NETCA Info: The files(32-bit SJJ1011) listed above will be delete! If needed, please backup them!\n";
		
			IsContinue;
			if [ $? == 0 ] ; then
				echo -e "NETCA Info : Install SJJ1011, stop...\n"
				return ;
			fi
		
			move_or_display_SJJ1011 $libpath 32-bit move;
		fi
	else
		move_or_display_SJJ1011 $libpath 32-bit display;
		if [ $? == 1 ] ; then
			echo -e "NETCA Info: The files(32-bit SJJ1011) listed above will be delete!";
			echo -e	"            If needed, please backup them! Or, please select other installation path";
		
			IsContinue;
			if [ $? == 0 ] ; then
				echo -e "NETCA Info : Install SJJ1011, stop...\n"
				return ;
			fi
			
			move_or_display_SJJ1011 $libpath 32-bit move;
		fi

		move_or_display_SJJ1011 $libpath 64-bit display;
		if [ $? == 1 ] ; then
			echo -e "NETCA Info: The files(64-bit SJJ1011) listed above will be delete! If needed, please backup them!\n";
		
			IsContinue;
			if [ $? == 0 ] ; then
				echo -e "NETCA Info : Install SJJ1011, stop...\n"
				return ;
			fi
		
			move_or_display_SJJ1011 $libpath 64-bit move;
		fi
	fi

	chmod 444 ./PHSJJ1011/$1/libph_sdf.so
	chmod 444 ./PHSJJ1011/$1/libphsjj1011prov.so
	cp -p ./PHSJJ1011/$1/libph_sdf.so $libpath
	cp -p ./PHSJJ1011/$1/libphsjj1011prov.so $libpath

	echo -e "Check libph_sdf.so dependence"
	lib=`ldd $libpath/libph_sdf.so | grep "not found"`
	if [ "$lib" != "" ]; then
		echo -e "NETCA Info: $lib\n"
	fi
	echo -e "Check libphsjj1011prov.so dependence"
	lib=`ldd $libpath/libphsjj1011prov.so | grep "not found"`
	if [ "$lib" != "" ]; then
		echo -e "NETCA Info: $lib\n"
	fi

	local DeviceStore="DeviceStore";
	if [ "$1" == "x64" ]; then
		DeviceStore="DeviceStore64";
	fi

	local total=0;
	local PHDevice="";
	local begin=0;
	local num=0;
	local count=0;
	if [ -e /etc/.NETCA/$DeviceStore ]; then
		total=$(wc -l /etc/.NETCA/$DeviceStore | cut -d ' ' -f 1)
		PHDevice=$(grep -n "\[PHSJJ1011\]" /etc/.NETCA/$DeviceStore)
		
		if [ "$PHDevice" != "" ]; then
			begin=$(echo $PHDevice | cut -d ':' -f 1)
			num=$(($total-$begin))
			count=0
			for line in `tail -n $num /etc/.NETCA/$DeviceStore`
			do
				if [[ $line == \[SJJ0929\] || $line == \[SJK1555\] ]]; then
					break
				fi
				((count=$count+1))
			done
		
			for (( i=0; i<=$count; i=i+1 ))
			do
				sed -i ''"$begin"'d' /etc/.NETCA/$DeviceStore
			done
		fi
		
	else	
		if [ ! -d /etc/.NETCA ]; then
			mkdir -p /etc/.NETCA
		fi

		touch /etc/.NETCA/$DeviceStore
		chmod 644 /etc/.NETCA/$DeviceStore
	fi
	
	total=$(wc -l /etc/.NETCA/$DeviceStore | cut -d ' ' -f 1)
	if [ "$total" == "0" ]; then
		echo "[PHSJJ1011]" > /etc/.NETCA/$DeviceStore
		
		sed -i '1a displayName=普华加密机' /etc/.NETCA/$DeviceStore
		local signature=`cat ./PHSJJ1011/$1/signature`
		sed -i '1a '"$signature"'' /etc/.NETCA/$DeviceStore
		sed -i '1a MultiDevice=1' /etc/.NETCA/$DeviceStore
		sed -i '1a NoUnload=1' /etc/.NETCA/$DeviceStore
		sed -i '1a Server=1' /etc/.NETCA/$DeviceStore
		sed -i '1a ECB2CTR=1' /etc/.NETCA/$DeviceStore
		sed -i '1a type=103' /etc/.NETCA/$DeviceStore
		sed -i '1a sopath='"$libpath"'/libphsjj1011prov.so' /etc/.NETCA/$DeviceStore
		sed -i '1a class=NETWORK' /etc/.NETCA/$DeviceStore
	else
		sed -i ''"$total"'a displayName=普华加密机' /etc/.NETCA/$DeviceStore
		local signature=`cat ./PHSJJ1011/$1/signature`
		sed -i ''"$total"'a '"$signature"'' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a MultiDevice=1' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a NoUnload=1' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a Server=1' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a ECB2CTR=1' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a type=103' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a sopath='"$libpath"'/libphsjj1011prov.so' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a class=NETWORK' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a [PHSJJ1011]' /etc/.NETCA/$DeviceStore
	fi
	
	if [ ! -d /usr/local/phgcs ]; then
		mkdir -p /usr/local/phgcs
	fi

	if [ -e /usr/local/phgcs/module.conf ]; then
		mv -f /usr/local/phgcs/module.conf $Trash;
	fi

	if [ -e /etc/.NETCA/SJJ1011KeyPairStatus ]; then
		mv -f /etc/.NETCA/SJJ1011KeyPairStatus $Trash;
	fi

	chmod 644 ./PHSJJ1011/module.conf
	chmod 644 ./PHSJJ1011/SJJ1011KeyPairStatus
	cp -p ./PHSJJ1011/module.conf /usr/local/phgcs/
	cp -p ./PHSJJ1011/SJJ1011KeyPairStatus /etc/.NETCA/
	
	read -p "Tips: input IP : " ip
	sed -i '2c HOST1='"$ip"'' /usr/local/phgcs/module.conf
	
	chmod 544 ./PHSJJ1011/$1/GetKeyPairStatus
	local KeyPairStatus=$(./PHSJJ1011/$1/GetKeyPairStatus)
	local isValid=$(echo $KeyPairStatus | grep -E "^[0-9]+$")
	if [ "$isValid" == "" ]; then
		echo -e "NETCA Info : Install PHSJJ1011, Fail... \n"
		return
	fi
	sed -i '4c KeyPairStatus='"$KeyPairStatus"'' /etc/.NETCA/SJJ1011KeyPairStatus

	echo -e "NETCA Info : Install PHSJJ1011, Success... \n"
}

function start_SJK1555_Drivers()
{
	echo -e "NETCA Info: Start SJK1555 Drivers, begin... \n"
	local folder="/lib/modules/k814abh11"

	insmod ${folder}/k814abh11.ko
	sleep 1
	info=`lsmod | grep k814abh11`
	if [ "$info" == "" ]; then
		echo -e "NETCA Info: Start SJK1555 Drivers, Fail... \n"
		return ;
	fi
	sh ${folder}/mknod
	
	echo -e "NETCA Info: Start SJK1555 Drivers, Success... \n"
}

function install_SJK1555_Drivers()
{
	echo -e "NETCA Info : Install SJK1555 Drivers, begin... \n"
	local folder="/lib/modules/k814abh11"

	if [ ! -d $folder ]; then
		mkdir -p $folder
	fi

	if [ -f ${folder}/k814abh11.ko ]; then
		ls ${folder}/k814abh11.ko
	fi
	if [ -f ${folder}/mknod ]; then
		ls ${folder}/mknod
	fi
	echo -e "NETCA Info: The files(SJK1555 Drivers) listed above will be delete! If needed, please backup them!\n";
	IsContinue;
	if [ $? == 0 ] ; then
		echo -e "NETCA Info : Install SJK1555 Drivers, stop...\n"
		return ;
	fi

	chmod 544 ./SJK1555/drivers/k814abh11.ko
	chmod 555 ./SJK1555/drivers/mknod
	cp -p ./SJK1555/drivers/k814abh11.ko $folder
	cp -p ./SJK1555/drivers/mknod $folder
	
	echo -e "NETCA Info: Install SJK1555 Drivers, Success... \n"
}

#$1 : x86 or x64
function install_SJK1555_Library()
{
	echo -e "NETCA Info : Install SJK1555 Library, begin... \n"
	
	if [ "$1" == "x86" ]; then
		echo -e "NETCA Info : Currently only support 64-bit SJK1555\n"
		echo -e "NETCA Info : Install SJK1555 Library, stop...\n"
		return ;
	else
		move_or_display_SJK1555 $libpath 32-bit display;
		if [ $? == 1 ] ; then
			echo -e "NETCA Info: The files(32-bit SJK1555) listed above will be delete! If needed, please backup them!\n";
		
			IsContinue;
			if [ $? == 0 ] ; then
				echo -e "NETCA Info : Install SJK1555 Library, stop...\n"
				return ;
			fi
			move_or_display_SJK1555 $libpath 32-bit move;
		fi
		
		move_or_display_SJK1555 $libpath 64-bit display;
		if [ $? == 1 ] ; then
			echo -e "NETCA Info: The files(64-bit SJK1555) listed above will be delete! If needed, please backup them!\n";
		
			IsContinue;
			if [ $? == 0 ] ; then
				echo -e "NETCA Info : Install SJK1555 Library, stop...\n"
				return ;
			fi
		
			move_or_display_SJK1555 $libpath 64-bit move;
		fi
	fi

	chmod 444 ./SJK1555/$1/libdtcsp.so
	chmod 444 ./SJK1555/$1/libdtrtl.so
	chmod 444 ./SJK1555/$1/libsjk1555prov.so
	chmod 444 ./SJK1555/$1/libsjk1555_dtcsp.so
	chmod 444 ./SJK1555/$1/libSJK1555KeypairManager.so
	chmod 644 ./SJK1555/$1/trust64
	cp -p ./SJK1555/$1/libdtcsp.so $libpath
	cp -p ./SJK1555/$1/libdtrtl.so $libpath
	cp -p ./SJK1555/$1/libsjk1555prov.so $libpath
	cp -p ./SJK1555/$1/libsjk1555_dtcsp.so $libpath
	cp -p ./SJK1555/$1/libSJK1555KeypairManager.so $libpath
	cp -p ./SJK1555/$1/trust64 /etc/.NETCA/certs/trust64;
	
	echo -e "Check libdtcsp.so dependence"
	lib=`ldd $libpath/libdtcsp.so | grep "not found"`
	if [ "$lib" != "" ]; then
		echo -e "NETCA Info: $lib\n"
	fi
	echo -e "Check libdtrtl.so dependence"
	lib=`ldd $libpath/libdtrtl.so | grep "not found"`
	if [ "$lib" != "" ]; then
		echo -e "NETCA Info: $lib\n"
	fi
	echo -e "Check libsjk1555prov.so dependence"
	lib=`ldd $libpath/libsjk1555prov.so | grep "not found"`
	if [ "$lib" != "" ]; then
		echo -e "NETCA Info: $lib\n"
	fi
	echo -e "Check libsjk1555_dtcsp.so dependence"
	lib=`ldd $libpath/libsjk1555_dtcsp.so | grep "not found"`
	if [ "$lib" != "" ]; then
		echo -e "NETCA Info: $lib\n"
	fi
	echo -e "Check libSJK1555KeypairManager.so dependence"
	lib=`ldd $libpath/libSJK1555KeypairManager.so | grep "not found"`
	if [ "$lib" != "" ]; then
		echo -e "NETCA Info: $lib\n"
	fi
	
	local DeviceStore="DeviceStore64";

	local total=0;
	local SJK1555Device="";
	local begin=0;
	local num=0;
	local count=0;
	if [ -e /etc/.NETCA/$DeviceStore ]; then
		total=$(wc -l /etc/.NETCA/$DeviceStore | cut -d ' ' -f 1)
		SJK1555Device=$(grep -n "\[SJK1555\]" /etc/.NETCA/$DeviceStore)
		if [ "$SJK1555Device" != "" ]; then
			begin=$(echo $SJK1555Device | cut -d ':' -f 1)
			num=$(($total-$begin))
			count=1
			for line in `tail -n $num /etc/.NETCA/$DeviceStore`
			do
				if [[ $line == \[PHSJJ1011\] || $line == \[SJJ0929\] ]]; then
					break
				fi
				((count=$count+1))
			done
			
			for (( i=0; i<$count; i=i+1 ))
			do
				sed -i ''"$begin"'d' /etc/.NETCA/$DeviceStore
			done
		fi
	else
		if [ ! -d /etc/.NETCA ]; then
			mkdir -p /etc/.NETCA
		fi
		
		touch /etc/.NETCA/$DeviceStore
		chmod 644 /etc/.NETCA/$DeviceStore
	fi
	
	total=$(wc -l /etc/.NETCA/$DeviceStore | cut -d ' ' -f 1)
	if [ "$total" == "0" ]; then
		echo "[SJK1555]" > /etc/.NETCA/$DeviceStore
		
		sed -i '1a displayName=得安加密卡' /etc/.NETCA/$DeviceStore
		local signature=`cat ./SJK1555/$1/signature`
		sed -i '1a '"$signature"'' /etc/.NETCA/$DeviceStore
		sed -i '1a Server=1' /etc/.NETCA/$DeviceStore
		sed -i '1a ECB2CTR=0' /etc/.NETCA/$DeviceStore
		sed -i '1a ECB2CBC=0' /etc/.NETCA/$DeviceStore
		sed -i '1a mustLogin=0' /etc/.NETCA/$DeviceStore
		sed -i '1a type=109' /etc/.NETCA/$DeviceStore
		sed -i '1a sopath='"$libpath"'/libsjk1555prov.so' /etc/.NETCA/$DeviceStore
		sed -i '1a class=PCI' /etc/.NETCA/$DeviceStore
	else
		sed -i ''"$total"'a displayName=得安加密卡' /etc/.NETCA/$DeviceStore
		local signature=`cat ./SJK1555/$1/signature`
		sed -i ''"$total"'a '"$signature"'' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a Server=1' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a ECB2CTR=0' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a ECB2CBC=0' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a mustLogin=0' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a type=109' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a sopath='"$libpath"'/libsjk1555prov.so' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a class=PCI' /etc/.NETCA/$DeviceStore
		sed -i ''"$total"'a [SJK1555]' /etc/.NETCA/$DeviceStore
	fi
	
	cp -p ./SJK1555/dtcrypt.ini /etc/.NETCA/sjk1555_dtcrypt.ini
	
	echo -e "NETCA Info: Install SJK1555 Library, Success... \n"

}

#$1 : x86 or x64
function install_SJK1555()
{
	while [ 1 ]
	do
		echo -e "\n\n+++++++++++++++++++++++++++++++++++++++++++"
		echo -e "   Install Options : "
		echo -e "   1 SJK1555 Drivers Install\n   2 SJK1555 Library Install\n   3 SJK1555 Drivers Start\n   4 EXIT"
		echo -e "+++++++++++++++++++++++++++++++++++++++++++\n\n"
		read -p "Please input one option : " option
		case $option in
		"1")
			install_SJK1555_Drivers;
			;;
		"2")
			install_SJK1555_Library $1;
			;;
		"3")
			start_SJK1555_Drivers;
			;;
		"4")
			return;
			;;
		*)
			echo "Usage {1|2|3}"
		;;
		esac
	done
}

#$1 : 2.6.18 or 2.6.32 or 3.10.0
function install_x86()
{
	check_sqlite 32 $1;
#	if [ $? != 1 ]; then
#		exit 1;
#	fi
	check_gmp 32 $1;
#	if [ $? != 1 ]; then
#		exit 1;
#	fi
	check_openldap 32 $1;
#	if [ $? != 1 ]; then
#		exit 1;
#	fi
	check_openssl 32 $1;
#	if [ $? != 1 ]; then
#		exit 1;
#	fi
	echo -e "NETCA Info: The four libraries are OK !"	

	select_library_path;
	if [ $? == 0 ]; then
		exit 1;
	fi

	if [ ! -d ${Trash} ]; then
		mkdir -p ${Trash};
	fi

	while [ 1 ]
	do
		echo -e "\n\n+++++++++++++++++++++++++++++++++++++++++++"
		echo -e "   Install Options : "
		echo -e "   1 NETCA CRYPTO x86\n   2 PHSJJ1011 x86\n   3 SJJ0929 ECC x86\n   4 SJJ0929 RSA x86\n   5 Exit"
		echo -e "+++++++++++++++++++++++++++++++++++++++++++\n\n"
		read -p "Please input one option : " option
		case $option in
		"1")
			install_crypto x86 $1;
			;;
		"2")	
			install_SJJ1011 x86;
			;;
		"3")
			install_SJJ0929 ECC x86;
			;;
		"4")
			install_SJJ0929 RSA x86;
			;;
		"5")
			return;
			;;
		*)
			echo "Usage {1|2|3|4|5}"
		;;
		esac
	done
}


#$1 : 2.6.18 or 2.6.32 or 3.10.0
function install_x64()
{
	check_sqlite 64 $1;
#	if [ $? != 1 ]; then
#		exit 1;
#	fi
	check_gmp 64 $1;
#	if [ $? != 1 ]; then
#		exit 1;
#	fi
	check_openldap 64 $1;
#	if [ $? != 1 ]; then
#		exit 1;
#	fi
	check_openssl 64 $1;
#	if [ $? != 1 ]; then
#		exit 1;
#	fi
	echo -e "NETCA Info: The four libraries are OK !"

	select_library_path;
	if [ $? == 0 ]; then
		exit 1;
	fi

	if [ ! -d ${Trash} ]; then
		mkdir -p ${Trash};
	fi

	while [ 1 ]
	do
		echo -e "\n\n+++++++++++++++++++++++++++++++++++++++++++"
		echo -e "   Install Options : "
		echo -e "   1 NETCA CRYPTO x64\n   2 PHSJJ1011 x64\n   3 SJJ0929 ECC x64\n   4 SJJ0929 RSA x64\n   5 SJK1555 x64\n   6 EXIT"
		echo -e "+++++++++++++++++++++++++++++++++++++++++++\n\n"
		read -p "Please input one option : " option
		case $option in
		"1")
			install_crypto x64 $1;
			;;
		"2")	
			install_SJJ1011 x64;
			;;
		"3")
			install_SJJ0929 ECC x64;
			;;
		"4")
			install_SJJ0929 RSA x64;
			;;
		"5")
			install_SJK1555 x64;
			;;
		"6")
			return;
			;;
		*)
			echo "Usage {1|2|3|4|5}"
		;;
		esac
	done
}

#$1 : 2.6.18 or 2.6.32 or 3.10.0
function crypto_select_install_platform()
{
	while [ 1 ]
	do
		echo -e "\n\n+++++++++++++++++++++++++++++++++++++++++++"
		echo -e "	Install Options : \n"
		echo -e "	1. 32-bit "
		echo -e "	2. 64-bit "
		echo -e "	3. EXIT "
		echo -e "+++++++++++++++++++++++++++++++++++++++++++\n\n"
		read -p "Plesae Select one option : " option
		case $option in
		"1")
			install_x86 $1;
			;;
		"2")
			install_x64 $1;
			;;
		"3")
			exit 1
			;;
		*)
			echo "Usage {1 | 2 | 3}"
			;;
		esac
	done
}

SymtemVersion="";
if [[ `uname -r` == 2.6.18* ]]; then
	SymtemVersion="2.6.18";
elif [[ `uname -r` == 2.6.32* ]]; then
	SymtemVersion="2.6.32";
elif [[ `uname -r` == 3.10.0* ]]; then
	SymtemVersion="3.10.0";
else
	echo -e "NETCA Info : Not support this system version 1494\n";
	return ;
fi

Is_x86_64=`uname -r | grep x86_64`;
if [ "$Is_x86_64" != "" ]; then
	crypto_select_install_platform $SymtemVersion;
else
	install_x86 $SymtemVersion;
fi