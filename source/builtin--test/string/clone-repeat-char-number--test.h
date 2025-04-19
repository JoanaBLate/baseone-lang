// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testNewStringFromCharCode() 
{    
    printf("- testing newStringFromCharCode\n");
    
    bool fails = false;
    
    String* result1 = newStringFromCharCode(64);
    String* expected1 = makeStringFromLiteral("@");
    if (! stringsAreEqual(expected1, result1)) { fails = true; }
    
    String* result2 = newStringFromCharCode(364);
    String* expected2 = makeStringEmpty();
    if (! stringsAreEqual(expected2, result2)) { fails = true ; }
    
    String* result3 = newStringFromCharCode(-1);
    String* expected3 = makeStringEmpty();
    if (! stringsAreEqual(expected3, result3)) { fails = true ; }
    
    if (fails) {
        printf("newStringFromCharCode FAILS!\n");
        exit(1);
    }
}

void testNewStringClone()
{
    printf("- testing newStringClone\n");
    
    bool fails = false;

    String* source1 = makeStringFromLiteral("Life is ∆ rock");
    String* result1 = newStringClone(source1);
    String* expected1 = makeStringFromLiteral("Life is ∆ rock");
    if (! stringsAreEqual(expected1, result1)) { fails = true; }
    
    String* source2 = makeStringEmpty(); 
    String* result2 = newStringClone(source2);
    String* expected2 = makeStringEmpty();
    if (! stringsAreEqual(expected2, result2)) { fails = true; }
    
    if (fails) {
        printf("newStringClone FAILS!\n");
        exit(1);
    }
}

void testNewStringRepeat()
{  
    printf("- testing newStringRepeat\n");
      
    bool fails = false;
    String* source = makeStringFromLiteral("∆rock∆");
    
    String* result1 = newStringRepeat(source, 3);
    String* expected1 = makeStringFromLiteral("∆rock∆∆rock∆∆rock∆");
    if (! stringsAreEqual(expected1, result1)) { fails = true; }

    String* result2 = newStringRepeat(source, -33);
    String* expected2 = makeStringEmpty();
    if (! stringsAreEqual(expected2, result2)) { fails = true; }

    String* source3 = makeStringEmpty();
    String* result3 = newStringRepeat(source3, 3);
    String* expected3 = makeStringEmpty();
    if (! stringsAreEqual(expected3, result3)) { fails = true; }
    
    if (fails) {
        printf("newStringRepeat FAILS!\n");
        exit(1);
    }
}

void testNewStringFromLong()
{  
    printf("- testing newStringFromLong\n");
      
    bool fails = false;
    
    String* result1 = newStringFromLong(999888777666555);
    String* expected1 = makeStringFromLiteral("999888777666555");
    if (! stringsAreEqual(expected1, result1)) { fails = true; }

    String* result2 = newStringFromLong(0);
    String* expected2 = makeStringFromLiteral("0");
    if (! stringsAreEqual(expected2, result2)) { fails = true; }
    
    String* result3 = newStringFromLong(-500.79);
    String* expected3 = makeStringFromLiteral("-500");
    if (! stringsAreEqual(expected3, result3)) { fails = true; }
    
    if (fails) {
        printf("newStringFromLong FAILS!\n");
        exit(1);
    }
}

