# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import SignedData
import sys,urllib.request

#验证级别4,添加crl信息：签名证书和二级CA证书的CRL

arg_count=len(sys.argv)

if arg_count!=5 and arg_count!=6:
    print("Usage: python signeddatasignaddcrl2.py [-detached] tbs_file_name sign_file_name cert_file issuer_cert_file")
    sys.exit(-1)

detached=False
pos=1
if arg_count==6:
    if sys.argv[1]!="-detached":
        print("Usage: python signeddatasignaddcrl2.py [-detached] tbs_file_name sign_file_name cert_file issuer_cert_file")
        sys.exit(-1)
    detached=True
    pos=2

tbs_file_name=sys.argv[pos]
sign_file_name=sys.argv[pos+1]
cert_file=sys.argv[pos+2]
issuer_cert_file=sys.argv[pos+3]

with open(tbs_file_name,"rb") as f:
    tbs_data=f.read()

with open(cert_file,"rb") as f:
    cert_data=f.read()

with open(issuer_cert_file,"rb") as f:
    issuer_cert_data=f.read()

cert_obj=Certificate(cert_data)
if cert_obj is None:
    print("no sign cert")
    sys.exit(-1)

issuer_cert_obj=Certificate(issuer_cert_data)
if issuer_cert_obj is None:
    print("no issuer cert")
    sys.exit(-1)

with cert_obj,SignedData(True) as sign_obj,open(tbs_file_name,"rb") as f_in,open(sign_file_name,"wb") as f_out:
    sign_obj.set_signcert(cert_obj)
    sign_obj.apply_sign_config()
    sign_obj.set_detached(detached)
    sign_obj.set_include_cert_option(SignedData.INCLUDE_CERT_OPTION_CERTPATHWITHROOT)
    #add crl
    #sign cert crl
    crl_url1=cert_obj.get_string_attribute(56)
    if crl_url1 is None:
        print("no CRL Distribution Point Extension!")
        sys.exit(-1)
    print("crl_url:\t"+crl_url1)
    crl1=urllib.request.urlopen(crl_url1)
    sign_obj.add_crl(crl1.read())

    #issuer cert crl
    crl_url2=issuer_cert_obj.get_string_attribute(56)
    if crl_url2 is None:
        print("no CRL Distribution Point Extension!")
        sys.exit(-1)
    print("crl_url:\t"+crl_url2)
    crl2=urllib.request.urlopen(crl_url2)
    sign_obj.add_crl(crl2.read())
    
    #sign
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

