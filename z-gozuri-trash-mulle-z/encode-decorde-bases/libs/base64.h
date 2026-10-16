#ifndef BASE64_H
#define BASE64_H

#include "../master.h"  // for size_t

#ifdef __cplusplus
extern "C" {
#endif

char* base64_encode(const unsigned char* data, size_t input_length, size_t* output_length);
char* base64_decode(const char* input, size_t input_length, size_t* output_length);

#ifdef __cplusplus
}
#endif

#endif // BASE64_H
