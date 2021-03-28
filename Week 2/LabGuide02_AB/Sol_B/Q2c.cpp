#include <stdio.h>
//CENG104 LG02 - Author: Evren
typedef struct{
	char movieName[50];
	double imdbScore;
} movie_t;

int main(void)
{
	movie_t	movie = { "The Lord of The Rings: The Fellowship of The Ring", 8.8 };

	movie_t *ptr = &movie;

	printf("The movie information is:\n");
	printf("Movie name: %s\n", ptr->movieName);
	printf("Movie's IMDB Score: %0.1f\n", ptr->imdbScore);

	return(0);
}