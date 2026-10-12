/* WORD LIST MANAGER: KEEP A FILE OF WORDS UP TO DATE USING COMMAND-LINE ARGUMENTS
 * EACH ARGUMENT: A (ADD) OR D (DELETE) FOLLOWED BY A WORD IN LOWERCASE LETTERS
 * IGNORED: INVALID ARGUMENTS, ADDING A WORD ALREADY THERE, DELETING A MISSING WORD */
#include <stdio.h>  /* FOPEN, FSCANF, FPRINTF, FCLOSE, PRINTF */
#include <string.h> /* STRCMP, STRCPY, STRLEN */

#define MAX_WORDS 100 /* HOW MANY WORDS THE LIST CAN HOLD */
#define MAX_LEN 50    /* LONGEST WORD + 1 FOR THE TERMINATOR */

char list[MAX_WORDS][MAX_LEN]; /* THE WORDS, IN MEMORY */
int count = 0;                 /* HOW MANY WORDS ARE IN THE LIST */

/* POSITION OF THE WORD IN THE LIST, OR -1 IF IT IS NOT THERE */
int find(char word[])
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(list[i], word) == 0) /* 0 MEANS THE STRINGS ARE EQUAL */
		{
			return i;
		}
	}
	return -1;
}

/* 1 IF THE ARGUMENT IS A OR D FOLLOWED BY LOWERCASE LETTERS ONLY */
int is_valid(char arg[])
{
	int len = strlen(arg);

	if (len < 2 || len > MAX_LEN)
	{
		return 0;
	}
	if (arg[0] != 'A' && arg[0] != 'D')
	{
		return 0;
	}
	for (int i = 1; i < len; i++)
	{
		if (arg[i] < 'a' || arg[i] > 'z')
		{
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[])
{
	char word[MAX_LEN];
	FILE *f;
	int existed = 0;

	if (argc < 2)
	{
		printf("Please give the items as argument. Example: %s Acar Aman Dcar\n", argv[0]);
		return 1;
	}

	/* 1. LOAD THE OLD LIST, IF THERE IS ONE */
	f = fopen("list.txt", "r"); /* NULL WHEN THE FILE DOES NOT EXIST */
	if (f != NULL)
	{
		existed = 1;
		while (count < MAX_WORDS && fscanf(f, "%49s", word) == 1) /* ONE WORD PER LINE */
		{
			strcpy(list[count], word);
			count++;
		}
		fclose(f);
	}

	/* 2. APPLY THE ARGUMENTS IN ORDER */
	for (int i = 1; i < argc; i++)
	{
		if (!is_valid(argv[i]))
		{
			continue; /* SKIP INVALID ARGUMENTS */
		}
		strcpy(word, argv[i] + 1); /* THE WORD WITHOUT ITS PREFIX */
		int pos = find(word);

		if (argv[i][0] == 'A' && pos == -1 && count < MAX_WORDS)
		{
			strcpy(list[count], word);
			count++;
			printf("Add - %s\n", word);
		}
		if (argv[i][0] == 'D' && pos != -1)
		{
			for (int j = pos; j < count - 1; j++) /* MOVE THE NEXT WORDS ONE PLACE LEFT */
			{
				strcpy(list[j], list[j + 1]);
			}
			count--;
			printf("Delete - %s\n", word);
		}
	}

	/* 3. SAVE THE NEW LIST */
	f = fopen("list.txt", "w"); /* WRITE MODE: CREATES THE FILE OR EMPTIES IT */
	if (f == NULL)
	{
		printf("Cannot write list.txt\n");
		return 1;
	}
	for (int i = 0; i < count; i++)
	{
		fprintf(f, "%s\n", list[i]);
	}
	fclose(f);

	if (existed)
	{
		printf("list.txt updated\n");
	}
	else
	{
		printf("A file generated named list.txt\n");
	}
	return 0;
}
