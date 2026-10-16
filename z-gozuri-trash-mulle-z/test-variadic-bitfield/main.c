#include <stdio.h>
#include <stdbool.h> /* NEEDED FOR BOOL FOR SOME REASON */
#include <stdarg.h> /* NEEDED FOR VARIARGS */

typedef union numer {
	struct {
		unsigned char b1 : 1;
		unsigned char b2 : 1;
		unsigned char b3 : 1;
		unsigned char b4 : 1;
		unsigned char b5 : 1;
		unsigned char b6 : 1;
		unsigned char b7 : 1;
		unsigned char b8 : 1;
		/* IF YOU WRITE SOMETHING LIKE:
		 * unsigned char  : 2;
		 * IT MEANS YOU HAVE 2 BITS YOU MAY NOT ACCESS. 
		 * THEY ARE BLOCKED */
	} bytes;
	unsigned char val;
} nb;

void print_bin(unsigned char arg) {
	for (int i = 7; i >= 0; i--) {
		printf("%d", (arg >> i) & 1);/* SMART WAY OF PRINTING THEM IN BINARY */
	}
	printf("\n");
}

void variac(bool opt, ...) {
	va_list args; /* VARIARGS LIST */
	va_start(args, opt);
	unsigned int value = va_arg(args, unsigned int); /* PROMOTED TO UNSIGNED INT */
	/* VA_ARGS PROMOTES THEM AUTOMATICALLY (CHAR TO INT) */
	nb n; /* WE NEED THIS AS ONE MAY NOT RETRIEVE A UNION OR STRUCT FROM VA_LIST */
	n.val = (unsigned char)value; /* WE TAKE THE VALUE FROM IT */
	/* IDEA IS:
	 * 1. SINCE IT'S A UNION, BOTH THE STRUCT AND VAL ARE ON THE SAME BYTE
	 * 2. THE BYTE ITSELF IS BEING PROMOTED TO UNSIGNED INT
	 * 3. IT IS PASSED IN THE FUNCTION AS SUCH --- THAT BYTE
	 * 4. WE TAKE IT AND EFFECTIVELY CONVERT IT TO A NB */

	printf("Val: %d\n\n", n.val);

	if(opt == true) {
		printf("b1: %d b8: %d\n", n.bytes.b1, n.bytes.b8);
		print_bin(n.val);
		printf("Decimal: %d\n", n.val);
	} else {
		printf("%d %d %d %d %d %d %d %d\n", 
			n.bytes.b1, n.bytes.b2, n.bytes.b3, n.bytes.b4,
			n.bytes.b5, n.bytes.b6, n.bytes.b7, n.bytes.b8);
		print_bin(n.val);
		printf("Decimal: %d\n", n.val);
	}
	
	va_end(args);
}

int main() {
	nb a;
	a.val = 134; /* 10000110 */
	variac(false, a.val); /* WILL BE PROMOTED AUTOMATICALLY */
	return 0;
}
/* EXPLANATION */
/*
 * Even though nb is a typedef of a union, you cannot safely or portably retrieve a union or struct directly from va_arg. Here's why:
 * EVEN THOUGH nb IS A TYPEDEF OF A UNION, ONE MAY NOT RETRIEVE A UNION OR STRUCT DIRECTLY FROM VA_ARG.
 * #__REASONING__#:
 * ACCORDING TO THE C STANDARD (ISO C99 §7.15.1.1): 
 * 		VA_ARG ONLY WORKS WITH TYPES THAT ARE PROMOTABLE — I.E., THE DEFAULT PROMOTIONS APPLY (E.G., CHAR → INT, FLOAT → DOUBLE, ETC.).
 * 
 * ONE MAY NOT PASS OR RETRIEVE STRUCTS/UNIONS THROUGH ... DIRECTLY.
 * THEY ARE NOT PROMOTED TYPES. MOST COMPILERS WILL EITHER:
 * 		THROW A WARNING/ERROR, OR
 * 		MESS UP YOUR MEMORY LAYOUT (UNDEFINED BEHAVIOR) 
 * */
