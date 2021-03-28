#include <stdio.h>
#include <string.h>
/*
CENG104 LabGuide 4, Protracting
Author: EVREN
*/
#define MAX_ROW 100   //maximum row number
#define MAX_COL 20    //maximum col number

//exchange two song names in the song list
void swap(char *x, char *y)
{
	char temp[MAX_COL];

	strcpy(temp, x);
	strcpy(x, y);
	strcpy(y, temp);
}

//sorts the song names in ascending order
void bubble(char songs[][MAX_COL], int n)
{
	int	i,
		sorted,
		pass;
	char	temp[MAX_COL]="";

	pass=1;
	do{
		sorted=1;

		for(i=0; i<n-pass; i++)
		{
			if (strcmp(songs[i], songs[i+1]) >0)
			{
				swap(songs[i], songs[i + 1]);
				sorted = 0;
			}
		}
		pass++;

	}while(!sorted);
}

/*Function displays the Top Songs*/
void display(char list[][MAX_COL], int n)
{
	int k;

	printf("\nTop Songs ");
	printf("\n--------------------");
	for(k = 0; k < n ; k++)
		printf("\n%d) %s",k+1, list[k]);
	printf("\n");
}

int main (void)
{
	char list[MAX_ROW][MAX_COL];//song list
	char temp[MAX_COL];//temporary array
	int size=0;
	int added;

	//read file content
	printf("Enter a song name (end to stop): ");
	scanf("%[^\n]", temp);

	while(strcmp(temp,"end")!=0)
	{
		strcpy(list[size],temp);
		size++;

		printf("Enter a song name (end to stop): ");
		scanf(" %[^\n]", temp);
	}

	bubble(list,size); //sort the list
	display(list,size);	 //display the list	
			
	return (0) ;
}
