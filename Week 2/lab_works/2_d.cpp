#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char movieName[25];
	double imdbScore;
}movie_t;


int main()
{
	movie_t *mv;
	FILE* inp;
	inp=fopen("movies.txt","r");
	int filmsayisi;
	fscanf(inp,"%d",&filmsayisi);
	mv=(movie_t *)malloc(filmsayisi*sizeof(movie_t));
	
	for(int i=0;i<filmsayisi;i++)
	{
		fscanf(inp,"%lf",&mv[i].imdbScore);
		fscanf(inp,"%[^\n]",&mv[i].movieName);
		
	}
	fclose(inp);
		printf("There ara %d movies\n",filmsayisi);
		for(int i=0;i<filmsayisi;i++)
		{
			printf("Movie name: %s\nMovies IMDB score: %.1lf\n*************\n",mv[i].movieName,mv[i].imdbScore);
		}
		
	
//	printf("size of  struct : %d",sizeof(movie_t));
//	double arr[10];
//	int table[2][4];	
//	printf("Size of *arr = %d \n", sizeof *(arr+0));
//	printf("Size of table[0] = %d \n", sizeof table[0]); 
//	printf("Size of *table = %d \n", sizeof *table); 
//	printf("Size of **table = %d \n", sizeof **table);
	
	
	
}
