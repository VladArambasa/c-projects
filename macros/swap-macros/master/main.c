/* SWAP MACROS: THREE WAYS TO EXCHANGE TWO VARIABLES WITH A MACRO */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define SWAP_XOR(A, B) { A = A ^ B; B = A ^ B; A = A ^ B; }      /* INTEGERS ONLY, NO EXTRA VARIABLE */
#define SWAP_INT(A, B) { int temp = A; A = B; B = temp; }        /* WITH A TEMPORARY VARIABLE */
#define SWAP(A, B, TYPE) do { TYPE temp = A; A = B; B = temp; } while (0) /* ANY TYPE */

int main(void)
{
	int a = 3, b = 7;
	double x = 1.5, y = 2.5;

	SWAP_XOR(a, b);
	printf("SWAP_XOR: a = %d, b = %d\n", a, b);

	SWAP_INT(a, b);
	printf("SWAP_INT: a = %d, b = %d\n", a, b);

	SWAP(x, y, double); /* DO ... WHILE (0) MAKES THE MACRO ACT LIKE ONE NORMAL STATEMENT */
	printf("SWAP:     x = %.1f, y = %.1f\n", x, y);

	/* SWAP_XOR(A, A) WOULD SET A TO 0: THE XOR TRICK NEEDS TWO DIFFERENT VARIABLES */
	return 0;
}
