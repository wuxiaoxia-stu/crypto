# -*- coding: utf-8 -*-
from netcacrypto import Certificate
from netcacrypto import EnvelopedData
import sys

arg_count=len(sys.argv)
encryptalgo=["DES_CBC","RC2_CBC","TDES_CBC","AES128_CBC","AES192_CBC","AES256_CBC","SSF33_CBC0","SM1_CBC","SM4_CBC","RC4"]

if arg_count!=4:
    print("Usage: python envelopeddataencrypt4.py cert_file_name clear_file_name env_file_name")
    sys.exit(-1)

cert_file_name=sys.argv[1]
clear_file_name=sys.argv[2]
env_file_name=sys.argv[3]

with open(cert_file_name,"rb") as f:
    cert_data=f.read()

with Certificate(cert_data) as cert_obj,EnvelopedData.new(True) as env_obj,open(clear_file_name,"rb") as f_in,open(env_file_name,"wb") as f_out:
    #设置是否使用contentinfo封装
    env_obj.set_use_contentinfo(False)
    #判断是否ContentInfo封装
    print("ContentInfo:\t"+str(env_obj.is_contentinfo()))
    
    #设置默认的对称加密算法
    EnvelopedData.set_default_encrypt_algo(EnvelopedData.DES_CBC)
    #获取默认的对称加密算法
    print("default encrypt algo:\t"+encryptalgo[EnvelopedData.get_default_encrypt_algo()-1])
    #设置对称加密算法
    env_obj.set_encrypt_algo(EnvelopedData.AES128_CBC)
    #获取数字信封使用的对称加密算法
    print("encrypt algo:\t"+encryptalgo[env_obj.get_encrypt_algo()-1])
    
    flag=0
    #设置默认是否使用主体密钥标识符
    EnvelopedData.set_default_use_subject_key_id(False)
    #判断默认是否使用主体密钥标识符
    print("use subject key id:\t"+str(EnvelopedData.is_default_use_subject_key_id()))
    if EnvelopedData.is_default_use_subject_key_id():
        flag=EnvelopedData.USEKEYID
        
    env_obj.add_encrypt_cert(cert_obj,flag)
    env_data=env_obj.encrypt_init()
    f_out.write(env_data)
    while True:
        clear_data=f_in.read(64*1024)
        if len(clear_data)==0:
            break
        env_data=env_obj.encrypt_update(clear_data)
        f_out.write(env_data)
    env_data=env_obj.encrypt_final()
    f_out.write(env_data)

print("encrypt ok")

