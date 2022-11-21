# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import SignedData
import sys

arg_count=len(sys.argv)

if arg_count!=4:
    print("Usage: python signeddataattachtimestamp2 tbs_file_name old_sign_file_name new_sign_file_name")
    sys.exit(-1)

tbs_file_name=sys.argv[1]
old_sign_file_name=sys.argv[2]
new_sign_file_name=sys.argv[3]

with open(old_sign_file_name,"rb") as f:
    sign_data=f.read()
    
with SignedData(False) as sign_obj,open(tbs_file_name,"rb") as f_in:
    sign_obj.detached_verify_init(sign_data)
    while True:
        tbs_data=f_in.read(64*1024)
        if len(tbs_data)==0:
            break
        sign_obj.detached_verify_update(tbs_data)
    sign_obj.detached_verify_final()
    
    print("verify ok")
    
    sign_data=sign_obj.attach_timestamp()
    with open(new_sign_file_name,"wb") as f_out:
        f_out.write(sign_data)
    time=sign_obj.get_tsa_time()
    print("timestamp:"+time)
    print("attach timestamp ok")

