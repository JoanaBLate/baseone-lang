
void testCharCodeAt() 
{
    struct String source = { 6, "He@llo" };
    bool fails = false;
    if (stringCharCodeAt(&source, 3) != 64)   { fails = true; }
    if (stringCharCodeAt(&source, 333) != -1) { fails = true; }
    if (stringCharCodeAt(&source, -33) != -1) { fails = true; }
    
    if (fails) { 
        printf("testCharCodeAt FAILS!\n"); 
        exit(1);
    }
}

void testStringsAreEquals()
{
    bool fails = false;

    struct String source1 = { 16, "Life is ∆ rock" };
    struct String source2 = { 16, "Life is ∆ rock" };
    struct String source3 = { 12, "Life is ∆ " };

    if (! stringsAreEqual(&source1, &source2)) { fails = true; };
    if (stringsAreEqual(&source1, &source3))   { fails = true; };
    
    struct String empty1 = createEmptyString();    
    struct String empty2 = createEmptyString();
    
    if (! stringsAreEqual(&empty1, &empty2)) { fails = true; };
    if (stringsAreEqual(&empty1, &source1))  { fails = true; };
    
    if (fails) { 
        printf("testStringsAreEqual FAILS!\n");
        exit(1);
    }
}

void testStringContains()
{
    bool fails = false;

    struct String empty = createEmptyString();    
    struct String source1 = { 16, "Life is ∆ rock" };
    struct String source2 = {  7, " ∆ ro" };
    struct String source3 = {  6, "ck ∆" };
    
    if (! stringContains(&source1, &source1)) { fails = true; }
    if (! stringContains(&source1, &source2)) { fails = true; }
    if (stringContains(&source1, &source3)) { fails = true; }
    if (stringContains(&source1, &empty))   { fails = true; }
    if (stringContains(&empty, &source1))   { fails = true; }

    if (fails) { 
        printf("testStringContains FAILS!\n"); 
        exit(1);
    }
}

void testStringStartsWith()
{
    bool fails = false;

    struct String empty = createEmptyString();  
    struct String source1 = { 16, "Life is ∆ rock" };  
    struct String source2 = { 11, "Life is ∆" };
    struct String source3 = { 10, "Life rocks" };
    
    if (stringStartsWith(&source1, &empty))   { fails = true; }
    if (stringStartsWith(&empty, &source1))   { fails = true; }
    if (stringStartsWith(&empty, &empty))     { fails = true; }
    if (stringStartsWith(&source1, &source3)) { fails = true; }
    if (! stringStartsWith(&source1, &source1)) { fails = true; }
    if (! stringStartsWith(&source1, &source2)) { fails = true; }

    if (fails) { 
        printf("testStringStartsWith FAILS!\n");
        exit(1);
    }
}

void testStringEndsWith()
{
    bool fails = false;

    struct String empty = createEmptyString();  
    struct String source1 = { 16, "Life is ∆ rock" };  
    struct String source2 = {  6, "ck ∆" };
    struct String source3 = {  8, "∆ rock" };
    
    if (stringEndsWith(&source1, &empty))   { fails = true; }
    if (stringEndsWith(&empty, &source1))   { fails = true; }
    if (stringEndsWith(&empty, &empty))   { fails = true; }
    if (stringEndsWith(&source1, &source2)) { fails = true; }
    if (! stringEndsWith(&source1, &source1)) { fails = true; }
    if (! stringEndsWith(&source1, &source3)) { fails = true; }

    if (fails) { 
        printf("testStringEndsWith FAILS!\n");
        exit(1);
    }
}

void testStringIndexOf()
{
    bool fails = false;

    struct String empty = createEmptyString();  
    struct String source1 = { 34, "Life is ∆ rock and ∆ like rock" };  
    struct String source2 = {  8, "∆ like" };
    struct String source3 = {  7, "and#∆" };

    if (stringIndexOf(&source1, &source1) !=  1) { fails = true; }
    if (stringIndexOf(&source1, &source2) != 22) { fails = true; }
    if (stringIndexOf(&source1, &source3) !=  0) { fails = true; }
    if (stringIndexOf(&source1, &empty)   !=  0) { fails = true; }
    if (stringIndexOf(&empty, &source1)   !=  0) { fails = true; }
    if (stringIndexOf(&empty, &empty)     !=  0) { fails = true; }
    
    if (fails) {
        printf("testStringIndexOf FAILS!\n");
        exit(1);
    }
}

void testStringLastIndexOf()
{
    bool fails = false;

    struct String empty = createEmptyString();  
    struct String source1 = { 34, "Life is ∆ rock and ∆ like rock" }; 
    struct String source2 = {  3, "∆" };
    struct String source3 = {  4, "∆#" };

    if (stringLastIndexOf(&source1, &source1) !=  1) { fails = true; }
    if (stringLastIndexOf(&source1, &source2) != 22) { fails = true; }
    if (stringLastIndexOf(&source1, &source3) !=  0) { fails = true; }
    if (stringLastIndexOf(&source1, &empty)   !=  0) { fails = true; }
    if (stringLastIndexOf(&empty, &source1) !=  0) { fails = true; }
    if (stringLastIndexOf(&empty, &empty)   !=  0) { fails = true; }    
    
    if (fails) {
        printf("testStringLastIndexOf FAILS!\n");
        exit(1);
    }
}

void testStringIndexOfAfter()
{
    bool fails = false;

    struct String empty = createEmptyString();  
    struct String source1 = { 34, "Life is ∆ rock and ∆ like rock" };  
    struct String source2 = {  3, "∆" };
    struct String source3 = {  4, "∆#" };
    
    if (stringIndexOfAfter(&source1, &source1,  0) !=  1) { fails = true; }
    if (stringIndexOfAfter(&source1, &source1, -9) !=  1) { fails = true; }
    if (stringIndexOfAfter(&source1, &source2,  9) != 22) { fails = true; }
    if (stringIndexOfAfter(&source1, &source2, 99) !=  0) { fails = true; }
    if (stringIndexOfAfter(&source1, &source2,  0) !=  9) { fails = true; }
    if (stringIndexOfAfter(&source1, &source3,  0) !=  0) { fails = true; }
    if (stringIndexOfAfter(&source1, &empty, 0) !=  0) { fails = true; }  
    if (stringIndexOfAfter(&empty, &source1, 0) !=  0) { fails = true; }  
    if (stringIndexOfAfter(&empty, &empty,   0) !=  0) { fails = true; }  
         
    if (fails) {
        printf("testStringIndexOfAfter FAILS!\n");
        exit(1);
    }
}

void testStringLastIndexOfBefore()
{
    bool fails = false;

    struct String empty = createEmptyString();  
    struct String source1 = { 34, "Life is ∆ rock and ∆ like rock" }; 
    struct String source2 = {  3, "∆" };
    struct String source3 = {  4, "∆#" };
    
    if (stringLastIndexOfBefore(&source1, &source1, -1) !=  0) { fails = true; }
    if (stringLastIndexOfBefore(&source1, &source1,  3) !=  0) { fails = true; }
    if (stringLastIndexOfBefore(&source1, &source2, 22) !=  9) { fails = true; }
    if (stringLastIndexOfBefore(&source1, &source3, 99) !=  0) { fails = true; }
    if (stringLastIndexOfBefore(&source1, &source1, 99) !=  1) { fails = true; }
    if (stringLastIndexOfBefore(&source1, &empty, 10)  !=  0) { fails = true; } 
    if (stringLastIndexOfBefore(&empty, &source1, 10)  !=  0) { fails = true; } 
    if (stringLastIndexOfBefore(&empty, &empty,   10)  !=  0) { fails = true; }  
         
    if (fails) {
        printf("testStringLastIndexOfBefore FAILS!\n"); 
        exit(1);
    }
}

void stringInfoTest()
{
    printf("TESTING string info\n");
    
    testCharCodeAt();

    testStringsAreEquals();

    testStringContains();
    testStringEndsWith();
    testStringStartsWith();

    testStringIndexOf();
    testStringLastIndexOf();

    testStringIndexOfAfter();
    testStringLastIndexOfBefore();
}

