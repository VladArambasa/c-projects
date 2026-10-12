/* POINTERS TO STRUCTURES: P->MEMBER IS SHORT FOR (*P).MEMBER */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

struct point
{
	int x;
	int y;
};

void move(struct point *p, int dx, int dy) /* GETS THE ADDRESS, SO IT CHANGES THE ORIGINAL */
{
	p->x = p->x + dx;
	p->y = p->y + dy;
}

int main(void)
{
	struct point a = {1, 2};
	struct point *p = &a;

	printf("(*p).x = %d, p->x = %d\n", (*p).x, p->x); /* THE SAME MEMBER */

	move(&a, 3, 4);
	printf("after move: a = (%d, %d)\n", a.x, a.y);

	return 0;
}
