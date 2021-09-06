#include <iostream>
int BoxVolume(int leghth, int width = 1, int height = 1);
	
int main()
{
	std::cout<<"[3,3,3] :"<<BoxVolume(3, 3, 3)<<std::endl; //27
	std::cout<<"[5,5,D] :"<<BoxVolume(5, 5)<<std::endl; //25 
	std::cout<<"[7,D,D] :"<<BoxVolume(7)<<std::endl;//0 
	//std::cout<<"[D,D,D] :"<<BoxVolume()<<std::endl; // int leghth 에 값이 안들어갈게 없기 때문에 오류가선언된다
}
int BoxVolume(int leghth, int width, int height)
{
	return leghth*width*height;
}