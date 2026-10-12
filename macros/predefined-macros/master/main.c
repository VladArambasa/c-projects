/* PREDEFINED MACROS: INFORMATION THE COMPILER FILLS IN BY ITSELF */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

#define TRACE() printf("[%s:%d] inside %s\n", __FILE__, __LINE__, __func__) /* WHERE AM I? */

void helper(void)
{
	TRACE();
}

int main(void)
{
	printf("File: %s\n", __FILE__);
	printf("Line: %d\n", __LINE__);
	printf("Compiled on %s at %s\n", __DATE__, __TIME__);
	printf("Standard C: %d, version %ld\n", __STDC__, __STDC_VERSION__);

	TRACE();
	helper();

#line 100 /* #LINE CHANGES THE LINE NUMBER THE COMPILER REPORTS */
	printf("Line after #line 100: %d\n", __LINE__);

	return 0;
}
