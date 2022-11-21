# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import EnvelopedData
import sys

arg_count=len(sys.argv)

if arg_count!=4:
    print("Usage: python envelopeddataencrypt1.py cert_file_name clear_file_name env_file_name")
    sys.exit(-1)

cert_file_name=sys.argv[1]
clear_file_name=sys.argv[2]
env_file_name=sys.argv[3]

with open(cert_file_name,"rb") as f:
    cert_data=f.read()

with open(clear_file_name,"rb") as f:
    clear_data=f.read()

with Certificate(cert_data) as cert_obj:
    env_data=EnvelopedData.encrypt_data(cert_obj,clear_data)

with open(env_file_name,"wb") as f:
    f.write(env_data)

print("encrypt ok")

