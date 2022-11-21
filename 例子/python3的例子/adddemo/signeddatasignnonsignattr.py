# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import SignedData
import sys

arg_count=len(sys.argv)

if arg_count!=4:
    print("Usage: python signeddatasignnonsignattr.py tbs_file_name sign_file_name SM2_cert_file")
    sys.exit(-1)


tbs_file_name=sys.argv[1]
sign_file_name=sys.argv[2]
cert_file_name=sys.argv[3]

with open(cert_file_name,"rb") as f:
    cert_data=f.read()
with open(tbs_file_name,"rb") as f:
    tbs_data=f.read()

cert_obj=Certificate(cert_data)
if cert_obj is None:
    print("no sign cert")
    sys.exit(-1)

with cert_obj,SignedData(True) as sign_obj,open(tbs_file_name,"rb") as f_in,open(sign_file_name,"wb") as f_out:
    cert_obj.get_privatekey("12345678")
    sign_obj.set_signcert(cert_obj)
    sign_obj.set_detached(False)
    sign_obj.set_sign_algo(SignedData.SM3WITHSM2)#set signalgo
    #产生不带签名属性的SignedData,设置不带签名时间属性
    sign_obj.set_int_attribute(4,0,0)
    sign_obj.set_include_cert_option(SignedData.INCLUDE_CERT_OPTION_CERTPATHWITHROOT)
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

