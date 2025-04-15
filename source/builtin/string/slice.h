// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


String* stringSlice(String* string, long start, long count) // one base index 
{
    if (count < 1) { return makeStringEmpty(); }
    
    start -= 1; // adjusts to zero base index
    
    long off = start + count;
    
    if (off > string->size) { off = string->size; }
    
    if (start < 0) { start = 0; }
    
    long size = off - start;
    
    if (size <= 0) { return makeStringEmpty(); }
    
    return makeString(string->data + start, size);
}

String* stringSliceStart(String* string, long count)
{    
    return stringSlice(string, 1, count);
}

String* stringSliceEnd(String* string, long count)
{    
    if (count < 1) { return makeStringEmpty(); }
    
    long start = string->size - count + 1;
    
    return stringSlice(string, start, count);
}

