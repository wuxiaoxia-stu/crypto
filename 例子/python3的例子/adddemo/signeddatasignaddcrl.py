# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import SignedData
import sys,urllib.request

#验证级别3,添加crl信息：签名证书的CRL

arg_count=len(sys.argv)

if arg_count!=3 and arg_count!=4:
    print("Usage: python signeddatasignaddcrl.py [-detached] tbs_file_name sign_file_name")
    sys.exit(-1)

detached=False
pos=1
if arg_count==4:
    if sys.argv[1]!="-detached":
        print("Usage: python signeddatasignaddcrl.py [-detached] tbs_file_name sign_file_name")
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
    sign_obj.set_signcert(cert_obj)
    sign_obj.apply_sign_config()
    sign_obj.set_detached(detached)
    sign_obj.set_include_cert_option(SignedData.INCLUDE_CERT_OPTION_CERTPATHWITHROOT)
    #add crl
    crl_url=cert_obj.get_string_attribute(56)
    if crl_url is None:
        print("no CRL Distribution Point Extension!")
        sys.exit(-1)
    print("crl_url:\t"+crl_url)
    crl=urllib.request.urlopen(crl_url)
    sign_obj.add_crl(crl.read())
    
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

