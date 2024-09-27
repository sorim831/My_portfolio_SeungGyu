//로그인 소스
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member.h"

char enterMem[20];		//로그인한 회원의 이름을 공유하기 위한 전역변수

int LOGIN(MEMBER* pArr) {

	char input_id[12];	// 입력할 id
	char input_pw[12];	// 입력할 pw
	int check = 1;	// while문을 돌리기 위한 장치
	int check2 = 1; // 존재하지 않는 아이디 문구를 출력하기 위한 장치
	int LoginCount = 0;	// 3번 틀리면 처음부터 다시하는데 사용
	int usernumber = 0;	//반환하는 값

	while (check == 1) {
		LoginCount++; //로그인 시도 횟수 증가

		if (LoginCount >= 4) {
			printf("\n3번 이상 틀렸습니다.\n");
			printf("처음으로 돌아갑니다.\n");
			usernumber = -1;

			break;
		}
		else {
			printf("아이디를 입력하세요.: ");
			gets_s(input_id, sizeof(input_id));  //아이디를 입력받음
			printf("비밀번호를 입력하세요.: ");
			gets_s(input_pw, sizeof(input_pw));  //패스워드를 입력받음

			for (int i = 0; i < arrMAXSIZE; i++) {
				if (strcmp(pArr[i].id, input_id) == 0) {  //입력한 아이디와 모든 회원의 아이디중 같은 것이 있다면
					if (strcmp(pArr[i].pw, input_pw) == 0) {  //위를 만족하고 모든회원의 패스워드중 같은 것이 있다면
						printf("%s님이 로그인 하셨습니다.\n\n", pArr[i].name);
						check = 0;							// 더 이상 로그인을 시도하지 않음
						check2 = 1;							// 존재하지 않는 아이디입니다.가 출력되지 않도록 함
						usernumber = i;                     // 함수가 끝나고 반환 값을 i로 반환하도록 함.

						strcpy_s(enterMem, sizeof(enterMem), pArr[i].name);
						strcat_s(enterMem, sizeof(enterMem), ".txt");   //회원의 이름.txt문자열을 전역변수 enterMem에 저장

						system("pause");
						break;
					}
					else {
						printf("비밀번호가 틀렸습니다.\n\n");
						check2 = 1;							// 존재하지 않는 아이디입니다.가 출력되지 않도록 함
						break;
					}

				}
				else 
					check2 = 0;                             // 존재하는 아이디가 없으므로 아래 조건문 인식을 위해 check2를 0으로 수정
			}
			if (check2 == 0)
				printf("존재하지 않는 아이디입니다.\n\n");
		}
	}

	return usernumber;
}