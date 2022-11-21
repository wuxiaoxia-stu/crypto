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
	        
	        System.out.println("���к�: "+cert.getSerialNumber());
	        
	        System.out.println("�䷢��: "+cert.getIssuer());
            String value;
            
            value=cert.getIssuerC();
            if(value!=null) {
                System.out.println("�䷢��C: "+value);
            }
            value=cert.getIssuerST();
            if(value!=null) {
                System.out.println("�䷢��ST: "+value);
            }
            
            value=cert.getIssuerL();
            if(value!=null) {
                System.out.println("�䷢��L: "+value);
            }

            value=cert.getIssuerO();
            if(value!=null) {
                System.out.println("�䷢��O: "+value);
            }

            String[] values;
            values=cert.getIssuerOU();
            if(values!=null) {
            	for(int i=0;i<values.length;i++) {
            		System.out.println("�䷢��OU: "+values[i]);
            	}
            }

            values=cert.getIssuerCN();
            if(values!=null) {
            	for(int i=0;i<values.length;i++) {
            		System.out.println("�䷢��CN: "+values[i]);
            	}
            }

            Date t;
            t=cert.getValidityStart();
            System.out.println("��Ч�ڿ�ʼʱ��: "+t);

            t=cert.getValidityEnd();
            System.out.println("��Ч�ڽ���ʱ��: "+t);

            System.out.println("����: "+cert.getSubject());

            value=cert.getC();
            if(value!=null) {
                System.out.println("����C: "+value);
            }

            value=cert.getST();
            if(value!=null) {
                System.out.println("����ST: "+value);
            }

            value=cert.getL();
            if(value!=null) {
                System.out.println("����L: "+value);
            }

            value=cert.getO();
            if(value!=null) {
                System.out.println("����O: "+value);
            }

            values=cert.getOU();
            if(values!=null) {
            	for(int i=0;i<values.length;i++) {
            		System.out.println("����OU: "+values[i]);
            	}
            }

            values=cert.getCN();
            if(values!=null) {
            	for(int i=0;i<values.length;i++) {
            		System.out.println("����CN: "+values[i]);
            	}
            }
            
            values=cert.getEmail();
            if(values!=null) {
            	for(int i=0;i<values.length;i++) {
            		System.out.println("����Email: "+values[i]);
            	}
            }
            
            int type=cert.getPublicKeyType();
            printPublicKeyType(type);

            System.out.println("��Կ����: "+cert.getPublicKeyBits()+"λ");

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
            System.out.println("��Կ�㷨: RSA");
        } else if(type==X509Certificate.DH) {
            System.out.println("��Կ�㷨: DH");
        } else if(type==X509Certificate.DSA) {
            System.out.println("��Կ�㷨: DSA");
        } else if(type==X509Certificate.SM2) {
            System.out.println("��Կ�㷨: SM2");
        } else if(type==X509Certificate.P256) {
            System.out.println("��Կ�㷨: P-256");
        } else if(type==X509Certificate.P384) {
            System.out.println("��Կ�㷨: P-384");
        } else if(type==X509Certificate.P521) {
            System.out.println("��Կ�㷨: P-521");
        } else {
            System.out.println("��Կ�㷨: δ֪��Կ�㷨("+type+")");
        }
    }
	
	private static void printKeyUsage(int ku) {
        if(ku==-1) {
            System.out.println("��Կ�÷�: û����Կ�÷�");
            return;
        }
        String kustr="";
        boolean first=true;

        if((ku&X509Certificate.KEYUSAGE_DIGITALSIGNATURE)!=0) {
            if(first) {
                kustr+="����ǩ��";
            } else {
                kustr+=",����ǩ��";
            }
            first=false;
        }

        if((ku&X509Certificate.KEYUSAGE_NONREPUDIATION)!=0) {
            if(first) {
                kustr+="���ɷ���";
            } else {
                kustr+=",���ɷ���";
            }
            first=false;
        }

        if((ku&X509Certificate.KEYUSAGE_KEYENCIPHERMENT)!=0) {
            if(first) {
                kustr+="������Կ";
            } else {
                kustr+=",������Կ";
            }
            first=false;
        }

        if((ku&X509Certificate.KEYUSAGE_DATAENCIPHERMENT)!=0) {
            if(first) {
                kustr+="��������";
            } else {
                kustr+=",��������";
            }
            first=false;
        }

        if((ku&X509Certificate.KEYUSAGE_KEYAGREEMENT)!=0) {
            if(first) {
                kustr+="��ԿЭ��";
            } else {
                kustr+=",��ԿЭ��";
            }
            first=false;
        }

        if((ku&X509Certificate.KEYUSAGE_KEYCERTSIGN)!=0) {
            if(first) {
                kustr+="ǩ֤��";
            } else {
                kustr+=",ǩ֤��";
            }
            first=false;
        }

        if((ku&X509Certificate.KEYUSAGE_CRLSIGN)!=0) {
            if(first) {
                kustr+="ǩCRL";
            } else {
                kustr+=",ǩCRL";
            }
            first=false;
        }

        if((ku&X509Certificate.KEYUSAGE_ENCIPHERONLY)!=0) {
            if(first) {
                kustr+="ֻ����";
            } else {
                kustr+=",ֻ����";
            }
            first=false;
        }

        if((ku&X509Certificate.KEYUSAGE_DECIPHERONLY)!=0) {
            if(first) {
                kustr+="ֻ����";
            } else {
                kustr+=",ֻ����";
            }
            first=false;
        }

        System.out.println("��Կ�÷�: "+kustr);
    }
	
	private static void printCertClass(int certClass) {
        if(certClass==X509Certificate.CERT_CLASS_SELFSIGN) {
            System.out.println("֤�����: ��ǩ֤��");
        } else if(certClass==X509Certificate.CERT_CLASS_SELFISSUER) {
            System.out.println("֤�����: �԰䷢֤��");
        } else if(certClass==X509Certificate.CERT_CLASS_CA) {
            System.out.println("֤�����: CA֤��");
        } else if(certClass==X509Certificate.CERT_CLASS_TSA) {
            System.out.println("֤�����: TSA֤��");
        } else if(certClass==X509Certificate.CERT_CLASS_OCSP) {
            System.out.println("֤�����: OCSP֤��");
		} else if (certClass == X509Certificate.CERT_CLASS_ORGANIZATION) {
			System.out.println("֤�����: ����֤��");
		} else if (certClass == X509Certificate.CERT_CLASS_EMPLOYEE) {
			System.out.println("֤�����: ��λԱ��֤��");
		} else if (certClass == X509Certificate.CERT_CLASS_INDIVIDUAL){
			System.out.println("֤�����: ����֤��");
		} else if (certClass == X509Certificate.CERT_CLASS_SERVER){
			System.out.println("֤�����: ������֤��");
		} else if (certClass == X509Certificate.CERT_CLASS_CODESIGN){
			System.out.println("֤�����: ����ǩ��֤��");
		} else{
			System.out.println("֤�����: δ֪֤�����(" + certClass + ")");
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
