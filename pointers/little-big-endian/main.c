#include "master.h"

int main(void)
{
	BYTE x = 1;

    // CHECK THE FIRST BYTE
    if (*(BYTE *)&x == 1)
   /*
    *		&x → GET THE ADDRESS OF x
	*		(unsigned char *)&x → TREAT THAT ADDRESS AS A POINTER TO unsigned char
	*		(unsigned char *)&x → READ THE FIRST BYTE OF x
    */
        printf("Little Endian\n");
    else
        printf("Big Endian\n");

    return 0;
}

