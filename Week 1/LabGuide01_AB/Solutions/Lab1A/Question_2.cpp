/*the purpose of the program is calculating each scores avg and each scores avg */ 
#include <stdio.h>
/*CENG104 Lab1-A Question2
Author: Evren*/
#define TEAM 50
#define GAME 4

//read the team ids and scores from the bowling.txt file into the arrays
void
readFromFile(FILE * inp, int *teams, int scores[][GAME], int *noOfTeams)
{
	int i, j, status, id;
	
	i = 0;
	status = fscanf(inp, "%d", &id);
	while (status != EOF)
	{
		*(teams+i) = id;
		
		//getting scores of the team
		for (j = 0; j<GAME; j++) {
			fscanf(inp, "%d", (*(scores+i)+j));
		}				
		i++;
		status = fscanf(inp, "%d", &id);//get the id 
	}
	*noOfTeams = i;
}

//find the average of each team and store them in a one-dim array
void findTeamAvg(int scores[][GAME], double *teamAvg, int noOfTeams)
{
	int i, j;
	double sum = 0;
	for (i = 0; i<noOfTeams; i++)
	{
		for (j = 0; j<GAME; j++)
			sum = sum + *(*(scores+i)+j);
		*(teamAvg+i) = sum / GAME;
		sum = 0;
	}
}
//find the average of each game and store them in a one-dim array
void findGameAvg(int scores[][GAME], double *gameAvg, int noOfTeams)
{
	int i, j;
	double sum = 0;
	for (i = 0; i<GAME; i++)
	{
		for (j = 0; j<noOfTeams; j++)
			sum = sum + *(*(scores + j) + i);
		*(gameAvg+i) = sum / noOfTeams;
		sum = 0;
	}
}
//displays the average score for each game
void displayGameAvg(double *gameAvg)
{
	printf("\n\nGame Number  Average	\n");
	printf("***********  *******\n");
	for (int i = 0; i < GAME; i++)
		printf("%d %16.1f\n", i+1, *(gameAvg+i));
}

int main()
{	
	FILE *inp;
	FILE *team;
	
	int	i=0, j=0, id, size, status, noOfTeams;
	int	teamIds[TEAM];
	int	scores[TEAM][GAME];
	double teamAvg[TEAM],
			gameAvg[GAME];

	inp = fopen("bowling.txt","r");
	if(inp == NULL)	//if the file is not found
		printf("File can not be opened");
	else
	{	
		//read the team ids and scores from the bowling.txt file into the arrays
		readFromFile(inp, teamIds, scores, &noOfTeams);

		//find the average of each team and store them in a one-dim array
		findTeamAvg(scores, teamAvg, noOfTeams);

		//display the avg scores of each team
		printf("Team Number  Average\n");
		printf("***********  *******\n");
		for (i = 0; i < noOfTeams; i++)
			printf("%3d %15.2f\n", *(teamIds+i), *(teamAvg+i));

		//find the average of each game and store them in a one-dim array
		findGameAvg(scores, gameAvg, noOfTeams);

		//displays the average score for each game
		displayGameAvg(gameAvg);

		fclose(inp);
	}
	return(0);
}

