# -*- coding: utf-8 -*-
from netcacrypto import TimeStamp
import sys

arg_count=len(sys.argv)

if arg_count!=3:
    print("Usage: python verifytimestamp1.py str token_file_name")
    sys.exit(-1)

data=sys.argv[1].encode("utf8")
token_file_name=sys.argv[2]
with open(token_file_name,"rb") as f:
    token=f.read()

with TimeStamp.verify_timestamp(data,token) as timestamp_obj:
    print("verify timestamp ok")
    time=timestamp_obj.get_time()
    print("time:"+time)
    with timestamp_obj.get_tsa_cert() as cert_obj:
        subject=cert_obj.get_subject()
        print("tsa cert subject:\t"+subject)



