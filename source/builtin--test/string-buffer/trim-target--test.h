// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


/* UNDER CONSTRUCTION

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

///////////////////////////////////////////////////////////////////////////////





void testStringBufferTrimStartTarget()
{
    printf("- testing stringBufferTrimStartTarget\n");
    
    bool fails = false;

    String source1 = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String target1 = makeStringFromLiteral("∆!");   
    stringBufferTrimStartTarget(&source1, target1);
    String expected1 = makeStringFromLiteral(" Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(source1, expected1)) { fails = true; }

    String source2 = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String target2 = makeStringFromLiteral("xy");   
    stringBufferTrimStartTarget(&source2, target2);
    String expected2 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(source2, expected2)) { fails = true; }
    
    String source3 = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String target3 = makeStringFromLiteral("");   
    stringBufferTrimStartTarget(&source3, target3);
    String expected3 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(source3, expected3)) { fails = true; }
    
    String source4 = createStringBufferFromLiteral("");
    String target4 = makeStringFromLiteral("xy");   
    stringBufferTrimStartTarget(&source4, target4);
    String expected4 = makeStringFromLiteral("");
    if (! stringsAreEqual(source4, expected4)) { fails = true; }

    if (fails) { 
        printf("stringBufferTrimStartTarget FAILS!\n");
        exit(1);
    }
}

void testStringBufferTrimEndTarget()
{
    printf("- testing stringBufferTrimEndTarget\n");
    
    bool fails = false;

    String source1 = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String target1 = makeStringFromLiteral("∆!");   
    stringBufferTrimEndTarget(&source1, target1);
    String expected1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ");
    if (! stringsAreEqual(source1, expected1)) { fails = true; }

    String source2 = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String target2 = makeStringFromLiteral("xy");   
    stringBufferTrimEndTarget(&source2, target2);
    String expected2 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(source2, expected2)) { fails = true; }
    
    String source3 = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String target3 = makeStringFromLiteral("");   
    stringBufferTrimEndTarget(&source3, target3);
    String expected3 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(source3, expected3)) { fails = true; }
    
    String source4 = createStringBufferFromLiteral("");
    String target4 = makeStringFromLiteral("xy");   
    stringBufferTrimEndTarget(&source4, target4);
    String expected4 = makeStringFromLiteral("");
    if (! stringsAreEqual(source4, expected4)) { fails = true; }

    if (fails) { 
        printf("stringBufferTrimEndTarget FAILS!\n");
        exit(1);
    }
}

void testStringBufferTrimTarget()
{
    printf("- testing stringBufferTrimTarget\n");
    
    bool fails = false;

    String source1 = createStringBufferFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String target1 = makeStringFromLiteral("∆!");   
    stringBufferTrimTarget(&source1, target1);
    String expected1 = makeStringFromLiteral(" Life is ∆ rock ");
    if (! stringsAreEqual(source1, expected1)) { fails = true; }

    String source2 = createStringBufferFromLiteral("");
    String target2 = makeStringFromLiteral("");   
    stringBufferTrimTarget(&source2, target2);
    String expected2 = makeStringFromLiteral("");
    if (! stringsAreEqual(source2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("stringBufferTrimTarget FAILS!\n");
        exit(1);
    }
}
*/
