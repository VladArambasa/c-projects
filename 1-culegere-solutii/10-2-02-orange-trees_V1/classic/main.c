/* CULEGERE X.2.2 - THE ORANGE TREES (ONI 2003, CLASS VII)
 * N ORANGE TREES WITH FRUIT STAND ON A CIRCLE, NUMBERED 1..N CLOCKWISE. STARTING FROM TREE M
 * (WHICH COUNTS AS 1), GINO COUNTS CLOCKWISE K TREES THAT STILL HAVE FRUIT AND PICKS ALL THE
 * FRUIT OF THE K-TH ONE; HE STARTS COUNTING AGAIN FROM THE NEXT TREE WITH FRUIT. THE LAST TREE
 * LEFT, P, BECOMES HIS SHELTER. WHICH TREE M MUST HE START FROM SO THAT THE SHELTER IS TREE P?
 * PORTOCAL.IN: N K P (2 <= N <= 1000, 1 <= K <= 10000); PORTOCAL.OUT: M
 * EXAMPLE: 6 8 5 -> 3
 * METHOD: TRY M = 1, 2, 3, ... AND PLAY THE WHOLE GAME FOR EACH ONE */
#include <stdio.h> /* PRINTF, FOPEN, FSCANF, FPRINTF, FCLOSE */

#define MAXN 1000 /* AT MOST 1000 TREES */

/* THE FIRST TREE WITH FRUIT AFTER TREE POS, GOING CLOCKWISE */
int next_tree(int fruit[], int n, int pos)
{
	pos = pos % n + 1; /* AFTER TREE N COMES TREE 1 */
	while (fruit[pos] == 0)
	{
		pos = pos % n + 1;
	}
	return pos;
}

/* PLAYS THE GAME STARTING FROM TREE M AND RETURNS THE LAST TREE LEFT WITH FRUIT */
int last_tree(int n, int k, int m)
{
	int fruit[MAXN + 1]; /* FRUIT[I] = 1 WHILE TREE I STILL HAS FRUIT */
	int i, left, pos, steps;

	for (i = 1; i <= n; i++)
	{
		fruit[i] = 1;
	}
	pos = m;
	left = n;
	while (left > 1)
	{
		/* POS COUNTS AS 1, SO K - 1 STEPS FOLLOW; A FULL ROUND OF THE TREES THAT ARE LEFT
		 * BRINGS US BACK ON POS, SO ONLY (K - 1) % LEFT STEPS REALLY MATTER */
		steps = (k - 1) % left;
		for (i = 0; i < steps; i++)
		{
			pos = next_tree(fruit, n, pos);
		}
		fruit[pos] = 0; /* GINO PICKS THE FRUIT OF THIS TREE */
		left--;
		pos = next_tree(fruit, n, pos); /* COUNT AGAIN FROM THE NEXT TREE WITH FRUIT */
	}
	return pos;
}

int main(void)
{
	FILE *in = fopen("portocal.in", "r");
	FILE *out;
	int n = 0, k = 0, p = 0, m;

	if (in == NULL)
	{
		printf("Cannot open portocal.in\n");
		return 1;
	}
	fscanf(in, "%d %d %d", &n, &k, &p);
	fclose(in);

	/* EXACTLY ONE START LEAVES TREE P AT THE END, SO IF NONE OF 1..N-1 DOES, THE ANSWER IS N */
	m = 1;
	while (m < n && last_tree(n, k, m) != p)
	{
		m++;
	}

	out = fopen("portocal.out", "w");
	fprintf(out, "%d\n", m);
	fclose(out);

	return 0;
}
