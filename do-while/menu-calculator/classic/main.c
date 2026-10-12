/* MENU CALCULATOR: SHOW THE MENU AGAIN AND AGAIN UNTIL THE USER CHOOSES 0 */
#include <stdio.h> /* PRINTF, SCANF */

int main(void)
{
	int choice = 0;
	double a = 0, b = 0;

	do
	{
		printf("\n1) Add  2) Subtract  3) Multiply  4) Divide  0) Exit\nChoice: ");
		choice = 0; /* IF NOTHING CAN BE READ, 0 ENDS THE PROGRAM */
		scanf("%d", &choice);

		if (choice >= 1 && choice <= 4)
		{
			printf("Enter two numbers: ");
			scanf("%lf %lf", &a, &b);
		}

		switch (choice)
		{
		case 1:
			printf("Result: %.2f\n", a + b);
			break;
		case 2:
			printf("Result: %.2f\n", a - b);
			break;
		case 3:
			printf("Result: %.2f\n", a * b);
			break;
		case 4:
			if (b == 0)
			{
				printf("Cannot divide by zero\n");
			}
			else
			{
				printf("Result: %.2f\n", a / b);
			}
			break;
		case 0:
			printf("Bye!\n");
			break;
		default:
			printf("Unknown choice\n");
		}
	} while (choice != 0);

	return 0;
}
