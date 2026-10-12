/* CULEGERE I.17 - SWAP TWO VARIABLES
 * READ TWO VALUES INTO THE VARIABLES A AND B, SWAP THEIR VALUES AND PRINT THE NEW A AND B
 * EXAMPLE: A=3 B=7 -> A=7 B=3 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int a = 0, b = 0, aux;

	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);

	/* LIKE SWAPPING THE JUICE IN TWO GLASSES: WE NEED A THIRD, EMPTY GLASS (AUX) */
	aux = a;
	a = b;
	b = aux;

	printf("a=%d b=%d\n", a, b);

	return 0;
}
