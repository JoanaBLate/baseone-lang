// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// IMPLICITLY TESTED:
// makeString, makeStringEmpty, makeStringFromLiteral, createString

// NOT TESTED:
// makeStringCopy, getStringSize

#include "info--test.h"
#include "append-insert-pad--test.h"
#include "lower-reverse-sort--test.h"
#include "clone-repeat-byte-number--test.h"
#include "print--test.h"
#include "remove--test.h"
#include "replace--test.h"
#include "substring--test.h"
#include "trim--test.h"

void testString()
{
    testStringCharCodeAt();
    testStringsAreEquals();
    testStringContains();
    testStringStartsWith();
    testStringEndsWith();
    testStringIndexOf();
    testStringLastIndexOf();
    testStringIndexOfAfter();
    testStringLastIndexOfBefore();
    testStringCountOf();

    testCreateStringFromByte();
    testCreateStringClone();
    testCreateStringRepeat();
    testCreateStringFromLong();
        
    testCreateStringAppend(); 
    testCreateStringInsert();     
    testCreateStringPadStart();
    testCreateStringPadEnd();
    
    testCreateStringRemove();
    testCreateStringRemoveLast();
    testCreateStringRemoveAll();
    
    testCreateStringReplaceStart();
    testCreateStringReplaceEnd();
    testCreateStringReplace();
    testCreateStringReplaceLast();
    testCreateStringReplaceAll();
    
    testCreateStringToLower();
    testCreateStringToUpper();
    testCreateStringToOppositeCase();
    testCreateStringReverse();
    testCreateStringSort();

    testCreateSubstringStart(); 
    testCreateSubstringEnd(); 
    testCreateSubstring(); 
    
    testStringTrimStart();
    testStringTrimEnd();
    testStringTrim();   

    testPrintStringA();
    testPrintStringB();
    testPrintStringC();
}

