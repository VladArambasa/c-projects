/* FORMAT SPECIFIERS: TELL PRINTF HOW TO SHOW EACH VALUE */
#include <stdio.h> /* PRINTF */

int main(void)
{
	int n = 255;
	float f = 5.99;
	double d = 3.14159265;
	char c = 'D';
	char city[] = "Timisoara";

	printf("int as %%d          : %d\n", n);
	printf("int as %%x (hex)    : %x\n", n);
	printf("int as %%o (octal)  : %o\n", n);
	printf("float as %%f        : %f\n", f);
	printf("double as %%f       : %f\n", d);
	printf("double as %%.2f     : %.2f\n", d); /* TWO DIGITS AFTER THE POINT */
	printf("double as %%e       : %e\n", d);   /* SCIENTIFIC NOTATION */
	printf("char as %%c         : %c\n", c);
	printf("char as %%d         : %d\n", c);   /* THE SAME BYTE SHOWN AS ITS CODE */
	printf("string as %%s       : %s\n", city);
	printf("width 5   [%%5d]    : [%5d]\n", 42);  /* RIGHT ALIGNED IN 5 PLACES */
	printf("left      [%%-5d]   : [%-5d]\n", 42); /* LEFT ALIGNED */
	printf("zeros     [%%05d]   : [%05d]\n", 42); /* PADDED WITH ZEROS */
	printf("a percent sign      : %%\n");          /* WRITE IT TWICE TO PRINT IT */

	return 0;
}
