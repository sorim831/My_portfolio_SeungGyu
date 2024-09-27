//백업 소스
#include <stdio.h>
#include <stdlib.h>
#include "member.h"


void BACKUP(MEMBER* pArr, int count) {
	FILE* fp = NULL;

	fopen_s(&fp, "member.txt", "w"); //회원의 모든 정보를 저장할 member라는 이름의 텍스트 파일열기

	if (fp == NULL) {

		printf("\t\t\t  !!에러!!\n");
		printf("\t\t  저장하는 동안 에러가 났습니다!");

		system("pause");
		system("cls");

		return;
	}



	for (int i = 0; i < count; i++) {
		fprintf(fp, "%d %s %d %s %s %d %d\n", i + 1, pArr[i].name, pArr[i].birth, pArr[i].id, pArr[i].pw, pArr[i].number, pArr[i].money); //회원의 모든 정보를 저장

	}
	fclose(fp);


	system("pause");
	system("cls");

	return;
}