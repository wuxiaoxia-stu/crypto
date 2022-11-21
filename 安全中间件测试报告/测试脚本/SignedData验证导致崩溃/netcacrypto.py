# -*- coding: utf-8 -*-
import platform
from ctypes import *

class NetcaCryptoErrorCode:
    #成功
    SUCCESS=1
    #失败
    FAIL=0
    #不存在
    NOTEXISIT=-7
    #验证SignedData签名，有的成功，有的失败
    VERIFY_SIGNEDDATA_PARTLY_SUCCESS=-32

class NetcaCryptoException(Exception):
    '''
    NetcaCryptoException是netcacrypto所有相关的类和方法出错抛出的异常
    '''
    def __init__(self,msg,error_code=NetcaCryptoErrorCode.FAIL):
        Exception.__init__(self,NetcaCryptoException._str(msg,error_code))
        self.msg=msg
        self.error_code=error_code
        
    @staticmethod
    def _str(msg,error_code):
        if error_code==NetcaCryptoErrorCode.FAIL :
            return msg
        else :
            return "%s,error code:%d" % (msg,error_code)




class Interop:

    @staticmethod
    def _load_dll():
        dll=None
        sys_str=platform.system()
        if sys_str=="Windows" :
            dll=windll.LoadLibrary("NETCA_CRYPTO.dll")
        elif sys_str=="Linux" :
            dll=cdll.LoadLibrary("libnetca_crypto.so")
        elif sys_str=="Darwin" :
            pass
        else:
            pass

        if dll==None :
            raise NetcaCryptoException("Load NETCA_CRYPTO Fail")

        return dll

    def _init_util_fuction(self):
        self._handle.NetcaPKICryptoAllocMemory.restype = c_void_p
        self._handle.NetcaPKICryptoAllocMemory.argtypes=[c_long]
        
        self._handle.NetcaPKICryptoFreeMemory.argtypes=[c_void_p]
        
        self._handle.NetcaPKICryptoFreeKeypair.restype = c_int
        self._handle.NetcaPKICryptoFreeKeypair.argtypes=[c_void_p]
        
        self._handle.NetcaPKIAppGetVersionInfo.restype = c_void_p
        self._handle.NetcaPKIAppGetVersionInfo.argtypes=[]
        
        self._handle.NetcaPKIGetLastError.restype = c_int
        self._handle.NetcaPKIGetLastError.argtypes=[]
        
        self._handle.NetcaPKIGetErrorMsg.restype = c_void_p
        self._handle.NetcaPKIGetErrorMsg.argtypes=[c_int]
        
        self._handle.NetcaPKIConfigReset.restype = c_int
        self._handle.NetcaPKIConfigReset.argtypes=[]

        self._handle.NetcaPKICryptoGenerateRandom.restype=c_int
        self._handle.NetcaPKICryptoGenerateRandom.argtypes=[c_void_p,c_int,c_void_p]
        
        self._handle.NetcaPKIConfigSetConfig.restype = c_int
        self._handle.NetcaPKIConfigSetConfig.argtypes=[c_char_p]
        
        self._handle.NetcaPKIConfigGetConfig.restype = c_void_p
        self._handle.NetcaPKIConfigGetConfig.argtypes=[]


    def _init_hash_fuction(self):
        self._handle.NetcaPKICryptoGetHashHandle.restype = c_void_p
        self._handle.NetcaPKICryptoGetHashHandle.argtypes=[c_int]

        self._handle.NetcaPKICryptoHashUpdate.restype = c_int
        self._handle.NetcaPKICryptoHashUpdate.argtypes=[c_void_p,POINTER(c_char),c_int]

        self._handle.NetcaPKICryptoHashFinal.restype = c_int
        self._handle.NetcaPKICryptoHashFinal.argtypes=[c_void_p,POINTER(c_void_p),POINTER(c_int)]

        self._handle.NetcaPKICryptoFreeHash.restype = c_int
        self._handle.NetcaPKICryptoFreeHash.argtypes=[c_void_p]

    def _init_cert_fuction(self):
        self._handle.NetcaPKICertNewCert.restype = c_void_p
        self._handle.NetcaPKICertNewCert.argtypes=[POINTER(c_char),c_int]

        self._handle.NetcaPKICertFreeCert.restype = c_int
        self._handle.NetcaPKICertFreeCert.argtypes=[c_void_p]

        self._handle.NetcaPKICertGetCertEncode.restype = c_int
        self._handle.NetcaPKICertGetCertEncode.argtypes=[c_void_p,c_int,POINTER(c_void_p),POINTER(c_int)]

        self._handle.NetcaPKICertEqual.restype = c_int
        self._handle.NetcaPKICertEqual.argtypes=[c_void_p,c_void_p]

        self._handle.NetcaPKICertMatch.restype = c_int
        self._handle.NetcaPKICertMatch.argtypes=[c_void_p,c_char_p]

        self._handle.NetcaPKISelectCert.restype = c_int
        self._handle.NetcaPKISelectCert.argtypes=[c_char_p,c_char_p,POINTER(c_void_p)]

        self._handle.NetcaPKICertGetCertIntegerAttribute.restype = c_int
        self._handle.NetcaPKICertGetCertIntegerAttribute.argtypes=[c_void_p,c_int,POINTER(c_long)]

        self._handle.NetcaPKICertGetCertStringAttribute.restype = c_int
        self._handle.NetcaPKICertGetCertStringAttribute.argtypes=[c_void_p,c_int,POINTER(c_void_p)]

        self._handle.NetcaPKICertGetAttributeType.restype = c_int
        self._handle.NetcaPKICertGetAttributeType.argtypes=[c_int]

        self._handle.NetcaPKICertGetCertHashAttribute.restype = c_int
        self._handle.NetcaPKICertGetCertHashAttribute.argtypes=[c_void_p,c_int,c_int,POINTER(c_void_p),POINTER(c_int)]

        self._handle.NetcaPKIAppGetUserCert.restype = c_void_p
        self._handle.NetcaPKIAppGetUserCert.argtypes=[c_int,c_char_p]

        self._handle.NetcaPKIAppCertGetKeypair.restype = c_int
        self._handle.NetcaPKIAppCertGetKeypair.argtypes=[c_void_p,c_char_p,POINTER(c_void_p)]

        self._handle.NetcaPKIAppCertGetStringExtension.restype = c_void_p
        self._handle.NetcaPKIAppCertGetStringExtension.argtypes=[c_void_p,c_char_p]
        
        self._handle.NetcaPKICertFindExtension.restype = c_int
        self._handle.NetcaPKICertFindExtension.argtypes=[c_void_p,c_char_p,POINTER(c_int),POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIAppCertEncrypt.restype = c_int
        self._handle.NetcaPKIAppCertEncrypt.argtypes=[c_void_p,POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIAppCertDecrypt.restype = c_int
        self._handle.NetcaPKIAppCertDecrypt.argtypes=[c_void_p,POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIAppSign.restype = c_int
        self._handle.NetcaPKIAppSign.argtypes=[c_void_p,POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIAppVerify.restype = c_int
        self._handle.NetcaPKIAppVerify.argtypes=[c_void_p,POINTER(c_char),c_int,POINTER(c_char),c_int]
        
        self._handle.NetcaPKIConfigSetSelectCertPolicy.restype = c_int
        self._handle.NetcaPKIConfigSetSelectCertPolicy.argtypes=[c_char_p]
        
        self._handle.NetcaPKIConfigGetSelectCertPolicy.restype = c_void_p
        self._handle.NetcaPKIConfigGetSelectCertPolicy.argtypes=[]
        
        self._handle.NetcaPKIConfigSetFilterCertCondition.restype = c_int
        self._handle.NetcaPKIConfigSetFilterCertCondition.argtypes=[c_char_p]
		
        self._handle.NetcaPKIConfigGetFilterCertCondition.restype = c_void_p
        self._handle.NetcaPKIConfigGetFilterCertCondition.argtypes=[]
        
        self._handle.NetcaPKIConfigSetSignAlgo.restype = c_int
        self._handle.NetcaPKIConfigSetSignAlgo.argtypes=[c_char_p,c_int]
        
        self._handle.NetcaPKIConfigSetPublicKeyEncryptAlgo.restype = c_int
        self._handle.NetcaPKIConfigSetPublicKeyEncryptAlgo.argtypes=[c_char_p,c_int]
        
        self._handle.NetcaPKICertGetCertPath.restype = c_int
        self._handle.NetcaPKICertGetCertPath.argtypes=[c_void_p,POINTER(c_void_p),POINTER(c_int)]

        self._handle.NetcaPKICertVerifyCert.restype = c_int
        self._handle.NetcaPKICertVerifyCert.argtypes=[c_void_p,c_char_p,c_int,POINTER(c_int),POINTER(c_void_p)]
        
        self._handle.NetcaPKICertGetRevokedCertRevokedTime.restype = c_void_p
        self._handle.NetcaPKICertGetRevokedCertRevokedTime.argtypes=[c_void_p]

        self._handle.NetcaPKICertGetRevokedCertRevokedReason.restype = c_int
        self._handle.NetcaPKICertGetRevokedCertRevokedReason.argtypes=[c_void_p]

        self._handle.NetcaPKICertFreeRevokedCert.restype = c_int
        self._handle.NetcaPKICertFreeRevokedCert.argtypes=[c_void_p]

        self._handle.NetcaPKICertOCSPVerifyCert.restype = c_int
        self._handle.NetcaPKICertOCSPVerifyCert.argtypes=[c_void_p,c_char_p,c_void_p,POINTER(c_int),POINTER(c_void_p)]

    def _init_envelopeddata_fuction(self):
        self._handle.NetcaPKIMsgNewEnvelopedData.restype = c_void_p
        self._handle.NetcaPKIMsgNewEnvelopedData.argtypes=[c_int]
        
        self._handle.NetcaPKIMsgFreeEnvelopedData.restype = c_int
        self._handle.NetcaPKIMsgFreeEnvelopedData.argtypes=[c_void_p]
        
        self._handle.NetcaPKIMsgEnvelopedDataSetEncAlgorithm.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataSetEncAlgorithm.argtypes=[c_void_p,c_int]
        
        self._handle.NetcaPKIMsgEnvelopedDataAddCert.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataAddCert.argtypes=[c_void_p,c_void_p,c_int]
        
        self._handle.NetcaPKIMsgEnvelopedDataSetIntegerAttribute.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataSetIntegerAttribute.argtypes=[c_void_p,c_int,c_int]
        
        self._handle.NetcaPKIMsgEnvelopedDataSetStringAttribute.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataSetStringAttribute.argtypes=[c_void_p,c_int,c_char_p]
        
        self._handle.NetcaPKIMsgEnvelopedDataEncryptInit.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataEncryptInit.argtypes=[c_void_p,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgEnvelopedDataEncryptUpdate.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataEncryptUpdate.argtypes=[c_void_p,POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgEnvelopedDataEncryptFinal.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataEncryptFinal.argtypes=[c_void_p,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgEnvelopedDataEncrypt.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataEncrypt.argtypes=[c_void_p,POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgEnvelopedDataAddStore.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataAddStore.argtypes=[c_void_p,c_void_p]
        
        self._handle.NetcaPKIMsgEnvelopedDataDecrypt.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataDecrypt.argtypes=[c_void_p,POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgEnvelopedDataDecryptInit.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataDecryptInit.argtypes=[c_void_p]
        
        self._handle.NetcaPKIMsgEnvelopedDataDecryptUpdate.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataDecryptUpdate.argtypes=[c_void_p,POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgEnvelopedDataDecryptFinal.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataDecryptFinal.argtypes=[c_void_p]
        
        self._handle.NetcaPKIMsgEnvelopedDataSetKey.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataSetKey.argtypes=[c_void_p,POINTER(c_char),c_int]
        
        self._handle.NetcaPKIMsgEnvelopedDataGetEncAlgorithm.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataGetEncAlgorithm.argtypes=[c_void_p]
        
        self._handle.NetcaPKIMsgEnvelopedDataGetCert.restype = c_void_p
        self._handle.NetcaPKIMsgEnvelopedDataGetCert.argtypes=[c_void_p]

        self._handle.NetcaPKIMsgEnvelopedDataGetRecipientInfosEncode.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataGetRecipientInfosEncode.argtypes=[c_void_p,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgEnvelopedDataIsContentInfo.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataIsContentInfo.argtypes=[c_void_p]
        
        self._handle.NetcaPKIMsgEnvelopedDataMaybe.restype = c_int
        self._handle.NetcaPKIMsgEnvelopedDataMaybe.argtypes=[POINTER(c_char),c_int]
        
        self._handle.NetcaPKIAppEnvelopedDataEncrypt.restype = c_int
        self._handle.NetcaPKIAppEnvelopedDataEncrypt.argtypes=[c_void_p,POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int),POINTER(c_void_p)]
        
        self._handle.NetcaPKIAppNewEnvelopedDataEncryptHandle.restype = c_void_p
        self._handle.NetcaPKIAppNewEnvelopedDataEncryptHandle.argtypes=[]
        
        self._handle.NetcaPKIConfigEnvelopedDataSetDecryptCert.restype = c_int
        self._handle.NetcaPKIConfigEnvelopedDataSetDecryptCert.argtypes=[c_void_p]
        
        self._handle.NetcaPKIAppEnvelopedDataDecrypt.restype = c_int
        self._handle.NetcaPKIAppEnvelopedDataDecrypt.argtypes=[POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int),POINTER(c_void_p)]
        
        self._handle.NetcaPKIAppNewEnvelopedDataDecryptHandle.restype = c_void_p
        self._handle.NetcaPKIAppNewEnvelopedDataDecryptHandle.argtypes=[]
        
        self._handle.NetcaPKIAppEnvelopedDataDecryptPostCheck.restype = c_int
        self._handle.NetcaPKIAppEnvelopedDataDecryptPostCheck.argtypes=[c_void_p]
        
        self._handle.NetcaPKIConfigEnvelopedDataSetEncryptAlgo.restype = c_int
        self._handle.NetcaPKIConfigEnvelopedDataSetEncryptAlgo.argtypes=[c_int]
        
        self._handle.NetcaPKIConfigEnvelopedDataGetEncryptAlgo.restype = c_int
        self._handle.NetcaPKIConfigEnvelopedDataGetEncryptAlgo.argtypes=[]
        
        self._handle.NetcaPKIConfigEnvelopedDataIsUseSubjectKeyIdentifier.restype = c_int
        self._handle.NetcaPKIConfigEnvelopedDataIsUseSubjectKeyIdentifier.argtypes=[]
        
        self._handle.NetcaPKIConfigEnvelopedDataSetUseSubjectKeyIdentifier.restype = c_int
        self._handle.NetcaPKIConfigEnvelopedDataSetUseSubjectKeyIdentifier.argtypes=[c_int]

    def _init_signeddata_fuction(self):
        self._handle.NetcaPKIMsgNewSignedData.restype = c_void_p
        self._handle.NetcaPKIMsgNewSignedData.argtypes=[c_int]
        
        self._handle.NetcaPKIMsgFreeSignedData.restype = c_int
        self._handle.NetcaPKIMsgFreeSignedData.argtypes=[c_void_p]
        
        self._handle.NetcaPKIMsgSignedDataSetIntegerAttribute.restype = c_int
        self._handle.NetcaPKIMsgSignedDataSetIntegerAttribute.argtypes=[c_void_p,c_int,c_int,c_int]
        
        self._handle.NetcaPKIMsgSignedDataSetStringAttribute.restype = c_int
        self._handle.NetcaPKIMsgSignedDataSetStringAttribute.argtypes=[c_void_p,c_int,c_int,c_char_p]
        
        self._handle.NetcaPKIMsgSignedDataSetSignCert.restype = c_int
        self._handle.NetcaPKIMsgSignedDataSetSignCert.argtypes=[c_void_p,c_void_p,c_char_p]
        
        self._handle.NetcaPKIMsgSignedDataSetEncCert.restype = c_int
        self._handle.NetcaPKIMsgSignedDataSetEncCert.argtypes=[c_void_p,c_int,c_int,c_void_p]
        
        self._handle.NetcaPKIMsgSignedDataAddCert.restype = c_int
        self._handle.NetcaPKIMsgSignedDataAddCert.argtypes=[c_void_p,c_void_p]
        
        self._handle.NetcaPKIMsgSignedDataAddCRL.restype = c_int
        self._handle.NetcaPKIMsgSignedDataAddCRL.argtypes=[c_void_p,POINTER(c_char),c_int]
        
        self._handle.NetcaPKIMsgSignedDataAddOCSP.restype = c_int
        self._handle.NetcaPKIMsgSignedDataAddOCSP.argtypes=[c_void_p,c_int,c_void_p,POINTER(c_char),c_int]
        
        self._handle.NetcaPKIMsgSignedDataAddSignedAttribute.restype = c_int
        self._handle.NetcaPKIMsgSignedDataAddSignedAttribute.argtypes=[c_void_p,c_int,c_char_p,POINTER(c_char),c_int]
        
        self._handle.NetcaPKIMsgSignedDataAddUnsignedAttribute.restype = c_int
        self._handle.NetcaPKIMsgSignedDataAddUnsignedAttribute.argtypes=[c_void_p,c_int,c_char_p,POINTER(c_char),c_int]
        
        self._handle.NetcaPKIMsgSignedDataDeleteUnsignedAttribute.restype = c_int
        self._handle.NetcaPKIMsgSignedDataDeleteUnsignedAttribute.argtypes=[c_void_p,c_int,c_char_p]
        
        self._handle.NetcaPKIMsgSignedDataEncode.restype = c_int
        self._handle.NetcaPKIMsgSignedDataEncode.argtypes=[c_void_p,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgSignedDataSign.restype = c_int
        self._handle.NetcaPKIMsgSignedDataSign.argtypes=[c_void_p,POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgSignedDataCountersign.restype = c_int
        self._handle.NetcaPKIMsgSignedDataCountersign.argtypes=[c_void_p,c_int,c_int,c_void_p,c_char_p,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgSignedDataSignWithTimeStamp.restype = c_int
        self._handle.NetcaPKIMsgSignedDataSignWithTimeStamp.argtypes=[c_void_p,c_char_p,POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgSignedDataAttachSignatureTimeStamp.restype = c_int
        self._handle.NetcaPKIMsgSignedDataAttachSignatureTimeStamp.argtypes=[c_void_p,c_int,c_int,c_char_p]
        
        self._handle.NetcaPKIMsgSignedDataSignInit.restype = c_int
        self._handle.NetcaPKIMsgSignedDataSignInit.argtypes=[c_void_p,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgSignedDataSignUpdate.restype = c_int
        self._handle.NetcaPKIMsgSignedDataSignUpdate.argtypes=[c_void_p,POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgSignedDataSignFinal.restype = c_int
        self._handle.NetcaPKIMsgSignedDataSignFinal.argtypes=[c_void_p,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgSignedDataSignWithTimeStampFinal.restype = c_int
        self._handle.NetcaPKIMsgSignedDataSignWithTimeStampFinal.argtypes=[c_void_p,c_char_p,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgSignedDataGetCertificates.restype = c_int
        self._handle.NetcaPKIMsgSignedDataGetCertificates.argtypes=[c_void_p,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgSignedDataAddRootCert.restype = c_int
        self._handle.NetcaPKIMsgSignedDataAddRootCert.argtypes=[c_void_p,c_void_p]
        
        self._handle.NetcaPKIMsgSignedDataVerify.restype = c_int
        self._handle.NetcaPKIMsgSignedDataVerify.argtypes=[c_void_p,POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgSignedDataVerifyTimeStamp.restype = c_int
        self._handle.NetcaPKIMsgSignedDataVerifyTimeStamp.argtypes=[c_void_p,c_int,c_void_p]
        
        self._handle.NetcaPKIMsgSignedDataVerifyCountersignature.restype = c_int
        self._handle.NetcaPKIMsgSignedDataVerifyCountersignature.argtypes=[c_void_p,c_int,c_int,c_void_p]
        
        self._handle.NetcaPKIMsgSignedDataVerifyInit.restype = c_int
        self._handle.NetcaPKIMsgSignedDataVerifyInit.argtypes=[c_void_p]
        
        self._handle.NetcaPKIMsgSignedDataVerifyUpdate.restype = c_int
        self._handle.NetcaPKIMsgSignedDataVerifyUpdate.argtypes=[c_void_p,POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgSignedDataVerifyFinal.restype = c_int
        self._handle.NetcaPKIMsgSignedDataVerifyFinal.argtypes=[c_void_p]
        
        self._handle.NetcaPKIMsgSignedDataDetachedVerifyInit.restype = c_int
        self._handle.NetcaPKIMsgSignedDataDetachedVerifyInit.argtypes=[c_void_p,POINTER(c_char),c_int]
        
        self._handle.NetcaPKIMsgSignedDataDetachedVerifyUpdate.restype = c_int
        self._handle.NetcaPKIMsgSignedDataDetachedVerifyUpdate.argtypes=[c_void_p,POINTER(c_char),c_int]
        
        self._handle.NetcaPKIMsgSignedDataDetachedVerifyFinal.restype = c_int
        self._handle.NetcaPKIMsgSignedDataDetachedVerifyFinal.argtypes=[c_void_p]
        
        self._handle.NetcaPKIMsgSignedDataDetachedVerifyHash.restype = c_int
        self._handle.NetcaPKIMsgSignedDataDetachedVerifyHash.argtypes=[c_void_p,c_int,POINTER(c_char),c_int]
        
        self._handle.NetcaPKIMsgSignedDataDetachedVerify.restype = c_int
        self._handle.NetcaPKIMsgSignedDataDetachedVerify.argtypes=[c_void_p,POINTER(c_char),c_int,POINTER(c_char),c_int]
        
        self._handle.NetcaPKIMsgSignedDataGetIntegerAttribute.restype = c_int
        self._handle.NetcaPKIMsgSignedDataGetIntegerAttribute.argtypes=[c_void_p,c_int,c_int,POINTER(c_int)]
        
        self._handle.NetcaPKIMsgSignedDataGetStringAttribute.restype = c_int
        self._handle.NetcaPKIMsgSignedDataGetStringAttribute.argtypes=[c_void_p,c_int,c_int,POINTER(c_void_p)]
        
        self._handle.NetcaPKIMsgSignedDataGetSignedAttribute.restype = c_int
        self._handle.NetcaPKIMsgSignedDataGetSignedAttribute.argtypes=[c_void_p,c_int,c_int,POINTER(c_void_p),POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgSignedDataGetUnsignedAttribute.restype = c_int
        self._handle.NetcaPKIMsgSignedDataGetUnsignedAttribute.argtypes=[c_void_p,c_int,c_int,POINTER(c_void_p),POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgSignedDataGetSignCert.restype = c_void_p
        self._handle.NetcaPKIMsgSignedDataGetSignCert.argtypes=[c_void_p,c_int]
        
        self._handle.NetcaPKIMsgSignedDataGetEncCert.restype = c_int
        self._handle.NetcaPKIMsgSignedDataGetEncCert.argtypes=[c_void_p,c_int,POINTER(c_void_p)]
        
        self._handle.NetcaPKIMsgSignedDataGetTSACert.restype = c_void_p
        self._handle.NetcaPKIMsgSignedDataGetTSACert.argtypes=[c_void_p,c_int]
        
        self._handle.NetcaPKIMsgSignedDataGetCountersignatureCert.restype = c_void_p
        self._handle.NetcaPKIMsgSignedDataGetCountersignatureCert.argtypes=[c_void_p,c_int,c_int]
        
        self._handle.NetcaPKIAppSignedDataSign.restype = c_int
        self._handle.NetcaPKIAppSignedDataSign.argtypes=[c_void_p,c_int,POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int),POINTER(c_void_p)]
        
        self._handle.NetcaPKIAppSignedDataApplySignConfig.restype = c_int
        self._handle.NetcaPKIAppSignedDataApplySignConfig.argtypes=[c_void_p]
        
        self._handle.NetcaPKIAppSignedDataVerify.restype = c_int
        self._handle.NetcaPKIAppSignedDataVerify.argtypes=[c_void_p,POINTER(c_char),c_int,POINTER(c_char),c_int,POINTER(c_void_p)]
        
        self._handle.NetcaPKIAppNewSignedDataVerifyHandle.restype = c_void_p
        self._handle.NetcaPKIAppNewSignedDataVerifyHandle.argtypes=[]
        
        self._handle.NetcaPKIAppSignedDataVerifyPostCheck.restype = c_int
        self._handle.NetcaPKIAppSignedDataVerifyPostCheck.argtypes=[c_void_p]
        
        self._handle.NetcaPKIAppSignedDataVerifyPostCheck.restype = c_int
        self._handle.NetcaPKIAppSignedDataVerifyPostCheck.argtypes=[c_void_p]
        
        self._handle.NetcaPKIMsgSignedDataMaybe.restype = c_int
        self._handle.NetcaPKIMsgSignedDataMaybe.argtypes=[POINTER(c_char),c_int,POINTER(c_int)]
        
        self._handle.NetcaPKIAppSignedDataAttachTimeStamp.restype = c_int
        self._handle.NetcaPKIAppSignedDataAttachTimeStamp.argtypes=[c_void_p,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIAppSignedDataAttachTimeStamp.restype = c_int
        self._handle.NetcaPKIAppSignedDataAttachTimeStamp.argtypes=[c_void_p,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIConfigSignedDataGetIncludeCertOption.restype = c_int
        self._handle.NetcaPKIConfigSignedDataGetIncludeCertOption.argtypes=[]
        
        self._handle.NetcaPKIConfigSignedDataSetIncludeCertOption.restype = c_int
        self._handle.NetcaPKIConfigSignedDataSetIncludeCertOption.argtypes=[]
    
    def _init_timestamp_fuction(self):
        self._handle.NetcaPKIMsgNewTimeStamp.restype = c_void_p
        self._handle.NetcaPKIMsgNewTimeStamp.argtypes=[]
        
        self._handle.NetcaPKIMsgFreeTimeStamp.restype = c_int
        self._handle.NetcaPKIMsgFreeTimeStamp.argtypes=[c_void_p]
        
        self._handle.NetcaPKIMsgTimeStampSetTSA.restype = c_int
        self._handle.NetcaPKIMsgTimeStampSetTSA.argtypes=[c_void_p,c_char_p]
        
        self._handle.NetcaPKIMsgTimeStampSetHashAlgorithm.restype = c_int
        self._handle.NetcaPKIMsgTimeStampSetHashAlgorithm.argtypes=[c_void_p,c_int]
        
        self._handle.NetcaPKIMsgTimeStampSetHashAlgorithm.restype = c_int
        self._handle.NetcaPKIMsgTimeStampSetHashAlgorithm.argtypes=[c_void_p,c_int]
        
        self._handle.NetcaPKIMsgTimeStampSetMessageImprint.restype = c_int
        self._handle.NetcaPKIMsgTimeStampSetMessageImprint.argtypes=[c_void_p,POINTER(c_char),c_int]
        
        self._handle.NetcaPKIMsgTimeStampGetReqEncode.restype = c_int
        self._handle.NetcaPKIMsgTimeStampGetReqEncode.argtypes=[c_void_p,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgTimeStampGetResponse.restype = c_int
        self._handle.NetcaPKIMsgTimeStampGetResponse.argtypes=[c_void_p,POINTER(c_int)]
        
        self._handle.NetcaPKIMsgTimeStampGetTimeStampTokenFromResponse.restype = c_int
        self._handle.NetcaPKIMsgTimeStampGetTimeStampTokenFromResponse.argtypes=[POINTER(c_char),c_int,POINTER(c_int),POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgTimeStampGetTimeStampToken.restype = c_int
        self._handle.NetcaPKIMsgTimeStampGetTimeStampToken.argtypes=[c_void_p,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgTimeStampGetTSACert.restype = c_void_p
        self._handle.NetcaPKIMsgTimeStampGetTSACert.argtypes=[c_void_p]
        
        self._handle.NetcaPKIMsgVerifyTimeStampToken.restype = c_void_p
        self._handle.NetcaPKIMsgVerifyTimeStampToken.argtypes=[POINTER(c_char),c_int,c_void_p]
        
        self._handle.NetcaPKIMsgTimeStampGetHashAlgorithm.restype = c_int
        self._handle.NetcaPKIMsgTimeStampGetHashAlgorithm.argtypes=[c_void_p]
        
        self._handle.NetcaPKIMsgTimeStampGetMessageImprint.restype = c_int
        self._handle.NetcaPKIMsgTimeStampGetMessageImprint.argtypes=[c_void_p,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKIMsgTimeStampGetTime.restype = c_void_p
        self._handle.NetcaPKIMsgTimeStampGetTime.argtypes=[c_void_p]
        
        self._handle.NetcaPKIMsgTimeStampGetPolicy.restype = c_void_p
        self._handle.NetcaPKIMsgTimeStampGetPolicy.argtypes=[c_void_p]
        
        self._handle.NetcaPKIMsgTimeStampSetPolicy.restype = c_int
        self._handle.NetcaPKIMsgTimeStampSetPolicy.argtypes=[c_void_p,c_char_p]
        
        self._handle.NetcaPKIMsgTimeStampGetSerialNumber.restype = c_void_p
        self._handle.NetcaPKIMsgTimeStampGetSerialNumber.argtypes=[c_void_p]
        
        self._handle.NetcaPKIMsgTimeStampSetCertReq.restype = c_int
        self._handle.NetcaPKIMsgTimeStampSetCertReq.argtypes=[c_void_p,c_int]
        
        self._handle.NetcaPKIMsgTimeStampGetCertReq.restype = c_int
        self._handle.NetcaPKIMsgTimeStampGetCertReq.argtypes=[c_void_p,POINTER(c_int)]
        
        self._handle.NetcaPKIMsgTimeStampSetTSACert.restype = c_int
        self._handle.NetcaPKIMsgTimeStampSetTSACert.argtypes=[c_void_p,c_void_p]
        
        self._handle.NetcaPKIAppTimeStampGetToken.restype = c_int
        self._handle.NetcaPKIAppTimeStampGetToken.argtypes=[POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int),POINTER(c_void_p)]
        
        self._handle.NetcaPKIAppTimeStampVerifyToken.restype = c_void_p
        self._handle.NetcaPKIAppTimeStampVerifyToken.argtypes=[POINTER(c_char),c_int,POINTER(c_char),c_int,POINTER(c_void_p)]
        
        self._handle.NetcaPKIMsgTimeStampGetAccuracy.restype = c_int
        self._handle.NetcaPKIMsgTimeStampGetAccuracy.argtypes=[c_void_p,POINTER(c_int),POINTER(c_int),POINTER(c_int)]
        
    def _init_base64_fuction(self):
        self._handle.NetcaPKICryptoNewBase64.restype = c_void_p
        self._handle.NetcaPKICryptoNewBase64.argtypes=[c_int,c_int]
        
        self._handle.NetcaPKICryptoBase64.restype = c_int
        self._handle.NetcaPKICryptoBase64.argtypes=[c_int,c_int,POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKICryptoBase64Update.restype = c_int
        self._handle.NetcaPKICryptoBase64Update.argtypes=[c_void_p,POINTER(c_char),c_int,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKICryptoBase64Final.restype = c_int
        self._handle.NetcaPKICryptoBase64Final.argtypes=[c_void_p,POINTER(c_void_p),POINTER(c_int)]
        
        self._handle.NetcaPKICryptoFreeBase64.restype = c_int
        self._handle.NetcaPKICryptoFreeBase64.argtypes=[c_void_p]
  
    @staticmethod
    def _to_bytes(data,data_len):
        buf=cast(data,POINTER(c_ubyte))
        buf_len=data_len.value
        b=bytearray(buf_len)
        for i in range(buf_len):
            b[i]=buf[i]
        return bytes(b)

    def __init__(self):
        self._handle=self._load_dll()
        self._init_util_fuction()
        self._init_hash_fuction()
        self._init_cert_fuction()
        self._init_envelopeddata_fuction()
        self._init_signeddata_fuction()
        self._init_timestamp_fuction()
        self._init_base64_fuction()

    def _new_hash(self,algo):
        handle=self._handle.NetcaPKICryptoGetHashHandle(algo)
        if handle is None:
            raise NetcaCryptoException("NetcaPKICryptoGetHashHandle Fail")
        return handle

    def _hash_update(self,handle,data):
        rv=self._handle.NetcaPKICryptoHashUpdate(handle,bytes(data),len(data))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKICryptoHashUpdate Fail",rv)

    def _hash_final(self,handle):
        data=c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKICryptoHashFinal(handle,byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKICryptoHashFinal Fail",rv) 
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret

    def _free_hash(self,handle):
        self._handle.NetcaPKICryptoFreeHash(handle)

    def _new_cert(self,str):
        if type(str)==type(b"") or type(str)==bytearray:
            handle=self._handle.NetcaPKICertNewCert(bytes(str),len(str))
        elif type(str)==type(""):
            p=str.encode("utf8")
            handle=self._handle.NetcaPKICertNewCert(p,len(p))
        else:
            raise NetcaCryptoException("bad str type")
        if handle==None:
            raise NetcaCryptoException("NetcaPKICertNewCert Fail")
        return handle

    def _free_cert(self,handle):
        self._handle.NetcaPKICertFreeCert(handle)

    def _get_cert_int_attribute(self,handle,attr_id):
        attr_value = c_long()
        rv=self._handle.NetcaPKICertGetCertIntegerAttribute(handle,attr_id,byref(attr_value))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKICertGetCertIntegerAttribute Fail",rv) 
        return attr_value.value

    @staticmethod
    def _to_utf8string(buf,begin,end):
        len=end-begin
        b=bytearray(len)
        for i in range(len):
            b[i]=buf[i+begin]
        return b.decode("utf8")

    @staticmethod
    def _c_void_p_to_utf8string(data,data_len):
        return Interop._to_bytes(data,data_len).decode("utf8")
        
    @staticmethod
    def _chararray_to_list(str):
        buf=cast(str,POINTER(c_ubyte))
        strlist=[]
        begin=0
        i=0
        while True:
            if buf[i]==0 :
                strlist.append(Interop._to_utf8string(buf,begin,i))
                begin=i+1
                if buf[i+1]==0:
                    break
            i=i+1
        return strlist

    @staticmethod
    def _chararray_to_string(str):
        buf=cast(str,POINTER(c_ubyte))
        i=0
        while True:
            if buf[i]==0 :
                return Interop._to_utf8string(buf,0,i)
            i=i+1

    @staticmethod
    def _void_p_p_to_list(str,count):
        buf=cast(str,POINTER(c_void_p))
        i=0
        list=[]
        while i<count:
            list.append(buf[i])
            i=i+1
        return list

    def _get_cert_string_attribute(self,handle,attr_id):
        attr_value = c_void_p()
        rv=self._handle.NetcaPKICertGetCertStringAttribute(handle,attr_id,byref(attr_value))
        if rv==NetcaCryptoErrorCode.NOTEXISIT:
            return None
        elif rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKICertGetCertStringAttribute Fail",rv)
        
        if self._handle.NetcaPKICertGetAttributeType(attr_id)==Certificate.ATTRIBUTE_TYPE_MULTI_VALUE_STRING:
            list= Interop._chararray_to_list(attr_value.value)
            if len(list)==0:
                self._handle.NetcaPKICryptoFreeMemory(attr_value)
                return None
            self._handle.NetcaPKICryptoFreeMemory(attr_value)
            return list[0]
        ret=Interop._chararray_to_string(attr_value.value)
        self._handle.NetcaPKICryptoFreeMemory(attr_value)
        return ret
    
    def _get_cert_stringarray_attribute(self,handle,attr_id):
        attr_value = c_void_p()
        rv=self._handle.NetcaPKICertGetCertStringAttribute(handle,attr_id,byref(attr_value))
        if rv==NetcaCryptoErrorCode.NOTEXISIT:
            return None
        elif rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKICertGetCertStringAttribute Fail",rv)
        
        if self._handle.NetcaPKICertGetAttributeType(attr_id)==Certificate.ATTRIBUTE_TYPE_MULTI_VALUE_STRING:
            list= Interop._chararray_to_list(attr_value.value)
            self._handle.NetcaPKICryptoFreeMemory(attr_value)
            return tuple(list)
        list=[]
        list.append(Interop._chararray_to_string(attr_value.value))
        self._handle.NetcaPKICryptoFreeMemory(attr_value)
        return tuple(list)
    
    def _get_cert_attribute_type(self,attr_id):
        return self._handle.NetcaPKICertGetAttributeType(attr_id)

    def _get_cert_hash_attribute(self,handle,attr_id,hash_algo):
        attr_value = c_void_p()
        attr_value_len = c_int()
        rv=self._handle.NetcaPKICertGetCertHashAttribute(handle,attr_id,hash_algo,byref(attr_value),byref(attr_value_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKICertGetCertHashAttribute Fail",rv)
        
        ret= Interop._to_bytes(attr_value,attr_value_len)
        self._handle.NetcaPKICryptoFreeMemory(attr_value)
        return ret
    
    def _get_cert_der_encode(self,handle):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKICertGetCertEncode(handle,1,byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKICertGetCertEncode Fail",rv)
        
        ret= Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _get_cert_pem_encode(self,handle):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKICertGetCertEncode(handle,2,byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKICertGetCertEncode Fail",rv)
        
        ret= Interop._c_void_p_to_utf8string(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret

    def _cert_match(self,handle,expr):
        rv=self._handle.NetcaPKICertMatch(handle,expr.encode("utf8"))
        if rv==1:
            return True
        elif rv==0:
            return False
        elif rv==-1:
            raise NetcaCryptoException("NetcaPKICertGetCertEncode Fail,bad expr:%s" % (expr))
        else:
            raise NetcaCryptoException("NetcaPKICertGetCertEncode Fail")
    
    def _select_cert(self,type,expr):
        cert = c_void_p()
        rv=NetcaCryptoErrorCode.SUCCESS
        if expr is None:
            rv=self._handle.NetcaPKISelectCert(type.encode("utf8"),expr,byref(cert))
        else:
            rv=self._handle.NetcaPKISelectCert(type.encode("utf8"),expr.encode("utf8"),byref(cert))
        
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            return None
        
        if cert.value is None:
            return None
        
        return cert
    
    def _get_cert_string_extension_value(self,handle,oid):
        str=self._handle.NetcaPKIAppCertGetStringExtension(handle,oid.encode("utf8"))
        if str is None:
            return None
        ret=Interop._chararray_to_string(str)
        self._handle.NetcaPKICryptoFreeMemory(str)
        return ret
    
    def _get_cert_extension_value(self,handle,oid):
        critical=c_int()
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKICertFindExtension(handle,oid.encode("utf8"),byref(critical),byref(data),byref(data_len))
        if rv==NetcaCryptoErrorCode.NOTEXISIT:
            return None
        elif rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKICertFindExtension Fail",rv)
        dict={}
        if critical.value==0:
            dict["critical"]=False
        else:
            dict["critical"]=True
        dict["extension_value"]= Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return dict
        
    def _get_user_cert(self,type,condition):
        cert = None
        if condition is None:
            cert=self._handle.NetcaPKIAppGetUserCert(type,condition)
        else:
            cert=self._handle.NetcaPKIAppGetUserCert(type,condition.encode("utf8"))
        
        if cert is None:
            return None
        
        return cert
    
    def _cert_encrypt(self,handle,clear):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIAppCertEncrypt(handle,bytes(clear),len(clear),byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIAppCertEncrypt Fail",rv)
        ret= Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _cert_decrypt(self,handle,cipher):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIAppCertDecrypt(handle,bytes(cipher),len(cipher),byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIAppCertDecrypt Fail",rv)
        ret= Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _cert_sign(self,handle,tbs):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIAppSign(handle,bytes(tbs),len(tbs),byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIAppSign Fail",rv)
        ret= Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _cert_verify_signature(self,handle,tbs,signature):
        rv=self._handle.NetcaPKIAppVerify(handle,bytes(tbs),len(tbs),bytes(signature),len(signature))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            return False
        return True
    
    def _cert_get_keypair(self,handle,pwd):
        keypair=c_void_p()
        if pwd==None:
            rv=self._handle.NetcaPKIAppCertGetKeypair(handle,pwd,byref(keypair))
        else:
            rv=self._handle.NetcaPKIAppCertGetKeypair(handle,pwd.encode("utf8"),byref(keypair))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            return None
        
        return keypair
    
    def _free_keypair(self,handle):
        self._handle.NetcaPKICryptoFreeKeypair(handle)
        
    def _get_certpath(self,handle):
        certpath_value = c_void_p()
        certpath_count = c_int()
        rv=self._handle.NetcaPKICertGetCertPath(handle,byref(certpath_value),byref(certpath_count))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKICertGetCertPath Fail",rv)
        
        list=Interop._void_p_p_to_list(certpath_value,certpath_count.value)
        self._handle.NetcaPKICryptoFreeMemory(certpath_value)
        return list

    def _get_revoke_info(self,dict,rev_info):
        time=self._handle.NetcaPKICertGetRevokedCertRevokedTime(rev_info)
        if time is None:
            raise NetcaCryptoException("NetcaPKICertGetRevokedCertRevokedTime Fail")
        dict["revoked_time"]=Interop._chararray_to_string(time)
        self._handle.NetcaPKICryptoFreeMemory(time)
        reason=self._handle.NetcaPKICertGetRevokedCertRevokedReason(rev_info)
        if reason!=-1:
            dict["revoked_reason"]=reason


    def _verify_cert(self,handle,flag,time):
        rev_info = c_void_p()
        status = c_int()
        rv=-1
        if time is None:
            rv=self._handle.NetcaPKICertVerifyCert(handle,None,flag,byref(status),byref(rev_info))
        else:
            rv=self._handle.NetcaPKICertVerifyCert(handle,time.encode("utf8"),flag,byref(status),byref(rev_info))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKICertVerifyCert Fail",rv)
        
        dict={}
        dict["status"]=status.value
        if status.value==0 or status.value==-2:
            try:
                self._get_revoke_info(dict,rev_info)
            finally:
                self._handle.NetcaPKICertFreeRevokedCert(rev_info)
        return dict
    
    def _verify_cert_by_ocsp(self,handle,url,ocsp_cert):
        rev_info = c_void_p()
        status = c_int()
        rv=-1
        if url is None:
            rv=self._handle.NetcaPKICertOCSPVerifyCert(handle,None,ocsp_cert,byref(status),byref(rev_info))
        else:
            rv=self._handle.NetcaPKICertOCSPVerifyCert(handle,url.encode("utf8"),ocsp_cert,byref(status),byref(rev_info))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKICertOCSPVerifyCert Fail",rv)
        
        dict={}
        dict["status"]=status.value
        if status.value==0 or status.value==-2:
            try:
                self._get_revoke_info(dict,rev_info)
            finally:
                self._handle.NetcaPKICertFreeRevokedCert(rev_info)
        return dict

    def _free_envelopeddata(self,handle):
        self._handle.NetcaPKIMsgFreeEnvelopedData(handle)
    
    def _new_envelopeddata(self,enc):
        handle=None
        if enc:
            handle=self._handle.NetcaPKIMsgNewEnvelopedData(1)
        else:
            handle=self._handle.NetcaPKIMsgNewEnvelopedData(0)
        if handle==None:
            raise NetcaCryptoException("NetcaPKIMsgNewEnvelopedData Fail")
        return handle
    
    def _envelopeddata_encrypt(self,handle,clear):
        data = c_void_p()
        data_len = c_int()
        env=c_void_p()
        rv=self._handle.NetcaPKIAppEnvelopedDataEncrypt(handle,bytes(clear),len(clear),byref(data),byref(data_len),byref(env))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIAppEnvelopedDataEncrypt Fail",rv)
        self._free_envelopeddata(env)
        ret= Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _envelopeddata_decrypt(self,cipher):
        data = c_void_p()
        data_len = c_int()
        env=c_void_p()
        rv=self._handle.NetcaPKIAppEnvelopedDataDecrypt(bytes(cipher),len(cipher),byref(data),byref(data_len),byref(env))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIAppEnvelopedDataDecrypt Fail",rv)
        self._free_envelopeddata(env)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
        
    def _envelopeddata_set_decrypt_cert(self,handle):
        rv=self._handle.NetcaPKIConfigEnvelopedDataSetDecryptCert(handle)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIConfigEnvelopedDataSetDecryptCert Fail",rv)
    
    def _envelopeddata_new_encrypt_handle(self):
        handle=self._handle.NetcaPKIAppNewEnvelopedDataEncryptHandle()
        if handle is None:
            raise NetcaCryptoException("NetcaPKIAppNewEnvelopedDataEncryptHandle Fail")
        return handle
        
    def _envelopeddata_new_decrypt_handle(self):
        handle=self._handle.NetcaPKIAppNewEnvelopedDataDecryptHandle()
        if handle==None:
            raise NetcaCryptoException("NetcaPKIAppNewEnvelopedDataDecryptHandle Fail")
        return handle
    
    def _envelopeddata_decrypt_postcheck(self,handle):
        rv=self._handle.NetcaPKIAppEnvelopedDataDecryptPostCheck(handle)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIAppEnvelopedDataDecryptPostCheck Fail",rv)
    
    def _envelopeddata_set_enc_algo(self,handle,algo):
        rv=self._handle.NetcaPKIMsgEnvelopedDataSetEncAlgorithm(handle,algo)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgEnvelopedDataSetEncAlgorithm Fail",rv)
    
    def _envelopeddata_add_cert(self,handle,cert_handle,flag):
        rv=self._handle.NetcaPKIMsgEnvelopedDataAddCert(handle,cert_handle,flag)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgEnvelopedDataAddCert Fail",rv)
    
    def _envelopeddata_set_int_attribute(self,handle,attr_type,attr_value):
        rv=self._handle.NetcaPKIMsgEnvelopedDataSetIntegerAttribute(handle,attr_type,attr_value)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgEnvelopedDataSetIntegerAttribute Fail",rv)
    
    def _envelopeddata_set_string_attribute(self,handle,attr_type,attr_value):
        rv=self._handle.NetcaPKIMsgEnvelopedDataSetStringAttribute(handle,attr_type,attr_value.encode("utf8"))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgEnvelopedDataSetStringAttribute Fail",rv)
    
    def _envelopeddata_encrypt_onestep(self,handle,clear):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgEnvelopedDataEncrypt(handle,bytes(clear),len(clear),byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgEnvelopedDataEncrypt Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
        
    def _envelopeddata_encrypt_init(self,handle):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgEnvelopedDataEncryptInit(handle,byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgEnvelopedDataEncryptInit Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _envelopeddata_encrypt_update(self,handle,clear):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgEnvelopedDataEncryptUpdate(handle,bytes(clear),len(clear),byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgEnvelopedDataEncryptUpdate Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _envelopeddata_encrypt_final(self,handle):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgEnvelopedDataEncryptFinal(handle,byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgEnvelopedDataEncryptFinal Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _envelopeddata_decrypt_onestep(self,handle,cipher):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgEnvelopedDataDecrypt(handle,bytes(cipher),len(cipher),byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgEnvelopedDataDecrypt Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _envelopeddata_decrypt_init(self,handle):
        rv=self._handle.NetcaPKIMsgEnvelopedDataDecryptInit(handle)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgEnvelopedDataDecryptInit Fail",rv)
    
    def _envelopeddata_decrypt_update(self,handle,cipher):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgEnvelopedDataDecryptUpdate(handle,bytes(cipher),len(cipher),byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgEnvelopedDataDecryptUpdate Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _envelopeddata_decrypt_final(self,handle):
        rv=self._handle.NetcaPKIMsgEnvelopedDataDecryptFinal(handle)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgEnvelopedDataDecryptFinal Fail",rv)
    
    def _envelopeddata_get_enc_algo(self,handle):
        return self._handle.NetcaPKIMsgEnvelopedDataGetEncAlgorithm(handle)
    
    def _envelopeddata_get_decrypt_cert(self,handle):
        return self._handle.NetcaPKIMsgEnvelopedDataGetCert(handle)

    def _envelopeddata_get_recipientinfosencode(self,handle):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgEnvelopedDataGetRecipientInfosEncode(handle,byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgEnvelopedDataGetRecipientInfosEncode Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret       
    
    def _envelopeddata_is_contentinfo(self,handle):
        if self._handle.NetcaPKIMsgEnvelopedDataIsContentInfo(handle)==0:
            return False
        else:
            return True
    
    def _new_signeddata(self,sign):
        handle=None
        if sign:
            handle=self._handle.NetcaPKIMsgNewSignedData(1)
        else:
            handle=self._handle.NetcaPKIMsgNewSignedData(0)
        if handle is None:
            raise NetcaCryptoException("NetcaPKIMsgNewSignedData Fail")
        return handle
    
    def _free_signeddata(self,handle):
        handle=self._handle.NetcaPKIMsgFreeSignedData(handle)
    
    def _signeddata_sign(self,cert_handle,detached,tbs):
        data = c_void_p()
        data_len = c_int()
        sign_handle=c_void_p()
        detachedValue=0
        if detached:
            detachedValue=1
        rv=self._handle.NetcaPKIAppSignedDataSign(cert_handle,detachedValue,bytes(tbs),len(tbs),byref(data),byref(data_len),byref(sign_handle))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIAppSignedDataSign Fail",rv)
        self._free_signeddata(sign_handle)
        ret= Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _signeddata_sign_with_timestamp(self,cert_handle,detached,tbs):
        data = c_void_p()
        data_len = c_int()
        sign_handle=c_void_p()
        detachedValue=0
        if detached:
            detachedValue=1
        rv=self._handle.NetcaPKIAppSignedDataSign(cert_handle,detachedValue,bytes(tbs),len(tbs),byref(data),byref(data_len),byref(sign_handle))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIAppSignedDataSign Fail",rv)
        self._handle.NetcaPKICryptoFreeMemory(data)
        
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIAppSignedDataAttachTimeStamp(sign_handle,byref(data),byref(data_len));
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            self._free_signeddata(sign_handle)
            raise NetcaCryptoException("NetcaPKIAppSignedDataAttachTimeStamp Fail",rv)
        try:
            list=[]
            list.append(Interop._to_bytes(data,data_len))
            count=self._signeddata_get_int_attribute(sign_handle,1,-1)
            time=self._signeddata_get_string_attribute(sign_handle,12,count-1)
            list.append(time)
            return tuple(list)
        finally:
            self._handle.NetcaPKICryptoFreeMemory(data)
            self._free_signeddata(sign_handle)
    
    def _signeddata_get_int_attribute(self,handle,attr_id,index):
        value=c_int()
        rv= self._handle.NetcaPKIMsgSignedDataGetIntegerAttribute(handle,attr_id,index,byref(value))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataGetIntegerAttribute Fail",rv)
        return value.value
    
    def _signeddata_verify(self,tbs,sign_value,cert_handle):
        sign_handle=c_void_p()
        rv=self._handle.NetcaPKIAppSignedDataVerify(cert_handle,bytes(tbs),len(tbs),bytes(sign_value),len(sign_value),byref(sign_handle))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIAppSignedDataVerify Fail",rv)
        if self._signeddata_get_int_attribute(sign_handle,1,-1)!=1:
            self._free_signeddata(sign_handle)
            raise NetcaCryptoException("too much signer")
        sign_cert=self._handle.NetcaPKIMsgSignedDataGetSignCert(sign_handle,0)
        self._free_signeddata(sign_handle)
        return sign_cert
    
    def _signeddata_apply_sign_config(self,handle):
        rv=self._handle.NetcaPKIAppSignedDataApplySignConfig(handle)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIAppSignedDataApplySignConfig Fail",rv)
    
    def _signeddata_new_verify_handle(self):
        handle=self._handle.NetcaPKIAppNewSignedDataVerifyHandle()
        if handle is None:
            raise NetcaCryptoException("NetcaPKIAppNewSignedDataVerifyHandle Fail")
        return handle
    
    def _signeddata_verify_postcheck(self,handle):
        rv=self._handle.NetcaPKIAppSignedDataVerifyPostCheck(handle)
        if handle is None:
            raise NetcaCryptoException("NetcaPKIAppSignedDataVerifyPostCheck Fail")
    
    def _signeddata_sign_onestep(self,handle,tbs):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgSignedDataSign(handle,bytes(tbs),len(tbs),byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataSign Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _signeddata_cosign(self,handle):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgSignedDataSign(handle,None,0,byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataSign Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret

    def _signeddata_countsign(self,handle,index,signalgo,cert_handle):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgSignedDataCountersign(handle,index,signalgo,cert_handle,None,byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataCountersign Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _signeddata_sign_init(self,handle):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgSignedDataSignInit(handle,byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataSignInit Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _signeddata_sign_update(self,handle,tbs):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgSignedDataSignUpdate(handle,bytes(tbs),len(tbs),byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataSignUpdate Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _signeddata_sign_final(self,handle):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgSignedDataSignFinal(handle,byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataSignFinal Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _signeddata_set_int_attribute(self,handle,attr_id,attr_value,index):
        rv=self._handle.NetcaPKIMsgSignedDataSetIntegerAttribute(handle,attr_id,index,attr_value)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataSetIntegerAttribute Fail",rv)
    
    def _signeddata_set_string_attribute(self,handle,attr_id,attr_value,index):
        rv=self._handle.NetcaPKIMsgSignedDataSetStringAttribute(handle,attr_id,index,attr_value.encode("utf8"))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataSetStringAttribute Fail",rv)
    
    def _signeddata_sign_with_timestamp_final(self,handle,tsaurl,hash_algo):
        if hash_algo>0:
            count=self._signeddata_get_int_attribute(handle,1,-1)
            self._signeddata_set_int_attribute(handle,18,hash_algo,count-1)
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgSignedDataSignWithTimeStampFinal(handle,tsaurl.encode("utf8"),byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataSignFinal Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _signeddata_sign_with_timestamp_onestep(self,handle,tbs,tsaurl,hash_algo):
        if hash_algo>0:
            count=self._signeddata_get_int_attribute(handle,1,-1)
            self._signeddata_set_int_attribute(handle,18,hash_algo,count-1)
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgSignedDataSignWithTimeStamp(handle,tsaurl.encode("utf8"),bytes(tbs),len(tbs),byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataSignWithTimeStamp Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _signeddata_get_string_attribute(self,handle,attr_id,index):
        attr_value = c_void_p()
        rv=self._handle.NetcaPKIMsgSignedDataGetStringAttribute(handle,attr_id,index,byref(attr_value))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataGetStringAttribute Fail",rv)
        
        ret=Interop._chararray_to_string(attr_value.value)
        self._handle.NetcaPKICryptoFreeMemory(attr_value)
        return ret
    
    def _signeddata_maybe(self,data):
        detached = c_int()
        rv=self._handle.NetcaPKIMsgSignedDataMaybe(bytes(data),len(data),byref(detached))
        list=[]
        if rv==0:
            list.append(False)
            list.append(True)
        else:
            list.append(True)
            if detached.value==0:
                list.append(False)
            else:
                list.append(True)
        
        return list

    def _signeddata_verify_onestep(self,handle,sign_value):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgSignedDataVerify(handle,bytes(sign_value),len(sign_value),byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataVerify Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _signeddata_verify_init(self,handle):
        rv=self._handle.NetcaPKIMsgSignedDataVerifyInit(handle)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataVerifyInit Fail",rv)
    
    def _signeddata_verify_update(self,handle,sign_value):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgSignedDataVerifyUpdate(handle,bytes(sign_value),len(sign_value),byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataVerifyUpdate Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _signeddata_verify_final(self,handle):
        rv=self._handle.NetcaPKIMsgSignedDataVerifyFinal(handle)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataVerifyFinal Fail",rv)
    
    def _signeddata_detached_verify_init(self,handle,sign_value):
        rv=self._handle.NetcaPKIMsgSignedDataDetachedVerifyInit(handle,bytes(sign_value),len(sign_value))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataDetachedVerifyInit Fail",rv)
    
    def _signeddata_detached_verify_update(self,handle,tbs):
        rv=self._handle.NetcaPKIMsgSignedDataDetachedVerifyUpdate(handle,bytes(tbs),len(tbs))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataDetachedVerifyUpdate Fail",rv)
    
    def _signeddata_detached_verify_final(self,handle):
        rv=self._handle.NetcaPKIMsgSignedDataDetachedVerifyFinal(handle)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataDetachedVerifyFinal Fail",rv)
    
    def _signeddata_detached_verify(self,handle,tbs,sign_value):
        rv=self._handle.NetcaPKIMsgSignedDataDetachedVerify(handle,bytes(tbs),len(tbs),bytes(sign_value),len(sign_value))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataDetachedVerify Fail",rv)
    
    def _signeddata_verify_timestamp(self,handle,index,cert_handle):
        rv=self._handle.NetcaPKIMsgSignedDataVerifyTimeStamp(handle,index,cert_handle)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataVerifyTimeStamp Fail",rv)

    def _signeddata_verify_countersignature(self,handle,index,countersignindex,cert_handle):
        rv=self._handle.NetcaPKIMsgSignedDataVerifyCountersignature(handle,index,countersignindex,cert_handle)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataVerifyCountersignature Fail",rv)
    
    def _signeddata_get_signcert(self,handle,index):
        handle=self._handle.NetcaPKIMsgSignedDataGetSignCert(handle,index)
        if handle is None:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataGetSignCert Fail")
        return handle

    def _signeddata_get_countsignaturecert(self,handle,index,countersignindex):
        handle=self._handle.NetcaPKIMsgSignedDataGetCountersignatureCert(handle,index,countersignindex)
        if handle is None:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataGetCountersignatureCert Fail")
        return handle
    
    def _signeddata_set_signcert(self,handle,cert_handle):
        rv=self._handle.NetcaPKIMsgSignedDataSetSignCert(handle,cert_handle,None)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataSetSignCert Fail",rv)
    
    def _signeddata_set_enccert(self,handle,cert_handle,index,flag):
        rv=self._handle.NetcaPKIMsgSignedDataSetEncCert(handle,index,flag,cert_handle)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataSetEncCert Fail",rv)
    
    def _signeddata_add_cert(self,handle,cert_handle):
        rv=self._handle.NetcaPKIMsgSignedDataAddCert(handle,cert_handle)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataAddCert Fail",rv)

    def _signeddata_add_rootcert(self,handle,cert_handle):
        rv=self._handle.NetcaPKIMsgSignedDataAddRootCert(handle,cert_handle)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataAddRootCert Fail",rv)

    def _signeddata_add_crl(self,handle,crl):
        rv=self._handle.NetcaPKIMsgSignedDataAddCRL(handle,bytes(crl),len(crl))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataAddCRL Fail",rv)

    def _signeddata_add_ocsp(self,handle,flag,cert,ocsp):
        if(cert is None):
            rv=self._handle.NetcaPKIMsgSignedDataAddOCSP(handle,flag,cert,bytes(ocsp),len(ocsp))
        else:
            rv=self._handle.NetcaPKIMsgSignedDataAddOCSP(handle,flag,cert._handle,bytes(ocsp),len(ocsp))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataAddOCSP Fail",rv)

    def _signeddata_get_tsacert(self,handle,index):
        handle=self._handle.NetcaPKIMsgSignedDataGetTSACert(handle,index)
        if handle is None:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataGetTSACert Fail")
        return handle
    
    def _signeddata_get_enccert(self,handle,index):
        cert_handle=c_void_p()
        rv=self._handle.NetcaPKIMsgSignedDataGetEncCert(handle,index,byref(cert_handle))
        if rv==NetcaCryptoErrorCode.NOTEXISIT:
            return None
        elif rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataGetEncCert Fail",rv)
        return cert_handle
        
    def _signeddata_attach_timestamp(self,handle):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIAppSignedDataAttachTimeStamp(handle,byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIAppSignedDataAttachTimeStamp Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _signeddata_attach_signature_timestamp(self,handle,tsa_url,hash_algo,index):
        rv=self._handle.NetcaPKIMsgSignedDataAttachSignatureTimeStamp(handle,index,hash_algo,tsa_url.encode("utf8"))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataAttachSignatureTimeStamp Fail",rv)
        
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgSignedDataEncode(handle,byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgSignedDataEncode Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _new_timestamp(self):
        handle=self._handle.NetcaPKIMsgNewTimeStamp()
        if handle is None:
            raise NetcaCryptoException("NetcaPKIMsgNewTimeStamp Fail")
        return handle
    
    def _free_timestamp(self,handle):
        self._handle.NetcaPKIMsgFreeTimeStamp(handle)
    
    def _get_timestamp(self,data):
        token = c_void_p()
        token_len = c_int()
        handle=c_void_p()
        rv=self._handle.NetcaPKIAppTimeStampGetToken(bytes(data),len(data),byref(token),byref(token_len),byref(handle))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIAppTimeStampGetToken Fail",rv)
        self._handle.NetcaPKICryptoFreeMemory(token)
        return handle
    
    def _timestamp_get_token(self,handle):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgTimeStampGetTimeStampToken(handle,byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampGetTimeStampToken Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _timestamp_get_time(self,handle):
        t=self._handle.NetcaPKIMsgTimeStampGetTime(handle)
        if t is None:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampGetTime Fail")
        ret=Interop._chararray_to_string(t)
        self._handle.NetcaPKICryptoFreeMemory(t)
        return ret
    
    def _timestamp_set_hash_algo(self,handle,algo):
        rv=self._handle.NetcaPKIMsgTimeStampSetHashAlgorithm(handle,algo)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampSetHashAlgorithm Fail",rv)
        
    def _timestamp_set_hash_value(self,handle,value):
        rv=self._handle.NetcaPKIMsgTimeStampSetMessageImprint(handle,bytes(value),len(value))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampSetMessageImprint Fail",rv)
    
    def _timestamp_set_tsa_url(self,handle,url):
        rv=self._handle.NetcaPKIMsgTimeStampSetTSA(handle,url.encode("utf8"))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampSetTSA Fail",rv)

    def _timestamp_get_req_encode(self,handle):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgTimeStampGetReqEncode(handle,byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampGetReqEncode Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _timestamp_get_resp(self,handle):
        status=c_int()
        rv=self._handle.NetcaPKIMsgTimeStampGetResponse(handle,byref(status))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampGetResponse Fail",rv)
        return status.value
    
    def _timestamp_get_tsa_cert(self,handle):
        cert=self._handle.NetcaPKIMsgTimeStampGetTSACert(handle)
        if cert is None:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampGetTSACert Fail")
        return cert
    
    def _decode_timestamp_resp(self,data,cert):
        status=c_int()
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgTimeStampGetTimeStampTokenFromResponse(byref(data),byref(data_len),byref(status),byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampGetTimeStampTokenFromResponse Fail",rv)
        if status.value==0 or status.value==1 :
            token=Interop._to_bytes(data,data_len)
            self._handle.NetcaPKICryptoFreeMemory(data)
            return (status.value,token)
        else:
            return (status.value,None)
        
    def _verify_timestamp_token(self,token,cert):
        handle=None
        if cert is None:
            handle=self._handle.NetcaPKIMsgVerifyTimeStampToken(bytes(token),len(token),cert)
        else:
            handle=self._handle.NetcaPKIMsgVerifyTimeStampToken(bytes(token),len(token),cert._handle)
        if handle is None:
            raise NetcaCryptoException("NetcaPKIMsgVerifyTimeStampToken Fail")
        return handle
    
    def _verify_timestamp(self,data,token):
        handle=c_void_p()
        time=self._handle.NetcaPKIAppTimeStampVerifyToken(bytes(data),len(data),bytes(token),len(token),byref(handle))
        if time is None:
            raise NetcaCryptoException("NetcaPKIAppTimeStampVerifyToken Fail")
        self._handle.NetcaPKICryptoFreeMemory(time)
        return handle
    
    def _timestamp_get_hash_algo(self,handle):
        rv=self._handle.NetcaPKIMsgTimeStampGetHashAlgorithm(handle)
        if rv==-1:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampGetHashAlgorithm Fail")
        return rv
    
    def _timestamp_get_hash_value(self,handle):
        data = c_void_p()
        data_len = c_int()
        rv=self._handle.NetcaPKIMsgTimeStampGetMessageImprint(handle,byref(data),byref(data_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampGetMessageImprint Fail",rv)
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret
    
    def _timestamp_get_policy(self,handle):
        policy=self._handle.NetcaPKIMsgTimeStampGetPolicy(handle)
        if policy is None:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampGetPolicy Fail")
        ret=Interop._chararray_to_string(policy)
        self._handle.NetcaPKICryptoFreeMemory(policy)
        return ret

    def _timestamp_set_policy(self,handle,policy):
        rv=self._handle.NetcaPKIMsgTimeStampSetPolicy(handle,policy.encode("utf8"))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampSetPolicy Fail",rv)

    def _timestamp_get_sn(self,handle):
        sn=self._handle.NetcaPKIMsgTimeStampGetSerialNumber(handle)
        if sn is None:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampGetSerialNumber Fail")
        ret=Interop._chararray_to_string(sn)
        self._handle.NetcaPKICryptoFreeMemory(sn)
        return ret
    
    def _timestamp_get_certreq(self,handle):
        value=c_int()
        rv=self._handle.NetcaPKIMsgTimeStampGetCertReq(handle,byref(value))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampGetCertReq Fail",rv)
        if value.value==0:
            return False
        else:
            return True
    
    def _timestamp_set_certreq(self,handle,certreq):
        value=0
        if certreq:
            value=1
        rv=self._handle.NetcaPKIMsgTimeStampSetCertReq(handle,value)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampSetCertReq Fail",rv)
    
    def _timestamp_set_tsa_cert(self,handle,cert):
        rv=self._handle.NetcaPKIMsgTimeStampSetTSACert(handle,cert._handle)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampSetTSACert Fail",rv)
    
    def _timestamp_get_accuracy(self,handle):
        seconds=c_int()
        millis=c_int()
        micros=c_int()
        rv=self._handle.NetcaPKIMsgTimeStampGetAccuracy(handle,byref(seconds),byref(millis),byref(micros))
        if rv==NetcaCryptoErrorCode.NOTEXISIT:
            return None
        elif rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIMsgTimeStampGetAccuracy Fail",rv)
        return (seconds.value,millis.value,micros.value)
    
    def _get_version(self):
        version=self._handle.NetcaPKIAppGetVersionInfo()
        if version is None:
            raise NetcaCryptoException("NetcaPKIAppGetVersionInfo Fail")
        
        ret=Interop._chararray_to_string(version)
        self._handle.NetcaPKICryptoFreeMemory(version)
        return ret
    
    def _get_last_error(self):
        return self._handle.NetcaPKIGetLastError()
    
    def _get_error_msg(self,error_no):
        value= self._handle.NetcaPKIGetErrorMsg(error_no)
        if value is None:
            return ""
        
        ret=Interop._chararray_to_string(value)
        self._handle.NetcaPKICryptoFreeMemory(value)
        return ret
    
    def _get_select_cert_policy(self):
        value= self._handle.NetcaPKIConfigGetSelectCertPolicy()
        if value is None:
            return None
        
        ret=Interop._chararray_to_string(value)
        self._handle.NetcaPKICryptoFreeMemory(value)
        return ret
    
    def _set_select_cert_policy(self,policy):
        rv=0
        if policy is None:
            rv=self._handle.NetcaPKIConfigSetSelectCertPolicy(None)
        else:
            rv=self._handle.NetcaPKIConfigSetSelectCertPolicy(policy.encode("utf8"))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIConfigSetSelectCertPolicy Fail",rv)
    
    def _get_filter_cert_condition(self):
        value= self._handle.NetcaPKIConfigGetFilterCertCondition()
        if value is None:
            return None
        
        ret=Interop._chararray_to_string(value)
        self._handle.NetcaPKICryptoFreeMemory(value)
        return ret
    
    def _set_filter_cert_condition(self,condition):
        rv=0
        if condition is None:
            rv=self._handle.NetcaPKIConfigSetFilterCertCondition(None)
        else:
            rv=self._handle.NetcaPKIConfigSetFilterCertCondition(condition.encode("utf8"))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIConfigSetFilterCertCondition Fail",rv)
    
    def _set_config(self,config):
        rv=self._handle.NetcaPKIConfigSetConfig(config.encode("utf8"))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIConfigSetConfig Fail",rv)
    
    def _get_config(self):
        value= self._handle.NetcaPKIConfigGetConfig()
        if value is None:
            return None
        
        ret=Interop._chararray_to_string(value)
        self._handle.NetcaPKICryptoFreeMemory(value)
        return ret
    
    def _reset_config(self):
        rv=self._handle.NetcaPKIConfigReset()
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIConfigReset Fail",rv)
    
    def _set_sign_algo(self,publickey_type,algo):
        rv=self._handle.NetcaPKIConfigSetSignAlgo(publickey_type.encode("utf8"),algo)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIConfigSetSignAlgo Fail",rv)
    
    def _set_publickey_encrypt_algo(self,publickey_type,algo):
        rv=self._handle.NetcaPKIConfigSetPublicKeyEncryptAlgo(publickey_type.encode("utf8"),algo)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIConfigSetPublicKeyEncryptAlgo Fail",rv)
    
    def _envelopeddata_set_default_enc_algo(self,algo):
        rv=self._handle.NetcaPKIConfigEnvelopedDataSetEncryptAlgo(algo)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIConfigEnvelopedDataSetEncryptAlgo Fail",rv)
    
    def _envelopeddata_get_default_enc_algo(self):
        algo=self._handle.NetcaPKIConfigEnvelopedDataGetEncryptAlgo()
        if algo==-1:
            raise NetcaCryptoException("NetcaPKIConfigEnvelopedDataGetEncryptAlgo Fail")
        return algo
    
    def _envelopeddata_set_default_use_subject_key_id(self,value):
        rv=0
        if value:
            rv=self._handle.NetcaPKIConfigEnvelopedDataSetUseSubjectKeyIdentifier(1)
        else:
            rv=self._handle.NetcaPKIConfigEnvelopedDataSetUseSubjectKeyIdentifier(0)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIConfigEnvelopedDataSetEncryptAlgo Fail",rv)
    
    def _envelopeddata_is_default_use_subject_key_id(self):
        rv=self._handle.NetcaPKIConfigEnvelopedDataIsUseSubjectKeyIdentifier()
        if rv==-1:
            raise NetcaCryptoException("NetcaPKIConfigEnvelopedDataIsUseSubjectKeyIdentifier Fail")
        if rv==0:
            return False
        else:
            return True
    
    def _signeddata_set_default_include_cert_option(self,option):
        rv=self._handle.NetcaPKIConfigSignedDataSetIncludeCertOption(option)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKIConfigSignedDataSetIncludeCertOption Fail",rv)
    
    def _signeddata_get_default_include_cert_option(self):
        option=self._handle.NetcaPKIConfigSignedDataGetIncludeCertOption()
        if option==-1:
            raise NetcaCryptoException("NetcaPKIConfigSignedDataGetIncludeCertOption Fail")
        return option
    
    def _new_base64(self,enc,flag):
        handle=self._handle.NetcaPKICryptoNewBase64(enc,flag)
        if handle is None:
            raise NetcaCryptoException("NetcaPKICryptoNewBase64 Fail")
        return handle
    
    def _free_base64(self,handle):
        self._handle.NetcaPKICryptoFreeBase64(handle)
    
    def _base64_update(self,handle,data):
        value=c_void_p()
        value_len=c_int()
        rv=self._handle.NetcaPKICryptoBase64Update(handle,bytes(data),len(data),byref(value),byref(value_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKICryptoBase64Update Fail",rv)
        ret=Interop._to_bytes(value,value_len)
        self._handle.NetcaPKICryptoFreeMemory(value)
        return ret
    
    def _base64_final(self,handle):
        value=c_void_p()
        value_len=c_int()
        rv=self._handle.NetcaPKICryptoBase64Final(handle,byref(value),byref(value_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKICryptoBase64Final Fail",rv)
        ret=Interop._to_bytes(value,value_len)
        self._handle.NetcaPKICryptoFreeMemory(value)
        return ret
        
    def _base64(self,enc,flag,data):
        value=c_void_p()
        value_len=c_int()
        rv=self._handle.NetcaPKICryptoBase64(enc,flag,bytes(data),len(data),byref(value),byref(value_len))
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            raise NetcaCryptoException("NetcaPKICryptoBase64 Fail",rv)
        ret=Interop._to_bytes(value,value_len)
        self._handle.NetcaPKICryptoFreeMemory(value)
        return ret

    def _generate_random(self,len):
        data=self._handle.NetcaPKICryptoAllocMemory(len)
        if data is None:
            raise NetcaCryptoException("NetcaPKICryptoAllocMemory Fail")
        
        rv=self._handle.NetcaPKICryptoGenerateRandom(None,len,data)
        if rv!=NetcaCryptoErrorCode.SUCCESS:
            self._handle.NetcaPKICryptoFreeMemory(data)
            raise NetcaCryptoException("NetcaPKICryptoGenerateRandom Fail",rv) 
        data_len=c_int()
        data_len.value=len
        ret=Interop._to_bytes(data,data_len)
        self._handle.NetcaPKICryptoFreeMemory(data)
        return ret

#全局的Interop对象    
_NetcaCryptoHandle=Interop()

class Hash:
    '''
    Hash类用于进行Hash运算
    Hash类需要释放，可用于with语句
    Hash运算输入和输出都是bytes
    一步计算：Hash.hash
    多步计算：创建Hash对象，多次调用update方法，最后调用final方法获取结果
    '''
    
    #Hash算法
    #MD5算法
    MD5         =   0x1000
    #SHA-1算法
    SHA1        =   0x2000
    #SHA-224算法
    SHA224      =   0x3000
    #SHA-256算法
    SHA256      =   0x4000
    #SHA-384算法
    SHA384      =   0x5000
    #SHA-512算法
    SHA512      =   0x6000
    #SM3算法
    SM3         =   0x7000
    #SHA512/224算法
    SHA512_224  =   0x8000
    #SHA512/256算法
    SHA512_256  =   0x9000
    #SHA3-224算法
    SHA3_224    =   0xA000
    #SHA3-256算法
    SHA3_256    =   0xB000
    #SHA3-384算法
    SHA3_384    =   0xC000
    #SHA3-512算法
    SHA3_512    =   0xD000

    def __init__(self,algo):
        '''
        根据Hash算法构造Hash对象
        参数
            algo：Hash算法,例如:Hash.SHA256
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        self.algo=algo
        self._handle=None
        self._handle=_NetcaCryptoHandle._new_hash(algo)

    def __del__(self):
        '''
            释放Hash对象
        '''
        _NetcaCryptoHandle._free_hash(self._handle)
        self._handle=None

    free=__del__
    
    def __enter__(self):
        return self
    
    def __exit__(self, exc_type, exc_val, exc_tb):
        self.free()
        return False
    
    def update(self,data):
        '''
        输入数据进行Hash，可以多次调用
        参数
            data：bytes类型，要进行Hash的数据
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._hash_update(self._handle,data)

    def final(self):
        '''
        结束Hash运算，得到Hash值
        返回值
            bytes类型，成功返回Hash值
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._hash_final(self._handle)

    digest=final

    @staticmethod
    def hash(algo,data):
        '''
        一步完成Hash运算
        参数
            algo：Hash算法，例如:Hash.SHA256
            data：bytes类型，要进行Hash的数据
        返回值
            bytes类型，成功返回Hash值
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        hashValue=None
        with Hash(algo) as hashObj:
            hashObj.update(data)
            hashValue=hashObj.final()
        return hashValue


class Certificate:
    '''
    Certificate类表示一个X.509公钥证书。Certificate类可以保护附加相应的密钥信息，这时它可以用于签名和解密
    Certificate类需要释放，可用于with语句
    '''
    
    #版本号
    #版本1
    V1         =   0
    #版本2
    V2         =   1
    #版本3
    V3         =   2

    #属性类型
    #整数类型的属性
    ATTRIBUTE_TYPE_INT                      =1
    #字符串类型的属性
    ATTRIBUTE_TYPE_SINGLE_VALUE_STRING      =2
    #字符串元组类型的属性
    ATTRIBUTE_TYPE_MULTI_VALUE_STRING       =3
    #Hash值类型的属性
    ATTRIBUTE_TYPE_HASH                     =4
    
    #用户证书类型
    #用户加密证书
    USER_CERT_TYPE_ENCRYPT                  =1
    #用户签名证书
    USER_CERT_TYPE_SIGN                     =2
    
    #非对称加密算法
    #PKCS#1 V1.5的RSA加密
    RSA_PKCS1_V1_5_ENC                      =0x10
    #SM2加密
    SM2_ENC                                 =0x40

    #验证证书的标志，或起来使用，可以为0
    #验证证书的作废状态
    VERIFY_FLAG_VERIFY_REVOKE               =1
    #在线验证证书
    VERIFY_FLAG_ONLINE                      =2
    #验证CA证书的作废状态
    VERIFY_FLAG_VERIFY_CACERT_REVOKE        =4
    #使用OCSP
    VERIFY_FLAG_VERIFY_OCSP                 =0x10
    #使用CRL
    VERIFY_FLAG_VERIFY_CRL                  =0x20

    #证书的状态
    #未作废
    STATUS_UNREVOKED                        =1
    #不确定
    STATUS_UNDETERMINED                     =-1
    #已经作废
    STATUS_REVOKED                          =0
    #证书链中的某个CA证书已经作废
    STATUS_CA_REVOKED                       =-2

    def __init__(self,str):
        '''
        根据证书的编码构造Certificate对象
        参数
            str：证书的编码，可以是字符串类型，也可以是bytes
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        self._handle=None
        self._handle=_NetcaCryptoHandle._new_cert(str)
        self._init()
    
    @staticmethod
    def _new_cert(handle):
        if handle is None:
            raise NetcaCryptoException("null handle")
        cert=Certificate.__new__(Certificate)
        cert._handle=cast(handle,c_void_p)
        cert._init()
        return cert

    def _init(self):
        self._der_encode=_NetcaCryptoHandle._get_cert_der_encode(self._handle)
    
    def __del__(self):
        '''
            释放Certificate对象
        '''
        _NetcaCryptoHandle._free_cert(self._handle)
        self._handle=None

    free=__del__

    def __enter__(self):
        return self
    
    def __exit__(self, exc_type, exc_val, exc_tb):
        self.free()
        return False
    
    @staticmethod
    def get_select_cert_policy():
        '''
        获取选择证书的策略。
        返回值
            字符串类型，成功返回选择证书的策略
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._get_select_cert_policy()
    
    @staticmethod
    def set_select_cert_policy(policy):
        '''
        设置选择证书的策略。对select方法有效
        参数
            policy：选择证书的策略，字符串类型。是UTF-8编码的JSON字符串。
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._set_select_cert_policy(policy)
    
    @staticmethod
    def get_filter_cert_condition():
        '''
        获取过滤证书的条件。
        返回值
            字符串类型，成功返回过滤证书的条件
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._get_filter_cert_condition()
    
    @staticmethod
    def set_filter_cert_condition(condition):
        '''
        设置过滤证书的条件。对select方法有效
        参数
            policy：过滤证书的条件，字符串类型。是UTF-8编码的JSON字符串。
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._set_filter_cert_condition(condition)
    
    @staticmethod
    def set_publickey_encrypt_algo(publickey_type,algo):
        '''
        设置公钥加密算法。对encrypt和decrypt方法有效
        参数
            publickey_type：公钥类型，字符串类型。例如："RSA"，"SM2"等。
            algo：公钥加密算法。例如：RSA_PKCS1_V1_5_ENC或SM2_ENC
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._set_publickey_encrypt_algo(publickey_type,algo)
    
    def get_der_encode(self):
        '''
        获取证书的DER编码。
        返回值
            bytes类型，成功返回证书的DER编码
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self._der_encode
        
    def get_pem_encode(self):
        '''
        获取证书的Base64编码。带BEGIN和END头的分行Base64编码
        返回值
            字符串类型，成功返回证书的Base64编码
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._get_cert_pem_encode(self._handle)
    
    def __hash__(self):
        return self._der_encode.__hash__
    
    def __eq__(self,other):
        return self.get_der_encode()==other.get_der_encode()
    
    def get_int_attribute(self,attr_id):
        '''
        获取证书的整数类型的属性
        参数
            attr_id：属性ID，整数类型。
        返回值
            整数类型，成功返回属性ID为attr_id的属性值
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._get_cert_int_attribute(self._handle,attr_id)
    
    def get_string_attribute(self,attr_id):
        '''
        获取证书的字符串类型的属性。如果属性为字符串元组组类型，则返回元组的首元素
        参数
            attr_id：属性ID，整数类型。
        返回值
            字符串类型，成功返回属性ID为attr_id的属性值，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._get_cert_string_attribute(self._handle,attr_id)
        
    def get_stringarray_attribute(self,attr_id):
        '''
        获取证书的字符串元组类型的属性。如果属性为字符串类型，则返回只有一个元素的字符串元组
        参数
            attr_id：属性ID，整数类型。
        返回值
            字符串元组类型，成功返回属性ID为attr_id的属性值，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._get_cert_stringarray_attribute(self._handle,attr_id)
    
    def get_hash_attribute(self,attr_id,hash_algo):
        '''
        获取证书的Hash值类型的属性。
        参数
            attr_id：属性ID，整数类型。
            hash_algo：Hash算法，例如：Hash.SHA256等
        返回值
            bytes类型，成功返回属性ID为attr_id的属性值
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._get_cert_hash_attribute(self._handle,attr_id,hash_algo)
    
    def get_attribute(self,attr_id):
        '''
        获取证书的属性。
        参数
            attr_id：属性ID，整数类型。
        返回值
            整数类型的属性返回整数类型，字符串类型的属性返回字符串类型，字符串元组类型的属性返回字符串元组类型，成功返回属性ID为attr_id的属性值
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        attr_type=Certificate.get_attribute_type(attr_id)
        if attr_type==ATTRIBUTE_TYPE_INT:
            return self.get_int_attribute(attr_id)
        elif attr_type==ATTRIBUTE_TYPE_SINGLE_VALUE_STRING:
            return self.get_string_attribute(attr_id)
        elif attr_type==ATTRIBUTE_TYPE_MULTI_VALUE_STRING:
            return self.get_stringarray_attribute(attr_id)
        else:
            raise NetcaCryptoException("bad attr_id")
    
    @staticmethod
    def get_attribute_type(attr_id):
        '''
        获取证书属性的类型。
        参数
            attr_id：属性ID，整数类型。
        返回值
            成功返回属性ID为attr_id的属性类型，例如：ATTRIBUTE_TYPE_INT
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._get_cert_attribute_type(attr_id)
    
    def get_c(self):
        '''
        获取证书主体的C的值
        返回值
            字符串类型，成功返回主体的C，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(17)
    
    def get_cn(self):
        '''
        获取证书主体的CN的值
        返回值
            字符串类型，成功返回主体的CN，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(20)
    
    def get_all_cn(self):
        '''
        获取证书主体的CN的值
        返回值
            字符串元组类型，成功返回主体的CN，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_stringarray_attribute(20)
        
    def get_st(self):
        '''
        获取证书主体的ST的值
        返回值
            字符串类型，成功返回主体的ST，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(39)
    
    def get_l(self):
        '''
        获取证书主体的L的值
        返回值
            字符串类型，成功返回主体的L，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(40)
        
    def get_o(self):
        '''
        获取证书主体的O的值
        返回值
            字符串类型，成功返回主体的O，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(18)
    
    def get_ou(self):
        '''
        获取证书主体的OU的值
        返回值
            字符串类型，成功返回主体的OU，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(19)
    
    def get_all_ou(self):
        '''
        获取证书主体的OU的值
        返回值
            字符串元组类型，成功返回主体的OU，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_stringarray_attribute(19)
        
    def get_dns(self):
        '''
        获取证书的DNS
        返回值
            字符串元组类型，成功返回DNS，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_stringarray_attribute(60)
    
    def get_email(self):
        '''
        获取证书的Email地址
        返回值
            字符串元组类型，成功返回Email地址，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_stringarray_attribute(21)
        
    def get_ext_keyusage(self):
        '''
        获取证书的扩展密钥用法
        返回值
            字符串元组类型，成功返回扩展密钥用法，每个元素是一个扩展密钥用法OID，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_stringarray_attribute(62)
        
    def get_ip(self):
        '''
        获取证书的IP
        返回值
            字符串元组类型，成功返回IP，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_stringarray_attribute(59)
    
    def get_issuer(self,reverse=True):
        '''
        获取证书的颁发者
        参数
            reverse：是否反序，布尔类型，默认为True
        返回值
            字符串类型，成功返回颁发者名
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        if reverse:
            return self.get_string_attribute(97)
        else:
            return self.get_string_attribute(8)
    
    def get_subject(self,reverse=True):
        '''
        获取证书的主体
        参数
            reverse：是否反序，布尔类型，默认为True
        返回值
            字符串类型，成功返回主体名
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        if reverse:
            return self.get_string_attribute(98)
        else:
            return self.get_string_attribute(15)
    
    def get_issuer_c(self):
        '''
        获取证书的颁发者的C的值
        返回值
            字符串类型，成功返回颁发者的C，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(10)
    
    def get_issuer_st(self):
        '''
        获取证书的颁发者的ST的值
        返回值
            字符串类型，成功返回颁发者的ST，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(37)
        
    def get_issuer_l(self):
        '''
        获取证书的颁发者的L的值
        返回值
            字符串类型，成功返回颁发者的L，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(38)
    
    def get_issuer_o(self):
        '''
        获取证书的颁发者的O的值
        返回值
            字符串类型，成功返回颁发者的O，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(11)
    
    def get_issuer_ou(self):
        '''
        获取证书的颁发者的OU的值
        返回值
            字符串类型，成功返回颁发者的OU，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(12)
        
    def get_all_issuer_ou(self):
        '''
        获取证书的颁发者的OU的值
        返回值
            字符串元组类型，成功返回颁发者的OU，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_stringarray_attribute(12)
    
    def get_issuer_cn(self):
        '''
        获取证书的颁发者的CN的值
        返回值
            字符串类型，成功返回颁发者的CN，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(13)
    
    def get_all_issuer_cn(self):
        '''
        获取证书的颁发者的CN的值
        返回值
            字符串元组类型，成功返回颁发者的CN，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_stringarray_attribute(13)
    
    def get_keyusage(self):
        '''
        获取证书的密钥用法
        返回值
            布尔元组类型，成功返回证书的密钥用法
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        ku=self.get_int_attribute(6)
        list=[]
        for i in range(9):
            if (ku&1)!=0:
                list.append(True)
            else:
                list.append(False)
            ku=ku>>1
        return tuple(list)
    
    def get_serialnumber(self):
        '''
        获取证书的序列号
        返回值
            字符串类型，成功返回证书的序列号
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(33)
        
    def get_dec_serialnumber(self):
        '''
        获取证书的十进制表示的序列号
        返回值
            字符串类型，成功返回证书的十进制表示的序列号
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(32)
    
    def get_subject_publickey_identifier(self):
        '''
        获取证书的主体密钥标识符
        返回值
            字符串类型，成功返回HEX编码的主体密钥标识符，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(66)
    
    def get_upn(self):
        '''
        获取证书的UPN
        返回值
            字符串类型，成功返回UPN，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(36)
        
    def computeThumbprint(self,hash_algo):
        '''
        计算证书的微缩图
        参数
            hash_algo：Hash算法，整数类型
        返回值
            bytes类型，成功返回证书的微缩图
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_hash_attribute(44,hash_algo)
        
    def match(self,expr):
        '''
        判断证书是否符合要求
        参数
            expr：条件表达式，字符串类型
        返回值
            布尔类型，匹配返回True，不匹配返回False
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._cert_match(self._handle,expr)
        
    @staticmethod
    def select(cert_type,expr=None):
        '''
        选择证书
        参数
            cert_type：证书的类型或者选择条件，字符串类型
            expr：过滤条件表达式，字符串类型，默认为None
        返回值
            Certificate类型，成功返回选择的证书，没有证书返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        cert= _NetcaCryptoHandle._select_cert(cert_type,expr)
        if cert is None:
            return None
        return Certificate._new_cert(cert)
    
    def get_string_extension_value(self,oid):
        '''
        获取字符串类型的扩展的值
        参数
            oid：扩展的OID，字符串类型
        返回值
            字符串类型，成功返回扩展的值。不存在该扩展返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._get_cert_string_extension_value(self._handle,oid)
    
    def get_extension_value(self,oid):
        '''
        获取扩展的值
        参数
            oid：扩展的OID，字符串类型
        返回值
            字典类型，成功返回扩展的值和关键性。"critical"的值为扩展的关键性，布尔类型。"extension_value""的值为扩展值，bytes类型。不存在该扩展返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._get_cert_extension_value(self._handle,oid)
    
    @staticmethod
    def get_user_cert(type,condition=None):
        '''
        获取用户的证书
        参数
            type：用户的证书类型，USER_CERT_TYPE_ENCRYPT或者USER_CERT_TYPE_SIGN
            condition：过滤的条件，字符串类型，默认为None
        返回值
            Certificate类型，成功返回用户的证书。没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        cert= _NetcaCryptoHandle._get_user_cert(type,condition)
        if cert is None:
            return None
        
        return Certificate._new_cert(cert)
        
    def encrypt(self,clear):
        '''
        使用证书的公钥加密
        参数
            clear：明文,bytes类型
        返回值
            bytes类型，成功返回密文
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._cert_encrypt(self._handle,clear)
    
    def decrypt(self,cipher):
        '''
        使用证书对应的私钥解密
        参数
            cipher：密文,bytes类型
        返回值
            bytes类型，成功返回明文
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._cert_decrypt(self._handle,cipher)
        
    def sign(self,tbs):
        '''
        使用证书对应的私钥进行签名
        参数
            tbs：要签名的数据,bytes类型
        返回值
            bytes类型，成功返回签名值
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._cert_sign(self._handle,tbs)
    
    def verify_signature(self,tbs,signature):
        '''
        使用证书的公钥验证签名
        参数
            tbs：要签名的数据,bytes类型
            signature：签名值，bytes类型
        返回值
            布尔类型，成功返回True,失败返回False
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._cert_verify_signature(self._handle,tbs,signature)
    
    def get_privatekey(self,pwd):
        '''
        获取证书的对应的私钥
        参数
            pwd：密码,字符串类型
        抛出
            NetcaCryptoException：出错或没有私钥抛出NetcaCryptoException异常
        '''
        keypair=_NetcaCryptoHandle._cert_get_keypair(self._handle,pwd)
        if keypair is None:
            raise NetcaCryptoException("no private key or pwd error")
        _NetcaCryptoHandle._free_keypair(keypair)

    def get_publickey_bits(self):
        '''
        获取证书的公钥的位数
        返回值
            整数类型，公钥的位数
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_int_attribute(5)

    def get_display_name(self):
        '''
        获取证书主体的显示名
        返回值
            字符串类型，成功返回主体的显示名
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(16)
    
    def get_issuer_display_name(self):
        '''
        获取证书颁发者的显示名
        返回值
            字符串类型，成功返回颁发者的显示名
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(9)
    
    def get_notbefore(self):
        '''
        获取证书有效期的开始时间
        返回值
            字符串类型，成功返回证书有效期的开始时间
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(30)

    def get_notafter(self):
        '''
        获取证书有效期的结束时间
        返回值
            字符串类型，成功返回证书有效期的结束时间
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(31)
        
    def build_certpath(self):
        '''
        构造证书链。
        返回值
            Certificate元组类型，成功返回证书链。第0个证书句柄是根证书对象，最后一个证书句柄是要构造证书链的那张证书对象，中间的第i个证书对象是第i+1个证书的颁发者的证书对象。
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        cert_handle_list=_NetcaCryptoHandle._get_certpath(self._handle)
        list=[]
        count=len(cert_handle_list)
        i=0
        while i<count:
            try:
                cert=Certificate._new_cert(cert_handle_list[i])
            except Exception as e:
                j=0
                while j<i:
                    list[i].free()
                    j=j+1
                
                while j<count:
                    _NetcaCryptoHandle._free_cert(cert_handle_list[j])
                    j=j+1
                raise e
            
            list.append(cert)
            i=i+1
        
        return tuple(list)

    def verify(self,flag,time=None):
        '''
        验证证书。
        参数
            flag: 验证的标识，整数类型
            time: 验证的时间，字符串类型。可选，默认为None
        返回值
            字典类型，成功返回证书的状态。status表示证书的状态，整数类型；revoked_time表示作废时间（可选），字符串类型；revoked_reason表示作废原因（可选），整数类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._verify_cert(self._handle,flag,time)

    def verify_by_ocsp(self,url,ocsp_cert=None):
        '''
        使用OCSP验证证书的作废状态。
        参数
            url: OCSP服务器的URL，字符串类型
            ocsp_cert: OCSP证书，Certificate类型。可选，默认为None。只有直接信任模式才需要
        返回值
            字典类型，成功返回证书的状态。status表示证书的状态，整数类型；revoked_time表示作废时间（可选），字符串类型；revoked_reason表示作废原因（可选），整数类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        if ocsp_cert is None:
            return _NetcaCryptoHandle._verify_cert_by_ocsp(self._handle,url,None)
        else:
            return _NetcaCryptoHandle._verify_cert_by_ocsp(self._handle,url,ocsp_cert._handle)

class EnvelopedData:
    '''
    EnvelopedData类用于进行数字信封加密运算或者解开数字信封
    EnvelopedData类需要释放，可用于with语句
    '''

    #对称加密算法
    #DES算法
    DES_CBC         =1
    #RC2算法
    RC2_CBC         =2
    #3DES算法
    TDES_CBC        =3
    #128位的AES算法
    AES128_CBC      =4
    #192位的AES算法
    AES192_CBC      =5
    #256位的AES算法
    AES256_CBC      =6
    #SSF33算法，需要特定的硬件加密设备支持
    SSF33_CBC       =7
    #SM1算法，需要特定的硬件加密设备支持
    SM1_CBC         =8
    #SM4算法
    SM4_CBC         =9
    #RC4算法
    RC4             =10

    #使用主体密钥标识符
    USEKEYID        =1
    
    def __init__(self,enc):
        '''
        构造EnvelopedData对象
        参数
            enc：True表示进行加密，Fasle表示进行解密。布尔类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        self._handle=None
        if type(enc)!=type(True):
            raise NetcaCryptoException("enc not boolean type")
        self._handle=_NetcaCryptoHandle._new_envelopeddata(enc)
    
    @staticmethod
    def _new_envelopeddata(handle):
        if handle is None:
            raise NetcaCryptoException("null handle")
        env=EnvelopedData.__new__(EnvelopedData)
        env._handle=cast(handle,c_void_p)
        return env
    
    def __del__(self):
        '''
            释放EnvelopedData对象
        '''
        _NetcaCryptoHandle._free_envelopeddata(self._handle)
        self._handle=None
    
    free=__del__
    
    def __enter__(self):
        return self
    
    def __exit__(self, exc_type, exc_val, exc_tb):
        self.free()
        return False
    
    @staticmethod
    def encrypt_data(cert,clear):
        '''
        构造数字信封
        参数
            cert：加密证书。Certificate类型
            clear：明文。bytes类型
        返回值
            bytes类型，成功返回数字信封的编码
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._envelopeddata_encrypt(cert._handle,clear)
    
    @staticmethod
    def decrypt_data(cipher):
        '''
        解开数字信封
        参数
            cipher：数字信封的编码。bytes类型
        返回值
            bytes类型，成功返回解密得到的明文
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._envelopeddata_decrypt(cipher)

    @staticmethod
    def set_decrypt_cert(cert):
        '''
        设置解密证书，供decrypt_data使用
        参数
            cert：解密证书，必须带有私钥。Certificate类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._envelopeddata_set_decrypt_cert(cert._handle)
    
    @staticmethod
    def new(enc):
        '''
        根据配置信息创建EnvelopedData对象
        参数
            enc：True表示进行加密，Fasle表示进行解密。布尔类型
        返回值
            EnvelopedData类型，成功返回EnvelopedData对象
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        if type(enc)!=type(True):
            raise NetcaCryptoException("enc not boolean type")
        env=None
        if enc:
            env=_NetcaCryptoHandle._envelopeddata_new_encrypt_handle()
        else:
            env=_NetcaCryptoHandle._envelopeddata_new_decrypt_handle()
        return EnvelopedData._new_envelopeddata(env)
    
    @staticmethod
    def set_default_encrypt_algo(algo):
        '''
        设置默认的对称加密算法
        参数
            algo：对称加密算法，比如：AES128_CBC等
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._envelopeddata_set_default_enc_algo(algo)
    
    @staticmethod
    def get_default_encrypt_algo():
        '''
        获取默认的对称加密算法
        返回值
            成功返回默认的对称加密算法，比如：AES128_CBC等
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._envelopeddata_get_default_enc_algo()
    
    @staticmethod
    def set_default_use_subject_key_id(value):
        '''
        设置默认是否使用主体密钥标识符
        参数
            value：为真表示使用主体密钥标识符，为假表示不使用。布尔类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._envelopeddata_set_default_use_subject_key_id(value)
    
    @staticmethod
    def is_default_use_subject_key_id():
        '''
        判断默认是否使用主体密钥标识符
        返回值
            布尔类型，如果默认使用主体密钥标识符返回True，否则返回False。
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._envelopeddata_is_default_use_subject_key_id()
    
    def decrypt_postcheck(self):
        '''
        解密后检查
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._envelopeddata_decrypt_postcheck(self._handle)
    
    def set_encrypt_algo(self,algo):
        '''
        设置对称加密算法
        参数
            algo：对称加密算法，比如：AES128_CBC等
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._envelopeddata_set_enc_algo(self._handle,algo)
    
    def add_encrypt_cert(self,cert,flag=0):
        '''
        添加加密证书
        参数
            cert：加密证书，Certificate类型
            flag：标识，如果为USEKEYID则是使用主体密钥标识符。默认为0
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._envelopeddata_add_cert(self._handle,cert._handle,flag)
    
    def add_decrypt_cert(self,cert):
        '''
        添加可能的解密证书
        参数
            cert：解密证书，必须带私钥，Certificate类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._envelopeddata_add_cert(self._handle,cert._handle,0)
        
    def set_int_attribute(self,attr_type,attr_value):
        '''
        设置整数类型的属性
        参数
            attr_type：属性ID，整数类型
            attr_value：属性值，整数类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._envelopeddata_set_int_attribute(self._handle,attr_type,attr_value)
    
    def set_sm2q7(self,value):
        '''
        设置是否使用SM2的Q7格式
        参数
            value：为真表示使用SM2的Q7格式，为假表示不使用，布尔类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        attr_value=0
        if value:
            attr_value=1
        self.set_int_attribute(3,attr_value)
        self.set_int_attribute(4,attr_value)
    
    def set_use_contentinfo(self,value):
        '''
        设置是否使用ContentInfo封装
        参数
            value：为真表示使用ContentInfo封装，为假表示不使用，布尔类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        attr_value=0
        if value:
            attr_value=1
        self.set_int_attribute(2,attr_value)
    
    def set_string_attribute(self,attr_type,attr_value):
        '''
        设置字符串类型的属性
        参数
            attr_type：属性ID，整数类型
            attr_value：属性值，字符串类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._envelopeddata_set_string_attribute(self._handle,attr_type,attr_value)
    
    def encrypt(self,clear):
        '''
        一步完成加密
        参数
            clear：明文，bytes类型
        返回值
            bytes类型。成功返回数字信封的编码
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._envelopeddata_encrypt_onestep(self._handle,clear)
    
    def encrypt_init(self):
        '''
        开始进行加密
        返回值
            bytes类型。成功返回数字信封的编码的开始部分
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._envelopeddata_encrypt_init(self._handle)
    
    def encrypt_update(self,clear):
        '''
        输入明文，进行加密。可多次调用
        参数
            clear：明文，bytes类型
        返回值
            bytes类型。成功返回加密得到数字信封的部分编码
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._envelopeddata_encrypt_update(self._handle,clear)
        
    def encrypt_final(self):
        '''
        结束加密
        返回值
            bytes类型。成功返回数字信封的编码的最后部分
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._envelopeddata_encrypt_final(self._handle)
    
    def decrypt(self,cipher):
        '''
        进行数字信封解密
        参数
            cipher：数字信封的编码，bytes类型
        返回值
            bytes类型。成功返回解密得到的明文
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._envelopeddata_decrypt_onestep(self._handle,cipher)
    
    def decrypt_init(self):
        '''
        开始进行数字信封解密
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._envelopeddata_decrypt_init(self._handle)
    
    def decrypt_update(self,cipher):
        '''
        输入数字信封编码进行解密。可以多次调用
        参数
            cipher：数字信封的编码，bytes类型
        返回值
            bytes类型。成功返回解密得到的部分明文
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._envelopeddata_decrypt_update(self._handle,cipher)
        
    def decrypt_final(self):
        '''
        结束数字信封解密
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._envelopeddata_decrypt_final(self._handle)
    
    def get_encrypt_algo(self):
        '''
        获取数字信封使用的对称加密算法
        返回值
            成功返回数字信封使用的对称加密算法，比如：AES128_CBC等
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._envelopeddata_get_enc_algo(self._handle)
    
    def get_decrypt_cert(self):
        '''
        获取解密证书
        返回值
            Certificate类型，成功返回解密证书，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        cert=_NetcaCryptoHandle._envelopeddata_get_decrypt_cert(self._handle)
        if cert is None:
            return None
        return Certificate._new_cert(cert)

    def get_recipientinfosencode(self):
        '''
        获取接收者信息的编码
        返回值
            bytes类型。成功返回接收者信息的编码，没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._envelopeddata_get_recipientinfosencode(self._handle)
             
    
    def is_contentinfo(self):
        '''
        判断是否ContentInfo封装
        返回值
            布尔类型，如果是ContentInfo封装返回True，否则返回False
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._envelopeddata_is_contentinfo(self._handle)

class SignedData:
    '''
    SignedData类用于进行SignedData签名运算或者验证SignedData签名
    SignedData类需要释放，可用于with语句
    '''

    #签名算法
    #SHA-1WithRSAEncryption
    SHA1WITHRSA         =2
    #SHA224WithRSAEncryption
    SHA224WITHRSA       =3
    #SHA256WithRSAEncryption
    SHA256WITHRSA       =4
    #SHA384WithRSAEncryption
    SHA384WITHRSA       =5
    #SHA512WithRSAEncryption
    SHA512WITHRSA       =6
    #ECDSAWithSHA-1
    ECDSAWITHSHA1       =16
    #ECDSAWithSHA224
    ECDSAWITHSHA224     =17
    #ECDSAWithSHA256
    ECDSAWITHSHA256     =18
    #ECDSAWithSHA384
    ECDSAWITHSHA384     =19
    #ECDSAWithSHA512
    ECDSAWITHSHA512     =20
    #SM3WithSM2
    SM3WITHSM2          =25
    #SHA512/224WithSM2Encryption
    SHA512_224WITHRSA   =34
    #SHA512/256WithSM2Encryption
    SHA512_256WITHRSA   =35
    #SHA3-224WithSM2Encryption
    SHA3_224WITHRSA     =36
    #SHA3-256WithSM2Encryption
    SHA3_256WITHRSA     =37
    #SHA3-384WithSM2Encryption
    SHA3_384WITHRSA     =38
    #SHA3-512WithSM2Encryption
    SHA3_512WITHRSA     =39
    #ECDSAWithSHA3-224
    ECDSAWITHSHA3_224   =40
    #ECDSAWithSHA3-256
    ECDSAWITHSHA3_256   =41
    #ECDSAWithSHA3-384
    ECDSAWITHSHA3_384   =42
    #ECDSAWithSHA3-512
    ECDSAWITHSHA3_512   =43
    
    #包含证书的选项
    #不包含证书
    INCLUDE_CERT_OPTION_NONE                =1
    #包含签名证书本身
    INCLUDE_CERT_OPTION_SELF                =2
    #尽量包含整个证书路径
    INCLUDE_CERT_OPTION_CERTPATH            =3
    #尽量包含整个证书路径和根证书
    INCLUDE_CERT_OPTION_CERTPATHWITHROOT    =4
    
    def __init__(self,sign):
        '''
        构造SignedData对象
        参数
            sign：True表示进行签名，Fasle表示验证签名。布尔类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        self._handle=None
        if type(sign)!=type(True):
            raise NetcaCryptoException("sign not boolean type")
        self._handle=_NetcaCryptoHandle._new_signeddata(sign)
    
    @staticmethod
    def _new_signeddata(handle):
        if handle is None:
            raise NetcaCryptoException("null handle")
        sign=SignedData.__new__(SignedData)
        sign._handle=cast(handle,c_void_p)
        return sign
    
    def __del__(self):
        '''
        是否SignedData对象
        '''
        _NetcaCryptoHandle._free_signeddata(self._handle)
        self._handle=None
    
    free=__del__
    
    def __enter__(self):
        return self
    
    def __exit__(self, exc_type, exc_val, exc_tb):
        self.free()
        return False
    
    @staticmethod
    def sign_data(cert,detached,tbs):
        '''
        进行SignedData签名
        参数
            cert：签名证书，必须带私钥。Certificate类型
            detached：True表示不带原文，Fasle表示带原文。布尔类型
            tbs：原文。bytes类型
        返回值
            bytes类型。成功返回SignedData的编码
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._signeddata_sign(cert._handle,detached,tbs)
    
    @staticmethod
    def sign_with_timestamp(cert,detached,tbs):
        '''
        进行带时间戳的SignedData签名
        参数
            cert：签名证书，必须带私钥。Certificate类型
            detached：True表示不带原文，Fasle表示带原文。布尔类型
            tbs：原文。bytes类型
        返回值
            元组类型。共两个元素，第0个是bytes，表示SignedData的编码，第1个是字符串，表示时间戳时间
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._signeddata_sign_with_timestamp(cert._handle,detached,tbs)
    
    @staticmethod
    def verify_data(tbs,sign_value,cert=None):
        '''
        验证SignedData签名
        参数
            tbs：原文。bytes类型
            sign_value：SignedData的编码。bytes类型
            cert：可能的签名证书。Certificate类型。默认为None
        返回值
            Certificate类型。成功返回签名证书
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        cert_handle=None
        if cert is None:
            cert_handle=_NetcaCryptoHandle._signeddata_verify(tbs,sign_value,None)
        else:
            cert_handle=_NetcaCryptoHandle._signeddata_verify(tbs,sign_value,cert._handle)
        return Certificate._new_cert(cert_handle)
    
    @staticmethod
    def is_signeddata(data):
        '''
        判断是否SignedData签名
        参数
            data：SignedData的前面部分编码。bytes类型
        返回值
            布尔类型。如果可能是SignedData的前面部分的编码返回True，否则返回False
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        list=_NetcaCryptoHandle._signeddata_maybe(data)
        return list[0]
    
    @staticmethod
    def is_detached_signeddata(data):
        '''
        判断是否不带原文的SignedData签名
        参数
            data：SignedData的前面部分编码。bytes类型
        返回值
            布尔类型。如果可能是不带原文的SignedData的前面部分的编码返回True，否则返回False
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        list=_NetcaCryptoHandle._signeddata_maybe(data)
        return list[1]
    
    @staticmethod
    def new_verify_object():
        '''
        根据配置信息创建验证签名的SignedData对象
        返回值
            SignedData类型，成功返回SignedData对象
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        sign_handle=_NetcaCryptoHandle._signeddata_new_verify_handle()
        return SignedData._new_signeddata(sign_handle)
    
    def apply_sign_config(self):
        '''
        根据配置信息设置SignedData对象的相关配置。必须在set_signcert方法之后调用
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._signeddata_apply_sign_config(self._handle)
    
    @staticmethod
    def set_defult_include_cert_option(cert_option):
        '''
        设置默认的包含证书的选项
        参数
            cert_option：包含证书的选项。比如：INCLUDE_CERT_OPTION_CERTPATH等
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._signeddata_set_defult_include_cert_option(cert_option)
    
    @staticmethod
    def get_defult_include_cert_option():
        '''
        获取默认的包含证书的选项
        返回值
            成功返回默认的包含证书的选项。比如：INCLUDE_CERT_OPTION_CERTPATH等
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._signeddata_get_defult_include_cert_option()
    
    def verify_postcheck(self):
        '''
        验证后检查
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._signeddata_verify_postcheck(self._handle)
    
    def sign_onestep(self,tbs):
        '''
        一步完成签名
        参数
            tbs：原文，bytes类型
        返回值
            bytes类型。成功返回SignedData的编码
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._signeddata_sign_onestep(self._handle,tbs)
    
    def cosign(self):
        '''
        多人签名
        返回值
            bytes类型。成功返回多人签名的SignedData的编码
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._signeddata_cosign(self._handle)

    def countsign(self,index,signalgo,cert):
        '''
        联署签名
        参数
            index：索引值，从0算起。整数类型。
            signalgo：签名算法
            cert：签名证书，Certficate类型           
        返回值
            bytes类型。成功返回联署签名的SignedData的编码
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._signeddata_countsign(self._handle,index,signalgo,cert._handle)

    def sign_init(self):
        '''
        开始进行签名
        返回值
            bytes类型。成功返回SignedData的开始部分的编码
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._signeddata_sign_init(self._handle)
    
    def sign_update(self,tbs):
        '''
        输入原文，进行签名。可以多次调用
        参数
            tbs：原文，bytes类型
        返回值
            bytes类型。成功返回SignedData的部分编码
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._signeddata_sign_update(self._handle,tbs)
    
    def sign_final(self):
        '''
        结束签名
        返回值
            bytes类型。成功返回SignedData的最后部分的编码
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._signeddata_sign_final(self._handle)
    
    def sign_with_timestamp_final(self,tsaurl,hash_algo):
        '''
        结束带时间戳的签名
        参数
            tsaurl：时间戳的URL，字符串类型
            hash_algo：时间戳的Hash算法，比如：Hash.SHA1等
        返回值
            bytes类型。成功返回SignedData的最后部分的编码
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._signeddata_sign_with_timestamp_final(self._handle,tsaurl,hash_algo)
    
    def sign_with_timestamp_onestep(self,tbs,tsaurl,hash_algo):
        '''
        一步完成带时间戳的签名
        参数
            tbs：原文，bytes类型
            tsaurl：时间戳的URL，字符串类型
            hash_algo：时间戳的Hash算法，比如：Hash.SHA1等
        返回值
            bytes类型。成功返回SignedData的编码
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._signeddata_sign_with_timestamp_onestep(self._handle,tbs,tsaurl,hash_algo)
    
    def attach_timestamp(self):
        '''
        附加时间戳
        返回值
            bytes类型。成功返回附加时间戳后的SignedData的编码
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._signeddata_attach_timestamp(self._handle)
    
    def attach_signature_timestamp(self,tsaurl,hash_algo,index=0):
        '''
        附加时间戳
        参数
            tsaurl：时间戳的URL，字符串类型
            hash_algo：Hash算法，例如：Hash.SHA256
            index:索引值，整数类型。默认为0
        返回值
            bytes类型。成功返回附加时间戳后的SignedData的编码
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._signeddata_attach_signature_timestamp(self._handle,tsaurl,hash_algo,index)
    
    def verify_onestep(self,sign_value):
        '''
        一步完成带原文的SignedData的验证
        参数
            sign_value：带原文的SignedData的编码，bytes类型
        返回值
            bytes类型。成功返回原文
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._signeddata_verify_onestep(self._handle,sign_value)
    
    def verify_init(self):
        '''
        开始带原文的SignedData的验证
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._signeddata_verify_init(self._handle)
    
    def verify_update(self,sign_value):
        '''
        输入SignedData的编码进行验证，可以多次调用
        参数
            sign_value：带原文的SignedData的编码，bytes类型
        返回值
            bytes类型。成功返回部分原文
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._signeddata_verify_update(self._handle,sign_value)
    
    def verify_final(self):
        '''
        结束带原文的SignedData的验证
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._signeddata_verify_final(self._handle)
        
    def detached_verify(self,tbs,sign_value):
        '''
        一步完成不带原文的SignedData的验证
        参数
            tbs：原文，bytes类型
            sign_value：不带原文的SignedData的编码，bytes类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._signeddata_detached_verify(self._handle,tbs,sign_value)
    
    def detached_verify_init(self,sign_value):
        '''
        开始不带原文的SignedData的验证
        参数
            sign_value：不带原文的SignedData的编码，bytes类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._signeddata_detached_verify_init(self._handle,sign_value)
    
    def detached_verify_update(self,tbs):
        '''
        输入原文，进行不带原文的SignedData的验证。可以多次调用
        参数
            tbs：原文，bytes类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._signeddata_detached_verify_update(self._handle,tbs)
    
    def detached_verify_final(self):
        '''
        结束不带原文的SignedData的验证
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._signeddata_detached_verify_final(self._handle)
    
    def verify_timestamp(self,index=0,cert=None):
        '''
        验证时间戳
        参数
            index：索引值，从0算起。整数类型。默认值为0
            cert：时间戳证书。Certificate类型。默认值为None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        if cert is None:
            _NetcaCryptoHandle._signeddata_verify_timestamp(self._handle,index,cert)
        else:
            _NetcaCryptoHandle._signeddata_verify_timestamp(self._handle,index,cert._handle)

    def verify_countersignature(self,index=0,countersignindex=0,cert=None):
        '''
        验证时间戳
        参数
            index：索引值，从0算起。整数类型。默认值为0
            countersignindex:联署签名索引值，从0算起。整数类型。默认值为0
            cert：签名证书。Certificate类型。默认值为None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        if cert is None:
            _NetcaCryptoHandle._signeddata_verify_countersignature(self._handle,index,countersignindex,cert)
        else:
            _NetcaCryptoHandle._signeddata_verify_countersignature(self._handle,index,countersignindex,cert._handle) 
    
    def set_int_attribute(self,attr_id,attr_value,index):
        '''
        设置整数类型的属性
        参数
            attr_id：属性ID，整数类型
            attr_value：属性值，整数类型
            index：索引号，从0算起，整数类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._signeddata_set_int_attribute(self._handle,attr_id,attr_value,index)
    
    def set_string_attribute(self,attr_id,attr_value,index):
        '''
        设置字符串类型的属性
        参数
            attr_id：属性ID，整数类型
            attr_value：属性值，字符串类型
            index：索引号，从0算起，整数类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._signeddata_set_string_attribute(self._handle,attr_id,attr_value,index)
    
    def set_detached(self,detached):
        '''
        设置是否带原文
        参数
            detached：为True表示不带原文，为False表示带原文，布尔类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        detached_value=0
        if detached:
            detached_value=1
        self.set_int_attribute(2,detached_value,-1)
    
    def set_sign_algo(self,sign_algo,index=0):
        '''
        设置签名算法
        参数
            sign_algo：签名算法，比如:SHA256WITHRSA
            index：索引号，从0算起。整数类型。默认为0
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        self.set_int_attribute(3,sign_algo,index)
    
    def set_use_signing_time(self,value,index=0):
        '''
        设置是否使用签名时间属性
        参数
            value：为真表示使用签名时间，为假不使用。布尔类型
            index：索引号，从0算起。整数类型。默认为0
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        attr_value=0
        if value:
            attr_value=1
        self.set_int_attribute(4,attr_value,index)
        
    def set_use_contentinfo(self,value):
        '''
        设置是否使用ContentInfo封装
        参数
            value：为真表示使用ContentInfo封装，为假不使用。布尔类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        attr_value=0
        if value:
            attr_value=1
        self.set_int_attribute(5,attr_value,-1)
    
    def set_use_subject_key_id(self,value,index=0):
        '''
        设置是否使用主体密钥标识符
        参数
            value：为真表示使用主体密钥标识符，为假不使用。布尔类型
            index：索引号，从0算起。整数类型。默认为0
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        attr_value=0
        if value:
            attr_value=1
        self.set_int_attribute(6,attr_value,index)
    
    def set_include_cert_option(self,cert_option):
        '''
        设置包含证书的选项
        参数
            cert_option：包含证书的选项。比如：INCLUDE_CERT_OPTION_CERTPATH
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        self.set_int_attribute(7,cert_option,-1)
    
    def keep_tbs(self):
        '''
        保存原文
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        self.set_int_attribute(8,1,-1)
    
    def set_use_signing_cert_attribute(self,value,index=0):
        '''
        设置是否使用签名证书属性
        参数
            value：为真表示使用签名证书属性，为假不使用。布尔类型
            index：索引号，从0算起。整数类型。默认为0
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        attr_value=0
        if value:
            attr_value=1
        self.set_int_attribute(9,attr_value,index)
    
    def set_signing_cert_v2_attribute_hash_algo(self,hash_algo,index=0):
        '''
        设置使用V2版签名证书属性的Hash算法
        参数
            hash_algo：V2版签名证书属性的Hash算法。比如：Hash.SHA256
            index：索引号，从0算起。整数类型。默认为0
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        self.set_int_attribute(10,hash_algo,index)
    
    def set_content_oid(self,oid):
        '''
        设置原文的OID
        参数
            oid：原文的OID。字符串类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        self.set_string_attribute(13,oid,-1)
    
    def set_verify_validity(self,value):
        '''
        设置是否验证证书的有效期
        参数
            value：为真表示验证证书的有效期，为假不验证。布尔类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        attr_value=0
        if value:
            attr_value=1
        self.set_int_attribute(14,attr_value,-1)
    
    def set_sm2q7(self,value,index=0):
        '''
        设置是否使用SM2的Q7结构
        参数
            value：为真表示使用SM2的Q7结构，为假表示不使用。布尔类型
            index：索引号，从0算起。整数类型。默认为0
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        attr_value=0
        if value:
            attr_value=1
        self.set_int_attribute(23,attr_value,-1)
        self.set_int_attribute(24,attr_value,index)
    
    def set_verify_level(self,verify_level):
        '''
        设置验证级别
        参数
            verify_level：验证级别。整数类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        self.set_int_attribute(41,verify_level,-1)
        
    def get_int_attribute(self,attr_id,index):
        '''
        获取整数类型的属性
        参数
            attr_id：属性ID。整数类型
            index：索引号，从0算起。整数类型。
        返回值
            整数类型。成功返回对应的属性值
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._signeddata_get_int_attribute(self._handle,attr_id,index)
        
    def get_string_attribute(self,attr_id,index):
        '''
        获取字符串类型的属性
        参数
            attr_id：属性ID。整数类型
            index：索引号，从0算起。整数类型。
        返回值
            字符串类型。成功返回对应的属性值
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._signeddata_get_string_attribute(self._handle,attr_id,index)
    
    def get_signer_count(self):
        '''
        获取签名个数
        返回值
            整数类型。成功返回签名个数
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_int_attribute(1,-1)
    
    def is_detached(self):
        '''
        判断是否带原文
        返回值
            布尔类型。如果不带原文返回True，否则返回False
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        rv=self.get_int_attribute(2,-1)
        if rv==0:
            return False
        else:
            return True
    
    def get_sign_algo(self,index=0):
        '''
        获取签名算法
        参数
            index：索引号，从0算起。整数类型。默认为0
        返回值
            整数类型。成功返回签名算法
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_int_attribute(3,index)
    
    def is_contentinfo(self):
        '''
        判断是否ContentInfo封装
        返回值
            布尔类型。如果是ContentInfo封装返回True，否则返回False
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        rv=self.get_int_attribute(5,-1)
        if rv==0:
            return False
        else:
            return True
    
    def has_signing_time(self,index=0):
        '''
        判断是否有签名时间属性
        参数
            index：索引号，从0算起。整数类型。默认为0
        返回值
            布尔类型。如果有签名时间属性返回True，否则返回False
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        rv=self.get_int_attribute(4,index)
        if rv==0:
            return False
        else:
            return True
    
    def is_use_subject_key_id(self,index=0):
        '''
        判断是否使用主体密钥标识符
        参数
            index：索引号，从0算起。整数类型。默认为0
        返回值
            布尔类型。如果使用主体密钥标识符返回True，否则返回False
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        rv=self.get_int_attribute(6,index)
        if rv==0:
            return False
        else:
            return True
    
    def has_signing_cert_attribute(self,index=0):
        '''
        判断是否有签名证书属性
        参数
            index：索引号，从0算起。整数类型。默认为0
        返回值
            布尔类型。如果有签名证书属性返回True，否则返回False
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        rv=self.get_int_attribute(9,index)
        if rv==0:
            return False
        else:
            return True
    
    def get_signing_cert_v2_attribute_hash_algo(self,index=0):
        '''
        获取V2版签名证书属性的Hash算法
        参数
            index：索引号，从0算起。整数类型。默认为0
        返回值
            成功返回V2版签名证书属性的Hash算法，比如：Hash.SHA256。如果没有这个属性，返回-1
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_int_attribute(10,index)
    
    def get_signing_time(self,index=0):
        '''
        获取签名时间
        参数
            index：索引号，从0算起。整数类型。默认为0
        返回值
            字符串类型。成功返回签名时间
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(11,index)
    
    def has_tsa_time(self,index=0):
        '''
        判断是否有时间戳
        参数
            index：索引号，从0算起。整数类型。默认为0
        返回值
            布尔类型。如果有时间戳，返回True。否则返回False
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_int_attribute(15,index)
    
    def get_tsa_time(self,index=0):
        '''
        获取时间戳时间
        参数
            index：索引号，从0算起。整数类型。默认为0
        返回值
            字符串类型。成功返回时间戳时间
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(12,index)
    
    def get_content_oid(self):
        '''
        获取Content的OID
        返回值
            字符串类型。成功返回Content的OID
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(13,-1)
    
    def get_tsa_sn(self,index=0):
        '''
        获取时间戳序列号
        参数
            index：索引号，从0算起。整数类型。默认为0
        返回值
            字符串类型。成功返回时间戳序列号
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(16,index)
    
    def get_tsa_policy(self,index=0):
        '''
        获取时间戳策略
        参数
            index：索引号，从0算起。整数类型。默认为0
        返回值
            字符串类型。成功返回时间戳策略
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_string_attribute(17,index)
    
    def get_tsa_hash_algo(self,index=0):
        '''
        获取时间戳的Hash算法
        参数
            index：索引号，从0算起。整数类型。默认为0
        返回值
            成功返回时间戳的Hash算法。比如：Hash.SHA256
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return self.get_int_attribute(18,index)
    
    def get_signcert(self,index=0):
        '''
        获取签名证书
        参数
            index：索引号，从0算起。整数类型。默认为0
        返回值
            Certificate类型。成功返回签名算法
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        handle=_NetcaCryptoHandle._signeddata_get_signcert(self._handle,index)
        return Certificate._new_cert(handle)

    def get_countsignaturecert(self,index=0,countersignindex=0):
        '''
        获取签名证书
        参数
            index：索引号，从0算起。整数类型。默认为0
            countersignindex:联署签名索引号，从0算起，整数类型，默认为0
        返回值
            Certificate类型。成功返回签名算法
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        handle=_NetcaCryptoHandle._signeddata_get_countsignaturecert(self._handle,index,countersignindex)
        return Certificate._new_cert(handle)
    
    def set_signcert(self,cert):
        '''
        设置签名证书
        参数
            cert：签名证书。Certificate类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._signeddata_set_signcert(self._handle,cert._handle)
    
    def set_enccert(self,cert,flag=0,index=0):
        '''
        设置加密证书
        参数
            cert：加密证书。Certificate类型
            flag：标志。整数类型。默认为0
            index：索引号，从0算起。整数类型。默认为0
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._signeddata_set_enccert(self._handle,cert._handle,index,flag)
        
    def add_cert(self,cert):
        '''
        添加其他证书
        参数
            cert：证书。Certificate类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._signeddata_add_cert(self._handle,cert._handle)

    def add_rootcert(self,cert):
        '''
        添加根证书
        参数
            cert：证书。Certificate类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._signeddata_add_rootcert(self._handle,cert._handle)

    def add_crl(self,crl):
        '''
        添加crl编码
        参数
           crl：crl编码
        抛出
           NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._signeddata_add_crl(self._handle,crl)

    def add_ocsp(self,flag,vacert,ocsp):
        '''
        添加crl编码
        参数           
           flag:标志，通常为0
           vacert:OCSP证书，可以为NULL,Certificate类型
           ocsp:BasicOCSPResponse的编码
        抛出
           NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._signeddata_add_ocsp(self._handle,flag,vacert,ocsp)
        
    def get_tsacert(self,index=0):
        '''
        获取时间戳证书
        参数
            index：索引号，从0算起。整数类型。默认为0
        返回值
            Certificate类型。成功返回时间戳证书
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        handle=_NetcaCryptoHandle._signeddata_get_tsacert(self._handle,index)
        return Certificate._new_cert(handle)
    
    def get_enccert(self,index=0):
        '''
        获取加密证书
        参数
            index：索引号，从0算起。整数类型。默认为0
        返回值
            Certificate类型。成功返回加密证书。如果没有返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        handle=_NetcaCryptoHandle._signeddata_get_enccert(self._handle,index)
        if handle is None:
            return None
        return Certificate._new_cert(handle)

class TimeStamp:
    '''
    TimeStamp类用于获取时间戳或者验证时间戳
    TimeStamp类需要释放，可用于with语句
    '''

    #时间戳响应的状态
    #错误的时间戳响应
    RESP_STATUS_BADRESP                 =-1
    #错误的时间戳证书
    RESP_STATUS_BADTSACERT              =-2
    #没有权限
    RESP_STATUS_ACCESSDENIED            =-3
    #正常
    RESP_STATUS_GRANTED                 =0
    #正常，但可能会被修改
    RESP_STATUS_GRANTEDWITHMODS         =1
    #拒绝
    RESP_STATUS_REJECTION               =2
    #等待
    RESP_STATUS_WAITING                 =3
    #撤销警告
    RESP_STATUS_REVOCATIONWARNING       =4
    #撤销通知
    RESP_STATUS_REVOCATIONNOTIFICATION  =5
    
    def __init__(self):
        '''
        构造TimeStamp对象，用于获取时间戳
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        self._handle=None
        self._handle=_NetcaCryptoHandle._new_timestamp()
    
    @staticmethod
    def _new_timestamp(handle):
        if handle is None:
            raise NetcaCryptoException("null handle")
        ts=TimeStamp.__new__(TimeStamp)
        ts._handle=cast(handle,c_void_p)
        return ts
    
    def __del__(self):
        '''
        释放TimeStamp对象
        '''
        _NetcaCryptoHandle._free_timestamp(self._handle)
        self._handle=None
    
    free=__del__
    
    def __enter__(self):
        return self
    
    def __exit__(self, exc_type, exc_val, exc_tb):
        self.free()
        return False
    
    @staticmethod
    def get_timestamp(data):
        '''
        获取时间戳
        参数
            data：要进行时间戳的数据。bytes类型
        返回值
            TimeStamp类型。成功返回TimeStamp对象
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        handle=_NetcaCryptoHandle._get_timestamp(data)
        ts=TimeStamp.__new__(TimeStamp)
        ts._handle=cast(handle,c_void_p)
        return ts
    
    @staticmethod
    def verify_timestamp_token(token,cert=None):
        '''
        验证时间戳
        参数
            token：时间戳Token。bytes类型
            cert：时间戳证书。Certificate类型。可以为None
        返回值
            TimeStamp类型。成功返回TimeStamp对象
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        handle=_NetcaCryptoHandle._verify_timestamp_token(token,cert)
        ts=TimeStamp.__new__(TimeStamp)
        ts._handle=cast(handle,c_void_p)
        return ts
    
    @staticmethod
    def verify_timestamp(data,token):
        '''
        验证时间戳
        参数
            data：要进行时间戳的数据。bytes类型
            token：时间戳Token。bytes类型
        返回值
            TimeStamp类型。成功返回TimeStamp对象
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        handle=_NetcaCryptoHandle._verify_timestamp(data,token)
        ts=TimeStamp.__new__(TimeStamp)
        ts._handle=cast(handle,c_void_p)
        return ts
    
    @staticmethod
    def decode_timestamp_resp(resp_encode):
        '''
        解码时间戳响应
        参数
            resp_encode：时间戳响应。bytes类型
        返回值
            元组类型。有两个元素，第0个是时间戳响应的状态，比如：RESP_STATUS_GRANTED，第1个是时间戳Token，bytes类型或者None。
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._decode_timestamp_resp(resp_encode)
    
    def get_token(self):
        '''
        获取时间戳Token
        返回值
            bytes类型。成功返回时间戳Token
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._timestamp_get_token(self._handle)
    
    def get_time(self):
        '''
        获取时间戳时间
        返回值
            字符串类型。成功返回时间戳时间
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._timestamp_get_time(self._handle)
    
    def set_hash_algo(self,algo):
        '''
        设置时间戳的Hash算法
        参数
            algo：Hash算法。比如：Hash.SHA256
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._timestamp_set_hash_algo(self._handle,algo)
    
    def set_hash_value(self,hash_value):
        '''
        设置要进行时间戳数据的Hash值
        参数
            hash_value：要进行时间戳数据的Hash值。bytes类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._timestamp_set_hash_value(self._handle,hash_value)
    
    def set_tsa_url(self,url):
        '''
        设置时间戳服务器的URL
        参数
            url：时间戳服务器的URL。字符串类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._timestamp_set_tsa_url(self._handle,url)
    
    def get_req_encode(self):
        '''
        获取时间戳请求的编码
        返回值
            bytes类型。成功返回时间戳请求的编码
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._timestamp_get_req_encode(self._handle)
    
    def get_resp(self):
        '''
        获取时间戳响应
        返回值
            成功返回时间戳响应的状态，比如:RESP_STATUS_GRANTED
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._timestamp_get_resp(self._handle)
    
    def get_tsa_cert(self):
        '''
        获取时间戳证书
        返回值
            Certificate类型。成功返回时间戳证书
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        cert=_NetcaCryptoHandle._timestamp_get_tsa_cert(self._handle)
        return Certificate._new_cert(cert)
    
    def get_hash_algo(self):
        '''
        获取时间戳的Hash算法
        返回值
            成功返回时间戳的Hash算法，比如：Hash.SHA256
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._timestamp_get_hash_algo(self._handle)
    
    def get_hash_value(self):
        '''
        获取要进行时间戳数据的Hash值
        返回值
            bytes类型。成功返回要进行时间戳数据的Hash值
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._timestamp_get_hash_value(self._handle)
    
    def get_policy(self):
        '''
        获取时间戳策略
        返回值
            字符串类型。成功返回时间戳策略
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._timestamp_get_policy(self._handle)
    
    def set_policy(self,policy):
        '''
        设置时间戳策略
        参数
            时间戳策略。字符串类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._timestamp_set_policy(self._handle,policy)
    
    def get_sn(self):
        '''
        获取时间戳序列号
        返回值
            字符串类型。成功返回时间戳序列号
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._timestamp_get_sn(self._handle)
     
    def set_certreq(self,value):
        '''
        设置是否要求时间戳响应带证书
        参数
            为真表示要求时间戳响应带证书，为假表示要求不带证书。布尔类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._timestamp_set_certreq(self._handle,value)
    
    def get_certreq(self):
        '''
        获取是否要求时间戳响应带证书
        返回值
            布尔类型。要求时间戳响应带证书返回True，否则返回False
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._timestamp_get_certreq(self._handle)
    
    def set_tsa_cert(self,cert):
        '''
        设置时间戳证书
        参数
            cert：时间戳证书。Certifcaite类型
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        _NetcaCryptoHandle._timestamp_set_tsa_cert(self._handle,cert)
    
    def get_accuracy(self):
        '''
        获取时间戳的精度
        返回值
            元组类型。有三个整数，分别表示：秒、毫秒和微秒。如果不存在时间戳的精度返回None
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._timestamp_get_accuracy(self._handle)


class Base64:
    '''
    Base64类用于进行Base64运算
    Base64类需要释放，可用于with语句
    '''

    #Base64标志，可以或起来使用。可以为0
    #不使用回车换行，编码时使用
    FLAG_NO_NL      =1
    #严格的Base64，解码时使用
    FLAG_STRICT     =2
    #不进行填充。编码和解码都可以使用
    FLAG_NOPADDING  =0x80
    #Base64Url编码。编码和解码都可以使用
    FLAG_URL        =0x100

    def __init__(self,enc,flag):
        '''
        构造Base64对象
        参数
            enc：为真表示进行编码，为假表示进行解码。布尔类型
            flag：Base64标志,比如：FLAG_NO_NL等
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        self._handle=None
        if type(enc)!=type(True):
            raise NetcaCryptoException("enc not boolean type")
        encodeType=True
        if enc==0:
            encodeType=False
        self._handle=_NetcaCryptoHandle._new_base64(encodeType,flag)
    
    @staticmethod
    def _new_base64(handle):
        if handle is None:
            raise NetcaCryptoException("null handle")
        b64=Base64.__new__(Base64)
        b64._handle=cast(handle,c_void_p)
        return b64
    
    def __del__(self):
        '''
        释放Base64对象
        '''
        _NetcaCryptoHandle._free_base64(self._handle)
        self._handle=None
    
    free=__del__
    
    def __enter__(self):
        return self
    
    def __exit__(self, exc_type, exc_val, exc_tb):
        self.free()
        return False
    
    def update(self,data):
        '''
        输入数据进行Base64运算。可以多次调用
        参数
            data：输入的数据。bytes类型
        返回值
            bytes类型。成功返回运算的结果
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._base64_update(self._handle,data)
    
    def final(self):
        '''
        结束Base64运算。
        返回值
            bytes类型。成功返回最后部分的结果
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        return _NetcaCryptoHandle._base64_final(self._handle)

    
    @staticmethod
    def base64(enc,flag,data):
        '''
        一步完成Base64运算
        参数
            enc：为真表示进行编码，为假表示进行解码。布尔类型
            flag：Base64标志,比如：FLAG_NO_NL等
            data：输入的数据。bytes类型
        返回值
            bytes类型。成功返回运算的结果
        抛出
            NetcaCryptoException：出错抛出NetcaCryptoException异常
        '''
        if type(enc)!=type(True):
            raise NetcaCryptoException("enc not boolean type")
        encodeType=True
        if enc==0:
            encodeType=False
        return _NetcaCryptoHandle._base64(encodeType,flag,data)
    
def get_version():
    '''
    获取版本信息
    返回值
        字符串类型。成功返回版本信息
    抛出
        NetcaCryptoException：出错抛出NetcaCryptoException异常
    '''
    return _NetcaCryptoHandle._get_version()

def get_last_error():
    '''
    获取错误号
    返回值
        整数类型。成功返回错误号
    '''
    return _NetcaCryptoHandle._get_last_error()
    
def get_error_msg(error_no):
    '''
    获取错误信息
    参数
        error_no：错误号。证书类型
    返回值
        字符串类型。成功返回错误号对应的错误信息，失败返回空串
    '''
    return _NetcaCryptoHandle._get_error_msg(error_no)

def reset_config():
    '''
    恢复原始配置
    抛出
        NetcaCryptoException：出错抛出NetcaCryptoException异常
    '''
    _NetcaCryptoHandle._reset_config()

def set_config(config):
    '''
    设置配置信息
    参数
        config：配置信息，JSON格式。字符串类型
    抛出
        NetcaCryptoException：出错抛出NetcaCryptoException异常
    '''
    _NetcaCryptoHandle._set_config(config)

def get_config():
    '''
    获取配置信息
    返回值
        字符串类型，配置信息
    抛出
        NetcaCryptoException：出错抛出NetcaCryptoException异常
    '''
    return _NetcaCryptoHandle._get_config()

def set_default_sign_algo(publickey_type,algo):
    '''
    设置默认的签名算法
    参数
        publickey_type：公钥类型，比如："RSA"。字符串类型
        algo：签名算法，比如：SignedData.SHA256WITHRSA
    抛出
        NetcaCryptoException：出错抛出NetcaCryptoException异常
    '''
    _NetcaCryptoHandle._set_sign_algo(publickey_type,algo)

def generate_random(len):
    '''
    产生随机数
    参数
        len：随机数的字节数。整数类型
    返回值
        bytes类型。成功返回随机数
    抛出
        NetcaCryptoException：出错抛出NetcaCryptoException异常
    '''
    return _NetcaCryptoHandle._generate_random(len)
