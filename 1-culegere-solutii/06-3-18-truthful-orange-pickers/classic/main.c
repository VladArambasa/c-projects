/* CULEGERE VI.3.18 - PICKING ORANGES
 * THE CHILDREN OF A CLASS PICK ORANGES. THE NUMBER OF CHILDREN AND HOW MANY ORANGES EACH CHILD
 * SAYS HE PICKED ARE READ. THE CHILD WHO SAYS THE BIGGEST NUMBER AND THE CHILD WHO SAYS THE
 * SMALLEST NUMBER LIE; PRINT HOW MANY ORANGES THE CHILDREN WHO TELL THE TRUTH PICKED TOGETHER
 * EXAMPLE: 5 CHILDREN, 69 25 14 329 54 -> 148
 * ASSUMPTION: IF SEVERAL CHILDREN SAY THE BIGGEST (OR THE SMALLEST) NUMBER, ALL OF THEM LIE */
#include <stdio.h> /* PRINTF, SCANF */

#define MAX 100

int main(void)
{
	int oranges[MAX] = {0};
	int n = 0, i, max, min;
	int sum = 0;

	printf("Number of children: ");
	scanf("%d", &n);
	printf("Oranges picked by each child: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &oranges[i]);
	}

	max = oranges[0]; /* FIRST FIND THE TWO LIES: THE BIGGEST AND THE SMALLEST NUMBER */
	min = oranges[0];
	for (i = 1; i < n; i++)
	{
		if (oranges[i] > max)
		{
			max = oranges[i];
		}
		if (oranges[i] < min)
		{
			min = oranges[i];
		}
	}

	for (i = 0; i < n; i++) /* THEN ADD UP ONLY THE TRUE NUMBERS */
	{
		if (oranges[i] != max && oranges[i] != min)
		{
			sum = sum + oranges[i];
		}
	}

	printf("%d\n", sum);

	return 0;
}
