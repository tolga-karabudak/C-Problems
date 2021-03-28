#include<stdio.h>
#include<string.h>
#include<malloc.h>
//CENG104 Author: Evren
#define SIZE 15

typedef struct
{
	char word[SIZE];
	int length;
}word_t;

word_t *simplEncrypt(word_t *wrd, int size);

int main()
{
	int num_word, asci, j, i;
	word_t *wrd, *encrypted;

	printf("Enter the number of words:");
	scanf("%d", &num_word);

	wrd = (word_t *)malloc(num_word * sizeof(word_t));

	for (i = 0; i < num_word; i++)
	{
		printf("Enter the %d. word : ", i + 1);
		scanf("%s", (wrd + i)->word);
	}

	encrypted = simplEncrypt(wrd, num_word);

	for (i = 0; i < num_word; i++)
		printf("The encrypted form of the %d. word is %s.\n", i + 1, encrypted[i].word);

	return 0;
}

word_t * simplEncrypt(word_t * wrd, int size)
{
	word_t *encrpyted;
	int len, j;

	encrpyted = (word_t *)malloc(sizeof(word_t) * size);

	for (int i = 0; i < size; i++)
	{
		len = strlen(wrd[i].word);

		for (j = 0; j < len; j++)
			(encrpyted + i)->word[j] = wrd[i].word[j] + len;
		(encrpyted + i)->word[j] = '\0';
	}

	return encrpyted;
}
