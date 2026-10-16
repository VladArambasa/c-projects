/* CULEGERE IX.3.1 - A STACK OF LETTERS
 * SHOW THE EFFECT OF THESE OPERATIONS ON A STACK THAT IS EMPTY AT FIRST: PUSH R, PUSH A, PUSH M,
 * PUSH A, POP, POP, PUSH V (THE STACK IS PRINTED FROM THE BOTTOM TO THE TOP AFTER EVERY OPERATION)
 * EXAMPLE: (NO INPUT) -> R / R A / R A M / R A M A / R A M / R A / R A V
 * THE STACK IS ALLOCATED STATICALLY: AN ARRAY AND THE NUMBER OF LETTERS IN IT */
#include <stdio.h> /* PRINTF */

#define MAX 10 /* ROOM FOR 10 LETTERS */

char stack[MAX]; /* STACK[0] IS THE BOTTOM */
int top = 0;     /* HOW MANY LETTERS ARE IN THE STACK */

/* PRINTS THE STACK FROM THE BOTTOM TO THE TOP */
void print_stack(void)
{
	int i;

	printf("stack:");
	for (i = 0; i < top; i++)
	{
		printf(" %c", stack[i]);
	}
	printf("\n");
}

/* THE NEW LETTER IS PLACED ON THE TOP */
void push(char letter)
{
	stack[top] = letter;
	top++;
	printf("push %c -> ", letter);
	print_stack();
}

/* ONLY THE LETTER ON THE TOP CAN BE TAKEN OUT */
void pop(void)
{
	top--;
	printf("pop %c  -> ", stack[top]);
	print_stack();
}

int main(void)
{
	push('R');
	push('A');
	push('M');
	push('A');
	pop();
	pop();
	push('V');

	return 0;
}
