//이용내역 조회 소스
#include<stdio.h>
#include<stdlib.h>
#include"member.h"

extern char enterMem[20];		//파일 이름

void USE() {
	char cont[1024];		//파일에서 읽을 문자열을 저장하는 변수
	FILE* fpMem = NULL;

	//로그인한 회원 이용 내역 파일 읽기 "r"
	fopen_s(&fpMem, enterMem, "r");
	if (fpMem == NULL) {
		printf("파일 개방 실패");
		exit(1);
	}

	while (fgets(cont, sizeof(cont), fpMem))
		fputs(cont,stdout);		//화면에 출력

	fclose(fpMem);

	return;
}