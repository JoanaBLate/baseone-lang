// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testNewStringRemove()
{
    printf("- testing newStringRemove\n");
    
    bool fails = false;

    String* empty = makeStringEmpty();    
    String* source1 = makeStringFromLiteral("Life is ∆ rock");   
    String* source2 = makeStringFromLiteral("∆ ");  
    String* source3 = makeStringFromLiteral("x");
   
    String* result1 = newStringRemove(source1, source2);
    String* expected1 = makeStringFromLiteral("Life is rock");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
   
    String* result2 = newStringRemove(source1, source3);
    String* expected2 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    String* result3 = newStringRemove(source1, empty);
    String* expected3 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(result3, expected3)) { fails = true; }
    
    String* result4 = newStringRemove(empty, source1);
    String* expected4 = makeStringEmpty();    
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    String* result5 = newStringRemove(empty, empty);
    String* expected5 = makeStringEmpty();    
    if (! stringsAreEqual(result5, expected5)) { fails = true; }
    
    if (fails) { 
        printf("newStringRemove FAILS!\n");
        exit(1);
    }
}

void testNewStringRemoveLast()
{
    printf("- testing newStringRemoveLast\n");
    
    bool fails = false;

    String* empty = makeStringEmpty();    
    String* source1 = makeStringFromLiteral("Life ∆ is ∆ rock");   
    String* source2 = makeStringFromLiteral("∆ ");  
    String* source3 = makeStringFromLiteral("x");
   
    String* result1 = newStringRemoveLast(source1, source2);
    String* expected1 = makeStringFromLiteral("Life ∆ is rock");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
   
    String* result2 = newStringRemoveLast(source1, source3);
    String* expected2 = makeStringFromLiteral("Life ∆ is ∆ rock");    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    String* result3 = newStringRemoveLast(source1, empty);
    String* expected3 = makeStringFromLiteral("Life ∆ is ∆ rock");    
    if (! stringsAreEqual(result3, expected3)) { fails = true; }
    
    String* result4 = newStringRemoveLast(empty, source1);
    String* expected4 = makeStringEmpty();    
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    String* result5 = newStringRemoveLast(empty, empty);
    String* expected5 = makeStringEmpty();    
    if (! stringsAreEqual(result5, expected5)) { fails = true; }
    
    if (fails) { 
        printf("newStringRemoveLast FAILS!\n");
        exit(1);
    }
}

void testNewStringRemoveAll()
{
    printf("- testing newStringRemoveAll\n");
    
    bool fails = false;

    String* empty = makeStringEmpty();    
    String* source1 = makeStringFromLiteral("∆∆∆ Life ∆is ∆ rock ∆∆∆");   
    String* source2 = makeStringFromLiteral("∆");    
    String* source3 = makeStringFromLiteral("∆∆");
   
    String* result1 = newStringRemoveAll(source1, source2);
    String* expected1 = makeStringFromLiteral(" Life is  rock ");   
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
   
    String* result2 = newStringRemoveAll(source1, source3);
    String* expected2 = makeStringFromLiteral("∆ Life ∆is ∆ rock ∆");    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    String* result3 = newStringRemoveAll(source1, empty);
    String* expected3 = makeStringFromLiteral("∆∆∆ Life ∆is ∆ rock ∆∆∆");    
    if (! stringsAreEqual(result3, expected3)) { fails = true; }
    
    String* result4 = newStringRemoveAll(empty, source1);
    String* expected4 = makeStringEmpty();    
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    if (fails) { 
        printf("newStringRemoveAll FAILS!\n");
        exit(1);
    }
}

