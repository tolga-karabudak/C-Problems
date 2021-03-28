#include <stdio.h>
#define NL '\n'
#define BLANK ' '
#define NO 0
#define YES 1
int main(void) {
int nc = 0, // (output) no. of chars
nw = 0; // (output) no. of words
char ch; // (input) a character of the line
int flag; /* to test whether we are currently in a word
or not */
flag = NO; // not in the word
printf("Type in a line of data:\n");
ch = getchar(); // gets char from the standard input stream
// Repeat until the end of the line
while (ch != NL) {
nc++; // increment number of characters
if (ch == BLANK) // Skip all the blanks
flag = NO;
else if (flag == NO) { // If it is the first letter of
flag = YES; // a word in the word
nw++; // increment number of words
}
ch = getchar(); // Get the next character
}
// Display number of characters and words
printf("Characters: %d\nWords: %d\n", nc, nw);
return (0);
}
