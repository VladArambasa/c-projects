/* ARRAY_LENGTH: THE NUMBER OF ELEMENTS OF AN ARRAY, COMPUTED BY THE COMPILER */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define ARRAY_LENGTH(A) (sizeof(A) / sizeof((A)[0])) /* ALL THE BYTES / THE BYTES OF ONE ELEMENT */

int main(void)
{
	int groups[] = {1, 3, 5, 3, 1};
	double prices[] = {9.99, 4.50};
	char word[] = "macro";
	size_t i;

	printf("groups has %zu elements\n", ARRAY_LENGTH(groups));
	printf("prices has %zu elements\n", ARRAY_LENGTH(prices));
	printf("word has %zu elements (5 letters + the terminator)\n", ARRAY_LENGTH(word));

	for (i = 0; i < ARRAY_LENGTH(groups); i++) /* ADD AN ELEMENT AND THE LOOP STILL FITS */
	{
		printf("%d ", groups[i]);
	}
	printf("\n");

	/* IT DOES NOT WORK ON A POINTER OR ON AN ARRAY PARAMETER: THERE THE SIZE IS LOST */
	return 0;
}
