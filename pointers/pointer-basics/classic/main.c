/* POINTERS: A POINTER IS A VARIABLE THAT HOLDS THE ADDRESS OF ANOTHER VARIABLE */
#include <stdio.h> /* PRINTF */

int main(void)
{
	int age = 43;
	int *ptr = &age; /* PTR POINTS TO AGE; THE TYPES MUST MATCH (INT * FOR AN INT) */

	printf("age   = %d\n", age);
	printf("&age  = %p\n", (void *)&age);
	printf("ptr   = %p (the same address)\n", (void *)ptr);
	printf("*ptr  = %d (the value at that address)\n", *ptr); /* * READS THROUGH THE POINTER */

	*ptr = 44; /* WRITE THROUGH THE POINTER: AGE CHANGES */
	printf("after *ptr = 44, age = %d\n", age);

	return 0;
}
