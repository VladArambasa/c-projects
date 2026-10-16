/* CULEGERE II.2.7 - IDEAL WEIGHT
 * READ THE HEIGHT (CM), THE AGE (YEARS) AND THE SEX (F OR M) OF A PERSON; PRINT THE IDEAL
 * WEIGHT: MALE = 50 + 0.75 * (HEIGHT - 150) + (AGE - 20) / 4, FEMALE = MALE - 10
 * EXAMPLE: 160 21 F -> WEIGHT=47.75 KG */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int height = 0, age = 0;
	char sex = ' ';
	double weight;

	printf("Height (cm): ");
	scanf("%d", &height);
	printf("Age (years): ");
	scanf("%d", &age);
	printf("Sex (f or m): ");
	scanf(" %c", &sex);

	/* 4.0 AND NOT 4, SO THAT THE DIVISION KEEPS THE DECIMALS (1 / 4 WOULD GIVE 0) */
	weight = 50 + 0.75 * (height - 150) + (age - 20) / 4.0;
	if (sex == 'f')
	{
		weight = weight - 10; /* THE FORMULA FOR WOMEN */
	}

	printf("weight=%.2f kg\n", weight);

	return 0;
}
