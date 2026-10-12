/* UNIONS: ALL MEMBERS SHARE THE SAME MEMORY, ONLY ONE IS VALID AT A TIME */
#include <stdio.h> /* PRINTF */

union value
{
	int i;
	double d;
	char c;
};

int main(void)
{
	union value v;

	v.i = 12; /* NOW THE UNION HOLDS AN INT */
	printf("as int    : %d\n", v.i);

	v.d = 1.75; /* OVERWRITES THE SAME BYTES WITH A DOUBLE */
	printf("as double : %.2f\n", v.d);

	v.c = 'Z';
	printf("as char   : %c\n", v.c);

	printf("sizeof(union value) = %zu (the size of its biggest member)\n", sizeof(union value));

	return 0;
}
