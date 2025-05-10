// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


bool testStringBufferTrimStartTarget1()
{
    StringBuffer sb = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("∆!");    

    stringBufferTrimStartTarget(&sb, target);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral(" Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimStartTarget2()
{
    StringBuffer sb = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("xy");    

    stringBufferTrimStartTarget(&sb, target);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimStartTarget3()
{
    StringBuffer sb = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("");    

    stringBufferTrimStartTarget(&sb, target);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimStartTarget4()
{
    StringBuffer sb = createStringBufferFromLiteral(""); 

    String target = makeStringFromLiteral("");    

    stringBufferTrimStartTarget(&sb, target);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
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
    StringBuffer sb = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("∆!");    

    stringBufferTrimEndTarget(&sb, target);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimEndTarget2()
{
    StringBuffer sb = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("xy");    

    stringBufferTrimEndTarget(&sb, target);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimEndTarget3()
{
    StringBuffer sb = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("");    

    stringBufferTrimEndTarget(&sb, target);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimEndTarget4()
{
    StringBuffer sb = createStringBufferFromLiteral(""); 

    String target = makeStringFromLiteral("xy");    

    stringBufferTrimEndTarget(&sb, target);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
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
    StringBuffer sb = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String target = makeStringFromLiteral("∆!");    

    stringBufferTrimTarget(&sb, target);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral(" Life is ∆ rock ");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimTarget2()
{
    StringBuffer sb = createStringBufferFromLiteral(""); 

    String target = makeStringFromLiteral("");    

    stringBufferTrimTarget(&sb, target);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimTarget3()
{
    StringBuffer sb = createStringBufferFromLiteral(""); 

    String target = makeStringFromLiteral("");    

    stringBufferTrimTarget(&sb, target);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
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

