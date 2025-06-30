// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testCreateStringPadStart()
{
    printf("- testing createStringPadStart\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life is ∆ rock");   
    String source2 = makeStringFromLiteral("(^-^) ");
   
    String result1 = createStringPadStart(&source1, &source2, 3);
    String expected1 = makeStringFromLiteral("(^-^) (^-^) (^-^) Life is ∆ rock");    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringPadStart(&source1, &empty, 3);
    String expected2 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringPadStart(&empty, &source2, 3);
    String expected3 = makeStringFromLiteral("(^-^) (^-^) (^-^) ");   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringPadStart(&source1, &source2, -1);
    String expected4 = makeStringFromLiteral("Life is ∆ rock");   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringPadStart(&empty, &empty, 3);
    String expected5 = makeStringEmpty();    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringPadStart FAILS!\n");
        exit(1);
    }
    
    releaseString(&result1);
    releaseString(&result2);
    releaseString(&result3);
    releaseString(&result4);
}   

void testCreateStringPadEnd()
{
    printf("- testing createStringPadEnd\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life is ∆ rock");   
    String source2 = makeStringFromLiteral(" (^-^)");
   
    String result1 = createStringPadEnd(&source1, &source2, 3);
    String expected1 = makeStringFromLiteral("Life is ∆ rock (^-^) (^-^) (^-^)");    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringPadEnd(&source1, &empty, 3);
    String expected2 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringPadEnd(&empty, &source2, 3);
    String expected3 = makeStringFromLiteral(" (^-^) (^-^) (^-^)");   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }  
    
    String result4 = createStringPadEnd(&source1, &source2, -1);
    String expected4 = makeStringFromLiteral("Life is ∆ rock");   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringPadEnd(&empty, &empty, 3);
    String expected5 = makeStringEmpty();    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringPadEnd FAILS!\n");
        exit(1);
    }
    
    releaseString(&result1);
    releaseString(&result2);
    releaseString(&result3);
    releaseString(&result4);
    releaseString(&result5);
    releaseString(&expected5);
}   

