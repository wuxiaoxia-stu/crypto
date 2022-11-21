# -*- coding: utf-8 -*-
from netcacrypto import Base64
import sys

arg_count=len(sys.argv)

if arg_count!=4:
    print("Usage: python base64onestep.py -e|-d in_file_name out_file_name")
    sys.exit(-1)

enc=None
flag=0
if sys.argv[1]=="-e":
    enc=True
elif sys.argv[1]=="-d":
    enc=False
else:
    print("Usage: python base64onestep.py -e|-d in_file_name out_file_name")
    sys.exit(-1)

in_file_name=sys.argv[2]
out_file_name=sys.argv[3]


with open(in_file_name,"rb") as f:
    data=f.read()
    
with open(out_file_name,"wb") as f_out:
    out_data=Base64.base64(enc, flag, data)
    f_out.write(out_data)

if enc:
    print("base64 encode ok")
else:
    print("base64 decode ok")

