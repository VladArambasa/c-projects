/* CULEGERE XI.1.1 - TABLE OF AVERAGES
 * READ_DATA (THE BOOK'S PROCEDURE CITIRE) READS N STUDENTS, EACH WITH A NAME AND THREE GRADES, AND
 * COMPUTES EVERY AVERAGE; TABLE_HEADER (TABEL) DRAWS THE HEADER OF THE TABLE; WRITE_DATA (SCRIERE)
 * PRINTS THE RESULTS; THE BORDER CHARACTER OF THE TABLE (* IN THE BOOK) IS READ IN MAIN AND
 * PASSED TO TABLE_HEADER
 * EXAMPLE: ANA 9 8 10, DAN 7 7 8, CHARACTER # -> A TABLE DRAWN WITH #: ANA 9.00, DAN 7.33
 * ASSUMPTION: EVERY NAME IS ONE WORD (NO SPACES) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50   /* MOST STUDENTS */
#define LEN 30   /* LONGEST NAME + 1 */
#define WIDTH 29 /* WIDTH OF THE TABLE, IN CHARACTERS */

/* CITIRE: READS THE N STUDENTS AND COMPUTES THEIR AVERAGES */
void read_data(int n, char names[][LEN], double averages[])
{
	int i, grade1 = 0, grade2 = 0, grade3 = 0;

	for (i = 0; i < n; i++)
	{
		printf("Student %d (name and 3 grades): ", i + 1);
		scanf("%29s %d %d %d", names[i], &grade1, &grade2, &grade3);
		averages[i] = (grade1 + grade2 + grade3) / 3.0; /* 3.0, NOT 3: A REAL DIVISION */
	}
}

/* A FULL LINE OF CHARACTER C */
void border_line(char c)
{
	int i;

	for (i = 0; i < WIDTH; i++)
	{
		printf("%c", c);
	}
	printf("\n");
}

/* TABEL: THE HEADER OF THE TABLE, DRAWN WITH CHARACTER C */
void table_header(char c)
{
	border_line(c);
	printf("%c %-15s %c %7s %c\n", c, "Student name", c, "Average", c);
	border_line(c);
}

/* SCRIERE: ONE ROW FOR EVERY STUDENT, THEN THE BOTTOM BORDER */
void write_data(int n, char names[][LEN], double averages[], char c)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%c %-15s %c %7.2f %c\n", c, names[i], c, averages[i], c);
	}
	border_line(c);
}

int main(void)
{
	char names[MAX][LEN];
	double averages[MAX];
	int n = 0;
	char c = '*'; /* THE BOOK'S CHARACTER; SCANF BELOW REPLACES IT WITH THE ONE TYPED */

	printf("n = ");
	scanf("%d", &n);
	read_data(n, names, averages);

	printf("Border character: ");
	scanf(" %c", &c); /* THE SPACE BEFORE %C SKIPS THE ENTER LEFT BY THE LAST SCANF */

	table_header(c);
	write_data(n, names, averages, c);

	return 0;
}
