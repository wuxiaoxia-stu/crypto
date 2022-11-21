# -*- coding: utf-8 -*-
from netcacrypto import Certificate
import sys

arg_count=len(sys.argv)

if arg_count!=4:
    print("Usage: python certencryptfile.py cert_file_name clear_file_name env_file_name")
    sys.exit(-1)

cert_file_name=sys.argv[1]
clear_file_name=sys.argv[2]
env_file_name=sys.argv[3]

with open(clear_file_name,"rb") as f:
    clear_data=f.read()

with open(cert_file_name,"rb") as f:
    cert_data=f.read()

with Certificate(cert_data) as cert_obj:
    encrypt_data=cert_obj.encrypt(clear_data)

with open(env_file_name,"wb") as f:
    f.write(encrypt_data)

print("encrypt ok")