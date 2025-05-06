// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


bool testStringBufferTrimStart1()
{
    StringBuffer bs = createStringBufferFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   

    stringBufferTrimStart(&bs);
    
    String result = makeStringFromStringBuffer(bs);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆! \n ");
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(bs);
    
    return ok;
}

bool testStringBufferTrimStart2()
{
    StringBuffer bs = createStringBufferFromLiteral(" \n   \n ");   

    stringBufferTrimStart(&bs);
    
    String result = makeStringFromStringBuffer(bs);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(bs);
    
    return ok;
}

bool testStringBufferTrimStart3()
{
    StringBuffer bs = createStringBufferFromLiteral("");   

    stringBufferTrimStart(&bs);
    
    String result = makeStringFromStringBuffer(bs);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(bs);
    
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
    StringBuffer bs = createStringBufferFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   

    stringBufferTrimEnd(&bs);
    
    String result = makeStringFromStringBuffer(bs);
    
    String expected = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(bs);
    
    return ok;
}

bool testStringBufferTrimEnd2()
{
    StringBuffer bs = createStringBufferFromLiteral(" \n   \n ");   

    stringBufferTrimEnd(&bs);
    
    String result = makeStringFromStringBuffer(bs);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(bs);
    
    return ok;
}

bool testStringBufferTrimEnd3()
{
    StringBuffer bs = createStringBufferFromLiteral("");   

    stringBufferTrimEnd(&bs);
    
    String result = makeStringFromStringBuffer(bs);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(bs);
    
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
    StringBuffer bs = createStringBufferFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   

    stringBufferTrim(&bs);
    
    String result = makeStringFromStringBuffer(bs);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(bs);
    
    return ok;
}

bool testStringBufferTrim2()
{
    StringBuffer bs = createStringBufferFromLiteral(" \n   \n ");   

    stringBufferTrim(&bs);
    
    String result = makeStringFromStringBuffer(bs);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(bs);
    
    return ok;
}

bool testStringBufferTrim3()
{
    StringBuffer bs = createStringBufferFromLiteral("");   

    stringBufferTrim(&bs);
    
    String result = makeStringFromStringBuffer(bs);
    
    String expected = makeStringEmpty();
    
    bool ok = stringsAreEqual(result, expected);
    
    releaseStringBuffer(bs);
    
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

