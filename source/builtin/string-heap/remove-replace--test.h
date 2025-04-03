// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testCreateStringRemoveHeap()
{
    printf("- testing createStringRemoveHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = { 16, "Life is ∆ rock" };   
    String source2 = {  4, "∆ " };  
    String source3 = {  1, "x" };
   
    String result1 = createStringRemoveHeap(&source1, &source2);
    String expected1 = { 12, "Life is rock" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringRemoveHeap(&source1, &source3);
    String expected2 = { 16, "Life is ∆ rock" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringRemoveHeap(&source1, &empty);
    String expected3 = { 16, "Life is ∆ rock" };    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringRemoveHeap(&empty, &source1);
    String expected4 = { 0, "" };    
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringRemoveHeap(&empty, &empty);
    String expected5 = { 0, "" };    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringRemoveHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringRemoveAllHeap()
{
    printf("- testing createStringRemoveAllHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = { 39, "∆∆∆ Life ∆is ∆ rock ∆∆∆" };   
    String source2 = {  3, "∆" };    
    String source3 = {  6, "∆∆" };
   
    String result1 = createStringRemoveAllHeap(&source1, &source2);
    String expected1 = { 15, " Life is  rock " };   
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringRemoveAllHeap(&source1, &source3);
    String expected2 = { 27, "∆ Life ∆is ∆ rock ∆" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringRemoveAllHeap(&source1, &empty);
    String expected3 = { 39, "∆∆∆ Life ∆is ∆ rock ∆∆∆" };    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringRemoveAllHeap(&empty, &source1);
    String expected4 = { 0, "" };    
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    if (fails) { 
        printf("createStringRemoveAllHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringReplaceStartHeap()
{
    printf("- testing createStringReplaceStartHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = { 16, "Life is ∆ rock" };   
    String source2 = {  4, "∆ " };  
   
    String result1 = createStringReplaceStartHeap(&source1, 0, &source2);
    String expected1 = { 16, "Life is ∆ rock" };
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringReplaceStartHeap(&source1, 16, &source2);
    String expected2 = { 4, "∆ " };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringReplaceStartHeap(&source1, 5, &source2);
    String expected3 = { 15, "∆ is ∆ rock" };    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringReplaceStartHeap(&source1, 8, &empty);
    String expected4 = { 8, "∆ rock" };
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringReplaceStartHeap(&empty, 1, &empty);
    String expected5 = { 0, "" };    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringReplaceStartHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringReplaceEndHeap()
{
    printf("- testing createStringReplaceEndHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = { 16, "Life is ∆ rock" };   
    String source2 = {  4, " ∆" };  
   
    String result1 = createStringReplaceEndHeap(&source1, 0, &source2);
    String expected1 = { 16, "Life is ∆ rock" };
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringReplaceEndHeap(&source1, 16, &source2);
    String expected2 = { 4, " ∆" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringReplaceEndHeap(&source1, 5, &source2);
    String expected3 = { 15, "Life is ∆ ∆" };    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringReplaceEndHeap(&source1, 5, &empty);
    String expected4 = { 11, "Life is ∆" };
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringReplaceEndHeap(&empty, 1, &empty);
    String expected5 = { 0, "" };    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringReplaceEndHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringReplaceHeap()
{
    printf("- testing createStringReplaceHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = { 16, "Life is ∆ rock" };   
    String source2 = {  3, "∆" };  
    String source3 = {  6, "Xx--xX" };  
   
    String result1 = createStringReplaceHeap(&source1, &source2, &source3);
    String expected1 = { 19, "Life is Xx--xX rock" };
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringReplaceHeap(&source1, &source3, &source2);
    String expected2 = { 16, "Life is ∆ rock" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringReplaceHeap(&source1, &source2, &empty);
    String expected3 = { 13, "Life is  rock" };    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringReplaceHeap(&source1, &empty, &source2);
    String expected4 = { 16, "Life is ∆ rock" };
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringReplaceHeap(&source1, &empty, &empty);
    String expected5 = { 16, "Life is ∆ rock" };    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    String result6 = createStringReplaceHeap(&empty, &empty, &source1);
    String expected6 = {  0, "" };    
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }
    
    if (fails) { 
        printf("createStringReplaceHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringReplaceAllHeap()
{
    printf("- testing createStringReplaceAllHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = { 39, "∆∆∆ Life ∆is ∆ rock ∆∆∆" };   
    String source2 = {  3, "∆" };    
    String source3 = {  6, "∆∆" };  
    String source4 = {  3, "Y.Y" };
   
    String result1 = createStringReplaceAllHeap(&source1, &source2, &source3);
    String expected1 = { 63, "∆∆∆∆∆∆ Life ∆∆is ∆∆ rock ∆∆∆∆∆∆" };  
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringReplaceAllHeap(&source1, &source2, &source4);
    String expected2 = { 39, "Y.YY.YY.Y Life Y.Yis Y.Y rock Y.YY.YY.Y" };  
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringReplaceAllHeap(&source1, &source3, &source2);
    String expected3 = { 33, "∆∆ Life ∆is ∆ rock ∆∆" };    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }

    String result4 = createStringReplaceAllHeap(&empty, &source1, &source2);
    String expected4 = { 0, "" };    
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringReplaceAllHeap(&source1, &source2, &empty);
    String expected5 = { 15, " Life is  rock " };    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createStringReplaceAllHeap FAILS!\n");
        exit(1);
    }
}

