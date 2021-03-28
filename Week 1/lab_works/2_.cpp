#include<stdio.h>
#define TeamNum 100
int readFromFile(FILE* inp,int arr_1[TeamNum],int arr_2[TeamNum][4])
{	int x;
	int i=0;
	int tNumber=0;
	if(inp==NULL)
	printf("Fýle can not opened\n");
	else
	{int i=0;
		int status=fscanf(inp,"%d",&x);
		while(status!=EOF){
			*(arr_1+i)=x;
			for(int j=0;j<4;j++)
			{
			status=fscanf(inp,"%d",&x);
			(*((*(arr_2+i))+j))=x;	
			}
			status=fscanf(inp,"%d",&x);
			i++;
			tNumber++;
		}		
	}
	return tNumber;
}
void findTeamAvg(int arr[TeamNum][4],double arr_team_avg[TeamNum],int x)
{
	double toplam=0;
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<4;j++)
		{
			toplam+=(*((*(arr+i))+j));
		}
		*(arr_team_avg+i)=toplam/4;
		toplam=0;
	}
}
void findGameAvg(int arr[TeamNum][4],double array_game_avg[4],int x)
{
	double gameScoreToplam=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<x;j++)
		{
			gameScoreToplam+=(*(*(arr+j)+i));		
		}
		*(array_game_avg+i)=gameScoreToplam/x;
		gameScoreToplam=0;
	}
	

}

void displayAvg(double arr_game_avg[4],double arr_team_avg[TeamNum],int arr_id[TeamNum],int t_num)
{
	printf("Team Number\tAvarage\n");
	printf("**** ******\t*******\n");
	for(int i=0;i<t_num;i++)
	{
		printf("%-11d\t",*(arr_id+i));
		printf("%-7.2lf",*(arr_team_avg+i));
		printf("\n");
	}
	printf("\n\n");
	printf("Game Number\tAvarage\n");
	printf("**** ******\t*******\n");
	for(int i=0;i<4;i++)
	{
		printf("%-11d\t",i+1);
		printf("%-7.1lf",*(arr_game_avg+i));
		printf("\n");	
	}
}

int main()
{
	FILE* inp;
	inp=fopen("bowling.txt","r");
	int arr_id[TeamNum];
	int arr_scores[TeamNum][4];
	double arr_game_avg[4];
	double arr_team_avg[TeamNum];
	int t_num=readFromFile(inp,arr_id,arr_scores);

	findTeamAvg(arr_scores,arr_team_avg,t_num);
	findGameAvg(arr_scores,arr_game_avg,t_num);
	displayAvg(arr_game_avg,arr_team_avg,arr_id,t_num);	
}
