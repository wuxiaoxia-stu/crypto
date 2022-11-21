# -*- coding: utf-8 -*-
from netcacrypto import EnvelopedData
from netcacrypto import Certificate
import sys

arg_count=len(sys.argv)

if arg_count!=3:
    print("Usage: python envelopeddatadecrypt3.py env_file_name clear_file_name")
    sys.exit(-1)

clear_file_name=sys.argv[2]
env_file_name=sys.argv[1]

with EnvelopedData.new(False) as env_obj,open(clear_file_name,"wb") as f_out,open(env_file_name,"rb") as f_in:
    env_obj.decrypt_init()
    while True:
        env_data=f_in.read(64*1024)
        if len(env_data)==0:
            break
        clear_data=env_obj.decrypt_update(env_data)
        f_out.write(clear_data)
    env_obj.decrypt_final()
    env_obj.decrypt_postcheck()
    print("decrypt ok")
    cert_obj=env_obj.get_decrypt_cert()
    with cert_obj:
        subject=cert_obj.get_subject()
        print("decrypt cert subject:\t"+subject)


