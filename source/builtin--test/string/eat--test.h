// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testStringEatStart()
{
    printf("- testing stringEatStart\n");
    
    bool fails = false;

    String source1 = makeStringFromLiteral("Life is ∆ rock"); 
    String result1 = stringEatStart(&source1, 5);
    String expected1a = makeStringFromLiteral("Life ");
    String expected1b = makeStringFromLiteral("is ∆ rock");
    if (! stringsAreEqual(result1, expected1a)) { fails = true; }
    if (! stringsAreEqual(source1, expected1b)) { fails = true; }

    String source2 = makeStringFromLiteral("Life is ∆ rock"); 
    String result2 = stringEatStart(&source2, 500);
    String expected2a = makeStringFromLiteral("Life is ∆ rock");
    String expected2b = makeStringFromLiteral("");
    if (! stringsAreEqual(result2, expected2a)) { fails = true; }
    if (! stringsAreEqual(source2, expected2b)) { fails = true; }
   
    String source3 = makeStringFromLiteral("Life is ∆ rock"); 
    String result3 = stringEatStart(&source3, -5);
    String expected3a = makeStringFromLiteral("");
    String expected3b = makeStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(result3, expected3a)) { fails = true; }
    if (! stringsAreEqual(source3, expected3b)) { fails = true; }
    
    String source4 = makeStringFromLiteral(""); 
    String result4 = stringEatStart(&source4, 5);
    String expected4a = makeStringFromLiteral("");
    String expected4b = makeStringFromLiteral("");
    if (! stringsAreEqual(result4, expected4a)) { fails = true; }
    if (! stringsAreEqual(source4, expected4b)) { fails = true; }
    
    if (fails) { 
        printf("stringEatStart FAILS!\n");
        exit(1);
    }
}

void testStringEatEnd()
{
    printf("- testing stringEatEnd\n");
    
    bool fails = false;   

    String source1 = makeStringFromLiteral("Life is ∆ rock"); 
    String result1 = stringEatEnd(&source1, 5);
    String expected1a = makeStringFromLiteral(" rock");
    String expected1b = makeStringFromLiteral("Life is ∆");
    if (! stringsAreEqual(result1, expected1a)) { fails = true; }
    if (! stringsAreEqual(source1, expected1b)) { fails = true; }

    String source2 = makeStringFromLiteral("Life is ∆ rock"); 
    String result2 = stringEatEnd(&source2, 500);
    String expected2a = makeStringFromLiteral("Life is ∆ rock");
    String expected2b = makeStringFromLiteral("");
    if (! stringsAreEqual(result2, expected2a)) { fails = true; }
    if (! stringsAreEqual(source2, expected2b)) { fails = true; }
   
    String source3 = makeStringFromLiteral("Life is ∆ rock"); 
    String result3 = stringEatEnd(&source3, -5);
    String expected3a = makeStringFromLiteral("");
    String expected3b = makeStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(result3, expected3a)) { fails = true; }
    if (! stringsAreEqual(source3, expected3b)) { fails = true; }
   
    String source4 = makeStringFromLiteral(""); 
    String result4 = stringEatEnd(&source4, 5);
    String expected4a = makeStringFromLiteral("");
    String expected4b = makeStringFromLiteral("");
    if (! stringsAreEqual(result4, expected4a)) { fails = true; }
    if (! stringsAreEqual(source4, expected4b)) { fails = true; }
    
    if (fails) { 
        printf("stringEatEnd FAILS!\n");
        exit(1);
    }
}

