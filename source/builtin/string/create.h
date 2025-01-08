
struct String createEmptyString()
{
    struct String empty = { .size = 0, .data = NULL };
    
    return empty;
}

struct String createStringFromCharCode(int n)
{   
    if (n < 0  ||  n > 255) { return createEmptyString(); }

    char *buffer = malloc(1);

    buffer[0] = n;
    
    struct String newString = { 1, buffer };
    
    return newString;
}

struct String createStringFromLiteral(char *cString)
{   
    int size = strlen(cString);
    
    if (size == 0) { return createEmptyString(); }
    
    char *buffer = malloc(size);

    memcpy(buffer, cString, size);
    
    struct String newString = { size, buffer };
    
    return newString;
}

struct String createStringClone(struct String *string)
{   
    int size = string->size;
    
    if (size == 0) { return createEmptyString(); }
    
    char *buffer = malloc(size);

    memcpy(buffer, string->data, size);
    
    struct String newString = { size, buffer };
    
    return newString;
}

struct String createRepeatedString(struct String *string, int count)
{
    if (count <= 0) { return createEmptyString(); }

    char *buffer = malloc(count * string->size);
    
    for (int turn = 0; turn < count; turn++) { memcpy(&buffer[turn * string->size], string->data, string->size); }

    struct String newString = { count * string->size, buffer };

    return newString;    
}

