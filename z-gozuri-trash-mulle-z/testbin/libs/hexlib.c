#include "../master.h"

/* PRINT ONE LINE: OFFSET | HEX | ASCII */
void print_hex_line (unsigned char *buffer, int bytes_read, long offset)
{
	/* PRINT OFFSET IN HEX */
	printf("%08lX ", offset);
	
	for(int i = 0; i < BYTES_PER_LINE; i++) /* FOR BYTES_PER LINE */
	{
		if(i < bytes_read)
		{
			/* PRINT BYTE IN HEX */
			printf("%02X ", buffer[i]);
		}
		else
		{
			/* PAD IF FEWER BYTES */
			printf(".. ");
		}
		if (i == 7)
		{
			/* EXTRA SPACE AFTER 8 BYTES */
			printf(" ");
		}
	}
	/* START ASCII BLOCK */
	printf(" |");
	for(int i = 0; i < bytes_read; i++)
	{
		/* PRINT CHAR OR DOT */
		printf("%c", isprint(buffer[i]) ? buffer[i] : '.');
		/* isprint() CHECKS IF CHAR CAN BE PRINTED */
		/* inline TEST CHECKS IF BUFFER[I] CAN BE PRINTED. 
		 * IF YES -> PRINT BUFFER[I], 
		 * OTHERWISE, PRINT DOT
		 * */
	}
	/* PRINT END LINE */
	printf("|\n"); 
	
}

