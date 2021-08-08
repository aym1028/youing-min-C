#include<stdio.h>
#include<time.h>

//물고기 6마리가 있다
// 어항에 살고 있ㄴ느데 . 사막이에요ㅕ
// 사막이 너무 더워서 너무 건조해서 물이 아주 빨리 증발을 해요
// 물이 증발하기 때문에 부지런히 어항에 물을 줘서 물고가를 살려주세요
// 물고기는 시간이 지날수록 커져서 나중에는 냠냠

int level;
int arrayFish[6];
int *cursor;

void initDate();
void printFishes();
void decreaseWater(long elapsedTime);

	
	
int main_pointer_project(void)
{
	long startTime = 0;// 게임 : 시작시간
	long totalElapsedTime = 0; // 총 경과 시간
	long prevElapesedTime= 0;// 직전 경과 시간 (최근에 물을 준 시간간격)
	int num; //몇 번 어항에 물을 줄것인지, 사용자 입력
	initDate();
	
	cursor = arrayFish;// cursor[0]...cursor[2]
	
	startTime = clock(); //clock 함수는 현재 시간을millisecond (1000분의 1초 )단위로 반환
	while(1)
	{
		printFishes();
		printf("몇번의 어항에 물의 주시겠어요? \n");
		scanf("%d",&num);
		
		// 입력 값 체크
		if(num<1 || num >6)
		{
			printf("입력값이 잘못입력되었습니더\n");
			continue;
		}
		//총경과 시간
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("총경과 시간 : %ld\n", totalElapsedTime);
		
		// 직전 물 준 시간 (마지막으로 물준 시간)이후로 흐른 시간 사용자가 물의 주고 10초동안 안줬의때의 물의 높이를 줄여야하기 때문에              
		// 물의 주고 다음 물의 주기전의 공백시간
		
		prevElapesedTime = totalElapsedTime - prevElapesedTime;
		printf("최근 경과 시간 : %ld 초\n", prevElapesedTime);
		
		//어항의 물의 감소 증발
		decreaseWater(prevElapesedTime);
		
		//사용자가 입력한 어항에 물의 준다
		//1. 어항에 물이 0이면 ? 물을 주지 않는다 ..이미 죽음
		if(cursor[num - 1] <=0)
		{
			printf("%d 번의 물고기는 이미 죽었습니다 물의 주지 않습니다\n", num);
			
		}
		//2. 어항의 물이 0이 아닌 경우? 물을 준다! 100을 넘지 않는지 체크 한다 현재어항의 물이 100보다 큰지 아는지를 알아야한다
		else if(cursor[num -1] + 1 <=100)
		{
			//물의 준다
			printf("%d번째 어항에 물을 줍니다\n", num);
			cursor[num-1] +=1; // num 번째 어항에 물의 준다
		}
		
		//레벨업을 할 건지 확인 (레벨업은 2초마다 한번씩 수행)
		if (totalElapsedTime / 20 > level -1) //totalElapsedTime==15초 level == 1일 경우 15나누기 20의 하면 0.7...정도 나오는 데 int에서는 0뒤에는 없어지기때문에 0이된다 level - 1 = 0  그러면 실행안됨
			//1level일때는 20초가 지나면 2level로 업된다
		{
			level++;   //level : 1->2
			printf("***축하합니다 1단계 level업 하였습니다 기존%d레벨에서 %d레벨로 업\n", level-1, level);
			
			//최종레벨 :5
			if (level == 5)
			{
				printf("\n\n\n축하합니다 최고레벨에 달성했습니다 게임의 종료합니다\n");
				exit(0);
			}
		}
		
		//모든 물고기가 죽었는지 확인
		if(checkFishAlive() == 0)
		{
			//물고기 모두 사망
			printf("모든 물고기가 사망하였습니다\n");
			exit(0);
		}
		else
		{
			// 최소 한마리 물고기가 살아있음
			printf("물고기가 아직살아있어요\n");
			
		}
			
		prevElapesedTime = totalElapsedTime;
		//totalElapsedTime은 계속 현재시간이 바뀌어서 들어가기 때문에 임시로  prevElapesedTime에 현재시간의 넣어둔다
		
		
	}
	
	return 0;
}

void initDate()
{
	level = 1;//게임 시작레벨(1~5)
	for (int i = 0; i<6;i++)
	{
		arrayFish[i] = 100;//어항의 물 높이 (0~100)
		
	}
}


void  printFishes()
{
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1,2,3,4,5,6 );
	for(int i = 0; i<6;i++)
	{
		printf(" %4d ", arrayFish[i]);
		
	}
	printf("\n");
}

void decreaseWater(long elapsedTime)
{
	for(int i = 0;i<6;i++)
	{
		arrayFish[i] -=(level * 3 * (int)elapsedTime); //만약에 elapsedTime이 10초가 지났을때 level이 1일때 30 만큼의 물이 줄어든다
		if(arrayFish[i] <0)
		{
			arrayFish[i] = 0;
		}
	}
}


int checkFishAlive()
{
	for(int i =0; i>6;i++)
	{
		if(arrayFish[i] >0)
		{
			return 1; //참 True
		}
		
		
	}
	return 0;
}








