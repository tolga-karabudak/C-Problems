#include<stdio.h>
typedef struct{
	int hour,min,sec;
}time;

void get_time(time*t)
{
	scanf("%d %d %d",&t->hour,&t->min,&t->sec);
}
void displayTime(time*t)
{
	printf("%1.2d:%0.2d:%0.2d",t->hour,t->min,t->sec);
}
void newTime(time *t,int *dsec)
{
	int temp;
	temp=t->sec+*dsec;
	t->sec=temp%60;
	temp=temp/60+t->min;
	t->min=temp%60;
	temp=t->hour+temp/60;
	t->hour=temp%24;
	
	
}

int main()
{
	time t;
	int duration;
	printf("Enter a time (as hours minutes seconds): ");
	get_time(&t);
	printf("Enter the duration in seconds:");
	scanf("%d",&duration);
	printf("The current time:          ");
	displayTime(&t);
	newTime(&t,&duration);
	printf("\nThe time after %d seconds:  ",duration);
	displayTime(&t);
	
}
