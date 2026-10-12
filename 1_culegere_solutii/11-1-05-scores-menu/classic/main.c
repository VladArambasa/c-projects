/* CULEGERE XI.1.5 - MENU FOR A LIST OF SCORES
 * READ N STUDENTS (NAME, SCORE); THE PROCEDURE MENU SHOWS
 *   1. DISPLAY IN ALPHABETICAL ORDER
 *   2. DISPLAY IN DESCENDING ORDER OF SCORES
 * AND THE USER CHOOSES; THE PROCEDURES SORT_DATA AND PRINT_DATA (THE BOOK'S SORTARE AND AFISARE)
 * DO THE WORK
 * EXAMPLE: MARIA 80, ANA 95, DAN 70; OPTION 1 -> ANA DAN MARIA; OPTION 2 -> ANA MARIA DAN
 * ASSUMPTION: EVERY NAME IS ONE WORD (NO SPACES)
 * ASSUMPTION: THE MENU COMES BACK AFTER EVERY CHOICE; OPTION 0 ENDS THE PROGRAM */
#include <stdio.h>  /* PRINTF, SCANF */
#include <string.h> /* STRCMP */

#define MAX 50 /* MOST STUDENTS */
#define LEN 30 /* LONGEST NAME + 1 */

struct student
{
	char name[LEN];
	int score;
};

/* MENU: SHOWS THE CHOICES */
void menu(void)
{
	printf("1. Display in alphabetical order\n");
	printf("2. Display in descending order of scores\n");
	printf("0. Exit\n");
	printf("Option: ");
}

/* SORTARE: BUBBLE SORT, BY NAME (OPTION 1) OR BY SCORE, HIGHEST FIRST (OPTION 2) */
void sort_data(struct student s[], int n, int option)
{
	struct student temp;
	int i, j, wrong_order;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			wrong_order = 0;
			if (option == 1 && strcmp(s[j].name, s[j + 1].name) > 0)
			{
				wrong_order = 1;
			}
			if (option == 2 && s[j].score < s[j + 1].score)
			{
				wrong_order = 1;
			}
			if (wrong_order == 1)
			{
				temp = s[j]; /* A WHOLE STRUCTURE IS COPIED AT ONCE */
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
}

/* AFISARE: ONE STUDENT PER LINE */
void print_data(struct student s[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%s %d\n", s[i].name, s[i].score);
	}
}

int main(void)
{
	struct student s[MAX];
	int n = 0, i, option = 0;

	printf("n = ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Student %d (name and score): ", i + 1);
		scanf("%29s %d", s[i].name, &s[i].score);
	}

	do
	{
		menu();
		option = 0; /* IF NOTHING IS TYPED ANY MORE, OPTION STAYS 0 AND THE PROGRAM ENDS */
		scanf("%d", &option);
		if (option == 1 || option == 2)
		{
			sort_data(s, n, option);
			print_data(s, n);
		}
		else if (option != 0)
		{
			printf("Unknown option\n");
		}
	} while (option != 0);

	return 0;
}
