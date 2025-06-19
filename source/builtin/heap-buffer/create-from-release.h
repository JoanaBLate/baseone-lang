// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void releaseHeapBuffer(HeapBuffer hb)
{
    heapRelease(hb.address);
}

HeapBuffer createHeapBufferEmpty() // allocates heap memory
{
    char* buffer = heapAllocate(1);
    
    HeapBuffer hb = { buffer, 1, 0, 0 };
    
    hb.address[0] = 0;
    
    return hb;
}

HeapBuffer createHeapBuffer(long capacity) // allocates heap memory
{
    if (capacity < 1) { return createHeapBufferEmpty(); }
    
    char* buffer = heapAllocate(capacity);
    
    HeapBuffer hb = { buffer, capacity, 0, 0 };
    
    return hb;
}

HeapBuffer createHeapBufferFromLiteral(char* cString) // allocates heap memory
{   
    long size = strlen(cString);
    
    long capacity = size;
    
    if (capacity < 1) { return createHeapBufferEmpty(); }
    
    char* buffer = heapAllocate(capacity);
    
    HeapBuffer hb = { buffer, capacity, 0, size };

    memcpy(buffer, cString, size);
    
    return hb;
}

HeapBuffer createHeapBufferFromString(String string) // allocates heap memory
{   
    long capacity = string.size;
    
    if (capacity < 1) { return createHeapBufferEmpty(); }
    
    char* buffer = heapAllocate(capacity);
    
    HeapBuffer hb = { buffer, capacity, 0, string.size };

    memcpy(buffer, string.address, string.size);
    
    return hb;
}

