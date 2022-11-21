package net.netca.pki.crypto.android.libtest;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.annotation.TargetApi;
import android.os.AsyncTask;
import android.os.Build;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.text.TextUtils;
import android.util.Base64;
import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.inputmethod.EditorInfo;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import net.netca.pki.Certificate;
import net.netca.pki.PkiException;
import net.netca.pki.crypto.android.constant.NetcaPKIConst;
import net.netca.pki.crypto.android.interfaces.NetcaCryptoFactory;
import net.netca.pki.crypto.android.interfaces.NetcaCryptoInterface;
import net.netca.pki.crypto.android.interfaces.SignedDataSignInterface;


public class LoginActivity extends AppCompatActivity  {


    private UserLoginTask mAuthTask = null;


    private EditText mPasswordView;
    private View mProgressView;
    private View mLoginFormView;
    private NetcaCryptoInterface netcaCryptoInterface;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        netcaCryptoInterface = NetcaCryptoFactory.createNetcaCrypto(NetcaCryptoFactory.TYPE_JAR);
        try {
            netcaCryptoInterface.init(this);
        } catch (PkiException e) {
            e.printStackTrace();
        }
        mPasswordView = (EditText) findViewById(R.id.password);
        mPasswordView.setOnEditorActionListener(new TextView.OnEditorActionListener() {
            @Override
            public boolean onEditorAction(TextView textView, int id, KeyEvent keyEvent) {
                if (id == EditorInfo.IME_ACTION_DONE || id == EditorInfo.IME_NULL) {
                    attemptLogin();
                    return true;
                }
                return false;
            }
        });

        Button mEmailSignInButton = (Button) findViewById(R.id.email_sign_in_button);
        mEmailSignInButton.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {
                attemptLogin();
            }
        });

        mLoginFormView = findViewById(R.id.login_form);
        mProgressView = findViewById(R.id.login_progress);
    }

    private void attemptLogin() {
        if (mAuthTask != null) {
            return;
        }


        mPasswordView.setError(null);


        String password = mPasswordView.getText().toString();

        boolean cancel = false;
        View focusView = null;

        if (!TextUtils.isEmpty(password) && !isPasswordValid(password)) {
            mPasswordView.setError(getString(R.string.error_invalid_password));
            focusView = mPasswordView;
            cancel = true;
        }


        if (cancel) {

            focusView.requestFocus();
        } else {

            showProgress(true);
            mAuthTask = new UserLoginTask(password);
            mAuthTask.execute((Void) null);
        }
    }


    private boolean isPasswordValid(String password) {

        return true;
    }

    @Override
    protected void onResume() {
        super.onResume();
        //如不希望申请悬浮窗权限，需增加这段代码
        netcaCryptoInterface.updateActivity(this);
    }

    @Override
    protected void onPause() {
        super.onPause();
        //如不希望申请悬浮窗权限，需增加这段代码
        netcaCryptoInterface.updateActivity(null);
    }

    @TargetApi(Build.VERSION_CODES.HONEYCOMB_MR2)
    private void showProgress(final boolean show) {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB_MR2) {
            int shortAnimTime = getResources().getInteger(android.R.integer.config_shortAnimTime);

            mLoginFormView.setVisibility(show ? View.GONE : View.VISIBLE);
            mLoginFormView.animate().setDuration(shortAnimTime).alpha(
                    show ? 0 : 1).setListener(new AnimatorListenerAdapter() {
                @Override
                public void onAnimationEnd(Animator animation) {
                    mLoginFormView.setVisibility(show ? View.GONE : View.VISIBLE);
                }
            });

            mProgressView.setVisibility(show ? View.VISIBLE : View.GONE);
            mProgressView.animate().setDuration(shortAnimTime).alpha(
                    show ? 1 : 0).setListener(new AnimatorListenerAdapter() {
                @Override
                public void onAnimationEnd(Animator animation) {
                    mProgressView.setVisibility(show ? View.VISIBLE : View.GONE);
                }
            });
        } else {
            mProgressView.setVisibility(show ? View.VISIBLE : View.GONE);
            mLoginFormView.setVisibility(show ? View.GONE : View.VISIBLE);
        }
    }

    public class UserLoginTask extends AsyncTask<Void, Void, String> {

        private final String mPassword;

        UserLoginTask(String password) {

            mPassword = password;
        }

        @Override
        protected String doInBackground(Void... params) {
            try {

                    //随机数由服务器参数，用户对该随机数进行签名，后台验证签名，拿出签名证书，找到证书绑定的用户，使用该用户登录。
                    String data = "random data";

                    //进行P7带原文签名，需在*线程*中执行
                    Certificate signCert = netcaCryptoInterface.getCertInterface().getSingleSignCert();
                    if(signCert==null){
                        throw new Exception("没有证书，或用户取消");
                    }
                    SignedDataSignInterface signedDataSignInterface = netcaCryptoInterface.getSignedDataSignInterface();
                    if(netcaCryptoInterface.getCertInterface().isSm2(signCert)) {
                        signedDataSignInterface.setSignAlgorithm(0, NetcaPKIConst.Signature.SM3WITHSM2);
                    }else{
                        signedDataSignInterface.setSignAlgorithm(0, NetcaPKIConst.Signature.SHA256WITHRSA);
                    }
                    signedDataSignInterface.setSignCertificate(signCert);
                    signedDataSignInterface.setDetached(false);
                    signedDataSignInterface.setIncludeCertOption(NetcaPKIConst.SignedData.INCLUDE_CERT_OPTION_CERTPATHWITHROOT);
                    byte[] signedData = signedDataSignInterface.sign(mPassword, data.getBytes("utf-8"),0, data.getBytes("utf-8").length);
                    //该签名值需传给后台进行验证
                    String signedDataBase64 = Base64.encodeToString(signedData, Base64.NO_WRAP);
                    return null;
                }catch (Exception e){
                    e.printStackTrace();
                    return e.getMessage();
                }


        }

        @Override
        protected void onPostExecute(final String errorMsg) {
            mAuthTask = null;
            showProgress(false);

            if (errorMsg==null) {
                Toast.makeText(LoginActivity.this,"登录成功",Toast.LENGTH_SHORT).show();
                finish();
            } else {
                Toast.makeText(LoginActivity.this,errorMsg,Toast.LENGTH_SHORT).show();
                mPasswordView.requestFocus();
            }
        }

        @Override
        protected void onCancelled() {
            mAuthTask = null;
            showProgress(false);
        }
    }
}

