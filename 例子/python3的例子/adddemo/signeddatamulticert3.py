#-*-codinng:utf-8-*-
from netcacrypto import SignedData
from netcacrypto import Certificate
import sys
#多人签名，第三种方式：联署签名，一人签名，签名文件发送给第二人，保存原文，验证后，对第一人的签名值进行SignedData签名
arg_count=len(sys.argv)

if arg_count!=4 and arg_count!=5:
    print("Usage: python signeddatamulticert3.py [tbs_file] oldsign_file newsign_file cert_file")
    sys.exit(-1)

detached=False
tbs_file=None
tbs_data=None
pos=1

if arg_count==5:
    tbs_file=sys.argv[1]
    with open(tbs_file,"rb") as f:
        tbs_data=f.read()
        pos=2
print("pos:%d"%pos)
oldsign_file=sys.argv[pos]
newsign_file=sys.argv[pos+1]
cert_file=sys.argv[pos+2]


with open(cert_file,"rb") as f:
    cert_data=f.read()

cert_obj=Certificate(cert_data)
if cert_obj is None:
    print("no sign cert")
    sys.exit(-1)

with open(oldsign_file,"rb") as f:
    oldsign_data=f.read()


with cert_obj,SignedData(False) as sign_obj,open(oldsign_file,"rb") as f_in,open(newsign_file,"wb") as f_out:
    cert_obj.get_privatekey("12345678")
    
    #验证第一人的签名文件
    detached=SignedData.is_detached_signeddata(oldsign_data)    
    #带原文
    if detached!=True:
        sign_obj.keep_tbs()
        sign_obj.verify_init()
        while True:
            sign_data=f_in.read(64*1024)
            if len(sign_data)==0:
                break
            temp=sign_obj.verify_update(sign_data)
        sign_obj.verify_final()
        print("verify ok")
    #不带原文
    else:
        sign_obj.detached_verify_init(oldsign_data)
        with open(tbs_file,"rb") as t_in:
            while True:
                tbs_data=t_in.read(64*1024)
                if len(tbs_data)==0:
                    break
                sign_obj.detached_verify_update(tbs_data)
        sign_obj.detached_verify_final()
        #sign_obj.verify_postcheck()
        print("verify(detached) ok")


	#第二人签名
    sign_data=sign_obj.countsign(0,2,cert_obj)
    f_out.write(sign_data)
    
    i=0
    count=sign_obj.get_signer_count()
    while i<count:
        with sign_obj.get_signcert(i) as cert_obj:
            subject=cert_obj.get_subject()
            print("sign cert "+str(i)+" subject:\t"+subject)
        i=i+1
