/* SHAPE.H: A RECTANGLE IS MADE OF TWO POINTS, SO THIS HEADER NEEDS POINT.H */
#ifndef SHAPE_H
#define SHAPE_H

/* POINT.H COMES FROM MASTER.H, WHICH INCLUDES IT BEFORE THIS FILE */

struct rect
{
	struct point top_left;
	struct point bottom_right;
};

int rect_area(struct rect r);

#endif /* SHAPE_H */
