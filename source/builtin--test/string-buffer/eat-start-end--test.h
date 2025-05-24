// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void _testStringBufferEatStart(StringBuffer* sb, long size, char* literal1,  char* literal2) 
{
    bool fails = false;

    String result1 = stringBufferEatStart(sb, size);    
    String result2 = createStringFromStringBuffer(*sb);
    
    String expected1 = makeStringFromLiteral(literal1);
    String expected2 = makeStringFromLiteral(literal2);           
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    releaseString(result1);
    releaseString(result2);

    if (fails) { 
        printf("stringBufferEatStart FAILS!\n"); 
        exit(1);
    }
}

void testStringBufferEatStart() 
{
    printf("- testing stringBufferEatStart\n");  
    
    StringBuffer sbEmpty = createStringBufferEmpty();    
        
    StringBuffer sbSource = createStringBufferFromLiteral("123Life is ∆ rock123");    

    sbSource.margin = 3; sbSource.size -= 6;
    
    _testStringBufferEatStart(&sbSource,  5, "Life ", "is ∆ rock"); 

    _testStringBufferEatStart(&sbSource,  0, "", "is ∆ rock"); 

    _testStringBufferEatStart(&sbSource, -9, "", "is ∆ rock"); 

    _testStringBufferEatStart(&sbSource, 300, "is ∆ rock", ""); 
    
    releaseStringBuffer(sbEmpty);
    releaseStringBuffer(sbSource);
}

void _testStringBufferEatEnd(StringBuffer* sb, long size, char* literal1,  char* literal2) 
{
    bool fails = false;

    String result1 = stringBufferEatEnd(sb, size);    
    String result2 = createStringFromStringBuffer(*sb);
    
    String expected1 = makeStringFromLiteral(literal1);
    String expected2 = makeStringFromLiteral(literal2); 
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    releaseString(result1);
    releaseString(result2);

    if (fails) { 
        printf("stringBufferEatEnd FAILS!\n"); 
        exit(1);
    }
}

void testStringBufferEatEnd() 
{
    printf("- testing stringBufferEatEnd\n");  
    
    StringBuffer sbEmpty = createStringBufferEmpty();    
        
    StringBuffer sbSource = createStringBufferFromLiteral("123Life is ∆ rock123");    

    sbSource.margin = 3; sbSource.size -= 6;
    
    _testStringBufferEatEnd(&sbSource,  5,  " rock", "Life is ∆"); 

    _testStringBufferEatEnd(&sbSource,  0, "", "Life is ∆"); 

    _testStringBufferEatEnd(&sbSource, -9, "", "Life is ∆"); 

    _testStringBufferEatEnd(&sbSource, 300, "Life is ∆", ""); 
    
    releaseStringBuffer(sbEmpty);
    releaseStringBuffer(sbSource);
}

