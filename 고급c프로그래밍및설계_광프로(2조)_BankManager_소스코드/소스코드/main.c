#include<stdio.h>
#include<stdlib.h>
#include"member.h"

int main(void) {

	int num1, num2, count = 0;
	int user = -1;
	MEMBER arr[arrMAXSIZE];

	count = MEM(arr, count);	//ȸ�� ���� ��������

	while (1) {
		system("cls");
		printf("====Bank Manager====\n\n");
		printf("1. ȸ������\n");
		printf("2. �α���\n");
		printf("3. ����\n");
		printf("4. ���α׷� ����\n");
		printf("�޴� ���� : [   ]\b\b\b");
		scanf_s("%d", &num1);
		while (getchar() != '\n');

		switch (num1) {
		case 1: count = ACCOUNT(arr, count);		break;
		case 2:
			user = LOGIN(arr);
			if (user != -1) {		//�α��� ���� �� �ش� ��� ���� ���ϵ��� user ��ȯ ���� �ʱ� ���� -1�϶��� ����Ұ�
				while (1)
				{
					system("cls");
					printf("  %s��, ���¹�ȣ : 0520-11-%d\n\n", arr[user].name, arr[user].number);
					printf("1) ��������\n");
					printf("2) �����ϱ�\n");
					printf("3) ����ϱ�\n");
					printf("4) �۱��ϱ�\n");
					printf("5) �ܾ���ȸ\n");
					printf("6) �̿볻��\n");
					printf("7) ó������\n");
					printf("�޴� ���� : [   ]\b\b\b");
					scanf_s("%d", &num2);
					while (getchar() != '\n');

					if (num2 == 7) break;	//7������ ó�� �޴���

					switch (num2) {
					case 1: CHANGE(arr, user);		break;
					case 2: SAVE(arr, user);		break;
					case 3: OUTPUT(arr, user);		break;
					case 4: SEND(arr, user);		break;
					case 5: MONEY(arr, user);		break;
					case 6: USE();		break;
					default: printf("�߸��� ����!!!\n");
					}
					system("pause");
				}
			} break;

		case 3: HELP();	break;
		case 4: printf("���α׷� ���� \n");
			exit(0);		//���α׷� ����
		default: printf("�߸��� ����!!!\n");
		}
		BACKUP(arr, count); //ȸ������ �ֽ�ȭ�� ����
	}
	return 0;
}
