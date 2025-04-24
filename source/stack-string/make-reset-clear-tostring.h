// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


StackString makeStackString(char* address, long capacity) // developer tells the capacity
{
    if (capacity < 1) 
    {         
        printf("\nERROR: making StackString with zero or negative capacity\n"); exit(1); 
    }
    
    StackString stk = { address, address, capacity, 0 };
        
    return stk;
}

void stackStringReset(StackString* stk)
{
    stk->data = stk->address;
    
    stk->size = 0;
}

void stackStringClear(StackString* stk)
{
    stk->data = stk->address;
    
    stk->size = 0;
    
    for (long n = 0; n < stk->capacity; n++)
    {
        stk->address[n] = ' ';
    } 
}

String stackStringToVolatileString(StackString stk) 
{    
    return makeString(NULL, stk.data, stk.size);
}

