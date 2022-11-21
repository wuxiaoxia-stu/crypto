# -*- coding: utf-8 -*-
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

if arg_count!=3:
	print("Usage: python hash.py sha1|sha256 file_name")
	sys.exit(-1)

algo=get_hash_algo(sys.argv[1].upper())
if algo==-1:
	print("bad hash algo")
	sys.exit(-1)

with Hash(algo) as hash_obj: 
	with open(sys.argv[2],"rb") as f:
		while True:
			data=f.read(64*1024)
			if len(data)==0:
				break
			hash_obj.update(data)
	hash_value=hash_obj.final()
	print(hash_value.hex())


