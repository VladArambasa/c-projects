/* MATHUTILS.C: THE IMPLEMENTATION, THE BODIES OF THE FUNCTIONS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int square(int x)
{
	return x * x;
}

int cube(int x)
{
	return x * x * x;
}

int is_even(int x)
{
	return x % 2 == 0; /* 1 OR 0 */
}

int maximum(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}
