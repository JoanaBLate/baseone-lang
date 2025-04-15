// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


String* newString(char* data, long size) // allocates memory
{
    char* buffer = allocateMemory(size);

    memcpy(buffer, data, size);
    
    return makeString(buffer, size);
}

String* newStringFromCharCode(int n) // allocates memory
{   
    if (n < 0  ||  n > 255) { return makeStringEmpty(); }

    char* buffer = allocateMemory(1);

    buffer[0] = n;
    
    return makeString(buffer, 1);
}

String* newStringClone(String* string) // allocates memory
{   
    long bufferSize = string->size;
    
    if (bufferSize == 0) { return makeStringEmpty(); }
    
    char* buffer = allocateMemory(bufferSize);

    memcpy(buffer, string->data, bufferSize);
    
    return makeString(buffer, bufferSize);
}

String* newStringRepeat(String* string, long count) // allocates memory
{
    if (string->size == 0) { return makeStringEmpty(); }
    
    if (count <= 0) { return makeStringEmpty(); }
    
    long bufferSize = count * string->size;

    char* buffer = allocateMemory(bufferSize);
    
    for (long turn = 0; turn < count; turn++) 
    { 
        memcpy(&buffer[turn*  string->size], string->data, string->size); 
    }

    return makeString(buffer, bufferSize);
}

