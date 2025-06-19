// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// TESTED SOMEWHERE ELSE (Advent Of Code puzzles):
// stringBufferEatLine, stringBufferEatToken, stringBufferEatLongInt 


#include "info--test.h"
#include "trim--test.h"
#include "trim-target--test.h"
#include "trim-any--test.h"
#include "eat-start-end--test.h"
#include "lower-reverse-sort--test.h"

void testHeapBuffer()
{    
    testHeapBufferCharCodeAt();
    testHeapBuffersAreEquals();
    testHeapBufferContains();
    testHeapBufferStartsWith();
    testHeapBufferEndsWith();
    testHeapBufferIndexOf();
    testHeapBufferLastIndexOf();
    testHeapBufferIndexOfAfter();
    testHeapBufferLastIndexOfBefore();
    testHeapBufferCountOf();
    
    testHeapBufferToLower();
    testHeapBufferToUpper();
    testHeapBufferToOppositeCase();
    testHeapBufferReverse();
    testHeapBufferSort();

    testHeapBufferTrimStart();
    testHeapBufferTrimEnd();
    testHeapBufferTrim();
        
    testHeapBufferTrimStartTarget();
    testHeapBufferTrimEndTarget();
    testHeapBufferTrimTarget(); 
       
    testHeapBufferTrimStartAny();
    testHeapBufferTrimEndAny();
    testHeapBufferTrimAny(); 
    
    testHeapBufferEatStart();
    testHeapBufferEatEnd();
}

