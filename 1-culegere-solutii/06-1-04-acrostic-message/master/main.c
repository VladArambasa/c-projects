/* CULEGERE VI.1.4 - ACROSTIC
 * IN AN ACROSTIC THE FIRST LETTERS OF THE VERSES MAKE A MESSAGE. READ AN ACROSTIC VERSE BY VERSE
 * AND PRINT THE MESSAGE MADE BY THE FIRST LETTERS
 * EXAMPLE: 5 VERSES: VREAU SA DORM / RAD IN SOMN / ESTE CA UN DROG / ACEST DRAG SOMN /
 *          UITAT IN PAT -> VREAU
 * ASSUMPTION: THE NUMBER OF VERSES IS READ FIRST, THEN THE VERSES, ONE PER LINE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 VERSES */
#define LEN 256 /* AT MOST 254 CHARACTERS IN A VERSE */

int main(void)
{
	char verse[LEN] = "";
	char message[MAX + 1] = ""; /* ONE LETTER FOR EVERY VERSE, PLUS THE END OF THE STRING */
	int n = 0, i;

	printf("Number of verses: ");
	scanf("%d", &n);
	fgets(verse, LEN, stdin); /* SKIP THE ENTER LEFT AFTER THE NUMBER */

	printf("The %d verses, one per line:\n", n);
	for (i = 0; i < n; i++)
	{
		fgets(verse, LEN, stdin); /* THE WHOLE VERSE, SPACES INCLUDED */
		message[i] = verse[0];    /* KEEP ONLY ITS FIRST LETTER */
	}
	message[n] = '\0'; /* NOW THE MESSAGE IS A STRING */

	printf("%s\n", message);

	return 0;
}
