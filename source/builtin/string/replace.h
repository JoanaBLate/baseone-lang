// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// replace by position ////////////////////////////////////////////////////////

String newStringReplaceStart(String string, long count, String chunk) // allocates memory
{    
    if (count < 1) { return newStringClone(string); } 
    
    if (count >= string.size) { return newStringClone(chunk); }
    
    long stringRightArmStart = count;
    long stringRightArmSize = string.size - count;
    
    long bufferSize = chunk.size + stringRightArmSize;
    
    char* buffer = heapAllocate(bufferSize);
    
    // buffer left arm
    for (long index = 0; index < chunk.size; index++) { buffer[index] = chunk.data[index]; } 
        
    // buffer right arm
    for (long index = 0; index < stringRightArmSize; index++) 
    {
        buffer[chunk.size + index] = string.data[stringRightArmStart + index];
    }
    
    return makeString(buffer, bufferSize);
}

String newStringReplaceEnd(String string, long count, String chunk) // allocates memory
{    
    if (count < 1) { return newStringClone(string); } 
    
    if (count >= string.size) { return newStringClone(chunk); } 
    
 // long stringLeftArmStart = 0;
    long stringLeftArmSize = string.size - count;
    
    long bufferSize = stringLeftArmSize + chunk.size;
    
    char* buffer = heapAllocate(bufferSize);
    
    // buffer left arm
    for (long index = 0; index < stringLeftArmSize; index++) { buffer[index] = string.data[index]; } 
    
    // buffer right arm
    for (long index = 0; index < chunk.size; index++) { buffer[stringLeftArmSize + index] = chunk.data[index]; } 
        
    return makeString(buffer, bufferSize);
}

// replace by target //////////////////////////////////////////////////////////

String newStringReplace2(String string, String target, String chunk, long position) // allocates memory
{
 // long stringLeftArmStart = 0;
    long stringLeftArmSize = position;
    
    long stringRightArmStart = position + target.size;
    long stringRightArmSize = string.size - stringLeftArmSize - target.size;
    
    long bufferSize = stringLeftArmSize + chunk.size + stringRightArmSize;
    
    char* buffer = heapAllocate(bufferSize);
    
    // buffer left arm
    for (long index = 0; index < stringLeftArmSize; index++) { buffer[index] = string.data[index]; } 
    
    // buffer middle 
    for (long index = 0; index < chunk.size; index++) { buffer[position + index] = chunk.data[index]; } 
        
    // buffer right arm
    for (long index = 0; index < stringRightArmSize; index++) 
    {
        buffer[position + chunk.size + index] = string.data[stringRightArmStart + index];
    }
    
    return makeString(buffer, bufferSize);
}

String newStringReplace(String string, String target, String chunk) // allocates memory (indirectly)
{
    long position = stringIndexOf(string, target) - 1; // '-1' adjusts to zero index
    
    if (position == -1) { return newStringClone(string); } // target not found
    
    if (position == 0) { return newStringReplaceStart(string, target.size, chunk); }
    
    if (position + target.size == string.size) { return newStringReplaceEnd(string, target.size, chunk); }
    
    return newStringReplace2(string, target, chunk, position);
}

String newStringReplaceLast(String string, String target, String chunk) // allocates memory (indirectly)
{
    long position = stringLastIndexOf(string, target) - 1; // '-1' adjusts to zero index
    
    if (position == -1) { return newStringClone(string); } // target not found
    
    if (position == 0) { return newStringReplaceStart(string, target.size, chunk); }
    
    if (position + target.size == string.size) { return newStringReplaceEnd(string, target.size, chunk); }
    
    return newStringReplace2(string, target, chunk, position);
}

// replace all by target //////////////////////////////////////////////////////

String newStringReplaceAll(String string, String target, String chunk) // allocates memory
{
    long count = stringCountOf(string, target);
    
    if (count == 0) { return newStringClone(string); }
    
    long bufferSize = string.size + count * (chunk.size - target.size);
    
    if (bufferSize == 0) { return makeStringEmpty(); }

    char* buffer = heapAllocate(bufferSize);

    long bufferIndex = -1;
    
    String temp = makeString(string.data, string.size);
    
    while (temp.size > 0) {

        bool startsNormal = true;
        
        if (temp.data[0] == target.data[0]) 
        {
            startsNormal = ! stringStartsWith(temp, target); // avoiding always call the function
        }
   
        if (startsNormal) {
        
            bufferIndex += 1; 
            buffer[bufferIndex] = temp.data[0];            
        
            temp.size -= 1;            
            temp.data += 1;
        
            continue;        
        }
        
        // skipping the target
        temp.size -= target.size;        
        temp.data += target.size;
        
        // inserting the chunk        
        for (long index = 0; index < chunk.size; index++) 
        { 
            bufferIndex += 1;
            buffer[bufferIndex] = chunk.data[index];
        }
    }
            
    return makeString(buffer, bufferSize);
}

