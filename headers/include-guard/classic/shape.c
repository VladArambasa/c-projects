/* SHAPE.C: RECTANGLE FUNCTIONS */
#include "shape.h" /* STRUCT RECT, RECT_AREA */

int rect_area(struct rect r)
{
	int width = r.bottom_right.x - r.top_left.x;
	int height = r.top_left.y - r.bottom_right.y;

	return width * height;
}
