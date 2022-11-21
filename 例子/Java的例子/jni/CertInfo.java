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

            System.out.println("���к�: "+cert.getSerialNumber());

            int algo;
            algo=cert.getSignAlgorithm();
            PrintSignAlgo(algo);

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

            value=cert.getIssuerOU();
            if(value!=null) {
                System.out.println("�䷢��OU: "+value);
            }

            value=cert.getIssuerCN();
            if(value!=null) {
                System.out.println("�䷢��CN: "+value);
            }

            value=cert.getIssuerEmail();
            if(value!=null) {
                System.out.println("�䷢��Email: "+value);
            }

            Date t;
            t=cert.getValidityStart();
            System.out.println("��Ч�ڿ�ʼʱ��: "+t);

            t=cert.getValidityEnd();
            System.out.println("��Ч�ڽ���ʱ��: "+t);

            System.out.println("����: "+cert.getSubject());

            value=cert.getSubjectC();
            if(value!=null) {
                System.out.println("����C: "+value);
            }

            value=cert.getSubjectST();
            if(value!=null) {
                System.out.println("����ST: "+value);
            }

            value=cert.getSubjectL();
            if(value!=null) {
                System.out.println("����L: "+value);
            }

            value=cert.getSubjectO();
            if(value!=null) {
                System.out.println("����O: "+value);
            }

            value=cert.getSubjectOU();
            if(value!=null) {
                System.out.println("����OU: "+value);
            }

            value=cert.getSubjectCN();
            if(value!=null) {
                System.out.println("����CN: "+value);
            }

            value=cert.getSubjectEmail();
            if(value!=null) {
                System.out.println("����Email: "+value);
            }

            algo=cert.getPublicKeyAlgorithm();
            PrintPublicKeyAlgo(algo);

            System.out.println("��Կ����: "+cert.getPublicKeyBits()+"λ");

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
            System.out.println("�汾��: V1");
        } else if(version==Certificate.CERT_VERSION_V2) {
            System.out.println("�汾��: V2");
        } else if(version==Certificate.CERT_VERSION_V3) {
            System.out.println("�汾��: V3");
        } else {
            System.out.println("�汾��: δ֪�汾("+version+")");
        }
    }

    static void PrintSignAlgo(int algo) {
        if(algo==Signature.MD5WITHRSA) {
            System.out.println("ǩ���㷨: MD5WITHRSA");
        } else if(algo==Signature.SHA1WITHRSA) {
            System.out.println("ǩ���㷨: SHA1WITHRSA");
        } else if(algo==Signature.SHA224WITHRSA) {
            System.out.println("ǩ���㷨: SHA224WITHRSA");
        } else if(algo==Signature.SHA256WITHRSA) {
            System.out.println("ǩ���㷨: SHA256WITHRSA");
        } else if(algo==Signature.SHA384WITHRSA) {
            System.out.println("ǩ���㷨: SHA384WITHRSA");
        } else if(algo==Signature.SHA512WITHRSA) {
            System.out.println("ǩ���㷨: SHA512WITHRSA");
        } else if(algo==Signature.DSAWITHSHA1) {
            System.out.println("ǩ���㷨: DSAWITHSHA1");
        } else if(algo==Signature.DSAWITHSHA224) {
            System.out.println("ǩ���㷨: DSAWITHSHA224");
        } else if(algo==Signature.DSAWITHSHA256) {
            System.out.println("ǩ���㷨: DSAWITHSHA256");
        } else if(algo==Signature.ECDSAWITHSHA1) {
            System.out.println("ǩ���㷨: ECDSAWITHSHA1");
        } else if(algo==Signature.ECDSAWITHSHA224) {
            System.out.println("ǩ���㷨: ECDSAWITHSHA224");
        } else if(algo==Signature.ECDSAWITHSHA256) {
            System.out.println("ǩ���㷨: ECDSAWITHSHA256");
        } else if(algo==Signature.ECDSAWITHSHA384) {
            System.out.println("ǩ���㷨: ECDSAWITHSHA384");
        } else if(algo==Signature.ECDSAWITHSHA512) {
            System.out.println("ǩ���㷨: ECDSAWITHSHA512");
        } else if(algo==Signature.SM3WITHSM2) {
            System.out.println("ǩ���㷨: SM3WITHSM2");
        } else {
            System.out.println("ǩ���㷨: δ֪ǩ���㷨("+algo+")");
        }
    }

    static void PrintPublicKeyAlgo(int algo) {
        if(algo==KeyPair.RSA) {
            System.out.println("��Կ�㷨: RSA");
        } else if(algo==KeyPair.DH) {
            System.out.println("��Կ�㷨: DH");
        } else if(algo==KeyPair.DSA) {
            System.out.println("��Կ�㷨: DSA");
        } else if(algo==KeyPair.ECC) {
            System.out.println("��Կ�㷨: ECC");
        } else {
            System.out.println("��Կ�㷨: δ֪��Կ�㷨("+algo+")");
        }
    }

    static void PrintKeyUsage(int ku) {
        if(ku==-1) {
            System.out.println("��Կ�÷�: û����Կ�÷�");
            return;
        }
        String kustr="";
        boolean first=true;

        if((ku&Certificate.KEYUSAGE_DIGITALSIGNATURE)!=0) {
            if(first) {
                kustr+="����ǩ��";
            } else {
                kustr+=",����ǩ��";
            }
            first=false;
        }

        if((ku&Certificate.KEYUSAGE_NONREPUDIATION)!=0) {
            if(first) {
                kustr+="���ɷ���";
            } else {
                kustr+=",���ɷ���";
            }
            first=false;
        }

        if((ku&Certificate.KEYUSAGE_KEYENCIPHERMENT)!=0) {
            if(first) {
                kustr+="������Կ";
            } else {
                kustr+=",������Կ";
            }
            first=false;
        }

        if((ku&Certificate.KEYUSAGE_DATAENCIPHERMENT)!=0) {
            if(first) {
                kustr+="��������";
            } else {
                kustr+=",��������";
            }
            first=false;
        }

        if((ku&Certificate.KEYUSAGE_KEYAGREEMENT)!=0) {
            if(first) {
                kustr+="��ԿЭ��";
            } else {
                kustr+=",��ԿЭ��";
            }
            first=false;
        }

        if((ku&Certificate.KEYUSAGE_KEYCERTSIGN)!=0) {
            if(first) {
                kustr+="ǩ֤��";
            } else {
                kustr+=",ǩ֤��";
            }
            first=false;
        }

        if((ku&Certificate.KEYUSAGE_CRLSIGN)!=0) {
            if(first) {
                kustr+="ǩCRL";
            } else {
                kustr+=",ǩCRL";
            }
            first=false;
        }

        if((ku&Certificate.KEYUSAGE_ENCIPHERONLY)!=0) {
            if(first) {
                kustr+="ֻ����";
            } else {
                kustr+=",ֻ����";
            }
            first=false;
        }

        if((ku&Certificate.KEYUSAGE_DECIPHERONLY)!=0) {
            if(first) {
                kustr+="ֻ����";
            } else {
                kustr+=",ֻ����";
            }
            first=false;
        }

        System.out.println("��Կ�÷�: "+kustr);
    }
}
