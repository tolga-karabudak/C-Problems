#include<stdio.h>
#include<string.h>
#define MAX 100



void replace(char *str, // The given string
char c1, char c2) { // The characters
int i;
for (i = 0; i < strlen(str); i++)
if (str[i] == c1)
str[i] = c2;
}

/*int main(void) {
char sent[20], ch1, ch2;
// Get the sentence and the characters
printf("Enter a sentence: ");
scanf("%[^\n]", sent); // gets(sent);
printf("Enter the character to replace: ");
scanf(" %c", &ch1);
printf("Replace with: ");
scanf(" %c", &ch2);
// Make replacements and display the new sentence
replace(sent, ch1, ch2);
printf("\nThe new sentence: %s\n", sent);
return (0);
}*/
void reverse(char *str) {
char rev[MAX];
int i, k = 0;
int len = strlen(str);
for (i = len-1; i >= 0; i--) {
*(rev+k) = *(str+i);
k++;
}
*(rev+k) = '\0';
// Copy the result into the given string
strcpy(str, rev);
}


int main(void) {
char *s1 = "abc def";
char *s2 = "abc def";
char *s3 = "abc degww";
printf("%3d%3d%3d\n", strcmp(s1, s2), strcmp(s1, s3),
strcmp(s3, s2));
printf("%3d%3d%3d\n", strncmp(s1, s3, 5), strncmp(s3, s1, 7),
strncmp(s2, s3, 9));
}
