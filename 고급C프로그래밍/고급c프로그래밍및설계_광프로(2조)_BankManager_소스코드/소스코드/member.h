#define arrMAXSIZE 50			//전체 회원 수

struct _member {
	char id[12];				//아이디
	char pw[12];				//패스워드
	char name[20];				//이름
	int birth, number, money;   //생년월일, 계좌번호, 잔액 
};
typedef struct _member MEMBER;


void HELP();							//도움말 
void SAVE(MEMBER* pArr, int user);		//예금하기
int ACCOUNT(MEMBER* pArr, int count);   //회원가입
void MONEY(MEMBER* pArr, int user);		//잔액조회
void OUTPUT(MEMBER* pArr, int user);	//출금하기
void SEND(MEMBER* pArr, int user);		//송금하기
int inch(const char* str);				//정수로 변환
int LOGIN(MEMBER* pArr);				//로그인
void CHANGE(MEMBER* pArr, int user);	//회원정보 수정
int MEM(MEMBER* pArr, int count);		//회원정보 불러오기
void BACKUP(MEMBER* pArr, int count);	//회원정보 파일 저장하기
void USE();								//계좌 이용내역 함수