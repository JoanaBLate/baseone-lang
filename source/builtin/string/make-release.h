// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


String makeString(char* data, long size)
{
    String string = { data, data, size };
    
    return string;
}

String makeStringEmpty()
{
    return makeString(NULL, 0);
}

String makeStringClone(String string) // will not adjust is address: it is not a new object in heap
{   
    return makeString(string.data, string.size);
}

String makeStringFromLiteral(char* cString)
{   
    long size = strlen(cString);
    
    if (size == 0) { return makeStringEmpty(); }
    
    String result = makeString(cString, size);
    
    result.address = 0; // so will not be heap released

    return result;
}

void releaseString(String string)
{
    if (string.address == 0) { return; }
    
    heapRelease(string.address);
}

