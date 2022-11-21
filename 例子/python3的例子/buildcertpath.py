# -*- coding: utf-8 -*-
from netcacrypto import Certificate
import sys

arg_count=len(sys.argv)

if arg_count!=2:
    print("Usage: python buildcertpath.py cert_file_name")
    sys.exit(-1)

file_name=sys.argv[1]

with open(file_name,"rb") as f:
    data=f.read()

with Certificate(data) as cert_obj:
    certpath=cert_obj.build_certpath()
    for cert in certpath:
        print(cert.get_subject())
    for cert in certpath:
        cert.free()
