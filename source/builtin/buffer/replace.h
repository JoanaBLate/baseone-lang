// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// replace start //////////////////////////////////////////////////////////////

void bufferReplaceStart(Buffer* buffer, long count, String chunk)
{    
    if (count < 1) { count = 0; }
     
    else if (count > buffer->size) { count = buffer->size; }
      
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
    
    // increasing buffer capacity (maybe)
 
    long newCapacity = buffer->size + chunk.size;
    
    if (newCapacity > buffer->capacity) 
    {
        buffer->address = heapReallocate(buffer->address, newCapacity); // allocates memory
        
        buffer->capacity = newCapacity;
    }

    // now capacity is enough but margin is not enough: must move bytes to right
    
    long delta = chunk.size - buffer->margin;
    
    buffer->size += delta;
    
    bufferMoveRange(buffer, 1, buffer->size - delta, 1 + delta); // arguments adjusted to one base index

    buffer->size += buffer->margin;
    
    buffer->margin = 0;
    
    // pasting the chunk
    
    memcpy(buffer->address, chunk.address, chunk.size);
}

// replace end ////////////////////////////////////////////////////////////////

void bufferReplaceEnd(Buffer* buffer, long count, String chunk)
{    
    if (count < 1) { count = 0; } 
    
    else if (count > buffer->size) { count = buffer->size; }
      
    // eating the end
    buffer->size -= count;
    
    long hiddenTail = buffer->capacity - buffer->margin - buffer->size;
    
    if (chunk.size <= hiddenTail)
    {        
        memcpy(buffer->address + buffer->margin + buffer->size, chunk.address, chunk.size);
        
        buffer->size += chunk.size;
        
        return;    
    }
    
    // increasing buffer capacity (maybe)
 
    long newCapacity = buffer->size + chunk.size;
    
    if (newCapacity > buffer->capacity) 
    {
        buffer->address = heapReallocate(buffer->address, newCapacity); // allocates memory
        
        buffer->capacity = newCapacity;
    }
  
    // now capacity is enough
    
    hiddenTail = buffer->capacity - buffer->margin - buffer->size;
    
    long delta = chunk.size - hiddenTail;
    
    if (delta == 0) // no need to displace data
    {
        memcpy(buffer->address + buffer->margin + buffer->size, chunk.address, chunk.size);
        
        buffer->size += chunk.size;
    
        return;    
    }     
    
    // must use the margin: moving bytes to left
    
    long position = buffer->margin + buffer->size - delta;
        
    buffer->margin -= delta;
    
    buffer->size += delta;
  
    bufferMoveRange(buffer, 1 + delta, buffer->size, 1); // arguments adjusted to one base index

    memcpy(buffer->address + position, chunk.address, chunk.size);
    
    buffer->size += chunk.size - delta;
}

// replace target once ////////////////////////////////////////////////////////

bool _bufferReplace(Buffer* buffer, String target, String chunk, long relativePosition) // may allocate heap memory
{
    if (relativePosition == -1) { return false; } // target not found
    
    long absolutePosition = buffer->margin + relativePosition;
    
    // just enough room
    if (target.size == chunk.size) 
    {
        memcpy(buffer->address + absolutePosition, chunk.address, chunk.size);
        
        return true;    
    }
    
    // more than enough room
    if (target.size > chunk.size) 
    {
        memcpy(buffer->address + absolutePosition, chunk.address, chunk.size);
        
        long delta = target.size - chunk.size;
        long start = absolutePosition + chunk.size;
        long off = buffer->margin + buffer->size - delta;
        
        for (long index = start; index < off; index++)
        {
            buffer->address[index] = buffer->address[index + delta];
        }
        
        buffer->size -= delta;

        return true;    
    }
    
    // expanding the buffer (maybe)    
    long neededSpace = chunk.size - target.size;
    
    long hiddenSpace = buffer->capacity - buffer->size;
    
    long neededExpansion = neededSpace - hiddenSpace;
 
    if (neededExpansion > 0)
    {
        long newCapacity = buffer->capacity + neededExpansion;
        
        buffer->address = heapReallocate(buffer->address, newCapacity); // allocates heap memory
            
        buffer->capacity = newCapacity;
    }
     
    // moving to the right (maybe)    
    long hiddenTail = buffer->capacity - buffer->margin - buffer->size;  
    
    long deltaRight = neededSpace;
    
    if (deltaRight > hiddenTail) { deltaRight = hiddenTail; }

    if (deltaRight > 0)
    {
        buffer->size += deltaRight;
        
        long a = relativePosition + target.size;
        
        long b = a + deltaRight;
      
        bufferMoveRange(buffer, a + 1, buffer->size, b + 1); // arguments adjusted to one base index
        
        neededSpace -= deltaRight;
    }
    
    // moving to the left (maybe)
    long deltaLeft = neededSpace;
    
 // if (deltaLeft > buffer->margin) { deltaLeft = buffer->margin; } // unnecessary
    
    if (deltaLeft > 0)
    {
        buffer->margin -= deltaLeft;
        
        buffer->size += deltaLeft;
      
        bufferMoveRange(buffer, 1 + deltaLeft, buffer->size, 1); // arguments adjusted to one base index
    
        absolutePosition -= deltaLeft;
    }
    
    // copyng the chunk
    memcpy(buffer->address + absolutePosition, chunk.address, chunk.size);
    
    return true;
}
   
bool bufferReplace(Buffer* buffer, String target, String chunk) // may allocate heap memory
{
    long position = bufferIndexOf(*buffer, target) - 1; // '-1' adjusts to zero index
    
    return _bufferReplace(buffer, target, chunk, position);
}

bool bufferReplaceLast(Buffer* buffer, String target, String chunk) // may allocate heap memory
{
    long position = bufferLastIndexOf(*buffer, target) - 1; // '-1' adjusts to zero index
    
    return _bufferReplace(buffer, target, chunk, position);
}

// replace target all /////////////////////////////////////////////////////////

void _bufferExpandBeforeReplaceAll(Buffer* buffer, String target, String chunk, long count) // may allocate heap memory
{
    if (target.size >= chunk.size) { return; }
    
    long neededSpace = count * (chunk.size - target.size);
    
    long hiddenSpace = buffer->capacity - buffer->size;
    
    long neededExpansion = neededSpace - hiddenSpace;
    
    if (neededExpansion <= 0) { return; }

    long newCapacity = buffer->capacity + neededExpansion;
    
    buffer->address = heapReallocate(buffer->address, newCapacity); // allocates heap memory
        
    buffer->capacity = newCapacity;
}

bool bufferReplaceAll(Buffer* buffer, String target, String chunk) // may allocate heap memory
{
    long count = bufferCountOf(*buffer, target);
    
    if (count == 0) { return false; }
    
     _bufferExpandBeforeReplaceAll(buffer, target, chunk, count);
     
     while (bufferReplace(buffer, target, chunk)) { }
     
     return true;
}

