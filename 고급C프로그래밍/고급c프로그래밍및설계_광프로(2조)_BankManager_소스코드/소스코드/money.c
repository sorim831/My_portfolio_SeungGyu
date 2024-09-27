//잔액조회 소스
#include<stdio.h>
#include"member.h"

void MONEY(MEMBER* pArr, int user) {

	printf("회원님의 계좌 잔액은 %d 입니다.\n", pArr[user].money);

	return;
}