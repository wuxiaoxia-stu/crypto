package net.netca.pki.crypto.android.libtest;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.TextView;

import java.io.File;
import java.util.List;

public class FileListActivity extends AppCompatActivity implements AdapterView.OnItemClickListener {

    public static final String FILE_FILTER = "FILE_FILTER";
    private String filter = null;
    ListView lv_file_list ;
    FileListAdapter fileListAdapter;
    TextView tv_path;
    File currentFile;
    String sdCardPath;
    Activity activity;
    private TextView tv_title_center;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView( R.layout.activity_file_list);
        activity = this;
        getDataFromIntent();
        initView();
        initListener();
        initData();
    }

    private void getDataFromIntent() {
        Intent it = getIntent();
        filter = it.getStringExtra(FILE_FILTER);
    }

    private void initData() {
        fileListAdapter = new FileListAdapter();
        lv_file_list.setAdapter(fileListAdapter);
        currentFile = Environment.getExternalStorageDirectory();
        sdCardPath = currentFile.getAbsolutePath();
        reloadDirectory(currentFile);
        tv_title_center.setText("选择文件");
    }

    private void initListener() {
        lv_file_list.setOnItemClickListener(this);
    }

    private void initView() {
        lv_file_list = (ListView)findViewById(R.id.lv_file_list);
        tv_path = (TextView)findViewById(R.id.tv_path);
        tv_title_center = (TextView)findViewById(R.id.tv_title_center_text);
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        File f = (File)fileListAdapter.getItem(position);
        if(f.isDirectory()){
            reloadDirectory(f);
        }else{
            Intent it = new Intent();
            it.setData(Uri.fromFile(f));
            setResult(RESULT_OK, it);
            finish();
        }
    }

    public void reloadDirectory(File f){
        currentFile = f;
        tv_path.setText(currentFile.getAbsolutePath().toString());
        List<File> fileList = FileUtils.getDirectoryFileList(currentFile, filter);
        fileListAdapter.clear();
        fileListAdapter.addAll(fileList);
        fileListAdapter.notifyDataSetChanged();

    }

    @Override
    public void onBackPressed() {
        if(sdCardPath.equals(currentFile.getAbsolutePath().toString())){
            super.onBackPressed();
        }else{
            reloadDirectory(currentFile.getParentFile());
        }

    }


}