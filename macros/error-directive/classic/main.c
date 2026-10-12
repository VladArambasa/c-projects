/* #ERROR: STOP THE BUILD WITH A MESSAGE WHEN A SETTING IS WRONG */
#include <stdio.h> /* PRINTF, SNPRINTF */

#define BUFFER_SIZE 64 /* CHANGE IT TO 8 AND REBUILD TO SEE THE ERROR */

#if BUFFER_SIZE < 30 /* THE MESSAGE BELOW NEEDS 30 BYTES */
#error "BUFFER_SIZE must be at least 30"
#endif

int main(void)
{
	char buffer[BUFFER_SIZE];

	/* SNPRINTF WORKS LIKE PRINTF, BUT WRITES INTO A STRING */
	snprintf(buffer, sizeof(buffer), "A buffer of %d bytes is ready", BUFFER_SIZE);
	printf("%s\n", buffer);

	return 0;
}
