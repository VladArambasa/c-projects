/* TEXT FILES WITH STDIO.H: WRITE SOME LINES, ADD ONE MORE, THEN READ THEM ALL BACK */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	FILE *f; /* THE FILE, AS SEEN BY THE PROGRAM */
	char line[100];
	int n = 0;

	f = fopen("notes.txt", "w"); /* WRITE MODE: CREATE THE FILE OR EMPTY IT */
	if (f == NULL)
	{
		printf("Cannot create notes.txt\n");
		return 1;
	}
	fprintf(f, "First line\n"); /* LIKE PRINTF, BUT INTO THE FILE */
	fprintf(f, "The answer is %d\n", 42);
	fclose(f); /* SAVE AND RELEASE THE FILE */

	f = fopen("notes.txt", "a"); /* APPEND MODE: WRITE AT THE END */
	if (f == NULL)
	{
		printf("Cannot open notes.txt\n");
		return 1;
	}
	fprintf(f, "Appended line\n");
	fclose(f);

	f = fopen("notes.txt", "r"); /* READ MODE */
	if (f == NULL)
	{
		printf("Cannot read notes.txt\n");
		return 1;
	}
	while (fgets(line, sizeof(line), f) != NULL) /* NULL AT THE END OF THE FILE */
	{
		n++;
		printf("%d: %s", n, line);
	}
	fclose(f);

	return 0;
}
