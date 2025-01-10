// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

String createStringReplaceStart(String *string, int count, String *chunk)
{    
    if (count < 1) { return createStringClone(string); } 
    
    if (count >= string->size) { return createStringClone(chunk); }
    
    int stringRightArmStart = count;
    int stringRightArmSize = string->size - count;
    
    int bufferSize = chunk->size + stringRightArmSize;
    
    char *buffer = malloc(bufferSize);
    
    // buffer left arm
    for (int index = 0; index < chunk->size; index++) { buffer[index] = chunk->data[index]; } 
        
    // buffer right arm
    for (int index = 0; index < stringRightArmSize; index++) 
    {
        buffer[chunk->size + index] = string->data[stringRightArmStart + index];
    }
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createStringReplaceEnd(String *string, int count, String *chunk)
{    
    if (count < 1) { return createStringClone(string); } 
    
    if (count >= string->size) { return createStringClone(chunk); } 
    
    int stringLeftArmStart = 0;
    int stringLeftArmSize = string->size - count;
    
    int bufferSize = stringLeftArmSize + chunk->size;
    
    char *buffer = malloc(bufferSize);
    
    // buffer left arm
    for (int index = 0; index < stringLeftArmSize; index++) { buffer[index] = string->data[index]; } 
    
    // buffer right arm
    for (int index = 0; index < chunk->size; index++) { buffer[stringLeftArmSize + index] = chunk->data[index]; } 
        
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createStringReplace(String *string, String *target, String *chunk)
{
    int position = stringIndexOf(string, target) - 1; // '-1' adjusts to zero index
    
    if (position == -1) { return createStringClone(string); } // target not found
    
    if (position == 0) { return createStringReplaceStart(string, target->size, chunk); }
    
    if (position + target->size == string->size) { return createStringReplaceEnd(string, target->size, chunk); }
    
    //
    
    int stringLeftArmStart = 0;
    int stringLeftArmSize = position;
    
    int stringRightArmStart = position + target->size;
    int stringRightArmSize = string->size - stringLeftArmSize - target->size;
    
    int bufferSize = stringLeftArmSize + chunk->size + stringRightArmSize;
    
    char *buffer = malloc(bufferSize);
    
    // buffer left arm
    for (int index = 0; index < stringLeftArmSize; index++) { buffer[index] = string->data[index]; } 
    
    // buffer middle 
    for (int index = 0; index < chunk->size; index++) { buffer[position + index] = chunk->data[index]; } 
        
    // buffer right arm
    for (int index = 0; index < stringRightArmSize; index++) 
    {
        buffer[position + chunk->size + index] = string->data[stringRightArmStart + index];
    }
    
    String newString = { bufferSize, buffer };
    
    return newString;
}

String createStringRemove(String *string, String *target)
{
    String empty = createEmptyString();
    
    return createStringReplace(string, target, &empty);
}

