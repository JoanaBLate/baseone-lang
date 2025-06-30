// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


long getStringSize(String* string)
{        
    return string->size;
}

unsigned char stringCharCodeAt(String* string, long index) // one base index
{    
    if (index < 1  ||  index > string->size) 
    { 
        printf("\nERROR in function '@stringCharCodeAt': index (%li) out of bounds\n", index); exit(1);
    }
    
    return (unsigned char) string->address[index - 1];
}

bool stringsAreEqual(String* stringA, String* stringB)
{
    if (stringA->size != stringB->size) { return false; };
    
    for (long index = 0; index < stringA->size; index ++)
    {
        if (stringA->address[index] != stringB->address[index]) { return false; }
    }
    return true;
}

bool stringStartsWith(String* string, String* target)
{    
    if (target->size == 0) { return false; }
    
    if (target->size > string->size) { return false; }
    
    for (long index = 0; index < target->size; index++)
    {
        if (string->address[index] != target->address[index]) { return false; }
    }
    return true;
}

bool stringEndsWith(String* string, String* target)
{    
    if (target->size == 0) { return false; }
    
    if (target->size > string->size) { return false; }
    
    long pad = string->size - target->size;
    
    for (long index = 0; index < target->size; index++)
    {
        if (string->address[pad + index] != target->address[index]) { return false; }
    }
    return true;
}

long stringIndexOf(String* string, String* target) // one base index
{    
    if (target->size == 0) { return 0; }
    
    if (target->size > string->size) { return 0; }
    
    long off = string->size - target->size + 1;
    
    for (long index = 0; index < off; index++)
    {
        bool match = true;
        
        for (long targetIndex = 0; targetIndex < target->size; targetIndex++)
        {
            if (string->address[index + targetIndex] != target->address[targetIndex]) { match = false; break; }
        }
        
        if (match) { return index + 1; }
    }
    return 0;
}

long stringIndexOfAfter(String* string, String* target, long usedIndex) // one base index
{    
    if (string->size == 0) { return 0; }

    if (target->size > string->size) { return 0; }
        
    if (usedIndex >= string->size) { return 0; }
    
    if (usedIndex < 1) { return stringIndexOf(string, target); }
    
    long startIndex = usedIndex; // stringStartIndex is zero base index
    
    long maxIndex = string->size - target->size;
    
    for (long index = startIndex; index <= maxIndex; index++) 
    {
        bool match = true;
        
        for (long targetIndex = 0; targetIndex < target->size; targetIndex++)
        {
            if (string->address[index + targetIndex] != target->address[targetIndex]) { match = false; break; }
        }
        
        if (match) { return index + 1; }
    }
    return 0;
}

long stringLastIndexOf(String* string, String* target) // one base index
{    
    if (target->size == 0) { return 0; }
    
    if (target->size > string->size) { return 0; }
    
    long startIndex = string->size - target->size;
    
    for (long index = startIndex; index > -1; index--) // runs backwards
    {
        bool match = true;
        
        for (long targetIndex = 0; targetIndex < target->size; targetIndex++)
        {
            if (string->address[index + targetIndex] != target->address[targetIndex]) { match = false; break; }
        }
        
        if (match) { return index + 1; }
    }
    return 0;
}

long stringLastIndexOfBefore(String* string, String* target, long usedIndex) // one base index
{    
    if (target->size == 0) { return 0; }

    if (target->size > string->size) { return 0; }
    
    if (usedIndex <= 1) { return 0; }
    
    if (usedIndex >= string->size) { return stringLastIndexOf(string, target); }
       
    long maxIndex = (usedIndex - 1) - target->size; // off is zero base index
    
    for (long index = maxIndex; index > -1; index--) // runs backwards
    {
        bool match = true;
        
        for (long targetIndex = 0; targetIndex < target->size; targetIndex++)
        {
            if (string->address[index + targetIndex] != target->address[targetIndex]) { match = false; break; }
        }
        
        if (match) { return index + 1; }
    }
    return 0;
}

bool stringContains(String* string, String* target)
{    
    return (stringIndexOf(string, target) != 0);
}

long stringCountOf(String* string, String* target)
{
    long count = 0;

    long index = -target->size;
    
    while (true) {
    
        index = stringIndexOfAfter(string, target, index + target->size - 1);
    
        if (index == 0) { break; } else { count += 1; }
    
    }
    return count;
}

