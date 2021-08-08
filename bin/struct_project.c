#include<stdio.h>
#include<time.h>



//5마리의 고양이가 있다
//아무 키나 눌러서 랜덤으로 고양이를 뽐되
// 5마이 모두 다 수집을 해서 열심히 키우면 되는 게임
// 그런데 중복 발생가능!


// 고양이
// 이름, 나이, 성격. 키우기 난이도(레벨정보)

// typedef struct {
// 	char *name;// 이름
// 	int age; // 나이
// 	char *character; // 성격
// 	int level;//난이도
	
// } CAT;

typedef struct CAT {
	char *name;// 이름
	int age; // 나이
	char *character; // 성격
	int level;//난이도 (1~5)5난이도가 가장키우기 어려움
	
};


// 현재까지 보유한 고양이
int collection[5] = {0,0,0,0,0};

//전체 고양이 리스트
struct CAT cats[5];


void initCats();//고양이 정보 초기화
void printCat(int selected); //내가 뽑은 고양이의 정보 출력

int main(void)
{
	srand(time(NULL));
	initCats();
	while (1)
	{
		printf("두근 두근 어느 고양이의 집사가 될까요? \n 아무키나 눌러서 확인하세요");
		getchar(); //어떤키를 누를 때까지 대기
		
		
		int selected = rand() % 5; //0~4사이의 숫자 반환 
		printCat(selected);// 뽑은 고양이의 정보 출력
		collection[selected] = 1;// 고양이 뽑기 처리 (뽑은 고양이의 처리)
		
		int collectionAll = checkCollection();
		if (collectionAll == 1)
		{
			break;
		}
		
	}
	
	return 0;
}

void initCats()
{
	cats[0].name = "김부건";
	cats[0].age = 5;
	cats[0].character ="온순";
	cats[0].level = 1;
	
	cats[1].name = "안영민";
	cats[1].age = 3;
	cats[1].character ="날카롭";
	cats[1].level = 2;
	
	
	cats[2].name = "최지웅";
	cats[2].age = 7;
	cats[2].character ="늘 잠만 잠";
	cats[2].level = 3;
	
	
	cats[3].name = "고원빈";
	cats[3].age = 2;
	cats[3].character ="시끄러움";
	cats[3].level = 4;
	
	
	
	cats[4].name = "문성준";
	cats[4].age = 1;
	cats[4].character ="배고픔";
	cats[4].level = 5;
	
}
void printCat(int selected)
{
	printf("\n\n#####당신은 이 고양이의 집사다 되었습니다######\n\n");
	printf("이름      : %s\n", cats[selected].name);
	printf("나이      : %d\n", cats[selected].age);
	printf("성격(특징) : %s\n", cats[selected].character);
	printf("난이도     :");
	for(int i=0;i<cats[selected].level;i++)
	{
		printf("%s","★" );
	}
	printf("\n\n");
}
int checkCollection()
{
	// 현재 보유한 고양이 목록도 출력, 다 모았는지 여부도 확인
	
	int collectAll = 1;
	
	printf("\n\n +++보유한 고양이 목록이에요 +++++\n\n");
	for(int i=0;i<5;i++)
	{
		if (collection[i] == 0) //고양이가 0마리 0이면 없는거
		{
			printf("%10s", "(빈 박스)");
			collectAll = 0;// 다 모으지 못한 상태
		}
		else // 고양이가 있음 0이아니면 있는것
		{
			printf("%10s", cats[i].name); //cats[i]번째에 고양이는 수집을 함
		}
	}
	printf("==================================\n\n");
	
	
	if (collectAll)
	{
		printf("\n\n+++축하합니다 모든 고양이를 모았습니다 앞으로 잘 키워주세요+++\n\n");
	}
	
   
	return collectAll;
	// 고양이를 다 수집했으면 1이 반환이 되고 아직 다안됬으면 0이 반환된다
	
}
















