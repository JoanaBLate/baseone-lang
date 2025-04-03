// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testCreateStringStartHeap()
{
    printf("- testing createStringStartHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source = { 16, "Life is ∆ rock" };
   
    String result1 = createStringStartHeap(&empty, 3);
    String expected1 = createStringEmpty();    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }

    String result2 = createStringStartHeap(&empty, -3);
    String expected2 = createStringEmpty();    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }

    String result3 = createStringStartHeap(&source, 0);
    String expected3 = createStringEmpty();   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringStartHeap(&source, -5);
    String expected4 = createStringEmpty();   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringStartHeap(&source, 4);
    String expected5 = { 4, "Life" };    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }

    String result6 = createStringStartHeap(&source, 400);
    String expected6 = { 16, "Life is ∆ rock" };    
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }

    if (fails) { 
        printf("createStringStartHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringEndHeap()
{
    printf("- testing createStringEndHeap\n");
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source = { 16, "Life is ∆ rock" };
   
    String result1 = createStringEndHeap(&empty, 3);
    String expected1 = createStringEmpty();    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }

    String result2 = createStringEndHeap(&empty, -3);
    String expected2 = createStringEmpty();    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }

    String result3 = createStringEndHeap(&source, 0);
    String expected3 = createStringEmpty();   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringEndHeap(&source, -5);
    String expected4 = createStringEmpty();   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringEndHeap(&source, 4);
    String expected5 = { 4, "rock" };    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }

    String result6 = createStringEndHeap(&source, 400);
    String expected6 = { 16, "Life is ∆ rock" };    
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }

    if (fails) { 
        printf("createStringEndHeap FAILS!\n");
        exit(1);
    }
}

void testCreateStringSubHeap()
{
    printf("- testing createStringSubHeap\n");
        
    bool fails = false;

    String empty = createStringEmpty();    
    String source = { 16, "Life is ∆ rock" };
   
    String result1 = createStringSubHeap(&empty, 3, 12);
    String expected1 = createStringEmpty();    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createStringSubHeap(&source, 3, 12);
    String expected2 = { 12, "fe is ∆ ro" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createStringSubHeap(&source, 16, 1);
    String expected3 = { 1, "k" };   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
        
    String result4 = createStringSubHeap(&source, 4, -5);
    String expected4 = createStringEmpty();
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringSubHeap(&source, -44, 555);
    String expected5 = { 16, "Life is ∆ rock" };
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }

    String result6 = createStringSubHeap(&source, -3, 8);    
    String expected6 = { 4, "Life" };
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }
    
    String result7 = createStringSubHeap(&source, 13, 8000);
    String expected7 = { 4, "rock" };
    if (! stringsAreEqual(&result7, &expected7)) { fails = true; }
    
    if (fails) { 
        printf("createStringSubHeap FAILS!\n");
        exit(1);
    }
}

