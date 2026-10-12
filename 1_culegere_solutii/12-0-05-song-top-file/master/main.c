/* CULEGERE XII.5 - SONG TOP FROM A FILE
 * THE SONG TOP OF IX.2.1, WITH A FILE: EVERY LINE OF THE FILE HOLDS A TITLE, AN ARTIST AND THE
 * POINTS GATHERED SO FAR; THE POINTS OF THIS WEEK ARE READ FROM THE KEYBOARD; THE TOP (THE FIRST 10
 * SONGS, MOST POINTS FIRST) IS SHOWN ON THE SCREEN AND THE FILE GETS THE NEW TOTALS
 * NOTE: THE BOOK PRINTS THIS PROBLEM AS NUMBER 7 (IT IS THE FIFTH OF THE CHAPTER)
 * EXAMPLE: THE SAMPLE FILE AND THE POINTS 10 50 0 30 -> SILVER_BIKE 145, MORNING_TRAIN 140,
 * GREEN_WINDOW 130, LAST_SUMMER 110, AND THE FILE IS REWRITTEN WITH THESE TOTALS
 * ASSUMPTION: A TITLE OR AN ARTIST IS ONE WORD (_ STANDS FOR A SPACE); THE FILE IS REWRITTEN IN THE
 * ORDER OF THE TOP */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* MOST SONGS IN THE FILE */
#define LEN 50  /* LONGEST TITLE OR ARTIST + 1 */
#define TOP 10  /* HOW MANY SONGS THE TOP SHOWS */

struct song
{
	char title[LEN];
	char artist[LEN];
	int points;
};

int main(void)
{
	struct song s[MAX];
	struct song temp;
	char name[100] = "";
	FILE *f;
	int n = 0, i, j, week = 0;

	printf("File name: ");
	scanf("%99s", name);
	f = fopen(name, "r");
	if (f == NULL)
	{
		printf("Cannot open %s\n", name);
		return 1;
	}
	/* ONE SONG PER LINE; FSCANF RETURNS 3 AS LONG AS A WHOLE SONG IS READ */
	while (n < MAX && fscanf(f, "%49s %49s %d", s[n].title, s[n].artist, &s[n].points) == 3)
	{
		n++;
	}
	fclose(f);

	for (i = 0; i < n; i++) /* ADD THE POINTS OF THIS WEEK */
	{
		printf("Points this week for %s: ", s[i].title);
		scanf("%d", &week);
		s[i].points = s[i].points + week;
	}

	/* BUBBLE SORT, MOST POINTS FIRST */
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (s[j].points < s[j + 1].points)
			{
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}

	printf("Top of the week:\n");
	for (i = 0; i < n && i < TOP; i++)
	{
		printf("%d. %s - %s - %d points\n", i + 1, s[i].title, s[i].artist, s[i].points);
	}

	f = fopen(name, "w"); /* WRITE MODE: THE OLD CONTENT IS REPLACED BY THE NEW TOTALS */
	if (f == NULL)
	{
		printf("Cannot open %s\n", name);
		return 1;
	}
	for (i = 0; i < n; i++)
	{
		fprintf(f, "%s %s %d\n", s[i].title, s[i].artist, s[i].points);
	}
	fclose(f);
	printf("%s was updated\n", name);

	return 0;
}
