#include<stdio.h>

int main_arr(void)
{
	int arr3[2][5][5] = {
		{
			{1, 2, 3, 4, 5},
			{6, 7, 8, 9, 10},
			{11, 12, 13, 14,15},
			{6, 7, 8, 9, 10},
			{11, 12, 13, 14,15}
		},
		{
			{1, 2, 3, 4, 5},
			{6, 7, 8, 9, 10},
			{11, 12, 13, 14,15},
			{6, 7, 8, 9, 10},
			{11, 12, 13, 14,15}
		}
	};
	
	// for(int i = 0; i<2;i++)
	// {
	// 	for(int k = 0;k<5;k++)
	// 	{
	// 		printf("%d번째%d째값  %d\n",i, k, arr2[i][k]);
	// 	}
	// 	printf("\n");
	// }
	// return 0;
	
	
		for(int i = 0; i<2;i++)
	{
		for(int k = 0;k<5;k++)
		{
			for(int j= 0;j<5;j++)
			{
				printf(" 3차원배열(%d %d %d)의 값 ==%d\n", i,k,j, arr3[i][k][j]);
			}
		}
		printf("\n");
	}
	return 0;
	
}