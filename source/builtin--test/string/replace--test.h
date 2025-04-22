// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testNewStringReplaceStart()
{
    printf("- testing newStringReplaceStart\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life is ∆ rock");   
    String source2 = makeStringFromLiteral("∆ ");  
   
    String result1 = newStringReplaceStart(source1, 0, source2);
    String expected1 = makeStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
   
    String result2 = newStringReplaceStart(source1, 16, source2);
    String expected2 = makeStringFromLiteral("∆ ");    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    String result3 = newStringReplaceStart(source1, 5, source2);
    String expected3 = makeStringFromLiteral("∆ is ∆ rock");    
    if (! stringsAreEqual(result3, expected3)) { fails = true; }
    
    String result4 = newStringReplaceStart(source1, 8, empty);
    String expected4 = makeStringFromLiteral("∆ rock");
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    String result5 = newStringReplaceStart(empty, 1, empty);
    String expected5 = makeStringEmpty();    
    if (! stringsAreEqual(result5, expected5)) { fails = true; }
    
    if (fails) { 
        printf("newStringReplaceStart FAILS!\n");
        exit(1);
    }
}

void testNewStringReplaceEnd()
{
    printf("- testing newStringReplaceEnd\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life is ∆ rock");   
    String source2 = makeStringFromLiteral(" ∆");  
   
    String result1 = newStringReplaceEnd(source1, 0, source2);
    String expected1 = makeStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
   
    String result2 = newStringReplaceEnd(source1, 16, source2);
    String expected2 = makeStringFromLiteral(" ∆");    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    String result3 = newStringReplaceEnd(source1, 5, source2);
    String expected3 = makeStringFromLiteral("Life is ∆ ∆");    
    if (! stringsAreEqual(result3, expected3)) { fails = true; }
    
    String result4 = newStringReplaceEnd(source1, 5, empty);
    String expected4 = makeStringFromLiteral("Life is ∆");
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    String result5 = newStringReplaceEnd(empty, 1, empty);
    String expected5 = makeStringEmpty();    
    if (! stringsAreEqual(result5, expected5)) { fails = true; }
    
    if (fails) { 
        printf("newStringReplaceEnd FAILS!\n");
        exit(1);
    }
}

void testNewStringReplace()
{
    printf("- testing newStringReplace\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life is ∆ rock");   
    String source2 = makeStringFromLiteral("∆");  
    String source3 = makeStringFromLiteral("Xx--xX");  
   
    String result1 = newStringReplace(source1, source2, source3);
    String expected1 = makeStringFromLiteral("Life is Xx--xX rock");
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
   
    String result2 = newStringReplace(source1, source3, source2);
    String expected2 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    String result3 = newStringReplace(source1, source2, empty);
    String expected3 = makeStringFromLiteral("Life is  rock");    
    if (! stringsAreEqual(result3, expected3)) { fails = true; }
    
    String result4 = newStringReplace(source1, empty, source2);
    String expected4 = makeStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    String result5 = newStringReplace(source1, empty, empty);
    String expected5 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(result5, expected5)) { fails = true; }
    
    String result6 = newStringReplace(empty, empty, source1);
    String expected6 = makeStringEmpty();    
    if (! stringsAreEqual(result6, expected6)) { fails = true; }
    
    if (fails) { 
        printf("newStringReplace FAILS!\n");
        exit(1);
    }
}

void testNewStringReplaceLast()
{
    printf("- testing newStringReplaceLast\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life ∆ is ∆ rock");   
    String source2 = makeStringFromLiteral("∆");  
    String source3 = makeStringFromLiteral("Xx--xX");  
   
    String result1 = newStringReplaceLast(source1, source2, source3);
    String expected1 = makeStringFromLiteral("Life ∆ is Xx--xX rock");
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
   
    String result2 = newStringReplaceLast(source1, source3, source2);
    String expected2 = makeStringFromLiteral("Life ∆ is ∆ rock");    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    String result3 = newStringReplaceLast(source1, source2, empty);
    String expected3 = makeStringFromLiteral("Life ∆ is  rock");    
    if (! stringsAreEqual(result3, expected3)) { fails = true; }
    
    String result4 = newStringReplaceLast(source1, empty, source2);
    String expected4 = makeStringFromLiteral("Life ∆ is ∆ rock");
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    String result5 = newStringReplaceLast(source1, empty, empty);
    String expected5 = makeStringFromLiteral("Life ∆ is ∆ rock");    
    if (! stringsAreEqual(result5, expected5)) { fails = true; }
    
    String result6 = newStringReplaceLast(empty, empty, source1);
    String expected6 = makeStringEmpty();    
    if (! stringsAreEqual(result6, expected6)) { fails = true; }
    
    if (fails) { 
        printf("newStringReplaceLast FAILS!\n");
        exit(1);
    }
}

void testNewStringReplaceAll()
{
    printf("- testing newStringReplaceAll\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("∆∆∆ Life ∆is ∆ rock ∆∆∆");   
    String source2 = makeStringFromLiteral("∆");    
    String source3 = makeStringFromLiteral("∆∆");  
    String source4 = makeStringFromLiteral("Y.Y");
   
    String result1 = newStringReplaceAll(source1, source2, source3);
    String expected1 = makeStringFromLiteral("∆∆∆∆∆∆ Life ∆∆is ∆∆ rock ∆∆∆∆∆∆");  
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
   
    String result2 = newStringReplaceAll(source1, source2, source4);
    String expected2 = makeStringFromLiteral("Y.YY.YY.Y Life Y.Yis Y.Y rock Y.YY.YY.Y");  
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    String result3 = newStringReplaceAll(source1, source3, source2);
    String expected3 = makeStringFromLiteral("∆∆ Life ∆is ∆ rock ∆∆");    
    if (! stringsAreEqual(result3, expected3)) { fails = true; }

    String result4 = newStringReplaceAll(empty, source1, source2);
    String expected4 = makeStringEmpty();    
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    String result5 = newStringReplaceAll(source1, source2, empty);
    String expected5 = makeStringFromLiteral(" Life is  rock ");    
    if (! stringsAreEqual(result5, expected5)) { fails = true; }
    
    if (fails) { 
        printf("newStringReplaceAll FAILS!\n");
        exit(1);
    }
}

