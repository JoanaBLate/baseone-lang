// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

String makeString(char *data, long size)
{
    String result = { data, size };
    
    return result;
}

String makeStringEmpty()
{
    String empty = { NULL, 0 };
    
    return empty;
}

String makeStringClone(String *string)
{   
    return makeString(string->data, string->size);
}

String makeStringFromLiteral(char *cString)
{   
    long size = strlen(cString);
    
    if (size == 0) { return makeStringEmpty(); }
    
    return makeString(cString, size);    
}

String createStringFromCharCode(int n)
{   
    if (n < 0  ||  n > 255) { return makeStringEmpty(); }

    char *buffer = allocateMemory(1);

    buffer[0] = n;
    
    return makeString(buffer, 1);
}

String _createStringFromLiteral(char *cString)
{   
    long bufferSize = strlen(cString);
    
    if (bufferSize == 0) { return makeStringEmpty(); }
    
    char *buffer = allocateMemory(bufferSize);

    memcpy(buffer, cString, bufferSize);
    
    return makeString(buffer, bufferSize);
}

String createStringClone(String *string)
{   
    long bufferSize = string->size;
    
    if (bufferSize == 0) { return makeStringEmpty(); }
    
    char *buffer = allocateMemory(bufferSize);

    memcpy(buffer, string->data, bufferSize);
    
    return makeString(buffer, bufferSize);
}

String createStringRepeat(String *string, int count)
{
    if (string->size == 0) { return makeStringEmpty(); }
    
    if (count <= 0) { return makeStringEmpty(); }
    
    long bufferSize = count * string->size;

    char *buffer = allocateMemory(bufferSize);
    
    for (int turn = 0; turn < count; turn++) { memcpy(&buffer[turn * string->size], string->data, string->size); }

    return makeString(buffer, bufferSize);
}

