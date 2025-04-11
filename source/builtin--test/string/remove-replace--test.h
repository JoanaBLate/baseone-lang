// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testCreateStringRemove()
{
    printf("- testing createStringRemove\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = createStringFromLiteral("Life is ∆ rock");   
    String source2 = createStringFromLiteral("∆ ");  
    String source3 = createStringFromLiteral("x");
   
    String result1 = createStringRemove(&source1, &source2);
    String expected1 = createStringFromLiteral("Life is rock");    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringRemove(&source1, &source3);
    String expected2 = createStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringRemove(&source1, &empty);
    String expected3 = createStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringRemove(&empty, &source1);
    String expected4 = createStringEmpty();    
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringRemove(&empty, &empty);
    String expected5 = createStringEmpty();    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringRemove FAILS!\n");
        exit(1);
    }
}

void testCreateStringRemoveAll()
{
    printf("- testing createStringRemoveAll\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = createStringFromLiteral("∆∆∆ Life ∆is ∆ rock ∆∆∆");   
    String source2 = createStringFromLiteral("∆");    
    String source3 = createStringFromLiteral("∆∆");
   
    String result1 = createStringRemoveAll(&source1, &source2);
    String expected1 = createStringFromLiteral(" Life is  rock ");   
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringRemoveAll(&source1, &source3);
    String expected2 = createStringFromLiteral("∆ Life ∆is ∆ rock ∆");    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringRemoveAll(&source1, &empty);
    String expected3 = createStringFromLiteral("∆∆∆ Life ∆is ∆ rock ∆∆∆");    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringRemoveAll(&empty, &source1);
    String expected4 = createStringEmpty();    
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    if (fails) { 
        printf("createStringRemoveAll FAILS!\n");
        exit(1);
    }
}

void testCreateStringReplaceStart()
{
    printf("- testing createStringReplaceStart\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = createStringFromLiteral("Life is ∆ rock");   
    String source2 = createStringFromLiteral("∆ ");  
   
    String result1 = createStringReplaceStart(&source1, 0, &source2);
    String expected1 = createStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringReplaceStart(&source1, 16, &source2);
    String expected2 = createStringFromLiteral("∆ ");    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringReplaceStart(&source1, 5, &source2);
    String expected3 = createStringFromLiteral("∆ is ∆ rock");    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringReplaceStart(&source1, 8, &empty);
    String expected4 = createStringFromLiteral("∆ rock");
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringReplaceStart(&empty, 1, &empty);
    String expected5 = createStringEmpty();    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringReplaceStart FAILS!\n");
        exit(1);
    }
}

void testCreateStringReplaceEnd()
{
    printf("- testing createStringReplaceEnd\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = createStringFromLiteral("Life is ∆ rock");   
    String source2 = createStringFromLiteral(" ∆");  
   
    String result1 = createStringReplaceEnd(&source1, 0, &source2);
    String expected1 = createStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringReplaceEnd(&source1, 16, &source2);
    String expected2 = createStringFromLiteral(" ∆");    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringReplaceEnd(&source1, 5, &source2);
    String expected3 = createStringFromLiteral("Life is ∆ ∆");    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringReplaceEnd(&source1, 5, &empty);
    String expected4 = createStringFromLiteral("Life is ∆");
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringReplaceEnd(&empty, 1, &empty);
    String expected5 = createStringEmpty();    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringReplaceEnd FAILS!\n");
        exit(1);
    }
}

void testCreateStringReplace()
{
    printf("- testing createStringReplace\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = createStringFromLiteral("Life is ∆ rock");   
    String source2 = createStringFromLiteral("∆");  
    String source3 = createStringFromLiteral("Xx--xX");  
   
    String result1 = createStringReplace(&source1, &source2, &source3);
    String expected1 = createStringFromLiteral("Life is Xx--xX rock");
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringReplace(&source1, &source3, &source2);
    String expected2 = createStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringReplace(&source1, &source2, &empty);
    String expected3 = createStringFromLiteral("Life is  rock");    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringReplace(&source1, &empty, &source2);
    String expected4 = createStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringReplace(&source1, &empty, &empty);
    String expected5 = createStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    String result6 = createStringReplace(&empty, &empty, &source1);
    String expected6 = createStringEmpty();    
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }
    
    if (fails) { 
        printf("createStringReplace FAILS!\n");
        exit(1);
    }
}

void testCreateStringReplaceAll()
{
    printf("- testing createStringReplaceAll\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = createStringFromLiteral("∆∆∆ Life ∆is ∆ rock ∆∆∆");   
    String source2 = createStringFromLiteral("∆");    
    String source3 = createStringFromLiteral("∆∆");  
    String source4 = createStringFromLiteral("Y.Y");
   
    String result1 = createStringReplaceAll(&source1, &source2, &source3);
    String expected1 = createStringFromLiteral("∆∆∆∆∆∆ Life ∆∆is ∆∆ rock ∆∆∆∆∆∆");  
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringReplaceAll(&source1, &source2, &source4);
    String expected2 = createStringFromLiteral("Y.YY.YY.Y Life Y.Yis Y.Y rock Y.YY.YY.Y");  
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringReplaceAll(&source1, &source3, &source2);
    String expected3 = createStringFromLiteral("∆∆ Life ∆is ∆ rock ∆∆");    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }

    String result4 = createStringReplaceAll(&empty, &source1, &source2);
    String expected4 = createStringEmpty();    
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringReplaceAll(&source1, &source2, &empty);
    String expected5 = createStringFromLiteral(" Life is  rock ");    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringReplaceAll FAILS!\n");
        exit(1);
    }
}

