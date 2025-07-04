// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// function 'createStringFromLong' is in file 'create-from-release.h'

NullLong stringParseLong(String* string)
{   
    int signal = 0; // zero means sinal is not found yet and number has not started
    
    long cursor = -1;
    
    long start = -1;
    
    while (true)
    {
        cursor += 1;
        
        if (cursor == string->size) { break; }
        
        unsigned char c = string->address[cursor];
        
        if (c == ' ') // whitespace
        {
            if (start  != -1) { break; } // whitespace after digit
            if (signal !=  0) { break; } /// whitespace after signal
            continue;
        }
        
        if (c == '-')
        {
            if (signal != 0) { break; } else { signal = -1; continue; }        
        }
        
        if (c == '+')
        {
            if (signal != 0) { break; } else { signal = 1; continue; }        
        }
        
        if (c < '0'  ||  c > '9') { break; } // not digit
        
        if (start == -1)
        {
            start = cursor;
            
            if (signal == 0) { signal = 1; }
        }
    }
    
    if (start == -1)
    {
        NullLong result = { 0, true };
        
        return result;
    }
    
    long end = cursor - 1;
    
    long value = 0;
    
    long factor = 1;

    for (int index = end; index >= start; index--) // runs backwards
    {
        value += (string->address[index] - '0') * factor;
        
        factor *= 10;
    }
      
    NullLong result = { signal * value, false };
        
    return result;
}

