package com.example.classtest;

import android.app.ListActivity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.example.classtest.MainActivity;
import com.example.classtest.R;

public class HelpActivity extends ListActivity {

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        String[] refers = {"https://www.youtube.com/watch?v=_UljKCtk0YI : 다이어트에 중요한 운동순서", "https://www.youtube.com/watch?v=28fI2--sRz0 : 코로나 증상과 예방",
                "https://www.youtube.com/watch?v=QQ7jxYp5z0o : 고혈압 관련 영상", "https://www.youtube.com/watch?v=shrRffAwFu0 : 심박수 관련 영상"};
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
                android.R.layout.simple_list_item_1, refers);
        setListAdapter(adapter);
    }

    protected void onListItemClick(ListView l, View v, int position, long id) {
        Intent intent=null;
        String list = (String) getListAdapter().getItem(position);
        Toast.makeText(this, list+" 링크로 연결됩니다.", Toast.LENGTH_LONG).show();
        if(list=="https://www.youtube.com/watch?v=_UljKCtk0YI : 다이어트에 중요한 운동순서"){
            intent = new Intent(Intent.ACTION_VIEW, Uri.parse("https://www.youtube.com/watch?v=_UljKCtk0YI"));
        }
        else if(list=="https://www.youtube.com/watch?v=28fI2--sRz0 : 코로나 증상과 예방"){
            intent = new Intent(Intent.ACTION_VIEW, Uri.parse("https://www.youtube.com/watch?v=28fI2--sRz0"));
        }
        else if(list=="https://www.youtube.com/watch?v=QQ7jxYp5z0o : 고혈압 관련 영상"){
            intent = new Intent(Intent.ACTION_VIEW, Uri.parse("https://www.youtube.com/watch?v=QQ7jxYp5z0o"));
        }
        else if(list=="https://www.youtube.com/watch?v=shrRffAwFu0 : 심박수 관련 영상"){
            intent = new Intent(Intent.ACTION_VIEW, Uri.parse("https://www.youtube.com/watch?v=shrRffAwFu0"));
        }
        startActivity(intent);
    }
}