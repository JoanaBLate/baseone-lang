// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void stackStringAppend(StackString* stk, String string)  // doesn't extend its inner array
{    
    long stkStart = stk->size;
    
    long stkAvailable = stk->capacity - stk->size;
        
    for (long n = 0; n < string.size; n++)
    {
        if (n + 1 > stkAvailable) { break; }
        
        long stkIndex = stkStart + n;
        
        stk->address[stkIndex] = string.data[n];
        
        stk->size += 1;
    }
}

