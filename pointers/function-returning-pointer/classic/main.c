/* A FUNCTION CAN RETURN A POINTER; CHECK IT FOR NULL BEFORE USING IT */
#include <stdio.h> /* PRINTF, SCANF, NULL */

int *find(int t[], int n, int value) /* ADDRESS OF THE FIRST MATCH, OR NULL */
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (t[i] == value)
		{
			return &t[i];
		}
	}
	return NULL; /* NULL: POINTS NOWHERE */
}

int main(void)
{
	int t[5] = {3, 8, 1, 8, 5};
	int value = 0, i;
	int *p;

	printf("Value to find: ");
	scanf("%d", &value);

	p = find(t, 5, value);
	if (p == NULL)
	{
		printf("%d not found\n", value);
		return 0;
	}

	printf("Found at index %d\n", (int)(p - t)); /* POINTER MINUS ARRAY START = INDEX */
	*p = 0; /* CHANGE THE ELEMENT THROUGH THE RETURNED POINTER */

	printf("Array after setting it to 0:");
	for (i = 0; i < 5; i++)
	{
		printf(" %d", t[i]);
	}
	printf("\n");

	return 0;
}
