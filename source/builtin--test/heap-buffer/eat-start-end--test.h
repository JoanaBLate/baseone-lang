// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void _testHeapBufferEatStart(HeapBuffer* hb, long size, char* literal1,  char* literal2) 
{
    bool fails = false;

    String result1 = heapBufferEatStart(hb, size);    
    String result2 = createStringFromHeapBuffer(*hb);
    
    String expected1 = makeStringFromLiteral(literal1);
    String expected2 = makeStringFromLiteral(literal2);           
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    releaseString(result1);
    releaseString(result2);

    if (fails) { 
        printf("heapBufferEatStart FAILS!\n"); 
        exit(1);
    }
}

void testHeapBufferEatStart() 
{
    printf("- testing heapBufferEatStart\n");  
    
    HeapBuffer hbEmpty = createHeapBufferEmpty();    
        
    HeapBuffer hbSource = createHeapBufferFromLiteral("123Life is ∆ rock123");    

    hbSource.margin = 3; hbSource.size -= 6;
    
    _testHeapBufferEatStart(&hbSource,  5, "Life ", "is ∆ rock"); 

    _testHeapBufferEatStart(&hbSource,  0, "", "is ∆ rock"); 

    _testHeapBufferEatStart(&hbSource, -9, "", "is ∆ rock"); 

    _testHeapBufferEatStart(&hbSource, 300, "is ∆ rock", ""); 
    
    releaseHeapBuffer(hbEmpty);
    releaseHeapBuffer(hbSource);
}

void _testHeapBufferEatEnd(HeapBuffer* hb, long size, char* literal1,  char* literal2) 
{
    bool fails = false;

    String result1 = heapBufferEatEnd(hb, size);    
    String result2 = createStringFromHeapBuffer(*hb);
    
    String expected1 = makeStringFromLiteral(literal1);
    String expected2 = makeStringFromLiteral(literal2); 
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    releaseString(result1);
    releaseString(result2);

    if (fails) { 
        printf("heapBufferEatEnd FAILS!\n"); 
        exit(1);
    }
}

void testHeapBufferEatEnd() 
{
    printf("- testing heapBufferEatEnd\n");  
    
    HeapBuffer hbEmpty = createHeapBufferEmpty();    
        
    HeapBuffer hbSource = createHeapBufferFromLiteral("123Life is ∆ rock123");    

    hbSource.margin = 3; hbSource.size -= 6;
    
    _testHeapBufferEatEnd(&hbSource,  5,  " rock", "Life is ∆"); 

    _testHeapBufferEatEnd(&hbSource,  0, "", "Life is ∆"); 

    _testHeapBufferEatEnd(&hbSource, -9, "", "Life is ∆"); 

    _testHeapBufferEatEnd(&hbSource, 300, "Life is ∆", ""); 
    
    releaseHeapBuffer(hbEmpty);
    releaseHeapBuffer(hbSource);
}

