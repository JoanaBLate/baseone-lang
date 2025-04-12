// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void stringTrimStart(String *string)
{
    while (true)
    {
        if (string->size == 0) { string->data = NULL; return; }
        
        if ((unsigned char) string->data[0] > ' ') { return; }
        
        string->data += 1; string->size -= 1;
    }
}

void stringTrimEnd(String *string)
{
    while (true)
    {
        if (string->size == 0) { string->data = NULL; return; }
        
        long index = string->size - 1;
        
        if ((unsigned char) string->data[index] > ' ') { return; }
    
        string->size -= 1;          
    }
}

void stringTrim(String *string)
{
    stringTrimStart(string);

    stringTrimEnd(string);
}

String stringEatStart(String *string, long size)
{
    String result = makeStringEmpty();
    
    if (size <= 0) { return result; }
    
    if (size >= string->size) { size = string->size; }
    
    result.data = string->data;
    result.size = size;
    
    string->data += size;
    string->size -= size;
    
    if (string->size == 0) { string->data = NULL; }
    
    return result;
}

String stringEatLine(String *string)
{
    String result = makeStringEmpty();
    
    char *rAddress = NULL;
    char *nAddress = NULL;

    while (true)
    {
        if (string->size == 0) { string->data = NULL; break; }
        
        char c = string->data[0];
        
        if (c == '\r') { rAddress = string->data; }
        
        if (c == '\n') { nAddress = string->data; }
    
        string->data += 1; string->size -= 1;
        
        if (c == '\n') { break; }

        if (result.data == NULL) { result.data = string->data - 1; }
        
        result.size += 1;
    }
    
    if (rAddress == NULL) { return result; }
    if (nAddress == NULL) { return result; }
    
    if (rAddress + 1 != nAddress) { return result; }
    
    result.size -= 1;
    
    if (result.size == 0) { result.data = NULL; }
    
    return result; 
}

String stringEatToken(String *string) // skips any kind of blank excepting EOL
{
    String result = makeStringEmpty();
    
    while (true)
    {
        if (string->size == 0) { string->data = NULL; break; }
        
        char c = (unsigned char) string->data[0];
        
        if (c == '\n') 
        {
            if (result.data != NULL) { break; }
            
            result.data = string->data; result.size = 1;
            
            string->data += 1; string->size -= 1;
            
            break;
        }
        
        if (c <= ' ') { string->data += 1; string->size -= 1; continue; }
        
        if (result.data == NULL) { result.data = string->data; }
        
        result.size = 1;
    }
    
    return result;
}
    
// number /////////////////////////////////////////////////////////////////////

NullLong _stringEatInteger(String *string, int signal) // expected to start with digit!!!
{   
    char *digits = string->data;
    
    int length = 0;
    
    while (true)
    {
        if (string->size == 0) { break; }
        
        if (string->data[0] < '0') { break; }
        if (string->data[0] > '9') { break; }
        
        length += 1;

        string->data += 1; string->size -= 1;
    }             

    long result = 0;
    long factor = 1;

    for (int index = length; index > 0; index--)
    {
        result += (digits[index - 1] - '0') * factor;
        
        factor *= 10;
    }

    return createNullableLong(signal * result, false);
}  

NullLong stringEatInteger(String *string) // trim leading startin whitespaces
{   
    while (string->size != 0) 
    {
        if (string->data[0] == ' ') { string->data += 1; string->size -= 1; } else { break; }
    }
    
    if (string->size == 0) { return createNullLong(); }
    
    char first = (unsigned char) string->data[0];
    
    if (string->size == 1)
    {
        if (first < '0') { return createNullLong(); }
        if (first > '9') { return createNullLong(); }
    
        return createNullableLong(first - '0', false);
    }
    
    int signal = 0;
    
    if (first == '-') { signal = -1; } else if (first == '+') { signal = +1; }
    
    if (signal != 0)
    {
        if (string->data[1] < '0') { return createNullLong(); }
        if (string->data[1] > '9') { return createNullLong(); }
                
        string->data += 1; string->size -= 1; // eating the signal
    }
    
    if (signal == 0) { signal = 1; }
    
    return _stringEatInteger(string, signal);
}

