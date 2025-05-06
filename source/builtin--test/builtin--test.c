// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// IMPLICITLY TESTED:
// makeString, makeStringEmpty, makeStringFromLiteral, createString

// NOT TESTED:
// makeStringCopy, getStringSize

// TESTED SOMEWHERE ELSE (Advent Of Code puzzles):
// stringBufferEatLine, stringBufferEatToken, stringBufferEatLongInt 
// Memory, Hashmap and ArrayList functions

#include "../builtin/builtin.h"
#include "file/file--test.h"
#include "string/info--test.h"
#include "string/append-insert-pad--test.h"
#include "string/lower-reverse-sort--test.h"
#include "string/clone-repeat-byte-number--test.h"
#include "string/print--test.h"
#include "string/remove--test.h"
#include "string/replace--test.h"
#include "string/substring--test.h"
#include "string/trim--test.h"

#include "string-buffer/trim--test.h"
#include "string-buffer/trim-target--test.h"


int main()
{
    // file
    
    testReadTextFile();
    
    // String (1)

    testStringCharCodeAt();
    testStringsAreEquals();
    testStringContains();
    testStringEndsWith();
    testStringStartsWith();
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
    
    // StringBuffer    

    testStringBufferTrimStart();
    testStringBufferTrimEnd();
    testStringBufferTrim();
        
    testStringBufferTrimStartTarget();
    testStringBufferTrimEndTarget();
    testStringBufferTrimTarget();    

    // String (2)

    testPrintStringA();
    testPrintStringB();
    testPrintStringC();
    
    return 0;
}

