# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import EnvelopedData
import sys


arg_count=len(sys.argv)

if arg_count!=5:
    print("Usage: python envelopeddataencrypt5.py cert_file_name1 cert_file_name2 clear_file_name env_file_name")
    sys.exit(-1)

cert_file_name1=sys.argv[1]
cert_file_name2=sys.argv[2]
clear_file_name=sys.argv[3]
env_file_name=sys.argv[4]

with open(cert_file_name1,"rb") as f:
    cert_data1=f.read()

with open(cert_file_name2,"rb") as f:
    cert_data2=f.read()

with Certificate(cert_data1) as cert_obj1,Certificate(cert_data2) as cert_obj2,EnvelopedData.new(True) as env_obj,open(clear_file_name,"rb") as f_in,open(env_file_name,"wb") as f_out:
    flag=0
    if EnvelopedData.is_default_use_subject_key_id():
        flag=EnvelopedData.USEKEYID
    env_obj.add_encrypt_cert(cert_obj1,flag)
    env_obj.add_encrypt_cert(cert_obj2,flag)
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

