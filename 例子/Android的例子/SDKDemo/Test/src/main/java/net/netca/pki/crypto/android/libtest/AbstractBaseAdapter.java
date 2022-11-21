package net.netca.pki.crypto.android.libtest;

import android.widget.BaseAdapter;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Donggui on 2017/2/16.
 */
public abstract class  AbstractBaseAdapter<T> extends BaseAdapter {
    List<T> data = new ArrayList<T>();
    @Override
    public int getCount() {
        if(data!=null){
            return data.size();
        }else {
            return 0;
        }
    }

    @Override
    public Object getItem(int i) {
        return data.get(i);
    }

    @Override
    public long getItemId(int i) {
        return i;
    }

    public void clear(){
        if(data!= null) {
            data.clear();
        }
    }

    public List<T> getAll(){
        return data;
    }

    public void add(T d) {
        if (d != null&&data!=null) {
            data.add(d);
        }
    }
    public void addAll(List<T> ds) {
        if (ds != null&&data!=null) {
            data.addAll(ds);
        }
    }

    public void remove(int index){
        if(data!=null&&data.size()>index&&index>0){
            data.remove(index);
        }
    }
}
