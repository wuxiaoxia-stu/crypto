# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import SignedData
import sys

arg_count=len(sys.argv)

if arg_count!=7:
    print("Usage: python signeddatadetachedverifyaddocsp.py tbs_file_name sign_file_name issuer_cert_file_name root_cert_file_name ocspcert_file_name ocspres_data_file_name")
    sys.exit(-1)

tbs_file_name=sys.argv[1]
sign_file_name=sys.argv[2]
issuer_cert_file_name=sys.argv[3]
root_cert_file_name=sys.argv[4]
ocspcert_file_name=sys.argv[5]
ocspres_data_file_name=sys.argv[6]

with open(sign_file_name,"rb") as f:
    sign_data=f.read()

with open(tbs_file_name,"rb") as f:
    tbs_data=f.read()
    
with open(issuer_cert_file_name,"rb") as f:
    issuer_cert_data=f.read()

with open(root_cert_file_name,"rb") as f:
    root_cert_data=f.read()

with open(ocspcert_file_name,"rb") as f:
    ocspcert_data=f.read()
with open(ocspres_data_file_name,"rb") as f:
    ocspres_data=f.read()


with SignedData(False) as sign_obj:
    #设置验签级别
    #0：仅解析，不验证
    #1：仅验证签名本身，不验证证书
    #2：验证签名和证书，但是不验证证书是否作废
    #3：验证签名和证书，并验证签名证书是否作废。但不验证CA证书是否作废
    #4：验证签名和整个证书路径，包括包括它们是否作废
    level=3
    sign_obj.set_verify_level(level)
    print("verify level:\t"+str(level))
    
    #添加CA证书,验证级别为2，3，4时会使用到
    with Certificate(issuer_cert_data) as cert: 
        sign_obj.add_cert(cert)

    with Certificate(root_cert_data) as cert: 
        sign_obj.add_rootcert(cert)
    
    #添加OCSP响应编码
    sign_obj.add_ocsp(0,Certificate(ocspcert_data),ocspres_data)

    #设置是否验证证书的有效期
    verifyvalidity=False
    sign_obj.set_verify_validity(verifyvalidity)
    print("verify validity:\t"+str(verifyvalidity))
    
    
    sign_obj.detached_verify(tbs_data,sign_data)
    
    if level!=0:
        count=sign_obj.get_signer_count()
        i=0
        while i<count:
            with sign_obj.get_signcert(i) as cert_obj:
                subject=cert_obj.get_subject()
                print("sign cert "+str(i)+" subject:\t"+subject)
            i=i+1
print("verify ok")



