#include <iostream>

//2개의 회사가 합동해서 프로젝트를 만들었는데 두회사가 만들때 쓴 함수의 이름이 같고 둘다 함수의 호출조건이
//같을 경우 BestComImp1의 회사의 따로 이름 공간의 만들어주어 함수가 같아도 각자의 함수를 호출한다

namespace BestComImp1
{
	void SimpleFunc(void)
	{
		std::cout<<"BestCom이가 정의한 함수"<<std::endl;
	}
}
namespace ProgComImp1
{
	void SimpleFunc(void)
	{
		std::cout<<"Progcom이가 정의한 함수"<<std::endl;
	}
}

int main (void)
{
	BestComImp1::SimpleFunc();
	ProgComImp1::SimpleFunc();
	return 0;
}