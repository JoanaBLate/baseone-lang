// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void stringTrimStart(String* string)
{
    while (true)
    {
        if (string->size == 0) { string->data = NULL; return; }
        
        if ((unsigned char) string->data[0] > ' ') { return; }
        
        string->data += 1; string->size -= 1;
    }
}

void stringTrimEnd(String* string)
{
    while (true)
    {
        if (string->size == 0) { string->data = NULL; return; }
        
        long index = string->size - 1;
        
        if ((unsigned char) string->data[index] > ' ') { return; }
    
        string->size -= 1;          
    }
}

void stringTrim(String* string)
{
    stringTrimStart(string);

    stringTrimEnd(string);
}

void stringTrimStartTarget(String* string, String target)
{
    while (stringStartsWith(*string, target))
    {
        string->data += target.size; string->size -= target.size;
    }
}

void stringTrimEndTarget(String* string, String target)
{
    while (stringEndsWith(*string, target))
    {
        string->size -= target.size;
    }
}

void stringTrimTarget(String* string, String target)
{
    stringTrimStartTarget(string, target);

    stringTrimEndTarget(string, target);
}

