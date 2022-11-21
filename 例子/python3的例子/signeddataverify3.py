# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import SignedData
import sys

arg_count=len(sys.argv)

if arg_count!=3:
    print("Usage: python signeddataverify3.py sign_file_name tbs_file_name")
    sys.exit(-1)

tbs_file_name=sys.argv[2]
sign_file_name=sys.argv[1]

with SignedData(False) as sign_obj,open(sign_file_name,"rb") as f_in,open(tbs_file_name,"wb") as f_out:
    sign_obj.verify_init()
    while True:
        sign_data=f_in.read(64*1024)
        if len(sign_data)==0:
            break
        tbs_data=sign_obj.verify_update(sign_data)
        f_out.write(tbs_data)
    sign_obj.verify_final()
    
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
        i=i+1



