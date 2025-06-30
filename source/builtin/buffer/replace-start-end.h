// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// replace start //////////////////////////////////////////////////////////////

void bufferReplaceStart(Buffer* buffer, long count, String* chunk)
{    
    if (count < 1) { count = 0; }
     
    else if (count > buffer->size) { count = buffer->size; }
      
    // eating the start
    buffer->size -= count;
    buffer->margin += count; 
    
    if (chunk->size <= buffer->margin)
    {        
        buffer->margin -= chunk->size;
        
        memcpy(buffer->address + buffer->margin, chunk->address, chunk->size);
        
        buffer->size += chunk->size;

        return;    
    }
    
    bufferMaybeExpandCapacity(buffer, chunk->size);
    
    // now capacity is enough but margin is not enough: must move bytes to right
    
    long delta = chunk->size - buffer->margin;
    
    buffer->size += delta;
    
    bufferMoveRange(buffer, 1, buffer->size - delta, 1 + delta); // arguments adjusted to one base index

    buffer->size += buffer->margin;
    
    buffer->margin = 0;
    
    // pasting the chunk
    
    memcpy(buffer->address, chunk->address, chunk->size);
}

// replace end ////////////////////////////////////////////////////////////////

void bufferReplaceEnd(Buffer* buffer, long count, String* chunk)
{    
    if (count < 1) { count = 0; } 
    
    else if (count > buffer->size) { count = buffer->size; }
      
    // eating the end
    buffer->size -= count;
    
    long hiddenTail = buffer->capacity - buffer->margin - buffer->size;
    
    if (chunk->size <= hiddenTail)
    {        
        memcpy(buffer->address + buffer->margin + buffer->size, chunk->address, chunk->size);
        
        buffer->size += chunk->size;
        
        return;    
    }
    
    bufferMaybeExpandCapacity(buffer, chunk->size);
        
    hiddenTail = buffer->capacity - buffer->margin - buffer->size;
    
    long delta = chunk->size - hiddenTail;
    
    if (delta == 0) // no need to displace data
    {
        memcpy(buffer->address + buffer->margin + buffer->size, chunk->address, chunk->size);
        
        buffer->size += chunk->size;
    
        return;    
    }     
    
    // must use the margin: moving bytes to left
    
    long position = buffer->margin + buffer->size - delta;
        
    buffer->margin -= delta;
    
    buffer->size += delta;
  
    bufferMoveRange(buffer, 1 + delta, buffer->size, 1); // arguments adjusted to one base index

    memcpy(buffer->address + position, chunk->address, chunk->size);
    
    buffer->size += chunk->size - delta;
}

