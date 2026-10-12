/* CULEGERE IX.2.3 - THE HOTTEST DAYS
 * A WEATHER STATION WRITES IN THE FILE TEMP.INT ONE LINE PER DAY: THE DATE AND THE TEMPERATURE;
 * PRINT THE DAYS WHEN THE TEMPERATURE WAS THE HIGHEST
 * ASSUMPTION: THE DATE IS ONE WORD WITHOUT SPACES (E.G. 02.07.2006), THE TEMPERATURE A REAL NUMBER;
 * THE FILE HAS NO COUNT AT THE START, SO IT IS READ UNTIL ITS END (AT MOST 366 DAYS)
 * EXAMPLE: 01.07.2006 28.5 / 02.07.2006 31.5 / 03.07.2006 30 / 04.07.2006 31.5 / 05.07.2006 27
 *          -> MAXIMUM TEMPERATURE 31.5 ON 02.07.2006 AND 04.07.2006
 * EVERY DAY IS A RECORD (A STRUCT) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 366 /* THE DAYS OF ONE YEAR */

struct day
{
	char date[21];
	double temp;
};

int main(void)
{
	FILE *f = fopen("temp.int", "r");
	struct day d[MAX];
	int n = 0, i;
	double max;

	if (f == NULL)
	{
		printf("Cannot open temp.int\n");
		return 1;
	}
	/* FSCANF RETURNS 2 AS LONG AS IT FINDS A DATE AND A TEMPERATURE */
	while (n < MAX && fscanf(f, "%20s %lf", d[n].date, &d[n].temp) == 2)
	{
		n++;
	}
	fclose(f);

	if (n == 0)
	{
		printf("The file has no data\n");
		return 0;
	}

	max = d[0].temp;
	for (i = 1; i < n; i++)
	{
		if (d[i].temp > max)
		{
			max = d[i].temp;
		}
	}
	printf("Maximum temperature: %g\n", max);
	for (i = 0; i < n; i++)
	{
		if (d[i].temp == max) /* MAX IS A COPY OF A VALUE READ, SO == IS EXACT HERE */
		{
			printf("%s\n", d[i].date);
		}
	}

	return 0;
}
