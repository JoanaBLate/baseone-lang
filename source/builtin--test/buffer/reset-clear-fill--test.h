// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testBufferReset()
{
    printf("- testing bufferReset\n");
    
    Buffer buffer = createBufferFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   
    
    buffer.margin = 3;
    
    buffer.size -= 6;
    
    bufferReset(&buffer);
    
    if (buffer.margin != 0  ||  buffer.size != 40) { printf("bufferReset FAILS!\n"); exit(1); }        
    
    releaseBuffer(&buffer);
}

void testBufferClear()
{
    printf("- testing bufferClear\n");
    
    Buffer buffer = createBufferFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   
    
    buffer.margin = 3;
    
    buffer.size -= 6;
    
    bufferClear(&buffer);
    
    Buffer expected = createBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");   
    
    for (long index = 0; index < expected.size; index++) { expected.address[index] = 0; }
    
    if (! buffersAreEqual(&buffer, &expected)) { printf("bufferClear FAILS!\n"); exit(1); }
    
    releaseBuffer(&buffer);
    releaseBuffer(&expected);
}

void testBufferFill()
{
    printf("- testing bufferFill\n");
    
    Buffer buffer = createBufferFromLiteral(" \n  Life is ∆ rock ∆!  \n ");   
    
    buffer.margin = 3;
    
    buffer.size -= 6;
    
    String chunk = makeStringFromLiteral("123456");
    
    bufferFill(&buffer, &chunk);
    
    Buffer expected = createBufferFromLiteral("12345612345612345612345"); 
    
    if (! buffersAreEqual(&buffer, &expected)) { printf("bufferFill FAILS!\n"); exit(1); }
    
    releaseBuffer(&buffer);
    releaseBuffer(&expected);
}

