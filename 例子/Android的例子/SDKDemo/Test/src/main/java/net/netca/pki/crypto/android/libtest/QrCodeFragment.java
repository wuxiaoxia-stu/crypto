package net.netca.pki.crypto.android.libtest;

import android.Manifest;
import android.app.Activity;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.PointF;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v4.content.ContextCompat;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.RelativeLayout;
import android.widget.Toast;

import com.dlazaro66.qrcodereaderview.QRCodeReaderView;


/**
 * Created by Donggui on 2017/6/20.
 */

public class QrCodeFragment extends Fragment implements QRCodeReaderView.OnQRCodeReadListener {
    public static final String QRCODE_RESULT = "qrcode_result";
    private static final int CAMERA_PERMISSION_REQUEST_CODE = 2;
    private static final int START_CAMERA = 1;
    private static final int NO_PERMISSION = 2;
    QRCodeReaderView zXingView;
    RelativeLayout rl_zxing;
    Handler handler = new Handler(){
        @Override
        public void handleMessage(Message msg) {
            super.handleMessage(msg);
            switch (msg.what) {
                case START_CAMERA:

                    startQrcodeScan();
                    break;
                case NO_PERMISSION:
                    Toast.makeText(getContext(), "获取相机权限失败", Toast.LENGTH_SHORT).show();
                    break;
            }
        }
    };
    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.fragment_qrcode, container, false);
        initView(v);
        initListener();
        return v;
    }

    private void initListener() {

    }

    private void initView(View v) {
        rl_zxing = (RelativeLayout)v.findViewById(R.id.rl_zxing);

    }

    private void initQrcode(){
        if(zXingView==null) {
            zXingView = new QRCodeReaderView(getContext());
            rl_zxing.addView(zXingView);
            zXingView.setQRDecodingEnabled(true);
            zXingView.setAutofocusInterval(2000L);
            zXingView.setOnQRCodeReadListener(this);
        }

    }

    @Override
    public void onResume() {
        super.onResume();
        if(hasCameraPermission()) {
            startQrcodeScan();
        }else{
            requestCameraPermission();
        }
    }

    @Override
    public void onQRCodeRead(String result, PointF[] points) {
        Intent it = new Intent();
        it.putExtra(QRCODE_RESULT, result);
        getActivity().setResult(Activity.RESULT_OK, it);
        getActivity().finish();
    }


    public boolean hasCameraPermission(){
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            if(ContextCompat.checkSelfPermission(getContext(), Manifest.permission.CAMERA)!= PackageManager.PERMISSION_GRANTED){
                return false;
            }
        }
        return true;
    }

    public void requestCameraPermission(){
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            getActivity().requestPermissions(new String[]{Manifest.permission.CAMERA}, CAMERA_PERMISSION_REQUEST_CODE);
        }
    }

    private void startQrcodeScan() {
        initQrcode();
        if(zXingView!=null){
            zXingView.startCamera();
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        if(requestCode==CAMERA_PERMISSION_REQUEST_CODE&&permissions[0].equals(Manifest.permission.CAMERA)&&grantResults[0]==PackageManager.PERMISSION_GRANTED){
            handler.sendEmptyMessage(START_CAMERA);
            
        }else{
            handler.sendEmptyMessage(NO_PERMISSION);
        }
    }

    @Override
    public void onPause() {
        super.onPause();
        stopQrcodeScan();
    }

    private void stopQrcodeScan() {
        if(zXingView!=null){
            zXingView.stopCamera();
        }
    }


}
