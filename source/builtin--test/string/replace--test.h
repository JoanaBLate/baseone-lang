// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testCreateStringReplaceStart()
{
    printf("- testing createStringReplaceStart\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life is ∆ rock");   
    String source2 = makeStringFromLiteral("∆ ");  
   
    String result1 = createStringReplaceStart(&source1, 0, &source2);
    String expected1 = makeStringFromLiteral("∆ Life is ∆ rock");
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringReplaceStart(&source1, 16, &source2);
    String expected2 = makeStringFromLiteral("∆ ");    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringReplaceStart(&source1, 5, &source2);
    String expected3 = makeStringFromLiteral("∆ is ∆ rock");    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringReplaceStart(&source1, 8, &empty);
    String expected4 = makeStringFromLiteral("∆ rock");
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringReplaceStart(&empty, 1, &empty);
    String expected5 = makeStringEmpty();    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringReplaceStart FAILS!\n");
        exit(1);
    }
    
    releaseString(&result1);
    releaseString(&result2);
    releaseString(&result3);
    releaseString(&result4);
    releaseString(&result5);
    releaseString(&expected5);
}

void testCreateStringReplaceEnd()
{
    printf("- testing createStringReplaceEnd\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life is ∆ rock");   
    String source2 = makeStringFromLiteral(" ∆");  
   
    String result1 = createStringReplaceEnd(&source1, 0, &source2);
    String expected1 = makeStringFromLiteral("Life is ∆ rock ∆");
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringReplaceEnd(&source1, 16, &source2);
    String expected2 = makeStringFromLiteral(" ∆");    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringReplaceEnd(&source1, 5, &source2);
    String expected3 = makeStringFromLiteral("Life is ∆ ∆");    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringReplaceEnd(&source1, 5, &empty);
    String expected4 = makeStringFromLiteral("Life is ∆");
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringReplaceEnd(&empty, 1, &empty);
    String expected5 = makeStringEmpty();    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringReplaceEnd FAILS!\n");
        exit(1);
    }
    
    releaseString(&result1);
    releaseString(&result2);
    releaseString(&result3);
    releaseString(&result4);
    releaseString(&result5);
    releaseString(&expected5);
}

void testCreateStringReplace()
{
    printf("- testing createStringReplace\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life is ∆ rock");   
    String source2 = makeStringFromLiteral("∆");  
    String source3 = makeStringFromLiteral("Xx--xX");  
   
    String result1 = createStringReplace(&source1, &source2, &source3);
    String expected1 = makeStringFromLiteral("Life is Xx--xX rock");
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringReplace(&source1, &source3, &source2);
    String expected2 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringReplace(&source1, &source2, &empty);
    String expected3 = makeStringFromLiteral("Life is  rock");    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringReplace(&source1, &empty, &source2);
    String expected4 = makeStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringReplace(&source1, &empty, &empty);
    String expected5 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    String result6 = createStringReplace(&empty, &empty, &source1);
    String expected6 = makeStringEmpty();    
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }
    
    if (fails) { 
        printf("createStringReplace FAILS!\n");
        exit(1);
    }
    
    releaseString(&result1);
    releaseString(&result2);
    releaseString(&result3);
    releaseString(&result4);
    releaseString(&result5);
    releaseString(&result6);
    releaseString(&expected6);
}

void testCreateStringReplaceLast()
{
    printf("- testing createStringReplaceLast\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life ∆ is ∆ rock");   
    String source2 = makeStringFromLiteral("∆");  
    String source3 = makeStringFromLiteral("Xx--xX");  
   
    String result1 = createStringReplaceLast(&source1, &source2, &source3);
    String expected1 = makeStringFromLiteral("Life ∆ is Xx--xX rock");
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringReplaceLast(&source1, &source3, &source2);
    String expected2 = makeStringFromLiteral("Life ∆ is ∆ rock");    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringReplaceLast(&source1, &source2, &empty);
    String expected3 = makeStringFromLiteral("Life ∆ is  rock");    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringReplaceLast(&source1, &empty, &source2);
    String expected4 = makeStringFromLiteral("Life ∆ is ∆ rock");
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringReplaceLast(&source1, &empty, &empty);
    String expected5 = makeStringFromLiteral("Life ∆ is ∆ rock");    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    String result6 = createStringReplaceLast(&empty, &empty, &source1);
    String expected6 = makeStringEmpty();    
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }
    
    if (fails) { 
        printf("createStringReplaceLast FAILS!\n");
        exit(1);
    }
    
    releaseString(&result1);
    releaseString(&result2);
    releaseString(&result3);
    releaseString(&result4);
    releaseString(&result5);
    releaseString(&result6);
    releaseString(&expected6);
}

void testCreateStringReplaceAll()
{
    printf("- testing createStringReplaceAll\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("∆∆∆ Life ∆is ∆ rock ∆∆∆");   
    String source2 = makeStringFromLiteral("∆");    
    String source3 = makeStringFromLiteral("∆∆");  
    String source4 = makeStringFromLiteral("Y.Y");
   
    String result1 = createStringReplaceAll(&source1, &source2, &source3);
    String expected1 = makeStringFromLiteral("∆∆∆∆∆∆ Life ∆∆is ∆∆ rock ∆∆∆∆∆∆");  
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringReplaceAll(&source1, &source2, &source4);
    String expected2 = makeStringFromLiteral("Y.YY.YY.Y Life Y.Yis Y.Y rock Y.YY.YY.Y");  
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringReplaceAll(&source1, &source3, &source2);
    String expected3 = makeStringFromLiteral("∆∆ Life ∆is ∆ rock ∆∆");    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }

    String result4 = createStringReplaceAll(&empty, &source1, &source2);
    String expected4 = makeStringEmpty();    
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringReplaceAll(&source1, &source2, &empty);
    String expected5 = makeStringFromLiteral(" Life is  rock ");    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringReplaceAll FAILS!\n");
        exit(1);
    }
    
    releaseString(&result1);
    releaseString(&result2);
    releaseString(&result3);
    releaseString(&result4);
    releaseString(&result5);
}

