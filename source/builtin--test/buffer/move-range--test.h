// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void _testBufferMoveRange(Buffer buffer, long origin, long count, long destiny, String expected) 
{
    bufferMoveRange(&buffer, origin, count, destiny);   
        
    String result = makeStringFromBuffer(buffer);
           
    if (stringsAreEqual(result, expected)) { return; }
    
    printf("bufferMoveRange FAILS!\n"); exit(1);
}

void testBufferMoveRange() 
{
    printf("- testing bufferMoveRange\n"); 
    
    Buffer buffer = createBufferFromLiteral("12345Hello67890");
    String expected = makeStringFromLiteral("12345Hello67890"); 
    
    _testBufferMoveRange(buffer,  600,  5,   7, expected);
    _testBufferMoveRange(buffer, -600,  5,   7, expected); 
    _testBufferMoveRange(buffer,    6,  5, -700, expected);
    _testBufferMoveRange(buffer,    6,  5,  700, expected);
    _testBufferMoveRange(buffer,    6, -5,   7, expected);
    
    releaseBuffer(buffer);   
      
    buffer = createBufferFromLiteral("12345Hello67890");
    expected = makeStringFromLiteral("HelloHello67890");    
    _testBufferMoveRange(buffer, 6, 5, 1, expected);    
    releaseBuffer(buffer);

    buffer = createBufferFromLiteral("12345Hello67890");
    expected = makeStringFromLiteral("12345HHello7890");    
    _testBufferMoveRange(buffer, 6, 5, 7, expected);    
    releaseBuffer(buffer);
    
    buffer = createBufferFromLiteral("12345Hello67890");
    expected = makeStringFromLiteral("12345Hello67Hel");    
    _testBufferMoveRange(buffer, 6, 5, 13, expected);    
    releaseBuffer(buffer);
  
    buffer = createBufferFromLiteral("12345Hello67890");
    expected = makeStringFromLiteral("Hello6789067890");    
    _testBufferMoveRange(buffer, 6, 50, 1, expected);    
    releaseBuffer(buffer);

    buffer = createBufferFromLiteral("12345Hello67890");
    expected = makeStringFromLiteral("1234512345Hello");    
    _testBufferMoveRange(buffer, 1, 50, 6, expected);    
    releaseBuffer(buffer);
        
    buffer = createBufferFromLiteral("12345Hello67890");
    expected = makeStringFromLiteral("123451234o67890");    
    _testBufferMoveRange(buffer, 0, 5, 6, expected);    
    releaseBuffer(buffer);

    buffer = createBufferFromLiteral("12345Hello67890");
    expected = makeStringFromLiteral("1234512llo67890");    
    _testBufferMoveRange(buffer, -2, 5, 6, expected);    
    releaseBuffer(buffer);

    buffer = createBufferFromLiteral("12345Hello67890");
    expected = makeStringFromLiteral("lo345Hello67890");    
    _testBufferMoveRange(buffer, 6, 5, -2, expected);    
    releaseBuffer(buffer);

    buffer = createBufferFromLiteral("12345Hello67890");
    expected = makeStringFromLiteral("o2345Hello67890");    
    _testBufferMoveRange(buffer, 6, 5, -3, expected);    
    releaseBuffer(buffer);

    buffer = createBufferFromLiteral("12345Hello67890");
    expected = makeStringFromLiteral("12345Hello67890");    
    _testBufferMoveRange(buffer, 6, 5, -4, expected);    
    releaseBuffer(buffer);
        
    buffer = createBufferFromLiteral("12345Hello67890");
    expected = makeStringFromLiteral("123451234567890");    
    _testBufferMoveRange(buffer, -4, 10, 6, expected);    
    releaseBuffer(buffer);
    
    buffer = createBufferFromLiteral("---12345Hello67890+++");
    buffer.margin = 3;
    buffer.size -= 6;
    expected = makeStringFromLiteral("o2345Hello67890");    
    _testBufferMoveRange(buffer, 6, 5, -3, expected);     
    releaseBuffer(buffer);
    
    buffer = createBufferFromLiteral("---12345Hello67890+++");
    buffer.margin = 3;
    buffer.size -= 6;
    expected = makeStringFromLiteral("12345Hello67890");    
    _testBufferMoveRange(buffer, -4, 50, 1, expected);     
    releaseBuffer(buffer);

    buffer = createBufferFromLiteral("---12345Hello67890+++");
    buffer.margin = 3;
    buffer.size -= 6;
    expected = makeStringFromLiteral("Hello6789067890");    
    _testBufferMoveRange(buffer, -4, 50, -4, expected);     
    releaseBuffer(buffer);
    
    buffer = createBufferFromLiteral(".12345xx");
    buffer.size -= 2;
    expected = makeStringFromLiteral("123455");    
    _testBufferMoveRange(buffer, 2, buffer.size, 1, expected);     
    releaseBuffer(buffer);       
}

