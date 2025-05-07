#include "hash.h"
#include <stdint.h>

uint64_t hash_naive(const char *str)
{
    uint8_t *bytes = (uint_t *)str;
    uint64_t h = 5381;
    for (size_t i = 0; bytes[i] != '\0'; i++)
    {
        h = (h * 33) ^ bytes[i]; 
    }
    return (uint64_t)h;
}
