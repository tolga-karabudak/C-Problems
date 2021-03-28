#include <stdio.h>
//CENG104 LG02 - Author: Evren
typedef struct{
	char movieName[50];
	double imdbScore;
} movie_t;

int main()
{
	movie_t movie = { "The Lord of The Rings: The Fellowship of The Ring", 8.8 };

	printf("The movie information is:\n");
	printf("Movie name: %s\n", movie.movieName);
	printf("Movie's IMDB Score: %0.1f\n", movie.imdbScore);

	return 0;
}