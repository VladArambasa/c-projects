/* ONE'S COMPLEMENT OF A BINARY NUMBER: EVERY 0 BECOMES 1 AND EVERY 1 BECOMES 0 */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	char bits[100] = "";
	int i;

	printf("Enter a binary number: ");
	scanf("%99s", bits);

	for (i = 0; bits[i] != '\0'; i++)
	{
		if (bits[i] == '0')
		{
			bits[i] = '1';
		}
		else if (bits[i] == '1')
		{
			bits[i] = '0';
		}
		else
		{
			printf("Only 0 and 1 are allowed\n");
			return 1;
		}
	}

	printf("One's complement: %s\n", bits);

	return 0;
}
