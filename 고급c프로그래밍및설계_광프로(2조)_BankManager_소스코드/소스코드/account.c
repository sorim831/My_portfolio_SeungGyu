//ȸ������ �ҽ�
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcmp
#include <time.h> //srand
#include "member.h"

int ACCOUNT(MEMBER* pArr, int count)
{
	char txtName[24];	//�ؽ�Ʈ ���� �̸�(�ش� ȸ���� �̸�)
	FILE* fpMem = NULL;

	for (int i = count; i < arrMAXSIZE; i++) {
		int check = 0; //�̸��� end�� �Է��� ��� ȸ�������� ���߱� ���� ��ġ
		while (1) {
			printf("\t�̸��� �Է��ϼ��� (����: end) : ");
			gets_s(pArr[i].name, sizeof(pArr[i].name)); //����� �̸��� �Է¹���
			if (!strcmp(pArr[i].name, "end")) {
				check = 1;
				break;
			}
			else if (strlen(pArr[i].name) == 0) { //������ ��� �ٽ� �Է¹���
				printf("\t��Ȯ�� �Է��ϼ���\n");
			}
			else
				break;
		}
		strcpy_s(txtName, sizeof(txtName), pArr[i].name);
		strcat_s(txtName, sizeof(txtName), ".txt"); //ȸ���� �̸�.txt ���ڿ��� txtName�� ����

		if (check == 1)  break; //�̸��� end�� ���

		printf("\t��������� �Է����ּ��� : "); scanf_s("%d", &pArr[i].birth);  //��������� �Է¹���
		while (getchar() != '\n');

		char id2[12]; //id �ߺ� �񱳿� �ӽ� �迭
		char id3[12]; //��밡���� ���̵�� �ٽ� �Է��� ���̵� ��ġ�ϳ� Ȯ��

		int check1 = 0;//�Ʒ� while�� ������ ���� ��ġ
		int check2 = 0;//���̵� �̹� ������ ��� if���� �ǳʶٱ� ���� ��ġ
		int check3 = 0;//�ٽ� �Է��� ���̵� ��� ������ ���̵�� ��ġ�ϳ� Ȯ���ϱ� ���� while�� ������ ���� ��ġ
		
		while (check1 == 0) {
			check2 = 0;
			while (1) {
				printf("\t���̵� �Է����ּ���. : ");
				gets_s(id2, sizeof(id2)); //����� ���̵� �Է¹���
				if (strlen(id2) == 0) {  //������ ��� �ٽ� �Է¹���
					printf("\t��Ȯ�� �Է��ϼ���\n");
				}
				else
					break;
			}

			for (int j = 0; j < count; j++) {

				if (strcmp(pArr[j].id, id2) == 0) { //������ ȸ������ ������ ���̵� �̹� ���� ���
					printf("\t�̹� �����ϴ� ���̵��Դϴ�.\n\n");
					check2 = 1; // ������ ���̵� ���� ��� �Ʒ� ���ǹ� ���� �Ұ���
					break;
				}
			}

			if (check2 == 0) { //������ ���̵� ���� ���
				printf("\t��� ������ ���̵� �Դϴ�.\n");

				while (check3 == 0) { //�ٽ� �Է��Ѱ� ��ġ�� �� ����
					printf("\t���̵� �ٽ� �Է����ּ���. : ");
					gets_s(id3, sizeof(id3));
					if (strcmp(id2, id3) == 0) {
						strcpy_s(pArr[i].id, 12, id3); //�Է��Ѱ� ���ٸ� pArr[i].id�� ������ ���̵� ����
						check3 = 1;
					}
					else {
						printf("\t���̵� ��ġ���� �ʽ��ϴ�.\n");
					}
				}

				check1 = 1;
			}

		}
		while (1) {
			printf("\t����� �н����带 �Է��ϼ��� : ");
			gets_s(pArr[i].pw, sizeof(pArr[i].pw)); //����� �н����带 �Է¹���
			if (strlen(pArr[i].pw) == 0) { //������ ��� �ٽ� �Է¹���
				printf("\t��Ȯ�� �Է��ϼ���\n");
			}
			else
				break;
		}


		int a, b, c, d, e, f, g, h;
		srand((unsigned int)time(NULL));
		a = rand() % 9 + 1;  //���¹�ȣ ������ 8�ڸ��� ù��° 1~9
		b = rand() % 10; //���¹�ȣ ������ 8�ڸ��� �ι�° 0~9
		c = rand() % 10; //���¹�ȣ ������ 8�ڸ��� ����° 0~9
		d = rand() % 10; //���¹�ȣ ������ 8�ڸ��� �׹�° 0~9
		e = rand() % 10; //���¹�ȣ ������ 8�ڸ��� �ټ���° 0~9
		f = rand() % 10; //���¹�ȣ ������ 8�ڸ��� ������° 0~9
		g = rand() % 10; //���¹�ȣ ������ 8�ڸ��� �ϰ���° 0~9
		h = rand() % 10; //���¹�ȣ ������ 8�ڸ��� ������° 0~9

		pArr[i].number = a * 10000000 + b * 1000000 + c * 100000 + d * 10000 + e * 1000 + f * 100 + g * 10 + h;
		printf("\tȸ������ ���¹�ȣ�� 0520-11-%d�Դϴ�. \n", pArr[i].number);
		printf("\n");


		pArr[i].money = 0; //���� ���� �� �ܾ��� 0������ �ʱ�ȭ
		
		//ȸ���� �̸����� �� ���� ���� ����(�̿� ����)
		fopen_s(&fpMem, txtName, "w");
		if (fpMem == NULL) {
			printf("���� ���� ����");
			exit(1);
		}
		fprintf(fpMem, "���� : %s ���� ��ȣ : 0520-11-%d\n\n", pArr[i].name, pArr[i].number);
		fprintf(fpMem, "\t*****�̿� ����*****\n");
		fclose(fpMem);

		count++;
	}

	return count;
}