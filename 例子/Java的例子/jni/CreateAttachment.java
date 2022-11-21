import net.netca.pki.*;
import java.io.*;

public class CreateAttachment {
    private static boolean isAscii(String fileName) {
	char [] chs=fileName.toCharArray();
	for(int i=0;i<chs.length;i++) {
		if(chs[i]<0 || chs[i]>127) {
			return false;
		}
	}
	return true;
    }	    
    public static void main(String[] arg) throws Exception {
        if(arg.length!=2) {
            System.out.println("Usage: java CreateAttachment infile outfile");
            return;
        }

	Smime attachMent=null;
	Smime contentMime=null;
	Smime mime=null;
	FileOutputStream fOut=null;
        try {
            
	    String charset;
	    String attachFileName=arg[0];
	    if(isAscii(attachFileName)) {
		charset=null;
	    } else {
		charset="gbk";
	    }
	    attachMent=Smime.newAttachment(null,charset,attachFileName);
	    if(attachMent==null) {
		    System.out.println("创建附件失败");
		    return ;
	    }
	    
	    contentMime=new Smime(Smime.MIME_TYPE_BASIC);
	    contentMime.addHeader("Content-Type:text/plain;charset=\"gbk\"");
	    contentMime.addHeader("Content-Transfer-Encoding: quoted-printable");
	    
	    String content=Smime.encodeQuotedPrintable("测试附件".getBytes("gbk"));
	    contentMime.setBody(content);
	    
	    
	    mime=new Smime(Smime.MIME_TYPE_MULTIPART);
	    String boundary=mime.getBoundary();   
	    mime.addHeader("Content-Type","multipart/mixed",new String[] { "boundary=\""+boundary+"\"" });
	    
	    mime.addSubEntity(contentMime);
	    mime.addSubEntity(attachMent);

	    
            byte[] encode=mime.encode();
	    
            fOut=new FileOutputStream(arg[1]);
            fOut.write(encode);
            fOut.close();
            fOut=null;
	    
	    System.out.println("创建附件成功");
        } finally {
            if(fOut!=null){
		fOut.close();
	    }

            if(attachMent!=null) {
                attachMent.free();
            }

	    if(contentMime!=null) {
                contentMime.free();
            }

	    if(mime!=null) {
                mime.free();
            }
        }

    }


}

