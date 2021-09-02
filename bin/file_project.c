#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



//비밀번호룰 입력 받아서 
//맞는경우? 비밀일기를 읽어와서 보여쥬고, 계속 작송하도록 합니다
//틀린경우? 경고 메세지를 표시하고 종료합니다/

#define MAX 100000

int main_file_project(void)
	
{
	char line[MAX];//파일에서 불러온 내용을 저장할 변수
	char contents[MAX];//일기장에 입력할 내용
	char password[20];
	char c;//비밀번호 입력 할 때 키값 확인용
	
	printf("비밀일기에 오신것을 환영합니다\n");
	printf("비밀번호를 입력하세요 : ");
	
	//getchar() / getch 의차이?
	//getchar() 엔터를 입력받아야 동작을 합니다
	//getch() 키입력시 바로바로 동작을합니다
	
	int i = 0;
	while(1)
	{
		c = getch();
		if (c==13)//아스키코드 13은 Enter를 나타낸다
		{
			password[i] = '\0';
			break;
		}
		else//비밀번호 입력중
		{
			printf("*");
			password[i] = c;
		}
		i++;
	}
	
	//비밀번호 : 나도코딩 == skehzheld
	printf("\n\n ====비밀번호 확인중......===\n\n");
	if (strcmp(password, "skehzheld") == 0)//비밀번호 일치
	{
		printf("비밀번호 확인완료  ===\n\n");
		char * fileName ="c:\\secretdiary.txt";
		FILE * file = fopen(fileName,"a+b");//파일이 없으면 생성 , 파일이 있으면 append를한다 뒤에서 내용추가
		if (file == NULL)
		{
			printf("파일열기 실패 \n");
			return 1;
			
		}
		while(fgets(line, MAX, file) != NULL) //line에 읽어온 파일의 내용이 담겨있음
		{
			printf("%s", line);
			
		}
		
		printf("\n\n 내용을 계속 작성하세요 ! 종료하시려면 EXIT를 입력하세요\n\n");
		
		while(1)
		{
			scanf("%[^\n]", contents);//줄바꿈이 나오기전까지 contents에 모두 받아적어라 뜻
			// 즉 한문장씩 저장하겠다 뜻
			getchar();// Enter 입력 (\n) Flush 처리 위에있던 줄바꿈의 없애버리는 효과
			if (strcmp(contents, "EXIT")==0)
			{
				printf("일기 작성의 종료하겠습니다");
				break;
				
			}
			fputs(contents, file);
			fputs("\n", file);
			
			
			
		}
		fclose(file);
		
		
	}
	else//비밀번호가 틀렸을시
	{
		printf("===비밀번호가 틀렸습니다 \n\n ");
		
	}
	
		
	
	
	
	
	
	
	
	
	
	return 0;
}