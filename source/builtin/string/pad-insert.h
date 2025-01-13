// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

String createAppendedString(String *string, String *chunk)
{    
    if (string->size == 0) { return createStringClone(chunk); }
    
    if (chunk->size == 0) { return createStringClone(string); }
    
    long bufferSize = string->size + chunk->size;
    
    char *buffer = memoryAllocate(bufferSize);
    
    memcpy(buffer, string->data, string->size);
    
    memcpy(&buffer[string->size], chunk->data, chunk->size);
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createInsertedString(String *string, String *chunk, long position) // one base index
{
    if (string->size == 0) { return createStringClone(chunk); }
    
    if (chunk->size == 0) { return createStringClone(string); }
    
    if (position <= 1) { return createAppendedString(chunk, string); }

    if (position > string->size) { return createAppendedString(string, chunk); }
    
    position -= 1;
    
    long bufferSize = string->size + chunk->size;
    
    char *buffer = memoryAllocate(bufferSize);

    for (long index = 0; index < position; index++) { buffer[index] = string->data[index]; }

    for (long index = 0; index < chunk->size; index++) { buffer[position + index] = chunk->data[index]; }

    for (long index = position; index < string->size; index++) { buffer[index + chunk->size] = string->data[index]; }
    
    String newString = { bufferSize, buffer };

    return newString;
}

String createPaddedStartString(String *string, String *chunk, long count)
{
    if (count < 1) { return createStringClone(string); }
    
    if (chunk->size == 0) { return createStringClone(string); }
    
    long bufferSize = (count * chunk->size) + string->size;
            
    char *buffer = memoryAllocate(bufferSize);
    
    long index = -1;
    
    while (count > 0) {
    
        count -= 1;
        
        for (long n = 0; n < chunk->size; n++) {
    
            index += 1;
            
            buffer[index] = chunk->data[n];
        }
    }
    
    memcpy(&buffer[index + 1], string->data, string->size);
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createPaddedEndString(String *string, String *chunk, long count)
{
    if (count < 1) { return createStringClone(string); }
    
    if (chunk->size == 0) { return createStringClone(string); }
    
    long bufferSize = (count * chunk->size) + string->size;
            
    char *buffer = memoryAllocate(bufferSize);
    
    memcpy(buffer, string->data, string->size);
    
    long index = string->size - 1;
    
    while (count > 0) {
    
        count -= 1;
        
        for (long n = 0; n < chunk->size; n++) {
    
            index += 1;
            
            buffer[index] = chunk->data[n];
        }
    }
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

