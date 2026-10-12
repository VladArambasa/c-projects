/* INCREMENT AND DECREMENT: ++ AND -- ADD OR SUBTRACT 1 */
#include <stdio.h> /* PRINTF */

int main(void)
{
	int a, b = 3, c;

	a = 5;
	c = a++ * b; /* POSTFIX: USE A (5), THEN A BECOMES 6 */
	printf("c = a++ * b  gives c = %d, a = %d\n", c, a);

	a = 5;
	c = ++a * b; /* PREFIX: A BECOMES 6 FIRST, THEN IT IS USED */
	printf("c = ++a * b  gives c = %d, a = %d\n", c, a);

	a = 5;
	a--; /* ALONE ON A LINE BOTH FORMS ARE THE SAME */
	--a;
	printf("after a-- and --a, a = %d\n", a);

	return 0;
}
