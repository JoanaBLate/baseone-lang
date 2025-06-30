// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testCreateSubstringStart()
{
    printf("- testing createSubstringStart\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ rock");
   
    String result1 = createSubstringStart(&empty, 3);
    String expected1 = makeStringEmpty();    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }

    String result2 = createSubstringStart(&empty, -3);
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }

    String result3 = createSubstringStart(&source, 0);
    String expected3 = makeStringEmpty();   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createSubstringStart(&source, -5);
    String expected4 = makeStringEmpty();   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createSubstringStart(&source, 4);
    String expected5 = makeStringFromLiteral("Life");    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }

    String result6 = createSubstringStart(&source, 400);
    String expected6 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }

    if (fails) { 
        printf("createSubstringStart FAILS!\n");
        exit(1);
    }
    
    releaseString(&result1);
    releaseString(&expected1);
    releaseString(&result2);
    releaseString(&expected2);
    releaseString(&result3);
    releaseString(&expected3);
    releaseString(&result4);
    releaseString(&expected4);
    releaseString(&result5);
    releaseString(&result6);
}

void testCreateSubstringEnd()
{
    printf("- testing createSubstringEnd\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ rock");
   
    String result1 = createSubstringEnd(&empty, 3);
    String expected1 = makeStringEmpty();    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }

    String result2 = createSubstringEnd(&empty, -3);
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }

    String result3 = createSubstringEnd(&source, 0);
    String expected3 = makeStringEmpty();   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createSubstringEnd(&source, -5);
    String expected4 = makeStringEmpty();   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createSubstringEnd(&source, 4);
    String expected5 = makeStringFromLiteral("rock");    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }

    String result6 = createSubstringEnd(&source, 400);
    String expected6 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }

    if (fails) { 
        printf("createSubstringEnd FAILS!\n");
        exit(1);
    }
    
    releaseString(&result1);
    releaseString(&expected1);
    releaseString(&result2);
    releaseString(&expected2);
    releaseString(&result3);
    releaseString(&expected3);
    releaseString(&result4);
    releaseString(&expected4);
    releaseString(&result5);
    releaseString(&result6);
}

void testCreateSubstring()
{
    printf("- testing createSubstring\n");
        
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ rock");
   
    String result1 = createSubstring(&empty, 3, 12);
    String expected1 = makeStringEmpty();    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createSubstring(&source, 3, 12);
    String expected2 = makeStringFromLiteral("fe is ∆ ro");    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createSubstring(&source, 16, 1);
    String expected3 = makeStringFromLiteral("k");   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
        
    String result4 = createSubstring(&source, 4, -5);
    String expected4 = makeStringEmpty();
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createSubstring(&source, -44, 555);
    String expected5 = makeStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }

    String result6 = createSubstring(&source, -3, 8);    
    String expected6 = makeStringFromLiteral("Life");
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }
    
    String result7 = createSubstring(&source, 13, 8000);
    String expected7 = makeStringFromLiteral("rock");
    if (! stringsAreEqual(&result7, &expected7)) { fails = true; }
    
    if (fails) { 
        printf("createSubstring FAILS!\n");
        exit(1);
    }
    
    releaseString(&result1);
    releaseString(&expected1);
    releaseString(&result2);
    releaseString(&result3);
    releaseString(&result4);
    releaseString(&expected4);
    releaseString(&result5);
    releaseString(&result6);
    releaseString(&result7);
}

