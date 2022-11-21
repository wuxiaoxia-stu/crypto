# -*- coding: utf-8 -*-
from netcacrypto import Certificate
import sys

arg_count=len(sys.argv)

if arg_count!=3:
    print("Usage: python verifycertbyocsp.py url cert_file_name")
    sys.exit(-1)

url=sys.argv[1]
file_name=sys.argv[2]

with open(file_name,"rb") as f:
    data=f.read()

with Certificate(data) as cert_obj:
    status=cert_obj.verify_by_ocsp(url)
    status_value=status["status"]
    if status_value==Certificate.STATUS_UNREVOKED:
            print("good")
    elif status_value==Certificate.STATUS_UNDETERMINED:
        print("unknown")
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
