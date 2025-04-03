// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testCreateStringAppendHeap()
{
    printf("- testing createStringAppendHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = { 11, "Life is ∆" };   
    String source2 = {  5, " rock" };
   
    String result1 = createStringAppendHeap(&source1, &source2);
    String expected1 = { 16, "Life is ∆ rock" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }

    String result2 = createStringAppendHeap(&source1, &empty);
    String expected2 = source1;    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }

    String result3 = createStringAppendHeap(&empty, &source1);
    String expected3 = source1;   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringAppendHeap(&empty, &empty);
    String expected4 = createStringEmpty();   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    if (fails) { 
        printf("createStringAppendHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringInsertHeap()
{
    printf("- testing createStringInsertHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = { 11, "Life is ∆" };   
    String source2 = {  5, " rock" };
   
    String result1 = createStringInsertHeap(&source1, &source2, 1000);
    String expected1 = { 16, "Life is ∆ rock" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringInsertHeap(&source1, &source2, 1);
    String expected2 = { 16, " rockLife is ∆" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
   
    String result3 = createStringInsertHeap(&source1, &source2, -1000);
    String expected3 = { 16, " rockLife is ∆" };    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringInsertHeap(&source1, &source2, 8);    
    String expected4 = { 16, "Life is rock ∆" };    
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringInsertHeap(&source1, &empty, 1);    
    String expected5 = source1;       
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    String result6 = createStringInsertHeap(&source1, &empty, 1);    
    String expected6 = source1;       
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }
    
    String result7 = createStringInsertHeap(&empty, &empty, 1);    
    String expected7 = createStringEmpty();       
    if (! stringsAreEqual(&result7, &expected7)) { fails = true; }
    
    if (fails) { 
        printf("createStringInsertHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringPadStartHeap()
{
    printf("- testing createStringPadStartHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = { 16, "Life is ∆ rock" };   
    String source2 = {  6, "(^-^) " };
   
    String result1 = createStringPadStartHeap(&source1, &source2, 3);
    String expected1 = { 34, "(^-^) (^-^) (^-^) Life is ∆ rock" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringPadStartHeap(&source1, &empty, 3);
    String expected2 = { 16, "Life is ∆ rock" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringPadStartHeap(&empty, &source2, 3);
    String expected3 = { 18, "(^-^) (^-^) (^-^) " };   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringPadStartHeap(&source1, &source2, -1);
    String expected4 = { 16, "Life is ∆ rock" };   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringPadStartHeap(&empty, &empty, 3);
    String expected5 = createStringEmpty();    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringPadStartHeap FAILS!\n");
        exit(1);
    }
}   

void testCreateStringPadEndHeap()
{
    printf("- testing createStringPadEndHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = { 16, "Life is ∆ rock" };   
    String source2 = {  6, " (^-^)" };
   
    String result1 = createStringPadEndHeap(&source1, &source2, 3);
    String expected1 = { 34, "Life is ∆ rock (^-^) (^-^) (^-^)" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringPadEndHeap(&source1, &empty, 3);
    String expected2 = { 16, "Life is ∆ rock" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringPadEndHeap(&empty, &source2, 3);
    String expected3 = { 18, " (^-^) (^-^) (^-^)" };   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }  
    
    String result4 = createStringPadEndHeap(&source1, &source2, -1);
    String expected4 = { 16, "Life is ∆ rock" };   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringPadEndHeap(&empty, &empty, 3);
    String expected5 = createStringEmpty();    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringPadEndHeap FAILS!\n");
        exit(1);
    }
}   

