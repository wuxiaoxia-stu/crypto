local CryptCore=require("CryptCore")

function toANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function usage(filename)
	print(toANSIString(string.format("Usage: lua %s attrId cert [hashAlgo]",filename)))
    print(toANSIString("参数"))
    print(toANSIString("\tattrId：属性的ID，可以是整数或者名称"))
    print(toANSIString("\tcert：证书文件名"))
    print(toANSIString("\thashAlgo：Hash算法"))
    print(toANSIString("说明"))
    print(toANSIString("\t获取证书的属性"))
	os.exit(-1)
end

function getCert(filename)
	fIn=io.open(filename,"rb")
	if fIn==nil then
		return nil
	end
	inData=fIn:read("*a")
	fIn:close()
	
	return CryptCore.NewCert(inData)
end

function getHashAlgo(hashAlgo)
    hashAlgo=hashAlgo:upper()
    if hashAlgo== "SHA-1" or hashAlgo=="SHA1" then
        return CryptCore.Const.SHA1
    elseif  hashAlgo== "SM3" then
        return CryptCore.Const.SM3
    elseif  hashAlgo== "MD5" then
        return CryptCore.Const.MD5
    elseif hashAlgo== "SHA-224" or hashAlgo=="SHA224" then
        return CryptCore.Const.SHA224
    elseif hashAlgo== "SHA-256" or hashAlgo=="SHA256" then
        return CryptCore.Const.SHA256
    elseif hashAlgo== "SHA-384" or hashAlgo=="SHA384" then
        return CryptCore.Const.SHA384
    elseif hashAlgo== "SHA-512" or hashAlgo=="SHA512" then
        return CryptCore.Const.SHA512
    elseif hashAlgo== "SHA-512/224" then
        return CryptCore.Const["SHA-512/224"]
    elseif hashAlgo== "SHA-512/256" then
        return CryptCore.Const["SHA-512/256"]
    elseif hashAlgo== "SHA3-224" then
        return CryptCore.Const["SHA3-224"]
    elseif hashAlgo== "SHA3-256" then
        return CryptCore.Const["SHA3-256"]
    elseif hashAlgo== "SHA3-384" then
        return CryptCore.Const["SHA3-384"]
    elseif hashAlgo== "SHA3-512" then
        return CryptCore.Const["SHA3-512"]
    else
        return nil;
    end
end

function getAttributeId(name)
    local upperName=name:upper()
    local t={
        ["VERSION"]=2,
        ["SIGNALGO"]=3,
        ["PUBKEYALGO"]=4,
        ["PUBKEYBITS"]=5,
        ["KEYUSAGE"]=6,
        ["HAS_PRIVKEY"]=7,
        ["HASPRIVKEY"]=7,
        ["ISSUER"]=8,
        ["ISSUER_DISPLAY_NAME"]=9,
        ["ISSUERDISPLAYNAME"]=9,
        ["ISSUER_C"]=10,
        ["ISSUERC"]=10,
        ["ISSUER_O"]=11,
        ["ISSUERO"]=11,
        ["ISSUER_OU"]=12,
        ["ISSUEROU"]=12,
        ["ISSUER_CN"]=13,
        ["ISSUERCN"]=13,
        ["ISSUER_EMAIL"]=14,
        ["ISSUEREMAIL"]=14,
        ["SUBJECT"]=15,
        ["SUBJECT_DISPLAY_NAME"]=16,
        ["SUBJECTDISPLAYNAME"]=16,
        ["SUBJECT_C"]=17,
        ["SUBJECTC"]=17,
        ["SUBJECT_O"]=18,
        ["SUBJECTO"]=18,
        ["SUBJECT_OU"]=19,
        ["SUBJECTOU"]=19,
        ["SUBJECT_CN"]=20,
        ["SUBJECTCN"]=20,
        ["SUBJECT_EMAIL"]=21,
        ["SUBJECTEMAIL"]=21,
        ["FRIENDLY_NAME"]=22,
        ["FRIENDLYNAME"]=22,
        ["NAME"]=23,
        ["ORGANIZATION"]=24,
        ["DEPARTMENT"]=25,
        ["EMAIL"]=26,
        ["GET_KEYPAIR_HADNLE_NEED_PWD"]=27,
        ["GETKEYPAIRHADNLENEEDPWD"]=27,
        ["PREVCERT_THUMBPRINT"]=29,
        ["PREVCERTTHUMBPRINT"]=29,
        ["VALIDITY_START"]=30,
        ["VALIDITYSTART"]=30,
        ["VALIDITY_END"]=31,
        ["VALIDITYEND"]=31,
        ["SN_DEC"]=32,
        ["SNDEC"]=32,
        ["SN_HEX"]=33,
        ["SNHEX"]=33,
        ["IN_VALIDITY"]=34,
        ["INVALIDITY"]=34,
        ["PRIVATE_ISCSP"]=35,
        ["PRIVATEISCSP"]=35,
        ["UPN"]=36,
        ["ISSUER_ST"]=37,
        ["ISSUERST"]=37,
        ["ISSUER_L"]=38,
        ["ISSUERL"]=38,
        ["SUBJECT_ST"]=39,
        ["SUBJECTST"]=39,
        ["SUBJECT_L"]=40,
        ["SUBJECTL"]=40,
        ["DEVICE_TYPE"]=41,
        ["DEVICETYPE"]=41,
        ["DEVICE_SN"]=42,
        ["DEVICESN"]=42,
        ["PUBKEY_ECC_CURVE"]=43,
        ["PUBKEYECCCURVE"]=43,
        ["THUMBPRINT"]=44,
        ["HASH_ISSUER"]=45,
        ["HASHISSUER"]=45,
        ["HASH_SUBJECT"]=46,
        ["HASHSUBJECT"]=46,
        ["HASH_PUBKEY"]=47,
        ["HASHPUBKEY"]=47,
        ["ISSUER_LDAP_NAME"]=48,
        ["ISSUERLDAPNAME"]=48,
        ["ISSUER_XMLSIG_NAME"]=49,
        ["ISSUERXMLSIGNAME"]=49,
        ["SUBJECT_LDAP_NAME"]=50,
        ["SUBJECTLDAPNAME"]=50,
        ["SUBJECT_XMLSIG_NAME"]=51,
        ["SUBJECTXMLSIGNAME"]=51,
        ["SUBJECT_HEX_ENCODE"]=52,
        ["SUBJECTHEXENCODE"]=52,
        ["ISSUER_HEX_ENCODE"]=53,
        ["ISSUERHEXENCODE"]=53,
        ["CHECK_PRIVKEY"]=54,
        ["CHECKPRIVKEY"]=54,
        ["CSP_NAME"]=55,
        ["CSPNAME"]=55,
        ["CRL_URL"]=56,
        ["CRLURL"]=56,
        ["DELTA_CRL_URL"]=57,
        ["DELTACRLURL"]=57,
        ["OCSP_URL"]=58,
        ["OCSPURL"]=58,
        ["IP"]=59,
        ["DNS_NAME"]=60,
        ["DNSNAME"]=60,
        ["CERT_POLICY_OID"]=61,
        ["CERTPOLICYOID"]=61,
        ["EXTENDED_KEY_USAGE"]=62,
        ["EXTENDEDKEYUSAGE"]=62,
        ["HASH_SUBJECT_PUBKEY_INFO"]=63,
        ["HASHSUBJECTPUBKEYINFO"]=63,
        ["SMIMECAPABILITIES"]=65,
        ["SUBJECT_KEYID"]=66,
        ["SUBJECTKEYID"]=66,
        ["ISSUER_DN_QUALIFIER"]=67,
        ["ISSUERDNQUALIFIER"]=67,
        ["SUBJECT_DN_QUALIFIER"]=68,
        ["SUBJECTDNQUALIFIER"]=68,
        ["ISSUER_SN"]=69,
        ["ISSUERSN"]=69,
        ["SUBJECT_SN"]=70,
        ["SUBJECTSN"]=70,
        ["ISSUER_TITLE"]=71,
        ["ISSUERTITLE"]=71,
        ["SUBJECT_TITLE"]=72,
        ["SUBJECTTITLE"]=72,
        ["ISSUER_SURNAME"]=73,
        ["ISSUERSURNAME"]=73,
        ["SUBJECT_SURNAME"]=74,
        ["SUBJECTSURNAME"]=74,
        ["ISSUER_GIVEN_NAME"]=75,
        ["ISSUERGIVENNAME"]=75,
        ["SUBJECT_GIVEN_NAME"]=76,
        ["SUBJECTGIVENNAME"]=76,
        ["ISSUER_INITIALS"]=77,
        ["ISSUERINITIALS"]=77,
        ["SUBJECT_INITIALS"]=78,
        ["SUBJECTINITIALS"]=78,
        ["ISSUER_PSEUDONYM"]=79,
        ["ISSUERPSEUDONYM"]=79,
        ["SUBJECT_PSEUDONYM"]=80,
        ["SUBJECTPSEUDONYM"]=80,
        ["ISSUER_GENERATION_QUALIFIER"]=81,
        ["ISSUERGENERATIONQUALIFIER"]=81,
        ["SUBJECT_GENERATION_QUALIFIER"]=82,
        ["SUBJECTGENERATIONQUALIFIER"]=82,
        ["ISSUER_DC"]=83,
        ["ISSUERDC"]=83,
        ["SUBJECT_DC"]=84,
        ["SUBJECTDC"]=84,
        ["ISSUER_UID"]=85,
        ["ISSUERUID"]=85,
        ["SUBJECT_UID"]=86,
        ["SUBJECTUID"]=86,
        ["ISSUER_STREET"]=87,
        ["ISSUERSTREET"]=87,
        ["SUBJECT_STREET"]=88,
        ["SUBJECTSTREET"]=88,
        ["CAISSUERS_URL"]=89,
        ["CAISSUERSURL"]=89,
        ["SUBJECT_JURISDICTION_L"]=90,
        ["SUBJECTJURISDICTIONL"]=90,
        ["SUBJECT_JURISDICTION_ST"]=91,
        ["SUBJECTJURISDICTIONST"]=91,
        ["SUBJECT_JURISDICTION_C"]=92,
        ["SUBJECTJURISDICTIONC"]=92,
        ["SUBJECT_BUSINESS_CATEGORY"]=93,
        ["SUBJECTBUSINESSCATEGORY"]=93,
        ["GB_IDENTITY_CODE"]=94,
        ["GBIDENTITYCODE"]=94,
        ["CRICAL_EXTENSIONS"]=95,
        ["CRICALEXTENSIONS"]=95,
        ["ISSUER_AND_SERIALNUMBER"]=96,
        ["ISSUERANDSERIALNUMBER"]=96,
        ["ISSUER_REVERSE"]=97,
        ["ISSUERREVERSE"]=97,
        ["SUBJECT_REVERSE"]=98,
        ["SUBJECTREVERSE"]=98,
        ["CERT_CLASS"]=99,
        ["CERTCLASS"]=99,
        ["CERT_CLASS_EXT_VALUE"]=100,
        ["CERTCLASSEXTVALUE"]=100,
        ["SHENZHEN_SUBJECT_UNIQUE_ID"]=101,
        ["SHENZHENSUBJECTUNIQUEID"]=101,
        ["NETCA_SUBJECT_UNIQUE_ID"]=102,
        ["NETCASUBJECTUNIQUEID"]=102,
        ["KEYPAIR_INFO_STRING"]=103,
        ["KEYPAIRINFOSTRING"]=103,
    }
    local id=t[upperName]
    if id==nil then
        local status,idValue=pcall(tonumber,name)
        if not status then
            return nil
        end
        return idValue
    else
        return id
    end
end

if #arg~=2 and #arg~=3 then
	usage(arg[0])
    os.exit(-1)
end


local attrId=getAttributeId(arg[1])
if attrId==nil then
    print(toANSIString("未知的属性Id"));
    os.exit(-1)
end
local cert=getCert(arg[2])
if cert==nil then
    print(toANSIString("读证书文件失败"));
    os.exit(-1)
end

local attrValue
local errCode
if #arg==2 then
    attrValue=cert:GetAttribute(attrId)
    errCode=CryptCore.GetLastError()
else
    local hashAlgo=getHashAlgo(arg[3])
    if hashAlgo==nil then
        print(toANSIString("未知的Hash算法"));
        os.exit(1)
    end
    attrValue=cert:GetAttribute(attrId,hashAlgo)
    errCode=CryptCore.GetLastError()
    if attrValue~=nil then
        attrValue=CryptCore.HexEncode(attrValue)
    end
end
cert:Free()

if attrValue==nil then
    if errCode==-7 then
        print(toANSIString("属性不存在"));
    else
        print(toANSIString("获取属性出错"));
    end
    os.exit(1)
end

if type(attrValue)=="number"  then
    print(attrValue)
elseif type(attrValue)=="string" then
    print(CryptCore.UTF8ToACP(attrValue))
else
    local count=#attrValue
    print(toANSIString(string.format("多值属性：共%d个属性",count)));
    for i=1,count do
        print(attrValue[i])
    end
end




