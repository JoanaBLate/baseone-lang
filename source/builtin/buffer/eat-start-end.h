// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


String bufferEatStart(Buffer* buffer, long count)
{
    if (count < 1) { return makeStringEmpty(); }
    
    long size = count;
    
    if (size > buffer->size) { size = buffer->size; }
    
    String token = createStringFromSource(buffer->address + buffer->margin, size);
    
    buffer->margin += size; buffer->size -= size;
    
    return token;
}

String bufferEatEnd(Buffer* buffer, long count)
{
    if (count < 1) { return makeStringEmpty(); }
    
    long size = count;
    
    if (size > buffer->size) { size = buffer->size; }
    
    String token = createStringFromSource(buffer->address + buffer->margin + buffer->size - size, size);
    
    buffer->size -= size;
    
    return token;
}

