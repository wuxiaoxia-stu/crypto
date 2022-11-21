import net.netca.pki.*;

import java.io.*;

public class SM9KeyExchange {
    public static void main(String[] arg) throws Exception {
        if(arg.length!=4) {
            System.out.println("Usage: java SM9KeyExchange senderUserKeyFile receiverUserKeyFile keyLen keyConfirm");
            return;
        }


        FileInputStream fIn=null;       
        byte [] sender=new byte[8192];
        byte [] receiver=new byte[8192];
        int len;
        SM9UserKey sm9Sender=null;
        SM9UserKey sm9Receiver=null;
        try {
        	 
        	fIn=new FileInputStream(arg[0]);
             len=fIn.read(sender);
             sm9Sender=SM9UserKey.importUserKeyPair(sender,0,len);
        	 fIn.close();
             fIn=null;
             
             fIn=new FileInputStream(arg[1]);
             len=fIn.read(receiver);
             sm9Receiver=SM9UserKey.importUserKeyPair(receiver,0,len);
        	 fIn.close();
             fIn=null;
             
           
             int keyLen;
             keyLen=Integer.parseInt(arg[2]);
             if(keyLen<=0)
             {
            	 System.out.println("keyLen is not integer");
                 return;            	 
             } 
             
             boolean keyConfirm=Boolean.parseBoolean(arg[3]);
            			 
             
             SM9Keyexchange senderKeyexchange = new SM9Keyexchange(true, sm9Sender);
             SM9Keyexchange receiverKeyexchange = new SM9Keyexchange(false, sm9Receiver);
             byte[] Ra=senderKeyexchange.SenderPrepare(sm9Receiver.getId());
             String str;
             str = "Ra:" + Util.HexEncode(true, Ra) + "\n";
             System.out.println(str);
             
             byte[] SKb=receiverKeyexchange.receiveKeyexchange(keyConfirm, sm9Sender.getId(), Ra, keyLen);
             byte[] Rb = receiverKeyexchange.getRb();
             str = "Rb:" + Util.HexEncode(true, Rb) + "\n"; 
             System.out.println(str);
             str = "SKb:" + Util.HexEncode(true, SKb) + "\n";
             System.out.println(str);
             
             byte[] SKa;
             if (keyConfirm)
             {
                 byte[] Sb = receiverKeyexchange.getSb();
                 str = "Sb:" + Util.HexEncode(true, Sb) + "\n";
                 System.out.println(str);
                 SKa = senderKeyexchange.senderKeyexchange(Rb, Sb, keyLen);
             }
             else
             {
                 SKa = senderKeyexchange.senderKeyexchange(Rb, keyLen);
             }
           
             str = "SKa:" + Util.HexEncode(true, SKa) + "\n";
             System.out.println(str);
             
             if(java.util.Arrays.equals(SKa,SKb)==false) {
                 System.out.println("��Կ��������õ�����Կ��ͬ\n");
                 return;
             }
             else
             {                
                 System.out.println("��Կ��������õ�����Կ��ͬ\n");
             }
             
             if (keyConfirm)
             {
                 byte[] Sa = senderKeyexchange.getSa();
                 str = "Sa:" + Util.HexEncode(true,Sa) + "\n";
                 System.out.println(str);
                 System.out.println("\n��Ӧ����\n");               
                 byte[] S2 = receiverKeyexchange.getSa();
                 str = "S2:" + Util.HexEncode(true,S2) + "\n";
                 System.out.println(str);
                 
                 if(java.util.Arrays.equals(SKa,SKb)==false) {
                     System.out.println("��Կȷ��ʧ��\n");
                     return;
                 }                 
                 else
                 {                 
                     System.out.println("��Կȷ�ϳɹ�\n");
                 }
                 
             }
        } finally {
            if(fIn!=null) {
                fIn.close();
            } 
            
            if(sm9Sender!=null)
            {
            	sm9Sender.free();            	
            }
            
            if(sm9Receiver!=null)
            {
            	sm9Receiver.free();            	
            }
            
        }

    }
}
