import java.io.File;
import java.io.FileInputStream;

import net.netca.pki.Freeable;
import net.netca.pki.global.Pki;
import net.netca.pki.global.X509Certificate;
import java.util.Date;

public class CertInfo {

	public static void main(String[] args) throws Exception{
		if(args.length!=1) {
            System.out.println("Usage: java CertInfo certFileName");
            return;
        }
		
		String certFileName=args[0];
		Pki pki=getPkiObject();
        if(pki==null) {
        	System.out.println("no pki implementation");
            return;
        }
        X509Certificate cert=null;
        try {
        	byte[] certData=readFile(certFileName);
	        cert=pki.decodeCert(certData);
	        
	        System.out.println("序列号: "+cert.getSerialNumber());
	        
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

            String[] values;
            values=cert.getIssuerOU();
            if(values!=null) {
            	for(int i=0;i<values.length;i++) {
            		System.out.println("颁发者OU: "+values[i]);
            	}
            }

            values=cert.getIssuerCN();
            if(values!=null) {
            	for(int i=0;i<values.length;i++) {
            		System.out.println("颁发者CN: "+values[i]);
            	}
            }

            Date t;
            t=cert.getValidityStart();
            System.out.println("有效期开始时间: "+t);

            t=cert.getValidityEnd();
            System.out.println("有效期结束时间: "+t);

            System.out.println("主体: "+cert.getSubject());

            value=cert.getC();
            if(value!=null) {
                System.out.println("主体C: "+value);
            }

            value=cert.getST();
            if(value!=null) {
                System.out.println("主体ST: "+value);
            }

            value=cert.getL();
            if(value!=null) {
                System.out.println("主体L: "+value);
            }

            value=cert.getO();
            if(value!=null) {
                System.out.println("主体O: "+value);
            }

            values=cert.getOU();
            if(values!=null) {
            	for(int i=0;i<values.length;i++) {
            		System.out.println("主体OU: "+values[i]);
            	}
            }

            values=cert.getCN();
            if(values!=null) {
            	for(int i=0;i<values.length;i++) {
            		System.out.println("主体CN: "+values[i]);
            	}
            }
            
            values=cert.getEmail();
            if(values!=null) {
            	for(int i=0;i<values.length;i++) {
            		System.out.println("主体Email: "+values[i]);
            	}
            }
            
            int type=cert.getPublicKeyType();
            printPublicKeyType(type);

            System.out.println("公钥长度: "+cert.getPublicKeyBits()+"位");

            int ku=cert.getKeyUsage();
            printKeyUsage(ku);
            
            int certClass=cert.getCertClass();
            printCertClass(certClass);
            
        } finally {
        	if (cert instanceof Freeable) {
        		((Freeable)cert).free();
        	}
        	
        	if (pki instanceof Freeable) {
        		((Freeable)pki).free();
        	}
        }

	}

	private static byte[] readFile(String fileName) throws Exception{
		File file=new File(fileName);
		
		long fileLen=file.length();
		if(fileLen>=Integer.MAX_VALUE) {
			throw new Exception("file too big");
		}
		int len=(int)fileLen;
		byte[] data=new byte[len];
		FileInputStream fIn=new FileInputStream(file);
		
		try{
			if (fIn.read(data)!=len) {
				throw new Exception("read file fail");
			}
			return data;
		} finally {
			fIn.close();
		}
	}
	
	private static void printPublicKeyType(int type) {
        if(type==X509Certificate.RSA) {
            System.out.println("公钥算法: RSA");
        } else if(type==X509Certificate.DH) {
            System.out.println("公钥算法: DH");
        } else if(type==X509Certificate.DSA) {
            System.out.println("公钥算法: DSA");
        } else if(type==X509Certificate.SM2) {
            System.out.println("公钥算法: SM2");
        } else if(type==X509Certificate.P256) {
            System.out.println("公钥算法: P-256");
        } else if(type==X509Certificate.P384) {
            System.out.println("公钥算法: P-384");
        } else if(type==X509Certificate.P521) {
            System.out.println("公钥算法: P-521");
        } else {
            System.out.println("公钥算法: 未知公钥算法("+type+")");
        }
    }
	
	private static void printKeyUsage(int ku) {
        if(ku==-1) {
            System.out.println("密钥用法: 没有密钥用法");
            return;
        }
        String kustr="";
        boolean first=true;

        if((ku&X509Certificate.KEYUSAGE_DIGITALSIGNATURE)!=0) {
            if(first) {
                kustr+="数字签名";
            } else {
                kustr+=",数字签名";
            }
            first=false;
        }

        if((ku&X509Certificate.KEYUSAGE_NONREPUDIATION)!=0) {
            if(first) {
                kustr+="不可否认";
            } else {
                kustr+=",不可否认";
            }
            first=false;
        }

        if((ku&X509Certificate.KEYUSAGE_KEYENCIPHERMENT)!=0) {
            if(first) {
                kustr+="加密密钥";
            } else {
                kustr+=",加密密钥";
            }
            first=false;
        }

        if((ku&X509Certificate.KEYUSAGE_DATAENCIPHERMENT)!=0) {
            if(first) {
                kustr+="加密数据";
            } else {
                kustr+=",加密数据";
            }
            first=false;
        }

        if((ku&X509Certificate.KEYUSAGE_KEYAGREEMENT)!=0) {
            if(first) {
                kustr+="密钥协商";
            } else {
                kustr+=",密钥协商";
            }
            first=false;
        }

        if((ku&X509Certificate.KEYUSAGE_KEYCERTSIGN)!=0) {
            if(first) {
                kustr+="签证书";
            } else {
                kustr+=",签证书";
            }
            first=false;
        }

        if((ku&X509Certificate.KEYUSAGE_CRLSIGN)!=0) {
            if(first) {
                kustr+="签CRL";
            } else {
                kustr+=",签CRL";
            }
            first=false;
        }

        if((ku&X509Certificate.KEYUSAGE_ENCIPHERONLY)!=0) {
            if(first) {
                kustr+="只加密";
            } else {
                kustr+=",只加密";
            }
            first=false;
        }

        if((ku&X509Certificate.KEYUSAGE_DECIPHERONLY)!=0) {
            if(first) {
                kustr+="只解密";
            } else {
                kustr+=",只解密";
            }
            first=false;
        }

        System.out.println("密钥用法: "+kustr);
    }
	
	private static void printCertClass(int certClass) {
        if(certClass==X509Certificate.CERT_CLASS_SELFSIGN) {
            System.out.println("证书类别: 自签证书");
        } else if(certClass==X509Certificate.CERT_CLASS_SELFISSUER) {
            System.out.println("证书类别: 自颁发证书");
        } else if(certClass==X509Certificate.CERT_CLASS_CA) {
            System.out.println("证书类别: CA证书");
        } else if(certClass==X509Certificate.CERT_CLASS_TSA) {
            System.out.println("证书类别: TSA证书");
        } else if(certClass==X509Certificate.CERT_CLASS_OCSP) {
            System.out.println("证书类别: OCSP证书");
		} else if (certClass == X509Certificate.CERT_CLASS_ORGANIZATION) {
			System.out.println("证书类别: 机构证书");
		} else if (certClass == X509Certificate.CERT_CLASS_EMPLOYEE) {
			System.out.println("证书类别: 单位员工证书");
		} else if (certClass == X509Certificate.CERT_CLASS_INDIVIDUAL){
			System.out.println("证书类别: 个人证书");
		} else if (certClass == X509Certificate.CERT_CLASS_SERVER){
			System.out.println("证书类别: 服务器证书");
		} else if (certClass == X509Certificate.CERT_CLASS_CODESIGN){
			System.out.println("证书类别: 代码签名证书");
		} else{
			System.out.println("证书类别: 未知证书类别(" + certClass + ")");
		}
    }
	
	private static Pki getPkiObject() throws Exception{
		String name=System.getProperty("pkiName");
		if(name==null) {
			name="netca";
		}
		String param=System.getProperty("pkiParam");
		if(param==null) {
			return Pki.getInstance(name);
		} else {
			return Pki.getInstance(name,param);
		}
	}
}
