package com.example.classtest;

import android.app.Service;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.IBinder;
import android.util.Log;

import androidx.annotation.Nullable;

public class MusicActivity extends Service{
    MediaPlayer mp;
    public IBinder onBind(Intent intent) {
        return null;
    }
    @Override
    public void onCreate() {
        super.onCreate();
    }
    @Override
    public void onDestroy() {
        mp.stop();
        super.onDestroy();
    }
    public int onStartCommand(Intent intent, int flags, int startId) {
        Log.i("서비스 테스트", "onStartCommand()");
        mp = MediaPlayer.create(this, R.raw.music);
        mp.setLooping(true);
        mp.start();
        return super.onStartCommand(intent, flags, startId);
    }

}
