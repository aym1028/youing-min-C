#include<iostream>
using namespace std;
int main()
{
	char irum[30];
	cout << "성함, 전화번호를 입력하세요\n";
	cin.getline(irum, sizeof(irum)); //이렇게 쓰면 공백도 입력가능
	//cin >> irum;  //cin은 뛰어쓰기 등등 입력의 받지 못한다 공백의 입력받지 못한다
	//출력
	cout << " 구메금액을 입력하세여\n";
	int caltot, calpoint;
	
	cin >>caltot;
	calpoint =caltot * 0.01;
	cout << irum << "님포인트는 : " << calpoint << "입니다\n";
}