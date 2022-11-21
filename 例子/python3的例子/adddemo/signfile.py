# -*- coding: utf-8 -*-
from netcacrypto import Certificate
import sys

arg_count=len(sys.argv)

if arg_count!=3:
    print("Usage: python signfile.py tbs_file_name sign_file_name")
    sys.exit(-1)

tbs_file_name=sys.argv[1]
sign_file_name=sys.argv[2]

with open(tbs_file_name,"rb") as f:
    tbs_data=f.read()

cert_obj=Certificate.get_user_cert(Certificate.USER_CERT_TYPE_SIGN)
if cert_obj is None:
    print("no sign cert")
    sys.exit(-1)

with cert_obj:
    sign_data=cert_obj.sign(tbs_data)

with open(sign_file_name,"wb") as f:
    f.write(sign_data)

print("sign ok")
