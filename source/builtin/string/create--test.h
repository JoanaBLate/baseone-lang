
void testCreateEmptyString() 
{    
    struct String result = createEmptyString();
    struct String expected = { 0, "" };
    
    if (! stringsAreEqual(&expected, &result)) {
        printf("testCreateEmptyString FAILS!\n");
        exit(1);
    }
}

void testCreateStringFromCharCode() 
{    
    bool fails = false;
    
    struct String result1 = createStringFromCharCode(64);
    struct String expected1 = { 1, "@" };
    if (! stringsAreEqual(&expected1, &result1)) { fails = true; }
    
    struct String result2 = createStringFromCharCode(364);
    struct String expected2 = createEmptyString();
    if (! stringsAreEqual(&expected2, &result2)) { fails = true ; }
    
    struct String result3 = createStringFromCharCode(-1);
    struct String expected3 = createEmptyString();
    if (! stringsAreEqual(&expected3, &result3)) { fails = true ; }
    
    if (fails) {
        printf("testCreateStringFromCharCode FAILS!\n");
        exit(1);
    }
}

void testCreateStringFromLiteral()
{    
    bool fails = false;
    
    struct String result1 = createStringFromLiteral("Life is ∆ rock");
    struct String expected1 = { 16, "Life is ∆ rock" };    
    if (!stringsAreEqual(&expected1, &result1)) { fails = true; }    
    
    struct String result2 = createStringFromLiteral("");
    struct String expected2 = createEmptyString();  
    if (!stringsAreEqual(&expected2, &result2)) { fails = true; }
    
    if (fails) { 
        printf("testCreateStringFromLiteral FAILS!\n");
        exit(1);
    }
}

void testCreateStringClone()
{
    bool fails = false;
    
    struct String source1 = { 16, "Life is ∆ rock" };
    struct String result1 = createStringClone(&source1);
    struct String expected1 = { 16, "Life is ∆ rock" };
    if (! stringsAreEqual(&expected1, &result1)) { fails = true; }
    
    struct String source2 = createEmptyString(); 
    struct String result2 = createStringClone(&source2);
    struct String expected2 = createEmptyString();
    if (! stringsAreEqual(&expected2, &result2)) { fails = true; }
    
    if (fails) {
        printf("testCreateStringClone FAILS!\n");
        exit(1);
    }
}

void testCreateRepeatedString()
{    
    bool fails = false;
    struct String source = { 10, "∆rock∆" };
    
    struct String result1 = createRepeatedString(&source, 3);
    struct String expected1 = { 30, "∆rock∆∆rock∆∆rock∆" };
    if (! stringsAreEqual(&expected1, &result1)) { fails = true; }

    struct String result2 = createRepeatedString(&source, -33);
    struct String expected2 = createEmptyString();
    if (! stringsAreEqual(&expected2, &result2)) { fails = true; }

    struct String source3 = createEmptyString();
    struct String result3 = createRepeatedString(&source3, 3);
    struct String expected3 = createEmptyString();
    if (! stringsAreEqual(&expected3, &result3)) { fails = true; }
    
    if (fails) {
        printf("testCreateRepeatedString FAILS!\n");
        exit(1);
    }
}

void stringCreateTest()
{
    printf("TESTING string create\n");
    testCreateEmptyString();
    testCreateStringFromCharCode();
    testCreateStringFromLiteral();
    testCreateStringClone();
    testCreateRepeatedString();
}

