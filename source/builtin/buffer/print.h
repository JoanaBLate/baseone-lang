// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void printBufferBytes(Buffer* buffer)
{    
    String string = makeStringFromBuffer(buffer);
    
    printStringBytes(&string);
}

void printBufferRunes(Buffer* buffer)
{    
    String string = makeStringFromBuffer(buffer);
    
    printStringRunes(&string);
}

void displayBuffer(Buffer* buffer)
{
    printf("[");
    printBufferRunes(buffer);
    printf("]  margin: %li   size: %li  capacity: %li\n",  buffer->margin, buffer->size, buffer->capacity);
}

