package net.netca.pki.crypto.android.libtest;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import java.io.File;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 * Created by zhangmike on 1/2/17.
 */
public class FileListAdapter  extends AbstractBaseAdapter<File> {


    public FileListAdapter(){


    }



    public void add(File f){
        super.add(f);
        Collections.sort(data, new Comparator<File>() {
            @Override
            public int compare(File lhs, File rhs) {
                return lhs.getName().compareToIgnoreCase(rhs.getName());

            }
        });
    }
    public void addAll(List<File> files){
        super.addAll(files);
        Collections.sort(data, new Comparator<File>(){
            @Override
            public int compare(File lhs, File rhs) {
                return lhs.getName().compareToIgnoreCase(rhs.getName());

            }
        });
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        View itemView = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_file_list, parent, false);
        ImageView iv_icon = (ImageView)itemView.findViewById(R.id.iv_icon);
        TextView tv_name = (TextView)itemView.findViewById(R.id.tv_name);
        File f = data.get(position);

        if(f.isDirectory()){
            iv_icon.setBackgroundResource(R.drawable.icon_folder);
        }else{
            iv_icon.setBackgroundResource(R.drawable.icon_file);
        }
        tv_name.setText(f.getName());
        return itemView;
    }


}