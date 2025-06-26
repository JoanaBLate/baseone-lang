// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// replace by position ////////////////////////////////////////////////////////

void bufferReplaceStart(Buffer* buffer, long count, String chunk)
{    
    if (count < 1) 
    { 
        count = 0; 
    } 
    else if (count > buffer->size) 
    { 
        count = buffer->size; 
    }
      
    // eating the start
    buffer->size -= count;
    buffer->margin += count; 
    
    if (chunk.size <= buffer->margin)
    {        
        buffer->margin -= chunk.size;
        
        memcpy(buffer->address + buffer->margin, chunk.address, chunk.size);
        
        buffer->size += chunk.size;

        return;    
    }
 
    long newCapacity = chunk.size + buffer->size;
    
    if (newCapacity > buffer->capacity) 
    {
        buffer->address = heapReallocate(buffer->address, newCapacity); // allocates memory
        
        buffer->capacity = newCapacity;
    }
    
    // now capacity is enough but margin is not enough: must move bytes (backwards)
    
    long jump = chunk.size - buffer->margin;
    
    long first = buffer->margin;
    
    long last = buffer->margin + buffer->size - 1;
        
    for (long index = last; index >= first; index--) // backwards
    {
        buffer->address[index + jump] = buffer->address[index];
    }
    
    buffer->margin = 0;
    buffer->size += chunk.size;        
    
    memcpy(buffer->address, chunk.address, chunk.size);
}

void bufferReplaceEnd(Buffer* buffer, long count, String chunk)
{    
    if (count < 1) 
    { 
        count = 0; 
    } 
    else if (count > buffer->size) 
    { 
        count = buffer->size; 
    }
      
    // eating the end
    buffer->size -= count;
    
    long hiddenEnd = buffer->capacity - buffer->margin - buffer->size;
    
    if (chunk.size <= hiddenEnd)
    {        
        memcpy(buffer->address + buffer->margin + buffer->size, chunk.address, chunk.size);
        
        buffer->size += chunk.size;
        
        return;    
    }
 
    long newCapacity = buffer->size + chunk.size;
    
    if (newCapacity > buffer->capacity) 
    {
        buffer->address = heapReallocate(buffer->address, newCapacity); // allocates memory
        
        buffer->capacity = newCapacity;
    }
    
    // now capacity is enough but hidden end space is not enough: must move bytes
    
    hiddenEnd = buffer->capacity - buffer->margin - buffer->size;
    
    long jump = chunk.size - hiddenEnd;
    
    long first = buffer->margin;
    
    long last = buffer->margin + buffer->size - 1;
    
    for (long index = first; index <= last; index++) 
    {
        buffer->address[index - jump] = buffer->address[index];
    }
    
    buffer->margin -= jump;
    
    memcpy(buffer->address + buffer->margin + buffer->size, chunk.address, chunk.size);

    buffer->size += chunk.size;        
}

// replace by target once /////////////////////////////////////////////////////

void _bufferReplace(Buffer* buffer, String target, String chunk, long relativePosition) // may allocate heap memory
{
    if (relativePosition == -1) { return; } // target not found
    
    long absolutePosition = buffer->margin + relativePosition;
    
    if (target.size == chunk.size) // just enough room
    {
        memcpy(buffer->address + absolutePosition, chunk.address, chunk.size);
        
        return;    
    }
    
    if (target.size > chunk.size) // more than enough room
    {
        memcpy(buffer->address + absolutePosition, chunk.address, chunk.size);
        
        long jump = target.size - chunk.size;
        long start = absolutePosition + chunk.size;
        long end = buffer->margin + buffer->size - 1 - jump;
        
        for (long index = start; index <= end; index++)
        {
            buffer->address[index] = buffer->address[index + jump];
        }
        
        buffer->size -= jump;

        return;    
    }
    
    // expanding the buffer (maybe)
    
    long extraSpace = chunk.size - target.size;
    
    long hiddenSpace = buffer->capacity - buffer->size;
    
    long neededExpansion = extraSpace - hiddenSpace;
    
    if (neededExpansion > 0)
    {
        long newCapacity = buffer->capacity + neededExpansion;
        
        buffer->address = heapReallocate(buffer->address, newCapacity); // allocates heap memory
            
        buffer->capacity = newCapacity;
    }
    
    // moving data to left
    
    long leftDisplacement = extraSpace;
    
    if (leftDisplacement > buffer->margin) { leftDisplacement = buffer->margin; }
    
    extraSpace -= leftDisplacement;
    
    for (long index = buffer->margin; index < absolutePosition; index++)
    {
        buffer->address[index - leftDisplacement] = buffer->address[index];    
    }
    
    buffer->margin -= leftDisplacement; 
    buffer->size   += leftDisplacement;
    
    // moving data to right
    
    long rightDisplacement = extraSpace; // ok because buffer is already extended
    
    buffer->size += rightDisplacement;
    
    for (long index = buffer->margin + buffer->size - 1; index >= absolutePosition + target.size; index--) // runs backwards
    {
        buffer->address[index] = buffer->address[index - rightDisplacement];    
    }
    
    // pasting chunk
    
    memcpy(buffer->address + absolutePosition - leftDisplacement, chunk.address, chunk.size);    
}
   
void bufferReplace(Buffer* buffer, String target, String chunk) // may allocate heap memory
{
    long position = bufferIndexOf(*buffer, target) - 1; // '-1' adjusts to zero index
    
    _bufferReplace(buffer, target, chunk, position);
}

void bufferReplaceLast(Buffer* buffer, String target, String chunk) // may allocate heap memory
{
    long position = bufferLastIndexOf(*buffer, target) - 1; // '-1' adjusts to zero index
    
    _bufferReplace(buffer, target, chunk, position);
}

// replace by target all //////////////////////////////////////////////////////

void _bufferExpandBeforeReplaceAll(Buffer* buffer, String target, String chunk, long count) // may allocate heap memory
{
    if (target.size >= chunk.size) { return; }
    
    long extraSpace = count * (chunk.size - target.size);
    
    long hiddenSpace = buffer->capacity - buffer->size;
    
    long neededExpansion = extraSpace - hiddenSpace;
    
    if (neededExpansion <= 0) { return; }

    long newCapacity = buffer->capacity + neededExpansion;
    
    buffer->address = heapReallocate(buffer->address, newCapacity); // allocates heap memory
        
    buffer->capacity = newCapacity;
}

void bufferReplaceAll(Buffer* buffer, String target, String chunk) // may allocate heap memory
{
    long count = bufferCountOf(*buffer, target);
    
    if (count == 0) { return; }
    
     _bufferExpandBeforeReplaceAll(buffer, target, chunk, count);
     
     while (true)
     {
        long position = bufferIndexOf(*buffer, target) - 1; // '-1' adjusts to zero index
        
        if (position == -1) { break; }
    
        _bufferReplace(buffer, target, chunk, position);
     }
}

