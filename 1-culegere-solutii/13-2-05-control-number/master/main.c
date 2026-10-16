/* CULEGERE XIII.2.5 - CONTROL NUMBER
 * N BOXES (1 <= N <= 100) HAVE NATURAL WEIGHTS UP TO 200. FOR EVERY DISTINCT WEIGHT, IN INCREASING
 * ORDER, WRITE HOW MANY BOXES HAVE IT. GROUP THESE NUMBERS BY THREE FROM THE START (A SHORTER
 * GROUP AT THE END IS IGNORED); A GROUP OF ONLY EVEN OR ONLY ODD NUMBERS GIVES 1, ANY OTHER GROUP
 * GIVES 0. THE CONTROL NUMBER HAS THE COUNT OF ONES AS TENS DIGIT AND THE COUNT OF ZEROS AS UNITS
 * DIGIT. PRINT IT, THEN 1 IF IT IS PRIME AND 0 OTHERWISE
 * EXAMPLE: 1 3 2 6 2 6 2 8 9 8 8 9 10 8 11 18 11 12 14 15 17 -> 31 AND 1
 * ASSUMPTION: WITH MORE THAN 9 GROUPS OF ONE KIND THE NUMBER IS STILL ONES * 10 + ZEROS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX_WEIGHT 200

/* 1 IF X IS PRIME, 0 OTHERWISE; DIVISORS ARE TRIED UP TO THE SQUARE ROOT */
int is_prime(int x)
{
	int d;

	if (x < 2)
	{
		return 0;
	}
	for (d = 2; d * d <= x; d++)
	{
		if (x % d == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	int boxes[MAX_WEIGHT + 1] = {0}; /* BOXES[W] = HOW MANY BOXES WEIGH W */
	int sheet[MAX_WEIGHT + 1] = {0}; /* THE NUMBERS WRITTEN ON THE SHEET */
	int n = 0, weight = 0, i, j, k = 0, even, ones = 0, zeros = 0, control;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d weights: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &weight);
		boxes[weight]++;
	}

	/* GOING THROUGH THE WEIGHTS IN INCREASING ORDER GIVES THE SHEET WITHOUT ANY SORTING */
	for (weight = 0; weight <= MAX_WEIGHT; weight++)
	{
		if (boxes[weight] > 0)
		{
			sheet[k] = boxes[weight];
			k++;
		}
	}

	/* GROUPS OF THREE: SHEET[I], SHEET[I + 1], SHEET[I + 2]; COUNT THE EVEN NUMBERS IN EACH */
	for (i = 0; i + 2 < k; i = i + 3)
	{
		even = 0;
		for (j = i; j < i + 3; j++)
		{
			if (sheet[j] % 2 == 0)
			{
				even++;
			}
		}
		if (even == 0 || even == 3)
		{
			ones++; /* ONLY ODD OR ONLY EVEN NUMBERS */
		}
		else
		{
			zeros++;
		}
	}

	control = ones * 10 + zeros;
	printf("Control number: %d\n", control);
	printf("Prime: %d\n", is_prime(control));

	return 0;
}
