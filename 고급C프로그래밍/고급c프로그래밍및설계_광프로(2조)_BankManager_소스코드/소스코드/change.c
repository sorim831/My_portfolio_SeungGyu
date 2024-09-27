//정보수정 소스
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "member.h"

void CHANGE(MEMBER* pArr, int user) {
    char id1[12];   //변경할 아이디
    char id2[12];   //중복 여부를 판단할 아이디
    char pw1[12];   //기존과 같은 지 판단할 임시 패스워드
    int n;         //변경할 정보 선택 변수
    int check = 0;   //아이디 일치 확인할 변수

    system("cls");
    printf("1) 아이디 변경 \n");
    printf("2) 비밀번호 변경 \n");
    printf("변경할 정보를 선택하세요[   ]\b\b\b");
    scanf_s("%d", &n);  //사용자로부터 변경할 정보를 입력받음
    while (getchar() != '\n');
    switch (n) {

    case 1:
        while (1)
        {
            printf("변경할 아이디를 입력해주세요: ");
            gets_s(id1, sizeof(id1));  //사용자로부터 변경할 아이디 입력받음
            if (strlen(id1) == 0) { //공백은 불가능
                printf("\t다시 입력하세요\n");
            }
            else
                break;
        }
        int check1 = 0;// 사용 가능한 아이디탭으로 넘어가기 위한 변수

        for (int k = 0; k < arrMAXSIZE; k++) {
            if (strcmp(pArr[k].id, id1) == 0) { //사용자가 입력한 id가 프로그램에 등록되어 있는 id 중 하나와 일치할 때 
                printf("이미 존재하는 아이디입니다. 변경이 불가능합니다.\n");
                check1 = 1;
                break;
            }
        }

        if (check1 == 0) { //사용 가능한 아이디
            printf("사용 가능한 아이디 입니다. ");
            while (check == 0) {
                printf("아이디를 다시 입력해주세요. : "); //아이디 중복 여부 판단이 끝난 후 등록할 아이디를 다시 입력받음
                gets_s(id2, sizeof(id2));


                if (strcmp(id1, id2) == 0) {  //아이디 중복 여부를 판단한 아이디와 다시 입력하는 아이디가 일치할 경우 
                    strcpy_s(pArr[user].id, 12, id2);
                    check = 1;   //check!=0이므로 반복문 종료
                    printf("변경이 완료되었습니다. \n");
                    break;
                }
                else {
                    printf("입력한 아이디가 변경한 아이디와 일치하지 않습니다.\n");
                    break;
                }

            }

        }
        break;


    case 2:
        while (1) {
            printf("변경할 비밀번호를 입력해주세요: ");
            gets_s(pw1, sizeof(pw1));   //사용자로부터 변경할 비밀번호 입력받음
            if (strlen(pw1) == 0) { //공백인 경우 다시 입력하도록 한다.
                printf("\t다시 입력하세요\n");
            }
            else if (strcmp(pArr[user].pw, pw1) == 0) { //기존에 사용하던 비밀번호인 경우 다시 입력하도록 한다.
                printf("\t동일한 비밀번호입니다. 다시 입력해주세요.\n");
            }
            else
                break;
        }
        strcpy_s(pArr[user].pw, 12, pw1);
        printf("변경이 완료되었습니다.\n");
        break;
    default: printf("1 또는 2 중에 선택하세요.\n"); //n이 1또는 2가 아닐 경우
        break;
    }

    return;
}