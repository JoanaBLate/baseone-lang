// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

// why using 'long' for sizes instead of 'unsigned long' (size_t)?
//   'long' is big enough (half of the adressable memory)
//   unsigned integers are more complicated to handle (logical comparison with negative numbers)
//   BaseOne builtin functions assure that size/capacity/length will never get negative value
//   while this is about the inner C code, it follows the BaseOne principle: there is no 'unsigned'

typedef unsigned short byte;

typedef unsigned short bool;

const unsigned short true = 1;
const unsigned short false = 0;

typedef struct
{
    long value;
    bool isNull;
} NullLong;

typedef struct 
{
    char* address; 
    long size;
} String;

typedef struct 
{
    char* address; 
    long capacity;
    long margin;
    long size;
} StringBuffer;

// creating ///////////////////////////////////////////////////////////////////

NullLong createNullLong()
{
    NullLong number = { 0, true };
    
    return number;
}

NullLong createNullableLong(long value, bool isNull)
{
    NullLong number = { value, isNull };
    
    return number;
}


