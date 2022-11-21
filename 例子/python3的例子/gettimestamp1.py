# -*- coding: utf-8 -*-
from netcacrypto import TimeStamp
import sys

arg_count=len(sys.argv)

if arg_count!=3:
    print("Usage: python gettimestamp1.py str token_file_name")
    sys.exit(-1)

data=sys.argv[1].encode("utf8")
token_file_name=sys.argv[2]

with TimeStamp.get_timestamp(data) as timestamp_obj:
    time=timestamp_obj.get_time()
    print("time:"+time)
    token=timestamp_obj.get_token()

with open(token_file_name,"wb") as f:
    f.write(token)

print("get timestamp ok")

