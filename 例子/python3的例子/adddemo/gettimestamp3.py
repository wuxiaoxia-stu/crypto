# -*- coding: utf-8 -*-
from netcacrypto import TimeStamp,Certificate
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

hashalgo=["MD5","SHA1","SHA224","SHA256","SHA384","SHA512","SM3","SHA512/224","SHA512/256","SHA3-224","SHA3-256","SHA3-384","SHA3-512"]

arg_count=len(sys.argv)

if arg_count!=6:
    print("Usage: python gettimestamp3.py hash_algo tsa_url data_file_name token_file_name [timestamp_cert_file_name]")
    sys.exit(-1)



algo=get_hash_algo(sys.argv[1].upper())
if algo==-1:
    print("bad hash algo")
    sys.exit(-1)

with Hash(algo) as hash_obj: 
    with open(sys.argv[3],"rb") as f:
        while True:
            data=f.read(64*1024)
            if len(data)==0:
                break
            hash_obj.update(data)
    hash_value=hash_obj.final()

tsa_url=sys.argv[2]
token_file_name=sys.argv[4]
timestamp_cert_file_name =sys.argv[5]
with open(timestamp_cert_file_name,"rb") as f:
    timestamp_cert_data=f.read()
    


with TimeStamp() as timestamp_obj:
    #设置时间戳服务器的URL
    timestamp_obj.set_tsa_url(tsa_url)
    #设置时间戳证书
    with Certificate(timestamp_cert_data) as cert: 
        timestamp_obj.set_tsa_cert(cert)
    
    #设置时间戳的Hash算法
    timestamp_obj.set_hash_algo(algo)
    #获取时间戳的Hash算法
    a=timestamp_obj.get_hash_algo()
    print("hash algo:\t"+hashalgo[int(a/4096)-1])
    
    #设置要进行时间戳数据的Hash值
    timestamp_obj.set_hash_value(hash_value)
    #获取进行时间戳数据的Hash值
    hash_value=timestamp_obj.get_hash_value()
    print("hash value:\t"+hash_value.hex()) 
    
    '''
    #设置时间戳策略oid
    timestamp_obj.set_policy("1.3.6.1.4.1.13762.3")
    '''
    
    
    #设置是否要求时间戳响应带证书，若不带，响应的状态为RESP_STATUS_BADRESP
    timestamp_obj.set_certreq(False)

    #获取是否要求时间戳响应带证书
    certreq=timestamp_obj.get_certreq()
    print("certreq:\t"+str(certreq))
    
    #获取时间戳响应
    status=timestamp_obj.get_resp()
    if status!=TimeStamp.RESP_STATUS_GRANTED and status!=TimeStamp. RESP_STATUS_GRANTEDWITHMODS:
        print("get timestamp resp fail,status="+str(status))
        sys.exit(-1)
    print("get timestamp ok")
    #获取时间戳时间
    time=timestamp_obj.get_time()
    print("time:"+time)
    #获取时间戳Token
    token=timestamp_obj.get_token()
    
with open(token_file_name,"wb") as f:
    f.write(token)
    
    
with TimeStamp.verify_timestamp_token(token,Certificate(timestamp_cert_data)) as timestamp_obj_verify:    
    #获取时间戳的Hash算法
    a=timestamp_obj_verify.get_hash_algo()
    print("hash algo:\t"+hashalgo[int(a/4096)-1])
    
    #获取进行时间戳数据的Hash值
    hash_value=timestamp_obj_verify.get_hash_value()
    print("hash value:\t"+hash_value.hex()) 
    
    #获取时间戳策略oid
    policy=timestamp_obj_verify.get_policy()
    print("policy:\t"+policy)
    
    #获取时间戳序列号
    sn=timestamp_obj_verify.get_sn()
    print("sn:\t"+sn)
    #获取时间戳的精度
    ac=timestamp_obj_verify.get_accuracy()
    print("accuracy:\t",end='')
    if ac!=None:
        print(ac)
    else:
        print("None")
    #获取时间戳证书
    with timestamp_obj_verify.get_tsa_cert() as cert_obj:
        subject=cert_obj.get_subject()
        print("tsa cert subject:\t"+subject)


