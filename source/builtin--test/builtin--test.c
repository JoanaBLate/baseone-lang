// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// TESTED SOMEWHERE ELSE (Advent Of Code puzzles) or implicitly tested:
// Memory, Hashmap and ArrayList functions

#include "../builtin/builtin.h"

#include "file/test.h"
#include "string/test.h"
#include "buffer/test.h"

int main()
{
    testReadTextFile();
    testBuffer();
    testString();

    printf("\nAll tests passed!\n");

    return 0;
}

