/* FIBONACCI NUMBERS: EACH ONE IS THE SUM OF THE TWO BEFORE IT (0 1 1 2 3 5 8 ...), RECURSIVE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int calls = 0; /* COUNTS HOW MANY TIMES FIB RUNS */

long long fib(int n)
{
	calls++;
	if (n < 2) /* FIB(0) = 0, FIB(1) = 1 */
	{
		return n;
	}
	return fib(n - 1) + fib(n - 2); /* TWO CALLS, AND EACH OF THEM MAKES TWO MORE ... */
}

int main(void)
{
	int n = 0;

	printf("Enter n (0-40): ");
	scanf("%d", &n);
	if (n < 0 || n > 40)
	{
		printf("n must be between 0 and 40\n");
		return 1;
	}

	printf("fib(%d) = %lld\n", n, fib(n));
	printf("function calls: %d\n", calls); /* THE SAME VALUES ARE COMPUTED OVER AND OVER */

	return 0;
}
