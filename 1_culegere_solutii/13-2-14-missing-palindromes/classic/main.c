/* CULEGERE XIII.2.14 - MISSING PALINDROMES
 * THE CODE NUMBERS OF N OBJECTS ARE GIVEN (0 < N < 26, THE LARGEST CODE IS SMALLER THAN 3001).
 * COUNT THE PALINDROMES THAT ARE SMALLER THAN THE LARGEST CODE AND ARE NOT AMONG THE CODES
 * EXAMPLE: 8 20 22 44 108 55 88 -> 15 (0 1 2 3 4 5 6 7 9 11 33 66 77 99 101) */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX_CODE 3000

/* 1 IF X READS THE SAME FROM BOTH ENDS */
int is_palindrome(int x)
{
	int copy = x, reversed = 0;

	while (copy > 0)
	{
		reversed = reversed * 10 + copy % 10; /* THE LAST DIGIT OF COPY GOES AT THE END */
		copy = copy / 10;
	}
	return reversed == x;
}

int main(void)
{
	int is_code[MAX_CODE + 1] = {0}; /* IS_CODE[X] = 1 WHEN X IS ONE OF THE CODES */
	int n = 0, code = 0, max = 0, i, x, count = 0;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d code numbers: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &code);
		is_code[code] = 1;
		if (code > max)
		{
			max = code;
		}
	}

	/* EVERY NUMBER BELOW THE LARGEST CODE: A PALINDROME THAT IS NOT A CODE IS COUNTED */
	for (x = 0; x < max; x++)
	{
		if (is_palindrome(x) && is_code[x] == 0)
		{
			count++;
		}
	}

	printf("Number of palindromes: %d\n", count);

	return 0;
}
