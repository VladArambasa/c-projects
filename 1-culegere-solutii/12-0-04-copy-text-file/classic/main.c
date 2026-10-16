/* CULEGERE XII.4 - COPY A TEXT FILE
 * COPY THE CONTENT OF A TEXT FILE INTO ANOTHER TEXT FILE, IN EXACTLY THE SAME FORM
 * BOTH FILE NAMES ARE READ FROM THE KEYBOARD (A SAMPLE FILE COMES WITH THE PROGRAM)
 * EXAMPLE: THE SAMPLE FILE AND A NAME FOR THE COPY -> A NEW FILE WITH EXACTLY THE SAME CONTENT */
#include <stdio.h> /* PRINTF, SCANF, FOPEN, FGETC, FPUTC, FCLOSE */

int main(void)
{
	char source[100] = "";
	char target[100] = "";
	FILE *in;
	FILE *out;
	int c; /* INT, NOT CHAR: FGETC ALSO RETURNS EOF */

	printf("File name: ");
	scanf("%99s", source);
	printf("Name of the copy: ");
	scanf("%99s", target);

	in = fopen(source, "r");
	if (in == NULL)
	{
		printf("Cannot open %s\n", source);
		return 1;
	}
	out = fopen(target, "w"); /* WRITE MODE: CREATES THE FILE OR EMPTIES IT */
	if (out == NULL)
	{
		printf("Cannot open %s\n", target);
		fclose(in);
		return 1;
	}

	/* CHARACTER BY CHARACTER: SPACES, TABS AND ENTERS ARE COPIED TOO */
	while ((c = fgetc(in)) != EOF)
	{
		fputc(c, out);
	}
	fclose(in);
	fclose(out);

	printf("%s was copied to %s\n", source, target);

	return 0;
}
