// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testCreateStringAppend()
{
    printf("- testing createStringAppend\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life is ∆");   
    String source2 = makeStringFromLiteral(" rock");
   
    String result1 = createStringAppend(&source1, &source2);
    String expected1 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }

    String result2 = createStringAppend(&source1, &empty);
    String expected2 = source1;    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }

    String result3 = createStringAppend(&empty, &source1);
    String expected3 = source1;   
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringAppend(&empty, &empty);
    String expected4 = makeStringEmpty();   
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    if (fails) { 
        printf("createStringAppend FAILS!\n");
        exit(1);
    }
    
    releaseString(&result1);
    releaseString(&result2);
    releaseString(&result3);
    releaseString(&result4);
    releaseString(&expected4);
}

void testCreateStringInsert()
{
    printf("- testing createStringInsert\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life is ∆");   
    String source2 = makeStringFromLiteral(" rock");
   
    String result1 = createStringInsert(&source1, &source2, 1000);
    String expected1 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(&result1, &expected1)) { fails = true; }
   
    String result2 = createStringInsert(&source1, &source2, 1);
    String expected2 = makeStringFromLiteral(" rockLife is ∆");    
    if (! stringsAreEqual(&result2, &expected2)) { fails = true; }
   
    String result3 = createStringInsert(&source1, &source2, -1000);
    String expected3 = makeStringFromLiteral(" rockLife is ∆");    
    if (! stringsAreEqual(&result3, &expected3)) { fails = true; }
    
    String result4 = createStringInsert(&source1, &source2, 8);    
    String expected4 = makeStringFromLiteral("Life is rock ∆");    
    if (! stringsAreEqual(&result4, &expected4)) { fails = true; }
    
    String result5 = createStringInsert(&source1, &empty, 1);    
    String expected5 = source1;       
    if (! stringsAreEqual(&result5, &expected5)) { fails = true; }
    
    String result6 = createStringInsert(&source1, &empty, 1);    
    String expected6 = source1;       
    if (! stringsAreEqual(&result6, &expected6)) { fails = true; }
    
    String result7 = createStringInsert(&empty, &empty, 1);    
    String expected7 = makeStringEmpty();       
    if (! stringsAreEqual(&result7, &expected7)) { fails = true; }
    
    if (fails) { 
        printf("createStringInsert FAILS!\n");
        exit(1);
    }
    
    releaseString(&result1);
    releaseString(&result2);
    releaseString(&result3);
    releaseString(&result4);
    releaseString(&result5);
    releaseString(&result6);
    releaseString(&result7);
    releaseString(&expected7);
}

