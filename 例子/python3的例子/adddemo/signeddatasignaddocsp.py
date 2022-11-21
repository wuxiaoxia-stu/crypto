# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import SignedData
import sys,urllib.request
from oscrypto import asymmetric
from ocspbuilder import OCSPRequestBuilder,OCSPResponseBuilder
from datetime import datetime
from asn1crypto.util import timezone
import asn1crypto.x509



#验证级别3、4

arg_count=len(sys.argv)

if arg_count!=7 and arg_count!=8:
    print("Usage: python signeddatasignaddocsp.py [-detached] tbs_file_name sign_file_name subject_cert_file_name issuer_cert_file_name ocsp_cert_file_name ocspres_data_file_name")
    sys.exit(-1)

detached=False
pos=1
if arg_count==8:
    if sys.argv[1]!="-detached":
        print("Usage: python signeddatasignaddocsp.py [-detached] tbs_file_name sign_file_name subject_cert_file_name issuer_cert_file_name ocsp_cert_file_name ocspres_data_file_name")
        sys.exit(-1)
    detached=True
    pos=2

tbs_file_name=sys.argv[pos]
sign_file_name=sys.argv[pos+1]
subject_cert_file_name=sys.argv[pos+2]
issuer_cert_file_name=sys.argv[pos+3]
ocsp_cert_file_name=sys.argv[pos+4]
ocspres_data_file_name=sys.argv[pos+5]

with open(tbs_file_name,"rb") as f:
    tbs_data=f.read()

with open(subject_cert_file_name,"rb") as f:
    subject_cert_data=f.read()

with open(ocsp_cert_file_name,"rb") as f:
    ocsp_cert=f.read()

subject_cert=asymmetric.load_certificate(subject_cert_file_name)
issuer_cert=asymmetric.load_certificate(issuer_cert_file_name)


builder = OCSPRequestBuilder(subject_cert, issuer_cert)
ocsp_request = builder.build()
request_der_bytes = ocsp_request.dump()

cert_obj=Certificate(subject_cert_data)
if cert_obj is None:
    print("no sign cert")
    sys.exit(-1)

with cert_obj,SignedData(True) as sign_obj,open(tbs_file_name,"rb") as f_in,open(sign_file_name,"wb") as f_out:
    sign_obj.set_signcert(cert_obj)
    sign_obj.apply_sign_config()
    sign_obj.set_detached(detached)
    sign_obj.set_include_cert_option(SignedData.INCLUDE_CERT_OPTION_CERTPATHWITHROOT)
    #add ocsp
    ocsp_url=cert_obj.get_string_attribute(58)
    if ocsp_url is None:
        print("no Authority Info Access Extension!")
        sys.exit(-1)
    print("ocsp_url:\t"+ocsp_url)
    
    #ocsp
    new_url = urllib.request.Request(ocsp_url,request_der_bytes)
    ocsp_response=urllib.request.urlopen(new_url)
    response = asn1crypto.ocsp.OCSPResponse.load(ocsp_response.read())
    basic_response = response['response_bytes']['response'].parsed
    response_der_bytes = basic_response.dump()
    with open(ocspres_data_file_name,"wb") as f:
       f.write(response_der_bytes)
    print("get response")

    response_data = basic_response['tbs_response_data']
    print(basic_response['signature_algorithm'].hash_algo)

    sign_obj.add_ocsp(0,Certificate(ocsp_cert), response_der_bytes)
    print("add ocsp")

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