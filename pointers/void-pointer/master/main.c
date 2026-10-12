/* VOID POINTERS: THEY CAN HOLD ANY ADDRESS, BUT MUST BE CAST BEFORE READING THROUGH THEM */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

void print_value(void *p, char type) /* TYPE TELLS WHAT IS STORED AT P */
{
	if (type == 'i')
	{
		printf("int: %d\n", *(int *)p); /* CAST FIRST, THEN READ */
	}
	else if (type == 'd')
	{
		printf("double: %.2f\n", *(double *)p);
	}
	else if (type == 'c')
	{
		printf("char: %c\n", *(char *)p);
	}
}

int main(void)
{
	int n = 42;
	double d = 3.5;
	char c = 'Z';

	print_value(&n, 'i'); /* ANY ADDRESS CONVERTS TO VOID * BY ITSELF */
	print_value(&d, 'd');
	print_value(&c, 'c');

	return 0;
}
