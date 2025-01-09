
void testCreateAppendedString()
{
    printf("- testing createAppendedString\n");
    
    bool fails = false;

    String empty = createEmptyString();    
    String source1 = { 11, "Life is ∆" };   
    String source2 = {  5, " rock" };
   
    String result1 = createAppendedString(&source1, &source2);
    String expected1 = { 16, "Life is ∆ rock" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }

    String result2 = createAppendedString(&source1, &empty);
    String expected2 = source1;    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }

    String result3 = createAppendedString(&empty, &source1);
    String expected3 = source1;   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createAppendedString(&empty, &empty);
    String expected4 = createEmptyString();   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    if (fails) { 
        printf("createAppendedString FAILS!\n");
        exit(1);
    }
}

void testCreateInsertedString()
{
    printf("- testing createInsertedString\n");
    
    bool fails = false;

    String empty = createEmptyString();    
    String source1 = { 11, "Life is ∆" };   
    String source2 = {  5, " rock" };
   
    String result1 = createInsertedString(&source1, &source2, 1000);
    String expected1 = { 16, "Life is ∆ rock" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createInsertedString(&source1, &source2, 1);
    String expected2 = { 16, " rockLife is ∆" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
   
    String result3 = createInsertedString(&source1, &source2, -1000);
    String expected3 = { 16, " rockLife is ∆" };    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createInsertedString(&source1, &source2, 8);    
    String expected4 = { 16, "Life is rock ∆" };    
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createInsertedString(&source1, &empty, 1);    
    String expected5 = source1;       
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    String result6 = createInsertedString(&source1, &empty, 1);    
    String expected6 = source1;       
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }
    
    String result7 = createInsertedString(&empty, &empty, 1);    
    String expected7 = createEmptyString();       
    if (! stringsAreEqual(&result7, &expected7)) { fails = true; }
    
    if (fails) { 
        printf("createInsertedString FAILS!\n");
        exit(1);
    }
}

void testCreatePaddedStartString()
{
    printf("- testing createPaddedStartString\n");
    
    bool fails = false;

    String empty = createEmptyString();    
    String source1 = { 16, "Life is ∆ rock" };   
    String source2 = {  6, "(^-^) " };
   
    String result1 = createPaddedStartString(&source1, &source2, 3);
    String expected1 = { 34, "(^-^) (^-^) (^-^) Life is ∆ rock" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createPaddedStartString(&source1, &empty, 3);
    String expected2 = { 16, "Life is ∆ rock" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createPaddedStartString(&empty, &source2, 3);
    String expected3 = { 18, "(^-^) (^-^) (^-^) " };   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createPaddedStartString(&source1, &source2, -1);
    String expected4 = { 16, "Life is ∆ rock" };   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createPaddedStartString(&empty, &empty, 3);
    String expected5 = createEmptyString();    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createPaddedStartString FAILS!\n");
        exit(1);
    }
}   

void testCreatePaddedEndString()
{
    printf("- testing createPaddedEndString\n");
    
    bool fails = false;

    String empty = createEmptyString();    
    String source1 = { 16, "Life is ∆ rock" };   
    String source2 = {  6, " (^-^)" };
   
    String result1 = createPaddedEndString(&source1, &source2, 3);
    String expected1 = { 34, "Life is ∆ rock (^-^) (^-^) (^-^)" };    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
    
    String result2 = createPaddedEndString(&source1, &empty, 3);
    String expected2 = { 16, "Life is ∆ rock" };    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
    
    String result3 = createPaddedEndString(&empty, &source2, 3);
    String expected3 = { 18, " (^-^) (^-^) (^-^)" };   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }  
    
    String result4 = createPaddedEndString(&source1, &source2, -1);
    String expected4 = { 16, "Life is ∆ rock" };   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createPaddedEndString(&empty, &empty, 3);
    String expected5 = createEmptyString();    
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    if (fails) { 
        printf("createPaddedEndString FAILS!\n");
        exit(1);
    }
}   

