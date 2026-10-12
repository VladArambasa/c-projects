/* BUILD A FULL NAME WITH STRCPY AND STRCAT */
#include <stdio.h>  /* PRINTF, SCANF */
#include <string.h> /* STRCPY, STRCAT */

int main(void)
{
	char first[30] = "", last[30] = "";
	char full[100]; /* ROOM FOR BOTH NAMES AND A SPACE */

	printf("First name and last name: ");
	scanf("%29s %29s", first, last);

	strcpy(full, first); /* FULL = FIRST */
	strcat(full, " ");   /* ADD A SPACE AT THE END */
	strcat(full, last);  /* ADD THE LAST NAME */

	printf("Full name: %s\n", full);

	return 0;
}
