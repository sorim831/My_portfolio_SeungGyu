package com.example.classtest;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;


public class SecondActivity extends AppCompatActivity {
    String userName;
    float userHeight,userWeight,userTem,userBp,userBp2,userHr;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.second);
        setTitle("정보 입력");
        EditText ename = (EditText) findViewById(R.id.name);
        EditText eheight = (EditText) findViewById(R.id.height);
        EditText eweight = (EditText) findViewById(R.id.weight);
        EditText etem = (EditText) findViewById(R.id.tem);
        EditText ebp = (EditText) findViewById(R.id.bp);
        EditText ebp2 = (EditText) findViewById(R.id.bp2);
        EditText ehr = (EditText) findViewById(R.id.hr);
        Button sbtn = (Button) findViewById(R.id.sbtn);


        sbtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                userName = ename.getText().toString();
                userHeight=Float.parseFloat(eheight.getText().toString());
                userWeight  = Float.parseFloat(eweight.getText().toString());
                userBp= Float.parseFloat(ebp.getText().toString());
                userBp2=Float.parseFloat(ebp2.getText().toString());
                userTem=Float.parseFloat(etem.getText().toString());
                userHr = Float.parseFloat(ehr.getText().toString());
                if (ename.length() == 0 || eheight.length() == 0 || eweight.length() == 0 || etem.length() == 0
                        || ebp.length() == 0 || ebp2.length() == 0 || ehr.length() == 0) { //입력하지 않은 경우
                    AlertDialog.Builder dl = new AlertDialog.Builder(SecondActivity.this);
                    dl.setTitle("오류!");
                    dl.setMessage("항목을 모두 입력해주세요.");
                    dl.setPositiveButton("확인.", new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dialog, int which) {
                        }
                    });
                    dl.show();
                } else {
                    if (userHeight<0||userHeight>999||userWeight<0||userWeight>999||userTem<0||userTem>100||
                            userBp<0||userBp>999||userBp2<0||userBp2>999||userHr<0||userHr>999){ // 비정상적인 수치를 입력한 경우
                        AlertDialog.Builder dl2 = new AlertDialog.Builder(SecondActivity.this);
                        dl2.setTitle("오류!");
                        dl2.setMessage("비정상적인 입력이 감지되었습니다.");
                        dl2.setPositiveButton("확인.", new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int which) {
                            }
                        });
                        dl2.show();
                    }
                    else {
                        Intent intent = new Intent(SecondActivity.this, ThirdActivity.class);
                        // ThirdActivity로 데이터 전달
                        intent.putExtra("UserName", userName);
                        intent.putExtra("UserHeight", userHeight);
                        intent.putExtra("UserWeight", userWeight);
                        intent.putExtra("UserTem", userTem);
                        intent.putExtra("UserBp", userBp);
                        intent.putExtra("UserBp2",userBp2);
                        intent.putExtra("UserHr", userHr);
                        startActivity(intent); // 결과화면으로
                    }
                    }
            }
        });
    }
}
