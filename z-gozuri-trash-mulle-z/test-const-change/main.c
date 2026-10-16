#include <stdio.h>
int main()
{
	const int a = 30;
	/* DEFINE A CONSTANT A OF TYPE INT WITH VALUE 30 */
	printf("Address of a is: %p\n",&a);
	printf("Value of a is: %d\n\n",a);
	int *p = (int*) &a;/* P KEEPS THE ADDRESS OF A */
	printf("Address of p is: %p\n",&p);
	printf("Value of p is: %p\n",p);
	printf("Value at address p(%p) is: %d\n\n",p,*p);
	
	*p = 567;
	printf("%d",a);
}
/** I HIGHLY ADVISE U NOT TO DO THIS! UNDEFINED BEHAVIOUR
*   I HOWEVER DID, WHILE WORKING IN A COMPANY, TO 
*   CHANGE SOME VALUES ON A MICROCONTROLLER TO WHAT I
*	DEEMED WAS RIGHT! **/
