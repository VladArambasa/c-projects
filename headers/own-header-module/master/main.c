/* OWN HEADER: PROTOTYPES IN MATHUTILS.H, CODE IN MATHUTILS.C, USE IN MAIN.C
 * <NAME.H> IS SEARCHED IN THE SYSTEM FOLDERS, "NAME.H" FIRST IN THE PROJECT FOLDER */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int n = 0;

	printf("Enter a number: ");
	scanf("%d", &n);

	printf("square = %d\n", square(n));
	printf("cube = %d\n", cube(n));
	printf("even = %s\n", is_even(n) ? "yes" : "no");
	printf("maximum(n, 10) = %d\n", maximum(n, 10));

	return 0;
}
