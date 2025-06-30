// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


bool bufferMaybeExpandCapacity(Buffer* buffer, long neededSpace) // may allocate heap memory
{
    long hiddenSpace = buffer->capacity - buffer->size;
    
    long neededExpansion = neededSpace - hiddenSpace;
 
    if (neededExpansion <= 0) { return false; }

    long newCapacity = buffer->capacity + neededExpansion;
    
    buffer->address = heapReallocate(buffer->address, newCapacity); // allocates heap memory
        
    buffer->capacity = newCapacity;
    
    return true;
}
     
