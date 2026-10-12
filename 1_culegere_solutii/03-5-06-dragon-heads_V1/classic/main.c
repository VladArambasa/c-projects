/* CULEGERE III.5.6 - THE DRAGON'S HEADS
 * A DRAGON HAS 6 HEADS. ONE DAY FAT-FRUMOS CUTS ONE HEAD OFF, BUT 6 NEW HEADS GROW AT NIGHT.
 * THE SAME HAPPENS EVERY DAY FOR N DAYS; ON DAY N+1 FAT-FRUMOS GETS BORED AND GOES HOME.
 * READ N AND PRINT HOW MANY HEADS THE DRAGON HAS AFTER N DAYS (ONI 2002, GRADE 5)
 * ASSUMPTION: N >= 1; THE HEADS ARE COUNTED RIGHT AFTER THE CUT OF DAY N, AS THE EXAMPLE SHOWS
 * EXAMPLE: N=3 -> 15 HEADS */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, heads, day;

	printf("n = ");
	scanf("%d", &n);

	heads = 6;
	for (day = 1; day <= n; day++)
	{
		heads = heads - 1; /* FAT-FRUMOS CUTS ONE HEAD OFF */
		if (day < n) /* AFTER DAY N HE LEAVES, SO THAT NIGHT IS NOT COUNTED */
		{
			heads = heads + 6; /* 6 NEW HEADS GROW DURING THE NIGHT */
		}
	}
	printf("%d heads\n", heads);

	return 0;
}
