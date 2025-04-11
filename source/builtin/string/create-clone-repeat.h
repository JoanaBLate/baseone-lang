// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

String createString(char *data, long size)
{
    String result = { data, size };
    
    return result;
}

String createStringEmpty()
{
    String empty = { .size = 0, .data = NULL };
    
    return empty;
}

String createStringFromCharCode(int n)
{   
    if (n < 0  ||  n > 255) { return createStringEmpty(); }

    char *buffer = allocateMemory(1);

    buffer[0] = n;
    
    return createString(buffer, 1);
}

String createStringFromLiteral(char *cString) // should not be released (not on the heap)
{   
    long size = strlen(cString);
    
    if (size == 0) { return createStringEmpty(); }
    
    return createString(cString, size);    
}

// not necessary because all memory allocation is done through arena(s)
//String createStringFromLiteralCloned(char *cString)
//{   
//    long bufferSize = strlen(cString);
//    
//    if (bufferSize == 0) { return createStringEmpty(); }
//    
//    char *buffer = allocateMemory(bufferSize);
//
//    memcpy(buffer, cString, bufferSize);
//    
//    return createString(buffer, bufferSize);
//}

String createStringClone(String *string)
{   
    long bufferSize = string->size;
    
    if (bufferSize == 0) { return createStringEmpty(); }
    
    char *buffer = allocateMemory(bufferSize);

    memcpy(buffer, string->data, bufferSize);
    
    return createString(buffer, bufferSize);
}

String createStringRepeat(String *string, int count)
{
    if (string->size == 0) { return createStringEmpty(); }
    
    if (count <= 0) { return createStringEmpty(); }
    
    long bufferSize = count * string->size;

    char *buffer = allocateMemory(bufferSize);
    
    for (int turn = 0; turn < count; turn++) { memcpy(&buffer[turn * string->size], string->data, string->size); }

    return createString(buffer, bufferSize);
}

