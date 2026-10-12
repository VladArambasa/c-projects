/* INCLUDE GUARD: POINT.H GETS INCLUDED TWICE IN THIS PROJECT
 * WITHOUT ITS GUARD, STRUCT POINT IS DEFINED TWICE: A BUILD ERROR UP TO C17 (C23 ALLOWS AN IDENTICAL COPY) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	struct point p = {2, 3};
	struct rect r = {{0, 4}, {5, 0}}; /* TOP LEFT (0, 4), BOTTOM RIGHT (5, 0) */

	printf("p = (%d, %d)\n", p.x, p.y);
	printf("rectangle area = %d\n", rect_area(r));

	return 0;
}
