local CryptCore=require("CryptCore")

function ToANSIString(utf8String)
    return CryptCore.UTF8ToACP(utf8String)
end

function Usage(filename)
    print(string.format("Usage: lua %s cert",filename))
end

function GetCert(filename)
    local fIn=io.open(filename,"rb")
    if fIn==nil then
        return nil
    end
    local inData=fIn:read("*a")
    fIn:close()
    
    return CryptCore.NewCert(inData)
end

--CryptCore.SetAllowCertType("ECC")
---[[
local cert=CryptCore.SelectCert("Signature")
if cert==nil then
    print(ToANSIString("选择证书失败"));
    os.exit(-1)
end

cert:Display()
cert:Free()
--]]
