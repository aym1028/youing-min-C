#include <stdio.h>
void swap (int a , int b);
void swap_addr (int *a, int *b);
void changeArray(int *ptr);

int main_pointer(void)
{
	// int arr[3] = { 5, 10, 15};
	// int *ptr = arr;
	// for (int i = 0; i < 3; i++)
	// {
	// 	printf("배열 arr[%d]의 값 : %d\n", i, arr[i] );
	// }
	// 	for (int i = 0; i < 3; i++)
	// {
	// 	printf("포인터 arr[%d]의 값 : %d\n", i, ptr[i] );//배열하나하나의 주소값의 포인터 변수가 가지고 있다
	// }
	// ptr[0] = 100;
	// ptr[1] = 200;
	// ptr[2] = 300;
	// 	for (int i = 0; i < 3; i++)
	// {
	// 	//printf("배열 arr[%d]의 값 : %d\n", i, arr[i]) 같다 두문법
	// 	printf("배열 arr[%d]의 값 : %d\n", i, *(arr + i)); // arr[i]라고 하면 배열이기 때문에 실제값의 가져온다
	// 		                                    	// arr+ i라고 치면 주소값을 가져온다 그래서 *붙여준다
	// }
	// for (int i = 0; i < 3; i++)
	// {
	// 	//printf("포인터 ptr[%d]의 값 : %d\n", i, ptr[i]);
	// 	printf("포인터 ptr[%d]의 값 : %d\n", i, *(ptr + i));
	// }
	
	// //주소값
	// printf("arr 자체의 값 : %d\n", arr);
	// printf("arr[0] 의 주소 : %d\n", &arr[0]);
	
	// //실제값
	// printf("arr 자체의 값이 가지는 주소의 실제 값 : %d\n", *arr); //*(arr + 0)
	// printf("arr[0] 의 실제값: %d\n", *&arr[0]);
	
	// // *&는 아무것도 없는 것과 같다 & 주소 *는 그주소의 값이기 때문에 *&같이 있으면 상쇄된다 
	// printf("arr[0] 의 실제값: %d\n", *&*&*&*&*&*&arr[0]);
	
	// // *(arr + i) == arr[i]
	// //	
	
	
	//SWAP
	
	// int a = 10;   //main 함수 내에서 a, b와 swap함수 내에서 a,b는 서로 다르다
	// int b = 20;	  //그래서 주소 값을 보내서 주소의 값이 변하도록 ㄹ하는 것이다
	
	
	
	
	// printf("swp 함수 전의 a : %d, b :%d \n", a, b);
	
	// swap(a, b);
	
	// printf("swap 함수 후의 a : %d,b :%d\n", a, b);
	
	// printf("주소값 전달  swap 함수 전 a :%d, b:%d\n", a, b);
	
	// swap_addr(&a, &b);
	
	// printf("주소값 전달  swap 함수 후 a :%d, b:%d\n", a, b);
	
	
	
	// 배열일 때 arr2[3] -> 주소 배열일때는 자체가 주소를 가지고 있다
		
	
	int arr2[3] = {10, 20, 30};
	//changeArray(arr2);
	changeArray(&arr2[0]);
	for(int i = 0; i<3; i++)
	{
		printf("%d\n", arr2[i]);
	}
	
	// scanf  에서 왜 앞에 &num의 보냈는지
	
	return 0;
}

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	printf("swap 함수 내의 a :%d, b = %d\n",a, b);
}
void swap_addr(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("swap 함수 내의 a :%d, b =%d\n", *a, *b);
}

void changeArray(int *ptr)
{
	ptr[2] = 50;
}
	


