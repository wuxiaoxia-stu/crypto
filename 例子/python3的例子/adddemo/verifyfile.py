# -*- coding: utf-8 -*-
from netcacrypto import Certificate
import sys

arg_count=len(sys.argv)

if arg_count!=4:
    print("Usage: python verifyfile.py cert_file_name sign_file_name tbs_file_name")
    sys.exit(-1)

cert_file_name=sys.argv[1]
sign_file_name=sys.argv[2]
tbs_file_name=sys.argv[3]

with open(cert_file_name,"rb") as f:
    cert_data=f.read()
    
with open(sign_file_name,"rb") as f:
    sign_data=f.read()
    
with open(tbs_file_name,"rb") as f:
    tbs_data=f.read()

with Certificate(cert_data) as cert_obj:
    if cert_obj.verify_signature(tbs_data,sign_data)==True:
        print("verify ok")
    else:
        print("verify fail")
    

