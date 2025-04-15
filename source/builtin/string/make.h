// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


String* makeString(char* data, long size)
{
    String* string = allocateMemory(sizeof(String));
    
    string->data = data;
    
    string->size = size;
    
    return string;
}

String* makeStringEmpty()
{
    return makeString(NULL, 0);
}

String* makeStringClone(String* string)
{   
    return makeString(string->data, string->size);
}

String* makeStringFromLiteral(char* cString)
{   
    long size = strlen(cString);
    
    if (size == 0) { return makeStringEmpty(); }
    
    return makeString(cString, size);    
}

