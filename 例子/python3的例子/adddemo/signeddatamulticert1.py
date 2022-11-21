#-*-codinng:utf-8-*-
from netcacrypto import SignedData
from netcacrypto import Certificate
import sys

#第一种多人签名：一人有多个证书，设置多个签名证书，算法，进行签名
arg_count=len(sys.argv)
print("param length:%d"%arg_count)

if arg_count!=6:
    print("Usage: python signeddatawithencert1 tbs_file newsign_file newsign_detacheFlag cert_file cert_file2")
    sys.exit(-1)

tbs_file=sys.argv[1]
newsign_file=sys.argv[2]
cert_file=sys.argv[4]
cert_file2=sys.argv[5]
newsign_detacheFlag=sys.argv[3]

flag=False
if newsign_detacheFlag!="False":
    flag=True

"""
with open(oldsign_file,"rb") as f:
    tbs_data=f.read()
"""
with open(cert_file,"rb") as f:
    cert_data=f.read()

cert_obj=Certificate(cert_data)
if cert_file2 is None:
    print("only one cert")
    sys.exit(-1)
else:
    with open(cert_file2,"rb") as f:
        cert_data2=f.read()
cert_obj2=Certificate(cert_data2)


if cert_obj is None:
    print("no sign cert")
    sys.exit(-1)

	
with cert_obj,cert_obj2,SignedData(True) as newsign_obj,open(tbs_file,"rb") as f_in,open(newsign_file,"wb") as f_out:
    cert_obj.get_privatekey("12345678")
    cert_obj2.get_privatekey("12345678")

    if flag!=True:
        count=newsign_obj.get_signer_count()
        newsign_obj.set_detached(flag)
        newsign_obj.set_signcert(cert_obj)
        newsign_obj.set_signcert(cert_obj2)
    #sign_obj.set_enccert(cert_obj)
        newsign_obj.set_sign_algo(SignedData.SHA1WITHRSA)#set signalgo
        newsign_obj.set_sign_algo(SignedData.SM3WITHSM2,1)#set signalgo
        sign_data=newsign_obj.sign_init()
        #f_out.write(sign_data)
        while True:
            tbs_data_new=f_in.read(64*1024)
            if len(tbs_data_new)==0:
                break
            sign_data=newsign_obj.sign_update(tbs_data_new)
            f_out.write(sign_data)
        sign_data=newsign_obj.sign_final()
        f_out.write(sign_data)
        print("multisign(newsign_detacheFlag=False) ok")
        count=newsign_obj.get_signer_count()
        i=0
        while i<count:
            with newsign_obj.get_signcert(i) as cert_obj:
                subject=cert_obj.get_subject()
                print("sign cert "+str(i)+" subject:\t"+subject)
            i=i+1
    else:
        count=newsign_obj.get_signer_count()
        newsign_obj.set_detached(flag)
        newsign_obj.set_signcert(cert_obj)
        newsign_obj.set_signcert(cert_obj2)
    #sign_obj.set_enccert(cert_obj)
        newsign_obj.set_sign_algo(SignedData.SHA1WITHRSA)#set signalgo
        newsign_obj.set_sign_algo(SignedData.SM3WITHSM2,1)#set signalgo
        sign_data=newsign_obj.sign_init()
        #f_out.write(sign_data)
        while True:
            tbs_data_new=f_in.read(64*1024)
            if len(tbs_data_new)==0:
                break
            sign_data=newsign_obj.sign_update(tbs_data_new)
            f_out.write(sign_data)
        sign_data=newsign_obj.sign_final()
        f_out.write(sign_data)
        print("multisign(newsign_detacheFlag=True) ok")
        count=newsign_obj.get_signer_count()
        i=0
        while i<count:
            with newsign_obj.get_signcert(i) as cert_obj:
                subject=cert_obj.get_subject()
                print("sign cert "+str(i)+" subject:\t"+subject)
            i=i+1