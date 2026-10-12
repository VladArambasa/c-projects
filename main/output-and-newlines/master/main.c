/* OUTPUT AND NEW LINES: HOW TEXT REACHES THE SCREEN */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	printf("Hello World! "); /* NO NEWLINE: THE NEXT TEXT STAYS ON THIS LINE */
	printf("I am learning C.\n");

	printf("Line one\nLine two\nLine three\n"); /* SEVERAL LINES IN ONE CALL */

	printf("Before the blank line\n\n"); /* TWO NEWLINES = ONE EMPTY LINE */
	printf("After the blank line\n");

	puts("puts adds the newline by itself");

	putchar('C'); /* ONE CHARACTER */
	putchar('\n');

	printf("Tab:[\t] Quote:[\"] Backslash:[\\] Percent:[%%]\n"); /* SPECIAL CHARACTERS */

	return 0;
}
