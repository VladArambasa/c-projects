/* VARIABLES: DECLARE, ASSIGN, OVERWRITE AND PRINT */
#include <stdio.h> /* PRINTF */

int main(void)
{
	int num = 15;        /* WHOLE NUMBER */
	float price = 5.99;  /* NUMBER WITH DECIMALS */
	char letter = 'D';   /* ONE CHARACTER, IN SINGLE QUOTES */
	int x, y, z;         /* DECLARED NOW, ASSIGNED LATER */
	int minutes_per_hour = 60; /* A DESCRIPTIVE NAME IS EASIER TO READ THAN M */

	printf("num = %d\n", num);
	num = 10; /* THE NEW VALUE REPLACES THE OLD ONE */
	printf("num = %d after the new assignment\n", num);

	printf("price = %f, letter = %c\n", price, letter);
	printf("My number is %d and my letter is %c\n", num, letter);

	x = y = z = 50; /* THE SAME VALUE FOR ALL THREE */
	printf("x + y + z = %d\n", x + y + z);

	printf("Seconds in an hour: %d\n", minutes_per_hour * 60);

	return 0;
}
