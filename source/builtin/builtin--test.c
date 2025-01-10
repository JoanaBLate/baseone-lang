// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

#include "builtin.h"
#include "file/file--test.h"
#include "string/create-clone-repeat--test.h"
#include "string/info--test.h"
#include "string/substr-start-end--test.h"
#include "string/pad-insert--test.h"
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
    
    testCreateEmptyString();
    testCreateStringFromCharCode();
    testCreateStringFromLiteral();
    testCreateStringClone();
    testCreateRepeatedString();
    
    testCreateStringStart(); 
    testCreateStringEnd(); 
    testCreateSubstring(); 
        
    testCreateAppendedString(); 
    testCreateInsertedString(); 
    testCreatePaddedStartString();
    testCreatePaddedEndString();
    
    testCreateStringRemove();
    testCreateStringReplaceStart();
    testCreateStringReplaceEnd();
    testCreateStringReplace();
    
    testCreateStringCutStart();
    testCreateStringCutEnd();
    testCreateStringCutMiddle();
        
    testCreateStringTrimStart();
    testCreateStringTrimEnd();
    testCreateStringTrim();
    
    testCreateStringToLower();
    testCreateStringToUpper();
    testCreateStringToOppositeCase();
    testCreateReversedString();
    testCreateSortedString();
    
    testPrintStringA();
    testPrintStringB();
    testPrintStringC();
    
    return 0;
}

