#include "master.h"

int main()
{
	/* PATH BUFFER */
	char filename[256];
	
	printf("Enter file path: ");
	scanf("%255s", filename); /* READ PATH */
	FILE *file = open_binary_file(expand_path(filename)); /* OPEN FILE BASED ON THE EXTENDED PATH */
	if(!file)/* IF FILE NULL */
	{
		/* PRINTS/PUTS ERROR IN STDERR */
		perror("Error opening file");
	}
	
	unsigned char buffer[BYTES_PER_LINE];
	size_t bytes_read;
	long offset = 0;
	while( (bytes_read = fread(buffer, 1, BYTES_PER_LINE, file)) > 0 )
	{
		print_hex_line(buffer,bytes_read,offset);
		offset += bytes_read;
	}
	fclose(file);
	return 0;
}
