#define arrMAXSIZE 50			//��ü ȸ�� ��

struct _member {
	char id[12];				//���̵�
	char pw[12];				//�н�����
	char name[20];				//�̸�
	int birth, number, money;   //�������, ���¹�ȣ, �ܾ� 
};
typedef struct _member MEMBER;


void HELP();							//���� 
void SAVE(MEMBER* pArr, int user);		//�����ϱ�
int ACCOUNT(MEMBER* pArr, int count);   //ȸ������
void MONEY(MEMBER* pArr, int user);		//�ܾ���ȸ
void OUTPUT(MEMBER* pArr, int user);	//����ϱ�
void SEND(MEMBER* pArr, int user);		//�۱��ϱ�
int inch(const char* str);				//������ ��ȯ
int LOGIN(MEMBER* pArr);				//�α���
void CHANGE(MEMBER* pArr, int user);	//ȸ������ ����
int MEM(MEMBER* pArr, int count);		//ȸ������ �ҷ�����
void BACKUP(MEMBER* pArr, int count);	//ȸ������ ���� �����ϱ�
void USE();								//���� �̿볻�� �Լ�