// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


String* newStringAppend(String* string, String* chunk) // allocates memory
{    
    if (string->size == 0) { return newStringClone(chunk); }
    
    if (chunk->size == 0) { return newStringClone(string); }
    
    long bufferSize = string->size + chunk->size;
    
    char* buffer = allocateMemory(bufferSize);
    
    memcpy(buffer, string->data, string->size);
    
    memcpy(&buffer[string->size], chunk->data, chunk->size);
    
    return makeString(buffer, bufferSize);
}

String* newStringInsert(String* string, String* chunk, long position) // allocates memory // one base index
{
    if (string->size == 0) { return newStringClone(chunk); }
    
    if (chunk->size == 0) { return newStringClone(string); }
    
    if (position <= 1) { return newStringAppend(chunk, string); }

    if (position > string->size) { return newStringAppend(string, chunk); }
    
    position -= 1;
    
    long bufferSize = string->size + chunk->size;
    
    char* buffer = allocateMemory(bufferSize);

    for (long index = 0; index < position; index++) { buffer[index] = string->data[index]; }

    for (long index = 0; index < chunk->size; index++) { buffer[position + index] = chunk->data[index]; }

    for (long index = position; index < string->size; index++) { buffer[index + chunk->size] = string->data[index]; }
    
    return makeString(buffer, bufferSize);
}

