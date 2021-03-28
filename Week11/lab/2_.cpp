#include<stdio.h>
#include<string.h>
#include"queue_int.h"
void display(queue_t depo)
{
	int k=depo.counter;
	for (int i=0;i<k;i++)
		printf("%c",remove(&depo));
	printf("\n");
	
}

void menu()
{
	printf("*     Erase the first ch(remove it from the queue\n)");
	printf("+    Kill the entire line(empty the queue)\n");
	printf(":or!  Display the queue\n");
	printf("Enter Termimnate the string entry and display the queue content\n");
	printf("Enter charecters to be inserted to the queue(press enter to stop)\n");
	
	
}


int main()
{
	queue_t depo;
	initialize_q(&depo);
	menu();
	char c;

//	printf("%s",cumle);

	int i=0;
	scanf("%c",&c);
	while(c!='\n')
	{
		if(c!='*'&&c!='+'&&c!=':'&&c!='!'&&c!='\n')
			insert(&depo,c);
		else if(c=='*')
		{
			printf("The charecter <%c> is removed\n",remove(&depo));
			
		}
		else if(c=='+')
		{
			printf("All the charecters are removed\n");
			initialize_q(&depo);
			
		}
		else if(c==':'||c=='!')
		{
			printf("\n");
			display(depo);
		}
			
		scanf("%c",&c);
	}
		display(depo);
	
	
}
