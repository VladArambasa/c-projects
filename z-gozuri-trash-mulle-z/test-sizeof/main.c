#include <stdio.h>
struct
{
	int int_field; /* PRIMITIVE : 4 BYTES */
	/* PADDING ADDED : 4 BYTES */
	unsigned long long int u64_field; /* PRIMITIVE : 8 BYTES */
	float fl_field; /* PRIMITIVE : 4 BYTES */
	char str_field[256]; /* 256 - Bytes; char = 1 Byte */
	/* PADDING ADDED : 4 BYTES */
}st_see;
/* PADDING IS ADDED FOR ALIGNMENT BECAUSE :
 * 1. LARGEST IS 8 BYTES (unsigned long long int = UINT64_T)
 * 2. CPU CAN ACCESS MEMORY MORE EFFICIENTLY IF EACH FIELD
 *    IS ALIGNED TO ITS NATURAL BOUNDARY (e.g., 4 or 8 BYTES)
 * 3. STRUCT SIZE IS ROUNDED TO MULTIPLE OF LARGEST ALIGNMENT 
 *    (USEFUL FOR ARRAYS OF STRUCTS)
 * */
union
{
	int int_field;						/* 4 BYTES */
	unsigned long long int u64_field;	/* 8 BYTES */
	float fl_field;						/* 4 BYTES */
	char str_field[256];				/* 256 * 1 BYTE = 256 BYTES */
	char *ch_ptr;
}un_see;/* 256 BYTES */
/* UNION :
 * ALL MEMBERS SHARE THE SAME MEMORY SPACE/
 * CHAR[256] IS THE LARGEST -> UNION ALLOCATES THE 256 BYTES.
 * THE REST OF THEM SHARE THOSE 256 BYTES WITH THE CHAR[]
 * THE CHAR* (THE POINTER) DOES NOT INFLUENCE THE ALLOCATION.
 * THAT IS BECAUSE:
 * CHAR[256] - ARRAY; ALLOCATES 256 BYTES.
 * CHAR * - POINTER; ALLOCATES SPACE FOR THE POINTER ITSELF, NOT AN
 * ACTUAL STRING.
 * */
enum
{
	RED,
	GREEN,
	BLUE,
}en_see;

void func(const char *str)
{
	printf("Const Char * AS ARG: %lu",sizeof(str));
}
int main()
{
	printf("Int %lu\n",sizeof(int));
	printf("Uint64_t %lu\n",sizeof(unsigned long long int));
	printf("Float %lu\n",sizeof(float));
	printf("Char %lu\n",sizeof(char));
	printf("Chars %lu\n",sizeof(char[256]));
	printf("\n\n");
	printf("Struct %lu\n",sizeof(st_see));
	printf("Union %lu\n",sizeof(un_see));
	printf("Enum %lu\n",sizeof(en_see));
	printf("\n\n");
	char c[256], *ptr;
	int i;
	ptr = c;
	for(i = 0; i < 256; i=i+1)
	{
		c[i] = '0';
	}
	printf("Char[256] %lu\n",sizeof(c));
	printf("Char* %lu\n",sizeof(ptr));
	func(c);
}
/*
 * STRUCT MEMORY LAYOUT
 *
 * +----------------------+-------+--------+--------------------------------------+
 * |     FIELD TYPE       | SIZE  | OFFSET |              NOTES                  |
 * +----------------------+-------+--------+--------------------------------------+
 * | int                  | 4     | 0      | aligned at 4                        |
 * | -- padding           | 4     | 4      | added to align next to 8            |
 * | uint64_t             | 8     | 8      | aligned at 8                        |
 * | float                | 4     | 16     | aligned at 4                        |
 * | char[256]            | 256   | 20     | aligned at 1, right after float     |
 * | -- padding           | 4     | 276    | added to align total size to 8      |
 * +----------------------+-------+--------+--------------------------------------+
 * | Total Size           | 280   |        | aligned to largest field (8 bytes)  |
 * +----------------------+-------+--------+--------------------------------------+
 *
 * NOTES:
 * - PADDING AFTER `int` ENSURES `uint64_t` IS AT OFFSET 8.
 * - NO PADDING NEEDED AFTER `float`, AS `char[256]` HAS 1-BYTE ALIGNMENT
 * 	AND FLOAT ENDS AT BYTE 20. 
 * - FINAL PADDING ADDED TO ENSURE THE STRUCT SIZE IS A MULTIPLE OF 8.
 * IT IS REQUIRED FOR ARRAYS, TO ENSURE THAT THE LARGEST MEMBER IS ALWAYS AT AN ADDRESS
 * WHICH IS A MULTIPLE OF 8.
 */
