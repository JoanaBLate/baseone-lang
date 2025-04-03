// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

String createStringFromCharCodeHeap(int n)
{   
    if (n < 0  ||  n > 255) { return createStringEmpty(); }

    char *buffer = allocateMemory(1);

    buffer[0] = n;
    
    String newString = { 1, buffer };
    
    return newString;
}

String createStringFromLiteralHeap(char *cString)
{   
    long bufferSize = strlen(cString);
    
    if (bufferSize == 0) { return createStringEmpty(); }
    
    char *buffer = allocateMemory(bufferSize);

    memcpy(buffer, cString, bufferSize);
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createStringCloneHeap(String *string)
{   
    long bufferSize = string->size;
    
    if (bufferSize == 0) { return createStringEmpty(); }
    
    char *buffer = allocateMemory(bufferSize);

    memcpy(buffer, string->data, bufferSize);
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createStringRepeatHeap(String *string, int count)
{
    if (string->size == 0) { return createStringEmpty(); }
    
    if (count <= 0) { return createStringEmpty(); }
    
    long bufferSize = count * string->size;

    char *buffer = allocateMemory(bufferSize);
    
    for (int turn = 0; turn < count; turn++) { memcpy(&buffer[turn * string->size], string->data, string->size); }

    String newString = { bufferSize, buffer };

    return newString;    
}

