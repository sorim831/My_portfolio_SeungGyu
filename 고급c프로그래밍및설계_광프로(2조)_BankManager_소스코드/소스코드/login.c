//�α��� �ҽ�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"member.h"

char enterMem[20];		//�α����� ȸ���� �̸��� �����ϱ� ���� ��������

int LOGIN(MEMBER* pArr) {

	char input_id[12];	// �Է��� id
	char input_pw[12];	// �Է��� pw
	int check = 1;	// while���� ������ ���� ��ġ
	int check2 = 1; // �������� �ʴ� ���̵� ������ ����ϱ� ���� ��ġ
	int LoginCount = 0;	// 3�� Ʋ���� ó������ �ٽ��ϴµ� ���
	int usernumber = 0;	//��ȯ�ϴ� ��

	while (check == 1) {
		LoginCount++; //�α��� �õ� Ƚ�� ����

		if (LoginCount >= 4) {
			printf("\n3�� �̻� Ʋ�Ƚ��ϴ�.\n");
			printf("ó������ ���ư��ϴ�.\n");
			usernumber = -1;

			break;
		}
		else {
			printf("���̵� �Է��ϼ���.: ");
			gets_s(input_id, sizeof(input_id));  //���̵� �Է¹���
			printf("��й�ȣ�� �Է��ϼ���.: ");
			gets_s(input_pw, sizeof(input_pw));  //�н����带 �Է¹���

			for (int i = 0; i < arrMAXSIZE; i++) {
				if (strcmp(pArr[i].id, input_id) == 0) {  //�Է��� ���̵�� ��� ȸ���� ���̵��� ���� ���� �ִٸ�
					if (strcmp(pArr[i].pw, input_pw) == 0) {  //���� �����ϰ� ���ȸ���� �н������� ���� ���� �ִٸ�
						printf("%s���� �α��� �ϼ̽��ϴ�.\n\n", pArr[i].name);
						check = 0;							// �� �̻� �α����� �õ����� ����
						check2 = 1;							// �������� �ʴ� ���̵��Դϴ�.�� ��µ��� �ʵ��� ��
						usernumber = i;                     // �Լ��� ������ ��ȯ ���� i�� ��ȯ�ϵ��� ��.

						strcpy_s(enterMem, sizeof(enterMem), pArr[i].name);
						strcat_s(enterMem, sizeof(enterMem), ".txt");   //ȸ���� �̸�.txt���ڿ��� �������� enterMem�� ����

						system("pause");
						break;
					}
					else {
						printf("��й�ȣ�� Ʋ�Ƚ��ϴ�.\n\n");
						check2 = 1;							// �������� �ʴ� ���̵��Դϴ�.�� ��µ��� �ʵ��� ��
						break;
					}

				}
				else 
					check2 = 0;                             // �����ϴ� ���̵� �����Ƿ� �Ʒ� ���ǹ� �ν��� ���� check2�� 0���� ����
			}
			if (check2 == 0)
				printf("�������� �ʴ� ���̵��Դϴ�.\n\n");
		}
	}

	return usernumber;
}