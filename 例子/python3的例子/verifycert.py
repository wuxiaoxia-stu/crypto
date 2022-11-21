# -*- coding: utf-8 -*-
from netcacrypto import Certificate
import sys

arg_count=len(sys.argv)

if arg_count!=2:
    print("Usage: python verifycert.py cert_file_name")
    sys.exit(-1)

file_name=sys.argv[1]

with open(file_name,"rb") as f:
    data=f.read()

flag=0
with Certificate(data) as cert_obj:
    status=cert_obj.verify(flag)
    status_value=status["status"]
    if status_value==Certificate.STATUS_UNREVOKED:
            print("unrevoked")
    elif status_value==Certificate.STATUS_UNDETERMINED:
        print("undetermined")
    elif status_value==Certificate.STATUS_REVOKED or status_value==Certificate.STATUS_CA_REVOKED:
        if status_value==Certificate.STATUS_REVOKED:
            print("revoked")
        else:
            print("ca revoked")
        print("revoked time:"+status["revoked_time"])
        reason=status.get("revoked_reason")
        if not(reason is None):
            print("revoked reason:"+str(reason))
    else:
        print("unknown statu:"+str(status_value))
