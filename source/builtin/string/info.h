
int stringCharCodeAt(struct String *string, int index) // one base index
{    
    if (index < 1) { return -1; }
    
    if (index > string->size) { return -1; }
    
    int value = (unsigned char) string->data[index - 1];
    
    return (int) value;
}

bool stringsAreEqual(struct String *stringA, struct String *stringB)
{
    if (stringA->size != stringB->size) { return false; };
    
    for (int index = 0; index < stringA->size; index ++)
    {
        if (stringA->data[index] != stringB->data[index]) { return false; }
    }
    return true;
}

bool stringStartsWith(struct String *string, struct String *target)
{    
    if (target->size == 0) { return false; }
    
    if (target->size > string->size) { return false; }
    
    for (int index = 0; index < target->size; index++)
    {
        if (string->data[index] != target->data[index]) { return false; }
    }
    return true;
}

bool stringEndsWith(struct String *string, struct String *target)
{    
    if (target->size == 0) { return false; }
    
    if (target->size > string->size) { return false; }
    
    int pad = string->size - target->size;
    
    for (int index = 0; index < target->size; index++)
    {
        if (string->data[pad + index] != target->data[index]) { return false; }
    }
    return true;
}

int stringIndexOf(struct String *string, struct String *target) // one base index
{    
    if (target->size == 0) { return 0; }
    
    if (target->size > string->size) { return 0; }
    
    int off = string->size - target->size + 1;
    
    for (int index = 0; index < off; index++)
    {
        bool match = true;
        
        for (int targetIndex = 0; targetIndex < target->size; targetIndex++)
        {
            if (string->data[index + targetIndex] != target->data[targetIndex]) { match = false; break; }
        }
        
        if (match) { return index + 1; }
    }
    return 0;
}

int stringIndexOfAfter(struct String *string, struct String *target, int usedIndex) // one base index
{    
    if (string->size == 0) { return 0; }

    if (target->size > string->size) { return 0; }
        
    if (usedIndex >= string->size) { return 0; }
    
    if (usedIndex < 1) { return stringIndexOf(string, target); }
    
    int startIndex = usedIndex; // stringStartIndex is zero base index
    
    int maxIndex = string->size - target->size;
    
    for (int index = startIndex; index <= maxIndex; index++) 
    {
        bool match = true;
        
        for (int targetIndex = 0; targetIndex < target->size; targetIndex++)
        {
            if (string->data[index + targetIndex] != target->data[targetIndex]) { match = false; break; }
        }
        
        if (match) { return index + 1; }
    }
    return 0;
}

int stringLastIndexOf(struct String *string, struct String *target) // one base index
{    
    if (target->size == 0) { return 0; }
    
    if (target->size > string->size) { return 0; }
    
    int startIndex = string->size - target->size;
    
    for (int index = startIndex; index > -1; index--) // runs backwards
    {
        bool match = true;
        
        for (int targetIndex = 0; targetIndex < target->size; targetIndex++)
        {
            if (string->data[index + targetIndex] != target->data[targetIndex]) { match = false; break; }
        }
        
        if (match) { return index + 1; }
    }
    return 0;
}

int stringLastIndexOfBefore(struct String *string, struct String *target, int usedIndex) // one base index
{    
    if (target->size == 0) { return 0; }

    if (target->size > string->size) { return 0; }
    
    if (usedIndex <= 1) { return 0; }
    
    if (usedIndex >= string->size) { return stringLastIndexOf(string, target); }
       
    int maxIndex = (usedIndex - 1) - target->size; // off is zero base index
    
    for (int index = maxIndex; index > -1; index--) // runs backwards
    {
        bool match = true;
        
        for (int targetIndex = 0; targetIndex < target->size; targetIndex++)
        {
            if (string->data[index + targetIndex] != target->data[targetIndex]) { match = false; break; }
        }
        
        if (match) { return index + 1; }
    }
    return 0;
}

bool stringContains(struct String *string, struct String *target)
{    
    return (stringIndexOf(string, target) != 0);
}

