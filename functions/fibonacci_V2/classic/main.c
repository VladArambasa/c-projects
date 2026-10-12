/* FIBONACCI NUMBERS (V2): A LOOP KEEPS ONLY THE LAST TWO VALUES, SO EACH ONE IS COMPUTED ONCE */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int n = 0, i;
	long long a = 0, b = 1, next; /* A = FIB(I), B = FIB(I + 1) */

	printf("Enter n (0-40): ");
	scanf("%d", &n);
	if (n < 0 || n > 40)
	{
		printf("n must be between 0 and 40\n");
		return 1;
	}

	for (i = 0; i < n; i++) /* N STEPS INSTEAD OF MILLIONS OF CALLS */
	{
		next = a + b;
		a = b;
		b = next;
	}

	printf("fib(%d) = %lld\n", n, a);
	printf("loop steps: %d\n", n);

	return 0;
}
