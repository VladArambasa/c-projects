/* BINARY FILES WITH STDIO.H: FWRITE SAVES THE BYTES OF VARIABLES, FREAD LOADS THEM BACK */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

struct student
{
	char name[20];
	int grade;
};

int main(void)
{
	struct student saved[3] = {{"Ana", 10}, {"Ion", 8}, {"Maria", 9}};
	struct student loaded[3];
	struct student third;
	FILE *f;
	int i;

	f = fopen("students.bin", "wb"); /* BINARY WRITE MODE: BYTES ARE SAVED EXACTLY AS IN MEMORY */
	if (f == NULL)
	{
		printf("Cannot create students.bin\n");
		return 1;
	}
	fwrite(saved, sizeof(struct student), 3, f); /* 3 RECORDS IN ONE CALL */
	fclose(f);

	f = fopen("students.bin", "rb");
	if (f == NULL)
	{
		printf("Cannot read students.bin\n");
		return 1;
	}
	fread(loaded, sizeof(struct student), 3, f);
	for (i = 0; i < 3; i++)
	{
		printf("%s: %d\n", loaded[i].name, loaded[i].grade);
	}

	fseek(f, 2 * sizeof(struct student), SEEK_SET); /* JUMP STRAIGHT TO THE THIRD RECORD */
	fread(&third, sizeof(struct student), 1, f);
	printf("Third record: %s\n", third.name);

	fseek(f, 0, SEEK_END); /* GO TO THE END */
	printf("File size: %ld bytes\n", ftell(f)); /* THE POSITION AT THE END IS THE SIZE */
	fclose(f);

	return 0;
}
