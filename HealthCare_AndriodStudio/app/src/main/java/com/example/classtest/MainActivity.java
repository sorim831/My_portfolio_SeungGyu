package com.example.classtest;

import android.app.ActionBar;
import android.content.ComponentName;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.ServiceConnection;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.net.Uri;
import android.os.Bundle;
import android.os.IBinder;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.Toast;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import com.example.classtest.R;
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        setTitle("건강관리 프로그램");
        Button b1 = (Button) findViewById(R.id.button1);
        Button b2 = (Button) findViewById(R.id.button2);
        Intent musicIntent = new Intent(this, MusicActivity.class);
        startService(musicIntent); // 서비스 ( 배경음악 실행 )


        b1.setOnClickListener(new View.OnClickListener() { //시작버튼
            @Override
            public void onClick(View v) {
                stopService(musicIntent);
                Intent intent = new Intent(MainActivity.this, SecondActivity.class);
                startActivity(intent); // 입력화면으로
            }
        });
        b2.setOnClickListener(new View.OnClickListener() { //종료 버튼
            @Override
            public void onClick(View v) {
                AlertDialog.Builder dlg= new AlertDialog.Builder(MainActivity.this);
                dlg.setTitle("프로그램 종료");
                dlg.setMessage("프로그램을 종료합니다.");
                dlg.setPositiveButton("확인", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Toast.makeText(MainActivity.this,"이용해주셔서 감사합니다.",Toast.LENGTH_SHORT).show();
                        stopService(musicIntent);
                        finish();
                    }
                });
                dlg.show();
            }
        });
    }
    }
