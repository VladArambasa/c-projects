/* SIMPLE AND COMPOUND INTEREST */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	double principal = 0, rate = 0, years = 0;
	double simple, compound;

	printf("Enter principal, rate (%%) and time (years): ");
	scanf("%lf %lf %lf", &principal, &rate, &years);

	simple = principal * rate * years / 100;
	compound = principal * pow(1 + rate / 100, years) - principal; /* POW(X, Y) = X TO THE POWER Y */

	printf("Simple interest = %.2f\n", simple);
	printf("Compound interest = %.2f\n", compound);

	return 0;
}
