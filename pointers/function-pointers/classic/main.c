/* POINTERS TO FUNCTIONS: A FUNCTION NAME IS THE ADDRESS OF ITS CODE */
#include <stdio.h>  /* PRINTF */
#include <stdlib.h> /* ATOI */

int add(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

int main(void)
{
	int (*op)(int, int); /* POINTER TO A FUNCTION THAT TAKES TWO INTS AND RETURNS AN INT */
	int (*table[3])(int, int) = {add, subtract, multiply}; /* ARRAY OF FUNCTION POINTERS */
	char *names[3] = {"add", "subtract", "multiply"};
	int (*convert)(const char *) = atoi; /* LIBRARY FUNCTIONS HAVE ADDRESSES TOO */
	int i;

	op = add;
	printf("op = add:      op(6, 3) = %d\n", op(6, 3));
	op = multiply;
	printf("op = multiply: (*op)(6, 3) = %d\n", (*op)(6, 3)); /* BOTH CALL SYNTAXES WORK */

	for (i = 0; i < 3; i++)
	{
		printf("%s(6, 3) = %d\n", names[i], table[i](6, 3));
	}

	printf("convert(\"2212\") + 1 = %d\n", convert("2212") + 1);

	return 0;
}
