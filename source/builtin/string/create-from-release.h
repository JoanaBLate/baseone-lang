// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void releaseString(String string)
{
    if (string.address == NULL) { return; }
    
    heapRelease(string.address);
}

String createStringFromByte(int n) // allocates heap memory
{   
    if (n < 0  ||  n > 255)  
    { 
        printf("\nERROR: cannot create String from byte: bad number: %i\n", n); exit(1); 
    }

    char* buffer = heapAllocate(1);

    buffer[0] = n;
    
    return makeString(buffer, 1);
}

String createStringFromSource(char* sourceAddress, long sourceSize) // allocates heap memory
{
    long bufferSize = sourceSize;
    
    if (bufferSize == 0) { return makeStringEmpty(); }
    
    char* buffer = heapAllocate(bufferSize);

    memcpy(buffer, sourceAddress, bufferSize);
    
    return makeString(buffer, bufferSize);
}

String createStringFromLiteral(char* cString) // allocates heap memory
{
    long size = strlen(cString);
    
    return createStringFromSource(cString, size);
}

String createStringClone(String string) // allocates heap memory
{   
    return createStringFromSource(string.address, string.size);
}

String createStringFromStringBuffer(StringBuffer sb) // allocates heap memory
{   
    return createStringFromSource(sb.address + sb.margin, sb.size);
}

String createStringFromLong(long number) // allocates heap memory
{
    char array[30]; // stack allocation 
    
    sprintf(array, "%li", number);
    
    long size = strlen(array);
    
    return createStringFromSource(array, size);
}

