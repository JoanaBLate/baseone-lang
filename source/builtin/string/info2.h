// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

long integerFromString(String *source) // EXPECTS TO RECEIVE A PERFECT NUMBER AS TOKEN!!!
{
    char *errorMsg = "\nERROR: in function 'integerFromString'\n";
    
    if (source->size == 0) { printf("%s", errorMsg); exit(1); }

    long signal = +1;
    
    long cursor = 0;
    
    if (source->data[0] == '-')
    {
        cursor = 1; signal = -1;    
    }
    else if (source->data[0] == '+')
    {
        cursor = 1;  signal = +1;
    }
    
    long length = 0;
    
    while (true)
    {
        if (cursor >= source->size) { break; }
    
        if (source->data[cursor] < '0') { break; }
        if (source->data[cursor] > '9') { break; }
        
        cursor += 1;
        length += 1;
    }
        
    if (length == 0) { printf("%s", errorMsg); exit(1); }
    
    // now, ready to convert
    
    long start = (signal == 0) ? 0 : 1;
    long end = cursor;
    
    long number = 0;
    long factor = 1;
    
    for (long index = end; index >= start; index--)
    {
        number += (source->data[index] - '0') * factor;
        
        factor *= 10;        
    }
    
    return (signal < 0) ? -number : number;
}

