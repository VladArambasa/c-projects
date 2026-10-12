/* CONST AND POINTERS: A POINTER TO CONST PROTECTS THE VALUE, A CONST POINTER PROTECTS THE ADDRESS */
#include <stdio.h> /* PRINTF */

void print_name(const char *name) /* CONST: THE FUNCTION PROMISES NOT TO CHANGE THE TEXT */
{
	printf("Name: %s\n", name);
}

int main(void)
{
	int a = 10, b = 20;
	const int *p1 = &a; /* POINTER TO CONST: THE VALUE CANNOT BE CHANGED THROUGH P1 */
	int *const p2 = &a; /* CONST POINTER: P2 HOLDS &A AND CAN NEVER POINT ELSEWHERE */

	/* *P1 = 5;  WOULD NOT COMPILE: READ ONLY THROUGH P1 */
	p1 = &b; /* ALLOWED: P1 ITSELF CAN MOVE */
	printf("*p1 = %d\n", *p1);

	*p2 = 15; /* ALLOWED: THE VALUE CAN CHANGE */
	/* P2 = &B;  WOULD NOT COMPILE: P2 IS CONST */
	printf("a = %d\n", a);

	print_name("Ana");

	return 0;
}
