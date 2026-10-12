/* MEMORY ADDRESS: & GIVES THE PLACE IN MEMORY WHERE A VARIABLE IS STORED */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	int age = 43;
	char letter = 'A';
	double price = 9.99;

	/* PRINTF WANTS ADDRESSES AS VOID POINTERS, HENCE THE CAST */
	printf("age    = %d, stored at %p\n", age, (void *)&age);
	printf("letter = %c, stored at %p\n", letter, (void *)&letter);
	printf("price  = %.2f, stored at %p\n", price, (void *)&price);

	/* ADDRESSES ARE SHOWN IN HEXADECIMAL AND USUALLY CHANGE FROM ONE RUN TO THE NEXT */
	return 0;
}
