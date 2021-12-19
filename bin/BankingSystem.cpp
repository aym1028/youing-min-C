// Banking system
// 작성자:안영민

#include<iostream>
#include<cstring>

using namespace std;
const int NAME_LEN=20;

void showMenu(void); //메뉴 출력
void MakeAccont(void); //계좌 개설
void DepositMoney(void); //입금
void WithdrawMoney(void); //출금
void ShowALLaccinfo(void); //잔액

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct Accont
{
	int accID; //계좌 번호
	int balance; // 잔액
	char cusName[NAME_LEN]; //고객이름
} Accont;

Accont accArr[100]; //Accont 저장을 위한 배열 고객의 100 명 
int accNUM=0; //저장된 고객의 수

int main(void)
{
	int choice;
	
	while(1)
	{
		showMenu();
		cout<<"선택 : ";
		cin>>choice;
		cout<<endl;
		
		switch(choice)
		{
			case MAKE:
				MakeAccont();
				break;
			case DEPOSIT:
				DepositMoney();
				break;
			case WITHDRAW:
				WithdrawMoney();
				break;
			case INQUIRE:
				ShowALLaccinfo();
				break;
			case EXIT:
				return 0;
			default:
				cout<<"잘못 선택하셨습니다.."<<endl;	
		}
		
	}
	return 0;
}

void showMenu(void)
{
	cout<<"------------MENU-------------"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입금"<<endl;
	cout<<"3. 출금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5, 프로그램 종료"<<endl;
}


void MakeAccont(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	cout<<"---[계좌개설]=----"<<endl;
	cout<<"계좌ID: "; cin>>id;
	cout<<"이름: "; cin>>name;
	cout<<"입금액: "; cin>>balance;
	cout<<endl;
	
	
	accArr[accNUM].accID=id; //accNUM번쨰 배열공간에 정보를 집어 넣는다
	accArr[accNUM].balance=balance;
	strcpy(accArr[accNUM].cusName, name);// 문자열이기때문에 카피해서 
	accNUM++; //고객의 수 증가
}
void DepositMoney(void)
{
	int money;
	int id;
	cout<<"---[입금]---"<<endl;
	cout<<"계좌ID : "; cin>>id;
	cout<<"입급액 : "; cin>>money;
	
	for(int i=0;i<accNUM;i++)
	{
		if(accArr[i].accID == id)
		{
			accArr[i].balance += money;
			cout<<"입금완료!!"<<endl<<endl;
			return;
		}
	}
	cout<<"유효하지 않은 아이디 입니다."<<endl<<endl;
		
}
void WithdrawMoney(void)
{
	int money;
	int id;
	cout<<"---[출금]---"<<endl;
	cout<<"계좌Id :";cin>>id;
	cout<<"출급액 :";cin>>money;
	for(int i=0;i<accNUM; i++)
	{
		if (accArr[i].accID == id)
		{
			if(accArr[i].balance < money)
			{
				cout<<"잔액 부족입니다."<<endl<<endl;
				return;
			}
			accArr[i].balance -= money;
			cout<<"출금완료"<<endl;
			return;
		}
	}
	cout<<"유효하지않은 ID입니다"<<endl;
}
void ShowALLaccinfo(void)
{
	for(int i=0;i<accNUM;i++)
		{
			cout<<"계좌ID: "<<accArr[i].accID<<endl;
			cout<<"이름  : "<<accArr[i].cusName<<endl;
			cout<<"잔액  : "<<accArr[i].balance<<endl;
			
		}
		
}
git add .
git commit -m "내가 보내는 파일 이름"
git push 


