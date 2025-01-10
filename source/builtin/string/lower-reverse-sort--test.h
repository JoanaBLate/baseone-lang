// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testCreateStringToLower()
{
    printf("- testing createStringToLower\n");
    
    bool fails = false;

    String empty = createEmptyString();    
    String source = { 16, "Life is ∆ ROCK" };   
   
    String result1 = createStringToLower(&source);
    String expected1 = { 16, "life is ∆ rock" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringToLower(&empty);
    String expected2 = { 0, "" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    if (fails) { 
        printf("createStringToLower FAILS!\n");
        exit(1);
    }
}

void testCreateStringToUpper()
{
    printf("- testing createStringToUpper\n");
    
    bool fails = false;

    String empty = createEmptyString();    
    String source = { 16, "Life is ∆ ROCK" };   
   
    String result1 = createStringToUpper(&source);
    String expected1 = { 16, "LIFE IS ∆ ROCK" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringToUpper(&empty);
    String expected2 = { 0, "" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    if (fails) { 
        printf("createStringToUpper FAILS!\n");
        exit(1);
    }
}

void testCreateStringToOppositeCase()
{
    printf("- testing createStringToOppositeCase\n");
    
    bool fails = false;

    String empty = createEmptyString();    
    String source = { 16, "Life is ∆ ROCK" };   
   
    String result1 = createStringToOppositeCase(&source);
    String expected1 = { 16, "lIFE IS ∆ rock" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringToOppositeCase(&empty);
    String expected2 = { 0, "" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    if (fails) { 
        printf("createStringToOppositeCase FAILS!\n");
        exit(1);
    }
}

void testCreateReversedString()
{
    printf("- testing createReversedString\n");
    
    bool fails = false;

    String empty = createEmptyString();    
    String source = { 16, "Life is ∆ rock" };   
   
    String result1 = createReversedString(&source);    
    String expected1 = { 16, "kcor \x86\x88\xe2 si efiL" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createReversedString(&empty);
    String expected2 = { 0, "" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    if (fails) { 
        printf("createReversedString FAILS!\n");
        exit(1);
    }
}

void testCreateSortedString()
{
    printf("- testing createSortedString\n");
    
    bool fails = false;

    String empty = createEmptyString();    
    String source = { 16, "Life is ∆ rock" };   
   
    String result1 = createSortedString(&source);
    String expected1 = { 16, "\x86\x88\xe2   Lcefiikors" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createSortedString(&empty);
    String expected2 = { 0, "" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    if (fails) { 
        printf("createSortedString FAILS!\n");
        exit(1);
    }
}

