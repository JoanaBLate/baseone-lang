
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
    int size = strlen(cString);
    
    if (size == 0) { return createEmptyString(); }
    
    char *buffer = malloc(size);

    memcpy(buffer, cString, size);
    
    String newString = { size, buffer };
    
    return newString;
}

String createStringClone(String *string)
{   
    int size = string->size;
    
    if (size == 0) { return createEmptyString(); }
    
    char *buffer = malloc(size);

    memcpy(buffer, string->data, size);
    
    String newString = { size, buffer };
    
    return newString;
}

String createRepeatedString(String *string, int count)
{
    if (string->size == 0) { return createEmptyString(); }
    
    if (count <= 0) { return createEmptyString(); }

    char *buffer = malloc(count * string->size);
    
    for (int turn = 0; turn < count; turn++) { memcpy(&buffer[turn * string->size], string->data, string->size); }

    String newString = { count * string->size, buffer };

    return newString;    
}

