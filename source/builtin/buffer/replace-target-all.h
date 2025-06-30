// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// replace target once ////////////////////////////////////////////////////////

bool _bufferReplace(Buffer* buffer, String* target, String* chunk, long relativePosition) // may allocate heap memory
{
    if (relativePosition == -1) { return false; } // target not found
    
    long absolutePosition = buffer->margin + relativePosition;
    
    // just enough room
    if (target->size == chunk->size) 
    {
        memcpy(buffer->address + absolutePosition, chunk->address, chunk->size);
        
        return true;    
    }
    
    // more than enough room
    if (target->size > chunk->size) 
    {
        memcpy(buffer->address + absolutePosition, chunk->address, chunk->size);
        
        long delta = target->size - chunk->size;
        long start = absolutePosition + chunk->size;
        long off = buffer->margin + buffer->size - delta;
        
        for (long index = start; index < off; index++)
        {
            buffer->address[index] = buffer->address[index + delta];
        }
        
        buffer->size -= delta;

        return true;    
    }

    long neededSpace = chunk->size - target->size;
    
    bufferMaybeExpandCapacity(buffer, neededSpace);
    
    // moving to the right (maybe)    
    long hiddenTail = buffer->capacity - buffer->margin - buffer->size;  
    
    long deltaRight = neededSpace;
    
    if (deltaRight > hiddenTail) { deltaRight = hiddenTail; }

    if (deltaRight > 0)
    {
        buffer->size += deltaRight;
        
        long a = relativePosition + target->size;
        
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
    memcpy(buffer->address + absolutePosition, chunk->address, chunk->size);
    
    return true;
}
   
bool bufferReplace(Buffer* buffer, String* target, String* chunk) // may allocate heap memory
{
    long position = bufferIndexOf(buffer, target) - 1; // '-1' adjusts to zero index
    
    return _bufferReplace(buffer, target, chunk, position);
}

bool bufferReplaceLast(Buffer* buffer, String* target, String* chunk) // may allocate heap memory
{
    long position = bufferLastIndexOf(buffer, target) - 1; // '-1' adjusts to zero index
    
    return _bufferReplace(buffer, target, chunk, position);
}

// replace target all /////////////////////////////////////////////////////////

bool bufferReplaceAll(Buffer* buffer, String* target, String* chunk) // may allocate heap memory
{
    long count = bufferCountOf(buffer, target);
    
    if (count == 0) { return false; }
    
    if (target->size < chunk->size)
    {
        long neededSpace = count * (chunk->size - target->size);
    
        bufferMaybeExpandCapacity(buffer, neededSpace);
    }
     
     while (bufferReplace(buffer, target, chunk)) { }
     
     return true;
}

