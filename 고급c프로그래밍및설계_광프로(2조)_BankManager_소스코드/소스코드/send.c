//�۱� �ҽ�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member.h"

extern char enterMem[20];		//���� �̸�

void SEND(MEMBER* pArr, int user) {
	char answer[10]; //�۱��� ���� ���ڸ� 8�ڸ�
	char send[10];   //�۱��� �ݾ�
	char memID[20];  //�޴� ����� �̸�.txt ���ڿ��� �����ϴ� �迭
	int sv;			//�Է��� �۱� �ݾ��� ������ ��ȯ�ϱ� ���� ����
	int an;			//�Է��� ���¹�ȣ�� ������ ��ȯ�ϱ� ���� ����
	FILE* fpMem = NULL;
	FILE* fpInMem = NULL;

	printf("�۱��� ������ ���ڸ� 8�ڸ��� �Է��ϼ���. : ");
	gets_s(answer, sizeof(answer));			//�۱��� ���¹�ȣ�� ���ڸ� 8�ڸ��� �Է¹���.
	an = inch(answer);

	int k = 0;		//���¹�ȣ Ȯ���� ���� ����
	int i = 0;		//�޴� ��� Ȯ���� ���� ����

	if (pArr[user].number == an) {			// �۱��� ���°� �ڽ��� ������ ���
		printf("�ڱ� �ڽ����״� �۱��� �� �����ϴ�.\n");
	}
	else {
		for (; i < arrMAXSIZE; i++) {
			if (pArr[i].number == an)      // �۱��Ϸ��� ���°� ȸ���߿� ������ ���
			{
				//�޴� ����� �̸��� ���ϸ�
				strcpy_s(memID, sizeof(memID), pArr[i].name);
				strcat_s(memID, sizeof(memID), ".txt");
				k = 1;
				break;
			}
			else
			{
				k = -1;
			}
		}
		if (k > 0) {
			while (1) {
				printf("�۱��� �ݾ��� �Է��ϼ��� (���ڸ� �Է��Ͻÿ�): ");
				gets_s(send, sizeof(send));		//�۱��ϰ��� �ϴ� �ݾ��� �Է¹���
				sv = inch(send);
				if (sv == 0)					//�۱ݾ��� ���ǿ� �������� ���� ���
				{
					printf("�ùٸ� ���� �Է��ϼ���.\n");
				}
				else
					break;
			}

			if (pArr[user].money - sv < 0)		//�۱ݾ��� �ܾ׺��� ���� ���
			{
				printf("�ܾ��� �����մϴ�.\n");
			}
			else
			{
				pArr[i].money += sv;
				pArr[user].money -= sv;
				printf("�۱��� �Ϸ�Ǿ����ϴ�.\n");

				//�޴� ��� ���� �߰�
				fopen_s(&fpInMem, memID, "a");
				if (fpInMem == NULL) {
					printf("���� ���� ����");
					exit(1);
				}
				fprintf(fpInMem, "\t�۱� -> +%d, �ܾ� : %d\n", sv, pArr[i].money);
				fclose(fpInMem);

				//���� ��� ���� �߰�
				fopen_s(&fpMem, enterMem, "a");
				if (fpMem == NULL) {
					printf("���� ���� ����");
					exit(1);
				}
				fprintf(fpMem, "\t�۱� -> -%d, �ܾ� : %d\n", sv, pArr[user].money);
				fclose(fpMem);
			}
		}
		else {
			printf("��ġ�ϴ� ���°� �����ϴ�.\n");
		}
	}
	return;
}