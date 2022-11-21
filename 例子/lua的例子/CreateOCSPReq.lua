local CryptCore=require("CryptCore")

function usage(filename)
	print(string.format("Usage: lua %s SHA-1|SM3 issuerCertFileName certFileName ocspReqName",filename))
	
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

function getCert(certFileName)
	local f=assert(io.open(certFileName,"rb"))
	local data=f:read("*a")
	f:close()
	return assert(CryptCore.NewCert(data))
end

local argCount=#arg
local hashAlgo

if argCount~=4 then
	usage(arg[0])
	os.exit(-1)
end

hashAlgo=getHashAlgo(arg[1])
if hashAlgo==nil then
    print("unknwon hash algo")
    os.exit(-1)
end

local issuerCert=getCert(arg[2])
local cert=getCert(arg[3])

local reqFileName=arg[4]

local ocspCertId=assert(CryptCore.NewOCSPCertID(hashAlgo,issuerCert,cert))
issuerCert:Free()
cert:Free()

local ocspReq=assert(CryptCore.NewOCSPReq())
ocspReq:AddCert(ocspCertId)
ocspCertId:Free()

ocspReq:SetNonce()

local data=ocspReq:Encode()
ocspReq:Free()

local fOut=assert(io.open(reqFileName,"wb"))
fOut:write(data)
fOut:close()

print("Success")
