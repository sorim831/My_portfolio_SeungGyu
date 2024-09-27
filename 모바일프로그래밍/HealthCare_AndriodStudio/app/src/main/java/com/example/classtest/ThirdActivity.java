package com.example.classtest;

import android.app.Activity;
import android.app.ListActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class ThirdActivity extends AppCompatActivity {

    float userHeight, userWeight, bmi,userTem,userBp,userBp2,userHr;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.third);
        setTitle("결과");

        Button nextbutton = (Button) findViewById(R.id.nextbutton);
        TextView result = (TextView) findViewById(R.id.result); //이름
        TextView result1 = (TextView) findViewById(R.id.result1); // BMI
        TextView result2 = (TextView) findViewById(R.id.result2); // 체온
        TextView result3 = (TextView) findViewById(R.id.result3); // 혈압
        TextView result4 = (TextView) findViewById(R.id.result4); // 심박수

        // SecondActivity로부터 데이터 전달받음
        Intent getintent = getIntent();
        result.setText(getintent.getStringExtra("UserName") + "님의 건강 상태입니다.");
        userHeight = getintent.getExtras().getFloat("UserHeight");
        userWeight = getintent.getExtras().getFloat("UserWeight");
        bmi = (float) (userWeight/(userHeight*0.01*userHeight*0.01)); //bmi 수치 계산식
        userTem = getintent.getExtras().getFloat("UserTem");
        userBp = getintent.getExtras().getFloat("UserBp");
        userBp2 = getintent.getExtras().getFloat("UserBp2");
        userHr = getintent.getExtras().getFloat("UserHr");
        //기준에 따른 수치 계산한 결과
        if (bmi > 23 && bmi<= 25) {
            result1.setText("회원님은 과체중입니다. BMI의 증가는 심혈관계 질환(주로 심장 질환과 뇌졸증), 당뇨병, 근골격계 질환(특히 골관절염)" +
                    " 및 일부 암(자궁 내막암, 유방암, 난소암, 전립선암, 간암, 담낭암, 신장암, 대장암)의 매우 중요한 위험인자입니다. 이 말고도 " +
                    "BMI의 증가는 다양한 질병을 야기합니다. 그러므로 개선이 필요합니다. 메뉴에서 해결책을 보세요.");
        }
        else if (bmi > 25 && bmi <= 30){
            result1.setText("BMI : 회원님은 비만입니다. BMI의 증가는 심혈관계 질환(주로 심장 질환과 뇌졸증), 당뇨병, 근골격계 질환(특히 골관절염)" +
                    " 및 일부 암(자궁 내막암, 유방암, 난소암, 전립선암, 간암, 담낭암, 신장암, 대장암)의 매우 중요한 위험인자입니다. 이 말고도 " +
                    "BMI의 증가는 다양한 질병을 야기합니다. 그러므로 개선이 필요합니다. 메뉴에서 해결책을 보세요.");
        }
        else if (bmi > 30){
            result1.setText("BMI : 회원님은 고도비만입니다. BMI의 증가는 심혈관계 질환(주로 심장 질환과 뇌졸증), 당뇨병, 근골격계 질환(특히 골관절염)" +
                    " 및 일부 암(자궁 내막암, 유방암, 난소암, 전립선암, 간암, 담낭암, 신장암, 대장암)의 매우 중요한 위험인자입니다. 이 말고도 " +
                    "BMI의 증가는 다양한 질병을 야기합니다. 그러므로 개선이 필요합니다. 메뉴에서 해결책을 보세요.");
        }
        else if (bmi < 18.5) {
            result1.setText("BMI : 회원님은 저체중입니다. 한국인은 비만보다 저체중으로 사망할 위험도가 훨씬 높다는 연구 결과가 있습니다." +
                    " 저체중인 사람들은 우울증, 마른당뇨, 골다공증, 영양실조 등에 걸리기 쉽습니다. 이 말고도 저체중은 다양한 질병을 야기합니다." +
                    " 그러므로 개선이 필요합니다. 메뉴에서 해결책을 보세요.");
        }
        else {
            result1.setText("BMI : 회원님의 BMI 수치는 정상입니다.");
        }
        if (userTem < 36) {
            result2.setText("체온 : 저체온입니다. 체온이 35℃  밑으로 내려가면 저체온증이 발생할 수 있습니다. " +
                    "저체온증은 혈액 순환과 호흡, 신경계의 기능이 느려지게 합니다. 지속될 경우 사망에 이를 수 있으므로 빠른 조치가 필요합니다." +
                    " 메뉴에서 해결책을 보세요.");
        } else if (userTem > 37.5) {
            result2.setText("체온 : 현재 발열 증상이 있습니다. 이 말고도 기침, 피로감, 미각 또는 후각 상실 등의 " +
                    "증상이 있다면 근처 보건소에서 코로나19 검사를 받으시기 바랍니다. ");
        } else {
            result2.setText("체온 : 정상 체온입니다.");
        }
        if (userBp < 90) {
            result3.setText("혈압 : 저혈압입니다. 저혈압은 무기력, 불면 등의 증상을 발생시키며, " +
                    "심한 경우 실신을 일으키기도 하고 시력장애 등의 증상이 나타날 수 있습니다. 그러므로 조치가 필요합니다. 메뉴에서 해결책을 보세요. ");
        } else if (userBp >= 120 && userBp < 140 || userBp2 >= 80 && userBp2 < 90) {
            result3.setText("혈압 : 고혈압 전단계입니다. 고혈압은 각종 장기에 치명적인 손상을 일으킵니다. " +
                    "고혈압은 별 증상을 일으키진 않지만, 고혈압은 조기에 사망할 확률이 높은 질병입니다. 그렇기 때문에 빠른 조치가 필요합니다. " +
                    "메뉴에서 해결책을 보세요.");
        } else if (userBp >= 140 && userBp < 159 || userBp2 >= 90 && userBp2 < 99) {
            result3.setText("혈압 : 1단계 고혈압입니다. 고혈압은 각종 장기에 치명적인 손상을 일으킵니다. " +
                    "고혈압은 별 증상을 일으키진 않지만, 고혈압은 조기에 사망할 확률이 높은 질병입니다. 그렇기 때문에 빠른 조치가 필요합니다. " +
                    "메뉴에서 해결책을 보세요.");
        } else if (userBp >= 160 || userBp2 >= 100) {
            result3.setText("혈압 : 2단계 고혈압입니다. 고혈압은 각종 장기에 치명적인 손상을 일으킵니다. " +
                    "고혈압은 별 증상을 일으키진 않지만, 고혈압은 조기에 사망할 확률이 높은 질병입니다. 그렇기 때문에 빠른 조치가 필요합니다. " +
                    "메뉴에서 해결책을 보세요.");
        } else {
            result3.setText("혈압 : 혈압 수치가 정상입니다.");
        }
        if (userHr <= 60) {
            result4.setText("심박수 : 심박수가 정상수치보다 느립니다. 심박수가 너무 느리면 혈액순환이 잘 안되고 피로, 무력감, 현기증이 나거나 실신 등의 증상이 생길 수 있습니다. " +
                    "증상이 나아지지 않으면 심장마비, 협심증, 고혈압 등의 합병증이 발생할 수 있습니다. 그렇기 때문에 조치가 필요합니다. 메뉴에서 해결책을 보세요. " +
                    "<백신을 맞은 후 심박수가 불규칙해졌을 경우 병원에 가보세요!>");
        } else if (userHr > 100) {
            result4.setText("심박수 : 심박수가 정상수치보다 빠릅니다. 심박수가 너무 빠르면 전신 무력감이나 가슴 통증이 생길 수도 있으며, 숨이 차는 현상이 일어날 수 있습니다. " +
                    "이는 심장마비로 이어질 가능성이 큽니다. 그렇기 때문에 조치가 필요합니다. 메뉴에서 해결책을 보세요. " +
                    "<백신을 맞은 후 심박수가 불규칙해졌을 경우 병원에 가보세요!>");
        } else {
            result4.setText("심박수 : 정상 수치입니다. ");
        }

        //확인 버튼
        nextbutton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ThirdActivity.this, HelpActivity.class);
                startActivity(intent);
            }
        });

    }

    //옵션
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.solmenu, menu);
        return true;
    }
    public boolean onOptionsItemSelected(MenuItem item) {
        Intent getintent = getIntent();
        Button nextbutton = (Button) findViewById(R.id.nextbutton);
        TextView result = (TextView) findViewById(R.id.result); //이름
        TextView result1 = (TextView) findViewById(R.id.result1); // BMI
        TextView result2 = (TextView) findViewById(R.id.result2); // 체온
        TextView result3 = (TextView) findViewById(R.id.result3); // 혈압
        TextView result4 = (TextView) findViewById(R.id.result4); // 심박수
        result.setText(getintent.getStringExtra("UserName") + "님의 건강 상태입니다.");

        userHeight = getintent.getExtras().getFloat("UserHeight");
        userWeight = getintent.getExtras().getFloat("UserWeight");
        bmi = (float) (userWeight/(userHeight*0.01*userHeight*0.01));
        userTem = getintent.getExtras().getFloat("UserTem");
        userBp = getintent.getExtras().getFloat("UserBp");
        userBp2 = getintent.getExtras().getFloat("UserBp2");
        userHr = getintent.getExtras().getFloat("UserHr");
        switch (item.getItemId()) {
            case R.id.sol1: //BMI 해결 옵션 선택한 경우
                if (bmi > 23) {
                    result1.setText("BMI : 생활 습관을 개선하는 것이 비만 해결에 가장 중요합니다. " +
                            "운동을 위해 특별히 시간을 내기 어려운 경우에는 일상생활을 하는 동안 활동량을 최대한 늘려야 합니다. " +
                            "단백질은 섭취가 허용되는 범위에서 최대의 양을 섭취해야 합니다. " +
                            "그러나 심장 ·혈관질환과 신장질환의 조건에서는 고단백 식사는 금해야 합니다.. 그 밖에 무기질과 비타민도 적당량 공급되어야 합니다. " +
                            "체중감소를 위해서 수분 조절도 매우 중요합니다. 체중감소를 시작한 첫주는 물의 손실로 인하여 현저하게 체중이 감소되며, 그뒤 신체는 초기에 체액 손실이 컸던 것을 다시 복원시킨다. " +
                            "수분의 섭취는 다른 합병증이 생기지 않는 한 식이에서 제한되지 않는다. 이런 경우 염분은 조직으로부터 체액이 유출되도록 염분이 제한되고 갈증을 느끼지 않도록 해야 합니다.");
                }
                if (bmi < 18.5) {
                    result1.setText("BMI : 생활 습관을 개선하는 것이 저체중 해결에 가장 중요합니다. " +
                            "열량보다 많은 열량을 섭취해 주어야 합니다. 이때 섭취열량은 조금씩 늘려야 합니다. 식사를 할 때에는 채소보다 육류를 먼저 섭취하고," +
                            " 고기, 생선 등을 먹어 근육의 형성을 돕는 단백질을 보충해야 합니다. 이때, 영양소의 흡수를 방해하는 담배나 술, 커피는 줄이고, " +
                            "운동을 병행해야 합니다.");
                } else if (bmi<23 && bmi>18.5) {
                    result1.setText("BMI : 회원님의 BMI 수치는 정상입니다.");
                }
                return true;
            case R.id.sol2: // 체온 해결 옵션 선택한 경우
                if (userTem < 36) {
                    result2.setText("체온 : 저체온증 증상이 있을 때에는 체온 손실을 막고 체온을 올리는 것이 중요합니다. " +
                            "주변을 따뜻한 환경으로 만들어야 합니다. 따뜻한 음료나 당분을 섭취하세요. 응급처치와 동시에" +
                            "119를 이용하여 병원으로 이송되어야 합니다.");
                } else if (userTem > 37.5) {
                    result2.setText("체온 : 현재 발열 증상이 있습니다. 이 말고도 기침, 피로감, 미각 또는 후각 상실 등의 " +
                            "증상이 있다면 근처 보건소에서 코로나19 검사를 받으시기 바랍니다. ");
                } else {
                    result2.setText("체온 : 정상 체온입니다.");
                }
                return true;
            case R.id.sol3: // 혈압 해결 옵션 선택한 경우
                if (userBp < 90) {
                    result3.setText("혈압 : 저혈압은 원인을 찾아서 치료하는 것이 중요합니다. 혈압 조절제와 같은 약물요법과  더불어 " +
                            "일상생활에서 적당한 운동, 충분한 수면, 규칙적인 식사, 원활한 통변 등의 자기 관리에 신경 쓰는 것도 필요합니다. " +
                            "평소 식사 시에 위장 장애가 초래되지 않는 범위에서 염분과 수분(하루 2~2.5L)을 충분히 섭취해야 하며, 식사는 규칙적으로 해야 합니다. " +
                            "취침 시 머리를 15~20도 이상 올린 상태로 자야하며, 아침에 갑작스럽게 일어나면 안됩니다.");
                } else if (userBp >= 120 || userBp2 >= 80 ) {
                    result3.setText("혈압 : 고혈압을 치료하려면 저염식을 하고, 그게 안되면 약물을 사용해야 합니다. " +
                            "식단에는 국물이 적어야 하고, 소금이나 인공 조미료 대신 천연 향신료를 사용해야 합니다. 천연 조미료로는 새우가루, 표고버섯 가루 등이 있습니다. " +
                            "또한 인스턴스 식품을 줄이고, 칼륨이 들어간 바나나, 아보가토, 흰콩, 시금치 등을 섭취해야 합니다. ");
                } else {
                    result3.setText("혈압 : 혈압 수치가 정상입니다.");
                }
                return true;
            case R.id.sol4: //심박수 해결 옵션 선택한 경우
                if (userHr <= 60) {
                    result4.setText("심박수 : 앞서 말한 증상이 나타날 경우 병원에 방문하여 심전도 검사를 받아 부정맥인지 아닌지 진단을 해야 합니다. " +
                            "이때, 부정맥을 진단받았을 경우 병원에서 치료를 받아야 합니다. 치료 외에도, 심박수를 감소시키는 약물을 복용하고 있었으면 약물 투약을 중단해야 합니다. " +
                            "또한, 커피나 알코올과 같은 부정맥 발생과 관련 있는 음식의 섭취를 피해야 합니다.");
                } else if (userHr > 100) {
                    result4.setText("심박수 : 앞서 말한 증상이 나타날 경우 병원에 방문하여 심전도 검사를 받아 부정맥인지 아닌지 진단을 해야 합니다. " +
                            "이때, 부정맥을 진단받았을 경우 병원에서 치료를 받아야 합니다. 치료 외에도, 심박수를 감소시키는 약물을 복용하고 있었으면 약물 투약을 중단해야 합니다. " +
                            "또한, 커피나 알코올과 같은 부정맥 발생과 관련 있는 음식의 섭취를 피해야 합니다.");
                } else {
                    result4.setText("심박수 : 정상 수치입니다. ");
                }
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

}

