/* CULEGERE IX.1.4 - DISTINCT LETTERS OF THE WORDS
 * N WORDS OF SMALL LATIN LETTERS ARE READ, EACH ON ITS OWN LINE; PRINT THE DISTINCT LETTERS
 * OF EVERY WORD AND THE DISTINCT LETTERS MET IN ALL THE N WORDS TOGETHER
 * EXAMPLE: BACKSPACE, PROGRAM -> A B C E K P S / A G M O P R / TOTAL: A B C E G K M O P R S
 * A SET OF LETTERS IS AN ARRAY OF 26 FLAGS, ONE FOR EACH LETTER OF THE ALPHABET */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAXLEN 256 /* A WORD HAS AT MOST 255 LETTERS */

/* PRINTS THE LETTERS OF THE SET IN ALPHABETICAL ORDER */
void print_letters(int set[])
{
	int i;

	for (i = 0; i < 26; i++)
	{
		if (set[i] == 1)
		{
			printf(" %c", 'a' + i); /* FLAG I IS THE I-TH LETTER (FROM 0) */
		}
	}
	printf("\n");
}

int main(void)
{
	char word[MAXLEN] = "";
	int letters[26]; /* THE LETTERS OF THE CURRENT WORD */
	int total[26];   /* THE LETTERS OF ALL THE WORDS READ SO FAR */
	int n = 0, i, j, len;

	printf("Number of words: ");
	scanf("%d", &n);

	for (j = 0; j < 26; j++)
	{
		total[j] = 0; /* NO LETTER MET YET */
	}
	for (i = 1; i <= n; i++)
	{
		printf("Word %d: ", i);
		scanf("%255s", word);

		for (j = 0; j < 26; j++)
		{
			letters[j] = 0;
		}
		len = strlen(word);
		for (j = 0; j < len; j++)
		{
			letters[word[j] - 'a'] = 1; /* THE LETTER JOINS THE SET OF THIS WORD */
			total[word[j] - 'a'] = 1;   /* AND THE SET OF ALL THE WORDS (THEIR UNION) */
		}
		printf("letters of word %d:", i);
		print_letters(letters);
	}
	printf("letters in total:");
	print_letters(total);

	return 0;
}
