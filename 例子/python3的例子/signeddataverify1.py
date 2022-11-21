# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import SignedData
import sys

arg_count=len(sys.argv)

if arg_count!=3:
    print("Usage: python signeddataverify1.py tbs_file_name sign_file_name")
    sys.exit(-1)

tbs_file_name=sys.argv[1]
sign_file_name=sys.argv[2]

with open(tbs_file_name,"rb") as f:
    tbs_data=f.read()

with open(sign_file_name,"rb") as f:
    sign_data=f.read()
    
with SignedData.verify_data(tbs_data,sign_data) as cert_obj:
    subject=cert_obj.get_subject()
    print("sign cert subject:\t"+subject)


print("verify ok")

