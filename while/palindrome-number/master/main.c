/* PALINDROME NUMBER: IT READS THE SAME BACKWARDS (12321) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0, copy;
	int reversed = 0;

	printf("Enter a number: ");
	scanf("%d", &n);

	copy = n; /* THE LOOP DESTROYS COPY, SO N KEEPS THE ORIGINAL */
	while (copy > 0)
	{
		reversed = reversed * 10 + copy % 10;
		copy = copy / 10;
	}

	if (n == reversed)
	{
		printf("%d is a palindrome\n", n);
	}
	else
	{
		printf("%d is not a palindrome\n", n);
	}

	return 0;
}
