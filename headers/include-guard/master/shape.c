/* SHAPE.C: RECTANGLE FUNCTIONS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int rect_area(struct rect r)
{
	int width = r.bottom_right.x - r.top_left.x;
	int height = r.top_left.y - r.bottom_right.y;

	return width * height;
}
