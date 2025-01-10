// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testCreateStringCutStart()
{
    printf("- testing createStringCutStart\n");
    
    bool fails = false;

    String empty = createEmptyString();    
    String source = { 16, "Life is ∆ rock" };   
   
    String result1 = createStringCutStart(&source, 5);
    String expected1 = { 11, "is ∆ rock" };
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringCutStart(&source, 500);
    String expected2 = empty;
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringCutStart(&source, 0);
    String expected3 = { 16, "Life is ∆ rock" };
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
   
    String result4 = createStringCutStart(&source, -5);
    String expected4 = { 16, "Life is ∆ rock" };
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
   
    String result5 = createStringCutStart(&empty, -5);
    String expected5 = { 0, "" };
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringCutStart FAILS!\n");
        exit(1);
    }
}

void testCreateStringCutEnd()
{
    printf("- testing createStringCutEnd\n");
    
    bool fails = false;

    String empty = createEmptyString();    
    String source = { 16, "Life is ∆ rock" };   
   
    String result1 = createStringCutEnd(&source, 5);
    String expected1 = { 11, "Life is ∆" };
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringCutEnd(&source, 500);
    String expected2 = empty;
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringCutEnd(&source, 0);
    String expected3 = { 16, "Life is ∆ rock" };
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
   
    String result4 = createStringCutEnd(&source, -5);
    String expected4 = { 16, "Life is ∆ rock" };
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
   
    String result5 = createStringCutEnd(&empty, -5);
    String expected5 = { 0, "" };
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringCutEnd FAILS!\n");
        exit(1);
    }
}

void testCreateStringCutMiddle()
{
    printf("- testing createStringCutMiddle\n");
    
    bool fails = false;

    String empty = createEmptyString();    
    String source = { 16, "Life is ∆ rock" };   
   
    String result1 = createStringCutMiddle(&source, 9, 4);
    String expected1 = { 12, "Life is rock" };
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringCutMiddle(&source, 8, 400);
    String expected2 = { 7, "Life is" };
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringCutMiddle(&source, -3, 12);
    String expected3 = { 8, "∆ rock" };
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringCutMiddle(&source, -300, 1000);
    String expected4 = empty;
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }

    String result5 = createStringCutMiddle(&empty, 0, 1);
    String expected5 = { 0, "" };
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringCutMiddle FAILS!\n");
        exit(1);
    }
}

void testCreateStringTrimStart()
{
    printf("- testing createStringTrimStart\n");
    
    bool fails = false;

    String empty = createEmptyString();    
    String source1 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    String source2 = {  4, "∆!" };   
    String source3 = {  2, "xy" };   
   
    String result1 = createStringTrimStart(&source1, &source2);
    String expected1 = { 26, " Life is ∆ rock ∆!∆!" };
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringTrimStart(&source1, &source3);
    String expected2 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringTrimStart(&source1, &empty);
    String expected3 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringTrimStart(&empty, &source1);
    String expected4 = { 0, "" };
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    if (fails) { 
        printf("createStringTrimStart FAILS!\n");
        exit(1);
    }
}

void testCreateStringTrimEnd()
{
    printf("- testing createStringTrimEnd\n");
    
    bool fails = false;

    String empty = createEmptyString();    
    String source1 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    String source2 = {  4, "∆!" };   
    String source3 = {  2, "xy" };   
   
    String result1 = createStringTrimEnd(&source1, &source2);
    String expected1 = { 26, "∆!∆! Life is ∆ rock " };
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringTrimEnd(&source1, &source3);
    String expected2 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringTrimEnd(&source1, &empty);
    String expected3 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringTrimEnd(&empty, &source1);
    String expected4 = { 0, "" };
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    if (fails) { 
        printf("createStringTrimEnd FAILS!\n");
        exit(1);
    }
}

void testCreateStringTrim()
{
    printf("- testing createStringTrim\n");
    
    bool fails = false;

    String empty = createEmptyString();    
    String source1 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    String source2 = {  4, "∆!" };   
    String source3 = {  2, "xy" };   
   
    String result1 = createStringTrim(&source1, &source2);
    String expected1 = { 18, " Life is ∆ rock " };
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringTrim(&source1, &source3);
    String expected2 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringTrim(&source1, &empty);
    String expected3 = { 34, "∆!∆! Life is ∆ rock ∆!∆!" };
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringTrim(&empty, &source1);
    String expected4 = { 0, "" };
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    if (fails) { 
        printf("createStringTrim FAILS!\n");
        exit(1);
    }
}

