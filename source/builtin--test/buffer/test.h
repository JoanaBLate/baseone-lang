// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// TESTED SOMEWHERE ELSE (Advent Of Code puzzles):
// bufferEatLine, bufferEatToken, bufferEatLongInt 


#include "info--test.h"
#include "lower-reverse-sort--test.h"
#include "trim--test.h"
#include "trim-target--test.h"
#include "trim-any--test.h"
#include "eat-start-end--test.h"
#include "replace--test.h"
#include "print--test.h"

void testBuffer()
{    
    testBufferByteAt();
    testBuffersAreEquals();
    testBufferContains();
    testBufferStartsWith();
    testBufferEndsWith();
    testBufferIndexOf();
    testBufferLastIndexOf();
    testBufferIndexOfAfter();
    testBufferLastIndexOfBefore();
    testBufferCountOf();
    
    testBufferToLower();
    testBufferToUpper();
    testBufferToOppositeCase();
    testBufferReverse();
    testBufferSort();

    testBufferTrimStart();
    testBufferTrimEnd();
    testBufferTrim();
        
    testBufferTrimStartTarget();
    testBufferTrimEndTarget();
    testBufferTrimTarget(); 
       
    testBufferTrimStartAny();
    testBufferTrimEndAny();
    testBufferTrimAny(); 
    
    testBufferEatStart();
    testBufferEatEnd();
    
    testBufferReplaceStart();
    testBufferReplaceEnd();
    testBufferReplace();
    testBufferReplaceLast();
    testBufferReplaceAll();
    
    testPrintBufferA();
    testPrintBufferB();
    testPrintBufferC();
}

