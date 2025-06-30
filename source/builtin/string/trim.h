// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


String stringTrimStart(String* string) // allocates heap memory
{
    long margin = 0;
    long size = string->size;

    while (true)
    {
        if (size == 0) { return makeStringEmpty(); }
        
        if ((unsigned char) string->address[margin] > ' ') { break; }
        
        margin += 1; size -= 1;
    }
    
    return createStringFromSource(string->address + margin, size);
}

String stringTrimEnd(String* string) // allocates heap memory
{
    long size = string->size;
    
    while (true)
    {
        if (size == 0) { return makeStringEmpty(); }
        
        long index = size - 1;
        
        if ((unsigned char) string->address[index] > ' ') { break; }
    
        size -= 1;          
    }
    
    return createStringFromSource(string->address, size);
}

String stringTrim(String* string) // allocates heap memory
{
    long margin = 0;
    long size = string->size;
    
    while (true) // trims end
    {
        if (size == 0) { return makeStringEmpty(); }
        
        long index = size - 1;
        
        if ((unsigned char) string->address[index] > ' ') { break; }
    
        size -= 1;          
    }

    while (true) // trims start
    {
        if (size == 0) { return makeStringEmpty(); } // probably not necessary
        
        if ((unsigned char) string->address[margin] > ' ') { break; }
        
        margin += 1; size -= 1;
    }
    
    return createStringFromSource(string->address + margin, size);
}

