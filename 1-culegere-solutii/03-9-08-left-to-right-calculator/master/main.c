/* CULEGERE III.9.8 - CALCULATOR WITHOUT PRIORITY
 * THE CHARACTERS OF AN EXPRESSION ARE READ ONE BY ONE UNTIL =; THEY CAN ONLY BE DIGITS AND
 * + - * / =. THE OPERATIONS ARE DONE IN THE ORDER THEY ARE TYPED, WITHOUT PRIORITY;
 * PRINT THE RESULT. A NUMBER CAN HAVE SEVERAL DIGITS
 * ASSUMPTION: / IS THE INTEGER DIVISION (THE QUOTIENT); DIVIDING BY 0 PRINTS DIVISION
 * IMPOSSIBLE; SPACES AND ENTER KEYS ARE IGNORED
 * EXAMPLE: 12+3*2= -> 30 (FIRST 12 + 3 = 15, THEN 15 * 2 = 30) */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int calculate(int a, char op, int b) /* A OP B, WHERE OP IS ONE OF + - * / */
{
	int result;

	if (op == '+')
	{
		result = a + b;
	}
	else if (op == '-')
	{
		result = a - b;
	}
	else if (op == '*')
	{
		result = a * b;
	}
	else
	{
		result = a / b; /* INTEGER DIVISION */
	}
	return result;
}

int main(void)
{
	int c;          /* INT, NOT CHAR: GETCHAR CAN ALSO RETURN EOF */
	int number = 0; /* THE NUMBER BEING TYPED NOW, DIGIT BY DIGIT */
	int result = 0; /* THE RESULT OF EVERYTHING BEFORE THAT NUMBER */
	char op = '+';  /* THE OPERATION WAITING FOR THAT NUMBER; AT THE START: 0 + FIRST NUMBER */

	printf("Expression (end it with =): ");
	do
	{
		c = getchar();
		if (isdigit(c))
		{
			number = number * 10 + (c - '0'); /* ONE MORE DIGIT: '7' - '0' IS 7 */
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == EOF)
		{
			/* THE NUMBER IS COMPLETE: DO THE OPERATION THAT WAS WAITING FOR IT */
			if (op == '/' && number == 0)
			{
				printf("Division impossible\n");
				return 0;
			}
			result = calculate(result, op, number);
			op = c; /* THIS SIGN WAITS FOR THE NEXT NUMBER */
			number = 0;
		}
	} while (c != '=' && c != EOF);

	printf("%d\n", result);

	return 0;
}
