// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


String createString(char* data, long size) // allocates memory
{
    char* buffer = heapAllocate(size);

    memcpy(buffer, data, size);
    
    return makeString(buffer, buffer, size);
}

String createStringFromCharCode(int n) // allocates memory
{   
    if (n < 0  ||  n > 255) { return makeStringEmpty(); }

    char* buffer = heapAllocate(1);

    buffer[0] = n;
    
    return makeString(buffer, buffer, 1);
}

String createStringClone(String string) // allocates memory
{   
    long bufferSize = string.size;
    
    if (bufferSize == 0) { return makeStringEmpty(); }
    
    char* buffer = heapAllocate(bufferSize);

    memcpy(buffer, string.data, bufferSize);
    
    return makeString(buffer, buffer, bufferSize);
}

String createStringRepeat(String string, long count) // allocates memory
{
    if (string.size == 0) { return makeStringEmpty(); }
    
    if (count <= 0) { return makeStringEmpty(); }
    
    long bufferSize = count * string.size;

    char* buffer = heapAllocate(bufferSize);
    
    for (long turn = 0; turn < count; turn++) 
    { 
        memcpy(&buffer[turn * string.size], string.data, string.size); 
    }

    return makeString(buffer, buffer, bufferSize);
}

String createStringFromLong(long number) // allocates memory
{
    char array[30];
    
    sprintf(array, "%li", number);
    
    long bufferSize = strlen(array);

    char* buffer = heapAllocate(bufferSize);
    
    memcpy(buffer, array, bufferSize);

    return makeString(buffer, buffer, bufferSize);
}

String createStringFromStackString(StackString stk) // allocates memory
{   
    long bufferSize = stk.size;
    
    if (bufferSize == 0) { return makeStringEmpty(); }
    
    char* buffer = heapAllocate(bufferSize);

    memcpy(buffer, stk.data, bufferSize);
    
    return makeString(buffer, buffer, bufferSize);
}

String createStringFromBufferString(BufferString buf) // allocates memory
{   
    long bufferSize = buf.size;
    
    if (bufferSize == 0) { return makeStringEmpty(); }
    
    char* buffer = heapAllocate(bufferSize);

    memcpy(buffer, buf.data, bufferSize);
    
    return makeString(buffer, buffer, bufferSize);
}

