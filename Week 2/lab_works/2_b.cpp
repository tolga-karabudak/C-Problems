#include<stdio.h>

typedef struct{
	char *movieName;
	double imdbScore;
}movie_t;


int main()
{
	movie_t movie;
	printf("Please enter The movie information: \n");
	gets(movie.movieName);
	scanf("%lf",&movie.imdbScore);
	printf("The movie name: %s\n",movie.movieName);
	printf("Movies IMDB score is: %.1lf",movie.imdbScore);
	
	
	
	
	
	
}
