// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

String createStringReplaceStartHeap(String *string, long count, String *chunk)
{    
    if (count < 1) { return createStringCloneHeap(string); } 
    
    if (count >= string->size) { return createStringCloneHeap(chunk); }
    
    long stringRightArmStart = count;
    long stringRightArmSize = string->size - count;
    
    long bufferSize = chunk->size + stringRightArmSize;
    
    char *buffer = allocateMemory(bufferSize);
    
    // buffer left arm
    for (long index = 0; index < chunk->size; index++) { buffer[index] = chunk->data[index]; } 
        
    // buffer right arm
    for (long index = 0; index < stringRightArmSize; index++) 
    {
        buffer[chunk->size + index] = string->data[stringRightArmStart + index];
    }
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createStringReplaceEndHeap(String *string, long count, String *chunk)
{    
    if (count < 1) { return createStringCloneHeap(string); } 
    
    if (count >= string->size) { return createStringCloneHeap(chunk); } 
    
 // long stringLeftArmStart = 0;
    long stringLeftArmSize = string->size - count;
    
    long bufferSize = stringLeftArmSize + chunk->size;
    
    char *buffer = allocateMemory(bufferSize);
    
    // buffer left arm
    for (long index = 0; index < stringLeftArmSize; index++) { buffer[index] = string->data[index]; } 
    
    // buffer right arm
    for (long index = 0; index < chunk->size; index++) { buffer[stringLeftArmSize + index] = chunk->data[index]; } 
        
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createStringReplaceHeap(String *string, String *target, String *chunk)
{
    long position = stringIndexOf(string, target) - 1; // '-1' adjusts to zero index
    
    if (position == -1) { return createStringCloneHeap(string); } // target not found
    
    if (position == 0) { return createStringReplaceStartHeap(string, target->size, chunk); }
    
    if (position + target->size == string->size) { return createStringReplaceEndHeap(string, target->size, chunk); }
    
    //
    
 // long stringLeftArmStart = 0;
    long stringLeftArmSize = position;
    
    long stringRightArmStart = position + target->size;
    long stringRightArmSize = string->size - stringLeftArmSize - target->size;
    
    long bufferSize = stringLeftArmSize + chunk->size + stringRightArmSize;
    
    char *buffer = allocateMemory(bufferSize);
    
    // buffer left arm
    for (long index = 0; index < stringLeftArmSize; index++) { buffer[index] = string->data[index]; } 
    
    // buffer middle 
    for (long index = 0; index < chunk->size; index++) { buffer[position + index] = chunk->data[index]; } 
        
    // buffer right arm
    for (long index = 0; index < stringRightArmSize; index++) 
    {
        buffer[position + chunk->size + index] = string->data[stringRightArmStart + index];
    }
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createStringRemoveHeap(String *string, String *target)
{
    String empty = createStringEmpty();
    
    return createStringReplaceHeap(string, target, &empty);
}

String createStringReplaceAllHeap(String *string, String *target, String *chunk)
{
    long count = stringCountOfTarget(string, target);
    
    if (count == 0) { return createStringCloneHeap(string); }
    
    long bufferSize = string->size + count * (chunk->size - target->size);
    
    if (bufferSize == 0) { return createStringEmpty(); }

    char *buffer = allocateMemory(bufferSize);

    long bufferIndex = -1;
    
    String temp = { string->size, string->data };
    
    while (temp.size > 0) {

        bool startsNormal = true;
        
        if (temp.data[0] == target->data[0]) { startsNormal = ! stringStartsWith(&temp, target); } // avoiding always call the function
   
        if (startsNormal) {
        
            bufferIndex += 1; 
            buffer[bufferIndex] = temp.data[0];            
        
            temp.size -= 1;            
            temp.data += 1;
        
            continue;        
        }
        
        // skipping the target
        temp.size -= target->size;        
        temp.data += target->size;
        
        // inserting the chunk        
        for (long index = 0; index < chunk->size; index++) 
        { 
            bufferIndex += 1;
            buffer[bufferIndex] = chunk->data[index];
        }
    }
            
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createStringRemoveAllHeap(String *string, String *target)
{
    String empty = createStringEmpty();
    
    return createStringReplaceAllHeap(string, target, &empty);
}

