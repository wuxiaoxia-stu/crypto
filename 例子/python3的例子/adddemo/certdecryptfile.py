# -*- coding: utf-8 -*-
from netcacrypto import Certificate
import sys

arg_count=len(sys.argv)

if arg_count!=3:
    print("Usage: python certdecryptfile.py env_file_name clear_file_name")
    sys.exit(-1)
    
env_file_name=sys.argv[1]
clear_file_name=sys.argv[2]

with open(env_file_name,"rb") as f:
    env_data=f.read()


with Certificate.get_user_cert(Certificate.USER_CERT_TYPE_ENCRYPT) as cert_obj:
    clear_data=cert_obj.decrypt(env_data)

with open(clear_file_name,"wb") as f:
    f.write(clear_data)

print("decrypt ok")