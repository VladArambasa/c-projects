/* ENUMERATIONS: NAMES FOR INTEGER CONSTANTS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

enum colors { BLACK, RED, GREEN, BLUE, WHITE }; /* 0, 1, 2, 3, 4 */
enum months { JAN = 1, FEB, MAR, DEC = 12 };    /* FEB = 2, MAR = 3 */

int main(void)
{
	char *names[] = {"BLACK", "RED", "GREEN", "BLUE", "WHITE"};
	enum colors c;

	for (c = BLACK; c <= WHITE; c++) /* ENUM VALUES ARE INTEGERS */
	{
		printf("%-5s = %d\n", names[c], (int)c);
	}

	printf("JAN = %d, FEB = %d, MAR = %d, DEC = %d\n", JAN, FEB, MAR, DEC);

	return 0;
}
