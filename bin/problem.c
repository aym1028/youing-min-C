#include <stdio.h>

int main(void)
{
	int a=10;
	int b=20;
	printf("swp 함수 전의 a : %d, b :%d \n", a, b);
	
	swap(a, b);
	
	printf("swap 함수 후의 a : %d,b :%d\n", a, b);
	
	printf("주소값 전달  swap 함수 전 a :%d, b:%d\n", a, b);

	swap_addr(&a, &b);
	
	printf("주소값 전달  swap 함수 후 a :%d, b:%d\n", a, b);
}