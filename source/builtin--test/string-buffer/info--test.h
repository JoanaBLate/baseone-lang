// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testStringBufferCharCodeAt() 
{
    printf("- testing stringBufferCharCodeAt\n"); 
    
    StringBuffer sb = makeStringBufferFromLiteral("123He@llo123");
    
    sb.margin = 3;
    sb.size -= 6;
    
    bool fails = false;
    if (stringBufferCharCodeAt(sb, 3) != 64)   { fails = true; }
    if (stringBufferCharCodeAt(sb, 9) != -1)   { fails = true; }
    if (stringBufferCharCodeAt(sb, -33) != -1) { fails = true; }
    
    if (fails) { 
        printf("stringBufferCharCodeAt FAILS!\n"); 
        exit(1);
    }
}

void testStringBuffersAreEquals()
{
    printf("- testing stringBuffersAreEqual\n"); 
    
    bool fails = false;

    StringBuffer sb1 = makeStringBufferFromLiteral("123Life is ∆ rock123");
    StringBuffer sb2 = makeStringBufferFromLiteral("Life is ∆ rock");
    StringBuffer sb3 = makeStringBufferFromLiteral("Life is ∆ ");
    
    sb1.margin = 3;
    sb1.size -= 6;

    if (! stringBuffersAreEqual(sb1, sb2)) { fails = true; }
    if (stringBuffersAreEqual(sb1, sb3))   { fails = true; }
    
    StringBuffer empty1 = makeStringBufferFromLiteral("");    
    StringBuffer empty2 = makeStringBufferFromLiteral("");
    
    if (! stringBuffersAreEqual(empty1, empty2)) { fails = true; }
    if (stringBuffersAreEqual(empty1, sb1))  { fails = true; }
    
    if (fails) { 
        printf("stringBuffersAreEqual FAILS!\n");
        exit(1);
    }
}

void testStringBufferContains()
{
    printf("- testing stringBufferContains\n"); 
    
    bool fails = false;

    StringBuffer sb0 = makeStringBufferFromLiteral("");    
    StringBuffer sb1 = makeStringBufferFromLiteral("123Life is ∆ rock123");

    sb1.margin = 3;
    sb1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock");
    String string2 = makeStringFromLiteral("Life is ∆ rock1");
    String string3 = makeStringFromLiteral("ck ∆");
    
    if (! stringBufferContains(sb1, string1)) { fails = true; }
    if (stringBufferContains(sb1, string2))   { fails = true; }
    if (stringBufferContains(sb1, string0))   { fails = true; }
    if (stringBufferContains(sb1, string3))   { fails = true; }
    if (stringBufferContains(sb0, string1))   { fails = true; }

    if (fails) { 
        printf("stringBufferContains FAILS!\n"); 
        exit(1);
    }
}

void testStringBufferStartsWith()
{
    printf("- testing stringBufferStartsWith\n"); 
    
    bool fails = false;
    
    StringBuffer sb0 = makeStringBufferFromLiteral("");    
    StringBuffer sb1 = makeStringBufferFromLiteral("123Life is ∆ rock123");

    sb1.margin = 3;
    sb1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock");
    String string2 = makeStringFromLiteral("Life is ∆");
    String string3 = makeStringFromLiteral("Life rocks");
    
    if (stringBufferStartsWith(sb1, string0)) { fails = true; }
    if (stringBufferStartsWith(sb0, string1)) { fails = true; }
    if (stringBufferStartsWith(sb0, string0)) { fails = true; }
    if (stringBufferStartsWith(sb1, string3)) { fails = true; }
    if (! stringBufferStartsWith(sb1, string1)) { fails = true; }
    if (! stringBufferStartsWith(sb1, string2)) { fails = true; }

    if (fails) { 
        printf("stringBufferStartsWith FAILS!\n");
        exit(1);
    }
}

void testStringBufferEndsWith()
{
    printf("- testing stringBufferEndsWith\n"); 
    
    bool fails = false;
    
    StringBuffer sb0 = makeStringBufferFromLiteral("");    
    StringBuffer sb1 = makeStringBufferFromLiteral("123Life is ∆ rock123");

    sb1.margin = 3;
    sb1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock");
    String string2 = makeStringFromLiteral("ck ∆");
    String string3 = makeStringFromLiteral("∆ rock");
    
    if (stringBufferEndsWith(sb1, string0))   { fails = true; }
    if (stringBufferEndsWith(sb0, string1))   { fails = true; }
    if (stringBufferEndsWith(sb0, string0))   { fails = true; }
    if (stringBufferEndsWith(sb1, string2))   { fails = true; }
    if (! stringBufferEndsWith(sb1, string1)) { fails = true; }
    if (! stringBufferEndsWith(sb1, string3)) { fails = true; }

    if (fails) { 
        printf("stringBufferEndsWith FAILS!\n");
        exit(1);
    }
}

void testStringBufferIndexOf()
{
    printf("- testing stringBufferIndexOf\n"); 
    
    bool fails = false;
    
    StringBuffer sb0 = makeStringBufferFromLiteral("");    
    StringBuffer sb1 = makeStringBufferFromLiteral("123Life is ∆ rock and ∆ like rock123");

    sb1.margin = 3;
    sb1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock and ∆ like rock");
    String string2 = makeStringFromLiteral("∆ like");
    String string3 = makeStringFromLiteral("and#");

    if (stringBufferIndexOf(sb1, string1) !=  1) { fails = true; }
    if (stringBufferIndexOf(sb1, string2) != 22) { fails = true; }
    if (stringBufferIndexOf(sb1, string3) !=  0) { fails = true; }
    if (stringBufferIndexOf(sb1, string0) !=  0) { fails = true; }
    if (stringBufferIndexOf(sb0, string1) !=  0) { fails = true; }
    if (stringBufferIndexOf(sb0, string0) !=  0) { fails = true; }
    
    if (fails) {
        printf("stringBufferIndexOf FAILS!\n");
        exit(1);
    }
}

void testStringBufferLastIndexOf()
{
    printf("- testing stringBufferLastIndexOf\n"); 
    
    bool fails = false;
    
    StringBuffer sb0 = makeStringBufferFromLiteral("");    
    StringBuffer sb1 = makeStringBufferFromLiteral("123Life is ∆ rock and ∆ like rock123");

    sb1.margin = 3;
    sb1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock and ∆ like rock");
    String string2 = makeStringFromLiteral("∆");
    String string3 = makeStringFromLiteral("∆#");

    if (stringBufferLastIndexOf(sb1, string1) !=  1) { fails = true; }
    if (stringBufferLastIndexOf(sb1, string2) != 22) { fails = true; }
    if (stringBufferLastIndexOf(sb1, string3) !=  0) { fails = true; }
    if (stringBufferLastIndexOf(sb1, string0) !=  0) { fails = true; }
    if (stringBufferLastIndexOf(sb0, string1) !=  0) { fails = true; }
    if (stringBufferLastIndexOf(sb0, string0) !=  0) { fails = true; }    
    
    if (fails) {
        printf("stringBufferLastIndexOf FAILS!\n");
        exit(1);
    }
}

void testStringBufferIndexOfAfter()
{
    printf("- testing stringBufferIndexOfAfter\n"); 
    
    bool fails = false;
    
    StringBuffer sb0 = makeStringBufferFromLiteral("");    
    StringBuffer sb1 = makeStringBufferFromLiteral("123Life is ∆ rock and ∆ like rock123");

    sb1.margin = 3;
    sb1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock and ∆ like rock");
    String string2 = makeStringFromLiteral("∆");
    String string3 = makeStringFromLiteral("∆#");
    
    if (stringBufferIndexOfAfter(sb1, string1,  0) !=  1) { fails = true; }
    if (stringBufferIndexOfAfter(sb1, string1, -9) !=  1) { fails = true; }
    if (stringBufferIndexOfAfter(sb1, string2,  9) != 22) { fails = true; }
    if (stringBufferIndexOfAfter(sb1, string2, 99) !=  0) { fails = true; }
    if (stringBufferIndexOfAfter(sb1, string2,  0) !=  9) { fails = true; }
    if (stringBufferIndexOfAfter(sb1, string3,  0) !=  0) { fails = true; }
    if (stringBufferIndexOfAfter(sb1, string0, 0) != 0) { fails = true; }  
    if (stringBufferIndexOfAfter(sb0, string1, 0) != 0) { fails = true; }  
    if (stringBufferIndexOfAfter(sb0, string0,   0) != 0) { fails = true; }  
         
    if (fails) {
        printf("stringBufferIndexOfAfter FAILS!\n");
        exit(1);
    }
}

void testStringBufferLastIndexOfBefore()
{
    printf("- testing stringBufferLastIndexOfBefore\n"); 
    
    bool fails = false;
    
    StringBuffer sb0 = makeStringBufferFromLiteral("");    
    StringBuffer sb1 = makeStringBufferFromLiteral("123Life is ∆ rock and ∆ like rock123");

    sb1.margin = 3;
    sb1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock and ∆ like rock");
    String string2 = makeStringFromLiteral("∆");
    String string3 = makeStringFromLiteral("∆#");
    
    if (stringBufferLastIndexOfBefore(sb1, string1, -1) !=  0) { fails = true; }
    if (stringBufferLastIndexOfBefore(sb1, string1,  3) !=  0) { fails = true; }
    if (stringBufferLastIndexOfBefore(sb1, string2, 22) !=  9) { fails = true; }
    if (stringBufferLastIndexOfBefore(sb1, string3, 99) !=  0) { fails = true; }
    if (stringBufferLastIndexOfBefore(sb1, string1, 99) !=  1) { fails = true; }
    if (stringBufferLastIndexOfBefore(sb1, string0, 10) !=  0) { fails = true; } 
    if (stringBufferLastIndexOfBefore(sb0, string1, 10) !=  0) { fails = true; } 
    if (stringBufferLastIndexOfBefore(sb0, string0, 10) !=  0) { fails = true; }  
         
    if (fails) {
        printf("stringBufferLastIndexOfBefore FAILS!\n"); 
        exit(1);
    }
}

void testStringBufferCountOf()
{
    printf("- testing stringBufferCountOf\n"); 
    
    bool fails = false;

    StringBuffer sb0 = makeStringBufferFromLiteral("");    
    StringBuffer sb1 = makeStringBufferFromLiteral("123Life is ∆ rock and ∆ like rock123");
    StringBuffer sb2 = makeStringBufferFromLiteral("∆∆∆");
    StringBuffer sb3 = makeStringBufferFromLiteral("∆.∆.∆");

    sb1.margin = 3;
    sb1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock and ∆ like rock");
    String string2 = makeStringFromLiteral("∆");
    String string3 = makeStringFromLiteral("∆#");
    
    if (stringBufferCountOf(sb1, string2) != 2) { fails = true; }
    if (stringBufferCountOf(sb1, string3) != 0) { fails = true; }
    if (stringBufferCountOf(sb2, string2) != 3) { fails = true; }
    if (stringBufferCountOf(sb3, string3) != 0) { fails = true; }
    if (stringBufferCountOf(sb1, string0) != 0) { fails = true; }
    if (stringBufferCountOf(sb0, string1) != 0) { fails = true; }
    if (stringBufferCountOf(sb0, string0) != 0) { fails = true; }
         
    if (fails) {
        printf("stringBufferCountOf FAILS!\n"); 
        exit(1);
    }
}

