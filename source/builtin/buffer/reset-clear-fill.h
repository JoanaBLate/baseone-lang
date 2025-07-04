// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void bufferReset(Buffer* buffer)
{
    buffer->margin = 0;
    
    buffer->size = buffer->capacity;
}

void bufferClear(Buffer* buffer)
{
    for (long index = 0; index < buffer->size; index++) 
    { 
        buffer->address[buffer->margin + index] = 0;
    }
}

void bufferFill(Buffer* buffer, String* chunk)
{
    if (chunk->size == 0) { return; } // necessary
    
    long bufferIndex = -1;
    
    while (true)
    {
        for (long chunkIndex = 0; chunkIndex < chunk->size; chunkIndex++) 
        { 
            bufferIndex += 1;
            
            if (bufferIndex == buffer->size) { return; }
            
            buffer->address[buffer->margin + bufferIndex] = chunk->address[chunkIndex];
        }
    }
}

