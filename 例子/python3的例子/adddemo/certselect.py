# -*- coding: utf-8 -*-
from netcacrypto import Certificate
import sys
'''
    type：输入参数，证书类型。
        Signature为签名证书，
        Encrypt为加密用的证书(无实现)，
        Decrypt为解密用的证书，
        Device为设备里的证书。
'''
arg_count=len(sys.argv)

if arg_count!=1:
    print("Usage: python certselect.py")
    sys.exit(-1)
     

#01 all
print("select cert from device:\t")
cert_obj=Certificate.select("Device")
if cert_obj is None:
    print("no cert")
else:
    with cert_obj:
        print(cert_obj.get_display_name())
        
#02 signature
print("select signature cert from device:\t")
cert_obj=Certificate.select("Signature")
if cert_obj is None:
    print("no signature cert")
else:
    with cert_obj:
        print(cert_obj.get_display_name())

#03 encrypt
print("select encrypt cert from device:\t")
cert_obj=Certificate.select("device","CertType='Encrypt'")
if cert_obj is None:
    print("no decrypt cert")
else:
    with cert_obj:
        print(cert_obj.get_display_name())
        
#04 decrypt
print("select decrypt cert from device:\t")
cert_obj=Certificate.select("Decrypt")
if cert_obj is None:
    print("no decrypt cert")
else:
    with cert_obj:
        print(cert_obj.get_display_name())
        


#05 默认证书策略
p=Certificate.get_select_cert_policy()
print("select cert policy:\t",p)

print("select cert from device:\t")
cert_obj=Certificate.select(p)
if cert_obj is None:
    print("no cert")
else:
    with cert_obj:
        print(cert_obj.get_display_name())

#06 修改证书策略：增加【证书在有效期内】
Certificate.set_select_cert_policy('{ "UIFlag":"default", "InValidity":true, "Method":"device", "Value":"any" }')
p=Certificate.get_select_cert_policy()
print("select cert policy:\t",p)

print("select cert from device:\t")
cert_obj=Certificate.select(p)
if cert_obj is None:
    print("no cert")
else:
    with cert_obj:
        print(cert_obj.get_display_name())


#07 过滤条件      
f=Certificate.get_filter_cert_condition()
print("filter cert condition:\t",f)      

Certificate.set_filter_cert_condition("IssuerCN~'T2' && KeyBits='2048' && InValidity='True'")
f=Certificate.get_filter_cert_condition()
print("filter cert condition:\t",f)  

print("select cert from device:\t")
cert_obj=Certificate.select("Device",f)
if cert_obj is None:
    print("no cert")
else:
    with cert_obj:
        print(cert_obj.get_display_name())


#08 从个人证书库获取证书
print("select cert from store:\t")
cert_obj=Certificate.select('{ \"UIFlag\":\"default\", \"InValidity\":true, \"Type\":\"signature\" , \"Method\":\"store\", \"Value\":{\"Type\":\"current user\",\"Value\":\"my\"}}')
if cert_obj is None:
    print("no cert")
else:
    with cert_obj:
        print(cert_obj.get_display_name())










