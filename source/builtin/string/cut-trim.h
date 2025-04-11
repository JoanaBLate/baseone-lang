// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

String createStringCutStart(String *string, long count)
{
    if (count < 1) { return createStringClone(string); }
    
    if (count >= string->size) { return createStringEmpty(); }
    
    long bufferSize = string->size - count;
    
    char *buffer = allocateMemory(bufferSize);
    
    memcpy(buffer, string->data + count, bufferSize);    
    
    return createString(buffer, bufferSize);
}

String createStringCutEnd(String *string, long count)
{
    if (count < 1) { return createStringClone(string); }
    
    if (count >= string->size) { return createStringEmpty(); }
    
    long bufferSize = string->size - count;
    
    char *buffer = allocateMemory(bufferSize);
    
    memcpy(buffer, string->data, bufferSize);    
    
    return createString(buffer, bufferSize);
}

String createStringCutMiddle(String *string, long position, long count) // one base index
{
    position -= 1; // adjusts to zero base index
    
    if (position < 0) { count += position; position = 0; }
    
    if (count < 1) { return createStringClone(string); }
    
    if (position == 0)
    {  
        if (count >= string->size) { return createStringEmpty(); }

        return createStringCutStart(string, count);  
    }
    
    if (position + count >= string->size) { return createStringCutEnd(string, string->size - position); }
    
    //
      
 // long stringLeftArmStart = 0;
    long stringLeftArmSize = position;
    
    long stringRightArmStart = position + count;
    long stringRightArmSize = string->size - stringLeftArmSize - count;
    
    long bufferSize = stringLeftArmSize + stringRightArmSize;
    
    char *buffer = allocateMemory(bufferSize);
    
    // buffer left arm
    for (long index = 0; index < stringLeftArmSize; index++) { buffer[index] = string->data[index]; } 
    
    // buffer right arm
    for (long index = 0; index < stringRightArmSize; index++) 
    {
        buffer[position + index] = string->data[stringRightArmStart + index];
    }
    
    return createString(buffer, bufferSize);
}

String createStringTrimStartIt(String *string, String *chunk)
{
    String temp = createString(string->data, string->size);
    
    while (stringStartsWith(&temp, chunk)) { temp.size -= chunk->size; temp.data += chunk->size; }
    
    long bufferSize = temp.size;
    
    char *buffer = allocateMemory(bufferSize);
    
    memcpy(buffer, temp.data, temp.size);
    
    return createString(buffer, bufferSize);
}

String createStringTrimEndIt(String *string, String *chunk)
{
    String temp = createString(string->data, string->size);
    
    while (stringEndsWith(&temp, chunk)) { temp.size -= chunk->size; }
    
    long bufferSize = temp.size;
    
    char *buffer = allocateMemory(bufferSize);
    
    memcpy(buffer, temp.data, temp.size);
    
    return createString(buffer, bufferSize);
}

String createStringTrimIt(String *string, String *chunk)
{
    String temp = createString(string->data, string->size);
    
    while (stringStartsWith(&temp, chunk)) { temp.size -= chunk->size; temp.data += chunk->size; }
    
    while (stringEndsWith(&temp, chunk)) { temp.size -= chunk->size; }
    
    long bufferSize = temp.size;
    
    char *buffer = allocateMemory(bufferSize);
    
    memcpy(buffer, temp.data, temp.size);
    
    return createString(buffer, bufferSize);
}

String createStringTrimStart(String *string)
{
    long start = 0;
        
    while (true) 
    {
        if (start == string->size) { return createStringEmpty(); } 
        
        if ((unsigned char) string->data[start] > ' ') { break; }
    
        start += 1;           
    }
    
    long bufferSize = string->size - start;
    
    char *buffer = allocateMemory(bufferSize);
    
    memcpy(buffer, string->data + start, bufferSize);
    
    return createString(buffer, bufferSize);
}

String createStringTrimEnd(String *string)
{
    long end = string->size - 1;

    while (true)
    {
        if (end < 0) { return createStringEmpty(); }    

        if ((unsigned char) string->data[end] > ' ') { break; }
    
        end -= 1;
    }
    
    long bufferSize = end + 1;
    
    char *buffer = allocateMemory(bufferSize);
    
    memcpy(buffer, string->data, bufferSize);
    
    return createString(buffer, bufferSize);
}

String createStringTrim(String *string)
{
    long start = 0;
        
    while (true) 
    {
        if (start == string->size) { return createStringEmpty(); } 
        
        if ((unsigned char) string->data[start] > ' ') { break; }
    
        start += 1;           
    } 
    
    long end = string->size - 1;

    while ((unsigned char) string->data[end] <= ' ') { end -= 1; } // granted to find non blank char
    
    long bufferSize = end - start + 1;
    
    char *buffer = allocateMemory(bufferSize);
    
    memcpy(buffer, string->data + start, bufferSize);
    
    return createString(buffer, bufferSize);
}

