// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


bool testStringBufferTrimStartAny1()
{
    StringBuffer sb = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String sample = makeStringFromLiteral(" ∆!");    

    stringBufferTrimStartAny(&sb, sample);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimStartAny2()
{
    StringBuffer sb = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String sample = makeStringFromLiteral("xy");    

    stringBufferTrimStartAny(&sb, sample);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimStartAny3()
{
    StringBuffer sb = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String sample = makeStringFromLiteral("");    

    stringBufferTrimStartAny(&sb, sample);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimStartAny4()
{
    StringBuffer sb = createStringBufferFromLiteral(""); 

    String sample = makeStringFromLiteral("");    

    stringBufferTrimStartAny(&sb, sample);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

void testStringBufferTrimStartAny()
{
    printf("- testing stringBufferTrimStartAny\n");
    
    char* msg = "stringBufferTrimStartAny FAILS!\n";
    
    if (! testStringBufferTrimStartAny1()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimStartAny2()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimStartAny3()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimStartAny4()) { printf("%s", msg); exit(1); }
}

///////////////////////////////////////////////////////////////////////////////

bool testStringBufferTrimEndAny1()
{
    StringBuffer sb = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String sample = makeStringFromLiteral(" ∆!");    

    stringBufferTrimEndAny(&sb, sample);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimEndAny2()
{
    StringBuffer sb = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String sample = makeStringFromLiteral("xy");    

    stringBufferTrimEndAny(&sb, sample);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimEndAny3()
{
    StringBuffer sb = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!"); 

    String sample = makeStringFromLiteral("");    

    stringBufferTrimEndAny(&sb, sample);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

bool testStringBufferTrimEndAny4()
{
    StringBuffer sb = createStringBufferFromLiteral(""); 

    String sample = makeStringFromLiteral("xy");    

    stringBufferTrimEndAny(&sb, sample);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
    return ok;
}

void testStringBufferTrimEndAny()
{
    printf("- testing stringBufferTrimEndAny\n");
    
    char* msg = "stringBufferTrimEndAny FAILS!\n";
    
    if (! testStringBufferTrimEndAny1()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimEndAny2()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimEndAny3()) { printf("%s", msg); exit(1); }
    if (! testStringBufferTrimEndAny4()) { printf("%s", msg); exit(1); }
}

///////////////////////////////////////////////////////////////////////////////

void testStringBufferTrimAny()
{
    printf("- testing stringBufferTrimAny\n");
    
    char* msg = "stringBufferTrimAny FAILS!\n";

    StringBuffer sb = createStringBufferFromLiteral("123∆!∆! Life is ∆ rock ∆!∆!123"); 
    
    sb.margin = 3;
    sb.size -= 6;

    String sample = makeStringFromLiteral(" ∆!");    

    stringBufferTrimAny(&sb, sample);
    
    String virtual = makeStringFromStringBuffer(sb);
    
    String expected = makeStringFromLiteral("Life is ∆ rock");
    
    bool ok = stringsAreEqual(virtual, expected);
    
    releaseStringBuffer(sb);
    
    if (! ok) { printf("%s", msg); exit(1); }
}

