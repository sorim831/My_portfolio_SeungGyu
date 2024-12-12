//도움말 소스
#include<stdio.h>
#include<stdlib.h>
#include"member.h"

void HELP()
{
	int num1, num2 = 0;

	while (1) {
		system("cls");
		printf("====Bank Manager====\n\n");
		printf("1. 회원가입\n");
		printf("2. 로그인\n");
		printf("3. 처음으로\n");
		printf("메뉴 선택 : [   ]\b\b\b");
		scanf_s("%d", &num1);
		while (getchar() != '\n');

		switch (num1) {
		case 1: //회원가입 설명
			printf("\n이름에는 회원의 성명을 입력한다.\n(한글로는~9글자까지, 영문 및 숫자로는 19자까지 입력 가능하며, end를 입력할 시 회원가입이 종료된다.)\n\n");
			printf("생년월일에는 회원의 생년월일을 입력한다.\n\n");
			printf("아이디에는 사용할 아이디를 입력한다.\n(한글로는~5글자까지, 영문 및 숫자로는 11자까지 입력 가능하다. 단, 둘을 섞어서 쓰지 않도록한다 )\n\n");
			printf("패스워드에는 사용할 패스워드를 입력한다.\n(한글로는~5글자까지, 영문 및 숫자로는 11자까지 입력 가능하다. 단, 둘을 섞어서 쓰지 않도록한다)\n\n");
			break;
		case 2: //로그인 설명
			printf("\n로그인을 할 시 아래와 같은 메뉴를 사용할 수 있다.\n\n");
			printf("1) 정보수정\n");
			printf("2) 예금하기\n");
			printf("3) 출금하기\n");
			printf("4) 송금하기\n");
			printf("5) 잔액조회\n");
			printf("6) 이용내역\n");
			printf("메뉴 선택 : [   ]\b\b\b");
			scanf_s("%d", &num2);
			while (getchar() != '\n');

			switch (num2) {	//로그인 탭에서의 추가 기능 설명
			case 1: printf("\n해당 탭에서 1번을 선택할 경우 로그인한 회원의 아이디를, 2번을 선택할 경우 로그인한 회원의 비밀번호를 수정할 수 있다.\n\n");			break;  //정보수정 설명
			case 2: printf("\n로그인한 회원의 계좌에 원하는 금액을 예금할 수 있다.\n\n");		break;																		//예금하기 설명
			case 3: printf("\n로그인한 회원의 계좌에서 원하는 금액을 출금할 수 있다.\n\n");		break;																		//출금하기 설명
			case 4: printf("\n로그인한 회원의 계좌에서 다른 회원의 계좌로 원하는 만큼의 잔액을 송금할 수 있다.\n\n");		break;											//송금하기 설명
			case 5: printf("\n로그인한 회원의 잔액을 출력해준다.\n\n");			break;																						//잔액조회 설명
			case 6: printf("\n로그인한 회원의 이용내역을 출력해준다.\n\n");			break;																					//이용내역 설명
			default: printf("잘못된 선택!!!\n");
			}
			break;

		case 3: return;

		default:
			printf("잘못된 선택!!!\n");
		}
		system("pause");		//화면대기
	}
}