/* CULEGERE I.8 - IDEAL WEIGHT AND HEIGHT
 * READ THE AGE V OF A CHILD AND PRINT THE IDEAL WEIGHT AND HEIGHT:
 * WEIGHT = 2*V+8 (KG), HEIGHT = 5*V+80 (CM)
 * EXAMPLE: 10 -> WEIGHT=28 KG, HEIGHT=130 CM */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int v = 0, weight, height;

	printf("v = ");
	scanf("%d", &v);

	/* THE TWO FORMULAS FROM THE BOOK */
	weight = 2 * v + 8;
	height = 5 * v + 80;

	printf("weight=%d kg\n", weight);
	printf("height=%d cm\n", height);

	return 0;
}
