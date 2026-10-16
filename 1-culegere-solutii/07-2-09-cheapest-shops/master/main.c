/* CULEGERE VII.2.9 - CHEAPEST SHOP FOR EACH PRODUCT
 * A PERSON MUST BUY P PRODUCTS SOLD IN M SHOPS; THE PRICES FORM A MATRIX WITH P ROWS (PRODUCTS)
 * AND M COLUMNS (SHOPS). FOR EACH PRODUCT PRINT THE SHOP WITH THE MINIMUM PRICE; KNOWING THE
 * QUANTITY TO BUY FROM EACH PRODUCT, PRINT THE MONEY NEEDED
 * EXAMPLE: P=2 M=3, 50000 48000 49500 / 11000 11500 11500, QUANTITIES 5 7 ->
 * PRODUCT 1 IN SHOP 2, PRODUCT 2 IN SHOP 1, 317000 LEI
 * ASSUMPTION: IF SEVERAL SHOPS HAVE THE SAME MINIMUM PRICE, THE FIRST OF THEM IS CHOSEN */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define MAX 50 /* AT MOST 50 PRODUCTS AND 50 SHOPS */

int main(void)
{
	int price[MAX][MAX] = {0};
	int quantity[MAX] = {0};
	int best[MAX];
	int p = 0, m = 0, i, j;
	long long total;

	printf("p = ");
	scanf("%d", &p);
	printf("m = ");
	scanf("%d", &m);
	for (i = 0; i < p; i++)
	{
		printf("Prices of product %d in the %d shops: ", i + 1, m);
		for (j = 0; j < m; j++)
		{
			scanf("%d", &price[i][j]);
		}
	}
	printf("Quantities of the %d products: ", p);
	for (i = 0; i < p; i++)
	{
		scanf("%d", &quantity[i]);
	}

	/* ON THE ROW OF EACH PRODUCT, FIND THE COLUMN (SHOP) WITH THE SMALLEST PRICE */
	for (i = 0; i < p; i++)
	{
		best[i] = 0;
		for (j = 1; j < m; j++)
		{
			if (price[i][j] < price[i][best[i]])
			{
				best[i] = j;
			}
		}
		printf("product %d minimum price in shop %d\n", i + 1, best[i] + 1);
	}

	/* EVERY PRODUCT IS BOUGHT IN ITS CHEAPEST SHOP;
	 * LONG LONG BECAUSE PRICES IN LEI CAN GIVE A VERY BIG TOTAL */
	total = 0;
	for (i = 0; i < p; i++)
	{
		total = total + (long long)quantity[i] * price[i][best[i]];
	}
	printf("The money needed: %lld lei\n", total);

	return 0;
}
