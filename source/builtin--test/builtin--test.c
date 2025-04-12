// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

#include "../builtin/builtin.h"
#include "file/file--test.h"
#include "string/info--test.h"
#include "string/create-clone-repeat--test.h"
#include "string/substr-start-end--test.h"
#include "string/pad-insert-append--test.h"
#include "string/remove-replace--test.h"
#include "string/cut-trim--test.h"
#include "string/lower-reverse-sort--test.h"
#include "string/print--test.h"

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
    testStringCountOfTarget();
        
 // testCreateString(); // not necessary, implicitly tested
 // testCreateStringEmpty(); // not necessary, implicitly tested
 // testCreateStringFromLiteral(); // not necessary, implicitly tested
 
    testCreateStringFromCharCode();
    testCreateStringClone();
    testCreateStringRepeat();

    testCreateStringStart(); 
    testCreateStringEnd(); 
    testCreateStringSub(); 
        
    testCreateStringAppend(); 
    testCreateStringInsert(); 
    testCreateStringPadStart();
    testCreateStringPadEnd();
    
    testCreateStringRemove();
    testCreateStringRemoveAll();
    testCreateStringReplaceStart();
    testCreateStringReplaceEnd();
    testCreateStringReplace();
    testCreateStringReplaceAll();
    
    testCreateStringCutStart();
    testCreateStringCutEnd();
    testCreateStringCutMiddle();
        
    testCreateStringTrimStart();
    testCreateStringTrimEnd();
    testCreateStringTrim();
    
    testCreateStringTrimStartIt();
    testCreateStringTrimEndIt();
    testCreateStringTrimIt();
    
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
