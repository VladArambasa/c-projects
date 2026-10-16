/* CULEGERE XII.2 - WHITE LINES
 * CHECK WHETHER A TEXT FILE HAS WHITE LINES, THAT IS LINES MADE ONLY OF SPACES AND TABS
 * THE FILE NAME IS READ FROM THE KEYBOARD (A SAMPLE FILE COMES WITH THE PROGRAM)
 * EXAMPLE: THE LINES "ONE", "   ", "TWO", "", "THREE" -> LINES 2 AND 4 ARE WHITE, SO YES
 * ASSUMPTION: AN EMPTY LINE ALSO COUNTS AS A WHITE LINE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	char name[100] = "";
	FILE *f;
	int c; /* INT, NOT CHAR: FGETC ALSO RETURNS EOF */
	int line = 1, white = 1, length = 0, found = 0;

	printf("File name: ");
	scanf("%99s", name);
	f = fopen(name, "r");
	if (f == NULL)
	{
		printf("Cannot open %s\n", name);
		return 1;
	}

	while ((c = fgetc(f)) != EOF)
	{
		if (c == '\n') /* THE LINE ENDS: WAS IT WHITE? */
		{
			if (white == 1)
			{
				printf("Line %d is white\n", line);
				found = 1;
			}
			line++;
			white = 1; /* A NEW LINE IS WHITE UNTIL ANOTHER CHARACTER SHOWS UP */
			length = 0;
		}
		else
		{
			length++;
			if (c != ' ' && c != '\t')
			{
				white = 0;
			}
		}
	}
	if (length > 0 && white == 1) /* A LAST LINE WITHOUT ENTER, MADE OF SPACES AND TABS */
	{
		printf("Line %d is white\n", line);
		found = 1;
	}
	fclose(f);

	if (found == 1)
	{
		printf("Yes, the file has white lines\n");
	}
	else
	{
		printf("No, the file has no white lines\n");
	}

	return 0;
}
