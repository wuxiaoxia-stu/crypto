# -*- coding: utf-8 -*-
from netcacrypto import Base64
import sys

arg_count=len(sys.argv)

if arg_count!=4:
    print("Usage: python base64.py -e|-d in_file_name out_file_name")
    sys.exit(-1)

enc=None
flag=0
if sys.argv[1]=="-e":
    enc=True
elif sys.argv[1]=="-d":
    enc=False
else:
    print("Usage: python base64.py -e|-d in_file_name out_file_name")
    sys.exit(-1)

in_file_name=sys.argv[2]
out_file_name=sys.argv[3]
with open(in_file_name,"rb") as f_in,open(out_file_name,"wb") as f_out,Base64(enc,flag) as b64_obj:
    while True:
        data=f_in.read(64*1024)
        if len(data)==0:
            break
        out_data=b64_obj.update(data)
        f_out.write(out_data)
    out_data=b64_obj.final()
    f_out.write(out_data)

if enc:
    print("base64 encode ok")
else:
    print("base64 decode ok")

