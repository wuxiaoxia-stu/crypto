package net.netca.pki.crypto.android.libtest;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.PorterDuff;
import android.graphics.PorterDuffXfermode;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.support.annotation.Nullable;
import android.util.AttributeSet;
import android.view.View;


import java.util.Timer;
import java.util.TimerTask;

/**
 * Created by Donggui on 2017/6/30.
 */

public class QrCodeCoverView extends View {
    private static final int REFRESH = 1;
    String backgroundColor = "#77585858";
    String rectBorderColor = "#ff3385ff";
    String lineColor = "#ffffffff";
    float curentLineTop = 0;
    float line_top = 0;
    float line_bottom = 0;
    Timer timer;
    Handler handler  = new Handler(Looper.getMainLooper()){
        @Override
        public void handleMessage(Message msg) {
            switch (msg.what){
                case REFRESH:
                    invalidate();
                    break;
            }
        }
    };
    public QrCodeCoverView(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
    }
    public QrCodeCoverView(Context context) {
        super(context);
    }


    @Override
    protected void onDetachedFromWindow() {
        super.onDetachedFromWindow();
        stopTimer();
    }

    private void stopTimer() {
        if(timer!=null) {
            timer.cancel();
            timer = null;
        }
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        int width = canvas.getWidth();
        int height = canvas.getHeight();
        float rect_width = width/2.0f;
        float rect_height = rect_width;
        float rect_top = (height-rect_height)/2.0f;
        float rect_left = (width-rect_width)/2.0f;
        float rect_bottom = rect_top + rect_height;
        float rect_right = rect_left + rect_width;
        line_top = rect_top;
        line_bottom = rect_bottom;
        initTimer();
        Paint p = new Paint();
        p.setStrokeCap(Paint.Cap.ROUND);
        p.setColor(Color.parseColor(backgroundColor));
        canvas.drawRect(0, 0, width, height, p);
        //清除中间的矩形
        p.setXfermode(new PorterDuffXfermode(PorterDuff.Mode.CLEAR));
        canvas.drawRect(rect_left, rect_top, rect_right, rect_bottom, p);
        p.setXfermode(new PorterDuffXfermode(PorterDuff.Mode.SRC));
        //画线
        p.setStrokeWidth(1);
        p.setColor(Color.parseColor(lineColor));
        canvas.drawLine(rect_left, curentLineTop, rect_right, curentLineTop, p);
        //画矩形
        float[] lines = new float[]{
                rect_left, rect_top,
                rect_left, rect_bottom,
                rect_left, rect_bottom,
                rect_right, rect_bottom,
                rect_right, rect_bottom,
                rect_right, rect_top,
                rect_right, rect_top,
                rect_left, rect_top
        };
        p.setStrokeWidth(dip2px(getContext(), 4));
        p.setColor(Color.parseColor(rectBorderColor));
        canvas.drawLines(lines, p);


    }

    /**
     * 根据手机的分辨率从 dp 的单位 转成为 px(像素)
     */
    public static int dip2px(Context context, float dpValue) {
        final float scale = context.getResources().getDisplayMetrics().density;
        return (int) (dpValue * scale + 0.5f);
    }

    /**
     * 根据手机的分辨率从 px(像素) 的单位 转成为 dp
     */
    public static int px2dip(Context context, float pxValue) {
        final float scale = context.getResources().getDisplayMetrics().density;
        return (int) (pxValue / scale + 0.5f);
    }

    private void initTimer() {
        if(timer == null){
            timer = new Timer();
            timer.schedule(new TimerTask() {
                @Override
                public void run() {
                    curentLineTop += (line_bottom-line_top)/100.0f;
                    if(curentLineTop>line_bottom){
                        curentLineTop = line_top;
                    }
                    if(curentLineTop<line_top){
                        curentLineTop = line_top;
                    }
                    handler.sendEmptyMessage(REFRESH);
                }
            }, 50, 50);
        }
    }

}
