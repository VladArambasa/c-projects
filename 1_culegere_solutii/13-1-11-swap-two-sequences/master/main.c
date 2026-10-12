/* CULEGERE XIII.1.11 - SWAP TWO SEQUENCES
 * READ N NUMBERS; SWAP THE SEQUENCE OF LENGTH L1 THAT STARTS ON POSITION P1 WITH THE SEQUENCE OF
 * LENGTH L2 THAT STARTS ON POSITION P2; THE ELEMENTS BETWEEN THEM MOVE AS NEEDED
 * EXAMPLE: 1 2 3 4 5 6 7 8 9, P1=2 L1=2 P2=6 L2=3 -> 1 6 7 8 4 5 2 3 9
 * ASSUMPTION: THE TWO SEQUENCES DO NOT OVERLAP; IF P2 < P1 THEY SIMPLY CHANGE ROLES */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 100

int main(void)
{
	int a[MAX + 1], b[MAX + 1]; /* B IS BUILT FROM THE PIECES OF A */
	int n = 0, p1 = 0, l1 = 0, p2 = 0, l2 = 0, i, m, temp;

	printf("n = ");
	scanf("%d", &n);
	printf("The %d numbers: ", n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("p1 = ");
	scanf("%d", &p1);
	printf("l1 = ");
	scanf("%d", &l1);
	printf("p2 = ");
	scanf("%d", &p2);
	printf("l2 = ");
	scanf("%d", &l2);

	if (p1 > p2) /* MAKE THE FIRST SEQUENCE THE ONE ON THE LEFT */
	{
		temp = p1;
		p1 = p2;
		p2 = temp;
		temp = l1;
		l1 = l2;
		l2 = temp;
	}

	/* COPY THE PIECES INTO B, FROM LEFT TO RIGHT, IN THE NEW ORDER */
	m = 0;
	for (i = 1; i < p1; i++) /* WHAT COMES BEFORE THE FIRST SEQUENCE */
	{
		m++;
		b[m] = a[i];
	}
	for (i = p2; i < p2 + l2; i++) /* THE SECOND SEQUENCE TAKES THE PLACE OF THE FIRST */
	{
		m++;
		b[m] = a[i];
	}
	for (i = p1 + l1; i < p2; i++) /* WHAT LIES BETWEEN THE TWO SEQUENCES */
	{
		m++;
		b[m] = a[i];
	}
	for (i = p1; i < p1 + l1; i++) /* THE FIRST SEQUENCE */
	{
		m++;
		b[m] = a[i];
	}
	for (i = p2 + l2; i <= n; i++) /* WHAT COMES AFTER THE SECOND SEQUENCE */
	{
		m++;
		b[m] = a[i];
	}

	printf("Result:");
	for (i = 1; i <= m; i++)
	{
		printf(" %d", b[i]);
	}
	printf("\n");

	return 0;
}
