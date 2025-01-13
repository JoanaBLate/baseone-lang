// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

String createSubstring(String *string, long start, long count) // one base index
{
    if (count < 1) { return createEmptyString(); }
    
    start -= 1; // adjusts to zero base index
    
    long off = start + count;
    
    if (off > string->size) { off = string->size; }
    
    if (start < 0) { start = 0; }
    
    long bufferSize = off - start;
    
    if (bufferSize <= 0) { return createEmptyString(); }
    
    char *buffer = memoryAllocate(bufferSize);

    for (long index = 0; index < bufferSize; index++) { buffer[index] = string->data[start + index]; }
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createStringStart(String *string, long count)
{    
    return createSubstring(string, 1, count);
}

String createStringEnd(String *string, long count)
{    
    if (count < 1) { return createEmptyString(); }
    
    long start = string->size - count + 1;
    
    return createSubstring(string, start, count);
}

