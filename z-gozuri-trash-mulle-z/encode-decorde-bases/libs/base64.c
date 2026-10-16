#include "../master.h"


static const char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char* base64_encode(const unsigned char* data, size_t input_length, size_t* output_length) {
    size_t i, j;
    size_t encoded_length = 4 * ((input_length + 2) / 3);
    char* encoded = malloc(encoded_length + 1); // +1 for null terminator
    if (!encoded) return NULL;

    for (i = 0, j = 0; i < input_length;) {
        uint32_t octet_a = i < input_length ? data[i++] : 0;
        uint32_t octet_b = i < input_length ? data[i++] : 0;
        uint32_t octet_c = i < input_length ? data[i++] : 0;

        uint32_t triple = (octet_a << 16) | (octet_b << 8) | octet_c;

        encoded[j++] = base64_table[(triple >> 18) & 0x3F];
        encoded[j++] = base64_table[(triple >> 12) & 0x3F];
        encoded[j++] = (i > input_length + 1) ? '=' : base64_table[(triple >> 6) & 0x3F];
        encoded[j++] = (i > input_length) ? '=' : base64_table[triple & 0x3F];
    }

    encoded[encoded_length] = '\0';
    if (output_length) *output_length = encoded_length;
    return encoded;
}
static const unsigned char base64_reverse_table[256] = {
    [0 ... 255] = 0x80, // mark all as invalid initially
    ['A'] = 0,  ['B'] = 1,  ['C'] = 2,  ['D'] = 3,
    ['E'] = 4,  ['F'] = 5,  ['G'] = 6,  ['H'] = 7,
    ['I'] = 8,  ['J'] = 9,  ['K'] = 10, ['L'] = 11,
    ['M'] = 12, ['N'] = 13, ['O'] = 14, ['P'] = 15,
    ['Q'] = 16, ['R'] = 17, ['S'] = 18, ['T'] = 19,
    ['U'] = 20, ['V'] = 21, ['W'] = 22, ['X'] = 23,
    ['Y'] = 24, ['Z'] = 25,
    ['a'] = 26, ['b'] = 27, ['c'] = 28, ['d'] = 29,
    ['e'] = 30, ['f'] = 31, ['g'] = 32, ['h'] = 33,
    ['i'] = 34, ['j'] = 35, ['k'] = 36, ['l'] = 37,
    ['m'] = 38, ['n'] = 39, ['o'] = 40, ['p'] = 41,
    ['q'] = 42, ['r'] = 43, ['s'] = 44, ['t'] = 45,
    ['u'] = 46, ['v'] = 47, ['w'] = 48, ['x'] = 49,
    ['y'] = 50, ['z'] = 51,
    ['0'] = 52, ['1'] = 53, ['2'] = 54, ['3'] = 55,
    ['4'] = 56, ['5'] = 57, ['6'] = 58, ['7'] = 59,
    ['8'] = 60, ['9'] = 61,
    ['+'] = 62, ['/'] = 63,
    ['='] = 0  // padding, handled separately
};

char* strip_whitespace(const char* input, size_t length, size_t* out_len) {
    char* clean = malloc(length + 1);
    if (!clean) return NULL;

    size_t j = 0;
    for (size_t i = 0; i < length; ++i) {
        if (input[i] != ' ' && input[i] != '\n' && input[i] != '\r' && input[i] != '\t') {
            clean[j++] = input[i];
        }
    }
    clean[j] = '\0';
    if (out_len) *out_len = j;
    return clean;
}


char* base64_decode(const char* input, size_t input_length, size_t* output_length) {
    if (input_length % 4 != 0) return NULL;

    size_t output_len = input_length / 4 * 3;
    if (input_length >= 2) {
        if (input[input_length - 1] == '=') output_len--;
        if (input[input_length - 2] == '=') output_len--;
    }

    char* decoded = malloc(output_len + 1); // +1 for safety null terminator
    if (!decoded) return NULL;

    size_t i, j;
    for (i = 0, j = 0; i < input_length;) {
        uint32_t sextet_a = input[i] == '=' ? 0 & i++ : base64_reverse_table[(unsigned char)input[i++]];
        uint32_t sextet_b = input[i] == '=' ? 0 & i++ : base64_reverse_table[(unsigned char)input[i++]];
        uint32_t sextet_c = input[i] == '=' ? 0 & i++ : base64_reverse_table[(unsigned char)input[i++]];
        uint32_t sextet_d = input[i] == '=' ? 0 & i++ : base64_reverse_table[(unsigned char)input[i++]];

        if ((sextet_a & 0x80) || (sextet_b & 0x80) || (sextet_c & 0x80) || (sextet_d & 0x80)) {
            free(decoded);
            return NULL; // invalid character
        }

        uint32_t triple = (sextet_a << 18) | (sextet_b << 12) | (sextet_c << 6) | sextet_d;

        if (j < output_len) decoded[j++] = (triple >> 16) & 0xFF;
        if (j < output_len) decoded[j++] = (triple >> 8) & 0xFF;
        if (j < output_len) decoded[j++] = triple & 0xFF;
    }

    decoded[output_len] = '\0';
    if (output_length) *output_length = output_len;
    return decoded;
}
