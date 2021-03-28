#include<stdio.h>
#include<string.h>
#include"queue_int.h"


// 3 elemaný siliyo...KADIRKORKAZ


void display_q(queue_t q)
{
	while (!is_empty_q(&q))
		printf("%5d\n",remove(&q));
	printf("\n");
}
void del_nth_ele(queue_t *depo, int n)
{
	queue_t temp;
	initialize_q(&temp);
	int cntr = 1;
	while (cntr<n)
	{
		insert(&temp,remove(depo));
		cntr++;
	}
	remove(depo);
	while (!is_empty_q(depo))
	{
		insert(&temp,remove(depo));
	}
	*depo=temp;
}
int main()
{
	queue_t depo;
	initialize_q(&depo);
	insert(&depo, 12); insert(&depo, 63); insert(&depo, 42); insert(&depo, 51); insert(&depo, 27);
	display_q(depo);
	del_nth_ele(&depo,4);
	display_q(depo);
}
