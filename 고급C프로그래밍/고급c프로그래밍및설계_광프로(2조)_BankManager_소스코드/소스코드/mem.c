//회원 정보 불러오는 소스
#include<stdio.h>
#include<stdlib.h>
#include"member.h"

int MEM(MEMBER* pArr, int count) {
	FILE* fpAll = NULL;
	int temp = 0;

	//회원 정보가 저장된 파일(member.txt) 읽기
	fopen_s(&fpAll, "member.txt", "r");
	if (fpAll == NULL) {
		printf("파일 개방 실패");
		exit(1);
	}

	//프로그램 종료 전 누적되었던 count값과 각 회원정보를 구조체에 순차적으로 불러옴.
	while (fscanf_s(fpAll, "%d %s %d %s %s %d %d\n", &temp, pArr->name, sizeof(pArr->name),
		&pArr->birth, pArr->id, sizeof(pArr->id), pArr->pw, sizeof(pArr->pw), &pArr->number, &pArr->money) == 7) {
		pArr++;		
	}

	fclose(fpAll);

	return temp;	//저장된 회원 수 만큼 tmep값이 결정됨
}
