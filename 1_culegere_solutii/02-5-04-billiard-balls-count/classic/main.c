/* CULEGERE II.5.4 - BILLIARD BALLS
 * A BILLIARD TABLE HAS WHITE, RED AND GREEN BALLS, EACH COLOR IN TWO SIZES: SMALL AND LARGE.
 * READ THE 6 COUNTS; PRINT THE TOTAL, WHICH SIZE HAS MORE BALLS (AND HOW MANY) AND WHICH
 * COLOR HAS THE MOST BALLS (AND HOW MANY)
 * EXAMPLE: 2 3 1 4 3 4 -> TOTAL BALLS: 17, LARGE: 11 BALLS, GREEN: 7 BALLS
 * ASSUMPTION: IF THERE ARE AS MANY SMALL BALLS AS LARGE ONES, THE PROGRAM SAYS SO
 * ASSUMPTION: IF TWO COLORS TIE, THE FIRST ONE IN THE ORDER WHITE, RED, GREEN IS PRINTED */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int white_small = 0, white_large = 0, red_small = 0, red_large = 0;
	int green_small = 0, green_large = 0;
	int small, large, white, red, green;

	printf("White small balls: ");
	scanf("%d", &white_small);
	printf("White large balls: ");
	scanf("%d", &white_large);
	printf("Red small balls: ");
	scanf("%d", &red_small);
	printf("Red large balls: ");
	scanf("%d", &red_large);
	printf("Green small balls: ");
	scanf("%d", &green_small);
	printf("Green large balls: ");
	scanf("%d", &green_large);

	/* GROUP THE BALLS BY SIZE AND BY COLOR */
	small = white_small + red_small + green_small;
	large = white_large + red_large + green_large;
	white = white_small + white_large;
	red = red_small + red_large;
	green = green_small + green_large;

	printf("Total balls: %d\n", small + large);

	if (large > small)
	{
		printf("Large: %d balls\n", large);
	}
	else if (small > large)
	{
		printf("Small: %d balls\n", small);
	}
	else
	{
		printf("Small and large: %d balls each\n", small);
	}

	/* THE COLOR WITH THE MOST BALLS HAS AT LEAST AS MANY AS EACH OF THE OTHER TWO */
	if (white >= red && white >= green)
	{
		printf("White: %d balls\n", white);
	}
	else if (red >= white && red >= green)
	{
		printf("Red: %d balls\n", red);
	}
	else
	{
		printf("Green: %d balls\n", green);
	}

	return 0;
}
