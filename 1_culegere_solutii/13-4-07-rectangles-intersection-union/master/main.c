/* CULEGERE XIII.4.7 - RECTANGLES: INTERSECTION AND UNION
 * N RECTANGLES HAVE THEIR SIDES PARALLEL TO THE AXES; EACH ONE IS GIVEN BY THE TWO ENDS OF A
 * DIAGONAL (NATURAL COORDINATES BELOW 100). PRINT THE AREA OF THE PART COMMON TO ALL THE
 * RECTANGLES, THE CORNERS OF THAT PART, AND THE PERIMETER OF THE FIGURE COVERED BY THE RECTANGLES
 * (THEIR UNION)
 * IDEA: THE COMMON PART IS A RECTANGLE: FROM THE LARGEST LEFT SIDE TO THE SMALLEST RIGHT SIDE AND
 * FROM THE LARGEST BOTTOM SIDE TO THE SMALLEST TOP SIDE. FOR THE UNION THE PLANE IS CUT INTO 1 X 1
 * SQUARES: EVERY SIDE BETWEEN A COVERED SQUARE AND AN UNCOVERED ONE IS PART OF THE PERIMETER
 * ASSUMPTION: THE BORDER OF A HOLE INSIDE THE UNION IS PART OF THE PERIMETER; IF THE COMMON PART
 * HAS NO AREA (THE RECTANGLES DO NOT MEET, OR ONLY TOUCH), NO CORNERS ARE PRINTED
 * EXAMPLE: 2 / 0 0 4 4 / 6 6 2 2 -> AREA 4, CORNERS (2,2) (4,2) (4,4) (2,4), PERIMETER 24 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAXC 100 /* COORDINATES FROM 0 TO 99 */

int covered[MAXC][MAXC]; /* COVERED[X][Y] = 1: THE SQUARE WITH THE LOWER LEFT CORNER (X, Y) */

/* MARKS AS COVERED THE 1 X 1 SQUARES OF THE RECTANGLE FROM (X1, Y1) TO (X2, Y2) */
void cover(int x1, int y1, int x2, int y2)
{
	int x, y;

	for (x = x1; x < x2; x++)
	{
		for (y = y1; y < y2; y++)
		{
			covered[x][y] = 1;
		}
	}
}

/* 1 IF THE SQUARE (X, Y) IS INSIDE THE TABLE AND COVERED */
int is_covered(int x, int y)
{
	if (x < 0 || y < 0 || x >= MAXC || y >= MAXC)
	{
		return 0;
	}
	return covered[x][y];
}

/* HOW MANY SIDES OF THE SQUARE (X, Y) HAVE NO COVERED SQUARE BEYOND THEM */
int free_sides(int x, int y)
{
	int sides = 4;

	sides = sides - is_covered(x - 1, y) - is_covered(x + 1, y); /* LEFT AND RIGHT */
	sides = sides - is_covered(x, y - 1) - is_covered(x, y + 1); /* BELOW AND ABOVE */
	return sides;
}

/* PERIMETER OF THE UNION: THE FREE SIDES OF ALL THE COVERED SQUARES */
int union_perimeter(void)
{
	int x, y, perimeter = 0;

	for (x = 0; x < MAXC; x++)
	{
		for (y = 0; y < MAXC; y++)
		{
			if (covered[x][y] == 1)
			{
				perimeter = perimeter + free_sides(x, y);
			}
		}
	}
	return perimeter;
}

int main(void)
{
	int n = 0, i, temp;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	/* THE SIDES OF THE COMMON PART, AT FIRST THE WHOLE TABLE */
	int left = 0, right = MAXC, bottom = 0, top = MAXC;

	printf("Number of rectangles: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("Rectangle %d (x1 y1 x2 y2): ", i);
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		/* PUT THE ENDS IN ORDER: (X1, Y1) LOWER LEFT, (X2, Y2) UPPER RIGHT */
		if (x1 > x2)
		{
			temp = x1;
			x1 = x2;
			x2 = temp;
		}
		if (y1 > y2)
		{
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
		cover(x1, y1, x2, y2);
		/* THE COMMON PART KEEPS ONLY WHAT THIS RECTANGLE COVERS TOO */
		if (x1 > left)
		{
			left = x1;
		}
		if (x2 < right)
		{
			right = x2;
		}
		if (y1 > bottom)
		{
			bottom = y1;
		}
		if (y2 < top)
		{
			top = y2;
		}
	}

	printf("\n");
	if (left < right && bottom < top)
	{
		printf("Intersection area: %d\n", (right - left) * (top - bottom));
		printf("Corners: (%d,%d) (%d,%d) (%d,%d) (%d,%d)\n",
			left, bottom, right, bottom, right, top, left, top);
	}
	else
	{
		printf("Intersection area: 0\n");
		printf("The rectangles have no common part\n");
	}
	printf("Union perimeter: %d\n", union_perimeter());

	return 0;
}
