# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import SignedData
import sys

#联署签名验证
arg_count=len(sys.argv)

if arg_count!=3:
    print("Usage: python signeddatadetachedverifycountersignature.py sign_file_name tbs_file_name")
    sys.exit(-1)


sign_file_name=sys.argv[1]
tbs_file_name=sys.argv[2]


with open(sign_file_name,"rb") as f:
    sign_data=f.read()

with open(tbs_file_name,"rb") as f:
    tbs_data=f.read()


with SignedData(False) as sign_obj:
    sign_obj.set_verify_validity(False)
    sign_obj.detached_verify(tbs_data,sign_data)
    print("verify ok")
	
    count=sign_obj.get_signer_count()
    i=0
    while i<count:
        with sign_obj.get_signcert(i) as cert_obj:
            subject=cert_obj.get_subject()
            print("sign cert "+str(i)+" subject:\t"+subject)
        #联署签名个数
        num=sign_obj.get_int_attribute(19,i)
        ii=0
        while ii<num:
            sign_obj.verify_countersignature(i,ii)
            print("countersignature("+str(i)+","+str(ii)+") verify ok")
            with sign_obj.get_countsignaturecert(i,ii) as cert_obj2:
                subject2=cert_obj2.get_subject()
                print("sign cert subject:\t"+subject2)
            ii=ii+1
        i=i+1



