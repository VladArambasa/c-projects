#ifndef BIG512_H
#define BIG512_H

/* DEFINES - HEADER WISE */
#define BIG512_WORDS 8 /* BYTES FOR 512-bits */

/* STRUCTS - HEADER WISE */
typedef struct
{
	uint64_t words[BIG512_WORDS];
}uint512_t;

/* CONSTRUCTORS */
uint512_t uint512_from_uint64(uint64_t val);
uint512_t uint512_from_hex(const char *str_arg);
uint512_t uint512_from_dec(const char *str_arg);
uint512_t uint512_from_bin(const char *str_arg);

/* ARITHMETIC */
uint512_t uint512_add (uint512_t arg_a, uint512_t arg_b);
uint512_t uint512_sub(uint512_t arg_a, uint512_t arg_b);
uint512_t uint512_mul(uint512_t arg_a, uint512_t arg_b);
uint512_t uint512_div(uint512_t arg_a, uint512_t arg_b);

/* COMPARISON */
uint512_t uint512_t_eq (uint512_t arg_a, uint512_t arg_b);
uint512_t uint512_t_neq (uint512_t arg_a, uint512_t arg_b);
uint512_t uint512_t_geq (uint512_t arg_a, uint512_t arg_b);
uint512_t uint512_t_leq (uint512_t arg_a, uint512_t arg_b);
uint512_t uint512_t_grt (uint512_t arg_a, uint512_t arg_b);
uint512_t uint521_t_les (uint512_t arg_a, uint512_t arg_b);

/* OUTPUT */
void uint512_t_print_dec (uint512_t arg);
void uint512_t_print_hex (uint512_t arg);
void uint512_t_print_bin (uint512_t arg);

#endif
