/* CULEGERE VI.3.14 - THE PARCELS
 * A PIECE OF LAND IS SPLIT INTO N RECTANGULAR PARCELS NUMBERED FROM 1 TO N. THE LENGTH AND THE
 * WIDTH OF EVERY PARCEL ARE READ; PRINT THE SUM OF THE AREAS AND THE LARGEST AREA
 * EXAMPLE: N=3, 10 5, 15 10, 12 5 -> SUM=260 MAX=150 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int area[MAX] = {0};
	int n = 0, i, length = 0, width = 0;
	int sum = 0, max;

	printf("n = ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Parcel %d (length width): ", i + 1);
		scanf("%d %d", &length, &width);
		area[i] = length * width; /* THE AREA OF A RECTANGLE */
	}

	max = area[0];
	for (i = 0; i < n; i++) /* THE SUM AND THE MAXIMUM IN THE SAME PASS */
	{
		sum = sum + area[i];
		if (area[i] > max)
		{
			max = area[i];
		}
	}

	printf("sum=%d max=%d\n", sum, max);

	return 0;
}
