package com.example.classtest;

import android.app.ListActivity;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ListView;
import android.widget.Toast;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

public class fy extends ListActivity {

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        String[] refers = {"www.youtube.com", "ee", "aa", "dd", "gita", "ememd"};
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
                android.R.layout.simple_list_item_1, refers);
        setListAdapter(adapter);
    }

    protected void onListItemClick(ListView l, View v, int position, long id) {
        Intent intent=null;
        String list = (String) getListAdapter().getItem(position);
        Toast.makeText(this, "링크로 연결됩니다.", Toast.LENGTH_SHORT).show();
        if(list=="www.youtube.com"){
            intent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://www.youtube.com"));
        }
        startActivity(intent);
    }
}