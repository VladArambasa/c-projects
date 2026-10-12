/* GEOMETRY.C: THE GEOMETRY FUNCTIONS */
#include <math.h>     /* SQRT */
#include "geometry.h" /* OWN PROTOTYPES AND POINT */

double distance(Point a, Point b)
{
	double dx = b.x - a.x;
	double dy = b.y - a.y;

	return sqrt(dx * dx + dy * dy); /* PYTHAGORAS */
}

Point midpoint(Point a, Point b)
{
	Point m;

	m.x = (a.x + b.x) / 2;
	m.y = (a.y + b.y) / 2;
	return m; /* A STRUCTURE CAN BE RETURNED LIKE ANY VALUE */
}
