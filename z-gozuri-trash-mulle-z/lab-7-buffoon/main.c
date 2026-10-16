#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TRIALS 1000000
/* MUCHO NUMBER -> MUCHO PRECISION */

int main() {
	int hits = 0;
	double d, theta;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < TRIALS; i++) {
		theta = ((double)rand() / RAND_MAX) * (M_PI / 2);	/*	THETA bt [0, PI/2]	*/
		d = ((double)rand() / RAND_MAX) * 0.5;				/* D bt [0, 0.5]		*/
		if (d <= 0.5 * sin(theta)) 
		{
			hits++;
		}
	}
	if (hits == 0)
	{
		printf("No hits detected. Try more trials.\n");
		return 1;
	}
	double estimated_pi = (2.0 * TRIALS) / hits;
	printf("Estimated π using Buffon's Needle: %f\n", estimated_pi);
	return 0;
}
