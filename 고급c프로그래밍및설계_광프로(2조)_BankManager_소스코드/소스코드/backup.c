//��� �ҽ�
#include <stdio.h>
#include <stdlib.h>
#include "member.h"


void BACKUP(MEMBER* pArr, int count) {
	FILE* fp = NULL;

	fopen_s(&fp, "member.txt", "w"); //ȸ���� ��� ������ ������ member��� �̸��� �ؽ�Ʈ ���Ͽ���

	if (fp == NULL) {

		printf("\t\t\t  !!����!!\n");
		printf("\t\t  �����ϴ� ���� ������ �����ϴ�!");

		system("pause");
		system("cls");

		return;
	}



	for (int i = 0; i < count; i++) {
		fprintf(fp, "%d %s %d %s %s %d %d\n", i + 1, pArr[i].name, pArr[i].birth, pArr[i].id, pArr[i].pw, pArr[i].number, pArr[i].money); //ȸ���� ��� ������ ����

	}
	fclose(fp);


	system("pause");
	system("cls");

	return;
}