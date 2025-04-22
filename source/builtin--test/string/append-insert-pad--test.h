// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testNewStringAppend()
{
    printf("- testing newStringAppend\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life is ∆");   
    String source2 = makeStringFromLiteral(" rock");
   
    String result1 = newStringAppend(source1, source2);
    String expected1 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }

    String result2 = newStringAppend(source1, empty);
    String expected2 = source1;    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }

    String result3 = newStringAppend(empty, source1);
    String expected3 = source1;   
    if (! stringsAreEqual(result3, expected3)) { fails = true; }
    
    String result4 = newStringAppend(empty, empty);
    String expected4 = makeStringEmpty();   
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    if (fails) { 
        printf("newStringAppend FAILS!\n");
        exit(1);
    }
}

void testNewStringInsert()
{
    printf("- testing newStringInsert\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life is ∆");   
    String source2 = makeStringFromLiteral(" rock");
   
    String result1 = newStringInsert(source1, source2, 1000);
    String expected1 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
   
    String result2 = newStringInsert(source1, source2, 1);
    String expected2 = makeStringFromLiteral(" rockLife is ∆");    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
   
    String result3 = newStringInsert(source1, source2, -1000);
    String expected3 = makeStringFromLiteral(" rockLife is ∆");    
    if (! stringsAreEqual(result3, expected3)) { fails = true; }
    
    String result4 = newStringInsert(source1, source2, 8);    
    String expected4 = makeStringFromLiteral("Life is rock ∆");    
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    String result5 = newStringInsert(source1, empty, 1);    
    String expected5 = source1;       
    if (! stringsAreEqual(result5, expected5)) { fails = true; }
    
    String result6 = newStringInsert(source1, empty, 1);    
    String expected6 = source1;       
    if (! stringsAreEqual(result6, expected6)) { fails = true; }
    
    String result7 = newStringInsert(empty, empty, 1);    
    String expected7 = makeStringEmpty();       
    if (! stringsAreEqual(result7, expected7)) { fails = true; }
    
    if (fails) { 
        printf("newStringInsert FAILS!\n");
        exit(1);
    }
}

void testNewStringPadStart()
{
    printf("- testing newStringPadStart\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life is ∆ rock");   
    String source2 = makeStringFromLiteral("(^-^) ");
   
    String result1 = newStringPadStart(source1, source2, 3);
    String expected1 = makeStringFromLiteral("(^-^) (^-^) (^-^) Life is ∆ rock");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String result2 = newStringPadStart(source1, empty, 3);
    String expected2 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    String result3 = newStringPadStart(empty, source2, 3);
    String expected3 = makeStringFromLiteral("(^-^) (^-^) (^-^) ");   
    if (! stringsAreEqual(result3, expected3)) { fails = true; }
    
    String result4 = newStringPadStart(source1, source2, -1);
    String expected4 = makeStringFromLiteral("Life is ∆ rock");   
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    String result5 = newStringPadStart(empty, empty, 3);
    String expected5 = makeStringEmpty();    
    if (! stringsAreEqual(result5, expected5)) { fails = true; }
    
    if (fails) { 
        printf("newStringPadStart FAILS!\n");
        exit(1);
    }
}   

void testNewStringPadEnd()
{
    printf("- testing newStringPadEnd\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life is ∆ rock");   
    String source2 = makeStringFromLiteral(" (^-^)");
   
    String result1 = newStringPadEnd(source1, source2, 3);
    String expected1 = makeStringFromLiteral("Life is ∆ rock (^-^) (^-^) (^-^)");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String result2 = newStringPadEnd(source1, empty, 3);
    String expected2 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    String result3 = newStringPadEnd(empty, source2, 3);
    String expected3 = makeStringFromLiteral(" (^-^) (^-^) (^-^)");   
    if (! stringsAreEqual(result3, expected3)) { fails = true; }  
    
    String result4 = newStringPadEnd(source1, source2, -1);
    String expected4 = makeStringFromLiteral("Life is ∆ rock");   
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    String result5 = newStringPadEnd(empty, empty, 3);
    String expected5 = makeStringEmpty();    
    if (! stringsAreEqual(result5, expected5)) { fails = true; }
    
    if (fails) { 
        printf("newStringPadEnd FAILS!\n");
        exit(1);
    }
}   

