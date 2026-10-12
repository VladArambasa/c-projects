/* SHAPE.H: A RECTANGLE IS MADE OF TWO POINTS, SO THIS HEADER NEEDS POINT.H */
#ifndef SHAPE_H
#define SHAPE_H

#include "point.h" /* STRUCT POINT (SECOND INCLUDE WHEN MAIN.C ALREADY HAS IT) */

struct rect
{
	struct point top_left;
	struct point bottom_right;
};

int rect_area(struct rect r);

#endif /* SHAPE_H */
