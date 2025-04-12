// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

String createStringSub(String *string, long start, long count) // one base index
{
    if (count < 1) { return makeStringEmpty(); }
    
    start -= 1; // adjusts to zero base index
    
    long off = start + count;
    
    if (off > string->size) { off = string->size; }
    
    if (start < 0) { start = 0; }
    
    long bufferSize = off - start;
    
    if (bufferSize <= 0) { return makeStringEmpty(); }
    
    char *buffer = allocateMemory(bufferSize);

    for (long index = 0; index < bufferSize; index++) { buffer[index] = string->data[start + index]; }
    
    return makeString(buffer, bufferSize);
}

String createStringStart(String *string, long count)
{    
    return createStringSub(string, 1, count);
}

String createStringEnd(String *string, long count)
{    
    if (count < 1) { return makeStringEmpty(); }
    
    long start = string->size - count + 1;
    
    return createStringSub(string, start, count);
}

