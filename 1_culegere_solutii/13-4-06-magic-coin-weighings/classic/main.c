/* CULEGERE XIII.4.6 - THE MAGIC COIN
 * THE MAGIC RON (A COIN) IS HIDDEN AMONG K OTHER RONS THAT LOOK THE SAME BUT ARE ALL HEAVIER. WITH
 * A BALANCE (THE SAME NUMBER OF RONS ON EACH PAN) THE MAGIC RON CAN ALWAYS BE FOUND IN W
 * WEIGHINGS, W BEING THE SMALLEST NUMBER WITH 3 TO THE POWER W >= K + 1: A WEIGHING SPLITS THE
 * RONS INTO THREE GROUPS (LEFT PAN, RIGHT PAN, OFF THE BALANCE) AND SHOWS WHICH GROUP HOLDS THE
 * LIGHT ONE. RON.IN HOLDS K (1 < K < 10000), THEN THE ANSWERS RL (LIDORIA) AND RS (SENOPICTIA);
 * WRITE IN RON.OUT L IF ONLY RL IS CORRECT, S IF ONLY RS IS CORRECT, AND O (ORINTIA) IF BOTH ARE
 * CORRECT OR NONE IS
 * EXAMPLE: 7 / 1 3 -> O (THE CORRECT NUMBER IS 2); 4 / 2 2 -> O (BOTH ARE CORRECT) */
#include <stdio.h> /* PRINTF, FOPEN, FSCANF, FPRINTF */

/* THE SMALLEST NUMBER OF WEIGHINGS THAT ALWAYS FINDS THE LIGHT RON AMONG COUNT RONS */
int weighings(int count)
{
	int w = 0;
	int power = 1; /* 3 TO THE POWER W: HOW MANY RONS W WEIGHINGS CAN HANDLE */

	while (power < count)
	{
		power = power * 3;
		w++;
	}
	return w;
}

int main(void)
{
	FILE *in = fopen("ron.in", "r");
	FILE *out;
	int k = 0, rl = 0, rs = 0, w;
	char winner;

	if (in == NULL)
	{
		printf("Cannot open ron.in\n");
		return 1;
	}
	fscanf(in, "%d %d %d", &k, &rl, &rs);
	fclose(in);

	w = weighings(k + 1); /* K HEAVY RONS AND THE MAGIC ONE */
	if (rl == w && rs != w)
	{
		winner = 'L';
	}
	else if (rs == w && rl != w)
	{
		winner = 'S';
	}
	else
	{
		winner = 'O'; /* BOTH CORRECT OR BOTH WRONG */
	}

	out = fopen("ron.out", "w");
	fprintf(out, "%c\n", winner);
	fclose(out);

	return 0;
}
