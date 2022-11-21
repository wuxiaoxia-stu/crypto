# -*- coding: utf-8 -*-
from netcacrypto import EnvelopedData
from netcacrypto import Certificate
import sys

arg_count=len(sys.argv)

if arg_count!=3:
    print("Usage: python envelopeddatadecrypt2.py env_file_name clear_file_name")
    sys.exit(-1)

clear_file_name=sys.argv[2]
env_file_name=sys.argv[1]

with open(env_file_name,"rb") as f:
    env_data=f.read()

cert_obj=Certificate.select("device","CertType='Encrypt'")
if cert_obj is None:
    print("no decrypt cert")
    sys.exit(-1)
    
with cert_obj:
    EnvelopedData.set_decrypt_cert(cert_obj)

clear_data=EnvelopedData.decrypt_data(env_data)
with open(clear_file_name,"wb") as f:
    f.write(clear_data)

print("decrypt ok")

