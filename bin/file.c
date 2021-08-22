#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


#define MAX 10000
int main(void)
{
	//파일 입출력
	//파일에 어떤 데이터를 저장
	//파일애 저장된 데이터를 불러오기
						
	//fputs, fgets -> 문자열
	char line[MAX]; //char line[10000]
	//파일 쓰기
	// FILE * file =fopen("c:\\test1.txt", "wb");
	// if (file == NULL)
	// {
	// 	printf("파일 열기 실패\n");
	// 	return 1;
		
	// }
	// fputs("fputs 를 이용해서 글을 적어볼게요\n", file);
	// fputs("잘 적히는지 확인해주세요\n", file);
	
	
	
	
	//파일 일기
	// FILE *file =fopen("c:\\test1.txt", "rb");
	// if (file == NULL)
	// {
	// 	printf("파일 열기 실패\n");
	// 	return 1;
	// }
	// while(fgets(line, MAX, file) != NULL)
	// {
	// 	printf("%s", line);
		
	// }
	
	
	//fclose(file);
	//파일을 열고 나서 닫지 않은 상태에서 어떤 프로그램에 문제가 생기면?
	//데이터 손실 발생가능 ! 그래서 항상 파일을 닫아주는 습관을 들어주세요
	
	
	//fprintf, fscanf
	
	//파일 쓰기
	int num[6] = {0,0,0,0,0,0}; // 로또 추천번호
	int bonus = 0; //보너스 번호
	char str1[MAX];
	char str2[MAX];
	// FILE * file = fopen("c:\\test2.txt", "wb");
	// if (file == NULL)
	// {
	// 	printf("파일 열기 실패");
	// 	return 1;
	// }
	 
	// //로또 추첨 번호 저장
	// fprintf(file, "%s %d %d %d %d %d %d\n", "추첨번호", 1,2,3,4,5,6);
	// fprintf(file, "%s %d\n", "보너스 번호", 7);
	
	
	//파일 읽기
	FILE * file = fopen("c:\\test2.txt", "rb");
	if (file == NULL)
	{
		printf("파일 읽기 실패\n");
		return 1;
	}
	fscanf(file, "%s %d %d %d %d %d %d", str1,
	 	   &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
	printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3], num[4], num[5] );
	
	
	fscanf(file, "%s %d" , str2, &bonus);
	printf("%s %d \n", str2, bonus);
	
	
	
	fclose(file);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}


















