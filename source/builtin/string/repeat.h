// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


String createStringRepeat(String string, long count) // allocates heap memory
{
    if (string.size == 0) { return makeStringEmpty(); }
    
    if (count <= 0) { return makeStringEmpty(); }
    
    long bufferSize = count * string.size;

    char* buffer = heapAllocate(bufferSize);
    
    for (long turn = 0; turn < count; turn++) 
    { 
        memcpy(&buffer[turn * string.size], string.address, string.size); 
    }

    return makeString(buffer, bufferSize);
}

