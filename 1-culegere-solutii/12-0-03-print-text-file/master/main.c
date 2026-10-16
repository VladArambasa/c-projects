/* CULEGERE XII.3 - SHOW A TEXT FILE
 * PRINT A TEXT FILE ON THE SCREEN, LINE BY LINE
 * THE FILE NAME IS READ FROM THE KEYBOARD (A SAMPLE FILE COMES WITH THE PROGRAM)
 * EXAMPLE: THE SAMPLE FILE -> ITS FOUR LINES, EXACTLY AS THEY ARE IN THE FILE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define LEN 256 /* A LONGER LINE IS SIMPLY READ IN SEVERAL PIECES */

int main(void)
{
	char name[100] = "";
	char line[LEN];
	FILE *f;

	printf("File name: ");
	scanf("%99s", name);
	f = fopen(name, "r");
	if (f == NULL)
	{
		printf("Cannot open %s\n", name);
		return 1;
	}

	while (fgets(line, LEN, f) != NULL) /* FGETS GIVES NULL AT THE END OF THE FILE */
	{
		printf("%s", line); /* THE LINE KEEPS ITS OWN ENTER */
	}
	fclose(f);

	return 0;
}
