# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import SignedData
import sys


def get_sign_algo(cert_obj):
    if cert_obj.match("Algorithm='RSA'"):
        return SignedData.SHA512WITHRSA
    elif cert_obj.match("Algorithm='SM2'"):
        return SignedData.SM3WITHSM2
    elif cert_obj.match("Algorithm='ECC'"):
        return SignedData.ECDSAWITHSHA512
    else:
        return -1

arg_count=len(sys.argv)

if arg_count!=3 and arg_count!=4:
    print("Usage: python signeddatasign3.py [-detached] tbs_file_name sign_file_name")
    sys.exit(-1)

detached=False
pos=1
if arg_count==4:
    if sys.argv[1]!="-detached":
        print("Usage: python signeddatasign3.py [-detached] tbs_file_name sign_file_name")
        sys.exit(-1)
    detached=True
    pos=2

tbs_file_name=sys.argv[pos]
sign_file_name=sys.argv[pos+1]

with open(tbs_file_name,"rb") as f:
    tbs_data=f.read()

cert_obj=Certificate.get_user_cert(Certificate.USER_CERT_TYPE_SIGN)
if cert_obj is None:
    print("no sign cert")
    sys.exit(-1)

with cert_obj,SignedData(True) as sign_obj,open(tbs_file_name,"rb") as f_in,open(sign_file_name,"wb") as f_out:
    sign_obj.set_detached(detached)
    sign_obj.set_signcert(cert_obj)
    algo=get_sign_algo(cert_obj)
    if algo==-1:
        print("get_sign_algo fail")
        sys.exit(-1)
    sign_obj.set_sign_algo(algo)
    sign_data=sign_obj.sign_init()
    f_out.write(sign_data)
    while True:
        tbs_data=f_in.read(64*1024)
        if len(tbs_data)==0:
            break
        sign_data=sign_obj.sign_update(tbs_data)
        f_out.write(sign_data)
    sign_data=sign_obj.sign_final()
    f_out.write(sign_data)
print("sign ok")

