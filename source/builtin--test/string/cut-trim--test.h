// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testCreateStringCutStart()
{
    printf("- testing createStringCutStart\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ rock");   
   
    String result1 = createStringCutStart(&source, 5);
    String expected1 = makeStringFromLiteral("is ∆ rock");
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringCutStart(&source, 500);
    String expected2 = empty;
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringCutStart(&source, 0);
    String expected3 = makeStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
   
    String result4 = createStringCutStart(&source, -5);
    String expected4 = makeStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
   
    String result5 = createStringCutStart(&empty, -5);
    String expected5 = makeStringEmpty();
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringCutStart FAILS!\n");
        exit(1);
    }
}

void testCreateStringCutEnd()
{
    printf("- testing createStringCutEnd\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ rock");   
   
    String result1 = createStringCutEnd(&source, 5);
    String expected1 = makeStringFromLiteral("Life is ∆");
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringCutEnd(&source, 500);
    String expected2 = empty;
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringCutEnd(&source, 0);
    String expected3 = makeStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
   
    String result4 = createStringCutEnd(&source, -5);
    String expected4 = makeStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
   
    String result5 = createStringCutEnd(&empty, -5);
    String expected5 = makeStringEmpty();
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringCutEnd FAILS!\n");
        exit(1);
    }
}

void testCreateStringCutMiddle()
{
    printf("- testing createStringCutMiddle\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ rock");   
   
    String result1 = createStringCutMiddle(&source, 9, 4);
    String expected1 = makeStringFromLiteral("Life is rock");
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringCutMiddle(&source, 8, 400);
    String expected2 = makeStringFromLiteral("Life is");
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringCutMiddle(&source, -3, 12);
    String expected3 = makeStringFromLiteral("∆ rock");
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringCutMiddle(&source, -300, 1000);
    String expected4 = empty;
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }

    String result5 = createStringCutMiddle(&empty, 0, 1);
    String expected5 = makeStringEmpty();
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringCutMiddle FAILS!\n");
        exit(1);
    }
}

void testCreateStringTrimStartIt()
{
    printf("- testing createStringTrimStartIt\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String source2 = makeStringFromLiteral("∆!");   
    String source3 = makeStringFromLiteral("xy");   
   
    String result1 = createStringTrimStartIt(&source1, &source2);
    String expected1 = makeStringFromLiteral(" Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringTrimStartIt(&source1, &source3);
    String expected2 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringTrimStartIt(&source1, &empty);
    String expected3 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringTrimStartIt(&empty, &source1);
    String expected4 = makeStringEmpty();
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    if (fails) { 
        printf("createStringTrimStartIt FAILS!\n");
        exit(1);
    }
}

void testCreateStringTrimEndIt()
{
    printf("- testing createStringTrimEndIt\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String source2 = makeStringFromLiteral("∆!");   
    String source3 = makeStringFromLiteral("xy");   
   
    String result1 = createStringTrimEndIt(&source1, &source2);
    String expected1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ");
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringTrimEndIt(&source1, &source3);
    String expected2 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringTrimEndIt(&source1, &empty);
    String expected3 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringTrimEndIt(&empty, &source1);
    String expected4 = makeStringEmpty();
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    if (fails) { 
        printf("createStringTrimEndIt FAILS!\n");
        exit(1);
    }
}

void testCreateStringTrimIt()
{
    printf("- testing createStringTrimIt\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String source2 = makeStringFromLiteral("∆!");   
    String source3 = makeStringFromLiteral("xy");   
   
    String result1 = createStringTrimIt(&source1, &source2);
    String expected1 = makeStringFromLiteral(" Life is ∆ rock ");
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringTrimIt(&source1, &source3);
    String expected2 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringTrimIt(&source1, &empty);
    String expected3 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringTrimIt(&empty, &source1);
    String expected4 = makeStringEmpty();
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    if (fails) { 
        printf("createStringTrimIt FAILS!\n");
        exit(1);
    }
}

void testCreateStringTrimStart()
{
    printf("- testing createStringTrimStart\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   
    String source2 = makeStringFromLiteral(" \n   \n ");
   
    String result1 = createStringTrimStart(&source1);    
    String expected1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆! \n ");
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }

    String result2 = createStringTrimStart(&source2);    
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; } 
     
    String result3 = createStringTrimStart(&empty);    
    String expected3 = makeStringEmpty();    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }    
    
    if (fails) { 
        printf("createStringTrimStart FAILS!\n");
        exit(1);
    }
}

void testCreateStringTrimEnd()
{
    printf("- testing createStringTrimEnd\n");
    
    bool fails = false;

    String empty = makeStringEmpty();   
    String source1 = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   
    String source2 = makeStringFromLiteral(" \n   \n ");
   
    String result1 = createStringTrimEnd(&source1);
    String expected1 = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }    

    String result2 = createStringTrimEnd(&source2);    
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; } 
     
    String result3 = createStringTrimEnd(&empty);    
    String expected3 = makeStringEmpty();    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    if (fails) { 
        printf("createStringTrimEnd FAILS!\n");
        exit(1);
    }
}

void testCreateStringTrim()
{
    printf("- testing createStringTrim\n");
    
    bool fails = false;
    String empty = makeStringEmpty();     
    String source1 = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   
    String source2 = makeStringFromLiteral(" \n   \n ");
   
    String result1 = createStringTrim(&source1);
    String expected1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }

    String result2 = createStringTrim(&source2);    
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; } 
     
    String result3 = createStringTrim(&empty);    
    String expected3 = makeStringEmpty();    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    if (fails) { 
        printf("createStringTrim FAILS!\n");
        exit(1);
    }
}

