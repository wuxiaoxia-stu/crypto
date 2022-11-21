# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import SignedData
import sys

arg_count=len(sys.argv)

if arg_count!=3:
    print("Usage: python signeddatadetachedverifywithtimestamp1.py tbs_file_name sign_file_name")
    sys.exit(-1)

tbs_file_name=sys.argv[1]
sign_file_name=sys.argv[2]

with open(sign_file_name,"rb") as f:
    sign_data=f.read()
    
with SignedData.new_verify_object() as sign_obj,open(tbs_file_name,"rb") as f:
    sign_obj.detached_verify_init(sign_data)
    while True:
        tbs_data=f.read(64*1024)
        if len(tbs_data)==0:
            break
        sign_obj.detached_verify_update(tbs_data)
    sign_obj.detached_verify_final()
    sign_obj.verify_postcheck()
    
    print("verify ok")
    #add Q7 assert
    if sign_obj.get_int_attribute(23,-1)==1:
        print('Q7 signeddata verify true')
    count=sign_obj.get_signer_count()
    i=0
    while i<count:
        with sign_obj.get_signcert(i) as cert_obj:
            subject=cert_obj.get_subject()
            print("sign cert "+str(i)+" subject:\t"+subject)
        if sign_obj.has_tsa_time(i):
            sign_obj.verify_timestamp(i)
            print("verify time stamp "+str(i)+" ok")
            time=sign_obj.get_tsa_time(i)
            print("time stamp "+str(i)+":"+time)
            with sign_obj.get_tsacert(i) as cert_obj:
                subject=cert_obj.get_subject()
                print("tsa cert "+str(i)+" subject:\t"+subject)
        i=i+1



