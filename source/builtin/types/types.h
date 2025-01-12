// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

typedef unsigned short bool;

const unsigned short true = 1;
const unsigned short false = 0;

// using size 'long' is big enough and allows easy math with indexes;
// also BaseOne string functions protect it from become negative
typedef struct {
    long size;
    char *data;    
} String;

