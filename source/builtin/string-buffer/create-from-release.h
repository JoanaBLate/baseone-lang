// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void releaseStringBuffer(StringBuffer sb)
{
    heapRelease(sb.address);
}

StringBuffer createStringBuffer(long capacity) // allocates heap memory
{
    if (capacity < 1)
    { 
        printf("\nERROR: cannot create StringBuffer: capacity must be greater than zero\n"); exit(1); 
    }
    
    char* buffer = heapAllocate(capacity);
    
    StringBuffer sb = { buffer, capacity, 0, 0 };
    
    return sb;
}

StringBuffer createStringBufferFromLiteral(char* cString) // allocates heap memory
{   
    long size = strlen(cString);
    
    long capacity = size;
    
    if (capacity < 1) { capacity = 1; }
    
    char* buffer = heapAllocate(capacity);
    
    StringBuffer sb = { buffer, capacity, 0, size };

    memcpy(buffer, cString, size);
    
    return sb;
}

StringBuffer createStringBufferFromString(String string) // allocates heap memory
{   
    long capacity = string.size;
    
    if (capacity < 1) { capacity = 1; }
    
    char* buffer = heapAllocate(capacity);
    
    StringBuffer sb = { buffer, capacity, 0, string.size };

    memcpy(buffer, string.address, string.size);
    
    return sb;
}

