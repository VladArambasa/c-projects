/* STRING.H: READY-MADE FUNCTIONS FOR STRINGS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	char city[50];
	char *p;

	strcpy(city, "Timis");  /* COPY INTO CITY */
	strcat(city, "oara");   /* ADD AT THE END */
	printf("city = %s, length = %zu\n", city, strlen(city));

	if (strcmp(city, "Timisoara") == 0) /* 0 MEANS EQUAL */
	{
		printf("strcmp: city is \"Timisoara\"\n");
	}
	if (strcmp("apple", "banana") < 0) /* NEGATIVE: THE FIRST COMES BEFORE */
	{
		printf("strcmp: apple comes before banana\n");
	}

	p = strchr(city, 's'); /* ADDRESS OF THE FIRST MATCHING CHARACTER, OR NULL */
	if (p != NULL)
	{
		printf("strchr: first 's' at index %d\n", (int)(p - city));
	}

	p = strstr(city, "oara"); /* ADDRESS WHERE THE SEARCHED TEXT STARTS, OR NULL */
	if (p != NULL)
	{
		printf("strstr: \"oara\" starts at index %d\n", (int)(p - city));
	}

	return 0;
}
