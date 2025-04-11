// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testCreateStringFromCharCode() 
{    
    printf("- testing createStringFromCharCode\n");
    
    bool fails = false;
    
    String result1 = createStringFromCharCode(64);
    String expected1 = createStringFromLiteral("@");
    if (! stringsAreEqual(&expected1, &result1)) { fails = true; }
    
    String result2 = createStringFromCharCode(364);
    String expected2 = createStringEmpty();
    if (! stringsAreEqual(&expected2, &result2)) { fails = true ; }
    
    String result3 = createStringFromCharCode(-1);
    String expected3 = createStringEmpty();
    if (! stringsAreEqual(&expected3, &result3)) { fails = true ; }
    
    if (fails) {
        printf("createStringFromCharCode FAILS!\n");
        exit(1);
    }
}

void testCreateStringClone()
{
    printf("- testing createStringClone\n");
    
    bool fails = false;

    String source1 = createStringFromLiteral("Life is ∆ rock");
    String result1 = createStringClone(&source1);
    String expected1 = createStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(&expected1, &result1)) { fails = true; }
    
    String source2 = createStringEmpty(); 
    String result2 = createStringClone(&source2);
    String expected2 = createStringEmpty();
    if (! stringsAreEqual(&expected2, &result2)) { fails = true; }
    
    if (fails) {
        printf("createStringClone FAILS!\n");
        exit(1);
    }
}

void testCreateStringRepeat()
{  
    printf("- testing createStringRepeat\n");
      
    bool fails = false;
    String source = createStringFromLiteral("∆rock∆");
    
    String result1 = createStringRepeat(&source, 3);
    String expected1 = createStringFromLiteral("∆rock∆∆rock∆∆rock∆");
    if (! stringsAreEqual(&expected1, &result1)) { fails = true; }

    String result2 = createStringRepeat(&source, -33);
    String expected2 = createStringEmpty();
    if (! stringsAreEqual(&expected2, &result2)) { fails = true; }

    String source3 = createStringEmpty();
    String result3 = createStringRepeat(&source3, 3);
    String expected3 = createStringEmpty();
    if (! stringsAreEqual(&expected3, &result3)) { fails = true; }
    
    if (fails) {
        printf("createStringRepeat FAILS!\n");
        exit(1);
    }
}

