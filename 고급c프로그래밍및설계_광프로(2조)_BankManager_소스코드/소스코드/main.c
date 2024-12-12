#include<stdio.h>
#include<stdlib.h>
#include"member.h"

int main(void) {

	int num1, num2, count = 0;
	int user = -1;
	MEMBER arr[arrMAXSIZE];

	count = MEM(arr, count);	//회원 정보 가져오기

	while (1) {
		system("cls");
		printf("====Bank Manager====\n\n");
		printf("1. 회원가입\n");
		printf("2. 로그인\n");
		printf("3. 도움말\n");
		printf("4. 프로그램 종료\n");
		printf("메뉴 선택 : [   ]\b\b\b");
		scanf_s("%d", &num1);
		while (getchar() != '\n');

		switch (num1) {
		case 1: count = ACCOUNT(arr, count);		break;
		case 2:
			user = LOGIN(arr);
			if (user != -1) {		//로그인 실패 시 해당 기능 수행 못하도록 user 반환 값이 초기 값인 -1일때는 실행불가
				while (1)
				{
					system("cls");
					printf("  %s님, 계좌번호 : 0520-11-%d\n\n", arr[user].name, arr[user].number);
					printf("1) 정보수정\n");
					printf("2) 예금하기\n");
					printf("3) 출금하기\n");
					printf("4) 송금하기\n");
					printf("5) 잔액조회\n");
					printf("6) 이용내역\n");
					printf("7) 처음으로\n");
					printf("메뉴 선택 : [   ]\b\b\b");
					scanf_s("%d", &num2);
					while (getchar() != '\n');

					if (num2 == 7) break;	//7누르면 처음 메뉴로

					switch (num2) {
					case 1: CHANGE(arr, user);		break;
					case 2: SAVE(arr, user);		break;
					case 3: OUTPUT(arr, user);		break;
					case 4: SEND(arr, user);		break;
					case 5: MONEY(arr, user);		break;
					case 6: USE();		break;
					default: printf("잘못된 선택!!!\n");
					}
					system("pause");
				}
			} break;

		case 3: HELP();	break;
		case 4: printf("프로그램 종료 \n");
			exit(0);		//프로그램 종료
		default: printf("잘못된 선택!!!\n");
		}
		BACKUP(arr, count); //회원정보 최신화로 저장
	}
	return 0;
}
