
void testCreateStringStart()
{
    printf("- testing createStringStart\n");
    
    bool fails = false;

    String empty = createEmptyString();    
    String source = { 16, "Life is ∆ rock" };
   
    String result1 = createStringStart(&empty, 3);
    String expected1 = createEmptyString();    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }

    String result2 = createStringStart(&empty, -3);
    String expected2 = createEmptyString();    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }

    String result3 = createStringStart(&source, 0);
    String expected3 = createEmptyString();   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringStart(&source, -5);
    String expected4 = createEmptyString();   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringStart(&source, 4);
    String expected5 = { 4, "Life" };    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }

    String result6 = createStringStart(&source, 400);
    String expected6 = { 16, "Life is ∆ rock" };    
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }

    if (fails) { 
        printf("createStringStart FAILS!\n");
        exit(1);
    }
}

void testCreateStringEnd()
{
    printf("- testing createStringEnd\n");
    
    bool fails = false;

    String empty = createEmptyString();    
    String source = { 16, "Life is ∆ rock" };
   
    String result1 = createStringEnd(&empty, 3);
    String expected1 = createEmptyString();    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }

    String result2 = createStringEnd(&empty, -3);
    String expected2 = createEmptyString();    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }

    String result3 = createStringEnd(&source, 0);
    String expected3 = createEmptyString();   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringEnd(&source, -5);
    String expected4 = createEmptyString();   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringEnd(&source, 4);
    String expected5 = { 4, "rock" };    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }

    String result6 = createStringEnd(&source, 400);
    String expected6 = { 16, "Life is ∆ rock" };    
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }

    if (fails) { 
        printf("createStringEnd FAILS!\n");
        exit(1);
    }
}

void testCreateSubstring()
{
    printf("- testing createSubstring\n");
        
    bool fails = false;

    String empty = createEmptyString();    
    String source = { 16, "Life is ∆ rock" };
   
    String result1 = createSubstring(&empty, 3, 12);
    String expected1 = createEmptyString();    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createSubstring(&source, 3, 12);
    String expected2 = { 12, "fe is ∆ ro" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createSubstring(&source, 16, 1);
    String expected3 = { 1, "k" };   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
        
    String result4 = createSubstring(&source, 4, -5);
    String expected4 = createEmptyString();
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createSubstring(&source, -44, 555);
    String expected5 = { 16, "Life is ∆ rock" };
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }

    String result6 = createSubstring(&source, -3, 8);    
    String expected6 = { 4, "Life" };
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }
    
    String result7 = createSubstring(&source, 13, 8000);
    String expected7 = { 4, "rock" };
    if (! stringsAreEqual(&result7, &expected7)) { fails = true; }
    
    if (fails) { 
        printf("createSubstring FAILS!\n");
        exit(1);
    }
}

