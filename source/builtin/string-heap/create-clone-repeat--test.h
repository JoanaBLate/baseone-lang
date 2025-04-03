// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testCreateStringFromCharCodeHeap() 
{    
    printf("- testing createStringFromCharCodeHeap\n");
    
    bool fails = false;
    
    String result1 = createStringFromCharCodeHeap(64);
    String expected1 = { 1, "@" };
    if (! stringsAreEqual(&expected1, &result1)) { fails = true; }
    
    String result2 = createStringFromCharCodeHeap(364);
    String expected2 = createStringEmpty();
    if (! stringsAreEqual(&expected2, &result2)) { fails = true ; }
    
    String result3 = createStringFromCharCodeHeap(-1);
    String expected3 = createStringEmpty();
    if (! stringsAreEqual(&expected3, &result3)) { fails = true ; }
    
    if (fails) {
        printf("createStringFromCharCodeHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringFromLiteralHeap()
{    
    printf("- testing createStringFromLiteralHeap\n");
    
    bool fails = false;
    
    String result1 = createStringFromLiteralHeap("Life is ∆ rock");
    String expected1 = { 16, "Life is ∆ rock" };    
    if (!stringsAreEqual(&expected1, &result1)) { fails = true; }    
    
    String result2 = createStringFromLiteralHeap("");
    String expected2 = createStringEmpty();  
    if (!stringsAreEqual(&expected2, &result2)) { fails = true; }
    
    if (fails) { 
        printf("createStringFromLiteralHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringCloneHeap()
{
    printf("- testing createStringCloneHeap\n");
    
    bool fails = false;
    
    String source1 = { 16, "Life is ∆ rock" };
    String result1 = createStringCloneHeap(&source1);
    String expected1 = { 16, "Life is ∆ rock" };
    if (! stringsAreEqual(&expected1, &result1)) { fails = true; }
    
    String source2 = createStringEmpty(); 
    String result2 = createStringCloneHeap(&source2);
    String expected2 = createStringEmpty();
    if (! stringsAreEqual(&expected2, &result2)) { fails = true; }
    
    if (fails) {
        printf("createStringCloneHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringRepeatHeap()
{  
    printf("- testing createStringRepeatHeap\n");
      
    bool fails = false;
    String source = { 10, "∆rock∆" };
    
    String result1 = createStringRepeatHeap(&source, 3);
    String expected1 = { 30, "∆rock∆∆rock∆∆rock∆" };
    if (! stringsAreEqual(&expected1, &result1)) { fails = true; }

    String result2 = createStringRepeatHeap(&source, -33);
    String expected2 = createStringEmpty();
    if (! stringsAreEqual(&expected2, &result2)) { fails = true; }

    String source3 = createStringEmpty();
    String result3 = createStringRepeatHeap(&source3, 3);
    String expected3 = createStringEmpty();
    if (! stringsAreEqual(&expected3, &result3)) { fails = true; }
    
    if (fails) {
        printf("createStringRepeatHeap FAILS!\n");
        exit(1);
    }
}

