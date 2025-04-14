// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// makeString, makeStringEmpty and makeStringFromLiteral
// are implicitly tested among the other function testes

// stringEatLine, stringEatToken, stringEatLongInt 
// and Hashmap and ArrayList functions
// are tested with Advent Of Code puzzles somewhere else
// TODO: make the tests here too


#include "../builtin/builtin.h"
#include "file/file--test.h"
#include "string/append-insert-pad--test.h"
#include "string/eat--test.h"
#include "string/info--test.h"
#include "string/lower-reverse-sort--test.h"
#include "string/make-clone-repeat--test.h"
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
 
    testNewStringFromCharCode();
    testNewStringClone();
    testNewStringRepeat();

    testStringSliceStart(); 
    testStringSliceEnd(); 
    testStringSlice(); 
        
    testNewStringAppend(); 
    testNewStringInsert(); 
    testNewStringPadStart();
    testNewStringPadEnd();
    
    testNewStringRemove();
    testNewStringRemoveLast();
    testNewStringRemoveAll();
    testNewStringReplaceStart();
    testNewStringReplaceEnd();
    testNewStringReplace();
    testNewStringReplaceLast();
    testNewStringReplaceAll();

    testStringEatStart();
    testStringEatEnd();
        
    testStringTrimStart();
    testStringTrimEnd();
    testStringTrim();

    testStringTrimStartTarget();
    testStringTrimEndTarget();
    testStringTrimTarget();
    
    testNewStringToLower();
    testNewStringToUpper();
    testNewStringToOppositeCase();
    testNewStringReverse();
    testNewStringSort();
       
    testPrintStringA();
    testPrintStringB();
    testPrintStringC();
 
    return 0;
}

