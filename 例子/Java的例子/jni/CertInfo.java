import net.netca.pki.*;
import java.io.*;
import java.util.Date;

public class CertInfo {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=1) {
            System.out.println("Usage: java CertInfo cert");
            return;
        }


        Certificate cert=null;
        FileInputStream fIn=null;
        byte [] in=new byte[8192];
        int len;
        try {
            fIn=new FileInputStream(arg[0]);
            len=fIn.read(in);
            cert=new Certificate(in,0,len);
            fIn.close();
            fIn=null;

            int version=cert.getVersion();
            PrintVersion(version);

            System.out.println("序列号: "+cert.getSerialNumber());

            int algo;
            algo=cert.getSignAlgorithm();
            PrintSignAlgo(algo);

            System.out.println("颁发者: "+cert.getIssuer());
            String value;

            value=cert.getIssuerC();
            if(value!=null) {
                System.out.println("颁发者C: "+value);
            }
            value=cert.getIssuerST();
            if(value!=null) {
                System.out.println("颁发者ST: "+value);
            }

            value=cert.getIssuerL();
            if(value!=null) {
                System.out.println("颁发者L: "+value);
            }

            value=cert.getIssuerO();
            if(value!=null) {
                System.out.println("颁发者O: "+value);
            }

            value=cert.getIssuerOU();
            if(value!=null) {
                System.out.println("颁发者OU: "+value);
            }

            value=cert.getIssuerCN();
            if(value!=null) {
                System.out.println("颁发者CN: "+value);
            }

            value=cert.getIssuerEmail();
            if(value!=null) {
                System.out.println("颁发者Email: "+value);
            }

            Date t;
            t=cert.getValidityStart();
            System.out.println("有效期开始时间: "+t);

            t=cert.getValidityEnd();
            System.out.println("有效期结束时间: "+t);

            System.out.println("主体: "+cert.getSubject());

            value=cert.getSubjectC();
            if(value!=null) {
                System.out.println("主体C: "+value);
            }

            value=cert.getSubjectST();
            if(value!=null) {
                System.out.println("主体ST: "+value);
            }

            value=cert.getSubjectL();
            if(value!=null) {
                System.out.println("主体L: "+value);
            }

            value=cert.getSubjectO();
            if(value!=null) {
                System.out.println("主体O: "+value);
            }

            value=cert.getSubjectOU();
            if(value!=null) {
                System.out.println("主体OU: "+value);
            }

            value=cert.getSubjectCN();
            if(value!=null) {
                System.out.println("主体CN: "+value);
            }

            value=cert.getSubjectEmail();
            if(value!=null) {
                System.out.println("主体Email: "+value);
            }

            algo=cert.getPublicKeyAlgorithm();
            PrintPublicKeyAlgo(algo);

            System.out.println("公钥长度: "+cert.getPublicKeyBits()+"位");

            int ku=cert.getKeyUsage();
            PrintKeyUsage(ku);
        } finally {
            if(fIn!=null) {
                fIn.close();
            }


            if(cert!=null) {
                cert.free();
            }


        }

    }

    static void PrintVersion(int version) {
        if(version==Certificate.CERT_VERSION_V1) {
            System.out.println("版本号: V1");
        } else if(version==Certificate.CERT_VERSION_V2) {
            System.out.println("版本号: V2");
        } else if(version==Certificate.CERT_VERSION_V3) {
            System.out.println("版本号: V3");
        } else {
            System.out.println("版本号: 未知版本("+version+")");
        }
    }

    static void PrintSignAlgo(int algo) {
        if(algo==Signature.MD5WITHRSA) {
            System.out.println("签名算法: MD5WITHRSA");
        } else if(algo==Signature.SHA1WITHRSA) {
            System.out.println("签名算法: SHA1WITHRSA");
        } else if(algo==Signature.SHA224WITHRSA) {
            System.out.println("签名算法: SHA224WITHRSA");
        } else if(algo==Signature.SHA256WITHRSA) {
            System.out.println("签名算法: SHA256WITHRSA");
        } else if(algo==Signature.SHA384WITHRSA) {
            System.out.println("签名算法: SHA384WITHRSA");
        } else if(algo==Signature.SHA512WITHRSA) {
            System.out.println("签名算法: SHA512WITHRSA");
        } else if(algo==Signature.DSAWITHSHA1) {
            System.out.println("签名算法: DSAWITHSHA1");
        } else if(algo==Signature.DSAWITHSHA224) {
            System.out.println("签名算法: DSAWITHSHA224");
        } else if(algo==Signature.DSAWITHSHA256) {
            System.out.println("签名算法: DSAWITHSHA256");
        } else if(algo==Signature.ECDSAWITHSHA1) {
            System.out.println("签名算法: ECDSAWITHSHA1");
        } else if(algo==Signature.ECDSAWITHSHA224) {
            System.out.println("签名算法: ECDSAWITHSHA224");
        } else if(algo==Signature.ECDSAWITHSHA256) {
            System.out.println("签名算法: ECDSAWITHSHA256");
        } else if(algo==Signature.ECDSAWITHSHA384) {
            System.out.println("签名算法: ECDSAWITHSHA384");
        } else if(algo==Signature.ECDSAWITHSHA512) {
            System.out.println("签名算法: ECDSAWITHSHA512");
        } else if(algo==Signature.SM3WITHSM2) {
            System.out.println("签名算法: SM3WITHSM2");
        } else {
            System.out.println("签名算法: 未知签名算法("+algo+")");
        }
    }

    static void PrintPublicKeyAlgo(int algo) {
        if(algo==KeyPair.RSA) {
            System.out.println("公钥算法: RSA");
        } else if(algo==KeyPair.DH) {
            System.out.println("公钥算法: DH");
        } else if(algo==KeyPair.DSA) {
            System.out.println("公钥算法: DSA");
        } else if(algo==KeyPair.ECC) {
            System.out.println("公钥算法: ECC");
        } else {
            System.out.println("公钥算法: 未知公钥算法("+algo+")");
        }
    }

    static void PrintKeyUsage(int ku) {
        if(ku==-1) {
            System.out.println("密钥用法: 没有密钥用法");
            return;
        }
        String kustr="";
        boolean first=true;

        if((ku&Certificate.KEYUSAGE_DIGITALSIGNATURE)!=0) {
            if(first) {
                kustr+="数字签名";
            } else {
                kustr+=",数字签名";
            }
            first=false;
        }

        if((ku&Certificate.KEYUSAGE_NONREPUDIATION)!=0) {
            if(first) {
                kustr+="不可否认";
            } else {
                kustr+=",不可否认";
            }
            first=false;
        }

        if((ku&Certificate.KEYUSAGE_KEYENCIPHERMENT)!=0) {
            if(first) {
                kustr+="加密密钥";
            } else {
                kustr+=",加密密钥";
            }
            first=false;
        }

        if((ku&Certificate.KEYUSAGE_DATAENCIPHERMENT)!=0) {
            if(first) {
                kustr+="加密数据";
            } else {
                kustr+=",加密数据";
            }
            first=false;
        }

        if((ku&Certificate.KEYUSAGE_KEYAGREEMENT)!=0) {
            if(first) {
                kustr+="密钥协商";
            } else {
                kustr+=",密钥协商";
            }
            first=false;
        }

        if((ku&Certificate.KEYUSAGE_KEYCERTSIGN)!=0) {
            if(first) {
                kustr+="签证书";
            } else {
                kustr+=",签证书";
            }
            first=false;
        }

        if((ku&Certificate.KEYUSAGE_CRLSIGN)!=0) {
            if(first) {
                kustr+="签CRL";
            } else {
                kustr+=",签CRL";
            }
            first=false;
        }

        if((ku&Certificate.KEYUSAGE_ENCIPHERONLY)!=0) {
            if(first) {
                kustr+="只加密";
            } else {
                kustr+=",只加密";
            }
            first=false;
        }

        if((ku&Certificate.KEYUSAGE_DECIPHERONLY)!=0) {
            if(first) {
                kustr+="只解密";
            } else {
                kustr+=",只解密";
            }
            first=false;
        }

        System.out.println("密钥用法: "+kustr);
    }
}
