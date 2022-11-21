# -*- coding: utf-8 -*-
from netcacrypto import Certificate
import sys

arg_count=len(sys.argv)

if arg_count!=3:
    print("Usage: python certencrypt.py cert_file_name clear")
    sys.exit(-1)

file_name=sys.argv[1]
clear=sys.argv[2].encode("utf8")

with open(file_name,"rb") as f:
    data=f.read()

with Certificate(data) as cert_obj:
    cipher=cert_obj.encrypt(clear)

print(cipher.hex())
