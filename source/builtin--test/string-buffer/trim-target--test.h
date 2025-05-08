// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


bool testStringBufferTrimStartTarget1()
{
    StringBuffer bs = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("∆!");    

    stringBufferTrimStartTarget(&bs, target);
    
    String virtual = makeStringFromStringBuffer(bs);
    
    String expected = makeStringFromLiteral(" Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(bs);
    
    return ok;
}

bool testStringBufferTrimStartTarget2()
{
    StringBuffer bs = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("xy");    

    stringBufferTrimStartTarget(&bs, target);
    
    String virtual = makeStringFromStringBuffer(bs);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(bs);
    
    return ok;
}

bool testStringBufferTrimStartTarget3()
{
    StringBuffer bs = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("");    

    stringBufferTrimStartTarget(&bs, target);
    
    String virtual = makeStringFromStringBuffer(bs);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(bs);
    
    return ok;
}

bool testStringBufferTrimStartTarget4()
{
    StringBuffer bs = createStringBufferFromLiteral(""); 

    String target = makeStringFromLiteral("");    

    stringBufferTrimStartTarget(&bs, target);
    
    String virtual = makeStringFromStringBuffer(bs);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(bs);
    
    return ok;
}

void testStringBufferTrimStartTarget()
{
    printf("- testing stringBufferTrimStartTarget\n");
    
    char* msg = "stringBufferTrimStartTarget FAILS!\n";
    
    if (! testStringBufferTrimStartTarget1()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimStartTarget2()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimStartTarget3()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimStartTarget4()) { printf("%s", msg); exit(1); }
}

///////////////////////////////////////////////////////////////////////////////

bool testStringBufferTrimEndTarget1()
{
    StringBuffer bs = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("∆!");    

    stringBufferTrimEndTarget(&bs, target);
    
    String virtual = makeStringFromStringBuffer(bs);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(bs);
    
    return ok;
}

bool testStringBufferTrimEndTarget2()
{
    StringBuffer bs = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("xy");    

    stringBufferTrimEndTarget(&bs, target);
    
    String virtual = makeStringFromStringBuffer(bs);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(bs);
    
    return ok;
}

bool testStringBufferTrimEndTarget3()
{
    StringBuffer bs = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("");    

    stringBufferTrimEndTarget(&bs, target);
    
    String virtual = makeStringFromStringBuffer(bs);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(bs);
    
    return ok;
}

bool testStringBufferTrimEndTarget4()
{
    StringBuffer bs = createStringBufferFromLiteral(""); 

    String target = makeStringFromLiteral("xy");    

    stringBufferTrimEndTarget(&bs, target);
    
    String virtual = makeStringFromStringBuffer(bs);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(bs);
    
    return ok;
}

void testStringBufferTrimEndTarget()
{
    printf("- testing stringBufferTrimEndTarget\n");
    
    char* msg = "stringBufferTrimEndTarget FAILS!\n";
    
    if (! testStringBufferTrimEndTarget1()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimEndTarget2()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimEndTarget3()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimEndTarget4()) { printf("%s", msg); exit(1); }
}

///////////////////////////////////////////////////////////////////////////////

bool testStringBufferTrimTarget1()
{
    StringBuffer bs = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("∆!");    

    stringBufferTrimTarget(&bs, target);
    
    String virtual = makeStringFromStringBuffer(bs);
    
    String expected = makeStringFromLiteral(" Life is ∆ rock ");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(bs);
    
    return ok;
}

bool testStringBufferTrimTarget2()
{
    StringBuffer bs = createStringBufferFromLiteral(""); 

    String target = makeStringFromLiteral("");    

    stringBufferTrimTarget(&bs, target);
    
    String virtual = makeStringFromStringBuffer(bs);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(bs);
    
    return ok;
}

bool testStringBufferTrimTarget3()
{
    StringBuffer bs = createStringBufferFromLiteral(""); 

    String target = makeStringFromLiteral("");    

    stringBufferTrimTarget(&bs, target);
    
    String virtual = makeStringFromStringBuffer(bs);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(bs);
    
    return ok;
}

void testStringBufferTrimTarget()
{
    printf("- testing stringBufferTrimTarget\n");
    
    char* msg = "stringBufferTrimTarget FAILS!\n";
    
    if (! testStringBufferTrimTarget1()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimTarget2()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimTarget3()) { printf("%s", msg); exit(1); }
}

