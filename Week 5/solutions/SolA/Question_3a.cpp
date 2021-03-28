#include <stdio.h>
#define MAX 50
/*
CENG104 LabGuide 4, Protracting
Author: EVREN
*/
//finds the position of the minimum element in the array
int min_pos_range (int arr[], int first, int last) 
{	
	int k, min_k;
	
	min_k = first; 

	for (k = first+1; k <= last; k++)
		if (arr[k] < arr[min_k])
		{	
			min_k = k;
 		} 
	return (min_k);
}
void swap (int *x, int *y)
{	
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
void Selection_Sort(int w[],int size)
{
	int top;	// first element in unsorted sub array
	int	ind_of_min; // subscript of the smallest element

	for (top = 0; top < size-1; top++) 
	{	
		ind_of_min = min_pos_range (w, top, size-1);
		// Exchange elements at top and ind_of_min 
		if (top != ind_of_min) 
			swap (&w[top], &w[ind_of_min]); 
	}
}
int main(void)
{
	FILE *inp;
	int points[MAX];
	int size=0, status;
	//open point file
	inp = fopen("points.txt","r");

	//check file
	if(inp == NULL)
		printf("Error in opening file\n");
	else
	{
		//read file content
		status = fscanf(inp,"%d", &points[size]);
		while(status!=EOF)
		{
			size++;
			status = fscanf(inp,"%d",&points[size]);
		}
	
		//sort points in ascending order
		Selection_Sort(points,size);

		//display points
		printf("Points\n");
		printf("------\n");
		for(int j=0; j < size; j++)
			printf("%d\n", points[j]);

		fclose(inp);
	}
	return(0);
}
