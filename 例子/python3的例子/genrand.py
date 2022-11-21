# -*- coding: utf-8 -*-
import netcacrypto
import sys

arg_count=len(sys.argv)

if arg_count!=2:
	print("Usage: python genrand.py length")
	sys.exit(-1)

len=int(sys.argv[1])
print(netcacrypto.generate_random(len).hex())
