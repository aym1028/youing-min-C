#include<stdio.h>
#include<time.h>
#include<stdlib.h>


//10마리의 서로 다른 동물 (각 카드2장씩)
//사용자로부터 2개의 입력값을 받아서 -> 같은 동물 찾으면 카드 뒤집기
//모든 동물 쌍을 찾으면 게임 종료
// 총실패 횟수 알려주기
int arrayAnimal[4][5]; //카드지도 전체카드 20장
int checkAnimal[4][5]; // 뒤집렸는지 여부 확인
char *strAnimal[10]; //메모리 공간속에 동물이름이 들어가있는 주소값이 들어있을곳
int getEmptyPosition();
int cony_pos_x(int x);
int cony_pos_y(int y);
int foundAllAnimals();
	
void iniAnimalArray();
void initAnimalName();
void shuffleAnimal();
void printAnimals();
void printQuestion();
int main_m_array_project (void)
{
	srand(time(NULL));
	
	iniAnimalArray();
	initAnimalName();
	
	shuffleAnimal();  
	
	int failCount = 0;// 실패 횟수
	
	while(1)
	{
		int select1 = 0;//사용자가 선택한 처음 수
		int select2 = 0;//사용자가 선택한 두번째 수
		
		printAnimals();//동물 위치 출력
		printQuestion();// 문제 출력(카드지도) 어떠어떤한 상황이니까 문제를 풀어보세요 그런상황을 표현하는
		printf("뒤집을 카드를 2개 고르세요 ");
		scanf("%d%d", &select1, &select2);
		
		if(select1 == select2)
		{
			
			continue;
		}
		
		//선택한 카드가 뒤집어보고 맞는지 안맞는지 확인을 한다
		
		//정수로 입력한 좌표를 x,y배열 좌표로 전환
		int firstSelect_x = cony_pos_x(select1);
		int firstSelect_y = cony_pos_y(select1);
		
		int secondSlelect_x = cony_pos_x(select2);
		int secondSlelect_y = cony_pos_y(select2);
		
		//0와 같다면 아직 뒤집지 않은것
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0
			&& checkAnimal[secondSlelect_x][secondSlelect_y] == 0)
			
			
			&& 
			
			(arrayAnimal[firstSelect_x][firstSelect_y]
			 == arrayAnimal[secondSlelect_x][secondSlelect_y])
		   )
		{
			printf("\n\n빙고: %s를 발견했습니다\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]); //정답이면 두개가 같은 동물 이므로 first , second두중 하나의 값만 들어와도 된다
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSlelect_x][secondSlelect_y] = 1;	//값의 1로 바꾸어야 정답을 맞춘것
		}
		else 
		{
			printf("\n땡(틀렸거나ㅣ 이미 뒤집힌카드입니다)\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSlelect_x][secondSlelect_y]]);
			printf("\n\n");
			
			failCount++;
		}
		
		if(foundAllAnimals() == 1)
		{
			printf("\n\n모든 동물의 다찾았11습니다 축하합니다 지금까지 총 %d 번의 실수 만에 정답을 다 맞추셨습니다\n", failCount); 
			break;
			
		}
		
		
		
		
			
		
	}
	
	return 0;
}


void iniAnimalArray()
{
	for(int i =0;i<4;i++)
	{
		for(int j=0;j<5;j++)//2차원 배열에 처음 값초기화를 해준다
		{
			arrayAnimal[i][j] = -1;
		}
	}
}
void initAnimalName()
{
	strAnimal[0] ="원숭이";
	strAnimal[1] ="하마";
	strAnimal[2] ="강아지";
	strAnimal[3] ="고양이";
	strAnimal[4] ="돼지";
	
	strAnimal[5] ="코끼리";
	strAnimal[6] ="기린";
	strAnimal[7] ="낙타";
	strAnimal[8] ="타조";
	strAnimal[9] ="호랑이";
	
}
void shuffleAnimal()
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<2;j++)
		{
			int pos = getEmptyPosition();
			int x = cony_pos_x(pos);
			int y = cony_pos_y(pos);
			
			arrayAnimal[x][y] = i; // 랜던으로 나온 [x][y]를 랜던으로 동물의 집어넣는다
		}
	}
}
//좌표에서 빈공간 찾기
int getEmptyPosition()
{
	while(1)
	{
		int randPos = rand() % 20; //0~19사이의 숫자를 반환
		// 19 == [3][4] 로 바꾸어야 좌표에 접근이 가능하다
		int x = cony_pos_x(randPos);
		int y = cony_pos_y(randPos);
		
		if (arrayAnimal[x][y] == -1 )
		{
			return randPos;
		}
		
		
		
	}
	return 0;
}
int cony_pos_x(int x)//랜덤으로 받은 좌표를 배열의 값으로ㅓ 바꾸는역할
{
	
	
	
	return x / 5;
	
}
int cony_pos_y(int y)
{
	
	
	return y % 5;
	
}
void printAnimals() //동물 위치 출력
{
	printf("\n##############몰래#############################3\n\n");
	for(int i = 0;i<4;i++)
	{
		for(int j = 0;j<5;j++)
		{
			printf("%8s\t", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n###########################################3\n\n");
	
}


void printQuestion()
{
	printf("\n\n 문제 \n");
	int seq = 0;
	
	for(int i =0;i<4;i++)
	{
		for(int j =0;j<5;j++)
		{
			//카드를 뒤집어서 정답을 맞혔으면 '동물 이름'
			if(checkAnimal[i][j]!=0) //0이아니면 뒤집은것 정답을 맟친것
			{
				printf("%11s",strAnimal[arrayAnimal[i][j]]);
			}
			else//아직 뒤집지 못했으면 (정답을 못맞쳤으면)뒷ㅁ면 -> 위치를 나타내는 숫자)
			{
				printf("%8d", seq);
			}
			seq++;
			
		}printf("\n");
	}
	
}

int foundAllAnimals()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++) 
		{
			if (checkAnimal[i][j] ==0)
			{
				return 0;
			}
		
			
		}
	}
	return 1;// for 문을 다돌았는데 값이 0인게 없으면 return1 모든 동물의 다찾음
}









