/*CENG104 Lab1-A Question1
Author: Evren*/
#include <stdio.h>
#define MAX 4

//function product that finds the product of the values in a one dimensional array
int product(int arr[], int size) {//returns an integer as product and takes an array and its size as parameters
	int pro = 1, i;//initializes the product to 1
	for (i = 0; i<size; i++)//start from 0 to size of the array one by one
		pro = pro * arr[i];	//multiply all the elements with the other one to find the product
	return(pro);		//return the product

}

//function disp-one that displays the elements of a one-dimensional array
void disp_one(int arr[], int size) {		//returns nothing, gets an array and its size as parameters
	int i;
	for (i = 0; i<size; i++)			//start from 0 and go to size one by one
		printf("%d ", arr[i]);		//display the element on the screen

}

//function disp-two that displays the elements of a two-dimensional array with 4 columns
void disp_two(int arr[][MAX], int row) {			//returns nothing, gets a matrix and the row number of the matrix as parameters 
	int i, j;
	for (i = 0; i<row; i++) {				//start from the first row go through the last one
		for (j = 0; j<MAX; j++)			//start from the first column and go trought the last one
			printf("%4d", arr[i][j]);	//display the value of that cell
		printf("\n");
	}
}

//function findMax that finds the maximum number of a two-dimensional array with 4 columns
int findMax(int arr[][MAX], int row) {			//returns the max number, gets a matrix and the row number of the matrix as parameters 
	int i, j, max=arr[0][0];						//assume that the first value is the maximum
	for (i = 0; i<row; i++) 				//start from the first row go through the last one
		for (j = 0; j < MAX; j++)				//start from the first column and go trought the last one
		{	
			if (max < arr[i][j])				//check whether the coming value is greater than our premised max value
				max = arr[i][j];				//if so assign the new max value
		}
	return max;									//this function returns an integer value (the max value)
}

int main(void) {
	FILE *input = fopen("num.txt", "r");		//open the file to be able to read the numbers into the matrix
	int matrix[MAX][MAX], diagonal[MAX], i, j;

	if (input == NULL)				//if the file can not be opened
		printf("File can not be opened");	//give a warning message
	else					//if the file is opened
	{
		for (i = 0; i<MAX; i++)			//get the numbers to the matrix in rowwise from the num.txt
			for (j = 0; j<MAX; j++)
				fscanf(input, "%d", &matrix[i][j]);

		printf("\nMatrix is\n");			//display the matrix
		disp_two(matrix, MAX);			//by calling the disp_two function

		for (i = 0; i<MAX; i++)				//find the diagonal of the matrix
			diagonal[i] = matrix[i][i];

		printf("\nDiagonal is\n");
		disp_one(diagonal, MAX);			//display the diagonal by calling the disp_one function
		printf("\n");
		printf("\nThe maximum number of the array is %d ", findMax(matrix, MAX));		//display the maximum number by calling the findMax function
		printf("\n");
		printf("\nProduct is %d ", product(diagonal, MAX));		//display the product of the diagonal by calling the product function
		printf("\n");
	}
	return(0);
}