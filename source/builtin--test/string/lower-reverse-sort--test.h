// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testNewStringToLower()
{
    printf("- testing newStringToLower\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ ROCK");   
   
    String result1 = newStringToLower(source);
    String expected1 = makeStringFromLiteral("life is ∆ rock");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String result2 = newStringToLower(empty);
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("newStringToLower FAILS!\n");
        exit(1);
    }
}

void testNewStringToUpper()
{
    printf("- testing newStringToUpper\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ ROCK");   
   
    String result1 = newStringToUpper(source);
    String expected1 = makeStringFromLiteral("LIFE IS ∆ ROCK");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String result2 = newStringToUpper(empty);
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("newStringToUpper FAILS!\n");
        exit(1);
    }
}

void testNewStringToOppositeCase()
{
    printf("- testing newStringToOppositeCase\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ ROCK");   
   
    String result1 = newStringToOppositeCase(source);
    String expected1 = makeStringFromLiteral("lIFE IS ∆ rock");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String result2 = newStringToOppositeCase(empty);
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("newStringToOppositeCase FAILS!\n");
        exit(1);
    }
}

void testNewStringReverse()
{
    printf("- testing newStringReverse\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ rock");   
   
    String result1 = newStringReverse(source);    
    String expected1 = makeStringFromLiteral("kcor \x86\x88\xe2 si efiL");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String result2 = newStringReverse(empty);
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("newStringReverse FAILS!\n");
        exit(1);
    }
}

void testNewStringSort()
{
    printf("- testing newStringSort\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ rock");   
   
    String result1 = newStringSort(source);
    String expected1 = makeStringFromLiteral("\x86\x88\xe2   Lcefiikors");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String result2 = newStringSort(empty);
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("newStringSort FAILS!\n");
        exit(1);
    }
}

