# include <stdio.h>

# define SIZE 80

int main(void)
{
	char sent[SIZE];

	printf("Enter a sentence: ");
	//scanf("%s", sent);
	//scanf("%[^\n]", sent);
	scanf("%[^0-9]", sent);

	printf("\nThe sentence is: %s\n", sent);

	return(0);
}
