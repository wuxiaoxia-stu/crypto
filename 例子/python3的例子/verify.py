# -*- coding: utf-8 -*-
from netcacrypto import Certificate
import sys

arg_count=len(sys.argv)

if arg_count!=4:
    print("Usage: python verify.py cert_file_name tbs signature")
    sys.exit(-1)

file_name=sys.argv[1]
tbs=sys.argv[2].encode("utf8")
signature=bytes.fromhex(sys.argv[3])

with open(file_name,"rb") as f:
    data=f.read()

with Certificate(data) as cert_obj:
    if cert_obj.verify_signature(tbs,signature)==True:
        print("verify ok")
    else:
        print("verify fail")
    

