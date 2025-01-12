// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

String createEmptyString()
{
    String empty = { .size = 0, .data = NULL };
    
    return empty;
}

String createStringFromCharCode(int n)
{   
    if (n < 0  ||  n > 255) { return createEmptyString(); }

    char *buffer = malloc(1);

    buffer[0] = n;
    
    String newString = { 1, buffer };
    
    return newString;
}

String createStringFromLiteral(char *cString)
{   
    long bufferSize = strlen(cString);
    
    if (bufferSize == 0) { return createEmptyString(); }
    
    char *buffer = malloc(bufferSize);

    memcpy(buffer, cString, bufferSize);
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createStringClone(String *string)
{   
    long bufferSize = string->size;
    
    if (bufferSize == 0) { return createEmptyString(); }
    
    char *buffer = malloc(bufferSize);

    memcpy(buffer, string->data, bufferSize);
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createRepeatedString(String *string, int count)
{
    if (string->size == 0) { return createEmptyString(); }
    
    if (count <= 0) { return createEmptyString(); }
    
    long bufferSize = count * string->size;

    char *buffer = malloc(bufferSize);
    
    for (int turn = 0; turn < count; turn++) { memcpy(&buffer[turn * string->size], string->data, string->size); }

    String newString = { bufferSize, buffer };

    return newString;    
}

