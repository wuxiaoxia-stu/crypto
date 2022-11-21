# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import SignedData
import sys

arg_count=len(sys.argv)

if arg_count!=3 and arg_count!=4:
    print("Usage: python signeddatasign1.py [-detached] tbs_file_name sign_file_name")
    sys.exit(-1)

detached=False
pos=1
if arg_count==4:
    if sys.argv[1]!="-detached":
        print("Usage: python signeddatasign1.py [-detached] tbs_file_name sign_file_name")
        sys.exit(-1)
    detached=True
    pos=2

tbs_file_name=sys.argv[pos]
sign_file_name=sys.argv[pos+1]

with open(tbs_file_name,"rb") as f:
    tbs_data=f.read()

cert_obj=Certificate.get_user_cert(Certificate.USER_CERT_TYPE_SIGN)
if cert_obj is None:
    print("no sign cert")
    sys.exit(-1)

with cert_obj:
    sign_data=SignedData.sign_data(cert_obj,detached,tbs_data)
with open(sign_file_name,"wb") as f:
    f.write(sign_data)

print("sign ok")

