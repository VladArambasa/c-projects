/* CULEGERE I.13 - METERS TO CENTIMETERS
 * READ A LENGTH GIVEN IN METERS AND PRINT IT IN CENTIMETERS
 * EXAMPLE: 72 -> 7200 CM */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int meters = 0;

	printf("Meters: ");
	scanf("%d", &meters);

	printf("%d cm\n", meters * 100); /* 1 M = 100 CM */

	return 0;
}
