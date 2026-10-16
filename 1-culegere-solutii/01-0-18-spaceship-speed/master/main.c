/* CULEGERE I.18 - SPACESHIP SPEED
 * A SHIP TRAVELS BETWEEN TWO ORBITAL STATIONS; PRINT ITS SPEED IN KM/H. THE INPUT IS
 * D = THE DISTANCE IN KM, A = THE NUMBER OF WEEKS, B = THE NUMBER OF DAYS OF THE TRIP
 * EXAMPLE: D=3360 A=2 B=0 -> 10.00 KM/H */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	double d = 0, speed;
	int a = 0, b = 0, hours;

	printf("d = ");
	scanf("%lf", &d);
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);

	hours = (a * 7 + b) * 24; /* WEEKS TO DAYS, THEN DAYS TO HOURS */
	speed = d / hours; /* SPEED = DISTANCE / TIME */

	printf("%.2f km/h\n", speed);

	return 0;
}
