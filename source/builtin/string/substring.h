// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


String createSubstring(String string, long start, long count) // allocates heap memory // one base index 
{
    if (count < 1) { return makeStringEmpty(); }
    
    start -= 1; // adjusts to zero base index
    
    long off = start + count;
    
    if (off > string.size) { off = string.size; }
    
    if (start < 0) { start = 0; }
    
    long size = off - start;
    
    if (size <= 0) { return makeStringEmpty(); }
    
    return createStringFromSource(string.address + start, size);
}

String createSubstringStart(String string, long count) // allocates heap memory
{    
    return createSubstring(string, 1, count);
}

String createSubstringEnd(String string, long count) // allocates heap memory
{    
    if (count < 1) { return makeStringEmpty(); }
    
    long start = string.size - count + 1;
    
    return createSubstring(string, start, count);
}

