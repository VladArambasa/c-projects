/* SECOND.C: USES THE V1 DEFINED IN MAIN.C */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

extern int v1; /* ONLY A DECLARATION: THE VARIABLE ITSELF LIVES IN MAIN.C */

void f2(void)
{
	v1 = 3; /* CHANGES MAIN.C'S V1 */
	printf("f2:   v1 = %d\n", v1);
	f3(); /* DEFINED IN THIRD.C */
}
