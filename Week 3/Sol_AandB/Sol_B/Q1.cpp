# include <stdio.h>
# include <string.h>
# define SIZE 80
//CENG104 Author: Evren
int main(void)
{
	char sent[SIZE];

	printf("\n Enter a sentence: ");
	//scanf("%s", sent);
	//scanf("%[^\n]", sent);
	scanf("%[^0-9]", sent);

	printf("\nThe sentence is: %s\n", sent);

	return(0);
}
