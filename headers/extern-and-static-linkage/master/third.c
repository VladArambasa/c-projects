/* THIRD.C: ITS STATIC V1 IS A DIFFERENT VARIABLE, INVISIBLE TO THE OTHER FILES */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

static int v1; /* INTERNAL LINKAGE: A SEPARATE V1 THAT ONLY THIS FILE SEES */

void f3(void)
{
	v1 = 10;
	printf("f3:   v1 = %d (the private one)\n", v1);
	f4();
}

void f4(void)
{
	v1 = v1 + 1;
	printf("f4:   v1 = %d (the private one)\n", v1);
}
