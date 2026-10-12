/* CULEGERE II.2.3 - MARKS FOR THE PARENTS
 * IONEL TELLS HIS PARENTS ONLY THE MARKS GREATER THAN OR EQUAL TO 7. READ THE THREE MARKS HE
 * GOT TODAY AND PRINT THE ONES HE WILL TELL HIS PARENTS
 * EXAMPLE: 8 7 5 -> 8 7 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int m1 = 0, m2 = 0, m3 = 0;

	printf("The three marks: ");
	scanf("%d %d %d", &m1, &m2, &m3);

	/* EACH MARK IS COMPARED WITH 7 */
	if (m1 >= 7)
	{
		printf("%d ", m1);
	}
	if (m2 >= 7)
	{
		printf("%d ", m2);
	}
	if (m3 >= 7)
	{
		printf("%d ", m3);
	}
	printf("\n");

	return 0;
}
