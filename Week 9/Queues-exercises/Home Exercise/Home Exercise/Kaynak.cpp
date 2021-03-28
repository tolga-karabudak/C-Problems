#define _CRT_SECURE_NO_WARNINGS_
#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"queue_int.h"

int menu()
{
	printf("1) Print Queue\n2) Clear Queue\n3)Count Queue\n4) Remove Maximum Element\n5) Send Nth To End\n6) Exit\n");
	int choice;
	printf("Enter your choice: ");
	scanf("%d", &choice);
	return choice;
}

void display_q(queue_t depo)
{
	while (!is_empty_q(&depo))
	{
		printf("%d\t", remove(&depo));
	}
	printf("\n");
}
void clearQueue(queue_t *depo)
{
	initialize_q(depo);
	if (is_empty_q(depo))
		printf("The queue is empty!!\n");
}
void remMaxQueue(queue_t *depo)
{
	queue_t temp;
	initialize_q(&temp);
	int max = remove(depo);
	int num;
	insert(&temp, max);
	while (!is_empty_q(depo))
	{
		num = remove(depo);
		if (num > max)
		{
			max = num;
		}
		insert(&temp, num);

	}
	while (!is_empty_q(&temp))
	{

		num = remove(&temp);
		if (num != max)
		{
			insert(depo, num);
		}
	}
}
void sendNthToEnd(queue_t *depo, int n)
{
	queue_t temp;
	initialize_q(&temp);
		int cntr = 1;
	while (cntr<n)
	{
		insert(&temp, remove(depo));
		cntr++;
	}
	int last = remove(depo);
	while (!is_empty_q(depo))
	{
		insert(&temp, remove(depo));
	}
	insert(&temp, last);
	*depo = temp;

}


int main()
{
	queue_t depo;
	initialize_q(&depo);
	printf("Enter the numbers for the queue (-9 to stop):\n");
	int num;
	scanf("%d", &num);
	if (num == -9)
		return 0;
	else
	{
		while (num != -9)
		{
			insert(&depo, num);
			scanf("%d", &num);
		}
		int choice = menu();

		while (choice!=6)
		{
			if (choice == 1)
			{
				display_q(depo);
				choice = menu();
			}
			else if (choice==2)
			{
				clearQueue(&depo);
				choice = menu();
			}
			else if (choice==3)
			{
				printf("Number of elements in the queue: %d\n", depo.counter);
				choice = menu();
			}
			else if (choice == 4)
			{
				remMaxQueue(&depo);
				choice = menu();
			}
			else if (choice == 5)
			{
				printf("Enter N: ");
				int n;
				scanf("%d", &n);
				if (n<1 || n>depo.counter)
				{
					printf("N must be between 1 and %d", depo.counter);
					choice = menu();
				}
				else
					sendNthToEnd(&depo, n);
				choice = menu();
			}
		}

	}
	system("pause");
}