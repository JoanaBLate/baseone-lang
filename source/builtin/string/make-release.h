// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// address == NULL means that the string must not be released,
// because it is just a slice or based on literal

String makeString(char* address, char* data, long size)
{
    String string = { address, data, size };
    
    return string;
}

String makeStringEmpty()
{
    return makeString(NULL, NULL, 0);
}

String makeStringClone(String string) // not a new object in heap!
{   
    return makeString(NULL, string.data, string.size);
}

String makeStringFromLiteral(char* cString)
{   
    long size = strlen(cString);
    
    if (size == 0) { return makeStringEmpty(); }
    
    return makeString(NULL, cString, size);
}

void releaseStringData(String string)
{
    if (string.address == 0) 
    { 
        printf("\nERROR: the string data cannot be released: this string is not the owner of the data\n"); exit(1); 
    }
    heapRelease(string.address);
}

String makePseudoStringFromStackString(StackString stk) // pseudo because may be mutated indirectly
{
    return makeString(NULL, stk.data, stk.size);
}

String makePseudoStringFromBufferString(StackString buf) // pseudo because may be mutated indirectly
{
    return makeString(NULL, buf.data, buf.size);
}

