package net.netca.pki.crypto.android.libtest;

import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.net.Uri;
import android.provider.MediaStore;
import android.support.v4.app.Fragment;

import java.io.File;

public class UrlUtil {
	public static void jumpToUrl(Context c, String url){
		Intent it = new Intent();
		it.setAction(Intent.ACTION_VIEW);
		it.setData(Uri.parse(url));
		c.startActivity(it);
	}
	public static void shareFile(Context c, String filePath) {
		Intent shareIntent = new Intent();
		Uri uri = Uri.fromFile(new File(filePath));
		shareIntent.setAction(Intent.ACTION_SEND);
		shareIntent.setType("*/*");
		shareIntent.putExtra(Intent.EXTRA_STREAM, uri);
		c.startActivity(Intent.createChooser(shareIntent, "分享"));
	}

	public static void openImageChooserActivity(Fragment fragment, int requetCode){
		Intent i = new Intent(Intent.ACTION_GET_CONTENT);
		i.addCategory(Intent.CATEGORY_OPENABLE);
		i.setType("image/*");
		fragment.startActivityForResult(Intent.createChooser(i, "选择图片"), requetCode);
	}

	public static String getImageNameFromUri(Context c, Uri uri){

		String[] proj = { MediaStore.Images.Media.DATA };
		Cursor actualimagecursor = c.getContentResolver().query(uri,proj,null,null,null);

		int actual_image_column_index = actualimagecursor.getColumnIndexOrThrow(MediaStore.Images.Media.DATA);

		actualimagecursor.moveToFirst();

		String img_path = actualimagecursor.getString(actual_image_column_index);

		File file = new File(img_path);
		return file.getName();
	}
}
