//���� �ҽ�
#include<stdio.h>
#include<stdlib.h>
#include"member.h"

extern char enterMem[20];	//���� �̸�

void SAVE(MEMBER* pArr, int user) {
	int sv;				//������ ��ȯ�ϱ� ���� ����
	char str[10];		//������ �ݾ��� �����ϴ� ����
	FILE* fpMem = NULL;

	while (1) {
		printf("�����ϱ⸦ ���ϴ� �ݾ��� �Է��Ͻÿ�.\n");
		printf("\t�ݾ�(���ڸ� �Է��Ͻÿ�) : ");
		gets_s(str, sizeof(str));  //������ �ݾ��� �Է¹���

		sv = inch(str);	//�Է��� �ݾ��� ���� ���·� ��ȯ (���ǿ� �������� ������ 0)

		if (sv == 0)	//���ݾ��� 0���̰ų� ���ǿ� �������� ���� ���
			printf("\t�ٽ� �Է��Ͻÿ�.\n");
		else
			break;	//����� �Է������� �ݺ��� Ż��
	}

	pArr[user].money += sv;		//�ܰ��� ���ݾ׸�ŭ ���� ���� �ܾ����� ���� ����
	printf("\n���� �� �ܾ� : %d, ���� �� �ܾ� : %d\n", pArr[user].money - sv, pArr[user].money);
	
	//�����ϸ� ���� �̿� ���� �������� ����
	fopen_s(&fpMem, enterMem, "a");
	if (fpMem == NULL) {
		printf("���� ���� ����");
		exit(1);
	}

	//ȸ�� �̸��� �ؽ�Ʈ���Ͽ� ��� ������ ���
	fprintf(fpMem, "\t���� -> +%d, �ܾ� : %d\n", sv, pArr[user].money);
	fclose(fpMem);

	return;
}