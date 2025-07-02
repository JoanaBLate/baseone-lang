// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void _testBufferPadStart(Buffer* buffer, String* chunk, long count, String* expected) 
{  
    bufferPadStart(buffer, chunk, count);    

    String result = makeStringFromBuffer(buffer);
       
    if (stringsAreEqual(&result, expected)) { return; }
    
    printf("bufferPadStart FAILS!\n"); exit(1);
}

void testBufferPadStart()
{
    printf("- testing bufferPadStart\n");
    
    Buffer buffer = createBufferFromLiteral("Life is ∆ rock");
    String chunk  = makeStringEmpty();
    String expected = makeStringFromLiteral("Life is ∆ rock");    
    _testBufferPadStart(&buffer, &chunk, 10, &expected);
    
    chunk = makeStringFromLiteral("(^-^) ");
    _testBufferPadStart(&buffer, &chunk, 0, &expected);
    
    expected = makeStringFromLiteral("(^-^) (^-^) Life is ∆ rock");
    _testBufferPadStart(&buffer, &chunk, 2, &expected);

    releaseBuffer(&buffer);

    buffer = createBufferFromLiteral("123456789012345Life is ∆ rock");
    buffer.margin = 15;
    buffer.size -= 15;
    expected = makeStringFromLiteral("(^-^) (^-^) Life is ∆ rock");
    _testBufferPadStart(&buffer, &chunk, 2, &expected);
     
    releaseBuffer(&buffer);

    buffer = createBufferFromLiteral("12Life is ∆ rock!");
    buffer.margin = 2;
    buffer.size -= 2;
    expected = makeStringFromLiteral("(^-^) (^-^) Life is ∆ rock!");
    _testBufferPadStart(&buffer, &chunk, 2, &expected);

    releaseBuffer(&buffer);
} 

void _testBufferPadEnd(Buffer* buffer, String* chunk, long count, String* expected)
{
    bufferPadEnd(buffer, chunk, count);  

    String result = makeStringFromBuffer(buffer);
       
    if (stringsAreEqual(&result, expected)) { return; }
    
    printf("bufferPadEnd FAILS!\n"); exit(1);
}

void testBufferPadEnd()
{
    printf("- testing bufferPadEnd\n");
    
    Buffer buffer = createBufferFromLiteral("Life is ∆ rock");
    String chunk  = makeStringEmpty();
    String expected = makeStringFromLiteral("Life is ∆ rock");    
    _testBufferPadEnd(&buffer, &chunk, 10, &expected);
    
    chunk = makeStringFromLiteral("(^-^) ");
    _testBufferPadEnd(&buffer, &chunk, 0, &expected);
    
    expected = makeStringFromLiteral("Life is ∆ rock(^-^) (^-^) ");
    _testBufferPadEnd(&buffer, &chunk, 2, &expected);

    releaseBuffer(&buffer);

    buffer = createBufferFromLiteral("123456789012345Life is ∆ rock");
    buffer.margin = 15;
    buffer.size -= 15;
    expected = makeStringFromLiteral("Life is ∆ rock(^-^) (^-^) ");
    _testBufferPadEnd(&buffer, &chunk, 2, &expected);
     
    releaseBuffer(&buffer);

    buffer = createBufferFromLiteral("12Life is ∆ rock!");
    buffer.margin = 2;
    buffer.size -= 2;
    expected = makeStringFromLiteral("Life is ∆ rock!(^-^) (^-^) ");
    _testBufferPadEnd(&buffer, &chunk, 2, &expected);

    releaseBuffer(&buffer);
} 
 
