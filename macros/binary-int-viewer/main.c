/* THIS IS A BINARY PRINTER */
#include "master.h"
/* WE SHALL DO IT BY MEANS OF DEFINE */
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_DT unsigned char /* BYTE DATA TYPE */
#define BYTE_TO_BINARY(byte) \
	((byte) & 0x80 ? '1' : '0'), \
	((byte) & 0x40 ? '1' : '0'), \
	((byte) & 0x20 ? '1' : '0'), \
	((byte) & 0x10 ? '1' : '0'), \
	((byte) & 0x08 ? '1' : '0'), \
	((byte) & 0x04 ? '1' : '0'), \
	((byte) & 0x02 ? '1' : '0'), \
	((byte) & 0x01 ? '1' : '0')
int main()
{
	int a=0;
	scanf("%d",&a);
	BYTE_DT *p = (BYTE_DT*)&a;
	for(int i=sizeof(a)-1;i>=0;i--)
	{
		printf(BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(*(p+i)));
		printf(" ");
	}
	printf("\n");
	return 0;
}
