//ȸ�� ���� �ҷ����� �ҽ�
#include<stdio.h>
#include<stdlib.h>
#include"member.h"

int MEM(MEMBER* pArr, int count) {
	FILE* fpAll = NULL;
	int temp = 0;

	//ȸ�� ������ ����� ����(member.txt) �б�
	fopen_s(&fpAll, "member.txt", "r");
	if (fpAll == NULL) {
		printf("���� ���� ����");
		exit(1);
	}

	//���α׷� ���� �� �����Ǿ��� count���� �� ȸ�������� ����ü�� ���������� �ҷ���.
	while (fscanf_s(fpAll, "%d %s %d %s %s %d %d\n", &temp, pArr->name, sizeof(pArr->name),
		&pArr->birth, pArr->id, sizeof(pArr->id), pArr->pw, sizeof(pArr->pw), &pArr->number, &pArr->money) == 7) {
		pArr++;		
	}

	fclose(fpAll);

	return temp;	//����� ȸ�� �� ��ŭ tmep���� ������
}
