/* SHARING DATA THROUGH THE RETURN VALUE: THE FUNCTION SENDS ITS RESULT BACK TO THE CALLER */
#include <stdio.h> /* PRINTF, SCANF */

int get_int(void);          /* READS A NUMBER AND RETURNS IT */
int add(int a, int b);  /* RETURNS THE SUM */

int main(void)
{
	int x, y;

	printf("First number: ");
	x = get_int();
	printf("Second number: ");
	y = get_int();

	printf("%d + %d = %d\n", x, y, add(x, y));

	return 0;
}

int get_int(void)
{
	int value = 0;

	scanf("%d", &value);
	return value; /* THE CALLER RECEIVES THIS VALUE */
}

int add(int a, int b)
{
	return a + b;
}
