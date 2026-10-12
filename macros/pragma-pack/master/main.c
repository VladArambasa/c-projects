/* #PRAGMA PACK (GCC): REMOVE THE PADDING BYTES THE COMPILER PUTS BETWEEN STRUCTURE MEMBERS */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

struct normal
{
	char c; /* 1 BYTE, THEN 3 PADDING BYTES SO THAT MEMBER I STARTS AT A MULTIPLE OF 4 */
	int i;
};

#pragma pack(push, 1) /* FROM HERE ON: NO PADDING */
struct packed
{
	char c;
	int i;
};
#pragma pack(pop) /* BACK TO THE NORMAL RULES */

int main(void)
{
	printf("sizeof(struct normal) = %zu\n", sizeof(struct normal));
	printf("sizeof(struct packed) = %zu\n", sizeof(struct packed));
	printf("i starts at byte %zu in normal, at byte %zu in packed\n",
	       offsetof(struct normal, i), offsetof(struct packed, i));

	return 0;
}
