#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	
	char article[5][10]={"the ","a ","one ","some ","any "},
	noun[5][10]={"bicycle","bird","dog","bus","car"},
	verb[5][10]={" drove "," jumped "," ran "," walked "," flew "},
	preposition[5][10]={" to "," from "," over "," under "," on "};
	int random; 
	srand(time(0));	
	
	for(int i=0;i<5;i++)
	{ 	
		printf("Sentence %d: ",i+1);
		random=rand()%5;
		printf("%s",article[random]);
		random=rand()%5;
		printf("%s",noun[random]);
		random=rand()%5;
		printf("%s",verb[random]);
		random=rand()%5;
		printf("%s",preposition[random]);
		random=rand()%5;
		printf("%s",article[random]);
		random=rand()%5;
		printf("%s",noun[random]);
		printf(".\n");
	}
	
}
