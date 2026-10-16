/* CULEGERE VIII.1.14 - THE GAME WITH NUMBERED BALLS
 * AN URN HOLDS WHITE AND RED BALLS, EACH WITH A NUMBER FROM 1 TO 50. IONEL AND PETRICA EACH
 * DRAW 5 BALLS AND WRITE THEIR NUMBERS ONE AFTER THE OTHER, FORMING A NUMBER; THE CHILD WITH
 * THE BIGGER NUMBER WINS. PRINT THE TWO NUMBERS AND THE WINNER (CJI PETROSANI 2005)
 * EXAMPLE: IONEL 10 23 1 15 48 -> 102311548, PETRICA 1 15 24 25 26 -> 115242526,
 * PETRICA WON
 * ASSUMPTION: THE NUMBERS OF THE 10 DRAWN BALLS ARE READ FROM THE KEYBOARD, 5 FOR EACH CHILD */
#include <stdio.h>  /* PRINTF, SCANF, SPRINTF */
#include <string.h> /* STRCAT, STRCMP, STRLEN */

#define BALLS 5    /* EACH CHILD DRAWS 5 BALLS */
#define MAX_LEN 60 /* ROOM FOR THE DIGITS OF 5 NUMBERS AND THE NULL CHARACTER */

/* READS THE NUMBERS OF THE 5 BALLS OF A CHILD AND WRITES THEM ONE AFTER THE OTHER INTO NUMBER[] */
void read_balls(char name[], char number[])
{
	char part[12]; /* ONE BALL NUMBER WRITTEN AS A STRING */
	int k, ball = 0;

	number[0] = '\0'; /* START WITH AN EMPTY STRING */
	printf("The %d balls of %s: ", BALLS, name);
	for (k = 0; k < BALLS; k++)
	{
		ball = 0;
		scanf("%d", &ball);
		sprintf(part, "%d", ball); /* THE NUMBER BECOMES A STRING: 23 -> "23" */
		strcat(number, part); /* AND IS GLUED AT THE END */
	}
}

/* COMPARES TWO NUMBERS WRITTEN AS STRINGS (WITH NO ZEROS IN FRONT):
 * RETURNS 1 IF X IS BIGGER, -1 IF Y IS BIGGER AND 0 IF THEY ARE EQUAL */
int compare_numbers(char x[], char y[])
{
	int lx, ly, result;

	lx = strlen(x);
	ly = strlen(y);
	/* THE NUMBER WITH MORE DIGITS IS THE BIGGER ONE */
	if (lx > ly)
	{
		return 1;
	}
	if (lx < ly)
	{
		return -1;
	}
	/* SAME NUMBER OF DIGITS: THE FIRST DIFFERENT DIGIT DECIDES,
	 * WHICH IS EXACTLY WHAT STRCMP CHECKS */
	result = strcmp(x, y);
	if (result > 0)
	{
		return 1;
	}
	if (result < 0)
	{
		return -1;
	}
	return 0;
}

int main(void)
{
	char ionel[MAX_LEN], petrica[MAX_LEN];
	int result;

	read_balls("Ionel", ionel);
	read_balls("Petrica", petrica);

	printf("Ionel's number: %s\n", ionel);
	printf("Petrica's number: %s\n", petrica);

	result = compare_numbers(ionel, petrica);
	if (result > 0)
	{
		printf("Ionel won.\n");
	}
	else if (result < 0)
	{
		printf("Petrica won.\n");
	}
	else
	{
		printf("It is a draw.\n");
	}

	return 0;
}
