#include <iostream>

int main(void)
{
	int money, result;
	while(1)
	{
		std::cout<<"판매 금액을 단위로 입력(-1 to end) : ";
		std::cin>>money;
		if(money == -1)
		{
			std::cout<<"프로그램의 종료합니다\n";
			break;
			
		}
		else
		{
			result = 50 + money *0.12;
			std::cout<<"이번달 급여 : "<<result<<"만원입니다"<<"\n";
		}
	}	
 
	
	
	
	return 0;
}