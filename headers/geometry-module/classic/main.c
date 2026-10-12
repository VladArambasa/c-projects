/* GEOMETRY MODULE: A HEADER THAT NEEDS ANOTHER HEADER (GEOMETRY.H USES THE POINT TYPE) */
#include <stdio.h>    /* PRINTF, SCANF */
#include "geometry.h" /* DISTANCE, MIDPOINT */

int main(void)
{
	Point a, b, m;

	printf("First point (x y): ");
	scanf("%lf %lf", &a.x, &a.y);
	printf("Second point (x y): ");
	scanf("%lf %lf", &b.x, &b.y);

	m = midpoint(a, b);
	printf("Distance = %.2f\n", distance(a, b));
	printf("Midpoint = (%.2f, %.2f)\n", m.x, m.y);

	return 0;
}
