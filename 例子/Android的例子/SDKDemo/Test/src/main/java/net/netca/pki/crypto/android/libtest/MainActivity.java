package net.netca.pki.crypto.android.libtest;

import android.Manifest;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.provider.Settings;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.text.TextUtils;
import android.util.Base64;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ToggleButton;

import net.netca.pki.Certificate;
import net.netca.pki.crypto.android.bluetooth.BluetoothDeviceItem;
import net.netca.pki.crypto.android.constant.NetcaPKIConst;
import net.netca.pki.crypto.android.interfaces.DeviceInterface;
import net.netca.pki.crypto.android.interfaces.EnvelopedDataDecryptInterface;
import net.netca.pki.crypto.android.interfaces.EnvelopedDataEncryptInterface;
import net.netca.pki.crypto.android.interfaces.NetcaCryptoFactory;
import net.netca.pki.crypto.android.interfaces.NetcaCryptoInterface;
import net.netca.pki.crypto.android.interfaces.QrcodeSignInterface;
import net.netca.pki.crypto.android.interfaces.SignatureInterface;
import net.netca.pki.crypto.android.interfaces.SignedDataSignInterface;
import net.netca.pki.crypto.android.interfaces.SignedDataVerifyInterface;
import net.netca.pki.crypto.android.interfaces.TimeStampInterface;
import net.netca.pki.crypto.android.utils.ByteUtils;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class MainActivity extends AppCompatActivity implements View.OnClickListener, CompoundButton.OnCheckedChangeListener {
    private static final int READ_WRITE_STORAGE = 1;
    private static final int REQUEST_CODE_WRITE_SEAL = 3;
    private static final int DISPLAY_TEXT = 4;
    private static final int DISPLAY_IMAGE = 5;
    private static final int REQUEST_CODE_SIGN_PDF = 6;
    private static final int REQUEST_CODE_VERIFY_PDF = 7;
    private static final int TOAST_TEXT = 8;
    private static final int BLE_PERMISSION = 9;
    private static final int DISPLAY_DEVICE_SELECT = 10;
    private static final int QEQUEST_QRCODE = 11;
    private static final int APPEND_TO_TEXT = 12;
    private static final int DISPLAY_TEXT_SIGNEDDATA = 13;
    private static final int DISPLAY_TEXT_ENVELOPEDDATA = 14;
    private static final int DISPLAY_TEXT_SIGNATURE = 15;

    TextView tv_result;
    ImageView iv_icon;
    EditText edt_password;
    Button btn_select_sign_cert;
    Button btn_select_enc_cert;
    Button btn_verify_cert_ocsp;
    Button btn_verify_cert_crl;
    EditText edt_signature;
    Button btn_signature_sign;
    Button btn_signature_verify;
    EditText edt_signeddata;
    Button btn_signeddata_sign_attach;
    Button btn_signeddata_sign_detach;
    Button btn_signeddata_verify;
    EditText edt_envelopeddata;
    Button btn_envelopeddata_enc;
    Button btn_envelopeddata_dec;
    Button btn_select_device;
    EditText edt_seal_index;
    Button btn_seal_count;
    Button btn_seal_name;
    Button btn_read_seal;
    Button btn_write_seal;
    Button btn_sign_pdf;
    Button btn_verify_pdf;
    EditText edt_option_url;
    Button btn_del_seal;
    Button btn_scan_qrcode;
    EditText edt_authcode;
    EditText edt_timestamp_url;
    Spinner spn_tiemstamp_hash_algo;
    EditText edt_timestamp_origin;
    Button btn_request_timestamp;
    Button btn_verify_timestamp;
    ToggleButton tgb_test_sign;
    ToggleButton tgb_test_decrypt;
    Button btn_login;
    Button btn_apply_cert;

    EditText edt_envelopeddata_out;
    EditText edt_signature_out;
    EditText edt_signeddata_out;
    EditText edt_new_pin;
    Button btn_change_pin;

    byte[] signedData;
    byte[] signature;
    byte[] envelopedData;
    byte[] imageData;
    Certificate signCert;
    Certificate encCert;
    DeviceInterface deviceInterface;
    List<DeviceInterface> deviceInterfaceList;
    int index;
    Bitmap bitmap;
    BroadcastReceiver mReceiver;
    byte[] timestamp_token;

    ExecutorService executorService = Executors.newFixedThreadPool(1);
    NetcaCryptoInterface netcaCryptoInterface;
    AlertDialog alertDialog;
    ArrayAdapter<String> dataAdapter;
    BluetoothAdapter bluetoothAdapter;
    //搜索的蓝牙列表
    List<String> bluetoothNameList;
    List<String> bluetoothMacList;
    //已连接蓝牙列表
    List<BluetoothDeviceItem> bluetoothConnectedDeviceItemList = new ArrayList<>();
    List<String> bluetoothConnectedNameList = new ArrayList<>();
    Thread testThread;

    Handler handler = new Handler(){
        @Override
        public void handleMessage(Message msg) {
            switch (msg.what){
                case DISPLAY_TEXT:
                    iv_icon.setVisibility(View.GONE);
                    tv_result.setText((String)msg.obj);
                    break;
                case DISPLAY_TEXT_ENVELOPEDDATA:
                    iv_icon.setVisibility(View.GONE);
                    tv_result.setText((String)msg.obj);
                    edt_envelopeddata_out.setText((String)msg.obj);
                    break;
                case DISPLAY_TEXT_SIGNATURE:
                    iv_icon.setVisibility(View.GONE);
                    tv_result.setText((String)msg.obj);
                    edt_signature_out.setText((String)msg.obj);
                    break;
                case DISPLAY_TEXT_SIGNEDDATA:
                    iv_icon.setVisibility(View.GONE);
                    tv_result.setText((String)msg.obj);
                    edt_signeddata_out.setText((String)msg.obj);
                    break;
                case APPEND_TO_TEXT:
                    iv_icon.setVisibility(View.GONE);
                    tv_result.setText(tv_result.getText().toString()+(String)msg.obj);
                    break;
                case DISPLAY_IMAGE:
                    if(bitmap!=null){
                        iv_icon.setVisibility(View.VISIBLE);
                        iv_icon.setImageBitmap(bitmap);
                    }
                    break;
                case TOAST_TEXT:
                    Toast.makeText(MainActivity.this, (String)msg.obj, Toast.LENGTH_LONG).show();
                    break;
                case DISPLAY_DEVICE_SELECT:
                    List<String>deviceIds = new ArrayList<>();
                    for(DeviceInterface di:deviceInterfaceList){
                        try {
                            deviceIds.add(di.getDeviceId());
                        }catch (Exception e){
                            e.printStackTrace();
                        }
                    }
                    ArrayAdapter<String> adapter = new ArrayAdapter<String>(MainActivity.this, android.R.layout.simple_list_item_1, deviceIds);
                    AlertDialog dialog=new AlertDialog.Builder(MainActivity.this).setAdapter(adapter, new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialogInterface, int i) {
                            deviceInterface = deviceInterfaceList.get(i);
                            try {
                                displayResult("选择一个设备:" + deviceInterface.getDeviceId());
                            }catch (Exception e){
                                e.printStackTrace();
                            }
                        }
                    }).setNegativeButton("取消", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialogInterface, int i) {
                            dialogInterface.cancel();
                        }
                    }).setCancelable(false).create();
                    dialog.show();
                    break;
            }
        }
    };
    private Thread refreshThread;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        netcaCryptoInterface = NetcaCryptoFactory.createNetcaCrypto(NetcaCryptoFactory.TYPE_JAR);
        try {
            netcaCryptoInterface.init(this);
        }catch (Exception e){
            e.printStackTrace();
        }

        initView();
        requestPermission();
        initListener();
        initData();
        refreshDevice();
    }


    private void initReceiver() {
        if(mReceiver==null) {
            mReceiver = new BroadcastReceiver() {

                @Override
                public void onReceive(Context context, Intent intent) {
                    String action = intent.getAction();
                    try {
                        final BluetoothDevice device = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);
                        String mac = device.getAddress();
                        String name = device.getName();
                        if (name == null) {
                            name = "";
                        }
                        if (BluetoothDevice.ACTION_FOUND.equals(action)) {
                            if (netcaCryptoInterface != null && netcaCryptoInterface.getBluetoothInterface().isSupport(mac, name)&&!bluetoothMacList.contains(mac)) {
                                bluetoothMacList.add(mac);
                                bluetoothNameList.add(name);
                                dataAdapter.notifyDataSetChanged();
                            }

                        }
                    }catch (Exception e){
                        e.printStackTrace();
                    }
                }
            };
        }
        IntentFilter filterFound = new IntentFilter(BluetoothDevice.ACTION_FOUND);
        registerReceiver(mReceiver, filterFound);
    }

    private void stopReceiver(){
        if(mReceiver!=null){
            unregisterReceiver(mReceiver);
            mReceiver = null;
        }
    }

    private void initData() {
        bluetoothMacList = new ArrayList<String>();
        bluetoothNameList = new ArrayList<String>();
        dataAdapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, bluetoothNameList);
    }

    private void initListener() {

        btn_select_sign_cert.setOnClickListener(this);
        btn_select_enc_cert.setOnClickListener(this);
        btn_verify_cert_ocsp.setOnClickListener(this);
        btn_verify_cert_crl.setOnClickListener(this);
        btn_signature_sign.setOnClickListener(this);
        btn_signature_verify.setOnClickListener(this);
        btn_signeddata_sign_attach.setOnClickListener(this);
        btn_signeddata_sign_detach.setOnClickListener(this);
        btn_signeddata_verify.setOnClickListener(this);
        edt_envelopeddata.setOnClickListener(this);
        btn_envelopeddata_enc.setOnClickListener(this);
        btn_envelopeddata_dec.setOnClickListener(this);
        btn_select_device.setOnClickListener(this);
        btn_seal_count.setOnClickListener(this);
        btn_seal_name.setOnClickListener(this);
        btn_read_seal.setOnClickListener(this);
        btn_write_seal.setOnClickListener(this);
        btn_sign_pdf.setOnClickListener(this);
        btn_verify_pdf.setOnClickListener(this);
        btn_del_seal.setOnClickListener(this);
        btn_scan_qrcode.setOnClickListener(this);
        btn_request_timestamp.setOnClickListener(this);
        btn_verify_timestamp.setOnClickListener(this);
        tgb_test_sign.setOnCheckedChangeListener(this);
        tgb_test_decrypt.setOnCheckedChangeListener(this);
        btn_login.setOnClickListener(this);
        btn_apply_cert.setOnClickListener(this);

        btn_change_pin.setOnClickListener(this);

    }

    private void initView() {
        tv_result = (TextView)findViewById(R.id.tv_result);
        iv_icon = (ImageView)findViewById(R.id.iv_icon);
        edt_password = (EditText)findViewById(R.id.edt_password);
        btn_login = (Button)findViewById(R.id.btn_login);
        btn_select_sign_cert = (Button)findViewById(R.id.btn_select_sign_cert);
        btn_select_enc_cert = (Button)findViewById(R.id.btn_select_enc_cert);
        btn_verify_cert_ocsp = (Button)findViewById(R.id.btn_verify_cert_ocsp);
        btn_verify_cert_crl = (Button)findViewById(R.id.btn_verify_cert_crl);
        edt_signature = (EditText)findViewById(R.id.edt_signature);
        btn_signature_sign = (Button)findViewById(R.id.btn_signature_sign);
        btn_signature_verify = (Button)findViewById(R.id.btn_signature_verify);
        edt_signeddata = (EditText)findViewById(R.id.edt_signeddata);
        btn_signeddata_sign_attach = (Button)findViewById(R.id.btn_signeddata_sign_attach);
        btn_signeddata_sign_detach = (Button)findViewById(R.id.btn_signeddata_sign_detach);
        btn_signeddata_verify = (Button)findViewById(R.id.btn_signeddata_verify);
        edt_envelopeddata = (EditText)findViewById(R.id.edt_envelopeddata);
        btn_envelopeddata_enc = (Button)findViewById(R.id.btn_envelopeddata_enc);
        btn_envelopeddata_dec = (Button)findViewById(R.id.btn_envelopeddata_dec);
        edt_option_url = (EditText)findViewById(R.id.edt_option_url);
        btn_select_device = (Button)findViewById(R.id.btn_select_device);
        edt_seal_index = (EditText)findViewById(R.id.edt_seal_index);
        btn_seal_count = (Button)findViewById(R.id.btn_seal_count);
        btn_seal_name = (Button)findViewById(R.id.btn_seal_name);
        btn_read_seal = (Button)findViewById(R.id.btn_read_seal);
        btn_write_seal = (Button)findViewById(R.id.btn_write_seal);
        btn_sign_pdf = (Button)findViewById(R.id.btn_sign_pdf);
        btn_verify_pdf = (Button)findViewById(R.id.btn_verify_pdf);
        btn_del_seal = (Button)findViewById(R.id.btn_del_seal);
        btn_scan_qrcode = (Button)findViewById(R.id.btn_scan_qrcode);
        edt_authcode = (EditText)findViewById(R.id.edt_authcode);
        edt_timestamp_url = (EditText)findViewById(R.id.edt_timestamp_url);
        spn_tiemstamp_hash_algo = (Spinner)findViewById(R.id.spn_tiemstamp_hash_algo);
        edt_timestamp_origin = (EditText)findViewById(R.id.edt_timestamp_origin);
        btn_request_timestamp = (Button)findViewById(R.id.btn_request_timestamp);
        btn_verify_timestamp = (Button)findViewById(R.id.btn_verify_timestamp);
        tgb_test_sign = (ToggleButton)findViewById(R.id.tgb_test_sign);
        tgb_test_decrypt = (ToggleButton)findViewById(R.id.tgb_test_decrypt);
        btn_apply_cert = (Button)findViewById(R.id.btn_apply_cert);

        edt_envelopeddata_out = (EditText)findViewById(R.id.edt_envelopeddata_out);
        edt_signature_out  = (EditText)findViewById(R.id.edt_signature_out);
        edt_signeddata_out  = (EditText)findViewById(R.id.edt_signeddata_out);

        edt_new_pin = (EditText)findViewById(R.id.edt_new_pin);
        btn_change_pin = (Button)findViewById(R.id.btn_change_pin);


    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main,menu);
        return super.onCreateOptionsMenu(menu);
    }
    public void requestBLEPermission() {
        if (Build.VERSION.SDK_INT >= 23) {
            if (ContextCompat.checkSelfPermission(this, Manifest.permission.ACCESS_COARSE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
                ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.ACCESS_COARSE_LOCATION},
                        BLE_PERMISSION);

            }
        }
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()){
            case R.id.menu_refresh:
                refreshDevice();

                break;
            case R.id.menu_search:
                requestBLEPermission();
                bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
                if(bluetoothAdapter==null){
                    Toast.makeText(this, "手机不支持蓝牙", Toast.LENGTH_SHORT).show();
                }else if(!bluetoothAdapter.isEnabled()){
                    Toast.makeText(this, "蓝牙没有打开", Toast.LENGTH_SHORT).show();
                }else{
                    bluetoothAdapter.startDiscovery();
                    bluetoothNameList.clear();
                    bluetoothMacList.clear();
                    if(alertDialog==null){
                        alertDialog=new AlertDialog.Builder(this).setAdapter(dataAdapter, new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                connectBluetoothDevice(i);
                            }
                        }).setNegativeButton("取消", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                bluetoothAdapter.cancelDiscovery();
                                alertDialog.cancel();
                            }
                        }).setCancelable(false).create();
                        alertDialog.show();
                    }else{
                        dataAdapter.notifyDataSetChanged();
                        alertDialog.show();
                    }
                }
                break;
            case R.id.menu_connect_list:
                try {
                    bluetoothConnectedDeviceItemList = netcaCryptoInterface.getBluetoothInterface().getConnectDeviceList();
                    Log.e("DEVICE", bluetoothConnectedDeviceItemList.size()+"");
                    if(bluetoothConnectedDeviceItemList==null||bluetoothConnectedDeviceItemList.isEmpty()){
                        Toast.makeText(this, "没有连接设备", Toast.LENGTH_LONG).show();
                    }else{
                        bluetoothConnectedNameList = new ArrayList<>();
                        for(BluetoothDeviceItem bdi:bluetoothConnectedDeviceItemList){
                            bluetoothConnectedNameList.add(bdi.getName());
                        }
                        ArrayAdapter<String> adapter = new ArrayAdapter<String>(MainActivity.this, android.R.layout.simple_list_item_1, bluetoothConnectedNameList);
                        AlertDialog dialog=new AlertDialog.Builder(MainActivity.this).setAdapter(adapter, new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                disconnectBluetoothDevice(i);
                            }
                        }).setNegativeButton("取消", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                dialogInterface.cancel();
                            }
                        }).setCancelable(false).create();
                        dialog.show();

                    }

                }catch (Exception e){
                    displayResult(e.getMessage());
                    e.printStackTrace();
                }

                break;
        }
        return super.onOptionsItemSelected(item);
    }

    private void refreshDevice() {
        if(refreshThread ==null||!refreshThread.isAlive()) {
            refreshThread = new Thread() {
                @Override
                public void run() {
                    try {
                        if (netcaCryptoInterface != null) {
                            toastResult("开始刷新");
                            netcaCryptoInterface.refresh();
                            toastResult("刷新结束");
                        }

                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            };
            refreshThread.start();
        }else{
            toastResult("正在刷新...");
        }
    }

    private void disconnectBluetoothDevice(int i){
        final String mac = bluetoothConnectedDeviceItemList.get(i).getMac();
        executorService.execute(new Runnable() {
            @Override
            public void run() {
                try {
                    netcaCryptoInterface.getBluetoothInterface().disconnect(mac);
                    toastResult("断开成功");
                }catch (Exception e){
                    e.printStackTrace();
                    displayResult(e.getMessage());
                }
            }
        });
    }

    private void toastResult(String result) {
        Message msg = new Message();
        msg.what = TOAST_TEXT;
        msg.obj = result;
        handler.sendMessage(msg);
    }

    private void connectBluetoothDevice(int i) {
        final String bluetoothName = bluetoothNameList.get(i);
        final String bluetoothMac = bluetoothMacList.get(i);
        executorService.execute(new Runnable() {
            @Override
            public void run() {
                try {
                    long startTs = System.currentTimeMillis();
                    netcaCryptoInterface.getBluetoothInterface().connect(bluetoothMac, bluetoothName);
                    long lastTs = System.currentTimeMillis();
                    displayResult(String.format("连接成功:耗时%d ms", lastTs-startTs));

                }catch (Exception e){
                    e.printStackTrace();
                    displayResult(e.getMessage());
                }
            }
        });
    }

    @Override
    protected void onResume() {
        super.onResume();
        netcaCryptoInterface.updateActivity(this);
    }

    @Override
    protected void onPause() {
        super.onPause();
        netcaCryptoInterface.updateActivity(null);
    }

    @Override
    protected void onStart() {
        super.onStart();
        initReceiver();

    }

    @Override
    protected void onStop() {
        super.onStop();
    }

    @Override
    protected void onDestroy() {
        stopReceiver();
        super.onDestroy();
    }

    public void displayResult(final String result){

        Message msg = new Message();
        msg.what = DISPLAY_TEXT;
        msg.obj = result;
        handler.sendMessage(msg);
    }

    public void outputSignedData(String result){
        Message msg = new Message();
        msg.what = DISPLAY_TEXT_SIGNEDDATA;
        msg.obj = result;
        handler.sendMessage(msg);
    }

    public void outputEnvelopedData(String result){
        Message msg = new Message();
        msg.what = DISPLAY_TEXT_ENVELOPEDDATA;
        msg.obj = result;
        handler.sendMessage(msg);
    }

    public void outputSignature(String result){
        Message msg = new Message();
        msg.what = DISPLAY_TEXT_SIGNATURE;
        msg.obj = result;
        handler.sendMessage(msg);
    }

    public void appendResult(final String result){

        Message msg = new Message();
        msg.what = APPEND_TO_TEXT;
        msg.obj = result;
        handler.sendMessage(msg);
    }
    private void requestPermission() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            if (!Settings.canDrawOverlays(this)) {
                AlertDialog systemTipDialog = new AlertDialog.Builder(MainActivity.this)
                        .setCancelable(false)
                        .setTitle("提示")
                        .setMessage("SDK正常运行需要悬浮窗权限！是否设置?")
                        .setPositiveButton("是", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                Intent intent = new Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION);
                                intent.setData(Uri.parse("package:" + getPackageName()));
                                startActivityForResult(intent, 1);
                            }
                        })
                        .setNegativeButton("否", null)
                        .show();
            }
        }
        hasStoragePermission();
    }
    private boolean hasStoragePermission() {
        if(Build.VERSION.SDK_INT>=23){
            if(ContextCompat.checkSelfPermission(this, Manifest.permission.WRITE_EXTERNAL_STORAGE)!= PackageManager.PERMISSION_GRANTED){
                requestPermissions(new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE, Manifest.permission.READ_EXTERNAL_STORAGE},
                        READ_WRITE_STORAGE);
                return false;
            }
        }
        return true;
    }

    @Override
    public void onClick(View view) {
        if(view == btn_apply_cert){
            Intent it = new Intent();
            //如需微信支付，提供相关包名以及签名证书用于注册微信支付id。
            //it.putExtra(WebViewActivity.PAY_ID_PARAMS,"wechat id need netca provide");
            it.setClass(this,net.netca.pki.netcaview.activity.WebViewActivity.class);
            it.putExtra("self_service", "https://wxbpms.cnca.net/um/");
            startActivity(it);
        }
        if(view == btn_login){
            Intent it = new Intent();
            it.setClass(this,LoginActivity.class);
            startActivity(it);
        }
        if(view == btn_scan_qrcode){
            if(signCert==null){
                Toast.makeText(this, "请选择签名证书", Toast.LENGTH_LONG).show();
                return ;
            }
            String password = edt_password.getText().toString();
            if(TextUtils.isEmpty(password)){
                Toast.makeText(this, "请输入pin码", Toast.LENGTH_SHORT).show();
                return ;
            }

            Intent it = new Intent();
            it.setClass(this, QrCodeActivity.class);
            startActivityForResult(it, QEQUEST_QRCODE);
        }
        if(view == btn_select_sign_cert){
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    try {
                        signCert = netcaCryptoInterface.getCertInterface().getSingleSignCert();
                        if(signCert!=null) {
                            displayResult(signCert.pemEncode());
                        }else{
                            displayResult("没有证书或没选择证书");
                        }
                    }catch (Exception e){
                        displayResult(e.getMessage());
                        e.printStackTrace();
                    }
                }
            });
        }
        if(view == btn_select_enc_cert){
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    try {
                        encCert = netcaCryptoInterface.getCertInterface().getSingleEncCert();
                        if(encCert!=null) {
                            displayResult(encCert.pemEncode());
                        }else{
                            displayResult("没有证书或没选择证书");
                        }
                    }catch (Exception e){
                        displayResult(e.getMessage());
                        e.printStackTrace();
                    }
                }
            });
        }

        if(view == btn_verify_cert_crl){
            if(signCert==null){
                Toast.makeText(this, "请选择签名证书", Toast.LENGTH_LONG).show();
                return ;
            }
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    try {
                        String url = edt_option_url.getText().toString();
                        byte[]crlData = netcaCryptoInterface.getCertInterface().verifyCertByCrl(signCert, url);
                        displayResult("CRL证书可用");
                    }catch (Exception e){
                        displayResult(e.getMessage());
                        e.printStackTrace();
                    }
                }
            });
        }
        if(view == btn_verify_cert_ocsp){
            if(signCert==null){
                Toast.makeText(this, "请选择签名证书", Toast.LENGTH_LONG).show();
                return ;
            }
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    try {
                        String url = edt_option_url.getText().toString();
                        byte[]ocspData = netcaCryptoInterface.getCertInterface().verifyCertByOcsp(signCert, url);
                        displayResult("OCSP证书可用");
                    }catch (Exception e){
                        displayResult(e.getMessage());
                        e.printStackTrace();
                    }
                }
            });
        }
        if(view == btn_signeddata_sign_attach){
            final String data = edt_signeddata.getText().toString();
            if(TextUtils.isEmpty(data)){
                Toast.makeText(this, "请输入签名输入", Toast.LENGTH_LONG).show();
                return;
            }
            if(signCert==null){
                Toast.makeText(this, "请选择签名证书", Toast.LENGTH_LONG).show();
                return ;
            }
            final String password = edt_password.getText().toString();
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    try {
                        SignedDataSignInterface signedDataSignInterface = netcaCryptoInterface.getSignedDataSignInterface();
                        if(netcaCryptoInterface.getCertInterface().isSm2(signCert)) {
                            signedDataSignInterface.setSignAlgorithm(0, NetcaPKIConst.Signature.SM3WITHSM2);
                        }else{
                            signedDataSignInterface.setSignAlgorithm(0, NetcaPKIConst.Signature.SHA256WITHRSA);
                        }
                        signedDataSignInterface.setSignCertificate(signCert);
                        signedDataSignInterface.setDetached(false);
                        signedDataSignInterface.setIncludeCertOption(NetcaPKIConst.SignedData.INCLUDE_CERT_OPTION_CERTPATHWITHROOT);
                        signedData = signedDataSignInterface.sign(password, data.getBytes("utf-8"),0, data.getBytes("utf-8").length);
                        final String ts_url = edt_timestamp_url.getText().toString();
                        if(!TextUtils.isEmpty(ts_url)){
                            signedData = signedDataSignInterface.addTimeStamp(ts_url);
                        }
                        outputSignedData(Base64.encodeToString(signedData, Base64.NO_WRAP));
//                        displayResult(Base64.encodeToString(signedData, Base64.NO_WRAP));

                    }catch (Exception e){
                        e.printStackTrace();
                        displayResult(e.getMessage());
                    }
                }
            });
        }
        if(view == btn_signeddata_sign_detach){
            final String data = edt_signeddata.getText().toString();
            if(TextUtils.isEmpty(data)){
                Toast.makeText(this, "请输入签名输入", Toast.LENGTH_LONG).show();
                return;
            }
            if(signCert==null){
                Toast.makeText(this, "请选择签名证书", Toast.LENGTH_LONG).show();
                return ;
            }
            final String password = edt_password.getText().toString();
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    try {
                        SignedDataSignInterface signedDataSignInterface = netcaCryptoInterface.getSignedDataSignInterface();
                        if(netcaCryptoInterface.getCertInterface().isSm2(signCert)) {
                            signedDataSignInterface.setSignAlgorithm(0, NetcaPKIConst.Signature.SM3WITHSM2);
                        }else{
                            signedDataSignInterface.setSignAlgorithm(0, NetcaPKIConst.Signature.SHA256WITHRSA);
                        }
                        signedDataSignInterface.setSignCertificate(signCert);
                        signedDataSignInterface.setDetached(true);
                        signedDataSignInterface.setIncludeCertOption(NetcaPKIConst.SignedData.INCLUDE_CERT_OPTION_CERTPATHWITHROOT);
                        signedData = signedDataSignInterface.sign(password, data.getBytes("utf-8"),0, data.getBytes("utf-8").length);
                        final String ts_url = edt_timestamp_url.getText().toString();
                        if(!TextUtils.isEmpty(ts_url)){
                            signedData = signedDataSignInterface.addTimeStamp(ts_url);
                        }
                        outputSignedData(Base64.encodeToString(signedData, Base64.NO_WRAP));
//                        displayResult(Base64.encodeToString(signedData, Base64.NO_WRAP));
                    }catch (Exception e){
                        e.printStackTrace();
                        displayResult(e.getMessage());
                    }
                }
            });
        }
        if(view == btn_signeddata_verify){
            String text = edt_signeddata_out.getText().toString();
            try{
                signedData = null;
                signedData = Base64.decode(text,Base64.NO_WRAP);
            }catch (Exception e){
                e.printStackTrace();
            }
            if(signedData==null||signedData.length == 0){
                Toast.makeText(this, "请先进行签名", Toast.LENGTH_LONG).show();
                return;
            }
            final String data = edt_signeddata.getText().toString();
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    try {
                        SignedDataVerifyInterface signedDataVerifyInterface = netcaCryptoInterface.getSignedDataVerifyInterface();
                        signedDataVerifyInterface.setVerifyLevel(NetcaPKIConst.SignedData.VERIFY_LEVEL_VERIFY_SIGNATURE_ONLY);
                        if(!signedDataVerifyInterface.isSignedData(signedData)){
                            displayResult("非signedData 数据");
                            return;
                        }
                        boolean result = signedDataVerifyInterface.signedDataVerify(data.getBytes("utf-8"), signedData);
                        if(result){
                            List<Certificate> certificates = signedDataVerifyInterface.getSignCerts();
                            displayResult("验证通过,原文 "+data +" 签名证书:"+ certificates.get(0).pemEncode());
                        }else{
                            displayResult("验证不通过");
                        }

                    }catch (Exception e){
                        e.printStackTrace();
                        displayResult(e.getMessage());
                    }
                }
            });
        }
        if(view == btn_envelopeddata_enc){
            final String data = edt_envelopeddata.getText().toString();
            if(TextUtils.isEmpty(data)){
                Toast.makeText(this, "请输入加密数据", Toast.LENGTH_LONG).show();
                return;
            }
            if(encCert==null){
                Toast.makeText(this, "请选择加密证书", Toast.LENGTH_LONG).show();
                return ;
            }
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    try {

                        EnvelopedDataEncryptInterface envelopedDataEncryptInterface = netcaCryptoInterface.getEnvelopedDataEncryptInterface();
                        envelopedData = envelopedDataEncryptInterface.envelopedDataEncrypt(Arrays.asList(encCert), data.getBytes("utf-8"));
                        outputEnvelopedData(Base64.encodeToString(envelopedData, Base64.NO_WRAP));
//                        displayResult(Base64.encodeToString(envelopedData, Base64.NO_WRAP));
                    }catch (Exception e){
                        e.printStackTrace();
                        displayResult(e.getMessage());
                    }
                }
            });
        }
        if(view == btn_envelopeddata_dec){
            String text = edt_envelopeddata_out.getText().toString();
            try{
                envelopedData = null;
                envelopedData = Base64.decode(text,Base64.NO_WRAP);
            }catch (Exception e){
                e.printStackTrace();
            }
            if(envelopedData==null||envelopedData.length == 0){
                Toast.makeText(this, "请先进行加密", Toast.LENGTH_LONG).show();
                return;
            }
            final String password = edt_password.getText().toString();
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    try {
                        EnvelopedDataDecryptInterface envelopedDataDecryptInterface = netcaCryptoInterface.getEnvelopedDataDecryptInterface();
                        byte[] origin = envelopedDataDecryptInterface.decrypt(password, envelopedData, 0, envelopedData.length);
                        displayResult(new String(origin, "utf-8"));

                    }catch (Exception e){
                        e.printStackTrace();
                        displayResult(e.getMessage());
                    }
                }
            });
        }
        if(view == btn_signature_sign){
            final String data = edt_signature.getText().toString();
            if(signCert==null){
                Toast.makeText(this, "请选择签名证书", Toast.LENGTH_LONG).show();
                return ;
            }
            final String password = edt_password.getText().toString();
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    try {
                        String tsaUrl = null;
                        SignatureInterface signatureInterface = netcaCryptoInterface.getSignatureInterface();
                        if(netcaCryptoInterface.getCertInterface().isSm2(signCert)) {
                            signatureInterface.init(NetcaPKIConst.Signature.SM3WITHSM2, signCert, password);
                        }else{
                            signatureInterface.init(NetcaPKIConst.Signature.SHA256WITHRSA, signCert, password);
                        }

                        signatureInterface.signUpdate(data.getBytes("utf-8"), 0, data.getBytes("utf-8").length);
                        signature = signatureInterface.sign();
                        outputSignature(Base64.encodeToString(signature, Base64.NO_WRAP));
//                        displayResult(Base64.encodeToString(signature, Base64.NO_WRAP));
                    }catch (Exception e){
                        e.printStackTrace();
                        displayResult(e.getMessage());
                    }
                }
            });
        }
        if(view == btn_signature_verify){
            final String data = edt_signature.getText().toString();

            String text = edt_signature_out.getText().toString();
            try{
                signature = null;
                signature = Base64.decode(text,Base64.NO_WRAP);
            }catch (Exception e){
                e.printStackTrace();
            }

            if(signature==null){
                Toast.makeText(this, "请先签名", Toast.LENGTH_SHORT).show();
                return;
            }
            if(signCert==null){
                Toast.makeText(this, "请选择签名证书", Toast.LENGTH_LONG).show();
                return ;
            }
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    try {

                        SignatureInterface signatureInterface = netcaCryptoInterface.getSignatureInterface();
                        if(netcaCryptoInterface.getCertInterface().isSm2(signCert)) {
                            signatureInterface.init(NetcaPKIConst.Signature.SM3WITHSM2, signCert, null);
                        }else{
                            signatureInterface.init(NetcaPKIConst.Signature.SHA256WITHRSA, signCert, null);
                        }
                        signatureInterface.verifyUpdate(data.getBytes("utf-8"), 0, data.getBytes("utf-8").length);
                        boolean verify = signatureInterface.verify(signature);
                        displayResult(verify?"验证通过":"验证不通过");
                    }catch (Exception e){
                        e.printStackTrace();
                        displayResult(e.getMessage());
                    }
                }
            });
        }

        if(view == btn_select_device){
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    try {
                        deviceInterfaceList = netcaCryptoInterface.getDeviceSetInterface().getDeviceList();
                        Log.e("DEVICE", deviceInterfaceList.size()+"");
                        if(deviceInterfaceList==null||deviceInterfaceList.isEmpty()){
                            displayResult("没找到可用设备");
                        }else{
                            if(deviceInterfaceList.size()==1) {
                                deviceInterface = deviceInterfaceList.get(0);
                                displayResult("选择一个设备:" + deviceInterface.getDeviceId());
                            }else{
                                handler.sendEmptyMessage(DISPLAY_DEVICE_SELECT);
                            }
                        }
                    }catch (Exception e){
                        e.printStackTrace();
                        displayResult(e.getMessage());
                    }

                }
            });
        }
        if(view == btn_seal_count){
            if(deviceInterface==null){
                Toast.makeText(this, "请先选择设备", Toast.LENGTH_SHORT).show();
                return;
            }
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    try {
                        int count = deviceInterface.getSealCount();
                        displayResult("章个数:"+count);

                    }catch (Exception e){
                        e.getMessage();
                        displayResult(e.getMessage());
                    }
                }
            });
        }
        if(view == btn_seal_name){
            if(deviceInterface==null){
                Toast.makeText(this, "请先选择设备", Toast.LENGTH_SHORT).show();
                return;
            }
            index = 0 ;
            try {
                index = Integer.parseInt(edt_seal_index.getText().toString());
            }catch (Exception e){
                e.printStackTrace();
            }
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    try {
                        String name = deviceInterface.getSealName(index);
                        displayResult("章名:"+name);

                    }catch (Exception e){
                        e.getMessage();
                        displayResult(e.getMessage());
                    }
                }
            });
        }
        if(view == btn_write_seal){
            if(deviceInterface==null){
                Toast.makeText(this, "请先选择设备", Toast.LENGTH_SHORT).show();
                return;
            }
            index = 0 ;
            try {
                index = Integer.parseInt(edt_seal_index.getText().toString());
            }catch (Exception e){
                e.printStackTrace();
            }
            String password = edt_password.getText().toString();
            if(TextUtils.isEmpty(password)){
                Toast.makeText(this, "请输入pin码", Toast.LENGTH_SHORT).show();
                return ;
            }
            Intent it = new Intent();
            it.setClass(this, FileListActivity.class);
            it.putExtra(FileListActivity.FILE_FILTER, ".gif|.jpg|.png");
            startActivityForResult(it, REQUEST_CODE_WRITE_SEAL);

        }
        if(view == btn_change_pin){
            if(deviceInterface==null){
                Toast.makeText(this, "请先选择设备", Toast.LENGTH_SHORT).show();
                return;
            }
            String password = edt_password.getText().toString();
            if(TextUtils.isEmpty(password)){
                Toast.makeText(this, "请输入pin码", Toast.LENGTH_SHORT).show();
                return ;
            }
            String new_password = edt_new_pin.getText().toString();
            if(TextUtils.isEmpty(new_password)){
                Toast.makeText(this, "请输入新pin码", Toast.LENGTH_SHORT).show();
                return ;
            }
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    try {
                        String pwd = edt_password.getText().toString();
                        String new_pwd = edt_new_pin.getText().toString();
                        if(deviceInterface.changePin(pwd, new_pwd)) {
                            displayResult("修改成功");
                        }else{
                            displayResult("修改失败");
                        }


                    }catch (Exception e){
                        e.getMessage();
                        displayResult(e.getMessage());
                    }
                }
            });
        }
        if(view == btn_del_seal){
            if(deviceInterface==null){
                Toast.makeText(this, "请先选择设备", Toast.LENGTH_SHORT).show();
                return;
            }
            index = 0 ;
            try {
                index = Integer.parseInt(edt_seal_index.getText().toString());
            }catch (Exception e){
                e.printStackTrace();
            }
            String password = edt_password.getText().toString();
            if(TextUtils.isEmpty(password)){
                Toast.makeText(this, "请输入pin码", Toast.LENGTH_SHORT).show();
                return ;
            }
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    try {
                        String pwd = edt_password.getText().toString();
                        if(deviceInterface.verifyPin(pwd)) {
                            deviceInterface.deleteSeal(index);
                            displayResult("删除成功");
                        }else{
                            displayResult("pin码错误");
                        }


                    }catch (Exception e){
                        e.getMessage();
                        displayResult(e.getMessage());
                    }
                }
            });
        }
        if(view == btn_read_seal){
            if(deviceInterface==null){
                Toast.makeText(this, "请先选择设备", Toast.LENGTH_SHORT).show();
                return;
            }
            index = 0 ;
            try {
                index = Integer.parseInt(edt_seal_index.getText().toString());
            }catch (Exception e){
                e.printStackTrace();
            }
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    try {
                        byte[] data = deviceInterface.readSeal(index);
                        if(bitmap!=null){
                            bitmap.recycle();
                        }
                        bitmap = BitmapFactory.decodeByteArray(data, 0, data.length);
                        displayBitmap();

                    }catch (Exception e){
                        e.getMessage();
                        displayResult(e.getMessage());
                    }
                }
            });
        }
        if(view == btn_sign_pdf){
            InputStream imageIs = getResources().openRawResource(R.raw.test);
            try {
                imageData = ByteUtils.readAll(imageIs);
            }catch (Exception e){
                e.getMessage();
            }
            if(imageData == null){
                Toast.makeText(this, "无法读取测试图片", Toast.LENGTH_SHORT).show();
                return;
            }
            if(signCert==null){
                Toast.makeText(this, "请选择签名证书", Toast.LENGTH_LONG).show();
                return ;
            }

            Intent it = new Intent();
            it.setClass(this, FileListActivity.class);
            it.putExtra(FileListActivity.FILE_FILTER, ".pdf");
            startActivityForResult(it, REQUEST_CODE_SIGN_PDF);

        }
        if(view == btn_verify_pdf){
            Intent it = new Intent();
            it.setClass(this, FileListActivity.class);
            it.putExtra(FileListActivity.FILE_FILTER, ".pdf");
            startActivityForResult(it, REQUEST_CODE_VERIFY_PDF);
        }
        if(view == btn_request_timestamp){
            final String ts_url = edt_timestamp_url.getText().toString();
            final String origin = edt_timestamp_origin.getText().toString();
            final String algo = spn_tiemstamp_hash_algo.getSelectedItem().toString();
            if(TextUtils.isEmpty(ts_url)||TextUtils.isEmpty(origin)){
                displayResult("时间戳服务器或原文为空");
                return;
            }
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    Certificate tsaCert = null;
                    try {
                        TimeStampInterface tsi = netcaCryptoInterface.getTimeStampInterface();
                        timestamp_token = tsi.requestTimeStampToken(ts_url, origin.getBytes("utf-8"), algo);
                        tsaCert = tsi.getTsaCert();
                        Date d = tsi.getTime();
                        String policy = tsi.getPolicy();
                        String sn = tsi.getSerialNumber();
                        displayResult("token:"+ net.netca.pki.encoding.Base64.encode(timestamp_token)+"\n时间戳:"+d.toString()+"\n策略:"+policy+"\nSN:"+sn+"\n证书:"+tsaCert.pemEncode());
                    }catch (Exception e){
                        displayResult(e.getMessage());
                        e.printStackTrace();
                    }finally {
                        if(tsaCert !=null){
                            tsaCert.free();
                        }
                    }
                }
            });
        }
        if(view == btn_verify_timestamp){
            final String origin = edt_timestamp_origin.getText().toString();
            if(TextUtils.isEmpty(origin)){
                displayResult("原文为空");
                return;
            }
            if(timestamp_token==null){
                displayResult("请先请求时间戳服务器token");
                return;
            }
            executorService.execute(new Runnable() {
                @Override
                public void run() {
                    Certificate tsaCert = null;
                    try {
                        TimeStampInterface tsi = netcaCryptoInterface.getTimeStampInterface();
                        tsi.verifyInit(origin.getBytes("utf-8"), timestamp_token);
                        tsaCert = tsi.getTsaCert();
                        Date d = tsi.getTime();
                        String policy = tsi.getPolicy();
                        String sn = tsi.getSerialNumber();
                        displayResult("时间戳:"+d.toString()+"\n策略:"+policy+"\nSN:"+sn+"\n证书:"+tsaCert.pemEncode());
                    }catch (Exception e){
                        displayResult(e.getMessage());
                        e.printStackTrace();
                    }finally {
                        if(tsaCert !=null){
                            tsaCert.free();
                        }
                    }
                }
            });
        }

    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if(resultCode==RESULT_OK){
            String filePath = "";
            switch (requestCode){
                case REQUEST_CODE_WRITE_SEAL:
                    filePath = data.getData().getPath();
                    writeSeal(filePath);
                    break;
                case REQUEST_CODE_SIGN_PDF:
                    filePath = data.getData().getPath();
                    signPDF(filePath);
                    break;
                case REQUEST_CODE_VERIFY_PDF:
                    filePath = data.getData().getPath();
                    verifyPDF(filePath);
                    break;
                case QEQUEST_QRCODE:
                    String url = data.getStringExtra(QrCodeFragment.QRCODE_RESULT);
                    signQrcode(url);
                    break;
            }
        }
    }

    private void signQrcode(final String url) {
        executorService.execute(new Runnable() {
            @Override
            public void run() {
                try {
                    netcaCryptoInterface.refresh();
                    String authCode = edt_authcode.getText().toString();
                    String password = edt_password.getText().toString();
                    QrcodeSignInterface qrcodeSignInterface = netcaCryptoInterface.getQrcodeSignInterface();
                    qrcodeSignInterface.init(url);
                    if (qrcodeSignInterface.isNeedAuthCode()) {
                        displayResult("签名内容:"+qrcodeSignInterface.requestSignContent(authCode));
                    } else {
                        displayResult("签名内容:"+qrcodeSignInterface.requestSignContent(null));
                    }
                    qrcodeSignInterface.signContent(signCert, password);
                    toastResult("二维码签名成功");
                }catch (Exception e){
                    e.printStackTrace();
                    displayResult(e.getMessage());
                }
            }
        });
    }

    private void verifyPDF(final String filePath) {
        executorService.execute(new Runnable() {
            @Override
            public void run() {
                try {
                    netcaCryptoInterface.refresh();
                    boolean result = netcaCryptoInterface.getPdfSignInterface().verifySignedPdfFile(filePath, NetcaPKIConst.SignedData.VERIFY_LEVEL_VERIFY_SIGNATURE_ONLY);
                    displayResult(result?"验证通过":"验证不通过");
                }catch (Exception e){
                    e.printStackTrace();
                    displayResult(e.getMessage());
                }
            }
        });
    }

    private void signPDF(final String filePath) {
        final String password = edt_password.getText().toString();
        executorService.execute(new Runnable() {
            @Override
            public void run() {
                try {
                    netcaCryptoInterface.refresh();
                    Certificate[] certificateList = signCert.buildCertPath();
                    String url = edt_option_url.getText().toString();
                    byte[] crlData = null;
//                    byte[] ocspData = netcaCryptoInterface.getCertInterface().verifyCertByOcsp(signCert, url);
                    String saveFile = filePath.substring(0, filePath.length()-4)+"_signed.pdf";
                    String tsaUrl = null;
                    netcaCryptoInterface.getPdfSignInterface().signPDFFile(filePath, imageData, saveFile,signCert, password, null, null,tsaUrl, 1, null, 100, 100, 100, 100);
                    displayResult("签名成功;文件路径:"+saveFile);
                }catch (Exception e){
                    e.printStackTrace();
                    displayResult(e.getMessage());
                }
            }
        });
    }


    private void writeSeal(String filePath) {
        final String password = edt_password.getText().toString();
        String f = new File(filePath).getName();
        final String fileName = f.substring(0, f.length()-4);
        imageData = null;
        try {
            imageData = ByteUtils.readAll(new FileInputStream(new File(filePath)));
        }catch (Exception e){
            e.printStackTrace();
        }
        if(imageData==null){
            displayResult("读取文件异常");
            return;
        }

        executorService.execute(new Runnable() {
            @Override
            public void run() {
                try {
                    netcaCryptoInterface.refresh();
                    if(deviceInterface.verifyPin(password)) {
                        deviceInterface.writeSeal(index, fileName, imageData);
                        displayResult("写入成功");
                    }else{
                        displayResult("pin码验证失败");
                    }


                }catch (Exception e){
                    e.getMessage();
                    displayResult(e.getMessage());
                }
            }
        });
    }

    private void displayBitmap() {
        handler.sendEmptyMessage(DISPLAY_IMAGE);

    }


    @Override
    public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
        if(compoundButton == tgb_test_decrypt&&b){
            if(encCert==null){
                Toast.makeText(this, "请选择加密证书", Toast.LENGTH_LONG).show();
                tgb_test_decrypt.setChecked(false);
                return;
            }
            if(envelopedData==null||envelopedData.length == 0){
                Toast.makeText(this, "请先进行加密", Toast.LENGTH_LONG).show();
                tgb_test_decrypt.setChecked(false);
                return;
            }
            final String password = edt_password.getText().toString();
            if(TextUtils.isEmpty(password)){
                Toast.makeText(this, "性能测试请输入密码", Toast.LENGTH_LONG).show();
                tgb_test_decrypt.setChecked(false);
                return;
            }
            if(testThread!=null&&testThread.isAlive()){
                Toast.makeText(this, "正在进行其他的测试!", Toast.LENGTH_LONG).show();
                tgb_test_decrypt.setChecked(false);
                return;
            }
            displayResult("开始解密测试");
            testThread = new Thread(){
                @Override
                public void run() {
                    try {
                        long count = 0;
                        long totalTs = 0;
                        while (tgb_test_decrypt.isChecked()) {
                            count++;
                            long startTs = System.currentTimeMillis();
                            EnvelopedDataDecryptInterface envelopedDataDecryptInterface = netcaCryptoInterface.getEnvelopedDataDecryptInterface();
                            envelopedDataDecryptInterface.decrypt(password, envelopedData, 0, envelopedData.length);
                            envelopedDataDecryptInterface.free();
                            long endTs = System.currentTimeMillis();
                            long spendTs = endTs-startTs;
                            totalTs+=spendTs;
                            Log.e("MainActivity",String.format("第%d次数字信封解密，共耗时%dms",count, spendTs));
                            if(count%10==0) {
                                displayResult(String.format("共%d次数字信封解密，平均耗时%fms", count, (double) totalTs / (double) count));
                            }
                        }
                        Log.e("MainActivity", String.format("共%d次数字信封解密，平均耗时%fms",count, (double)totalTs/(double)count));
                        displayResult(String.format("共%d次数字信封解密，平均耗时%fms",count, (double)totalTs/(double)count));


                    }catch (Exception e){
                        e.printStackTrace();
                        displayResult("测试异常结束"+e.getMessage());
                    }
                }
            };
            testThread.start();
        }
        if(compoundButton == tgb_test_sign&&b){
            if(signCert==null){
                Toast.makeText(this, "请选择签名证书", Toast.LENGTH_LONG).show();
                tgb_test_sign.setChecked(false);
                return;
            }
            if(TextUtils.isEmpty(edt_signature.getText().toString())){
                Toast.makeText(this, "请输入签名内容", Toast.LENGTH_LONG).show();
                tgb_test_sign.setChecked(false);
                return;
            }
            final String password = edt_password.getText().toString();
            if(TextUtils.isEmpty(password)){
                Toast.makeText(this, "性能测试请输入密码", Toast.LENGTH_LONG).show();
                tgb_test_sign.setChecked(false);
                return;
            }
            if(testThread!=null&&testThread.isAlive()){
                Toast.makeText(this, "正在进行其他的测试!", Toast.LENGTH_LONG).show();
                tgb_test_sign.setChecked(false);
                return;
            }
            displayResult("开始签名测试");
            testThread = new Thread(){
                @Override
                public void run() {
                    try {
                        long count = 0;
                        long totalTs = 0;
                        String data = edt_signature.getText().toString();
                        while (tgb_test_sign.isChecked()) {
                            count++;
                            long startTs = System.currentTimeMillis();
                            SignatureInterface signatureInterface = netcaCryptoInterface.getSignatureInterface();
                            if(netcaCryptoInterface.getCertInterface().isSm2(signCert)) {
                                signatureInterface.init(NetcaPKIConst.Signature.SM3WITHSM2, signCert, password);
                            }else{
                                signatureInterface.init(NetcaPKIConst.Signature.SHA256WITHRSA, signCert, password);
                            }

                            signatureInterface.signUpdate(data.getBytes("utf-8"), 0, data.getBytes("utf-8").length);
                            signatureInterface.sign();
                            signatureInterface.free();
                            long endTs = System.currentTimeMillis();
                            long spendTs = endTs-startTs;
                            totalTs+=spendTs;
                            Log.e("MainActivity",String.format("第%d次签名，共耗时%dms",count, spendTs));
                            if(count%10==0){
                                displayResult(String.format("共%d次签名，平均耗时%fms",count, (double)totalTs/(double)count));
                            }
                        }
                        displayResult(String.format("共%d次签名，平均耗时%fms",count, (double)totalTs/(double)count));
                        Log.e("MainActivity",String.format("共%d次签名，平均耗时%fms",count, (double)totalTs/(double)count));
                    }catch (Exception e){
                        e.printStackTrace();
                        displayResult("测试异常结束"+e.getMessage());
                    }
                }
            };
            testThread.start();
        }
    }
}
