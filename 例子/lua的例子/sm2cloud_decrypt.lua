local CryptCore=require("CryptCore")

local n=assert(CryptCore.NewBigInteger(true,"FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFF7203DF6B21C6052B53BBF40939D54123"))
local p=assert(CryptCore.NewBigInteger(true,"FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFF"))
local Gx=assert(CryptCore.NewBigInteger(true,"32C4AE2C1F1981195F9904466A39C9948FE30BBFF2660BE1715A4589334C74C7"))
local Gy=assert(CryptCore.NewBigInteger(true,"BC3736A2F4F6779C59BDCEE36B692153D0A9877CC62A474002DF32E52139F0A0"))

local G=assert(CryptCore.NewPoint("SM2",Gx,Gy))

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s [-verbose] url publicKeyFileName cipherFileName clearFileName",filename))
    print(ToANSIString("参数"))
    print(ToANSIString("\t-verbose：输出中间过程"))
    print(ToANSIString("\turl：服务器的URL"))
    print(ToANSIString("\tpublicKeyFileName：公钥文件名"))
    print(ToANSIString("\tcipherFileName：密文文件名，格式为C1||C2||C3"))
    print(ToANSIString("\tclearFileName：保存的明文文件名"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t基于云计算的SM2解密"))
end

function GetFileConetent(fileName)
    local fIn=io.open(fileName,"rb")
    if fIn==nil then
        return nil
    end
    local data=fIn:read("*a")
    fIn:close()
    
    return data
end

function Save(fileName,data)
    local fOut=io.open(fileName,"wb")
    if fOut==nil then
        return false
    end
    fOut:write(data)
    fOut:close()    
    return true
end

if #arg~=4 and #arg~=5 then
    Usage(arg[0])
    os.exit(-1)
end

local pos=1
local verbose=false
if #arg==5 then
    if arg[pos]=="-verbose" or arg[pos]=="/verbose" then
        pos=pos+1
        verbose=true
    else
        Usage(arg[0])
        os.exit(-1)
    end
end
--local url="http://127.0.0.1:8080/test/SM2Server"
local url=arg[pos]
pos=pos+1
local publicKeyFileName=arg[pos]
pos=pos+1
local cipherFileName=arg[pos]
pos=pos+1
local clearFileName=arg[pos]
pos=pos+1

local data=GetFileConetent(publicKeyFileName)
if data==nil then
    print(ToANSIString("读公钥文件失败"));
    os.exit(-1)
end
local jsonObj=CryptCore.Json.Decode(data)
if jsonObj==nil then
    print(ToANSIString("公钥文件格式错误"));
    os.exit(-1)
end
local id=jsonObj["id"]
local d1=jsonObj["d1"]
if verbose then
    print("id:"..id)
    print("d1:"..d1)
end

data=GetFileConetent(cipherFileName)
if data==nil then
    print(ToANSIString("读密文文件失败"));
    os.exit(-1)
end
if #data<=97 then
    print(ToANSIString("密文文件太短"));
    os.exit(-1)
end

local cipher=CryptCore.HexEncode(data)
if verbose then
    print(ToANSIString("密文:"..cipher))
end

local str=cipher:sub(1,2)
if str~="04" then
    print("密文错误")
    os.exit(-1)
end

local x=assert(CryptCore.NewBigInteger(true,cipher:sub(3,66)))
local y=assert(CryptCore.NewBigInteger(true,cipher:sub(67,130)))
local C1=assert(CryptCore.NewPoint("SM2",x,y))

d1=assert(CryptCore.NewBigInteger(true,d1))

local d1Inv=d1:InvMod(n)
if verbose then
    print("d1Inv:"..d1Inv:Encode(32))
end

local T1=assert(C1:Mul(d1Inv))
x=T1:GetX()
y=T1:GetY()
if verbose then
    print(ToANSIString("T1的x坐标:"..x:Encode(32)))
    print(ToANSIString("T1的y坐标:"..y:Encode(32)))
end

local t={["function"]="Decrypt",
        ["arguement"]={
            ["T1"]={
                ["x"]=x:Encode(32),
                ["y"]=y:Encode(32),
            },
            ["id"]=id
        }}
local jsonData=CryptCore.Json.Encode(t)
if verbose then
    print(ToANSIString(string.format("向服务器(%s)发送请求:\n%s",url,jsonData)))
end

local status,contentType,outData=CryptCore.HttpPost(url,jsonData,{})
if status==nil then
    print(ToANSIString("向服务器发送解密请求失败"))
    return nil
end
if status<200 or status>=300 then
    print(ToANSIString(string.format("向服务器发送解密请求失败,服务器返回响应码:%s",status)))
    os.exit(-1)
end
if verbose then
    print(ToANSIString(string.format("服务器返回的状态码:%d",status)))
    print(ToANSIString(string.format("服务器返回的响应:%s",outData)))
end

local jsonObj=CryptCore.Json.Decode(outData)
local T2=jsonObj["return"]["T2"]
x=T2.x
y=T2.y
if verbose then
    print(ToANSIString("T2的x坐标:"..x))
    print(ToANSIString("T2的y坐标:"..y))
end

x=assert(CryptCore.NewBigInteger(true,x))
y=assert(CryptCore.NewBigInteger(true,y))

local negC1=-C1
local T2=assert(CryptCore.NewPoint("SM2",x,y))
local tempP=T2+negC1
x=tempP:GetX()
y=tempP:GetY()
if verbose then
    print(ToANSIString("T2-C1的x坐标:"..x:Encode(32)))
    print(ToANSIString("T2-C1的y坐标:"..y:Encode(32)))
end


local x_y=CryptCore.HexDecode(x:Encode(32)..y:Encode(32))
local len=#cipher
str=cipher:sub(131,len-64)
local C2=assert(CryptCore.HexDecode(str))
t=assert(CryptCore.KDF { ["algo"]=5,
		data=x_y,["length"]=#C2,["hashalgo"]=CryptCore.Const.SM3})
if verbose then
    print(ToANSIString("KDF(x2||y2):"..CryptCore.HexEncode(t)))
end

local M=CryptCore.Xor(t,C2)
if verbose then
    print(ToANSIString("C2 XOR KDF(x2||y2):"..CryptCore.HexEncode(M)))
end


local hashObj=assert(CryptCore.NewHash(CryptCore.Const.SM3))
hashObj:Update(CryptCore.HexDecode(x:Encode(32)))
hashObj:Update(M)
hashObj:Update(CryptCore.HexDecode(y:Encode(32)))
local hashValue=hashObj:Final()
if verbose then
    print(ToANSIString("SM3(x2||M||y2):"..CryptCore.HexEncode(hashValue)))
end

str=CryptCore.HexDecode(cipher:sub(len-63))
if hashValue~=str then
    print(ToANSIString("解密失败"))
    os.exit(-1)
end

if Save(clearFileName,M)==false then
    print(ToANSIString("保存明文文件失败"))
    os.exit(-1)
end

print(ToANSIString("解密成功"))


