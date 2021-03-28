/*
CENG104 LabGuide 4, Protracting
Author: EVREN
*/
#include <stdio.h>
#define MAX 50

void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void bubble_sort(int arr[], int size)
{
	int	i,sorted,pass;

	pass=1;//this counter avoids to look to the same elements in the array which are sorted
	do{
		sorted=1;//this controls if all the elements are sorted or not.

		for(i=0; i<size-pass; i++)//size-pass because we do not want to control the sorted array elements 
		{
			if (arr[i+1]>arr[i]) //if next element is bigger that the current one
			{
				swap(&arr[i], &arr[i + 1]);//swap these
				sorted = 0;
			}
		}
		pass++;

	}while(!sorted);//continue while the sort operation is not completed
}

int main(void)
{
	FILE *inp;
	int points[MAX];
	int size=0, status;
	//open points file
	inp = fopen("points.txt","r");

	//check file
	if(inp == NULL)
		printf("Error in opening file");
	else
	{
		//read file content
		status = fscanf(inp,"%d",&points[size]);

		while(status!=EOF)
		{
			size++;
			status = fscanf(inp,"%d",&points[size]);
		}
	
		//sort points in descendding order
		bubble_sort(points,size);

		//display points
		printf("Points\n");
		printf("------\n");
		for(int j=0; j < size; j++)
			printf("%d\n", points[j]);
				
		fclose(inp);
	}
	return(0);
}
