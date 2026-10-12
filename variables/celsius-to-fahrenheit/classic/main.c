/* CELSIUS TO FAHRENHEIT: F = C * 9 / 5 + 32 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	double celsius = 0, fahrenheit;

	printf("Enter the temperature in Celsius: ");
	scanf("%lf", &celsius);

	fahrenheit = celsius * 9 / 5 + 32; /* CELSIUS IS DOUBLE, SO THE DIVISION IS REAL */

	printf("%.1f C = %.1f F\n", celsius, fahrenheit);

	return 0;
}
