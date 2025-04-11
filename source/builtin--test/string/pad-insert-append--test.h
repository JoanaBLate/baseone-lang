// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testCreateStringAppend()
{
    printf("- testing createStringAppend\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = createStringFromLiteral("Life is ∆");   
    String source2 = createStringFromLiteral(" rock");
   
    String result1 = createStringAppend(&source1, &source2);
    String expected1 = createStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }

    String result2 = createStringAppend(&source1, &empty);
    String expected2 = source1;    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }

    String result3 = createStringAppend(&empty, &source1);
    String expected3 = source1;   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringAppend(&empty, &empty);
    String expected4 = createStringEmpty();   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    if (fails) { 
        printf("createStringAppend FAILS!\n");
        exit(1);
    }
}

void testCreateStringInsert()
{
    printf("- testing createStringInsert\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = createStringFromLiteral("Life is ∆");   
    String source2 = createStringFromLiteral(" rock");
   
    String result1 = createStringInsert(&source1, &source2, 1000);
    String expected1 = createStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringInsert(&source1, &source2, 1);
    String expected2 = createStringFromLiteral(" rockLife is ∆");    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
   
    String result3 = createStringInsert(&source1, &source2, -1000);
    String expected3 = createStringFromLiteral(" rockLife is ∆");    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringInsert(&source1, &source2, 8);    
    String expected4 = createStringFromLiteral("Life is rock ∆");    
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringInsert(&source1, &empty, 1);    
    String expected5 = source1;       
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    String result6 = createStringInsert(&source1, &empty, 1);    
    String expected6 = source1;       
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }
    
    String result7 = createStringInsert(&empty, &empty, 1);    
    String expected7 = createStringEmpty();       
    if (! stringsAreEqual(&result7, &expected7)) { fails = true; }
    
    if (fails) { 
        printf("createStringInsert FAILS!\n");
        exit(1);
    }
}

void testCreateStringPadStart()
{
    printf("- testing createStringPadStart\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = createStringFromLiteral("Life is ∆ rock");   
    String source2 = createStringFromLiteral("(^-^) ");
   
    String result1 = createStringPadStart(&source1, &source2, 3);
    String expected1 = createStringFromLiteral("(^-^) (^-^) (^-^) Life is ∆ rock");    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringPadStart(&source1, &empty, 3);
    String expected2 = createStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringPadStart(&empty, &source2, 3);
    String expected3 = createStringFromLiteral("(^-^) (^-^) (^-^) ");   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringPadStart(&source1, &source2, -1);
    String expected4 = createStringFromLiteral("Life is ∆ rock");   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringPadStart(&empty, &empty, 3);
    String expected5 = createStringEmpty();    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringPadStart FAILS!\n");
        exit(1);
    }
}   

void testCreateStringPadEnd()
{
    printf("- testing createStringPadEnd\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = createStringFromLiteral("Life is ∆ rock");   
    String source2 = createStringFromLiteral(" (^-^)");
   
    String result1 = createStringPadEnd(&source1, &source2, 3);
    String expected1 = createStringFromLiteral("Life is ∆ rock (^-^) (^-^) (^-^)");    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringPadEnd(&source1, &empty, 3);
    String expected2 = createStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringPadEnd(&empty, &source2, 3);
    String expected3 = createStringFromLiteral(" (^-^) (^-^) (^-^)");   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }  
    
    String result4 = createStringPadEnd(&source1, &source2, -1);
    String expected4 = createStringFromLiteral("Life is ∆ rock");   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringPadEnd(&empty, &empty, 3);
    String expected5 = createStringEmpty();    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringPadEnd FAILS!\n");
        exit(1);
    }
}   

