/* CULEGERE XIII.2.2 - SLOPE VALUES
 * A VECTOR HAS N ELEMENTS (1 <= N <= 30), NATURAL NUMBERS WITH AT MOST 8 DIGITS. A SLOPE VALUE IS
 * A NUMBER WHOSE DIGITS ARE IN INCREASING ORDER WHEN READ FROM THE LEFT OR FROM THE RIGHT
 * (136, 931). A) PRINT HOW MANY ELEMENTS ARE SLOPE VALUES; B) PRINT THE LARGEST AND THE SMALLEST
 * SLOPE VALUE AND THE POSITIONS WHERE THEY ARE
 * EXAMPLE: 126 9621 1212 3678 9231 9621 -> 4; LARGEST 9621 AT POSITIONS 2 6; SMALLEST 126 AT 1
 * ASSUMPTION: THE DIGITS MUST BE STRICTLY INCREASING (112 IS NOT A SLOPE VALUE); A NUMBER WITH
 *             ONE DIGIT IS A SLOPE VALUE */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 30

/* 1 IF THE DIGITS OF X GROW FROM LEFT TO RIGHT OR FROM RIGHT TO LEFT */
int is_slope(int x)
{
	int from_left = 1, from_right = 1;
	int last, digit;

	last = x % 10; /* THE DIGITS ARE TAKEN FROM THE RIGHT END */
	x = x / 10;
	while (x > 0)
	{
		digit = x % 10; /* DIGIT STANDS JUST LEFT OF LAST */
		if (digit >= last)
		{
			from_left = 0; /* READ FROM THE LEFT, THE DIGITS DO NOT GROW HERE */
		}
		if (digit <= last)
		{
			from_right = 0; /* READ FROM THE RIGHT, THE DIGITS DO NOT GROW HERE */
		}
		last = digit;
		x = x / 10;
	}
	return from_left || from_right;
}

/* PRINTS THE POSITIONS (COUNTED FROM 1) WHERE VALUE APPEARS IN V */
void print_positions(int v[], int n, int value)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (v[i] == value)
		{
			printf(" %d", i + 1);
		}
	}
	printf("\n");
}

int main(void)
{
	int v[MAX] = {0};
	int n = 0, i, count = 0, max = 0, min = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}

	/* COUNT THE SLOPE VALUES; THE FIRST ONE FOUND STARTS BOTH THE MAXIMUM AND THE MINIMUM */
	for (i = 0; i < n; i++)
	{
		if (is_slope(v[i]))
		{
			count++;
			if (count == 1 || v[i] > max)
			{
				max = v[i];
			}
			if (count == 1 || v[i] < min)
			{
				min = v[i];
			}
		}
	}

	printf("number of slope values= %d\n", count);
	if (count == 0)
	{
		printf("There are no slope values\n");
	}
	else
	{
		printf("largest slope value=%d at positions", max);
		print_positions(v, n, max);
		printf("smallest slope value=%d at positions", min);
		print_positions(v, n, min);
	}

	return 0;
}
