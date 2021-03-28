#include <stdio.h>
#define SIZE 10
/*CENG104 Lab1-B Question2
Author: Evren*/
int
main(void)
{
	FILE	*outp;	// File pointer

	int	i,			// loop control variable
		nums[SIZE];	// keeps 10 numbers

	for (i = 0; i<SIZE; i++)
		*(nums + i) = (i + 1) * 10;


	outp = fopen("result.txt", "w");

	if (outp == NULL)
		printf("\n The file could not be created");
	else
	{

		fprintf(outp, "Element Name  Value  Address\n");
		fprintf(outp, "------------  -----  --------\n");

		for (i = 0; i<SIZE; i++)
			fprintf(outp, "*(nums +%2d)   %5d  %p\n", i, *(nums + i), nums + i);

		fclose(outp);

		printf("\n !!! Process Completed. Please examine the result.txt file\n\n");
	}


	return(0);
}
