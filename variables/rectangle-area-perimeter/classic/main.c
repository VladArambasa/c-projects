/* AREA AND PERIMETER OF A RECTANGLE */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int length = 0, width = 0;
	int area, perimeter;

	printf("Enter length and width: ");
	scanf("%d %d", &length, &width);

	area = length * width;
	perimeter = 2 * (length + width);

	printf("Area = %d, Perimeter = %d\n", area, perimeter);

	return 0;
}
