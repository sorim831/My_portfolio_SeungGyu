//회원가입 소스
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcmp
#include <time.h> //srand
#include "member.h"

int ACCOUNT(MEMBER* pArr, int count)
{
	char txtName[24];	//텍스트 파일 이름(해당 회원의 이름)
	FILE* fpMem = NULL;

	for (int i = count; i < arrMAXSIZE; i++) {
		int check = 0; //이름에 end를 입력할 경우 회원가입을 멈추기 위한 장치
		while (1) {
			printf("\t이름을 입력하세요 (종료: end) : ");
			gets_s(pArr[i].name, sizeof(pArr[i].name)); //사용할 이름을 입력받음
			if (!strcmp(pArr[i].name, "end")) {
				check = 1;
				break;
			}
			else if (strlen(pArr[i].name) == 0) { //공백일 경우 다시 입력받음
				printf("\t정확히 입력하세요\n");
			}
			else
				break;
		}
		strcpy_s(txtName, sizeof(txtName), pArr[i].name);
		strcat_s(txtName, sizeof(txtName), ".txt"); //회원의 이름.txt 문자열을 txtName에 저장

		if (check == 1)  break; //이름이 end인 경우

		printf("\t생년월일을 입력해주세요 : "); scanf_s("%d", &pArr[i].birth);  //생년월일을 입력받음
		while (getchar() != '\n');

		char id2[12]; //id 중복 비교용 임시 배열
		char id3[12]; //사용가능한 아이디와 다시 입력한 아이디가 일치하나 확인

		int check1 = 0;//아래 while을 돌리기 위한 장치
		int check2 = 0;//아이디가 이미 존재할 경우 if문을 건너뛰기 위한 장치
		int check3 = 0;//다시 입력한 아이디가 사용 가능한 아이디와 일치하나 확인하기 위한 while문 돌리기 위한 장치
		
		while (check1 == 0) {
			check2 = 0;
			while (1) {
				printf("\t아이디를 입력해주세요. : ");
				gets_s(id2, sizeof(id2)); //사용할 아이디를 입력받음
				if (strlen(id2) == 0) {  //공백일 경우 다시 입력받음
					printf("\t정확히 입력하세요\n");
				}
				else
					break;
			}

			for (int j = 0; j < count; j++) {

				if (strcmp(pArr[j].id, id2) == 0) { //생성된 회원들중 동일한 아이디가 이미 있을 경우
					printf("\t이미 존재하는 아이디입니다.\n\n");
					check2 = 1; // 동일한 아이디가 있을 경우 아래 조건문 실행 불가능
					break;
				}
			}

			if (check2 == 0) { //동일한 아이디가 없을 경우
				printf("\t사용 가능한 아이디 입니다.\n");

				while (check3 == 0) { //다시 입력한게 일치할 때 까지
					printf("\t아이디를 다시 입력해주세요. : ");
					gets_s(id3, sizeof(id3));
					if (strcmp(id2, id3) == 0) {
						strcpy_s(pArr[i].id, 12, id3); //입력한게 같다면 pArr[i].id에 복사한 아이디를 저장
						check3 = 1;
					}
					else {
						printf("\t아이디가 일치하지 않습니다.\n");
					}
				}

				check1 = 1;
			}

		}
		while (1) {
			printf("\t사용할 패스워드를 입력하세요 : ");
			gets_s(pArr[i].pw, sizeof(pArr[i].pw)); //사용할 패스워드를 입력받음
			if (strlen(pArr[i].pw) == 0) { //공백인 경우 다시 입력받음
				printf("\t정확히 입력하세요\n");
			}
			else
				break;
		}


		int a, b, c, d, e, f, g, h;
		srand((unsigned int)time(NULL));
		a = rand() % 9 + 1;  //계좌번호 마지막 8자리중 첫번째 1~9
		b = rand() % 10; //계좌번호 마지막 8자리중 두번째 0~9
		c = rand() % 10; //계좌번호 마지막 8자리중 세번째 0~9
		d = rand() % 10; //계좌번호 마지막 8자리중 네번째 0~9
		e = rand() % 10; //계좌번호 마지막 8자리중 다섯번째 0~9
		f = rand() % 10; //계좌번호 마지막 8자리중 여섯번째 0~9
		g = rand() % 10; //계좌번호 마지막 8자리중 일곱번째 0~9
		h = rand() % 10; //계좌번호 마지막 8자리중 여덟번째 0~9

		pArr[i].number = a * 10000000 + b * 1000000 + c * 100000 + d * 10000 + e * 1000 + f * 100 + g * 10 + h;
		printf("\t회원님의 계좌번호는 0520-11-%d입니다. \n", pArr[i].number);
		printf("\n");


		pArr[i].money = 0; //계좌 개설 시 잔액은 0원으로 초기화
		
		//회원의 이름으로 된 개별 파일 생성(이용 내역)
		fopen_s(&fpMem, txtName, "w");
		if (fpMem == NULL) {
			printf("파일 개방 실패");
			exit(1);
		}
		fprintf(fpMem, "성명 : %s 계좌 번호 : 0520-11-%d\n\n", pArr[i].name, pArr[i].number);
		fprintf(fpMem, "\t*****이용 내역*****\n");
		fclose(fpMem);

		count++;
	}

	return count;
}