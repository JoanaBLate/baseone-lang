// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


String* newStringToLower(String* string) // allocates memory
{
    String* newString = newStringClone(string);
    
    for (long index = 0; index < newString->size; index++)
    {
        newString->data[index] = tolower(newString->data[index]);
    }
    
    return newString;
}

String* newStringToUpper(String* string) // allocates memory
{
    String* newString = newStringClone(string);
    
    for (long index = 0; index < newString->size; index++)
    {
        newString->data[index] = toupper(newString->data[index]);
    }
    
    return newString;
}

String* newStringToOppositeCase(String* string) // allocates memory
{
    String* newString = newStringClone(string);
    
    for (long index = 0; index < newString->size; index++)
    {
        char c = newString->data[index];
        
        if (isupper(c)) 
        { 
            newString->data[index] = tolower(c);
        }
        else if (islower(c)) 
        { 
            newString->data[index] = toupper(c);
        }
    }
    
    return newString;
}

String* newStringReverse(String* string) // allocates memory
{
    String* newString = newStringClone(string);
    
    long halfLen = newString->size / 2;

    for (long index = 0; index < halfLen; index++) 
    {     
        char temp = newString->data[index];
        newString->data[index] = newString->data[newString->size - 1 - index];
        newString->data[newString->size - 1 - index] = temp;
    }
    
    return newString;
}

String* newStringSort(String* string) // TODO: slow  // allocates memory
{
    String* newString = newStringClone(string);
    
    for (long indexA = 0; indexA < newString->size - 1; indexA++) 
    { 
        for (long indexB = indexA + 1; indexB < newString->size; indexB++) 
        { 
            if (newString->data[indexA] <= newString->data[indexB]) { continue; }
            
            char temp = newString->data[indexA];
            newString->data[indexA] = newString->data[indexB];
            newString->data[indexB] = temp;
        }
    }
    
    return newString;
}

