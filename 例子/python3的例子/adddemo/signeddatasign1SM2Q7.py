# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import SignedData
import netcacrypto
import sys

arg_count=len(sys.argv)

if arg_count!=4 and arg_count!=5:
    print("Usage: python signeddatasign1.py [-detached] tbs_file_name sign_file_name cert_file")
    sys.exit(-1)

detached=False
pos=1
if arg_count==5:
    if sys.argv[1]!="-detached":
        print("Usage: python signeddatasign1SM2Q7.py [-detached] tbs_file_name sign_file_name cert_file")
        sys.exit(-1)
    detached=True
    pos=2

tbs_file_name=sys.argv[pos]
sign_file_name=sys.argv[pos+1]
cert_file_name=sys.argv[pos+2]

with open(cert_file_name,"rb") as f:
    cert_data=f.read()
with open(tbs_file_name,"rb") as f:
    tbs_data=f.read()

cert_obj=Certificate(cert_data)
if cert_obj is None:
    print("no sign cert")
    sys.exit(-1)

#cert_obj=Certificate.get_user_cert(Certificate.USER_CERT_TYPE_SIGN)
#if cert_obj is None:
#   print("no sign cert")
#  sys.exit(-1)

with cert_obj:
    cert_obj.get_privatekey("12345678")
    conf=netcacrypto.get_config()
    #print("conf:\t"+conf)
    netcacrypto.set_config("{\"signedData\":{\"sign\":{\"signingCertHashAlgo\":[[1,8192],[4,16384],[25,28672]],\"useQ7\":true},\"verify\":{\"verifyLevel\":1}}}")
    #print("new conf:\t"+netcacrypto.get_config())
    sign_data=SignedData.sign_data(cert_obj,detached,tbs_data)
with open(sign_file_name,"wb") as f:
    f.write(sign_data)
#netcacrypto.set_config(conf)
netcacrypto.reset_config()
print("sign ok")

