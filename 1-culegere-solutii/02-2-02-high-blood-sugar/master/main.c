/* CULEGERE II.2.2 - HIGH BLOOD SUGAR
 * THREE PAIRS (PATIENT NUMBER, BLOOD SUGAR VALUE) ARE READ; PRINT THE NUMBERS OF THE PATIENTS
 * WHOSE BLOOD SUGAR IS GREATER THAN 100
 * EXAMPLE: 6 90, 10 107, 21 110 -> 10 21 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int nr1 = 0, sugar1 = 0, nr2 = 0, sugar2 = 0, nr3 = 0, sugar3 = 0;

	printf("Patient 1 (number and blood sugar): ");
	scanf("%d %d", &nr1, &sugar1);
	printf("Patient 2 (number and blood sugar): ");
	scanf("%d %d", &nr2, &sugar2);
	printf("Patient 3 (number and blood sugar): ");
	scanf("%d %d", &nr3, &sugar3);

	/* EACH VALUE IS COMPARED WITH THE LIMIT 100, SEPARATELY */
	if (sugar1 > 100)
	{
		printf("%d ", nr1);
	}
	if (sugar2 > 100)
	{
		printf("%d ", nr2);
	}
	if (sugar3 > 100)
	{
		printf("%d ", nr3);
	}
	printf("\n");

	return 0;
}
