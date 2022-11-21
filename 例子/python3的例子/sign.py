# -*- coding: utf-8 -*-
from netcacrypto import Certificate
import sys

arg_count=len(sys.argv)

if arg_count!=2:
    print("Usage: python sign.py tbs")
    sys.exit(-1)

tbs=sys.argv[1].encode("utf8")

cert_obj=Certificate.get_user_cert(Certificate.USER_CERT_TYPE_SIGN)
if cert_obj is None:
    print("no sign cert")
    sys.exit(-1)

with cert_obj:
    signature=cert_obj.sign(tbs)

print(signature.hex())
