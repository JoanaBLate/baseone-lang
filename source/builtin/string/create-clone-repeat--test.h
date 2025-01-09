
void testCreateEmptyString() 
{    
    printf("- testing createEmptyString\n");
    
    String result = createEmptyString();
    String expected = { 0, "" };
    
    if (! stringsAreEqual(&expected, &result)) {
        printf("createEmptyString FAILS!\n");
        exit(1);
    }
}

void testCreateStringFromCharCode() 
{    
    printf("- testing createStringFromCharCode\n");
    
    bool fails = false;
    
    String result1 = createStringFromCharCode(64);
    String expected1 = { 1, "@" };
    if (! stringsAreEqual(&expected1, &result1)) { fails = true; }
    
    String result2 = createStringFromCharCode(364);
    String expected2 = createEmptyString();
    if (! stringsAreEqual(&expected2, &result2)) { fails = true ; }
    
    String result3 = createStringFromCharCode(-1);
    String expected3 = createEmptyString();
    if (! stringsAreEqual(&expected3, &result3)) { fails = true ; }
    
    if (fails) {
        printf("createStringFromCharCode FAILS!\n");
        exit(1);
    }
}

void testCreateStringFromLiteral()
{    
    printf("- testing createStringFromLiteral\n");
    
    bool fails = false;
    
    String result1 = createStringFromLiteral("Life is ∆ rock");
    String expected1 = { 16, "Life is ∆ rock" };    
    if (!stringsAreEqual(&expected1, &result1)) { fails = true; }    
    
    String result2 = createStringFromLiteral("");
    String expected2 = createEmptyString();  
    if (!stringsAreEqual(&expected2, &result2)) { fails = true; }
    
    if (fails) { 
        printf("createStringFromLiteral FAILS!\n");
        exit(1);
    }
}

void testCreateStringClone()
{
    printf("- testing createStringClone\n");
    
    bool fails = false;
    
    String source1 = { 16, "Life is ∆ rock" };
    String result1 = createStringClone(&source1);
    String expected1 = { 16, "Life is ∆ rock" };
    if (! stringsAreEqual(&expected1, &result1)) { fails = true; }
    
    String source2 = createEmptyString(); 
    String result2 = createStringClone(&source2);
    String expected2 = createEmptyString();
    if (! stringsAreEqual(&expected2, &result2)) { fails = true; }
    
    if (fails) {
        printf("createStringClone FAILS!\n");
        exit(1);
    }
}

void testCreateRepeatedString()
{  
    printf("- testing createRepeatedString\n");
      
    bool fails = false;
    String source = { 10, "∆rock∆" };
    
    String result1 = createRepeatedString(&source, 3);
    String expected1 = { 30, "∆rock∆∆rock∆∆rock∆" };
    if (! stringsAreEqual(&expected1, &result1)) { fails = true; }

    String result2 = createRepeatedString(&source, -33);
    String expected2 = createEmptyString();
    if (! stringsAreEqual(&expected2, &result2)) { fails = true; }

    String source3 = createEmptyString();
    String result3 = createRepeatedString(&source3, 3);
    String expected3 = createEmptyString();
    if (! stringsAreEqual(&expected3, &result3)) { fails = true; }
    
    if (fails) {
        printf("createRepeatedString FAILS!\n");
        exit(1);
    }
}

