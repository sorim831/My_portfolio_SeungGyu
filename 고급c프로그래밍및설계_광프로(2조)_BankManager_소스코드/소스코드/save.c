//예금 소스
#include<stdio.h>
#include<stdlib.h>
#include"member.h"

extern char enterMem[20];	//파일 이름

void SAVE(MEMBER* pArr, int user) {
	int sv;				//정수로 변환하기 위한 변수
	char str[10];		//예금할 금액을 저장하는 변수
	FILE* fpMem = NULL;

	while (1) {
		printf("예금하기를 원하는 금액을 입력하시오.\n");
		printf("\t금액(숫자만 입력하시오) : ");
		gets_s(str, sizeof(str));  //예금할 금액을 입력받음

		sv = inch(str);	//입력한 금액을 정수 형태로 변환 (조건에 부합하지 않으면 0)

		if (sv == 0)	//예금액이 0원이거나 조건에 부합하지 않은 경우
			printf("\t다시 입력하시오.\n");
		else
			break;	//제대로 입력했으면 반복문 탈출
	}

	pArr[user].money += sv;		//잔고에서 예금액만큼 더한 값을 잔액으로 새로 저장
	printf("\n예금 전 잔액 : %d, 예금 후 잔액 : %d\n", pArr[user].money - sv, pArr[user].money);
	
	//예금하면 기존 이용 내역 다음부터 쓰기
	fopen_s(&fpMem, enterMem, "a");
	if (fpMem == NULL) {
		printf("파일 개방 실패");
		exit(1);
	}

	//회원 이름의 텍스트파일에 사용 내역을 기록
	fprintf(fpMem, "\t예금 -> +%d, 잔액 : %d\n", sv, pArr[user].money);
	fclose(fpMem);

	return;
}