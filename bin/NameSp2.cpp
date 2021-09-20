#include <iostream>

namespace BestComImp1
{
	void SimpleFunc(void);
}

namespace ProgcomImp1
{
	void SimpleFunc(void);
}

int main(void)
{
	BestComImp1::SimpleFunc();
	ProgcomImp1::SimpleFunc();
	return 0;
	
}

void BestComImp1::SimpleFunc(void)
{
	std::cout<<"BestCom이 정의한 함수"<<std::endl;
}
void ProgcomImp1::SimpleFunc(void)
{
	std::cout<<"ProgcomImp이 정의한 함수"<<std::endl;
}
