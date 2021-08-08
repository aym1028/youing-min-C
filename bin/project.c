#include<stdio.h>
#include<time.h>
// 영어는 1글자 : 1byte
// 한글는 1글자 : 2byte

int main_project(void)
{
    srand(time(NULL));
    printf("\n\n == 아빠는 대머리 게임 =\n\n");
    int answer; // 사용자 입력값 
    int treament = rand() % 4; //발모제 선택(0~3)

    int cntShowBottle = 0; //이번 게임에 보여줄 병 갯수
    int preCntshowBottle = 0; //앞 게임에 보여준 병 갯수
    //서로 보여주는 병 갯수를 다르게하여 정답률 향상(처음에는2개-> 다음엔 3개 ...)
    
    //총 3번의기회(3번의 발모제 투여)
    for (int i=1; i<=3; i++)
    {
        int bottle[4] = {0,0,0,0}; //4개의 병
        do{
            cntShowBottle = rand() % 2 + 2; //보여줄 병 갯수 (0~1인데 +2를 하였으므로 2~3)

        }while(cntShowBottle == preCntshowBottle);
        int islncluded = 0;//보여줄 병 중에 발모제가 포함되었는지 여부
        printf(" %d 번째 시도 : ", i);

        //보여줄 병 종류를 선택
        for(int j=0; j<cntShowBottle;j++)
        {
            int randBottle = rand() % 4; //0~3

            //아직 선택되지 않은 병이면 선택처리
            if (bottle[randBottle] == 0)
            {
                bottle[randBottle] = 1;
                if(randBottle == treament)
                {
                    islncluded = 1;
                }

            }
            else 
            {
                j--;
            }
        }
        for(int k=0; k<4;k++)
        {
            if(bottle[k] == 1)
            {
                printf("%d", k+1);
            }
        }
        printf("물약을 머리에 바릅니다\n\n");
        if(islncluded == 1)
        {
            printf("성공\n");
        }
        else
        {
            printf("실패");
        }

        printf("\n 계속하려면 아무키나 누르세요\n");
        getchar();
    }

    printf("\n발모제는 몇번일까요? : ");
    scanf("%d", &answer);
    if(answer == treament + 1)
    {
        printf("\n정답");
    }
    else
    {
        printf("\n실패 정답을!!!!!!! %d\n ", treament + 1);
    }

    return 0;
}
 