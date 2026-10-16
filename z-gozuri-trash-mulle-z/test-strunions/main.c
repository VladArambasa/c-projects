#include <stdio.h>

/* DEFINED A UNION WITH AN INT AND 8 BITS IN A STRUCT , I.E. A BITFIELD FOR A BYTE */
union {
    int a;
    struct { 
        unsigned b0 : 1;
        unsigned b1 : 1;
        unsigned b2 : 1;
        unsigned b3 : 1;
        unsigned b4 : 1;
        unsigned b5 : 1;
        unsigned b6 : 1;
        unsigned b7 : 1;
        unsigned b8 : 1;
    } bits;
} UNI;

/* BINARY PRINT --- THE SMART-ISH WAY */
void print_binary(unsigned char n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int main() {
    UNI.a = 245; /* IN BINARY: 11110101 */

    printf("Binary of UNI.a: ");
    print_binary(UNI.a & 0xFF); /* MASKING TO LOWER 8 BITS */
    /* I.E. ALL THE OTHER BITS, SAVE FOR THE LOWER 8 WILL BE 0 */
    /* 0XFF = 1111 1111 */
    /* WHEN WE BIT-AND IT TO A VALUE, ITS TAKEN AS: 0000 0000  0000 0000  0000 0000  1111 1111.
     * BIT BY BIT, WE KEEP ONLY THE LOWER 8, AS THE OTHERS ARE ZEROED OUT */

    printf("Bitfields (b0 = LSB):\n");
    printf("b0 = %u\n", UNI.bits.b0);
    printf("b1 = %u\n", UNI.bits.b1);
    printf("b2 = %u\n", UNI.bits.b2);
    printf("b3 = %u\n", UNI.bits.b3);
    printf("b4 = %u\n", UNI.bits.b4);
    printf("b5 = %u\n", UNI.bits.b5);
    printf("b6 = %u\n", UNI.bits.b6);
    printf("b7 = %u\n", UNI.bits.b7);
    printf("b8 = %u\n", UNI.bits.b8);
    /* WILL BE 0 AS WE OCCUPY 4 BYTES (AN INT) IN THE UNION */
    return 0;
}
