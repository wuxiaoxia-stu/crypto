package net.netca.pki.crypto.android.libtest;

import android.content.Context;
import android.content.Intent;
import android.net.Uri;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileFilter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.security.MessageDigest;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.UUID;

/**
 * Created by Donggui on 2016/11/28.
 */
public class FileUtils {

    public static void installAPK(Context c, String path) {
        Intent it = new Intent();
        it.setAction(Intent.ACTION_INSTALL_PACKAGE);
        it.setData(Uri.fromFile(new File(path)));
        c.startActivity(it);
    }

    public static void createSoftDeviceFileV2(String filePath) throws Exception {
        File f = new File(filePath);
        if(f.exists()){
            return;
        }
        f.createNewFile();
        String softDevice = "[\""+ UUID.randomUUID().toString().replace("-", "")+"\",\"NetcaSoftDevice\",[]]";
        byte[] data = softDevice.getBytes("utf-8");
        MessageDigest md = MessageDigest.getInstance("SHA512");
        byte[] digest = md.digest(data);
        DataOutputStream dataOutputStrea = new DataOutputStream(new FileOutputStream(f));
        dataOutputStrea.writeInt(2);
        dataOutputStrea.writeInt(data.length);
        dataOutputStrea.write(data);
        dataOutputStrea.write(digest);
        dataOutputStrea.close();
    }

    public static boolean isSoftDeviceFormat(String file){
        try {
            int hashSize = 64;
            int bufSize = 1024;
            int headerSize = 8;
            byte[]header = new byte[headerSize];
            byte[]buf = new byte[bufSize];
            byte[]hashBuf = new byte[hashSize];
            File f = new File(file);
            MessageDigest md = MessageDigest.getInstance("SHA512");
            if (f.exists() && f.isFile()) {
                FileInputStream fis = new FileInputStream(f);
                long fileLen = f.length();
                fileLen-=hashSize;
                fileLen-=headerSize;
                //文件小于哈希值大小
                if(fileLen<0){
                    return false;
                }
                fis.read(header);
                //计算哈希值
                while(fileLen>0){
                    if(fileLen<bufSize){
                        buf = new byte[(int)fileLen];
                    }
                    int size = fis.read(buf);
                    md.update(buf, 0, size);
                    fileLen-=bufSize;
                }
                //读取文件中的哈希值
                fis.read(hashBuf);
                byte[] digest = md.digest();
                return Arrays.equals(digest, hashBuf);
            }
        }catch (Exception e){
            e.printStackTrace();
        }
        return false;
    }

    public static byte[] getFileHash(String filePath, MessageDigest md) throws IOException {
        if (md == null || filePath != null) {
            return null;
        }
        FileInputStream fileInputStream = new FileInputStream(new File(filePath));
        md.reset();
        byte[] buf = new byte[1024];
        int len = 0;
        while ((len = fileInputStream.read(buf)) > 0) {
            md.update(buf, 0, len);
        }
        return md.digest();
    }

    public static byte[] readAll(InputStream is) throws IOException{
        byte[] retData = new byte[0];
        if (is == null) {
            return retData;
        }
        ByteArrayOutputStream byteStream = new ByteArrayOutputStream();
        try{
            byte[] buf = new byte[1024];
            int len;
            while ((len = is.read(buf)) > 0) {
                byteStream.write(buf, 0, len);
            }
            retData = byteStream.toByteArray();
        }finally{
            try{
                byteStream.close();
            }catch(Exception e){
                e.printStackTrace();
            }
        }
        return retData;

    }
    static public List<File> getDirectoryFileList(final File f, final String filter){
        final List<File> fileList = new ArrayList<File>();
        if(!f.isDirectory()){
            return fileList;
        }
        File[] files = f.listFiles(new FileFilter() {
            @Override
            public boolean accept(File pathname) {
                if(pathname.getName().startsWith(".")){
                    return false;
                }
                if(filter==null||pathname.isDirectory()){
                    return true;
                }
                String [] filters = filter.split("\\|");
                for(String f:filters){
                    if(pathname.getName().endsWith(f.toLowerCase())|| pathname.getName().endsWith(f.toUpperCase())){
                        return true;
                    }
                }
                return false;
            }
        });
        fileList.addAll(Arrays.asList(files));
        return fileList;
    }

    static public List<File> getDirectoryFolder(final File f){
        final List<File> fileList = new ArrayList<File>();
        if(!f.isDirectory()){
            return fileList;
        }
        File[] files = f.listFiles(new FileFilter() {
            @Override
            public boolean accept(File pathname) {
                if(pathname.getName().startsWith(".")){
                    return false;
                }
                return pathname.isDirectory();
            }
        });
        fileList.addAll(Arrays.asList(files));
        return fileList;
    }

    public static void copy(InputStream fis, String filePath) throws IOException {
        File file = new File(filePath);
        file.delete();
        file.createNewFile();
        FileOutputStream fos = new FileOutputStream(file);
        try {
            byte[] buf = new byte[1024];
            int len = 0;
            while ((len = fis.read(buf)) > 0) {
                fos.write(buf, 0, len);
            }
        } finally {
            if (fis != null) {
                try {
                    fis.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (fos != null) {
                try {
                    fos.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static byte[] copy(InputStream fis, String filePath, MessageDigest md) throws IOException {
        File file = new File(filePath);
        file.delete();
        file.createNewFile();
        if (md != null) {
            md.reset();
        }
        FileOutputStream fos = new FileOutputStream(file);
        try {
            byte[] buf = new byte[1024];
            int len = 0;
            while ((len = fis.read(buf)) > 0) {
                fos.write(buf, 0, len);
                if (md != null) {
                    md.update(buf, 0, len);
                }
            }
            if (md != null) {
                return md.digest();
            } else {
                return null;
            }
        } finally {
            if (fis != null) {
                try {
                    fis.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (fos != null) {
                try {
                    fos.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static void copy(InputStream fis, OutputStream fos) throws IOException {
        try {
            byte[] buf = new byte[1024];
            int len = 0;
            while ((len = fis.read(buf)) > 0) {
                fos.write(buf, 0, len);
            }
        } finally {
            if (fis != null) {
                try {
                    fis.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (fos != null) {
                try {
                    fos.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
