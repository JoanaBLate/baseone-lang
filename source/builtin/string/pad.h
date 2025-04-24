// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


String createStringPadStart(String string, String chunk, long count)
{
    if (count < 1) { return createStringClone(string); }
    
    if (chunk.size == 0) { return createStringClone(string); }
    
    long bufferSize = (count * chunk.size) + string.size;
            
    char* buffer = heapAllocate(bufferSize);
    
    long index = -1;
    
    while (count > 0) {
    
        count -= 1;
        
        for (long n = 0; n < chunk.size; n++) {
    
            index += 1;
            
            buffer[index] = chunk.data[n];
        }
    }
    
    memcpy(&buffer[index + 1], string.data, string.size);
    
    return makeString(buffer, buffer, bufferSize);
}

String createStringPadEnd(String string, String chunk, long count)
{
    if (count < 1) { return createStringClone(string); }
    
    if (chunk.size == 0) { return createStringClone(string); }
    
    long bufferSize = (count * chunk.size) + string.size;
            
    char* buffer = heapAllocate(bufferSize);
    
    memcpy(buffer, string.data, string.size);
    
    long index = string.size - 1;
    
    while (count > 0) {
    
        count -= 1;
        
        for (long n = 0; n < chunk.size; n++) {
    
            index += 1;
            
            buffer[index] = chunk.data[n];
        }
    }
    
    return makeString(buffer, buffer, bufferSize);
}

