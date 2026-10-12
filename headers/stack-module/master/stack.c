/* STACK.C: THE IMPLEMENTATION; STATIC KEEPS THE ARRAY AND THE COUNTER PRIVATE TO THIS FILE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

static int data[STACK_SIZE]; /* NO OTHER FILE CAN SEE THESE TWO */
static int top = 0;          /* HOW MANY VALUES ARE STORED */

void push(int value)
{
	if (top < STACK_SIZE)
	{
		data[top] = value;
		top++;
	}
}

int pop(void)
{
	if (top > 0)
	{
		top--;
		return data[top];
	}
	return 0; /* EMPTY STACK */
}

int is_empty(void)
{
	return top == 0;
}

int is_full(void)
{
	return top == STACK_SIZE;
}
