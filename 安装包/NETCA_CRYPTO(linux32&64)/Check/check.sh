#$1 : x86 or x64
function check()
{
	chmod 544 CryptoTestTool_"$1"
	while [ 1 ]
	do
		echo -e "\n+++++++++++++++++++++++++"
		echo -e "   1 NETCA CRYPTO "$1"\n   2 PHSJJ1011 "$1"\n   3 SJJ0929 ECC "$1"\n   4 SJJ0929 RSA "$1"\n   5 SJJ1540 ECC "$1"\n   6 SJK1555 "$1"\n   7 SJJ1507 "$1"\n   8 SRJ1401 "$1"\n   9 NetcaSoftCertificate "$1"\n   10 NetcaSoftOpenSSL "$1"\n   0 Exit"
		echo -e "++++++++++++++++++++++++++\n"

		read -p "please select one option : " option
		case $option in
		"1")
			./CryptoTestTool_"$1";
			;;
		"2")	
			./CryptoTestTool_"$1" 103;
			;;
		"3")
			./CryptoTestTool_"$1" 102;
			;;
		"4")
			./CryptoTestTool_"$1" 102;
			;;
		"5")
			./CryptoTestTool_"$1" 102;
			;;
		"6")
			./CryptoTestTool_"$1" 109;
			;;
		"7")
			./CryptoTestTool_"$1" 107;
			;;
		"8")
			./CryptoTestTool_"$1" 110;
			;;
		"9")
			./CryptoTestTool_"$1" 52;
			;;
		"10")
			./CryptoTestTool_"$1" 11;
			;;
		"0")
			return;
			;;
		*)
			echo "Usage {1|2|3|4|5|6|7|8|9|10}"
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
		echo -e "	0. EXIT "
		echo -e "+++++++++++++++++++++++++++++++++++++++++++\n\n"
		read -p "Plesae Select one option : " option
		case $option in
		"1")
			check x86;
			;;
		"2")
			check x64;
			;;
		"0")
			exit 1
			;;
		*)
			echo "Usage {1 | 2}"
			;;
		esac
	done
}

Is_x86_64=`uname -a | grep x86_64`;
if [ "$Is_x86_64" != "" ]; then
	crypto_select_check_platform;
else
	check x86;
fi
