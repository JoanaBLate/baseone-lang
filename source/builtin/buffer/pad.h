// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void bufferPadStart(Buffer* buffer, String* chunk, long count)
{
    long padLength = count * chunk->size;
        
    if (padLength < 1) { return; }
    
    bufferMaybeExpandCapacity(buffer, padLength);

    buffer->size += padLength;
    
    if (buffer->margin >= padLength)
    {
        buffer->margin -= padLength;
    }
    else
    {
        long deltaRight = padLength - buffer->margin;
        
        bufferMoveRange(buffer, 1, buffer->size, 1 + deltaRight); // adjusted to one base index
        
        buffer->margin = 0;
    }
    for (long n = 0; n < count; n++)
    {
        long start = buffer->margin + (n * chunk->size);
    
        for (long index = 0; index < chunk->size; index++) { buffer->address[start + index] = chunk->address[index]; }
    }
}

/*

String createStringPadEnd(String string, String chunk, long count)
{
    if (count < 1) { return createStringClone(string); }
    
    if (chunk->size == 0) { return createStringClone(string); }
    
    long bufferSize = (count * chunk->size) + string.size;
            
    char* buffer = heapAllocate(bufferSize);
    
    memcpy(buffer, string.address, string.size);
    
    long index = string.size - 1;
    
    while (count > 0) {
    
        count -= 1;
        
        for (long n = 0; n < chunk->size; n++) {
    
            index += 1;
            
            buffer[index] = chunk->address[n];
        }
    }
    
    return makeString(buffer, bufferSize);
}
*/
