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

