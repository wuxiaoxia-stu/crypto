# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import SignedData
from netcacrypto import Hash
import sys

def get_hash_algo(name):
	if name=="MD5":
		return Hash.MD5
	elif name=="SHA1":
		return Hash.SHA1
	elif name=="SHA224":
		return Hash.SHA224
	elif name=="SHA256":
		return Hash.SHA256
	elif name=="SHA384":
		return Hash.SHA384
	elif name=="SHA512":
		return Hash.SHA512
	elif name=="SM3":
		return Hash.SM3
	elif name=="SHA512/224":
		return Hash.SHA512_224
	elif name=="SHA512/256":
		return Hash.SHA512_256
	elif name=="SHA3-224":
		return Hash.SHA3_224
	elif name=="SHA3-256":
		return Hash.SHA3_256
	elif name=="SHA3-384":
		return Hash.SHA3_384
	elif name=="SHA3-512":
		return Hash.SHA3_512	
	else:
		return -1

arg_count=len(sys.argv)

if arg_count!=5:
    print("Usage: python signeddataattachtimestamp3 hash_algo tsa_url old_sign_file_name new_sign_file_name")
    sys.exit(-1)

hash_algo=get_hash_algo(sys.argv[1].upper())
if hash_algo==-1:
	print("bad hash algo")
	sys.exit(-1)
tsa_url=sys.argv[2]
old_sign_file_name=sys.argv[3]
new_sign_file_name=sys.argv[4]

with SignedData.new_verify_object() as sign_obj,open(old_sign_file_name,"rb") as f_in:
    sign_obj.keep_tbs()
    sign_obj.verify_init()
    while True:
        sign_data=f_in.read(64*1024)
        if len(sign_data)==0:
            break
        tbs_data=sign_obj.verify_update(sign_data)
    
    sign_obj.verify_final()
    sign_obj.verify_postcheck()
    print("verify ok")
    
    sign_data=sign_obj.attach_signature_timestamp(tsa_url,hash_algo)
    with open(new_sign_file_name,"wb") as f_out:
        f_out.write(sign_data)
    time=sign_obj.get_tsa_time()
    print("timestamp:"+time)
    print("attach timestamp ok")

