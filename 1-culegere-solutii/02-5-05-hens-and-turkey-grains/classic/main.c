/* CULEGERE II.5.5 - HENS AND THE TURKEY
 * EVERY HEN GETS THE SAME NUMBER OF CORN GRAINS; THE GRAINS THAT CANNOT BE SHARED GO TO THE
 * TURKEY. READ THE NUMBER OF HENS, THEN THE NUMBER OF GRAINS; PRINT WHO GOT MORE AND BY HOW
 * MUCH, OR, WHEN THEY GOT THE SAME, THE NUMBER OF GRAINS AND THE WORD "TIE"
 * EXAMPLE: 100 4050 -> THE TURKEY GOT 10 MORE GRAINS */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int hens = 0, grains = 0, hen, turkey;

	printf("Number of hens: ");
	scanf("%d", &hens);
	printf("Number of grains: ");
	scanf("%d", &grains);

	hen = grains / hens; /* EACH HEN GETS THE QUOTIENT */
	turkey = grains % hens; /* THE TURKEY GETS THE REMAINDER */

	if (turkey > hen)
	{
		printf("The turkey got %d more grains\n", turkey - hen);
	}
	else if (hen > turkey)
	{
		printf("Each hen got %d more grains\n", hen - turkey);
	}
	else
	{
		printf("%d grains, tie\n", hen);
	}

	return 0;
}
