/* CULEGERE I.5 - CHRISTMAS TREE BAUBLES
 * A TREE HAS WHITE, RED AND BLUE BAUBLES. THE NUMBER OF WHITE ONES IS READ; THERE ARE 3 MORE
 * RED ONES THAN WHITE ONES AND 2 FEWER BLUE ONES THAN WHITE AND RED TOGETHER. PRINT THE TOTAL
 * EXAMPLE: 12 -> 52 BAUBLES */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int white = 0, red, blue;

	printf("Number of white baubles: ");
	scanf("%d", &white);

	red = white + 3; /* 3 MORE THAN THE WHITE ONES */
	blue = white + red - 2; /* 2 FEWER THAN WHITE AND RED TOGETHER */

	printf("%d baubles\n", white + red + blue);

	return 0;
}
