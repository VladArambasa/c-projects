/* CULEGERE XII.1 - LINES AND THEIR LENGTHS
 * COUNT THE LINES OF A TEXT FILE AND THE CHARACTERS ON EACH LINE
 * THE FILE NAME IS READ FROM THE KEYBOARD (A SAMPLE FILE COMES WITH THE PROGRAM)
 * EXAMPLE: THE LINES "HELLO" AND "C IS FUN" -> LINE 1: 5 CHARACTERS, LINE 2: 8 CHARACTERS, 2 LINES
 * ASSUMPTION: THE END OF LINE (ENTER) IS NOT COUNTED AS A CHARACTER */
#include <stdio.h> /* PRINTF, SCANF, FOPEN, FGETC, FCLOSE */

int main(void)
{
	char name[100] = "";
	FILE *f;
	int c; /* INT, NOT CHAR: FGETC ALSO RETURNS EOF */
	int lines = 0, count = 0;

	printf("File name: ");
	scanf("%99s", name);
	f = fopen(name, "r");
	if (f == NULL)
	{
		printf("Cannot open %s\n", name);
		return 1;
	}

	while ((c = fgetc(f)) != EOF) /* ONE CHARACTER AT A TIME, UNTIL THE END OF THE FILE */
	{
		if (c == '\n') /* THE LINE ENDS HERE */
		{
			lines++;
			printf("Line %d: %d characters\n", lines, count);
			count = 0;
		}
		else
		{
			count++;
		}
	}
	if (count > 0) /* THE LAST LINE MAY HAVE NO ENTER AT ITS END */
	{
		lines++;
		printf("Line %d: %d characters\n", lines, count);
	}
	fclose(f);

	printf("Number of lines: %d\n", lines);

	return 0;
}
