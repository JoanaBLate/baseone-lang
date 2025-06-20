// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


bool testBufferTrimStartTarget1()
{
    Buffer buffer = createBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("∆!");    

    bufferTrimStartTarget(&buffer, target);
    
    String virtual = makeStringFromBuffer(buffer);
    
    String expected = makeStringFromLiteral(" Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseBuffer(buffer);
    
    return ok;
}

bool testBufferTrimStartTarget2()
{
    Buffer buffer = createBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("xy");    

    bufferTrimStartTarget(&buffer, target);
    
    String virtual = makeStringFromBuffer(buffer);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseBuffer(buffer);
    
    return ok;
}

bool testBufferTrimStartTarget3()
{
    Buffer buffer = createBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("");    

    bufferTrimStartTarget(&buffer, target);
    
    String virtual = makeStringFromBuffer(buffer);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseBuffer(buffer);
    
    return ok;
}

bool testBufferTrimStartTarget4()
{
    Buffer buffer = createBufferFromLiteral(""); 

    String target = makeStringFromLiteral("");    

    bufferTrimStartTarget(&buffer, target);
    
    String virtual = makeStringFromBuffer(buffer);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseBuffer(buffer);
    
    return ok;
}

void testBufferTrimStartTarget()
{
    printf("- testing bufferTrimStartTarget\n");
    
    char* msg = "bufferTrimStartTarget FAILS!\n";
    
    if (! testBufferTrimStartTarget1()) { printf("%s", msg); exit(1); }
    if (! testBufferTrimStartTarget2()) { printf("%s", msg); exit(1); }
    if (! testBufferTrimStartTarget3()) { printf("%s", msg); exit(1); }
    if (! testBufferTrimStartTarget4()) { printf("%s", msg); exit(1); }
}

///////////////////////////////////////////////////////////////////////////////

bool testBufferTrimEndTarget1()
{
    Buffer buffer = createBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("∆!");    

    bufferTrimEndTarget(&buffer, target);
    
    String virtual = makeStringFromBuffer(buffer);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseBuffer(buffer);
    
    return ok;
}

bool testBufferTrimEndTarget2()
{
    Buffer buffer = createBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("xy");    

    bufferTrimEndTarget(&buffer, target);
    
    String virtual = makeStringFromBuffer(buffer);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseBuffer(buffer);
    
    return ok;
}

bool testBufferTrimEndTarget3()
{
    Buffer buffer = createBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("");    

    bufferTrimEndTarget(&buffer, target);
    
    String virtual = makeStringFromBuffer(buffer);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseBuffer(buffer);
    
    return ok;
}

bool testBufferTrimEndTarget4()
{
    Buffer buffer = createBufferFromLiteral(""); 

    String target = makeStringFromLiteral("xy");    

    bufferTrimEndTarget(&buffer, target);
    
    String virtual = makeStringFromBuffer(buffer);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseBuffer(buffer);
    
    return ok;
}

void testBufferTrimEndTarget()
{
    printf("- testing bufferTrimEndTarget\n");
    
    char* msg = "bufferTrimEndTarget FAILS!\n";
    
    if (! testBufferTrimEndTarget1()) { printf("%s", msg); exit(1); }
    if (! testBufferTrimEndTarget2()) { printf("%s", msg); exit(1); }
    if (! testBufferTrimEndTarget3()) { printf("%s", msg); exit(1); }
    if (! testBufferTrimEndTarget4()) { printf("%s", msg); exit(1); }
}

///////////////////////////////////////////////////////////////////////////////

bool testBufferTrimTarget1()
{
    Buffer buffer = createBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("∆!");    

    bufferTrimTarget(&buffer, target);
    
    String virtual = makeStringFromBuffer(buffer);
    
    String expected = makeStringFromLiteral(" Life is ∆ rock ");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseBuffer(buffer);
    
    return ok;
}

bool testBufferTrimTarget2()
{
    Buffer buffer = createBufferFromLiteral(""); 

    String target = makeStringFromLiteral("");    

    bufferTrimTarget(&buffer, target);
    
    String virtual = makeStringFromBuffer(buffer);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseBuffer(buffer);
    
    return ok;
}

bool testBufferTrimTarget3()
{
    Buffer buffer = createBufferFromLiteral(""); 

    String target = makeStringFromLiteral("");    

    bufferTrimTarget(&buffer, target);
    
    String virtual = makeStringFromBuffer(buffer);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseBuffer(buffer);
    
    return ok;
}

void testBufferTrimTarget()
{
    printf("- testing bufferTrimTarget\n");
    
    char* msg = "bufferTrimTarget FAILS!\n";
    
    if (! testBufferTrimTarget1()) { printf("%s", msg); exit(1); }
    if (! testBufferTrimTarget2()) { printf("%s", msg); exit(1); }
    if (! testBufferTrimTarget3()) { printf("%s", msg); exit(1); }
}

