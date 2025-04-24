// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


NullLong _stringEatLongInt(String* string, int signal) // expected to start with digit!!!
{   
    char* digits = string->data;
    
    int length = 0;
    
    while (true)
    {
        if (string->size == 0) { break; }
        
        if (string->data[0] < '0') { break; }
        if (string->data[0] > '9') { break; }
        
        length += 1;

        string->data += 1; string->size -= 1;
    }             

    long result = 0;
    long factor = 1;

    for (int index = length; index > 0; index--)
    {
        result += (digits[index - 1] - '0')*  factor;
        
        factor *= 10;
    }

    return createNullableLong(signal*  result, false);
}  

NullLong stringEatLongInt(String* string) // trims leading whitespaces
{   
    while (string->size != 0) 
    {
        if (string->data[0] == ' ') { string->data += 1; string->size -= 1; } else { break; }
    }
    
    if (string->size == 0) { return createNullLong(); }
    
    char first = (unsigned char) string->data[0];
    
    if (string->size == 1)
    {
        if (first < '0') { return createNullLong(); }
        if (first > '9') { return createNullLong(); }
    
        return createNullableLong(first - '0', false);
    }
    
    int signal = 0;
    
    if (first == '-') { signal = -1; } else if (first == '+') { signal = +1; }
    
    if (signal != 0)
    {
        if (string->data[1] < '0') { return createNullLong(); }
        if (string->data[1] > '9') { return createNullLong(); }
                
        string->data += 1; string->size -= 1; // eating the signal
    }
    
    if (signal == 0) { signal = 1; }
    
    return _stringEatLongInt(string, signal);
}

