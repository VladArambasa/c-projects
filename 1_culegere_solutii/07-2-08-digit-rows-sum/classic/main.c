/* CULEGERE VII.2.8 - SUM OF NUMBERS WRITTEN WITH DIGITS
 * AN M X N TABLE HOLDS DECIMAL DIGITS; EACH ROW HOLDS THE DIGITS OF A NATURAL NUMBER (SHORTER
 * NUMBERS START WITH ZEROS); PRINT ON ONE LINE THE DIGITS OF THE SUM OF THE M NUMBERS
 * EXAMPLE: M=4 N=4, 0 9 1 4 / 9 2 1 1 / 3 5 4 7 / 0 0 2 3 (914+9211+3547+23) -> 1 3 6 9 5 */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 50 /* AT MOST 50 NUMBERS WITH AT MOST 50 DIGITS */

int main(void)
{
	int a[MAX][MAX] = {0};
	int digit[MAX + 3]; /* THE SUM CAN HAVE UP TO 2 DIGITS MORE THAN THE NUMBERS */
	int m = 0, n = 0, i, j, s, carry, len;

	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);
	for (i = 0; i < m; i++)
	{
		printf("Digits of number %d: ", i + 1);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	/* ADD COLUMN BY COLUMN FROM RIGHT TO LEFT, AS ON PAPER;
	 * THE DIGITS OF THE SUM ARE STORED FROM THE LAST ONE TO THE FIRST ONE */
	carry = 0;
	len = 0;
	for (j = n - 1; j >= 0; j--)
	{
		s = carry;
		for (i = 0; i < m; i++)
		{
			s = s + a[i][j];
		}
		digit[len] = s % 10; /* THE DIGIT WE WRITE DOWN */
		len++;
		carry = s / 10; /* WHAT GOES TO THE NEXT COLUMN */
	}

	/* WHAT IS LEFT OF THE CARRY GIVES THE FIRST DIGITS OF THE SUM */
	while (carry > 0)
	{
		digit[len] = carry % 10;
		len++;
		carry = carry / 10;
	}

	/* ZEROS AT THE BEGINNING ARE NOT PRINTED, BUT AT LEAST ONE DIGIT IS */
	while (len > 1 && digit[len - 1] == 0)
	{
		len--;
	}

	printf("Sum:");
	for (i = len - 1; i >= 0; i--)
	{
		printf(" %d", digit[i]);
	}
	printf("\n");

	return 0;
}
