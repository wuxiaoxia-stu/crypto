# -*- coding: utf-8 -*-
from netcacrypto import TimeStamp
from netcacrypto import Hash
import sys

arg_count=len(sys.argv)

if arg_count!=3:
    print("Usage: python verifytimestamp2.py data_file_name token_file_name")
    sys.exit(-1)

data_file_name=sys.argv[1]
token_file_name=sys.argv[2]
with open(token_file_name,"rb") as f:
    token=f.read()

with TimeStamp.verify_timestamp_token(token) as timestamp_obj:
    algo=timestamp_obj.get_hash_algo()
    hash_value=timestamp_obj.get_hash_value()
    with open(data_file_name,"rb") as f,Hash(algo) as hash_obj:
        while True:
            data=f.read(64*1024)
            if len(data)==0:
                break
            hash_obj.update(data)
        hash_value2=hash_obj.final()
    if hash_value!=hash_value2:
        print("hash mismatch")
        sys.exit(-1)
    print("verify timestamp ok")
    time=timestamp_obj.get_time()
    print("time:"+time)
    with timestamp_obj.get_tsa_cert() as cert_obj:
        subject=cert_obj.get_subject()
        print("tsa cert subject:\t"+subject)



