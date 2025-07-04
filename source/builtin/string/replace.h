// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// replace by position ////////////////////////////////////////////////////////

String createStringReplaceStart(String* string, long count, String* chunk) // allocates heap memory
{    
    if (count < 1) { return createStringInsert(string, chunk, 0); } 
    
    if (count >= string->size) { return createStringClone(chunk); }
    
    long stringRightArmStart = count;
    long stringRightArmSize = string->size - count;
    
    long bufferSize = chunk->size + stringRightArmSize;
    
    char* buffer = heapAllocate(bufferSize);
    
    // buffer left arm
    for (long index = 0; index < chunk->size; index++) { buffer[index] = chunk->address[index]; } 
        
    // buffer right arm
    for (long index = 0; index < stringRightArmSize; index++) 
    {
        buffer[chunk->size + index] = string->address[stringRightArmStart + index];
    }
    
    return makeString(buffer, bufferSize);
}

String createStringReplaceEnd(String* string, long count, String* chunk) // allocates heap memory
{    
    if (count < 1) { return createStringAppend(string, chunk); } 
    
    if (count >= string->size) { return createStringClone(chunk); } 
    
 // long stringLeftArmStart = 0;
    long stringLeftArmSize = string->size - count;
    
    long bufferSize = stringLeftArmSize + chunk->size;
    
    char* buffer = heapAllocate(bufferSize);
    
    // buffer left arm
    for (long index = 0; index < stringLeftArmSize; index++) { buffer[index] = string->address[index]; } 
    
    // buffer right arm
    for (long index = 0; index < chunk->size; index++) { buffer[stringLeftArmSize + index] = chunk->address[index]; } 
        
    return makeString(buffer, bufferSize);
}

// replace by target //////////////////////////////////////////////////////////

String _createStringReplace(String* string, String* target, String* chunk, long position) // allocates heap memory
{
 // long stringLeftArmStart = 0;
    long stringLeftArmSize = position;
    
    long stringRightArmStart = position + target->size;
    long stringRightArmSize = string->size - stringLeftArmSize - target->size;
    
    long bufferSize = stringLeftArmSize + chunk->size + stringRightArmSize;
    
    char* buffer = heapAllocate(bufferSize);
    
    // buffer left arm
    for (long index = 0; index < stringLeftArmSize; index++) { buffer[index] = string->address[index]; } 
    
    // buffer middle 
    for (long index = 0; index < chunk->size; index++) { buffer[position + index] = chunk->address[index]; } 
        
    // buffer right arm
    for (long index = 0; index < stringRightArmSize; index++) 
    {
        buffer[position + chunk->size + index] = string->address[stringRightArmStart + index];
    }
    
    return makeString(buffer, bufferSize);
}

String createStringReplace(String* string, String* target, String* chunk) // allocates heap memory
{
    long position = stringIndexOf(string, target) - 1; // '-1' adjusts to zero index
    
    if (position == -1) { return createStringClone(string); } // target not found
    
    if (position == 0) { return createStringReplaceStart(string, target->size, chunk); }
    
    if (position + target->size == string->size) { return createStringReplaceEnd(string, target->size, chunk); }
    
    return _createStringReplace(string, target, chunk, position);
}

String createStringReplaceLast(String* string, String* target, String* chunk) // allocates heap memory
{
    long position = stringLastIndexOf(string, target) - 1; // '-1' adjusts to zero index
    
    if (position == -1) { return createStringClone(string); } // target not found
    
    if (position == 0) { return createStringReplaceStart(string, target->size, chunk); }
    
    if (position + target->size == string->size) { return createStringReplaceEnd(string, target->size, chunk); }
    
    return _createStringReplace(string, target, chunk, position);
}

// replace all by target //////////////////////////////////////////////////////

String createStringReplaceAll(String* string, String* target, String* chunk) // allocates heap memory
{
    long count = stringCountOf(string, target);
    
    if (count == 0) { return createStringClone(string); }
    
    long bufferSize = string->size + count * (chunk->size - target->size);
    
    if (bufferSize == 0) { return makeStringEmpty(); }

    char* buffer = heapAllocate(bufferSize);

    long bufferIndex = -1;
    
    String temp = makeString(string->address, string->size);
    
    while (temp.size > 0) {

        bool startsNormal = true;
        
        if (temp.address[0] == target->address[0]) 
        {
            startsNormal = ! stringStartsWith(&temp, target); // avoiding always call the function
        }
   
        if (startsNormal) {
        
            bufferIndex += 1; 
            buffer[bufferIndex] = temp.address[0];            
        
            temp.size -= 1;            
            temp.address += 1;
        
            continue;        
        }
        
        // skipping the target
        temp.size -= target->size;        
        temp.address += target->size;
        
        // inserting the chunk        
        for (long index = 0; index < chunk->size; index++) 
        { 
            bufferIndex += 1;
            buffer[bufferIndex] = chunk->address[index];
        }
    }
            
    return makeString(buffer, bufferSize);
}

