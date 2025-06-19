// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


bool testHeapBufferTrimStartAny1()
{
    HeapBuffer hb = createHeapBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String sample = makeStringFromLiteral(" ∆!");    

    heapBufferTrimStartAny(&hb, sample);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimStartAny2()
{
    HeapBuffer hb = createHeapBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String sample = makeStringFromLiteral("xy");    

    heapBufferTrimStartAny(&hb, sample);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimStartAny3()
{
    HeapBuffer hb = createHeapBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String sample = makeStringFromLiteral("");    

    heapBufferTrimStartAny(&hb, sample);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimStartAny4()
{
    HeapBuffer hb = createHeapBufferFromLiteral(""); 

    String sample = makeStringFromLiteral("");    

    heapBufferTrimStartAny(&hb, sample);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

void testHeapBufferTrimStartAny()
{
    printf("- testing heapBufferTrimStartAny\n");
    
    char* msg = "heapBufferTrimStartAny FAILS!\n";
    
    if (! testHeapBufferTrimStartAny1()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimStartAny2()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimStartAny3()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimStartAny4()) { printf("%s", msg); exit(1); }
}

///////////////////////////////////////////////////////////////////////////////

bool testHeapBufferTrimEndAny1()
{
    HeapBuffer hb = createHeapBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String sample = makeStringFromLiteral(" ∆!");    

    heapBufferTrimEndAny(&hb, sample);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimEndAny2()
{
    HeapBuffer hb = createHeapBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String sample = makeStringFromLiteral("xy");    

    heapBufferTrimEndAny(&hb, sample);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimEndAny3()
{
    HeapBuffer hb = createHeapBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String sample = makeStringFromLiteral("");    

    heapBufferTrimEndAny(&hb, sample);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimEndAny4()
{
    HeapBuffer hb = createHeapBufferFromLiteral(""); 

    String sample = makeStringFromLiteral("xy");    

    heapBufferTrimEndAny(&hb, sample);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

void testHeapBufferTrimEndAny()
{
    printf("- testing heapBufferTrimEndAny\n");
    
    char* msg = "heapBufferTrimEndAny FAILS!\n";
    
    if (! testHeapBufferTrimEndAny1()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimEndAny2()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimEndAny3()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimEndAny4()) { printf("%s", msg); exit(1); }
}

///////////////////////////////////////////////////////////////////////////////

void testHeapBufferTrimAny()
{
    printf("- testing heapBufferTrimAny\n");
    
    char* msg = "heapBufferTrimAny FAILS!\n";

    HeapBuffer hb = createHeapBufferFromLiteral("123∆!∆! Life is ∆ rock ∆!∆!123"); 
    
    hb.margin = 3;
    hb.size -= 6;

    String sample = makeStringFromLiteral(" ∆!");    

    heapBufferTrimAny(&hb, sample);
    
    String virtual = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("Life is ∆ rock");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseHeapBuffer(hb);
    
    if (! ok) { printf("%s", msg); exit(1); }
}

