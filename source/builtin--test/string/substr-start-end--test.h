// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testCreateStringStart()
{
    printf("- testing createStringStart\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ rock");
   
    String result1 = createStringStart(&empty, 3);
    String expected1 = makeStringEmpty();    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }

    String result2 = createStringStart(&empty, -3);
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }

    String result3 = createStringStart(&source, 0);
    String expected3 = makeStringEmpty();   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringStart(&source, -5);
    String expected4 = makeStringEmpty();   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringStart(&source, 4);
    String expected5 = makeStringFromLiteral("Life");    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }

    String result6 = createStringStart(&source, 400);
    String expected6 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }

    if (fails) { 
        printf("createStringStart FAILS!\n");
        exit(1);
    }
}

void testCreateStringEnd()
{
    printf("- testing createStringEnd\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ rock");
   
    String result1 = createStringEnd(&empty, 3);
    String expected1 = makeStringEmpty();    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }

    String result2 = createStringEnd(&empty, -3);
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }

    String result3 = createStringEnd(&source, 0);
    String expected3 = makeStringEmpty();   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringEnd(&source, -5);
    String expected4 = makeStringEmpty();   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringEnd(&source, 4);
    String expected5 = makeStringFromLiteral("rock");    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }

    String result6 = createStringEnd(&source, 400);
    String expected6 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }

    if (fails) { 
        printf("createStringEnd FAILS!\n");
        exit(1);
    }
}

void testCreateStringSub()
{
    printf("- testing createStringSub\n");
        
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ rock");
   
    String result1 = createStringSub(&empty, 3, 12);
    String expected1 = makeStringEmpty();    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringSub(&source, 3, 12);
    String expected2 = makeStringFromLiteral("fe is ∆ ro");    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringSub(&source, 16, 1);
    String expected3 = makeStringFromLiteral("k");   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
        
    String result4 = createStringSub(&source, 4, -5);
    String expected4 = makeStringEmpty();
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringSub(&source, -44, 555);
    String expected5 = makeStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }

    String result6 = createStringSub(&source, -3, 8);    
    String expected6 = makeStringFromLiteral("Life");
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }
    
    String result7 = createStringSub(&source, 13, 8000);
    String expected7 = makeStringFromLiteral("rock");
    if (! stringsAreEqual(&result7, &expected7)) { fails = true; }
    
    if (fails) { 
        printf("createStringSub FAILS!\n");
        exit(1);
    }
}

