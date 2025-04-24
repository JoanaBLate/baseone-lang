// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


String createStringAppend(String string, String chunk) // allocates memory
{    
    if (string.size == 0) { return createStringClone(chunk); }
    
    if (chunk.size == 0) { return createStringClone(string); }
    
    long bufferSize = string.size + chunk.size;
    
    char* buffer = heapAllocate(bufferSize);
    
    memcpy(buffer, string.data, string.size);
    
    memcpy(&buffer[string.size], chunk.data, chunk.size);
    
    return makeString(buffer, buffer, bufferSize);
}

String createStringInsert(String string, String chunk, long position) // allocates memory // one base index
{
    if (string.size == 0) { return createStringClone(chunk); }
    
    if (chunk.size == 0) { return createStringClone(string); }
    
    if (position <= 1) { return createStringAppend(chunk, string); }

    if (position > string.size) { return createStringAppend(string, chunk); }
    
    position -= 1;
    
    long bufferSize = string.size + chunk.size;
    
    char* buffer = heapAllocate(bufferSize);

    for (long index = 0; index < position; index++) { buffer[index] = string.data[index]; }

    for (long index = 0; index < chunk.size; index++) { buffer[position + index] = chunk.data[index]; }

    for (long index = position; index < string.size; index++) { buffer[index + chunk.size] = string.data[index]; }
    
    return makeString(buffer, buffer, bufferSize);
}

