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

