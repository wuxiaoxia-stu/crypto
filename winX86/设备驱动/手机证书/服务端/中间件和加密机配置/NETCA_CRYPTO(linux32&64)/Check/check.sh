
#$1 : x86 or x64
function T_Crypto ()
{
	if [ -e crypto_$1 ]; then
		chmod 544 crypto_$1
		./crypto_$1
	fi
}

#$1 : x86 or x64
function T_PHSJJ1011 ()
{
	if [ -e sjj1011_$1 ]; then
		chmod 544 sjj1011_$1
		read -p "input UsrPin : " usrpin
		./sjj1011_$1 $usrpin
	fi
}


#$1 : x86 or x64
function T_SJJ0929 ()
{
	local SJJ0929Config="SJJ0929Config";
	if [ "$1" == "x64" ]; then
		SJJ0929Config="SJJ0929Config64";
	fi

	if [ -e sjj0929_$1 ]; then
		chmod 544 sjj0929_$1
		info="select one SerialNumber from **"
		for sn in `cat /etc/.NETCA/$SJJ0929Config | grep SerialNumber`
		do
			info=${info}" ${sn}"
		done

		read -p "${info} ** : " serial
		read -p "input UsrPin : " usrpin
		./sjj0929_$1 $serial $usrpin
	fi
}


#$1 : x86 or x64
function T_SJK1555 ()
{
	if [ -e sjk1555_$1 ]; then
		chmod 544 sjk1555_$1
		./sjk1555_$1
	else
		gcc SJK1555SimpleTest.c -g -w -o sjk1555_$1 -lnetca_crypto -Iinclude
		chmod 544 sjk1555_$1
		./sjk1555_$1
	fi
}

function check_x86()
{
	while [ 1 ]
	do
		echo -e "\n+++++++++++++++++++++++++"
		echo -e " 1.NETCA CRYPTO x86\n 2.PHSJJ1011 x86\n 3.SJJ0929 x86\n 4.Exit"
		echo -e "++++++++++++++++++++++++++\n"

		read -p "please select one option : " option
		case $option in
		"1")
			T_Crypto x86;
			;;
		"2")	
			T_PHSJJ1011 x86;
			;;
		"3")
			T_SJJ0929 x86;
			;;
		"4")
			return;
			;;
		*)
			echo "Usage {1|2|3|4}"
			;;
		esac
	done
}

function check_x64()
{
	while [ 1 ]
	do
		echo -e "\n+++++++++++++++++++++++++"
		echo -e " 1.NETCA CRYPTO x64\n 2.PHSJJ1011 x64\n 3.SJJ0929 x64\n 4.SJK555 x64\n 5.Exit"
		echo -e "++++++++++++++++++++++++++\n"

		read -p "please select one option : " option
		case $option in
		"1")
			T_Crypto x64;
			;;
		"2")	
			T_PHSJJ1011 x64;
			;;
		"3")
			T_SJJ0929 x64;
			;;
		"4")
			T_SJK1555 x64;
			;;
		"5")
			return;
			;;
		*)
			echo "Usage {1|2|3|4}"
			;;
		esac
	done
}

function crypto_select_check_platform()
{
	while [ 1 ]
	do
		echo -e "\n\n+++++++++++++++++++++++++++++++++++++++++++"
		echo -e "	Check Options : \n"
		echo -e "	1. 32-bit "
		echo -e "	2. 64-bit "
		echo -e "	3. EXIT "
		echo -e "+++++++++++++++++++++++++++++++++++++++++++\n\n"
		read -p "Plesae Select one option : " option
		case $option in
		"1")
			check_x86;
			;;
		"2")
			check_x64;
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

Is_x86_64=`uname -r | grep x86_64`;
if [ "$Is_x86_64" != "" ]; then
	crypto_select_check_platform;
else
	check_x86;
fi
