/* #UNDEF: FORGET A MACRO; AFTER THAT IT CAN BE DEFINED AGAIN WITH ANOTHER VALUE */
#include <stdio.h> /* PRINTF */

#define SIZE 10
int first[SIZE]; /* 10 ELEMENTS */

#undef SIZE     /* FROM HERE ON, SIZE IS UNKNOWN */
#define SIZE 20 /* NOW IT CAN GET A NEW VALUE */
int second[SIZE]; /* 20 ELEMENTS */

int main(void)
{
	printf("first has %zu elements\n", sizeof(first) / sizeof(first[0]));
	printf("second has %zu elements\n", sizeof(second) / sizeof(second[0]));
	printf("SIZE is now %d\n", SIZE);

#undef SIZE
#ifndef SIZE
	printf("After the second #undef, SIZE is not defined any more\n");
#endif

	return 0;
}
