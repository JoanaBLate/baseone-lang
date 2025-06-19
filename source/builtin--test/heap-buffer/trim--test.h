// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


bool testHeapBufferTrimStart1()
{
    HeapBuffer hb = createHeapBufferFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   

    heapBufferTrimStart(&hb);
    
    String result = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆! \n ");
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimStart2()
{
    HeapBuffer hb = createHeapBufferFromLiteral(" \n   \n ");   

    heapBufferTrimStart(&hb);
    
    String result = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimStart3()
{
    HeapBuffer hb = createHeapBufferFromLiteral("");   

    heapBufferTrimStart(&hb);
    
    String result = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

void testHeapBufferTrimStart()
{
    printf("- testing heapBufferTrimStart\n");
    
    char* msg = "heapBufferTrimStart FAILS!\n";
    
    if (! testHeapBufferTrimStart1()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimStart2()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimStart3()) { printf("%s", msg); exit(1); }
}

///////////////////////////////////////////////////////////////////////////////

bool testHeapBufferTrimEnd1()
{
    HeapBuffer hb = createHeapBufferFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   

    heapBufferTrimEnd(&hb);
    
    String result = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimEnd2()
{
    HeapBuffer hb = createHeapBufferFromLiteral(" \n   \n ");   

    heapBufferTrimEnd(&hb);
    
    String result = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrimEnd3()
{
    HeapBuffer hb = createHeapBufferFromLiteral("");   

    heapBufferTrimEnd(&hb);
    
    String result = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

void testHeapBufferTrimEnd()
{
    printf("- testing heapBufferTrimEnd\n");
    
    char* msg = "heapBufferTrimEnd FAILS!\n";
    
    if (! testHeapBufferTrimEnd1()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimEnd2()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrimEnd3()) { printf("%s", msg); exit(1); }
}

///////////////////////////////////////////////////////////////////////////////

bool testHeapBufferTrim1()
{
    HeapBuffer hb = createHeapBufferFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   

    heapBufferTrim(&hb);
    
    String result = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrim2()
{
    HeapBuffer hb = createHeapBufferFromLiteral(" \n   \n ");   

    heapBufferTrim(&hb);
    
    String result = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

bool testHeapBufferTrim3()
{
    HeapBuffer hb = createHeapBufferFromLiteral("");   

    heapBufferTrim(&hb);
    
    String result = makeStringFromHeapBuffer(hb);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseHeapBuffer(hb);
    
    return ok;
}

void testHeapBufferTrim()
{
    printf("- testing heapBufferTrim\n");
    
    char* msg = "heapBufferTrim FAILS!\n";
    
    if (! testHeapBufferTrim1()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrim2()) { printf("%s", msg); exit(1); }
    if (! testHeapBufferTrim3()) { printf("%s", msg); exit(1); }
}

