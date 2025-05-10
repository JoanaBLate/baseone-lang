// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


bool testStringBufferTrimStart1()
{
    StringBuffer sb = createStringBufferFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   

    stringBufferTrimStart(&sb);
    
    String result = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆! \n ");
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimStart2()
{
    StringBuffer sb = createStringBufferFromLiteral(" \n   \n ");   

    stringBufferTrimStart(&sb);
    
    String result = makeStringFromStringBuffer(sb);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimStart3()
{
    StringBuffer sb = createStringBufferFromLiteral("");   

    stringBufferTrimStart(&sb);
    
    String result = makeStringFromStringBuffer(sb);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

void testStringBufferTrimStart()
{
    printf("- testing stringBufferTrimStart\n");
    
    char* msg = "stringBufferTrimStart FAILS!\n";
    
    if (! testStringBufferTrimStart1()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimStart2()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimStart3()) { printf("%s", msg); exit(1); }
}

///////////////////////////////////////////////////////////////////////////////

bool testStringBufferTrimEnd1()
{
    StringBuffer sb = createStringBufferFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   

    stringBufferTrimEnd(&sb);
    
    String result = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimEnd2()
{
    StringBuffer sb = createStringBufferFromLiteral(" \n   \n ");   

    stringBufferTrimEnd(&sb);
    
    String result = makeStringFromStringBuffer(sb);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimEnd3()
{
    StringBuffer sb = createStringBufferFromLiteral("");   

    stringBufferTrimEnd(&sb);
    
    String result = makeStringFromStringBuffer(sb);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

void testStringBufferTrimEnd()
{
    printf("- testing stringBufferTrimEnd\n");
    
    char* msg = "stringBufferTrimEnd FAILS!\n";
    
    if (! testStringBufferTrimEnd1()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimEnd2()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimEnd3()) { printf("%s", msg); exit(1); }
}

///////////////////////////////////////////////////////////////////////////////

bool testStringBufferTrim1()
{
    StringBuffer sb = createStringBufferFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   

    stringBufferTrim(&sb);
    
    String result = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrim2()
{
    StringBuffer sb = createStringBufferFromLiteral(" \n   \n ");   

    stringBufferTrim(&sb);
    
    String result = makeStringFromStringBuffer(sb);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrim3()
{
    StringBuffer sb = createStringBufferFromLiteral("");   

    stringBufferTrim(&sb);
    
    String result = makeStringFromStringBuffer(sb);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

void testStringBufferTrim()
{
    printf("- testing stringBufferTrim\n");
    
    char* msg = "stringBufferTrim FAILS!\n";
    
    if (! testStringBufferTrim1()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrim2()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrim3()) { printf("%s", msg); exit(1); }
}

