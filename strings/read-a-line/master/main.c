/* READING TEXT: FGETS READS A WHOLE LINE, SCANF READS ONE WORD */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	char line[100] = "";
	char word[50] = "";

	printf("Enter a sentence: ");
	fgets(line, sizeof(line), stdin); /* KEEPS THE SPACES AND THE ENTER KEY */

	printf("Enter one word: ");
	scanf("%49s", word); /* STOPS AT THE FIRST SPACE; 49 LEAVES ROOM FOR '\0' */

	printf("Sentence: %s", line); /* THE LINE ALREADY ENDS WITH A NEWLINE */
	printf("Word: %s\n", word);

	return 0;
}
