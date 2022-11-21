package net.netca.pki.crypto.android.libtest;

import android.support.multidex.MultiDexApplication;

import net.netca.pki.crypto.android.interfaces.NetcaCryptoFactory;
import net.netca.pki.crypto.android.interfaces.NetcaCryptoInterface;

/**
 * Created by Donggui on 2017/8/2.
 */

public class DemoApplication extends MultiDexApplication {
    NetcaCryptoInterface netcaCryptoInterface;
    @Override
    public void onCreate() {
        super.onCreate();
        netcaCryptoInterface = NetcaCryptoFactory.createNetcaCrypto(NetcaCryptoFactory.TYPE_JAR);

//        netcaCryptoInterface.addExtraParam("net.netca.pki.puhuakey.PHMobileKeyDeviceFactory","{\"mAppID\":\"MaNpjkjPnYcLI8BGE3Fh\",\"mAppSecret\":\"JDmMwzrmpqZLHoYB3mBijA9J9QXvqdwuHD0pSIageyKuKVVmo7J2lNUJshpmHMSZ\",\"mServerList\":[\"124.42.9.15:8082\"]}");
//        netcaCryptoInterface.addExtraParam("net.netca.pki.crypto.android.devicefactory.JNIDeviceFactory_61","{\"DefaultMethod\":2,\"DefaultServerAddress\":\"https://192.168.200.58:7071/softCertInterface/allService\", \"DefaultServerParam\":\"TLS\",\"RSAMethod\":2,\"RSAServerAddress\":\"https://192.168.200.58:7071/softCertInterface/allService\",\"RSAServerParam\":\"TLS\",\"ImportRSAMethod\":2,\"ImportRSAServerAddress\":\"https://192.168.200.58:7071/softCertInterface/allService\", \"ImportRSAServerParam\":\"TLS\",\"SM2Method\":2,\"SM2ServerAddress\":\"https://192.168.200.58:7071/softCertInterface/allService\",\"SM2ServerParam\":\"TLS\",\"ImportSM2Method\":2,\"ImportSM2ServerAddress\":\"https://192.168.200.58:7071/softCertInterface/allService\",\"ImportSM2ServerParam\":\"TLS\"}");
        netcaCryptoInterface.addExtraParam("net.netca.pki.mkey.MKGeneralDeviceFactory","{\"id\":\"200951922012717056\",\"u\":\"http://120.25.164.100:7091\"}");

    }

}
