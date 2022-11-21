# -*- coding: utf-8 -*-
from netcacrypto import Certificate
import sys

arg_count=len(sys.argv)

if arg_count!=3:
    print("Usage: python certmatch.py cert_file_name expr")
    sys.exit(-1)

file_name=sys.argv[1]
expr=sys.argv[2]

with open(file_name,"rb") as f:
    data=f.read()

with Certificate(data) as cert_obj:
    if cert_obj.match(expr)==True:
        print("match")
    else:
        print("mismatch")
    

