
#include "builtin.h"
#include "file/file--test.h"
#include "string/create-clone-repeat--test.h"
#include "string/info--test.h"
#include "string/substr-start-end--test.h"
#include "string/pad-insert--test.h"
#include "string/print--test.h"

int main()
{
    testReadTextFile();
    
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

    testStringCharCodeAt();
    testStringsAreEquals();
    testStringContains();
    testStringEndsWith();
    testStringStartsWith();
    testStringIndexOf();
    testStringLastIndexOf();
    testStringIndexOfAfter();
    testStringLastIndexOfBefore();
    
    testPrintStringA();
    testPrintStringB();
    testPrintStringC();
    
    return 0;
}

