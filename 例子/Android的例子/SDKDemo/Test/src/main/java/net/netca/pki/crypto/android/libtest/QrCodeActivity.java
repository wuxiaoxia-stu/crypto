package net.netca.pki.crypto.android.libtest;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

import net.netca.pki.crypto.android.interfaces.NetcaCryptoFactory;
import net.netca.pki.crypto.android.interfaces.NetcaCryptoInterface;

public class QrCodeActivity extends AppCompatActivity {
    private TextView tv_title_center;
    private NetcaCryptoInterface netcaCryptoInterface;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_qr_code);
        netcaCryptoInterface = NetcaCryptoFactory.createNetcaCrypto(NetcaCryptoFactory.TYPE_JAR);
        try {
            netcaCryptoInterface.init(this);
        }catch (Exception e){
            e.printStackTrace();
        }
        initView();
        initData();
    }

    @Override
    protected void onResume() {
        super.onResume();
        try {
            netcaCryptoInterface.init(this);
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    @Override
    protected void onPause() {
        super.onPause();
        try {
            netcaCryptoInterface.end();
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    private void initData() {
        tv_title_center.setText("二维码扫码");
    }

    private void initView() {
        tv_title_center = (TextView)findViewById(R.id.tv_title_center_text);

    }
}
