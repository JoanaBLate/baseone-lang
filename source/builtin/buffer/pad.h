// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void bufferPadStart(Buffer* buffer, String* chunk, long count)
{
    long padLength = count * chunk->size;
        
    if (padLength < 1) { return; }
    
    bufferMaybeExpandCapacity(buffer, padLength);

    if (buffer->margin >= padLength)
    {
        buffer->margin -= padLength;
        
        buffer->size += padLength;
    }
    else
    {
        long deltaRight = padLength - buffer->margin;
        
        long origin = buffer->margin + 1; // one base index
        
        long length = buffer->size;
        
        long destiny = origin + deltaRight; // one base index

        buffer->margin = 0;
        
        buffer->size += padLength;
        
        bufferMoveRange(buffer, origin, length, destiny);
    }
    
    for (long n = 0; n < count; n++)
    {
        long start = buffer->margin + (n * chunk->size);
    
        for (long index = 0; index < chunk->size; index++) { buffer->address[start + index] = chunk->address[index]; }
    }
}

void bufferPadEnd(Buffer* buffer, String* chunk, long count)
{
    long padLength = count * chunk->size;
        
    if (padLength < 1) { return; }
    
    bufferMaybeExpandCapacity(buffer, padLength);
    
    long hiddenTail = buffer->capacity - buffer->margin - buffer->size;
    
    if (hiddenTail >= padLength)
    {
        buffer->size += padLength;
    }
    else
    {
        long length = buffer->size;
        
        long deltaLeft = padLength - hiddenTail;
        
        buffer->margin -= deltaLeft;

        buffer->size += deltaLeft; // temporary
        
        long origin = 1 + deltaLeft; // one base index
        
        long destiny = 1; // one base index
        
        bufferMoveRange(buffer, origin, length, destiny);

        buffer->size = length + padLength; // definitive
    }
   
    for (long n = 0; n < count; n++)
    {
        long start = buffer->margin + buffer->size - padLength + (n * chunk->size);
  
        for (long index = 0; index < chunk->size; index++) { buffer->address[start + index] = chunk->address[index]; }
    }
}

