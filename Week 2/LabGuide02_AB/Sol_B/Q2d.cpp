#include <stdio.h>
#include <stdlib.h>
//CENG104 LG02 - Author: Evren
typedef struct{
	char movieName[50];
	double imdbScore;
} movie_t;

int main()
{
	FILE *fp = fopen("movies.txt", "r");
	movie_t *movies;
	int count;

	if (fp == NULL)
		printf("The file movies.txt couldn't be opened.\n");
	else
	{
		fscanf(fp, "%d", &count);

		movies = (movie_t *)malloc(count * sizeof(movie_t));

		printf("There are %d movies\n\n", count);

		for (int i = 0; i < count; i++)
			fscanf(fp, "%lf %[^\n]", &(movies + i)->imdbScore, &(movies + i)->movieName);

		printf("The Movies Information:\n");
		for (int i = 0; i < count; i++)
			printf("***********************\nMovie Name : %s\nMovie's IMDB Score is : %0.1f\n", (movies + i)->movieName, (movies + i)->imdbScore);

		fclose(fp);
	}

	return 0;
}