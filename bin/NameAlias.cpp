#include <iostream>

using std::cout;
using std::cin;
using std::endl;


//이름공간이 중첩되면서 과도하게 사용하는 경우는 드물지만 그런상황이 생겼을때는 이렇게 사용하면 좋다

//범위지정연산자 = :: 지역변수와 전역변수의 이름이 같은 경우에는 전역변수가 지역변수에 가려진다 그런경우 범위지정연산자를 사용해서 전역변수를 쓸 수 있다 (지역변수)val += 20; (전역변수)::val += 40;
{
	namespace BBB
	{
		namespace CCC
		{
			int num1;
			int num2;
		}
	}
}

int main (void)
{
	// AAA::BBB::CCC::num1 = 20;
	// AAA::BBB::CCC::num2 = 30;
	
	namespace ABC = AAA::BBB::CCC;
	
	ABC::num1 =20;
	ABC::num2 =40;
	cout<<ABC::num1<<endl;
	cout<<ABC::num2<<endl;
	return 0;

}