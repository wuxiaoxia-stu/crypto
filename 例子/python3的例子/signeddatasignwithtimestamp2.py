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

if arg_count!=5 and arg_count!=6:
    print("Usage: python signeddatasignwithtimestamp2.py [-detached] hash_algo tsa_url tbs_file_name sign_file_name")
    sys.exit(-1)

detached=False
pos=1
if arg_count==6:
    if sys.argv[1]!="-detached":
        print("Usage: python signeddatasignwithtimestamp2.py [-detached] hash_algo tsa_url tbs_file_name sign_file_name")
        sys.exit(-1)
    detached=True
    pos=2

hash_algo=get_hash_algo(sys.argv[pos].upper())
if hash_algo==-1:
	print("bad hash algo")
	sys.exit(-1)
tsa_url=sys.argv[pos+1]
tbs_file_name=sys.argv[pos+2]
sign_file_name=sys.argv[pos+3]

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
    sign_data=sign_obj.sign_init()
    f_out.write(sign_data)
    while True:
        tbs_data=f_in.read(64*1024)
        if len(tbs_data)==0:
            break
        sign_data=sign_obj.sign_update(tbs_data)
        f_out.write(sign_data)
    sign_data=sign_obj.sign_with_timestamp_final(tsa_url,hash_algo)
    f_out.write(sign_data)
    time=sign_obj.get_tsa_time()
    print("timestamp:"+time)

print("sign ok")

