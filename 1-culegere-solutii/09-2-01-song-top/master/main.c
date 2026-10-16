/* CULEGERE IX.2.1 - TOP 10 SONGS
 * N SONGS ARE READ: TITLE, PERFORMER, POINTS ACCUMULATED BEFORE AND POINTS RECEIVED THIS WEEK;
 * PRINT THE FIRST 10 SONGS IN DECREASING ORDER OF THEIR POINTS
 * ASSUMPTION: THE POINTS OF A SONG = ACCUMULATED + RECEIVED; SONGS WITH EQUAL POINTS KEEP THE ORDER
 * IN WHICH THEY WERE READ; A TITLE OR A PERFORMER IS ONE WORD (WRITE _ INSTEAD OF A SPACE)
 * EXAMPLE: HELLO ADELE 25 25, THRILLER JACKSON 50 2, HALO BEYONCE 12 12
 *          -> 1. THRILLER 52 POINTS, 2. HELLO 50 POINTS, 3. HALO 24 POINTS
 * EVERY SONG IS A RECORD (A STRUCT) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100 /* AT MOST 100 SONGS */
#define TOP 10  /* THE TOP HAS 10 PLACES */

struct song
{
	char title[51];
	char performer[51];
	int accumulated; /* POINTS FROM THE PREVIOUS WEEKS */
	int received;    /* POINTS RECEIVED THIS WEEK */
	int total;
};

int main(void)
{
	struct song songs[MAX], temp;
	int n = 0, i, j, places;

	printf("n = ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Song %d (title, performer, accumulated, received): ", i + 1);
		scanf("%50s %50s", songs[i].title, songs[i].performer);
		scanf("%d %d", &songs[i].accumulated, &songs[i].received);
		songs[i].total = songs[i].accumulated + songs[i].received;
	}

	/* BUBBLE SORT, DECREASING BY THE TOTAL;
	 * EQUAL TOTALS ARE NEVER SWAPPED, SO THEY KEEP THE ORDER IN WHICH THEY WERE READ */
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (songs[j].total < songs[j + 1].total)
			{
				temp = songs[j]; /* A WHOLE RECORD IS COPIED AT ONCE */
				songs[j] = songs[j + 1];
				songs[j + 1] = temp;
			}
		}
	}

	places = TOP;
	if (n < TOP)
	{
		places = n; /* FEWER THAN 10 SONGS: ALL OF THEM ARE SHOWN */
	}
	for (i = 0; i < places; i++)
	{
		printf("%d. %s - %s - %d points\n", i + 1, songs[i].title, songs[i].performer,
		       songs[i].total);
	}

	return 0;
}
