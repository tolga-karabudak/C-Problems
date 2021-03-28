#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include"queue_int.h"
#include<stdlib.h>


// kuyrukta ki butun 2 leri siliyor..

void display_q(queue_t depo)
{
	while (!is_empty_q(&depo))
	{
		printf("%5d", remove(&depo));
	}
	printf("\n");
}
void removes_all_occurrences(queue_t *depo, QType item)
{
	queue_t temp;
	initialize_q(&temp);
	int num;
	while (!is_empty_q(depo))
	{
		num = remove(depo);
		if (num != item)
			insert(&temp, num);
		
	}
	initialize_q(depo);
	*depo = temp;

}
int main()
{
	queue_t depo;
	initialize_q(&depo);
	insert(&depo, 1);insert(&depo, 2);insert(&depo, 3);insert(&depo, 4);insert(&depo, 2);insert(&depo, 4);insert(&depo, 6);insert(&depo, 2);
	display_q(depo);
	removes_all_occurrences(&depo, 2);
	display_q(depo);
	int a;
	scanf("%d", &a);
	printf("%d", a);
	system("pause");
	return 0;
	
}
