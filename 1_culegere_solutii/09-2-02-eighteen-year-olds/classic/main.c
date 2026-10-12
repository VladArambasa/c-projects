/* CULEGERE IX.2.2 - ADULTS ON 1 JANUARY 2006
 * THE FILE DATE.INT HOLDS N, THEN N LINES "NAME YY MM DD" (A NAME AND A DATE OF BIRTH);
 * PRINT ON THE SCREEN, ONE UNDER THE OTHER, THE NAMES OF THE PERSONS WHO HAD TURNED 18
 * BY 1 JANUARY 2006
 * ASSUMPTION: A TWO-DIGIT YEAR MEANS 19YY (87 MEANS 1987), A FOUR-DIGIT YEAR IS TAKEN AS IT IS;
 * A PERSON BORN ON 1 JANUARY 1988 TURNS 18 EXACTLY THAT DAY, SO IS SELECTED; A NAME IS ONE WORD
 * EXAMPLE: POPESCU 87 03 15, IONESCU 88 01 01, MARIN 88 01 02 -> POPESCU, IONESCU */
#include <stdio.h> /* PRINTF, FOPEN, FSCANF, FCLOSE */

#define MAX 100        /* AT MOST 100 PERSONS */
#define LIMIT 19880101 /* BORN ON 1 JANUARY 1988 OR EARLIER = AT LEAST 18 ON 1 JANUARY 2006 */

struct person
{
	char name[31];
	int year;
	int month;
	int day;
};

int main(void)
{
	FILE *f = fopen("date.int", "r");
	struct person p[MAX];
	int n = 0, i, found = 0;

	if (f == NULL)
	{
		printf("Cannot open date.int\n");
		return 1;
	}
	fscanf(f, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(f, "%30s %d %d %d", p[i].name, &p[i].year, &p[i].month, &p[i].day);
		if (p[i].year < 100)
		{
			p[i].year = p[i].year + 1900; /* 87 MEANS 1987 */
		}
	}
	fclose(f);

	for (i = 0; i < n; i++)
	{
		/* THE DATE AS ONE NUMBER YYYYMMDD: A SMALLER NUMBER MEANS AN EARLIER DATE */
		if (p[i].year * 10000 + p[i].month * 100 + p[i].day <= LIMIT)
		{
			printf("%s\n", p[i].name);
			found = 1;
		}
	}
	if (found == 0)
	{
		printf("Nobody\n");
	}

	return 0;
}
