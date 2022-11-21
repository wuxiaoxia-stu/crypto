# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import SignedData
import sys

arg_count=len(sys.argv)

if arg_count!=3:
    print("Usage: python signeddataattachtimestamp1 old_sign_file_name new_sign_file_name")
    sys.exit(-1)

new_sign_file_name=sys.argv[2]
old_sign_file_name=sys.argv[1]

with SignedData.new_verify_object() as sign_obj,open(old_sign_file_name,"rb") as f_in:
    sign_obj.keep_tbs()
    sign_obj.verify_init()
    while True:
        sign_data=f_in.read(64*1024)
        if len(sign_data)==0:
            break
        tbs_data=sign_obj.verify_update(sign_data)
    
    sign_obj.verify_final()
    sign_obj.verify_postcheck()
    print("verify ok")
    
    sign_data=sign_obj.attach_timestamp()
    with open(new_sign_file_name,"wb") as f_out:
        f_out.write(sign_data)
    time=sign_obj.get_tsa_time()
    print("timestamp:"+time)
    print("attach timestamp ok")

