//��� �ҽ�
#include<stdio.h>
#include<stdlib.h>
#include"member.h"

extern char enterMem[20];		//���� �̸�

void OUTPUT(MEMBER* pArr, int user)
{
	int sv;  //������ ��ȯ�ϱ� ���� ����
	char input_money[10]; // ����� �ݾ��� �����ϴ� ����
	FILE* fpMem = NULL;

	while (1) {
		printf("����� �ݾ��� �Է����ּ���.(������ �Է�): ");
		gets_s(input_money, sizeof(input_money));  //����� �ݾ��� �Է¹���

		sv = inch(input_money);   //�Է��� �ݾ��� �������·� ��ȯ
		if (sv == 0)	printf("�ٽ� �Է��Ͻÿ�.\n");  //��ݾ��� 0���� ���
		else 	break;
	}

	if (sv > (pArr[user].money)) {  //��ݾ��� �ܰ��� ���� ���
		printf("�ܾ��� �����մϴ�.\n\n");
	}
	else {
		pArr[user].money -= sv;		//�ܰ��� ��ݾ׸�ŭ �� ���� �ܾ����� ���� ����
		printf("����� �Ϸ�Ǿ����ϴ�. \n");
		printf("��� �� �ܾ�: %d\n", pArr[user].money);

		//����ϸ� ���� �̿� ���� �������� ����
		fopen_s(&fpMem, enterMem, "a");
		if (fpMem == NULL) {
			printf("���� ���� ����");
			exit(1);
		}

		fprintf(fpMem, "\t��� -> -%d, �ܾ� : %d\n", sv, pArr[user].money); //ȸ�� �̸��� �ؽ�Ʈ���Ͽ� ��� ������ ���
		fclose(fpMem);
	}

	return;
}