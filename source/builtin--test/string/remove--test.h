// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testCreateStringRemove()
{
    printf("- testing createStringRemove\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life is ∆ rock");   
    String source2 = makeStringFromLiteral("∆ ");  
    String source3 = makeStringFromLiteral("x");
   
    String result1 = createStringRemove(source1, source2);
    String expected1 = makeStringFromLiteral("Life is rock");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
   
    String result2 = createStringRemove(source1, source3);
    String expected2 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    String result3 = createStringRemove(source1, empty);
    String expected3 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(result3, expected3)) { fails = true; }
    
    String result4 = createStringRemove(empty, source1);
    String expected4 = makeStringEmpty();    
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    String result5 = createStringRemove(empty, empty);
    String expected5 = makeStringEmpty();    
    if (! stringsAreEqual(result5, expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringRemove FAILS!\n");
        exit(1);
    }
}

void testCreateStringRemoveLast()
{
    printf("- testing createStringRemoveLast\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life ∆ is ∆ rock");   
    String source2 = makeStringFromLiteral("∆ ");  
    String source3 = makeStringFromLiteral("x");
   
    String result1 = createStringRemoveLast(source1, source2);
    String expected1 = makeStringFromLiteral("Life ∆ is rock");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
   
    String result2 = createStringRemoveLast(source1, source3);
    String expected2 = makeStringFromLiteral("Life ∆ is ∆ rock");    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    String result3 = createStringRemoveLast(source1, empty);
    String expected3 = makeStringFromLiteral("Life ∆ is ∆ rock");    
    if (! stringsAreEqual(result3, expected3)) { fails = true; }
    
    String result4 = createStringRemoveLast(empty, source1);
    String expected4 = makeStringEmpty();    
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    String result5 = createStringRemoveLast(empty, empty);
    String expected5 = makeStringEmpty();    
    if (! stringsAreEqual(result5, expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringRemoveLast FAILS!\n");
        exit(1);
    }
}

void testCreateStringRemoveAll()
{
    printf("- testing createStringRemoveAll\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("∆∆∆ Life ∆is ∆ rock ∆∆∆");   
    String source2 = makeStringFromLiteral("∆");    
    String source3 = makeStringFromLiteral("∆∆");
   
    String result1 = createStringRemoveAll(source1, source2);
    String expected1 = makeStringFromLiteral(" Life is  rock ");   
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
   
    String result2 = createStringRemoveAll(source1, source3);
    String expected2 = makeStringFromLiteral("∆ Life ∆is ∆ rock ∆");    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    String result3 = createStringRemoveAll(source1, empty);
    String expected3 = makeStringFromLiteral("∆∆∆ Life ∆is ∆ rock ∆∆∆");    
    if (! stringsAreEqual(result3, expected3)) { fails = true; }
    
    String result4 = createStringRemoveAll(empty, source1);
    String expected4 = makeStringEmpty();    
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    if (fails) { 
        printf("createStringRemoveAll FAILS!\n");
        exit(1);
    }
}

