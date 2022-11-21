# -*- coding: utf-8 -*-
from netcacrypto import Certificate
import sys

arg_count=len(sys.argv)

if arg_count!=2:
    print("Usage: python certdecrypt.py cipher")
    sys.exit(-1)

cipher=bytes.fromhex(sys.argv[1])

cert_obj=Certificate.get_user_cert(Certificate.USER_CERT_TYPE_ENCRYPT)
if cert_obj is None:
    print("no decrypt cert")
    sys.exit(-1)
    
with cert_obj:
    clear=cert_obj.decrypt(cipher)

print(clear)
