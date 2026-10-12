/* CULEGERE IX.1.6 - MEDICINES FOR A PATIENT
 * FOR EACH OF THE 10 DISEASES, THE NAMES OF THE INDICATED AND OF THE CONTRAINDICATED MEDICINES ARE
 * READ; THEN THE DISEASES OF A PATIENT ARE READ. PRINT THE MEDICINES THE PATIENT CAN BE GIVEN
 * ASSUMPTION: A MEDICINE CAN BE GIVEN IF IT IS INDICATED FOR AT LEAST ONE OF THE PATIENT'S DISEASES
 * AND CONTRAINDICATED FOR NONE OF THEM; THE DISEASES ARE NUMBERED 1..10; A NAME IS ONE WORD
 * EXAMPLE: DISEASE 1: INDICATED ASPIRIN, PARACETAMOL; DISEASE 2: INDICATED ANTACID, CONTRAINDICATED
 *          ASPIRIN; EMPTY LISTS FOR 3..10; A PATIENT WITH DISEASES 1 AND 2 -> PARACETAMOL ANTACID
 * A MEDICINE GETS A NUMBER WHEN ITS NAME FIRST APPEARS; A SET OF MEDICINES IS AN ARRAY OF FLAGS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define DISEASES 10 /* THE STATEMENT HAS 10 DISEASES */
#define MAXMED 100  /* AT MOST 100 DIFFERENT MEDICINES */
#define MAXNAME 31  /* A NAME HAS AT MOST 30 LETTERS */

/* THE NUMBER OF THE MEDICINE CALLED NAME, OR -1 IF IT IS NOT IN THE LIST YET */
int find_name(char names[][MAXNAME], int known, char name[])
{
	int i;

	for (i = 0; i < known; i++)
	{
		if (strcmp(names[i], name) == 0)
		{
			return i;
		}
	}
	return -1;
}

/* READS A LIST (HOW MANY, THEN THE NAMES) INTO THE SET; NEW NAMES ARE ADDED TO NAMES;
 * RETURNS HOW MANY NAMES ARE KNOWN AFTERWARDS */
int read_list(int set[], char names[][MAXNAME], int known)
{
	char name[MAXNAME] = "";
	int count = 0, i, k;

	for (k = 0; k < MAXMED; k++)
	{
		set[k] = 0; /* START WITH THE EMPTY SET */
	}
	scanf("%d", &count);
	for (i = 0; i < count; i++)
	{
		scanf("%30s", name);
		k = find_name(names, known, name);
		if (k == -1) /* A NEW MEDICINE GETS THE NEXT FREE NUMBER */
		{
			strcpy(names[known], name);
			k = known;
			known++;
		}
		set[k] = 1;
	}
	return known;
}

int main(void)
{
	char names[MAXMED][MAXNAME];         /* NAMES[K] = THE NAME OF MEDICINE NUMBER K */
	int indicated[DISEASES + 1][MAXMED]; /* FOR EACH DISEASE: THE INDICATED MEDICINES */
	int contra[DISEASES + 1][MAXMED];    /* FOR EACH DISEASE: THE CONTRAINDICATED ONES */
	int needed[MAXMED], forbidden[MAXMED];
	int known = 0, count = 0, d = 0, i, k, found = 0;

	for (i = 1; i <= DISEASES; i++)
	{
		printf("Disease %d, indicated medicines (how many, then the names): ", i);
		known = read_list(indicated[i], names, known);
		printf("Disease %d, contraindicated medicines (how many, then the names): ", i);
		known = read_list(contra[i], names, known);
	}

	for (k = 0; k < known; k++)
	{
		needed[k] = 0;
		forbidden[k] = 0;
	}
	printf("Number of diseases of the patient: ");
	scanf("%d", &count);
	printf("The diseases (numbers from 1 to %d): ", DISEASES);
	for (i = 0; i < count; i++)
	{
		scanf("%d", &d);
		for (k = 0; k < known; k++)
		{
			/* UNION OF THE INDICATED SETS AND UNION OF THE CONTRAINDICATED SETS */
			needed[k] = needed[k] || indicated[d][k];
			forbidden[k] = forbidden[k] || contra[d][k];
		}
	}

	printf("Medicines that can be given:");
	for (k = 0; k < known; k++)
	{
		if (needed[k] == 1 && forbidden[k] == 0) /* THE DIFFERENCE NEEDED - FORBIDDEN */
		{
			printf(" %s", names[k]);
			found = 1;
		}
	}
	if (found == 0)
	{
		printf(" none");
	}
	printf("\n");

	return 0;
}
