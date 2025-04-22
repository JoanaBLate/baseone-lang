// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testStringSliceStart()
{
    printf("- testing stringSliceStart\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ rock");
   
    String result1 = stringSliceStart(empty, 3);
    String expected1 = makeStringEmpty();    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }

    String result2 = stringSliceStart(empty, -3);
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }

    String result3 = stringSliceStart(source, 0);
    String expected3 = makeStringEmpty();   
    if (! stringsAreEqual(result3, expected3)) { fails = true; }
    
    String result4 = stringSliceStart(source, -5);
    String expected4 = makeStringEmpty();   
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    String result5 = stringSliceStart(source, 4);
    String expected5 = makeStringFromLiteral("Life");    
    if (! stringsAreEqual(result5, expected5)) { fails = true; }

    String result6 = stringSliceStart(source, 400);
    String expected6 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(result6, expected6)) { fails = true; }

    if (fails) { 
        printf("stringSliceStart FAILS!\n");
        exit(1);
    }
}

void testStringSliceEnd()
{
    printf("- testing stringSliceEnd\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ rock");
   
    String result1 = stringSliceEnd(empty, 3);
    String expected1 = makeStringEmpty();    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }

    String result2 = stringSliceEnd(empty, -3);
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }

    String result3 = stringSliceEnd(source, 0);
    String expected3 = makeStringEmpty();   
    if (! stringsAreEqual(result3, expected3)) { fails = true; }
    
    String result4 = stringSliceEnd(source, -5);
    String expected4 = makeStringEmpty();   
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    String result5 = stringSliceEnd(source, 4);
    String expected5 = makeStringFromLiteral("rock");    
    if (! stringsAreEqual(result5, expected5)) { fails = true; }

    String result6 = stringSliceEnd(source, 400);
    String expected6 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(result6, expected6)) { fails = true; }

    if (fails) { 
        printf("stringSliceEnd FAILS!\n");
        exit(1);
    }
}

void testStringSlice()
{
    printf("- testing stringSlice\n");
        
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ rock");
   
    String result1 = stringSlice(empty, 3, 12);
    String expected1 = makeStringEmpty();    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String result2 = stringSlice(source, 3, 12);
    String expected2 = makeStringFromLiteral("fe is ∆ ro");    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    String result3 = stringSlice(source, 16, 1);
    String expected3 = makeStringFromLiteral("k");   
    if (! stringsAreEqual(result3, expected3)) { fails = true; }
        
    String result4 = stringSlice(source, 4, -5);
    String expected4 = makeStringEmpty();
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    String result5 = stringSlice(source, -44, 555);
    String expected5 = makeStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(result5, expected5)) { fails = true; }

    String result6 = stringSlice(source, -3, 8);    
    String expected6 = makeStringFromLiteral("Life");
    if (! stringsAreEqual(result6, expected6)) { fails = true; }
    
    String result7 = stringSlice(source, 13, 8000);
    String expected7 = makeStringFromLiteral("rock");
    if (! stringsAreEqual(result7, expected7)) { fails = true; }
    
    if (fails) { 
        printf("stringSlice FAILS!\n");
        exit(1);
    }
}

