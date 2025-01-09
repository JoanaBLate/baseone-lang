
String createSubstring(String *string, int start, int count) // one base index
{
    if (count < 1) { return createEmptyString(); }
    
    start -= 1; // adjusts to zero base index
    
    int off = start + count;
    
    if (off > string->size) { off = string->size; }
    
    if (start < 0) { start = 0; }
    
    int size = off - start;
    
    if (size <= 0) { return createEmptyString(); }
    
    char *buffer = malloc(size);

    for (int index = 0; index < size; index++) { buffer[index] = string->data[start + index]; }
    
    String newString = { size, buffer };
    
    return newString;
}

String createStringStart(String *string, int count)
{    
    return createSubstring(string, 1, count);
}

String createStringEnd(String *string, int count)
{    
    if (count < 1) { return createEmptyString(); }
    
    int start = string->size - count + 1;
    
    return createSubstring(string, start, count);
}

