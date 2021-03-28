#include<stdio.h>
#include <stdlib.h>
/* CENG104 LG5 
Author: Evren*/
#define MIN 5
#define MAX 2000

int main()
{
	FILE *bfp;
	int	k = 0;

	//write the 500 integers to the file
	bfp = fopen("numbers.bin", "wb");

	for (int i = MIN; i <= MAX; i += 5)
		fwrite(&i, sizeof(int), 1, bfp);

	//close the written file
	fclose(bfp);

	//reopen the written file for reading
	bfp = fopen("numbers.bin", "rb");
	if (bfp == NULL)
		printf("File could NOT be opened!\n");
	else
	{
		int n, *nums;

		printf("How many numbers do you want to read: ");
		scanf("%d", &n);

		while (n < 0 || n > MAX)
		{
			printf("Enter a number between 1 and 500!\n");
			printf("How many numbers do you want to read: ");
			scanf("%d", &n);
		}

		//allocate n size space for the storage of numbers read from the file
		nums = (int *)malloc(n * sizeof(int));

		//read nums until end of file or until n to the array
		while (!feof(bfp) && k < n)
		{
			fread(&nums[k], sizeof(int), 1, bfp);
			k++;
		}

		//close the file
		fclose(bfp);

		//display the array
		for (int i = 0; i < n; i++)
			printf("%5d", nums[i]);

		printf("\n");
	}


	return 0;
}