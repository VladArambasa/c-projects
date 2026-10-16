/* CULEGERE III.8.5 - IDENTICAL TEAMS
 * A CAMP HAS B BOYS AND F GIRLS; FORM AS MANY TEAMS AS POSSIBLE, ALL WITH THE SAME NUMBER NRB
 * OF BOYS AND THE SAME NUMBER NRF OF GIRLS. PRINT THE NUMBER OF TEAMS, NRB AND NRF, OR
 * "WE CANNOT PLAY" IF NOT EVEN TWO IDENTICAL TEAMS CAN BE FORMED
 * ASSUMPTION: EVERY CHILD PLAYS, SO THE NUMBER OF TEAMS IS GCD(B, F), AS THE EXAMPLES SHOW
 * EXAMPLES: B=10 F=15 -> 5 TEAMS WITH 2 BOYS AND 3 GIRLS; B=12 F=25 -> WE CANNOT PLAY */
#include <stdio.h> /* PRINTF, SCANF */

int gcd(int a, int b) /* EUCLID'S ALGORITHM */
{
	int r;

	while (b != 0)
	{
		r = a % b; /* REPLACE (A, B) WITH (B, A % B) */
		a = b;
		b = r;
	}
	return a; /* WHEN THE REMAINDER IS 0, A IS THE GCD */
}

int main(void)
{
	int b = 0, f = 0;
	int teams, nrb, nrf;

	printf("b = ");
	scanf("%d", &b);
	printf("f = ");
	scanf("%d", &f);

	/* THE NUMBER OF TEAMS MUST DIVIDE BOTH B AND F: THE LARGEST SUCH NUMBER IS THE GCD */
	teams = gcd(b, f);

	if (teams < 2)
	{
		printf("We cannot play\n");
	}
	else
	{
		nrb = b / teams; /* THE BOYS ARE SHARED EQUALLY AMONG THE TEAMS */
		nrf = f / teams; /* AND SO ARE THE GIRLS */
		printf("%d teams with %d %s and %d %s\n", teams,
		       nrb, (nrb == 1) ? "boy" : "boys", nrf, (nrf == 1) ? "girl" : "girls");
	}

	return 0;
}
