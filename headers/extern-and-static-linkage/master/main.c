/* LINKAGE ACROSS FILES: EXTERN SHARES A GLOBAL VARIABLE, STATIC HIDES ONE INSIDE ITS FILE
 * MAIN.C AND SECOND.C SHARE THE SAME V1; THIRD.C HAS A PRIVATE V1 OF ITS OWN */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int v1; /* GLOBAL WITH EXTERNAL LINKAGE: OTHER FILES MAY USE IT */

int main(void)
{
	v1 = 1;
	printf("main: v1 = %d\n", v1);
	f1();
	printf("main: v1 = %d (third.c changed only its own v1)\n", v1);

	return 0;
}

void f1(void)
{
	v1 = 2;
	printf("f1:   v1 = %d\n", v1);
	f2(); /* DEFINED IN SECOND.C */
}
