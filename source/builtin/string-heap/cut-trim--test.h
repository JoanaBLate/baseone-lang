// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testCreateStringCutStartHeap()
{
    printf("- testing createStringCutStartHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source = { 16, "Life is ∆ rock" };   
   
    String result1 = createStringCutStartHeap(&source, 5);
    String expected1 = { 11, "is ∆ rock" };
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringCutStartHeap(&source, 500);
    String expected2 = empty;
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringCutStartHeap(&source, 0);
    String expected3 = { 16, "Life is ∆ rock" };
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
   
    String result4 = createStringCutStartHeap(&source, -5);
    String expected4 = { 16, "Life is ∆ rock" };
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
   
    String result5 = createStringCutStartHeap(&empty, -5);
    String expected5 = { 0, "" };
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringCutStartHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringCutEndHeap()
{
    printf("- testing createStringCutEndHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source = { 16, "Life is ∆ rock" };   
   
    String result1 = createStringCutEndHeap(&source, 5);
    String expected1 = { 11, "Life is ∆" };
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringCutEndHeap(&source, 500);
    String expected2 = empty;
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringCutEndHeap(&source, 0);
    String expected3 = { 16, "Life is ∆ rock" };
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
   
    String result4 = createStringCutEndHeap(&source, -5);
    String expected4 = { 16, "Life is ∆ rock" };
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
   
    String result5 = createStringCutEndHeap(&empty, -5);
    String expected5 = { 0, "" };
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringCutEndHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringCutMiddleHeap()
{
    printf("- testing createStringCutMiddleHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source = { 16, "Life is ∆ rock" };   
   
    String result1 = createStringCutMiddleHeap(&source, 9, 4);
    String expected1 = { 12, "Life is rock" };
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringCutMiddleHeap(&source, 8, 400);
    String expected2 = { 7, "Life is" };
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringCutMiddleHeap(&source, -3, 12);
    String expected3 = { 8, "∆ rock" };
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringCutMiddleHeap(&source, -300, 1000);
    String expected4 = empty;
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }

    String result5 = createStringCutMiddleHeap(&empty, 0, 1);
    String expected5 = { 0, "" };
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringCutMiddleHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringTrimStartHeap()
{
    printf("- testing createStringTrimStartHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    String source2 = {  4, "∆!" };   
    String source3 = {  2, "xy" };   
   
    String result1 = createStringTrimStartHeap(&source1, &source2);
    String expected1 = { 26, " Life is ∆ rock ∆!∆!" };
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringTrimStartHeap(&source1, &source3);
    String expected2 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringTrimStartHeap(&source1, &empty);
    String expected3 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringTrimStartHeap(&empty, &source1);
    String expected4 = { 0, "" };
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    if (fails) { 
        printf("createStringTrimStartHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringTrimEndHeap()
{
    printf("- testing createStringTrimEndHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    String source2 = {  4, "∆!" };   
    String source3 = {  2, "xy" };   
   
    String result1 = createStringTrimEndHeap(&source1, &source2);
    String expected1 = { 26, "∆!∆! Life is ∆ rock " };
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringTrimEndHeap(&source1, &source3);
    String expected2 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringTrimEndHeap(&source1, &empty);
    String expected3 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringTrimEndHeap(&empty, &source1);
    String expected4 = { 0, "" };
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    if (fails) { 
        printf("createStringTrimEndHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringTrimHeap()
{
    printf("- testing createStringTrimHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    String source2 = {  4, "∆!" };   
    String source3 = {  2, "xy" };   
   
    String result1 = createStringTrimHeap(&source1, &source2);
    String expected1 = { 18, " Life is ∆ rock " };
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringTrimHeap(&source1, &source3);
    String expected2 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringTrimHeap(&source1, &empty);
    String expected3 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringTrimHeap(&empty, &source1);
    String expected4 = { 0, "" };
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    if (fails) { 
        printf("createStringTrimHeap FAILS!\n");
        exit(1);
    }
}

