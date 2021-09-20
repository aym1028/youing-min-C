#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//using namespace std; 이렇게 선언하면 위에처럼 하나하나씩 안써도 똑같은 실행결과가 나온다 
//하지만 위에처럼 namespace를 쓰는것 보다는 하나하나 선언하는것이 좋은 습관이다 하나하나 씩하면 이름공간 충돌 확률이 줄기 때문이다

int main (void)
{
	int num = 20;
	char* name;
	cout<<"Hello world!"<<endl;
	cout<<"Hello"<<" "<<"world"<<endl;
	cout<<num<<' '<<'A';
	cout<<' '<<3.14<<endl;
	cin>>num;
	return 0;
}