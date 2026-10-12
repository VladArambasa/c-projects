/* EXPLICIT CASTS: (TYPE) VALUE CONVERTS A VALUE ON PURPOSE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int sum = 7, count = 2;
	double price = 9.99;
	int code = 0x1234;

	printf("sum / count          = %d\n", sum / count);              /* INTEGER DIVISION */
	printf("(double)sum / count  = %.2f\n", (double)sum / count);    /* REAL DIVISION */
	printf("(double)(sum / count)= %.2f\n", (double)(sum / count));  /* TOO LATE: ALREADY 3 */
	printf("(int)price           = %d\n", (int)price);               /* CUTS THE FRACTION */
	printf("(int)(price + 0.5)   = %d\n", (int)(price + 0.5));       /* ROUNDS A POSITIVE VALUE */
	printf("(unsigned char)code  = 0x%X\n", (unsigned char)code);    /* KEEPS THE LOW BYTE */
	printf("(char)65             = %c\n", (char)65);

	return 0;
}
