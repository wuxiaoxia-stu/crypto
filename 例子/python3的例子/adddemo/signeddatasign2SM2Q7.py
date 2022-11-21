# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import SignedData
import sys

#using default config, and using SM2Q7 sign
arg_count=len(sys.argv)

if arg_count!=4 and arg_count!=5:
    print("Usage: python signeddatasign2.py [-detached] tbs_file_name sign_file_name cert_file")
    sys.exit(-1)

detached=False
pos=1
if arg_count==5:
    if sys.argv[1]!="-detached":
        print("Usage: python signeddatasign2.py [-detached] tbs_file_name sign_file_name cert_file")
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

#with cert_obj:
 #   cert_obj.get_privatekey("12345678")

with cert_obj,SignedData(True) as sign_obj,open(tbs_file_name,"rb") as f_in,open(sign_file_name,"wb") as f_out:
    cert_obj.get_privatekey("12345678")
    sign_obj.set_signcert(cert_obj)
    sign_obj.apply_sign_config()
    sign_obj.set_detached(detached)
    sign_obj.set_sm2q7(True)
    sign_data=sign_obj.sign_init()
    f_out.write(sign_data)
    while True:
        tbs_data=f_in.read(64*1024)
        if len(tbs_data)==0:
            break
        sign_data=sign_obj.sign_update(tbs_data)
        f_out.write(sign_data)
    sign_data=sign_obj.sign_final()
    f_out.write(sign_data)
print("sign ok")

