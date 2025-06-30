// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void _testBufferReplaceStart(Buffer* buffer, long count, String* chunk, String* expected) 
{
    bufferReplaceStart(buffer, count, chunk);    
    
    String result = makeStringFromBuffer(buffer);
       
    if (stringsAreEqual(&result, expected)) { return; }
    
    printf("bufferReplaceStart FAILS!\n"); exit(1);
}

void testBufferReplaceStart() 
{
    printf("- testing bufferReplaceStart\n"); 
    
    Buffer buffer = createBufferFromLiteral(".....Hello!");
    buffer.margin = 5;
    buffer.size = 6;
    
    String chunk = makeStringFromLiteral("123"); 
    String expected = makeStringFromLiteral("123Hello!");    
    _testBufferReplaceStart(&buffer, -15, &chunk, &expected);    

    chunk = makeStringFromLiteral("AB"); 
    expected = makeStringFromLiteral("ABHello!");    
    _testBufferReplaceStart(&buffer, 3, &chunk, &expected);     
 
    chunk = makeStringFromLiteral("abcdefghij"); 
    expected = makeStringFromLiteral("abcdefghijHello!");    
    _testBufferReplaceStart(&buffer, 2, &chunk, &expected); 

    buffer.margin += 2; // cutting 'ab', leaving margin
    buffer.size -= 2;
     
    buffer.size -= 2;   // cutting 'o!', leaving hidden end

    chunk = makeStringFromLiteral(""); 
    expected = makeStringFromLiteral("Hell");    
    _testBufferReplaceStart(&buffer, 8, &chunk, &expected);  
    
    releaseBuffer(&buffer);
}

///////////////////////////////////////////////////////////////////////////////

void _testBufferReplaceEnd(Buffer* buffer, long count, String *chunk, String *expected) 
{
    bufferReplaceEnd(buffer, count, chunk); 
    
    String result = makeStringFromBuffer(buffer);    
    
    if (stringsAreEqual(&result, expected)) { return; }
    
    printf("bufferReplaceEnd FAILS!\n"); exit(1);
}

void testBufferReplaceEnd() 
{
    printf("- testing bufferReplaceEnd\n"); 
    
    Buffer buffer = createBufferFromLiteral("XYZHello!.....");
    buffer.margin = 3;
    buffer.size = 6;

    String chunk = makeStringFromLiteral("123"); 
    String expected = makeStringFromLiteral("Hello!123");    
    _testBufferReplaceEnd(&buffer, -15, &chunk, &expected); 
    
    chunk = makeStringFromLiteral("AB"); 
    expected = makeStringFromLiteral("Hello!AB");    
    _testBufferReplaceEnd(&buffer, 3, &chunk, &expected);    
    releaseBuffer(&buffer);
    
    buffer = createBufferFromLiteral("Hello!");
    chunk = makeStringFromLiteral("abc"); 
    expected = makeStringFromLiteral("Helloabc");    
    _testBufferReplaceEnd(&buffer, 1, &chunk, &expected);
    releaseBuffer(&buffer);
    
    buffer = createBufferFromLiteral(".12345!");
    buffer.margin = 1;
    buffer.size -= 1;
    chunk = makeStringFromLiteral("abc"); 
    expected = makeStringFromLiteral("12345abc");    
    _testBufferReplaceEnd(&buffer, 1, &chunk, &expected);
    releaseBuffer(&buffer);
    
    buffer = createBufferFromLiteral("...HelloXX...");
    buffer.margin = 3;
    buffer.size = 7;
    chunk = makeStringFromLiteral("abcdefghijklmn"); 
    expected = makeStringFromLiteral("Helloabcdefghijklmn");
    _testBufferReplaceEnd(&buffer, 2, &chunk, &expected);  
    releaseBuffer(&buffer);
}

///////////////////////////////////////////////////////////////////////////////

void _testBufferReplace(Buffer* buffer, String* target, String* chunk, String* expected) 
{
    bufferReplace(buffer, target, chunk);    
    
    String result = makeStringFromBuffer(buffer);
    
    if (stringsAreEqual(&result, expected)) { return; }
    
    printf("bufferReplace FAILS!\n"); exit(1);
}

void testBufferReplace() 
{
    printf("- testing bufferReplace\n"); 
    
    Buffer buffer = createBufferFromLiteral("Hello!");
    String target = makeStringFromLiteral("ll");
    String chunk = makeStringFromLiteral("@#"); 
    String expected = makeStringFromLiteral("He@#o!");    
    _testBufferReplace(&buffer, &target, &chunk, &expected);

    target = makeStringFromLiteral("@#");
    chunk = makeStringFromLiteral(""); 
    expected = makeStringFromLiteral("Heo!");      
    _testBufferReplace(&buffer, &target, &chunk, &expected);

    target = makeStringFromLiteral("e");
    chunk = makeStringFromLiteral("ell---$$$---"); 
    expected = makeStringFromLiteral("Hell---$$$---o!");    
    _testBufferReplace(&buffer, &target, &chunk, &expected);
    
    buffer.margin = 4;
    buffer.size -= 4;
    
    target = makeStringFromLiteral("---$$$---o!");
    chunk = makeStringFromLiteral(">[^]<"); 
    expected = makeStringFromLiteral(">[^]<");   
    _testBufferReplace(&buffer, &target, &chunk, &expected);
        
    target = makeStringFromLiteral("^");
    chunk = makeStringFromLiteral("Life is ∆ rock! Life is ∆ rock!"); 
    expected = makeStringFromLiteral(">[Life is ∆ rock! Life is ∆ rock!]<");   
    _testBufferReplace(&buffer, &target, &chunk, &expected);
    releaseBuffer(&buffer);
}

///////////////////////////////////////////////////////////////////////////////

void _testBufferReplaceLast(Buffer* buffer, String *target, String *chunk, String *expected) 
{
    bufferReplaceLast(buffer, target, chunk);    
    
    String result = makeStringFromBuffer(buffer);
    
    if (stringsAreEqual(&result, expected)) { return; }
    
    printf("bufferReplaceLast FAILS!\n"); exit(1);
}

void testBufferReplaceLast() // bufferReplaceLast basically uses the same code as bufferReplace
{
    printf("- testing bufferReplaceLast\n"); 
    
    Buffer buffer = createBufferFromLiteral("Hello!");
    String target = makeStringFromLiteral("l");
    String chunk = makeStringFromLiteral("∆"); 
    String expected = makeStringFromLiteral("Hel∆o!");    
    _testBufferReplaceLast(&buffer, &target, &chunk, &expected);

    releaseBuffer(&buffer);
}

///////////////////////////////////////////////////////////////////////////////

void _testBufferReplaceAll(Buffer* buffer, String* target, String* chunk, String* expected) 
{
    bufferReplaceAll(buffer, target, chunk);    
    
    String result = makeStringFromBuffer(buffer);
    
    if (stringsAreEqual(&result, expected)) { return; }
    
    printf("bufferReplaceAll FAILS!\n"); exit(1);
}

void testBufferReplaceAll() // bufferReplaceAll basically uses the same code as bufferReplace
{
    printf("- testing bufferReplaceAll\n"); 
    
    Buffer buffer = createBufferFromLiteral(". . . .");
    String target = makeStringFromLiteral(".");
    String chunk = makeStringFromLiteral("Hello!"); 
    String expected = makeStringFromLiteral("Hello! Hello! Hello! Hello!");    
    _testBufferReplaceAll(&buffer, &target, &chunk, &expected);

    releaseBuffer(&buffer);
}

