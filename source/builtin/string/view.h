// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

// any String returned from a StringView function does NOT have own memory,
// that string is just a view for the data contained by the StringView object

typedef struct 
{
    char *data;
    long size;
    char *start; // keeps bad value when length reaches zero
    long length;
} StringView;

StringView createStringView(char* data, long size)
{
    StringView sv = { data, size, data, size };    

    return sv;
}

void stringViewReset(StringView *sv)
{
    sv->start  = sv->data;
    sv->length = sv->size;
}

String stringViewCurrent(StringView *sv)
{
    String result = createStringEmpty();
    
    if (sv->length == 0) { return result; }
    
    result.data = sv->start;

    result.size = sv->length;

    return result;
}

void stringViewTrimStart(StringView *sv)
{
    while (sv->length != 0)
    {
        if ((unsigned char) sv->start[0] > ' ') { return; }
        
        sv->start  += 1; sv->length -= 1;
    }
}

void stringViewTrimEnd(StringView *sv)
{
    while (sv->length != 0)
    {
        long index = sv->length - 1;
        
        if ((unsigned char) sv->data[index] > ' ') { return; }
    
        sv->length -= 1;          
    }
}

void stringViewTrim(StringView *sv)
{
    stringViewTrimStart(sv);

    stringViewTrimEnd(sv);
}

String stringViewEatStart(StringView *sv, long count)
{
    String result = createStringEmpty();
    
    if (count <= 0) { return result; }
    
    if (count > sv->length) { count = sv->length; }
        
    result.data = sv->start;    
    result.size = count;
    
    sv->start += count;
    sv->length -= count;
    
    return result;
}

String stringViewEatLine(StringView *sv)
{
    String result = createStringEmpty();
    
    if (sv->length == 0) { return result; }
    
    result.data = sv->start;
    
    result.size = 1;
    
    while (sv->length != 0)
    {
        char c = sv->start[0];
    
        sv->start += 1; sv->length -= 1;
        
        if (c == '\n') { break; }
        
        result.size += 1;          
    }
    
    if (result.size == 0) { return createStringEmpty(); }
    
    if (result.data[result.size - 1] == '\r') { result.size -= 1; }
    
    if (result.size == 0) { return createStringEmpty(); }
    
    return result;
}
    
String stringViewEatToken(StringView *sv) // skips any kind of blank (like EOL)
{
    String result = createStringEmpty();
    
    stringViewTrimStart(sv);
    
    if (sv->length == 0) { return result; } 
    
    // now, granted to start with non blank token
    
    result.data = sv->start;
    
    result.size = 1;
    
    sv->start += 1; sv->length -= 1;
    
    while (sv->length != 0)
    {        
        if ((unsigned char) sv->start[0] <= ' ') { break; }
        
        result.size += 1;          
    
        sv->start += 1; sv->length -= 1;
    }

    return result;
}

String stringViewJustEatSignalBeforeDigit(StringView *sv) // will not trim start 
{  
    String result = createStringEmpty();

    if (sv->length < 2) { return result; }
      
    char c = sv->start[0];
    
    if (c != '-'   &&   c != '+') { return result; } 
    
    if (sv->start[1] < '0') { return result; }         
    if (sv->start[1] > '9') { return result; } 
        
    result.data = sv->start;
    result.size = 1;
        
    sv->start += 1; sv->length -= 1;         
    
    return result;
}

String stringViewJustEatDigits(StringView *sv) // will not trim start
{
    String result = createStringEmpty();
    
    if (sv->length == 0) { return result; }
    
    if (sv->start[0] < '0') { return result; }
    if (sv->start[0] > '9') { return result; }
    
    // now, granted to start with digit
    
    result.data = sv->start;
    
    result.size = 1;
    
    sv->start += 1; sv->length -= 1;
    
    while (sv->length != 0)
    {
        if (sv->start[0] < '0') { break; }
        if (sv->start[0] > '9') { break; }
        
        result.size += 1;
            
        sv->start += 1; sv->length -= 1;
    }
    
    return result;
}

String stringViewEatNumber(StringView *sv) // returns String!
{
    String result = createStringEmpty();
    
    stringViewTrimStart(sv);
    
    if (sv->length == 0) { return result; } 
    
    result.data = sv->start;
    
    result.size = stringViewJustEatSignalBeforeDigit(sv).size;
    
    String tokenA = stringViewJustEatDigits(sv);
    
    if (tokenA.size == 0) { return createStringEmpty(); }
    
    result.size += tokenA.size;    
    
    if (sv->length < 2) { return result; } // no room for dot and digit
    
    if (sv->start[0] != '.') { return result; };
    
    if (sv->start[1] < '0') { return result; }
    if (sv->start[1] > '9') { return result; }
    
    sv->start += 1; sv->length -= 1; // dot

    String tokenB = stringViewJustEatDigits(sv);
    
    result.size += tokenB.size;

    return result;
}

