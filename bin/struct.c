#include<stdio.h>

struct Gameinfo{
	char * name;
	int year;
	int price;
	char * company;
	
	struct Gameinfo * friendGame; // 연관 게임 업체
};


typedef struct Gameinformation {
	char * name;
	int year;
	int price;
	char * company;
	
	struct Gameinfo * friendGame; // 연관 게임 업체
} GAME_INFO;

int main_struct(void)
{

	// [게임 출시]
	// [이름 : 나도게임]
	// 발매년도 : 2017년
	// 가격 :50원
	// 제작사 :나도회사
	
	struct Gameinfo gameinfo1;
	
	gameinfo1.name = "나도게임";
	gameinfo1.year = 2017;
	gameinfo1.price = 50;
	gameinfo1.company = "나도회사";
	
	//구조체 출력
	printf("게임 회사 : %s\n", gameinfo1.name);
	printf("게임 출시년 : %d\n", gameinfo1.year);
	printf("게임 가격 : %d\n", gameinfo1.price);
	printf("게임 제작사 : %s\n", gameinfo1.company);
	
	
	// 구조체 배열처럼 초기화
	struct Gameinfo gameinfo2 = {"너도게임", 2017, 100, "너도회사"};
	
	printf("다른 게임 출시 정보\n");
	printf("게임 회사 : %s\n", gameinfo2.name);
	printf("게임 출시년 : %d\n", gameinfo2.year);
	printf("게임 가격 : %d\n", gameinfo2.price);
	printf("게임 제작사 : %s\n", gameinfo2.company);
	
	
	//구조체 배열 
	struct Gameinfo gameArray[2] = {
		{"너도게임", 2017, 100, "너도회사"},
		{"나도게임", 2017, 50, "나도회사"}
	};
	
	//구조체 포인터
	
	struct Gameinfo * gamePtr;
	gamePtr = &gameinfo1;
	// printf("\n\n또다른 미션맨의 게임 출시  \n");
	// printf("게임 회사 : %s\n", (*gamePtr).name); //(*gamePtr)의 값을 먼저 정의를 하고 그다음 그안에 있는 .name 값의 가져온다
	// printf("게임 출시년 : %d\n", (*gamePtr).year);//*gamePtr안의 실제값의 먼저 찾고 그다음 실제값 안에있는 .name값의 가져온다
	// printf("게임 가격 : %d\n", (*gamePtr).price);
	// printf("게임 제작사 : %s\n", (*gamePtr).company);
	
	
	//구조체 포인터의 일때는 .의쓰거나 혹은 ->를 사용한다 
	printf("\n\n또다른 미션맨의 게임 출시  \n");  
	printf("게임 회사 : %s\n", gamePtr->name); 
	printf("게임 출시년 : %d\n", gamePtr->year);
	printf("게임 가격 : %d\n", gamePtr->price);
	printf("게임 제작사 : %s\n", gamePtr->company);
	
	// 연관 업체 게임 소개 (구조체 안의 구조체)
	
	gameinfo1.friendGame = &gameinfo2;
	printf("\n\n연관 없체의 게임 출시  \n");  
	printf("게임 회사 : %s\n", gameinfo1.friendGame->name); 
	printf("게임 출시년 : %d\n",gameinfo1.friendGame->year);
	printf("게임 가격 : %d\n", gameinfo1.friendGame->price);
	printf("게임 제작사 : %s\n", gameinfo1.friendGame->company);
	
	
	//typedef
	//자료형의 별명 지정
	// int i = 1;
	// typedef int 정수;
	// typedef float 실수;
	// 정수 정수변수 = 3;
	// 실수 실수변수 = 3.23f;
	
	// printf("정수 변수 = %d\n", 정수변수);
	// printf("실수 변수 = %.2f\n", 실수변수);
	
	
	
 	typedef struct Gameinfo 게임정보;
 	게임정보 game1;
 	game1.name = "한글 게임";
 	game1.year = 2015;
	
 	GAME_INFO game2;
 	game2.name = "한글게임 2";
 	game2.year = 2014;
	
	
	
	
	
	return 0;
}
