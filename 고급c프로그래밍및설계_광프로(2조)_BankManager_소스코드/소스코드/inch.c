//���ڿ��� -> ������ ��ȯ �ҽ�
int inch(const char* str)
{
	int res = 0;

	while (1)
	{
		if (*str != '\0' && *str >= '0' && *str <= '9') {
			res = (res * 10) + (*str - 48);			//������ ��ȯ
			str++;
		}
		else if (*str == '\0')
			break;
		else {
			res = 0;	//0~9�̿��� ���ڰ� �Էµ� �� res=0
			break;
		}
	}
	return res;
}