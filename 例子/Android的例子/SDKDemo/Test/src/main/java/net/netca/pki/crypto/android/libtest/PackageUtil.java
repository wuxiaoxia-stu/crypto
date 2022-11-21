package net.netca.pki.crypto.android.libtest;

import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.os.Build;
import android.text.TextUtils;

import java.io.ByteArrayInputStream;
import java.security.cert.Certificate;
import java.security.cert.CertificateFactory;

public class PackageUtil {
    public static Certificate getPackageSignCert(Context context, String packageName)throws Exception{
        if (TextUtils.isEmpty(packageName)) {
            throw new Exception("包名参数为空");
        }
        PackageManager localPackageManager = context.getPackageManager();
        PackageInfo localPackageInfo = null;
        try {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
                localPackageInfo = localPackageManager.getPackageInfo(packageName, PackageManager.GET_SIGNING_CERTIFICATES);
                return CertificateFactory.getInstance("x.509").generateCertificate(new ByteArrayInputStream(localPackageInfo.signingInfo.getApkContentsSigners()[0].toByteArray()));
            }else{
                localPackageInfo = localPackageManager.getPackageInfo(packageName, PackageManager.GET_SIGNATURES);
                return CertificateFactory.getInstance("x.509").generateCertificate(new ByteArrayInputStream(localPackageInfo.signatures[0].toByteArray()));
            }
        } catch (PackageManager.NameNotFoundException localNameNotFoundException) {
            throw new Exception("应用未安装");
        }

    }

}
