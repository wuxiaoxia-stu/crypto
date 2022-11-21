# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import EnvelopedData
import sys


arg_count=len(sys.argv)

if arg_count!=4:
    print("Usage: python envelopeddataencrypt3.py cert_file_name clear_file_name env_file_name")
    sys.exit(-1)

cert_file_name=sys.argv[1]
clear_file_name=sys.argv[2]
env_file_name=sys.argv[3]

with open(cert_file_name,"rb") as f:
    cert_data=f.read()

with Certificate(cert_data) as cert_obj,EnvelopedData(True) as env_obj,open(clear_file_name,"rb") as f_in,open(env_file_name,"wb") as f_out:
    env_obj.set_encrypt_algo(EnvelopedData.AES128_CBC)
    env_obj.add_encrypt_cert(cert_obj)
    env_data=env_obj.encrypt_init()
    f_out.write(env_data)
    while True:
        clear_data=f_in.read(64*1024)
        if len(clear_data)==0:
            break
        env_data=env_obj.encrypt_update(clear_data)
        f_out.write(env_data)
    env_data=env_obj.encrypt_final()
    f_out.write(env_data)

print("encrypt ok")

