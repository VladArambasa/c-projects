/* CULEGERE XIII.2.25 - ROBOT BACK HOME
 * A ROBOT MOVES ON COMMANDS: NX = X METRES TO THE NORTH, EX = TO THE EAST, VX = TO THE WEST (VEST),
 * SX = TO THE SOUTH; THE COMMAND STAI (STOP) ENDS THE LIST. PRINT AT MOST 2 COMMANDS THAT BRING THE
 * ROBOT BACK TO ITS STARTING POINT
 * EXAMPLE: N3 V5 S3 E4 E5 N2 STAI -> V 4 S 2 (THE NUMBER MAY ALSO COME APART: N 3 V 5 S 3 ...) */
#include <stdio.h>  /* PRINTF, SCANF */
#include <string.h> /* STRCMP */

/* THE NUMBER WRITTEN IN THE WORD RIGHT AFTER ITS FIRST LETTER (N3 GIVES 3) */
int number_after_letter(char word[])
{
	int i, n = 0;

	for (i = 1; word[i] >= '0' && word[i] <= '9'; i++)
	{
		n = n * 10 + (word[i] - '0');
	}
	return n;
}

int main(void)
{
	char word[21] = "";
	int x = 0, east = 0, north = 0;

	printf("Commands (end with STAI): ");
	/* EAST AND NORTH: HOW FAR THE ROBOT IS FROM THE START (WEST AND SOUTH COUNT AS MINUS) */
	while (scanf("%20s", word) == 1 && strcmp(word, "STAI") != 0)
	{
		x = 0;
		if (word[1] != '\0')
		{
			x = number_after_letter(word); /* THE NUMBER IS GLUED TO THE LETTER: N3 */
		}
		else
		{
			scanf("%d", &x); /* THE NUMBER COMES APART: N 3 */
		}
		if (word[0] == 'N')
		{
			north = north + x;
		}
		else if (word[0] == 'S')
		{
			north = north - x;
		}
		else if (word[0] == 'E')
		{
			east = east + x;
		}
		else if (word[0] == 'V')
		{
			east = east - x;
		}
	}

	if (east == 0 && north == 0)
	{
		printf("The robot is already at the starting point\n");
		return 0;
	}

	/* TO COME BACK, GO THE OTHER WAY: FIRST EAST OR WEST, THEN NORTH OR SOUTH */
	printf("The robot returns with:");
	if (east > 0)
	{
		printf(" V %d", east);
	}
	else if (east < 0)
	{
		printf(" E %d", -east);
	}
	if (north > 0)
	{
		printf(" S %d", north);
	}
	else if (north < 0)
	{
		printf(" N %d", -north);
	}
	printf("\n");
	return 0;
}
