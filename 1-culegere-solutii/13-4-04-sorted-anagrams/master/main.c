/* CULEGERE XIII.4.4 - SORTED ANAGRAMS
 * ANAG.IN HOLDS A WORD OF AT MOST 10 LOWERCASE LETTERS; WRITE IN ANAG.OUT ALL ITS ANAGRAMS (THE
 * WORDS MADE OF THE SAME LETTERS, THE WORD ITSELF INCLUDED), EACH ONE ONCE, IN LEXICOGRAPHIC
 * ORDER, ONE PER LINE
 * IDEA: BACKTRACKING; POSITION BY POSITION, THE LETTERS STILL AVAILABLE ARE TRIED FROM A TO Z, SO
 * TWO EQUAL LETTERS ARE NEVER TRIED ON THE SAME POSITION AND THE ANAGRAMS COME OUT IN ORDER
 * EXAMPLE: ANA -> AAN ANA NAA */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAXLEN 11

int available[26];  /* HOW MANY OF EACH LETTER ARE STILL FREE */
char word[MAXLEN];  /* THE ANAGRAM BEING BUILT */
int len;
FILE *out;

/* CHOOSES THE LETTER OF POSITION POS, THEN GOES ON WITH THE NEXT POSITIONS */
void generate(int pos)
{
	int c;

	if (pos == len)
	{
		fprintf(out, "%s\n", word);
		return;
	}
	for (c = 0; c < 26; c++)
	{
		if (available[c] > 0)
		{
			available[c]--;
			word[pos] = 'a' + c;
			generate(pos + 1);
			available[c]++; /* THE LETTER IS FREE AGAIN FOR THE NEXT TRY */
		}
	}
}

int main(void)
{
	FILE *in = fopen("ANAG.IN", "r");
	char given[MAXLEN] = "";
	int i;

	if (in == NULL)
	{
		printf("Cannot open ANAG.IN\n");
		return 1;
	}
	fscanf(in, "%10s", given);
	fclose(in);

	len = strlen(given);
	for (i = 0; i < len; i++)
	{
		available[given[i] - 'a']++;
	}
	word[len] = '\0';

	out = fopen("ANAG.OUT", "w");
	generate(0);
	fclose(out);

	return 0;
}
