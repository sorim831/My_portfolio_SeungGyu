//�������� �ҽ�
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "member.h"

void CHANGE(MEMBER* pArr, int user) {
    char id1[12];   //������ ���̵�
    char id2[12];   //�ߺ� ���θ� �Ǵ��� ���̵�
    char pw1[12];   //������ ���� �� �Ǵ��� �ӽ� �н�����
    int n;         //������ ���� ���� ����
    int check = 0;   //���̵� ��ġ Ȯ���� ����

    system("cls");
    printf("1) ���̵� ���� \n");
    printf("2) ��й�ȣ ���� \n");
    printf("������ ������ �����ϼ���[   ]\b\b\b");
    scanf_s("%d", &n);  //����ڷκ��� ������ ������ �Է¹���
    while (getchar() != '\n');
    switch (n) {

    case 1:
        while (1)
        {
            printf("������ ���̵� �Է����ּ���: ");
            gets_s(id1, sizeof(id1));  //����ڷκ��� ������ ���̵� �Է¹���
            if (strlen(id1) == 0) { //������ �Ұ���
                printf("\t�ٽ� �Է��ϼ���\n");
            }
            else
                break;
        }
        int check1 = 0;// ��� ������ ���̵������� �Ѿ�� ���� ����

        for (int k = 0; k < arrMAXSIZE; k++) {
            if (strcmp(pArr[k].id, id1) == 0) { //����ڰ� �Է��� id�� ���α׷��� ��ϵǾ� �ִ� id �� �ϳ��� ��ġ�� �� 
                printf("�̹� �����ϴ� ���̵��Դϴ�. ������ �Ұ����մϴ�.\n");
                check1 = 1;
                break;
            }
        }

        if (check1 == 0) { //��� ������ ���̵�
            printf("��� ������ ���̵� �Դϴ�. ");
            while (check == 0) {
                printf("���̵� �ٽ� �Է����ּ���. : "); //���̵� �ߺ� ���� �Ǵ��� ���� �� ����� ���̵� �ٽ� �Է¹���
                gets_s(id2, sizeof(id2));


                if (strcmp(id1, id2) == 0) {  //���̵� �ߺ� ���θ� �Ǵ��� ���̵�� �ٽ� �Է��ϴ� ���̵� ��ġ�� ��� 
                    strcpy_s(pArr[user].id, 12, id2);
                    check = 1;   //check!=0�̹Ƿ� �ݺ��� ����
                    printf("������ �Ϸ�Ǿ����ϴ�. \n");
                    break;
                }
                else {
                    printf("�Է��� ���̵� ������ ���̵�� ��ġ���� �ʽ��ϴ�.\n");
                    break;
                }

            }

        }
        break;


    case 2:
        while (1) {
            printf("������ ��й�ȣ�� �Է����ּ���: ");
            gets_s(pw1, sizeof(pw1));   //����ڷκ��� ������ ��й�ȣ �Է¹���
            if (strlen(pw1) == 0) { //������ ��� �ٽ� �Է��ϵ��� �Ѵ�.
                printf("\t�ٽ� �Է��ϼ���\n");
            }
            else if (strcmp(pArr[user].pw, pw1) == 0) { //������ ����ϴ� ��й�ȣ�� ��� �ٽ� �Է��ϵ��� �Ѵ�.
                printf("\t������ ��й�ȣ�Դϴ�. �ٽ� �Է����ּ���.\n");
            }
            else
                break;
        }
        strcpy_s(pArr[user].pw, 12, pw1);
        printf("������ �Ϸ�Ǿ����ϴ�.\n");
        break;
    default: printf("1 �Ǵ� 2 �߿� �����ϼ���.\n"); //n�� 1�Ǵ� 2�� �ƴ� ���
        break;
    }

    return;
}