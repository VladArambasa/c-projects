/* ARRAYS: MANY VALUES OF THE SAME TYPE UNDER ONE NAME, REACHED BY THEIR INDEX */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int numbers[] = {25, 50, 75, 100}; /* THE SIZE (4) COMES FROM THE LIST */
	int tens[4];                       /* SIZE GIVEN NOW, VALUES ADDED LATER */
	int i;

	printf("First element: %d\n", numbers[0]); /* INDEXES START AT 0 */
	numbers[0] = 33;                           /* CHANGE ONE ELEMENT */
	printf("First element now: %d\n", numbers[0]);

	for (i = 0; i < 4; i++) /* VISIT EVERY ELEMENT; THE LAST INDEX IS 3, NOT 4 */
	{
		printf("numbers[%d] = %d\n", i, numbers[i]);
	}

	for (i = 0; i < 4; i++)
	{
		tens[i] = (i + 1) * 10;
	}
	printf("tens: %d %d %d %d\n", tens[0], tens[1], tens[2], tens[3]);

	/* NUMBER OF ELEMENTS = ALL THE BYTES / THE BYTES OF ONE ELEMENT */
	printf("Elements in numbers: %zu\n", sizeof(numbers) / sizeof(numbers[0]));

	return 0;
}
