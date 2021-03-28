#include <stdio.h>
//CENG104 LG02 - Author: Evren
typedef struct{
	char movieName[50];
	double imdbScore;
} movie_t;

int main()
{
	movie_t movie;

	printf("Please enter the information of the movie: \nEnter Movie Name: ");
	gets(movie.movieName);
	printf("Enter Movie’s IMDB Score: ");
	scanf("%lf", &movie.imdbScore);

	printf("\nThe movie information is:\n");
	printf("Movie name: %s\n", movie.movieName);
	printf("Movie's IMDB Score: %0.1f\n", movie.imdbScore);

	return 0;
}