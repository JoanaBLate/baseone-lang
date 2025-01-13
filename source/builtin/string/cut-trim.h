// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

String createStringCutStart(String *string, long count)
{
    if (count < 1) { return createStringClone(string); }
    
    if (count >= string->size) { return createEmptyString(); }
    
    long bufferSize = string->size - count;
    
    char *buffer = memoryAllocate(bufferSize);
    
    memcpy(buffer, string->data + count, bufferSize);    
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createStringCutEnd(String *string, long count)
{
    if (count < 1) { return createStringClone(string); }
    
    if (count >= string->size) { return createEmptyString(); }
    
    long bufferSize = string->size - count;
    
    char *buffer = memoryAllocate(bufferSize);
    
    memcpy(buffer, string->data, bufferSize);    
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createStringCutMiddle(String *string, long position, long count) // one base index
{
    position -= 1; // adjusts to zero base index
    
    if (position < 0) { count += position; position = 0; }
    
    if (count < 1) { return createStringClone(string); }
    
    if (position == 0)
    {  
        if (count >= string->size) { return createEmptyString(); }

        return createStringCutStart(string, count);  
    }
    
    if (position + count >= string->size) { return createStringCutEnd(string, string->size - position); }
    
    //
      
 // long stringLeftArmStart = 0;
    long stringLeftArmSize = position;
    
    long stringRightArmStart = position + count;
    long stringRightArmSize = string->size - stringLeftArmSize - count;
    
    long bufferSize = stringLeftArmSize + stringRightArmSize;
    
    char *buffer = memoryAllocate(bufferSize);
    
    // buffer left arm
    for (long index = 0; index < stringLeftArmSize; index++) { buffer[index] = string->data[index]; } 
    
    // buffer right arm
    for (long index = 0; index < stringRightArmSize; index++) 
    {
        buffer[position + index] = string->data[stringRightArmStart + index];
    }
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createStringTrimStart(String *string, String *chunk)
{
    String temp = { string->size, string->data };
    
    while (stringStartsWith(&temp, chunk)) { temp.size -= chunk->size; temp.data += chunk->size; }
    
    long bufferSize = temp.size;
    
    char *buffer = memoryAllocate(bufferSize);
    
    memcpy(buffer, temp.data, temp.size);
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createStringTrimEnd(String *string, String *chunk)
{
    String temp = { string->size, string->data };
    
    while (stringEndsWith(&temp, chunk)) { temp.size -= chunk->size; }
    
    long bufferSize = temp.size;
    
    char *buffer = memoryAllocate(bufferSize);
    
    memcpy(buffer, temp.data, temp.size);
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createStringTrim(String *string, String *chunk)
{
    String temp = { string->size, string->data };
    
    while (stringStartsWith(&temp, chunk)) { temp.size -= chunk->size; temp.data += chunk->size; }
    
    while (stringEndsWith(&temp, chunk)) { temp.size -= chunk->size; }
    
    long bufferSize = temp.size;
    
    char *buffer = memoryAllocate(bufferSize);
    
    memcpy(buffer, temp.data, temp.size);
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

