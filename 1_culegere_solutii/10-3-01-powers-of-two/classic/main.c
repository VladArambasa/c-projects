/* CULEGERE X.3.1 - POWERS OF 2
 * PRINT ALL THE VALUES 2^N FOR N FROM 31 TO 50
 * EXAMPLE: (NO INPUT) -> 2^31 = 2147483648, 2^32 = 4294967296, ..., 2^50 = 1125899906842624
 * 2^50 IS ABOUT 10^15: IT DOES NOT FIT IN AN INT, BUT IT FITS EASILY IN A LONG LONG */
#include <stdio.h> /* PRINTF */

int main(void)
{
	long long power = 1;
	int n;

	for (n = 1; n <= 50; n++)
	{
		power = power * 2; /* NOW POWER = 2^N */
		if (n >= 31)
		{
			printf("2^%d = %lld\n", n, power);
		}
	}

	return 0;
}
