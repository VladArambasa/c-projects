/* ARGUMENT CONVERSION: WITH A PROTOTYPE IN SIGHT, EACH ARGUMENT IS CONVERTED TO THE PARAMETER TYPE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

double half(double x); /* THE COMPILER NOW KNOWS X IS A DOUBLE */
int whole(int x);      /* AND THAT THIS X IS AN INT */

int main(void)
{
	int count = 5;
	double price = 7.9;

	printf("half(count) = %.1f\n", half(count));   /* THE INT 5 BECOMES 5.0 */
	printf("whole(price) = %d\n", whole(price)); /* 7.9 BECOMES 7 */

	return 0;
}

double half(double x)
{
	return x / 2;
}

int whole(int x)
{
	return x;
}
