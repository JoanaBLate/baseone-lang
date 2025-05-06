// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testCreateStringToLower()
{
    printf("- testing createStringToLower\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ ROCK");   
   
    String result1 = createStringToLower(source);
    String expected1 = makeStringFromLiteral("life is ∆ rock");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String result2 = createStringToLower(empty);
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("createStringToLower FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(result2);
    releaseString(expected2);
}

void testCreateStringToUpper()
{
    printf("- testing createStringToUpper\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ ROCK");   
   
    String result1 = createStringToUpper(source);
    String expected1 = makeStringFromLiteral("LIFE IS ∆ ROCK");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String result2 = createStringToUpper(empty);
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("createStringToUpper FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(result2);
    releaseString(expected2);
}

void testCreateStringToOppositeCase()
{
    printf("- testing createStringToOppositeCase\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ ROCK");   
   
    String result1 = createStringToOppositeCase(source);
    String expected1 = makeStringFromLiteral("lIFE IS ∆ rock");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String result2 = createStringToOppositeCase(empty);
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("createStringToOppositeCase FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(result2);
    releaseString(expected2);
}

void testCreateStringReverse()
{
    printf("- testing createStringReverse\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ rock");   
   
    String result1 = createStringReverse(source);    
    String expected1 = makeStringFromLiteral("kcor \x86\x88\xe2 si efiL");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String result2 = createStringReverse(empty);
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("createStringReverse FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(result2);
    releaseString(expected2);
}

void testCreateStringSort()
{
    printf("- testing createStringSort\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source = makeStringFromLiteral("Life is ∆ rock");   
   
    String result1 = createStringSort(source);
    String expected1 = makeStringFromLiteral("\x86\x88\xe2   Lcefiikors");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String result2 = createStringSort(empty);
    String expected2 = makeStringEmpty();    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("createStringSort FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(result2);
    releaseString(expected2);
}

