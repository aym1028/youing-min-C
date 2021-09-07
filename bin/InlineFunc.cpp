#include<iostream>

// inline int SQUARE(int x)
// {
// 	return x*x;
// }
// int main (void)
// {
// 	std::cout<<SQUARE(4)<<std::endl;
// 	std::cout<<SQUARE(25)<<std::endl;
// 	return 0;
// }

template <typename T> //이렇게 사용시 손실 값이 없음 자료형
inline T SQUARE(T x)
{
	return x*x;
}
int main (void)gi
{
	std::cout<<SQUARE(5.5)<<std::endl;
	std::cout<<SQUARE(12)<<std::endl;
	return 0;
}
