// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testCreateStringToLowerHeap()
{
    printf("- testing createStringToLowerHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source = { 16, "Life is ∆ ROCK" };   
   
    String result1 = createStringToLowerHeap(&source);
    String expected1 = { 16, "life is ∆ rock" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringToLowerHeap(&empty);
    String expected2 = { 0, "" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    if (fails) { 
        printf("createStringToLowerHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringToUpperHeap()
{
    printf("- testing createStringToUpperHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source = { 16, "Life is ∆ ROCK" };   
   
    String result1 = createStringToUpperHeap(&source);
    String expected1 = { 16, "LIFE IS ∆ ROCK" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringToUpperHeap(&empty);
    String expected2 = { 0, "" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    if (fails) { 
        printf("createStringToUpperHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringToOppositeCaseHeap()
{
    printf("- testing createStringToOppositeCaseHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source = { 16, "Life is ∆ ROCK" };   
   
    String result1 = createStringToOppositeCaseHeap(&source);
    String expected1 = { 16, "lIFE IS ∆ rock" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringToOppositeCaseHeap(&empty);
    String expected2 = { 0, "" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    if (fails) { 
        printf("createStringToOppositeCaseHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringReverseHeap()
{
    printf("- testing createStringReverseHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source = { 16, "Life is ∆ rock" };   
   
    String result1 = createStringReverseHeap(&source);    
    String expected1 = { 16, "kcor \x86\x88\xe2 si efiL" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringReverseHeap(&empty);
    String expected2 = { 0, "" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    if (fails) { 
        printf("createStringReverseHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringSortHeap()
{
    printf("- testing createStringSortHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source = { 16, "Life is ∆ rock" };   
   
    String result1 = createStringSortHeap(&source);
    String expected1 = { 16, "\x86\x88\xe2   Lcefiikors" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringSortHeap(&empty);
    String expected2 = { 0, "" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    if (fails) { 
        printf("createStringSortHeap FAILS!\n");
        exit(1);
    }
}

