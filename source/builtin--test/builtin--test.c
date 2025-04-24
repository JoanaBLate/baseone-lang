// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

// IMPLICITLY TESTED:
// makeString, makeStringEmpty, makeStringFromLiteral, createString

// NOT TESTED:
// makeStringClone, getStringSize

// TESTED SOMEWHERE ELSE (Advent Of Code puzzles):
// stringEatLine, stringEatToken, stringEatLongInt 
// Memory, Hashmap and ArrayList functions


#include "../builtin/builtin.h"
#include "file/file--test.h"
#include "string/append-insert-pad--test.h"
#include "string/eat--test.h"
#include "string/info--test.h"
#include "string/lower-reverse-sort--test.h"
#include "string/clone-repeat-char-number--test.h"
#include "string/print--test.h"
#include "string/remove--test.h"
#include "string/replace--test.h"
#include "string/slice--test.h"
#include "string/trim--test.h"

int main()
{
    testReadTextFile();

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
 
    testCreateStringFromCharCode();
    testCreateStringClone();
    testCreateStringRepeat();
    testCreateStringFromLong();

    testStringSliceStart(); 
    testStringSliceEnd(); 
    testStringSlice(); 
        
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

    testStringEatStart();
    testStringEatEnd();
        
    testStringTrimStart();
    testStringTrimEnd();
    testStringTrim();

    testStringTrimStartTarget();
    testStringTrimEndTarget();
    testStringTrimTarget();
    
    testCreateStringToLower();
    testCreateStringToUpper();
    testCreateStringToOppositeCase();
    testCreateStringReverse();
    testCreateStringSort();
       
    testPrintStringA();
    testPrintStringB();
    testPrintStringC();
 
    return 0;
}

