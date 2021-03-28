#include<stdio.h>

typedef struct{
	char *movieName;
	double imdbScore;
}movie_t;


int main()
{
	movie_t movie;
	movie.movieName="The Hitchhiker s Guide to the galaxy";
	movie.imdbScore=7.2;
	printf("The movie information: \n");
	printf("The movie name: %s\n",movie.movieName);
	printf("Movies IMDB score is: %.1lf",movie.imdbScore);
	
	
	
	
	
	
}
