/* PROFIT OR LOSS PERCENTAGE FROM THE COST PRICE AND THE SELLING PRICE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	double cost = 0, sell = 0;

	printf("Enter cost price and selling price: ");
	scanf("%lf %lf", &cost, &sell);

	if (sell > cost)
	{
		printf("Profit %.2f%%\n", (sell - cost) / cost * 100);
	}
	else if (sell < cost)
	{
		printf("Loss %.2f%%\n", (cost - sell) / cost * 100);
	}
	else
	{
		printf("No profit, no loss\n");
	}

	return 0;
}
