/* CULEGERE VI.3.9 - NUMBERS OF THE FORM AAA
 * HOW MANY OF N GIVEN NUMBERS HAVE THE FORM AAA (THREE DIGITS, ALL OF THEM EQUAL)?
 * EXAMPLE: N=3, 123 222 434 -> 1 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

/* RETURNS 1 IF X HAS EXACTLY THREE DIGITS AND THEY ARE ALL EQUAL */
int is_aaa(int x)
{
	int hundreds, tens, units;

	if (x < 100 || x > 999) /* NOT A 3-DIGIT NUMBER */
	{
		return 0;
	}
	hundreds = x / 100; /* SPLIT THE NUMBER INTO ITS THREE DIGITS */
	tens = x / 10 % 10;
	units = x % 10;
	return hundreds == tens && tens == units;
}

int main(void)
{
	int a[MAX] = {0};
	int n = 0, i;
	int count = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++)
	{
		if (is_aaa(a[i]) == 1)
		{
			count++;
		}
	}

	printf("Numbers of the form aaa: %d\n", count);

	return 0;
}
