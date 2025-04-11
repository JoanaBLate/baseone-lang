// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testStringCharCodeAt() 
{
    printf("- testing stringCharCodeAt\n"); 
    
    String source = createStringFromLiteral("He@llo");
    bool fails = false;
    if (stringCharCodeAt(&source, 3) != 64)   { fails = true; }
    if (stringCharCodeAt(&source, 333) != -1) { fails = true; }
    if (stringCharCodeAt(&source, -33) != -1) { fails = true; }
    
    if (fails) { 
        printf("stringCharCodeAt FAILS!\n"); 
        exit(1);
    }
}

void testStringsAreEquals()
{
    printf("- testing stringsAreEqual\n"); 
    
    bool fails = false;

    String source1 = createStringFromLiteral("Life is ∆ rock");
    String source2 = createStringFromLiteral("Life is ∆ rock");
    String source3 = createStringFromLiteral("Life is ∆ ");

    if (! stringsAreEqual(&source1, &source2)) { fails = true; }
    if (stringsAreEqual(&source1, &source3))   { fails = true; }
    
    String empty1 = createStringEmpty();    
    String empty2 = createStringEmpty();
    
    if (! stringsAreEqual(&empty1, &empty2)) { fails = true; }
    if (stringsAreEqual(&empty1, &source1))  { fails = true; }
    
    if (fails) { 
        printf("stringsAreEqual FAILS!\n");
        exit(1);
    }
}

void testStringContains()
{
    printf("- testing stringContains\n"); 
    
    bool fails = false;

    String empty = createStringEmpty();    
    String source1 = createStringFromLiteral("Life is ∆ rock");
    String source2 = createStringFromLiteral(" ∆ ro");
    String source3 = createStringFromLiteral("ck ∆");
    
    if (! stringContains(&source1, &source1)) { fails = true; }
    if (! stringContains(&source1, &source2)) { fails = true; }
    if (stringContains(&source1, &source3)) { fails = true; }
    if (stringContains(&source1, &empty))   { fails = true; }
    if (stringContains(&empty, &source1))   { fails = true; }

    if (fails) { 
        printf("stringContains FAILS!\n"); 
        exit(1);
    }
}

void testStringStartsWith()
{
    printf("- testing stringStartsWith\n"); 
    
    bool fails = false;

    String empty = createStringEmpty();  
    String source1 = createStringFromLiteral("Life is ∆ rock");  
    String source2 = createStringFromLiteral("Life is ∆");
    String source3 = createStringFromLiteral("Life rocks");
    
    if (stringStartsWith(&source1, &empty))   { fails = true; }
    if (stringStartsWith(&empty, &source1))   { fails = true; }
    if (stringStartsWith(&empty, &empty))     { fails = true; }
    if (stringStartsWith(&source1, &source3)) { fails = true; }
    if (! stringStartsWith(&source1, &source1)) { fails = true; }
    if (! stringStartsWith(&source1, &source2)) { fails = true; }

    if (fails) { 
        printf("stringStartsWith FAILS!\n");
        exit(1);
    }
}

void testStringEndsWith()
{
    printf("- testing stringEndsWith\n"); 
    
    bool fails = false;

    String empty = createStringEmpty();  
    String source1 = createStringFromLiteral("Life is ∆ rock");  
    String source2 = createStringFromLiteral("ck ∆");
    String source3 = createStringFromLiteral("∆ rock");
    
    if (stringEndsWith(&source1, &empty))   { fails = true; }
    if (stringEndsWith(&empty, &source1))   { fails = true; }
    if (stringEndsWith(&empty, &empty))   { fails = true; }
    if (stringEndsWith(&source1, &source2)) { fails = true; }
    if (! stringEndsWith(&source1, &source1)) { fails = true; }
    if (! stringEndsWith(&source1, &source3)) { fails = true; }

    if (fails) { 
        printf("stringEndsWith FAILS!\n");
        exit(1);
    }
}

void testStringIndexOf()
{
    printf("- testing stringIndexOf\n"); 
    
    bool fails = false;

    String empty = createStringEmpty();  
    String source1 = createStringFromLiteral("Life is ∆ rock and ∆ like rock");  
    String source2 = createStringFromLiteral("∆ like");
    String source3 = createStringFromLiteral("and#∆");

    if (stringIndexOf(&source1, &source1) !=  1) { fails = true; }
    if (stringIndexOf(&source1, &source2) != 22) { fails = true; }
    if (stringIndexOf(&source1, &source3) !=  0) { fails = true; }
    if (stringIndexOf(&source1, &empty)   !=  0) { fails = true; }
    if (stringIndexOf(&empty, &source1)   !=  0) { fails = true; }
    if (stringIndexOf(&empty, &empty)     !=  0) { fails = true; }
    
    if (fails) {
        printf("stringIndexOf FAILS!\n");
        exit(1);
    }
}

void testStringLastIndexOf()
{
    printf("- testing stringLastIndexOf\n"); 
    
    bool fails = false;

    String empty = createStringEmpty();  
    String source1 = createStringFromLiteral("Life is ∆ rock and ∆ like rock"); 
    String source2 = createStringFromLiteral("∆");
    String source3 = createStringFromLiteral("∆#");

    if (stringLastIndexOf(&source1, &source1) !=  1) { fails = true; }
    if (stringLastIndexOf(&source1, &source2) != 22) { fails = true; }
    if (stringLastIndexOf(&source1, &source3) !=  0) { fails = true; }
    if (stringLastIndexOf(&source1, &empty)   !=  0) { fails = true; }
    if (stringLastIndexOf(&empty, &source1) !=  0) { fails = true; }
    if (stringLastIndexOf(&empty, &empty)   !=  0) { fails = true; }    
    
    if (fails) {
        printf("stringLastIndexOf FAILS!\n");
        exit(1);
    }
}

void testStringIndexOfAfter()
{
    printf("- testing stringIndexOfAfter\n"); 
    
    bool fails = false;

    String empty = createStringEmpty();  
    String source1 = createStringFromLiteral("Life is ∆ rock and ∆ like rock");  
    String source2 = createStringFromLiteral("∆");
    String source3 = createStringFromLiteral("∆#");
    
    if (stringIndexOfAfter(&source1, &source1,  0) !=  1) { fails = true; }
    if (stringIndexOfAfter(&source1, &source1, -9) !=  1) { fails = true; }
    if (stringIndexOfAfter(&source1, &source2,  9) != 22) { fails = true; }
    if (stringIndexOfAfter(&source1, &source2, 99) !=  0) { fails = true; }
    if (stringIndexOfAfter(&source1, &source2,  0) !=  9) { fails = true; }
    if (stringIndexOfAfter(&source1, &source3,  0) !=  0) { fails = true; }
    if (stringIndexOfAfter(&source1, &empty, 0) != 0) { fails = true; }  
    if (stringIndexOfAfter(&empty, &source1, 0) != 0) { fails = true; }  
    if (stringIndexOfAfter(&empty, &empty,   0) != 0) { fails = true; }  
         
    if (fails) {
        printf("stringIndexOfAfter FAILS!\n");
        exit(1);
    }
}

void testStringLastIndexOfBefore()
{
    printf("- testing stringLastIndexOfBefore\n"); 
    
    bool fails = false;

    String empty = createStringEmpty();  
    String source1 = createStringFromLiteral("Life is ∆ rock and ∆ like rock"); 
    String source2 = createStringFromLiteral("∆");
    String source3 = createStringFromLiteral("∆#");
    
    if (stringLastIndexOfBefore(&source1, &source1, -1) !=  0) { fails = true; }
    if (stringLastIndexOfBefore(&source1, &source1,  3) !=  0) { fails = true; }
    if (stringLastIndexOfBefore(&source1, &source2, 22) !=  9) { fails = true; }
    if (stringLastIndexOfBefore(&source1, &source3, 99) !=  0) { fails = true; }
    if (stringLastIndexOfBefore(&source1, &source1, 99) !=  1) { fails = true; }
    if (stringLastIndexOfBefore(&source1, &empty, 10) !=  0) { fails = true; } 
    if (stringLastIndexOfBefore(&empty, &source1, 10) !=  0) { fails = true; } 
    if (stringLastIndexOfBefore(&empty, &empty,   10) !=  0) { fails = true; }  
         
    if (fails) {
        printf("stringLastIndexOfBefore FAILS!\n"); 
        exit(1);
    }
}

void testStringCountOfTarget()
{
    printf("- testing stringCountOfTarget\n"); 
    
    bool fails = false;

    String empty = createStringEmpty();  
    String source1 = createStringFromLiteral("Life is ∆ rock and ∆ like rock"); 
    String source2 = createStringFromLiteral("∆");
    String source3 = createStringFromLiteral("∆#");
    String source4 = createStringFromLiteral("∆∆∆");
    String source5 = createStringFromLiteral("∆.∆.∆");
    
    if (stringCountOfTarget(&source1, &source2) != 2) { fails = true; }
    if (stringCountOfTarget(&source1, &source3) != 0) { fails = true; }
    if (stringCountOfTarget(&source4, &source2) != 3) { fails = true; }
    if (stringCountOfTarget(&source5, &source2) != 3) { fails = true; }
    if (stringCountOfTarget(&source1, &empty) != 0) { fails = true; }
    if (stringCountOfTarget(&empty, &source1) != 0) { fails = true; }
    if (stringCountOfTarget(&empty, &empty)   != 0) { fails = true; }
         
    if (fails) {
        printf("stringCountOfTarget FAILS!\n"); 
        exit(1);
    }
}

