// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

#include "builtin.h"
#include "file-heap/file--test.h"
#include "string-neutral/empty--test.h"
#include "string-neutral/info--test.h"
#include "string-heap/create-clone-repeat--test.h"
#include "string-heap/substr-start-end--test.h"
#include "string-heap/pad-insert-append--test.h"
#include "string-heap/remove-replace--test.h"
#include "string-heap/cut-trim--test.h"
#include "string-heap/lower-reverse-sort--test.h"
#include "string-neutral/print--test.h"

int main()
{
    testReadTextFileHeap();

    testCreateStringEmpty();

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
    
    testCreateStringFromCharCodeHeap();
    testCreateStringFromLiteralHeap();
    testCreateStringCloneHeap();
    testCreateStringRepeatHeap();
    
    testCreateStringStartHeap(); 
    testCreateStringEndHeap(); 
    testCreateStringSubHeap(); 
        
    testCreateStringAppendHeap(); 
    testCreateStringInsertHeap(); 
    testCreateStringPadStartHeap();
    testCreateStringPadEndHeap();
    
    testCreateStringRemoveHeap();
    testCreateStringRemoveAllHeap();
    testCreateStringReplaceStartHeap();
    testCreateStringReplaceEndHeap();
    testCreateStringReplaceHeap();
    testCreateStringReplaceAllHeap();
    
    testCreateStringCutStartHeap();
    testCreateStringCutEndHeap();
    testCreateStringCutMiddleHeap();
        
    testCreateStringTrimStartHeap();
    testCreateStringTrimEndHeap();
    testCreateStringTrimHeap();
    
    testCreateStringToLowerHeap();
    testCreateStringToUpperHeap();
    testCreateStringToOppositeCaseHeap();
    testCreateStringReverseHeap();
    testCreateStringSortHeap();
    
    testPrintStringA();
    testPrintStringB();
    testPrintStringC();
    
    return 0;
}

