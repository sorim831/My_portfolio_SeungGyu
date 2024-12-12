//문자열형 -> 정수형 변환 소스
int inch(const char* str)
{
	int res = 0;

	while (1)
	{
		if (*str != '\0' && *str >= '0' && *str <= '9') {
			res = (res * 10) + (*str - 48);			//정수로 변환
			str++;
		}
		else if (*str == '\0')
			break;
		else {
			res = 0;	//0~9이외의 문자가 입력될 시 res=0
			break;
		}
	}
	return res;
}