// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void _testBufferReplaceStart(Buffer* buffer, long count, String chunk, String expected) 
{
    bufferReplaceStart(buffer, count, chunk);    
    
    String result = makeStringFromBuffer(*buffer);
       
    if (stringsAreEqual(result, expected)) { return; }
    
    printf("bufferReplaceStart FAILS!\n"); exit(1);
}

void testBufferReplaceStart() 
{
    printf("- testing bufferReplaceStart\n"); 
    
    Buffer source = createBufferFromLiteral(".....Hello!");
    source.margin = 5;
    source.size = 6;
    Buffer* buffer = &source;

    String chunk1 = makeStringFromLiteral("123"); 
    String expected1 = makeStringFromLiteral("123Hello!");    
    _testBufferReplaceStart(buffer, -15, chunk1, expected1);    
    
    String chunk2 = makeStringFromLiteral("AB"); 
    String expected2 = makeStringFromLiteral("ABHello!");    
    _testBufferReplaceStart(buffer, 3, chunk2, expected2);    
    
    String chunk3 = makeStringFromLiteral("abcdefghij"); 
    String expected3 = makeStringFromLiteral("abcdefghijHello!");    
    _testBufferReplaceStart(buffer, 2, chunk3, expected3);  
    
    String chunk4 = makeStringFromLiteral(""); 
    String expected4 = makeStringFromLiteral("Hello!");    
    _testBufferReplaceStart(buffer, 10, chunk4, expected4);  
    
    releaseBuffer(*buffer);
}

///////////////////////////////////////////////////////////////////////////////

void _testBufferReplaceEnd(Buffer* buffer, long count, String chunk, String expected) 
{
    bufferReplaceEnd(buffer, count, chunk);    
    
    String result = makeStringFromBuffer(*buffer);
    
    if (stringsAreEqual(result, expected)) { return; }
    
    printf("bufferReplaceEnd FAILS!\n"); exit(1);
}

void testBufferReplaceEnd() 
{
    printf("- testing bufferReplaceEnd\n"); 
    
    Buffer source = createBufferFromLiteral("XYZHello!.....");
    source.margin = 3;
    source.size = 6;
    Buffer* buffer = &source;

    String chunk1 = makeStringFromLiteral("123"); 
    String expected1 = makeStringFromLiteral("Hello!123");    
    _testBufferReplaceEnd(buffer, -15, chunk1, expected1); 
    
    String chunk2 = makeStringFromLiteral("AB"); 
    String expected2 = makeStringFromLiteral("Hello!AB");    
    _testBufferReplaceEnd(buffer, 3, chunk2, expected2);    
  
    String chunk3 = makeStringFromLiteral("abcdefghij"); 
    String expected3 = makeStringFromLiteral("Hello!abcdefghij");    
    _testBufferReplaceEnd(buffer, 2, chunk3, expected3);  
    
    String chunk4 = makeStringFromLiteral(""); 
    String expected4 = makeStringFromLiteral("Hello!");    
    _testBufferReplaceEnd(buffer, 10, chunk4, expected4);
    
    releaseBuffer(*buffer);
}

///////////////////////////////////////////////////////////////////////////////

void _testBufferReplace(Buffer* buffer, String target, String chunk, String expected) 
{
    bufferReplace(buffer, target, chunk);    
    
    String result = makeStringFromBuffer(*buffer);
    
    if (stringsAreEqual(result, expected)) { return; }
    
    printf("bufferReplace FAILS!\n"); exit(1);
}

void testBufferReplace() 
{
    printf("- testing bufferReplace\n"); 
    
    Buffer source = createBufferFromLiteral("Hello!");
    Buffer* buffer = &source;

    String target1 = makeStringFromLiteral("ll");
    String chunk1 = makeStringFromLiteral("@#"); 
    String expected1 = makeStringFromLiteral("He@#o!");    
    _testBufferReplace(buffer, target1, chunk1, expected1);

    String target2 = makeStringFromLiteral("@#");
    String chunk2 = makeStringFromLiteral(""); 
    String expected2 = makeStringFromLiteral("Heo!");    
    _testBufferReplace(buffer, target2, chunk2, expected2);

    String target3 = makeStringFromLiteral("e");
    String chunk3 = makeStringFromLiteral("ell---$$$---"); 
    String expected3 = makeStringFromLiteral("Hell---$$$---o!");    
    _testBufferReplace(buffer, target3, chunk3, expected3);
    
    buffer->margin = 4;
    buffer->size -= 4;
    
    String target4 = makeStringFromLiteral("---$$$---o!");
    String chunk4 = makeStringFromLiteral(">[^]<"); 
    String expected4 = makeStringFromLiteral(">[^]<");    
    _testBufferReplace(buffer, target4, chunk4, expected4);
        
    String target5 = makeStringFromLiteral("^");
    String chunk5 = makeStringFromLiteral("Life is ∆ rock! Life is ∆ rock!"); 
    String expected5 = makeStringFromLiteral(">[Life is ∆ rock! Life is ∆ rock!]<");    
    _testBufferReplace(buffer, target5, chunk5, expected5);

    releaseBuffer(*buffer);
}

///////////////////////////////////////////////////////////////////////////////

void _testBufferReplaceLast(Buffer* buffer, String target, String chunk, String expected) 
{
    bufferReplaceLast(buffer, target, chunk);    
    
    String result = makeStringFromBuffer(*buffer);
    
    if (stringsAreEqual(result, expected)) { return; }
    
    printf("bufferReplaceLast FAILS!\n"); exit(1);
}

void testBufferReplaceLast() // bufferReplaceLast basically uses the same code as bufferReplace
{
    printf("- testing bufferReplaceLast\n"); 
    
    Buffer source = createBufferFromLiteral("Hello!");
    Buffer* buffer = &source;

    String target1 = makeStringFromLiteral("l");
    String chunk1 = makeStringFromLiteral("∆"); 
    String expected1 = makeStringFromLiteral("Hel∆o!");    
    _testBufferReplaceLast(buffer, target1, chunk1, expected1);

    releaseBuffer(*buffer);
}

///////////////////////////////////////////////////////////////////////////////

void _testBufferReplaceAll(Buffer* buffer, String target, String chunk, String expected) 
{
    bufferReplaceAll(buffer, target, chunk);    
    
    String result = makeStringFromBuffer(*buffer);
    
    if (stringsAreEqual(result, expected)) { return; }
    
    printf("bufferReplaceAll FAILS!\n"); exit(1);
}

void testBufferReplaceAll() // bufferReplaceAll basically uses the same code as bufferReplace
{
    printf("- testing bufferReplaceAll\n"); 
    
    Buffer source = createBufferFromLiteral(". . . .");
    Buffer* buffer = &source;

    String target1 = makeStringFromLiteral(".");
    String chunk1 = makeStringFromLiteral("Hello!"); 
    String expected1 = makeStringFromLiteral("Hello! Hello! Hello! Hello!");    
    _testBufferReplaceAll(buffer, target1, chunk1, expected1);

    releaseBuffer(*buffer);
}

