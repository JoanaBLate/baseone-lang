// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testStringTrimStart()
{
    printf("- testing stringTrimStart\n");
    
    bool fails = false;

    String source1 = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   
    String expected1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆! \n ");
    stringTrimStart(&source1);
    if (! stringsAreEqual(source1, expected1)) { fails = true; }
    
    String source2 = makeStringFromLiteral(" \n   \n ");   
    String expected2 = makeStringEmpty();
    stringTrimStart(&source2);
    if (! stringsAreEqual(source2, expected2)) { fails = true; }

    String source3 = makeStringFromLiteral("");
    stringTrimStart(&source3);    
    String expected3 = makeStringEmpty();    
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

    String source1 = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   
    String expected1 = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆!");
    stringTrimEnd(&source1);
    if (! stringsAreEqual(source1, expected1)) { fails = true; }
    
    String source2 = makeStringFromLiteral(" \n   \n ");   
    String expected2 = makeStringEmpty();
    stringTrimEnd(&source2);
    if (! stringsAreEqual(source2, expected2)) { fails = true; }

    String source3 = makeStringFromLiteral("");
    stringTrimEnd(&source3);    
    String expected3 = makeStringEmpty();    
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

    String source1 = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   
    String expected1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    stringTrim(&source1);
    if (! stringsAreEqual(source1, expected1)) { fails = true; }
    
    String source2 = makeStringFromLiteral(" \n   \n ");   
    String expected2 = makeStringEmpty();
    stringTrim(&source2);
    if (! stringsAreEqual(source2, expected2)) { fails = true; }

    String source3 = makeStringFromLiteral("");
    stringTrim(&source3);    
    String expected3 = makeStringEmpty();    
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

    String source1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String target1 = makeStringFromLiteral("∆!");   
    stringTrimStartTarget(&source1, target1);
    String expected1 = makeStringFromLiteral(" Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(source1, expected1)) { fails = true; }

    String source2 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String target2 = makeStringFromLiteral("xy");   
    stringTrimStartTarget(&source2, target2);
    String expected2 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(source2, expected2)) { fails = true; }
    
    String source3 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String target3 = makeStringFromLiteral("");   
    stringTrimStartTarget(&source3, target3);
    String expected3 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(source3, expected3)) { fails = true; }
    
    String source4 = makeStringFromLiteral("");
    String target4 = makeStringFromLiteral("xy");   
    stringTrimStartTarget(&source4, target4);
    String expected4 = makeStringFromLiteral("");
    if (! stringsAreEqual(source4, expected4)) { fails = true; }

    if (fails) { 
        printf("stringTrimStartTarget FAILS!\n");
        exit(1);
    }
}

void testStringTrimEndTarget()
{
    printf("- testing stringTrimEndTarget\n");
    
    bool fails = false;

    String source1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String target1 = makeStringFromLiteral("∆!");   
    stringTrimEndTarget(&source1, target1);
    String expected1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ");
    if (! stringsAreEqual(source1, expected1)) { fails = true; }

    String source2 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String target2 = makeStringFromLiteral("xy");   
    stringTrimEndTarget(&source2, target2);
    String expected2 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(source2, expected2)) { fails = true; }
    
    String source3 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String target3 = makeStringFromLiteral("");   
    stringTrimEndTarget(&source3, target3);
    String expected3 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(source3, expected3)) { fails = true; }
    
    String source4 = makeStringFromLiteral("");
    String target4 = makeStringFromLiteral("xy");   
    stringTrimEndTarget(&source4, target4);
    String expected4 = makeStringFromLiteral("");
    if (! stringsAreEqual(source4, expected4)) { fails = true; }

    if (fails) { 
        printf("stringTrimEndTarget FAILS!\n");
        exit(1);
    }
}

void testStringTrimTarget()
{
    printf("- testing stringTrimTarget\n");
    
    bool fails = false;

    String source1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String target1 = makeStringFromLiteral("∆!");   
    stringTrimTarget(&source1, target1);
    String expected1 = makeStringFromLiteral(" Life is ∆ rock ");
    if (! stringsAreEqual(source1, expected1)) { fails = true; }

    String source2 = makeStringFromLiteral("");
    String target2 = makeStringFromLiteral("");   
    stringTrimTarget(&source2, target2);
    String expected2 = makeStringFromLiteral("");
    if (! stringsAreEqual(source2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("stringTrimTarget FAILS!\n");
        exit(1);
    }
}

