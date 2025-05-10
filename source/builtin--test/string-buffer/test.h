// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// TESTED SOMEWHERE ELSE (Advent Of Code puzzles):
// stringBufferEatLine, stringBufferEatToken, stringBufferEatLongInt 


#include "info--test.h"
#include "trim--test.h"
#include "trim-target--test.h"
#include "trim-any--test.h"

void testStringBuffer()
{    
    testStringBufferCharCodeAt();
    testStringBuffersAreEquals();
    testStringBufferContains();
    testStringBufferStartsWith();
    testStringBufferEndsWith();
    testStringBufferIndexOf();
    testStringBufferLastIndexOf();
    testStringBufferIndexOfAfter();
    testStringBufferLastIndexOfBefore();
    testStringBufferCountOf();

    testStringBufferTrimStart();
    testStringBufferTrimEnd();
    testStringBufferTrim();
        
    testStringBufferTrimStartTarget();
    testStringBufferTrimEndTarget();
    testStringBufferTrimTarget(); 
       
    testStringBufferTrimStartAny();
    testStringBufferTrimEndAny();
    testStringBufferTrimAny(); 
}

