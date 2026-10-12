/* LIMITS.H AND FLOAT.H: THE SMALLEST AND LARGEST VALUE OF EACH TYPE ON THIS MACHINE */
#include "master.h" /* ALL THE HEADERS, IN ONE PLACE */

int main(void)
{
	printf("char          : %d to %d\n", CHAR_MIN, CHAR_MAX);
	printf("unsigned char : 0 to %d\n", UCHAR_MAX);
	printf("short         : %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("int           : %d to %d\n", INT_MIN, INT_MAX);
	printf("unsigned int  : 0 to %u\n", UINT_MAX);
	printf("long long     : %lld to %lld\n", LLONG_MIN, LLONG_MAX);
	printf("float         : up to %e, %d exact digits\n", FLT_MAX, FLT_DIG);
	printf("double        : up to %e, %d exact digits\n", DBL_MAX, DBL_DIG);
	printf("float epsilon : %e (smallest step after 1.0)\n", FLT_EPSILON);

	return 0;
}
