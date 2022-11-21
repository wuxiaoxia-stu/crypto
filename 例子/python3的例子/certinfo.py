# -*- coding: utf-8 -*-
from netcacrypto import Certificate,Hash,Interop
import sys

arg_count=len(sys.argv)

if arg_count!=2:
    print("Usage: python certinfo.py cert_file_name")
    sys.exit(-1)

file_name=sys.argv[1]

with open(file_name,"rb") as f:
    data=f.read()

with Certificate(data) as cert_obj:
    #基本信息
    sd=cert_obj.get_display_name()
    print("subject display name:\t"+sd)
    isd=cert_obj.get_issuer_display_name()
    print("issuer display name:\t"+isd)
    sn=cert_obj.get_serialnumber()
    print("serialNumber(HEX):\t"+sn)
    sn=cert_obj.get_dec_serialnumber()
    print("serialNumber(DEC):\t"+sn)
    b=cert_obj.get_publickey_bits()
    print("publickey bits:\t"+str(b))
    
    
    #issuer
    issuer=cert_obj.get_issuer()
    print("issuer:\t"+issuer)
    
    c=cert_obj.get_issuer_c()
    if not (c is None):
        print("issuer c:\t"+c)
    
    st=cert_obj.get_issuer_st()
    if not (st is None):
        print("issuer st:\t"+st)
    
    l=cert_obj.get_issuer_l()
    if not (l is None):
        print("issuer l:\t"+l)
    
    o=cert_obj.get_issuer_o()
    if not (o is None):
        print("issuer o:\t"+o)
    
    ous=cert_obj.get_all_issuer_ou()
    if not (ous is None):
        for ou in ous:
            print("issuer ou:\t"+ou)
    
    cns=cert_obj.get_all_issuer_cn()
    if not (cns is None):
        for cn in cns:
            print("issuer cn:\t"+cn)

    #有效期        
    notbefore=cert_obj.get_notbefore()
    print("notBefore:\t"+notbefore)
    notafter=cert_obj.get_notafter()
    print("notAfter:\t"+notafter)
    
    #subject
    subject=cert_obj.get_subject()
    print("subject:\t"+subject)
    
    c=cert_obj.get_c()
    if not (c is None):
        print("subject c:\t"+c)
    
    st=cert_obj.get_st()
    if not (st is None):
        print("subject st:\t"+st)
    
    l=cert_obj.get_l()
    if not (l is None):
        print("subject l:\t"+l)
    
    o=cert_obj.get_o()
    if not (o is None):
        print("subject o:\t"+o)
    
    ous=cert_obj.get_all_ou()
    if not (ous is None):
        for ou in ous:
            print("subject ou:\t"+ou)
    
    cns=cert_obj.get_all_cn()
    if not (cns is None):
        for cn in cns:
            print("subject cn:\t"+cn)
    
   # tbs="www.nn.com_sign.cer"
    #cert_obj.get_privatekey("12345678")
   # signature=cert_obj.sign( tbs.encode("utf8"))
   # print("signature :\t"+signature.hex())

    #密钥用法
    keyusage=cert_obj.get_keyusage()
    list=['digitalSignature','nonRepudiation','keyEncipherment','dataEncipherment','keyAgreement','keyCertSign','cRLSign','encipherOnly','decipherOnly']
    if not (keyusage is None):
        s = "keyusage:\t"
        for i in range(9):
            if keyusage[i]==True:
                s+=list[i]+" "
        print (s)
        
    #主题密钥标识符
    sid=cert_obj.get_subject_publickey_identifier()
    if not (sid is None):
        print("subject publickey identifier:\t"+sid)
    
    #缩略图
    algo=Hash.SHA256
    t=cert_obj.computeThumbprint(algo)
    print("Thumbprint:\t"+t.hex())
    
    #扩展
    oid="2.5.29.35"
    v=cert_obj.get_extension_value(oid)
    print(oid+":\t",end='')
    print(v)
    
    

            
            