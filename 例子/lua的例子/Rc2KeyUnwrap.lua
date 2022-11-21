local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(scriptName)
    print(string.format("lua %s keywrap kek effectiveBits [hmac]",scriptName))
    print(ToANSIString("参数"))
    print(ToANSIString("\tkeywrap：Hex编码的keywrap"))
    print(ToANSIString("\tkek：Hex编码的kek"))
    print(ToANSIString("\teffectiveBits：有效密钥位数"))
    print(ToANSIString("\thmac：表示HMAC的Key"))
    print(ToANSIString("说明"))
    print(ToANSIString("\t进行RC2 的KeyWrap"))
end

local argCount=#arg
if argCount~=3 and argCount~=4 then
    Usage(arg[0])
    os.exit(-1)
end

local keywrap=CryptCore.HexDecode(arg[1])
if keywrap==nil then
    print(ToANSIString("keywrap不是Hex编码的"));
    os.exit(-1)
end

local cek=CryptCore.HexDecode(arg[1])
if cek==nil then
    print(ToANSIString("cek不是Hex编码的"));
    os.exit(-1)
end

local kek=CryptCore.HexDecode(arg[2])
if not kek then
    print(ToANSIString("kek不是Hex编码的"));
    os.exit(-1)
end

local effectiveBits=tonumber(arg[3])
if effectiveBits<=0 then
    Usage(arg[0]);
    os.exit(-1)
end

local isHmackey=false
if argCount==4 then
    if arg[4]=="hmac" then
        isHmackey=true
    else
        Usage(arg[0]);
        os.exit(-1)
    end
end

local algo=CryptCore.Const.RC2_ECB
local cek=CryptCore.KeyUnwrap{
    ["algo"]=algo,
    ["ishmackey"]=isHmackey,
    ["kek"]=kek,
    ["keywrap"]=keywrap,
    ["effectivebits"]=effectiveBits
}

if cek==nil then
    print(ToANSIString("RC2 Key Unwarp失败"));
    os.exit(-1)
end
print(CryptCore.HexEncode(cek))