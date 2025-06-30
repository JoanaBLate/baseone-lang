// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void releaseBuffer(Buffer* buffer)
{
    heapRelease(buffer->address);
}

Buffer createBufferEmpty() // allocates heap memory
{
    char* address = heapAllocate(1);
    
    Buffer buffer = { address, 1, 0, 0 };
    
    buffer.address[0] = 0;
    
    return buffer;
}

Buffer createBuffer(long capacity) // allocates heap memory
{
    if (capacity < 1) { return createBufferEmpty(); }
    
    char* address = heapAllocate(capacity);
    
    Buffer buffer = { address, capacity, 0, 0 };
    
    return buffer;
}

Buffer createBufferFromLiteral(char* cString) // allocates heap memory
{   
    long size = strlen(cString);
    
    long capacity = size;
    
    if (capacity < 1) { return createBufferEmpty(); }
    
    char* address = heapAllocate(capacity);
    
    Buffer buffer = { address, capacity, 0, size };

    memcpy(buffer.address, cString, size);
    
    return buffer;
}

Buffer createBufferFromString(String string) // allocates heap memory
{   
    long capacity = string.size;
    
    if (capacity < 1) { return createBufferEmpty(); }
    
    char* address = heapAllocate(capacity);
    
    Buffer buffer = { address, capacity, 0, string.size };

    memcpy(buffer.address, string.address, string.size);
    
    return buffer;
}

