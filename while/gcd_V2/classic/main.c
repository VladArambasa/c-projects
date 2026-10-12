/* GREATEST COMMON DIVISOR (V2): EUCLID'S ALGORITHM, GCD(A, B) = GCD(B, A % B), MUCH FEWER STEPS */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int a = 0, b = 0, r;

	printf("Enter two positive numbers: ");
	scanf("%d %d", &a, &b);

	if (a <= 0 || b <= 0)
	{
		printf("Please enter positive numbers\n");
		return 1;
	}

	while (b != 0)
	{
		r = a % b; /* REPLACE (A, B) WITH (B, A % B) */
		a = b;
		b = r;
	}

	printf("GCD = %d\n", a); /* WHEN THE REMAINDER IS 0, A IS THE GCD */

	return 0;
}
