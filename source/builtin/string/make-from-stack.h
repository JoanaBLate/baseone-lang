// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// creating String on the stack:
// must be hard coded by the compiler
// inside the body of the user's C function,
// then makeString will be called

String makeString(char* address, long size) // just the struct
{
    String string = { address, size };
    
    return string;
}

String makeStringEmpty() // just the struct
{
    return makeString(NULL, 0);
}

String makeStringFromByte(char* address) // just the struct
{   
    return makeString(address, 1);
}

String makeStringFromLiteral(char* cString) // just the struct
{   
    long size = strlen(cString);
    
    if (size == 0) { return makeStringEmpty(); }
    
    return makeString(cString, size);
}

String makeStringCopy(String string) // just the struct
{   
    if (string.size == 0) { return makeStringEmpty(); }
    
    return makeString(string.address, string.size);
}

// for type compatibility of builtin function arguments ONLY
String makeStringFromHeapBuffer(HeapBuffer hb) // just the struct 
{   
    if (hb.size == 0) { return makeStringEmpty(); }
    
    return makeString(hb.address + hb.margin, hb.size);
}

