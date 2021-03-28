#include <stdio.h>
#include <string.h>
#include "stack_int.h"
// Author: Evren
#define	ARRSIZE	6

void display_stack(stack_t s)
{
	while (!is_empty_s(&s))
	{
		printf("%d\n", pop(&s));
	}

}

int main()
{
	stack_t	stack;
	initialize_s(&stack);


	int	 a, b, number;

	for (int i = 0; i<ARRSIZE; i++)
	{
		printf("\nEnter an integer: ");
		scanf("%d", &number);
		push(&stack, number);
	}

	printf("\nBEFORE SWAP:\n");
	display_stack(stack);

	a = pop(&stack);
	b = pop(&stack);

	push(&stack, a);
	push(&stack, b);

	printf("\n\n\nAFTER SWAP:\n");
	display_stack(stack);

	printf("\n\n\n");

	return 0;
}
