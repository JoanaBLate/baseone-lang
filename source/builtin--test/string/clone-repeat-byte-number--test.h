// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testCreateStringFromByte() 
{    
    printf("- testing createStringFromByte\n");
    
    bool fails = false;
    
    String result1 = createStringFromByte(64);
    String expected1 = makeStringFromLiteral("@");
    if (! stringsAreEqual(&expected1, &result1)) { fails = true; }
  
//    makes the program exit    
//    String result2 = createStringFromByte(364);
//    String expected2 = makeStringEmpty();
//    if (! stringsAreEqual(&expected2, &result2)) { fails = true ; }
    
//    makes the program exit 
//    String result3 = createStringFromByte(-1);
//    String expected3 = makeStringEmpty();
//    if (! stringsAreEqual(&expected3, &result3)) { fails = true ; }
    
    if (fails) {
        printf("createStringFromByte FAILS!\n");
        exit(1);
    }

    releaseString(&result1);
}

void testCreateStringClone()
{
    printf("- testing createStringClone\n");
    
    bool fails = false;

    String source1 = makeStringFromLiteral("Life is ∆ rock");
    String result1 = createStringClone(&source1);
    String expected1 = makeStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(&expected1, &result1)) { fails = true; }
    
    String source2 = makeStringEmpty(); 
    String result2 = createStringClone(&source2);
    String expected2 = makeStringEmpty();
    if (! stringsAreEqual(&expected2, &result2)) { fails = true; }
    
    if (fails) {
        printf("createStringClone FAILS!\n");
        exit(1);
    }
    
    releaseString(&result1);
    releaseString(&source2);
    releaseString(&result2);
    releaseString(&expected2);
}

void testCreateStringRepeat()
{  
    printf("- testing createStringRepeat\n");
      
    bool fails = false;
    String source = makeStringFromLiteral("∆rock∆");
    
    String result1 = createStringRepeat(source, 3);
    String expected1 = makeStringFromLiteral("∆rock∆∆rock∆∆rock∆");
    if (! stringsAreEqual(&expected1, &result1)) { fails = true; }

    String result2 = createStringRepeat(source, -33);
    String expected2 = makeStringEmpty();
    if (! stringsAreEqual(&expected2, &result2)) { fails = true; }

    String source3 = makeStringEmpty();
    String result3 = createStringRepeat(source3, 3);
    String expected3 = makeStringEmpty();
    if (! stringsAreEqual(&expected3, &result3)) { fails = true; }
    
    if (fails) {
        printf("createStringRepeat FAILS!\n");
        exit(1);
    }
    
    releaseString(&result1);
    releaseString(&result2);
    releaseString(&expected2);
    releaseString(&result3);
    releaseString(&expected3);
}

void testCreateStringFromLong()
{  
    printf("- testing createStringFromLong\n");
      
    bool fails = false;
    
    String result1 = createStringFromLong(999888777666555);
    String expected1 = makeStringFromLiteral("999888777666555");
    if (! stringsAreEqual(&expected1, &result1)) { fails = true; }

    String result2 = createStringFromLong(0);
    String expected2 = makeStringFromLiteral("0");
    if (! stringsAreEqual(&expected2, &result2)) { fails = true; }
    
    String result3 = createStringFromLong(-500.79);
    String expected3 = makeStringFromLiteral("-500");
    if (! stringsAreEqual(&expected3, &result3)) { fails = true; }
    
    if (fails) {
        printf("createStringFromLong FAILS!\n");
        exit(1);
    }
    
    releaseString(&result1);
    releaseString(&result2);
    releaseString(&result3);
}

