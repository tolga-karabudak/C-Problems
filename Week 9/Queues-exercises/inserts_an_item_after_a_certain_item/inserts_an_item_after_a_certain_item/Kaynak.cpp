#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"queue_int.h"

void display(queue_t depo)
{
	while (!is_empty_q(&depo))
	{
		printf("%5d", remove(&depo));
	}
	printf("\n");

}

void inserts_an_item_after_a_certain_item(queue_t *depo, QType item_add, QType item_after)
{
	queue_t temp;
	initialize_q(&temp);
	int num;
		while (!is_empty_q(depo))
		{
			num = remove(depo);
			insert(&temp, num);
			if (num == item_after)
				insert(&temp, item_add);
		}
		initialize_q(depo);
		*depo = temp;

}

int main()
{
	queue_t depo;
	initialize_q(&depo);
	int i = 0;
	while (i<10)
	{
		insert(&depo, i);
		i++;
	}
	display(depo);
	inserts_an_item_after_a_certain_item(&depo, 15, 7);
	display(depo);

	system("pause");
}