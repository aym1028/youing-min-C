#include <iostream>

namespace Hybrid
{
	void HyFunc(void)
	{
		std::cout<<"so simple Function!"<<std::endl;
		std::cout<<"In namespace Hybrid!"<<std::endl;
	}
	
}

int main(void)
{
	using Hybrid::HyFunc;
	HyFunc();
	return 0;
}