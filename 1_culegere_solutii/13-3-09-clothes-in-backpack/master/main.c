/* CULEGERE XIII.3.9 - CLOTHES IN THE BACKPACK
 * THE BACKPACK HOLDS V CM3 (0 < V < 30000); THERE ARE N CLOTHES (0 < N < 100) WITH THE VOLUMES
 * V1..VN CM3 (BELOW 30000) AND, PACKED AND PRESSED, EACH ONE GETS SMALLER BY P1..PN PERCENT (BELOW
 * 100). EXCURSIE.IN HOLDS V AND N, THE N VOLUMES AND THE N PERCENTS; WRITE IN EXCURSIE.OUT THE
 * GREATEST NUMBER OF CLOTHES THAT FIT IN THE BACKPACK
 * IDEA: THE SMALLEST PACKED CLOTHES ARE TAKEN FIRST, AS LONG AS THEY FIT: THIS GIVES THE MOST
 * CLOTHES. ALL VOLUMES ARE MULTIPLIED BY 100, SO THE PERCENTS GIVE WHOLE NUMBERS
 * EXAMPLE: 980 4 / 1600 200 10000 800 / 50 20 10 10 -> 2 (PACKED: 800 160 9000 720) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAXN 100

/* SORTS THE FIRST N VALUES OF A INCREASINGLY (BUBBLE SORT) */
void sort_increasing(int a[], int n)
{
	int i, j, temp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main(void)
{
	FILE *in = fopen("excursie.in", "r");
	FILE *out;
	int volume[MAXN], packed[MAXN];
	int v = 0, n = 0, percent = 0, i, sum, count;

	if (in == NULL)
	{
		printf("Cannot open excursie.in\n");
		return 1;
	}
	fscanf(in, "%d %d", &v, &n);
	for (i = 0; i < n; i++)
	{
		volume[i] = 0;
		fscanf(in, "%d", &volume[i]);
	}
	for (i = 0; i < n; i++)
	{
		fscanf(in, "%d", &percent);
		/* 100 TIMES THE PACKED VOLUME: OF EVERY 100 PARTS, 100 - PERCENT ARE LEFT */
		packed[i] = volume[i] * (100 - percent);
	}
	fclose(in);

	sort_increasing(packed, n);
	sum = 0;
	count = 0;
	while (count < n && sum + packed[count] <= v * 100)
	{
		sum = sum + packed[count];
		count++;
	}

	out = fopen("excursie.out", "w");
	fprintf(out, "%d\n", count);
	fclose(out);

	return 0;
}
