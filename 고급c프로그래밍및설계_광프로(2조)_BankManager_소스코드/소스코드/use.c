//�̿볻�� ��ȸ �ҽ�
#include<stdio.h>
#include<stdlib.h>
#include"member.h"

extern char enterMem[20];		//���� �̸�

void USE() {
	char cont[1024];		//���Ͽ��� ���� ���ڿ��� �����ϴ� ����
	FILE* fpMem = NULL;

	//�α����� ȸ�� �̿� ���� ���� �б� "r"
	fopen_s(&fpMem, enterMem, "r");
	if (fpMem == NULL) {
		printf("���� ���� ����");
		exit(1);
	}

	while (fgets(cont, sizeof(cont), fpMem))
		fputs(cont,stdout);		//ȭ�鿡 ���

	fclose(fpMem);

	return;
}