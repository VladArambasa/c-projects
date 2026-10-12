/* CULEGERE III.4.2 - SEVEN SUMS
 * READ N AND PRINT THE SUMS
 * S1 = 1+2+3+...+N
 * S2 = 1*2+2*3+3*4+...+(N-1)*N
 * S3 = 1+1*2+1*2*3+...+1*2*3*...*N
 * S4 = 1^2+2^2+3^2+...+N^2
 * S5 = 1/2+2/3+3/4+...+N/(N+1), A REAL NUMBER PRINTED WITH TWO DECIMALS
 * S6 = 2-3+4-5+...-99+100, WHICH DOES NOT DEPEND ON N
 * S7 = 1+2+2^2+2^3+...+2^N
 * ASSUMPTION: N <= 20, SO THAT 1*2*...*N FITS IN A LONG LONG
 * EXAMPLE: N=5 -> S1 = 15, S2 = 40, S3 = 153, S4 = 55, S5 = 3.55, S6 = 51, S7 = 63 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, i, s1, s2, s4, s6, s7, power;
	long long s3, factorial; /* 20! IS ABOUT 2.4 * 10^18 */
	double s5;

	printf("n = ");
	scanf("%d", &n);

	s1 = 0;
	s2 = 0;
	s3 = 0;
	s4 = 0;
	s5 = 0;
	s7 = 1; /* THE FIRST TERM, 2^0 = 1 */
	factorial = 1;
	power = 1;
	/* ONE LOOP BUILDS THE TERM NUMBER I OF EVERY SUM AND ADDS IT */
	for (i = 1; i <= n; i++)
	{
		s1 = s1 + i;
		s2 = s2 + (i - 1) * i; /* FOR I = 1 THE TERM IS 0 * 1 = 0 */
		factorial = factorial * i; /* NOW FACTORIAL = 1*2*...*I */
		s3 = s3 + factorial;
		s4 = s4 + i * i;
		s5 = s5 + (double)i / (i + 1); /* REAL DIVISION, NOT INTEGER DIVISION */
		power = power * 2; /* NOW POWER = 2^I */
		s7 = s7 + power;
	}

	/* S6 HAS FIXED LIMITS: THE EVEN NUMBERS ARE ADDED, THE ODD ONES ARE SUBTRACTED */
	s6 = 0;
	for (i = 2; i <= 100; i++)
	{
		if (i % 2 == 0)
		{
			s6 = s6 + i;
		}
		else
		{
			s6 = s6 - i;
		}
	}

	printf("s1 = %d\n", s1);
	printf("s2 = %d\n", s2);
	printf("s3 = %lld\n", s3);
	printf("s4 = %d\n", s4);
	printf("s5 = %.2f\n", s5);
	printf("s6 = %d\n", s6);
	printf("s7 = %d\n", s7);

	return 0;
}
