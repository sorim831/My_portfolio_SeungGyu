//송금 소스
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member.h"

extern char enterMem[20];		//파일 이름

void SEND(MEMBER* pArr, int user) {
	char answer[10]; //송금할 계좌 뒷자리 8자리
	char send[10];   //송금할 금액
	char memID[20];  //받는 사람의 이름.txt 문자열을 저장하는 배열
	int sv;			//입력한 송금 금액을 정수로 변환하기 위한 변수
	int an;			//입력한 계좌번호를 정수로 변환하기 위한 변수
	FILE* fpMem = NULL;
	FILE* fpInMem = NULL;

	printf("송금할 계좌의 뒷자리 8자리를 입력하세요. : ");
	gets_s(answer, sizeof(answer));			//송금할 계좌번호의 뒷자리 8자리를 입력받음.
	an = inch(answer);

	int k = 0;		//계좌번호 확인을 위한 변수
	int i = 0;		//받는 사람 확인을 위한 변수

	if (pArr[user].number == an) {			// 송금할 계좌가 자신의 계좌일 경우
		printf("자기 자신한테는 송금할 수 없습니다.\n");
	}
	else {
		for (; i < arrMAXSIZE; i++) {
			if (pArr[i].number == an)      // 송금하려는 계좌가 회원중에 존재할 경우
			{
				//받는 사람의 이름을 파일명
				strcpy_s(memID, sizeof(memID), pArr[i].name);
				strcat_s(memID, sizeof(memID), ".txt");
				k = 1;
				break;
			}
			else
			{
				k = -1;
			}
		}
		if (k > 0) {
			while (1) {
				printf("송금할 금액을 입력하세요 (숫자만 입력하시오): ");
				gets_s(send, sizeof(send));		//송금하고자 하는 금액을 입력받음
				sv = inch(send);
				if (sv == 0)					//송금액이 조건에 부합하지 않은 경우
				{
					printf("올바른 수를 입력하세요.\n");
				}
				else
					break;
			}

			if (pArr[user].money - sv < 0)		//송금액이 잔액보다 많을 경우
			{
				printf("잔액이 부족합니다.\n");
			}
			else
			{
				pArr[i].money += sv;
				pArr[user].money -= sv;
				printf("송금이 완료되었습니다.\n");

				//받는 사람 내역 추가
				fopen_s(&fpInMem, memID, "a");
				if (fpInMem == NULL) {
					printf("파일 개방 실패");
					exit(1);
				}
				fprintf(fpInMem, "\t송금 -> +%d, 잔액 : %d\n", sv, pArr[i].money);
				fclose(fpInMem);

				//보낸 사람 내역 추가
				fopen_s(&fpMem, enterMem, "a");
				if (fpMem == NULL) {
					printf("파일 개방 실패");
					exit(1);
				}
				fprintf(fpMem, "\t송금 -> -%d, 잔액 : %d\n", sv, pArr[user].money);
				fclose(fpMem);
			}
		}
		else {
			printf("일치하는 계좌가 없습니다.\n");
		}
	}
	return;
}