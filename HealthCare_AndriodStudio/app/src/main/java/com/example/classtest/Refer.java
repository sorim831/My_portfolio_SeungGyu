package com.example.classtest;

import android.app.ListActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.example.classtest.MainActivity;
import com.example.classtest.R;



public class Refer extends ListActivity{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.help);
        setTitle("도움말");
        Button backbt = (Button) findViewById(R.id.backbt);

        backbt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent backIntent = new Intent(Refer.this, MainActivity.class);
                startActivity(backIntent);
            }
        });

    }
}


