// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


bool testHeapBufferTrimStartTarget1()
{
    HeapBuffer hb = createHeapBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("∆!");    

    heapBufferTrimStartTarget(&hb, target);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral(" Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimStartTarget2()
{
    HeapBuffer hb = createHeapBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("xy");    

    heapBufferTrimStartTarget(&hb, target);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimStartTarget3()
{
    HeapBuffer hb = createHeapBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("");    

    heapBufferTrimStartTarget(&hb, target);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimStartTarget4()
{
    HeapBuffer hb = createHeapBufferFromLiteral(""); 

    String target = makeStringFromLiteral("");    

    heapBufferTrimStartTarget(&hb, target);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

void testHeapBufferTrimStartTarget()
{
    printf("- testing heapBufferTrimStartTarget\n");
    
    char* msg = "heapBufferTrimStartTarget FAILS!\n";
    
    if (! testHeapBufferTrimStartTarget1()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimStartTarget2()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimStartTarget3()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimStartTarget4()) { printf("%s", msg); exit(1); }
}

///////////////////////////////////////////////////////////////////////////////

bool testHeapBufferTrimEndTarget1()
{
    HeapBuffer hb = createHeapBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("∆!");    

    heapBufferTrimEndTarget(&hb, target);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimEndTarget2()
{
    HeapBuffer hb = createHeapBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("xy");    

    heapBufferTrimEndTarget(&hb, target);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimEndTarget3()
{
    HeapBuffer hb = createHeapBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("");    

    heapBufferTrimEndTarget(&hb, target);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimEndTarget4()
{
    HeapBuffer hb = createHeapBufferFromLiteral(""); 

    String target = makeStringFromLiteral("xy");    

    heapBufferTrimEndTarget(&hb, target);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

void testHeapBufferTrimEndTarget()
{
    printf("- testing heapBufferTrimEndTarget\n");
    
    char* msg = "heapBufferTrimEndTarget FAILS!\n";
    
    if (! testHeapBufferTrimEndTarget1()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimEndTarget2()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimEndTarget3()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimEndTarget4()) { printf("%s", msg); exit(1); }
}

///////////////////////////////////////////////////////////////////////////////

bool testHeapBufferTrimTarget1()
{
    HeapBuffer hb = createHeapBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("∆!");    

    heapBufferTrimTarget(&hb, target);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral(" Life is ∆ rock ");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimTarget2()
{
    HeapBuffer hb = createHeapBufferFromLiteral(""); 

    String target = makeStringFromLiteral("");    

    heapBufferTrimTarget(&hb, target);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimTarget3()
{
    HeapBuffer hb = createHeapBufferFromLiteral(""); 

    String target = makeStringFromLiteral("");    

    heapBufferTrimTarget(&hb, target);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

void testHeapBufferTrimTarget()
{
    printf("- testing heapBufferTrimTarget\n");
    
    char* msg = "heapBufferTrimTarget FAILS!\n";
    
    if (! testHeapBufferTrimTarget1()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimTarget2()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimTarget3()) { printf("%s", msg); exit(1); }
}

