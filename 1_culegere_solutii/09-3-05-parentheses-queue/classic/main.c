/* CULEGERE IX.3.5 - PARENTHESES IN A QUEUE
 * A LINE OF ROUND PARENTHESES ENDING WITH A DOT IS READ. AN OPEN PARENTHESIS IS INSERTED IN
 * A QUEUE, A CLOSED ONE EXTRACTS AN ELEMENT FROM THE QUEUE. CHECK WHETHER THE PARENTHESES CLOSE
 * CORRECTLY AND FIND THE MAXIMUM SIZE OF THE QUEUE (THE MOST OPEN PARENTHESES WAITING AT ONCE)
 * ASSUMPTION: A CLOSED PARENTHESIS FOUND WITH AN EMPTY QUEUE MAKES THE LINE INCORRECT, BUT THE
 * READING GOES ON UNTIL THE DOT; OTHER CHARACTERS (SPACES) ARE SKIPPED
 * EXAMPLE: (()). -> CORRECT MAX SIZE=2; (((). -> INCORRECT MAX SIZE=3;
 *          ()). -> INCORRECT MAX SIZE=1
 * EVERY ELEMENT OF THIS QUEUE IS AN OPEN PARENTHESIS, SO THE QUEUE IS KNOWN FROM ITS SIZE ALONE:
 * AN INSERTION ADDS 1 TO THE SIZE, AN EXTRACTION TAKES 1 AWAY */
#include <stdio.h> /* PRINTF, GETCHAR */

int main(void)
{
	int size = 0; /* HOW MANY OPEN PARENTHESES WAIT IN THE QUEUE */
	int max = 0, correct = 1;
	int c;

	printf("Parentheses (end with a dot): ");
	c = getchar();
	while (c != '.' && c != EOF)
	{
		if (c == '(')
		{
			size++; /* INSERT IT AT THE END OF THE QUEUE */
			if (size > max)
			{
				max = size;
			}
		}
		else if (c == ')')
		{
			if (size == 0)
			{
				correct = 0; /* NOTHING TO EXTRACT: IT WAS NEVER OPENED */
			}
			else
			{
				size--; /* EXTRACT THE ELEMENT AT THE FRONT */
			}
		}
		c = getchar();
	}
	if (size > 0)
	{
		correct = 0; /* SOME PARENTHESES WERE NEVER CLOSED */
	}

	if (correct == 1)
	{
		printf("correct max size=%d\n", max);
	}
	else
	{
		printf("incorrect max size=%d\n", max);
	}

	return 0;
}
