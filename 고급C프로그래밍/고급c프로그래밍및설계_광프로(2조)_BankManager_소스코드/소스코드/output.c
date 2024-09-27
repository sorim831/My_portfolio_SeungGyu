//출금 소스
#include<stdio.h>
#include<stdlib.h>
#include"member.h"

extern char enterMem[20];		//파일 이름

void OUTPUT(MEMBER* pArr, int user)
{
	int sv;  //정수로 변환하기 위한 변수
	char input_money[10]; // 출금할 금액을 저장하는 변수
	FILE* fpMem = NULL;

	while (1) {
		printf("출금할 금액을 입력해주세요.(정수만 입력): ");
		gets_s(input_money, sizeof(input_money));  //출금할 금액을 입력받음

		sv = inch(input_money);   //입력한 금액을 정수형태로 변환
		if (sv == 0)	printf("다시 입력하시오.\n");  //출금액이 0원인 경우
		else 	break;
	}

	if (sv > (pArr[user].money)) {  //출금액이 잔고보다 많은 경우
		printf("잔액이 부족합니다.\n\n");
	}
	else {
		pArr[user].money -= sv;		//잔고에서 출금액만큼 뺀 값을 잔액으로 새로 저장
		printf("출금이 완료되었습니다. \n");
		printf("출금 후 잔액: %d\n", pArr[user].money);

		//출금하면 기존 이용 내역 다음부터 쓰기
		fopen_s(&fpMem, enterMem, "a");
		if (fpMem == NULL) {
			printf("파일 개방 실패");
			exit(1);
		}

		fprintf(fpMem, "\t출금 -> -%d, 잔액 : %d\n", sv, pArr[user].money); //회원 이름의 텍스트파일에 사용 내역을 기록
		fclose(fpMem);
	}

	return;
}