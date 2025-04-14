// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testStringTrimStart()
{
    printf("- testing stringTrimStart\n");
    
    bool fails = false;

    String* source1 = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   
    String* expected1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆! \n ");
    stringTrimStart(source1);
    if (! stringsAreEqual(source1, expected1)) { fails = true; }
    
    String* source2 = makeStringFromLiteral(" \n   \n ");   
    String* expected2 = makeStringEmpty();
    stringTrimStart(source2);
    if (! stringsAreEqual(source2, expected2)) { fails = true; }

    String* source3 = makeStringFromLiteral("");
    stringTrimStart(source3);    
    String* expected3 = makeStringEmpty();    
    if (! stringsAreEqual(source3, expected3)) { fails = true; }    

    if (fails) { 
        printf("stringTrimStart FAILS!\n");
        exit(1);
    }
}

void testStringTrimEnd()
{
    printf("- testing stringTrimEnd\n");
    
    bool fails = false;

    String* source1 = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   
    String* expected1 = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆!");
    stringTrimEnd(source1);
    if (! stringsAreEqual(source1, expected1)) { fails = true; }
    
    String* source2 = makeStringFromLiteral(" \n   \n ");   
    String* expected2 = makeStringEmpty();
    stringTrimEnd(source2);
    if (! stringsAreEqual(source2, expected2)) { fails = true; }

    String* source3 = makeStringFromLiteral("");
    stringTrimEnd(source3);    
    String* expected3 = makeStringEmpty();    
    if (! stringsAreEqual(source3, expected3)) { fails = true; } 
    
    if (fails) { 
        printf("stringTrimEnd FAILS!\n");
        exit(1);
    }
}

void testStringTrim()
{
    printf("- testing stringTrim\n");
    
    bool fails = false;    

    String* source1 = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   
    String* expected1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    stringTrim(source1);
    if (! stringsAreEqual(source1, expected1)) { fails = true; }
    
    String* source2 = makeStringFromLiteral(" \n   \n ");   
    String* expected2 = makeStringEmpty();
    stringTrim(source2);
    if (! stringsAreEqual(source2, expected2)) { fails = true; }

    String* source3 = makeStringFromLiteral("");
    stringTrim(source3);    
    String* expected3 = makeStringEmpty();    
    if (! stringsAreEqual(source3, expected3)) { fails = true; } 
    
    if (fails) { 
        printf("stringTrim FAILS!\n");
        exit(1);
    }
}

void testStringTrimStartTarget()
{
    printf("- testing stringTrimStartTarget\n");
    
    bool fails = false;

    String* source1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String* source2 = makeStringFromLiteral("∆!");   
    stringTrimStartTarget(source1, source2);
    String* expected1 = makeStringFromLiteral(" Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(source1, expected1)) { fails = true; }

    String* source3 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String* source4 = makeStringFromLiteral("xy");   
    stringTrimStartTarget(source3, source4);
    String* expected2 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(source3, expected2)) { fails = true; }
    
    String* source5 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String* source6 = makeStringFromLiteral("");   
    stringTrimStartTarget(source5, source6);
    String* expected3 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(source5, expected3)) { fails = true; }
    
    String* source7 = makeStringFromLiteral("");
    String* source8 = makeStringFromLiteral("xy");   
    stringTrimStartTarget(source7, source8);
    String* expected4 = makeStringFromLiteral("");
    if (! stringsAreEqual(source7, expected4)) { fails = true; }

    if (fails) { 
        printf("stringTrimStartTarget FAILS!\n");
        exit(1);
    }
}

void testStringTrimEndTarget()
{
    printf("- testing stringTrimEndTarget\n");
    
    bool fails = false;

    String* source1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String* source2 = makeStringFromLiteral("∆!");   
    stringTrimEndTarget(source1, source2);
    String* expected1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ");
    if (! stringsAreEqual(source1, expected1)) { fails = true; }

    String* source3 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String* source4 = makeStringFromLiteral("xy");   
    stringTrimEndTarget(source3, source4);
    String* expected2 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(source3, expected2)) { fails = true; }
    
    String* source5 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String* source6 = makeStringFromLiteral("");   
    stringTrimEndTarget(source5, source6);
    String* expected3 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(source5, expected3)) { fails = true; }
    
    String* source7 = makeStringFromLiteral("");
    String* source8 = makeStringFromLiteral("xy");   
    stringTrimEndTarget(source7, source8);
    String* expected4 = makeStringFromLiteral("");
    if (! stringsAreEqual(source7, expected4)) { fails = true; }

    if (fails) { 
        printf("stringTrimEndTarget FAILS!\n");
        exit(1);
    }
}

void testStringTrimTarget()
{
    printf("- testing stringTrimTarget\n");
    
    bool fails = false;

    String* source1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String* source2 = makeStringFromLiteral("∆!");   
    stringTrimTarget(source1, source2);
    String* expected1 = makeStringFromLiteral(" Life is ∆ rock ");
    if (! stringsAreEqual(source1, expected1)) { fails = true; }

    String* source3 = makeStringFromLiteral("");
    String* source4 = makeStringFromLiteral("");   
    stringTrimTarget(source3, source4);
    String* expected2 = makeStringFromLiteral("");
    if (! stringsAreEqual(source3, expected2)) { fails = true; }
    
    if (fails) { 
        printf("stringTrimTarget FAILS!\n");
        exit(1);
    }
}

