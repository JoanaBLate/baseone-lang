
/*
    abandoned because having a limited StringBuffer would be confusing,
    only useful in corner cases, and those corner cases could be solved
    in other ways
*/



// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// creating StringBuffer on the stack:
// must be hard coded by the compiler
// inside the body of the user's C function,
// then makeStringBuffer will be called

// only for the stack
StringBuffer makeStringBuffer(char* address, long capacity) // just the struct
{
    StringBuffer sb = { address, capacity, 0, 0 };
    
    return sb;
}

// only for the stack
StringBuffer makeStringBufferFromLiteral(char* cString) // just the struct
{
    long length = strlen(cString);
    
    StringBuffer sb = { cString, length, 0, length };
    
    return sb;
}
