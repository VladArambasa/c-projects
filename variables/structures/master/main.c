/* STRUCTURES: SEVERAL VALUES OF DIFFERENT TYPES UNDER ONE NAME */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

struct point
{
	int x;
	int y;
};

struct person
{
	char name[30];
	char sex;
	int age;
	float height;
};

int main(void)
{
	struct point p1, p2;
	struct point origin = {0, 0};
	struct person ion = {"Barbu Ion", 'M', 23, 1.78};

	p1.x = 3; /* THE DOT GIVES ACCESS TO A MEMBER */
	p1.y = 4;
	p2 = p1;  /* A WHOLE STRUCTURE CAN BE COPIED AT ONCE */
	p2.y = -1;

	printf("origin = (%d, %d)\n", origin.x, origin.y);
	printf("p1 = (%d, %d), p2 = (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
	printf("%s, %c, %d years, %.2f m\n", ion.name, ion.sex, ion.age, ion.height);
	printf("sizeof(struct person) = %zu\n", sizeof(struct person)); /* CAN INCLUDE PADDING BYTES */

	return 0;
}
