/* TYPEDEF: A NEW NAME FOR AN EXISTING TYPE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

typedef unsigned char Byte; /* BYTE MEANS UNSIGNED CHAR */
typedef int Coord;          /* COORD MEANS INT */
typedef char *String;       /* STRING MEANS POINTER TO CHAR */

typedef struct
{
	Coord x;
	Coord y;
} Point; /* NO NEED TO WRITE STRUCT EVERY TIME */

int main(void)
{
	Byte mask = 0xF0;
	String city = "Timisoara";
	Point p = {3, 7};

	printf("mask = %d, city = %s\n", mask, city);
	printf("point = (%d, %d)\n", p.x, p.y);
	printf("sizeof(Coord) = %zu, same as sizeof(int) = %zu\n", sizeof(Coord), sizeof(int));

	return 0;
}
