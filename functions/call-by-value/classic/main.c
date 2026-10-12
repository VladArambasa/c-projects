/* CALL BY VALUE: A FUNCTION RECEIVES COPIES OF THE ARGUMENTS, NOT THE VARIABLES THEMSELVES */
#include <stdio.h> /* PRINTF */

void try_to_change(int x)
{
	x = 100; /* CHANGES ONLY THE LOCAL COPY */
	printf("inside the function: x = %d\n", x);
}

int main(void)
{
	int a = 5;

	try_to_change(a);
	printf("after the call: a = %d (unchanged)\n", a);
	/* TO CHANGE A VARIABLE, PASS ITS ADDRESS: SEE POINTERS/SWAP-VALUE-VS-ADDRESS */

	return 0;
}
