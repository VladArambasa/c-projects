#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double exponential(double lambda) {
	double u;
	do{
		u = (double)rand() / (RAND_MAX + 1.0);
	}while (u == 0.0); /* AVOID LOG[0] */
	return -log(u) / lambda;
}


int main() {
	int i, n = 100000;
	double lambda = 2.0;
	double sum = 0.0;
	srand(time(NULL));

	for (i = 0; i < n; i++) {
		double x = exponential(lambda);
		sum += x;
	}
	printf("Estimated E[X] = %f\n", sum / n);
	printf("Theoretical E[X] = %f\n", 1.0 / lambda);

	return 0;
}

