// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testHeapBufferCharCodeAt() 
{
    printf("- testing heapBufferCharCodeAt\n"); 
    
    HeapBuffer hb = createHeapBufferFromLiteral("123He@llo123");
    
    hb.margin = 3;
    hb.size -= 6;
    
    bool fails = false;
    if (heapBufferCharCodeAt(hb, 3) != 64)   { fails = true; }
    
//  RAISES ERROR 
//  printf("%c\n", heapBufferCharCodeAt(hb, -1));
//  printf("%c\n", heapBufferCharCodeAt(hb, 333));
    
    if (fails) { 
        printf("heapBufferCharCodeAt FAILS!\n"); 
        exit(1);
    }
    
    releaseHeapBuffer(hb);
}

void testHeapBuffersAreEquals()
{
    printf("- testing heapBuffersAreEqual\n"); 
    
    bool fails = false;

    HeapBuffer hb1 = createHeapBufferFromLiteral("123Life is ∆ rock123");
    HeapBuffer hb2 = createHeapBufferFromLiteral("Life is ∆ rock");
    HeapBuffer hb3 = createHeapBufferFromLiteral("Life is ∆ ");
    
    hb1.margin = 3;
    hb1.size -= 6;

    if (! heapBuffersAreEqual(hb1, hb2)) { fails = true; }
    if (heapBuffersAreEqual(hb1, hb3))   { fails = true; }
    
    HeapBuffer empty1 = createHeapBufferFromLiteral("");    
    HeapBuffer empty2 = createHeapBufferFromLiteral("");
    
    if (! heapBuffersAreEqual(empty1, empty2)) { fails = true; }
    if (heapBuffersAreEqual(empty1, hb1))  { fails = true; }
    
    if (fails) { 
        printf("heapBuffersAreEqual FAILS!\n");
        exit(1);
    }
    
    releaseHeapBuffer(hb1);
    releaseHeapBuffer(hb2);
    releaseHeapBuffer(hb3);
    releaseHeapBuffer(empty1);
    releaseHeapBuffer(empty2);
}

void testHeapBufferContains()
{
    printf("- testing heapBufferContains\n"); 
    
    bool fails = false;

    HeapBuffer hb0 = createHeapBufferFromLiteral("");    
    HeapBuffer hb1 = createHeapBufferFromLiteral("123Life is ∆ rock123");

    hb1.margin = 3;
    hb1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock");
    String string2 = makeStringFromLiteral("Life is ∆ rock1");
    String string3 = makeStringFromLiteral("ck ∆");
    
    if (! heapBufferContains(hb1, string1)) { fails = true; }
    if (heapBufferContains(hb1, string2))   { fails = true; }
    if (heapBufferContains(hb1, string0))   { fails = true; }
    if (heapBufferContains(hb1, string3))   { fails = true; }
    if (heapBufferContains(hb0, string1))   { fails = true; }

    if (fails) { 
        printf("heapBufferContains FAILS!\n"); 
        exit(1);
    }
    
    releaseHeapBuffer(hb0);
    releaseHeapBuffer(hb1);
}

void testHeapBufferStartsWith()
{
    printf("- testing heapBufferStartsWith\n"); 
    
    bool fails = false;
    
    HeapBuffer hb0 = createHeapBufferFromLiteral("");    
    HeapBuffer hb1 = createHeapBufferFromLiteral("123Life is ∆ rock123");

    hb1.margin = 3;
    hb1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock");
    String string2 = makeStringFromLiteral("Life is ∆");
    String string3 = makeStringFromLiteral("Life rocks");
    
    if (heapBufferStartsWith(hb1, string0)) { fails = true; }
    if (heapBufferStartsWith(hb0, string1)) { fails = true; }
    if (heapBufferStartsWith(hb0, string0)) { fails = true; }
    if (heapBufferStartsWith(hb1, string3)) { fails = true; }
    if (! heapBufferStartsWith(hb1, string1)) { fails = true; }
    if (! heapBufferStartsWith(hb1, string2)) { fails = true; }

    if (fails) { 
        printf("heapBufferStartsWith FAILS!\n");
        exit(1);
    }
    
    releaseHeapBuffer(hb0);
    releaseHeapBuffer(hb1);
}

void testHeapBufferEndsWith()
{
    printf("- testing heapBufferEndsWith\n"); 
    
    bool fails = false;
    
    HeapBuffer hb0 = createHeapBufferFromLiteral("");    
    HeapBuffer hb1 = createHeapBufferFromLiteral("123Life is ∆ rock123");

    hb1.margin = 3;
    hb1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock");
    String string2 = makeStringFromLiteral("ck ∆");
    String string3 = makeStringFromLiteral("∆ rock");
    
    if (heapBufferEndsWith(hb1, string0))   { fails = true; }
    if (heapBufferEndsWith(hb0, string1))   { fails = true; }
    if (heapBufferEndsWith(hb0, string0))   { fails = true; }
    if (heapBufferEndsWith(hb1, string2))   { fails = true; }
    if (! heapBufferEndsWith(hb1, string1)) { fails = true; }
    if (! heapBufferEndsWith(hb1, string3)) { fails = true; }

    if (fails) { 
        printf("heapBufferEndsWith FAILS!\n");
        exit(1);
    }
    
    releaseHeapBuffer(hb0);
    releaseHeapBuffer(hb1);
}

void testHeapBufferIndexOf()
{
    printf("- testing heapBufferIndexOf\n"); 
    
    bool fails = false;
    
    HeapBuffer hb0 = createHeapBufferFromLiteral("");    
    HeapBuffer hb1 = createHeapBufferFromLiteral("123Life is ∆ rock and ∆ like rock123");

    hb1.margin = 3;
    hb1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock and ∆ like rock");
    String string2 = makeStringFromLiteral("∆ like");
    String string3 = makeStringFromLiteral("and#");

    if (heapBufferIndexOf(hb1, string1) !=  1) { fails = true; }
    if (heapBufferIndexOf(hb1, string2) != 22) { fails = true; }
    if (heapBufferIndexOf(hb1, string3) !=  0) { fails = true; }
    if (heapBufferIndexOf(hb1, string0) !=  0) { fails = true; }
    if (heapBufferIndexOf(hb0, string1) !=  0) { fails = true; }
    if (heapBufferIndexOf(hb0, string0) !=  0) { fails = true; }
    
    if (fails) {
        printf("heapBufferIndexOf FAILS!\n");
        exit(1);
    }
    
    releaseHeapBuffer(hb0);
    releaseHeapBuffer(hb1);
}

void testHeapBufferLastIndexOf()
{
    printf("- testing heapBufferLastIndexOf\n"); 
    
    bool fails = false;
    
    HeapBuffer hb0 = createHeapBufferFromLiteral("");    
    HeapBuffer hb1 = createHeapBufferFromLiteral("123Life is ∆ rock and ∆ like rock123");

    hb1.margin = 3;
    hb1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock and ∆ like rock");
    String string2 = makeStringFromLiteral("∆");
    String string3 = makeStringFromLiteral("∆#");

    if (heapBufferLastIndexOf(hb1, string1) !=  1) { fails = true; }
    if (heapBufferLastIndexOf(hb1, string2) != 22) { fails = true; }
    if (heapBufferLastIndexOf(hb1, string3) !=  0) { fails = true; }
    if (heapBufferLastIndexOf(hb1, string0) !=  0) { fails = true; }
    if (heapBufferLastIndexOf(hb0, string1) !=  0) { fails = true; }
    if (heapBufferLastIndexOf(hb0, string0) !=  0) { fails = true; }    
    
    if (fails) {
        printf("heapBufferLastIndexOf FAILS!\n");
        exit(1);
    }
    
    releaseHeapBuffer(hb0);
    releaseHeapBuffer(hb1);
}

void testHeapBufferIndexOfAfter()
{
    printf("- testing heapBufferIndexOfAfter\n"); 
    
    bool fails = false;
    
    HeapBuffer hb0 = createHeapBufferFromLiteral("");    
    HeapBuffer hb1 = createHeapBufferFromLiteral("123Life is ∆ rock and ∆ like rock123");

    hb1.margin = 3;
    hb1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock and ∆ like rock");
    String string2 = makeStringFromLiteral("∆");
    String string3 = makeStringFromLiteral("∆#");
    
    if (heapBufferIndexOfAfter(hb1, string1,  0) !=  1) { fails = true; }
    if (heapBufferIndexOfAfter(hb1, string1, -9) !=  1) { fails = true; }
    if (heapBufferIndexOfAfter(hb1, string2,  9) != 22) { fails = true; }
    if (heapBufferIndexOfAfter(hb1, string2, 99) !=  0) { fails = true; }
    if (heapBufferIndexOfAfter(hb1, string2,  0) !=  9) { fails = true; }
    if (heapBufferIndexOfAfter(hb1, string3,  0) !=  0) { fails = true; }
    if (heapBufferIndexOfAfter(hb1, string0, 0) != 0) { fails = true; }  
    if (heapBufferIndexOfAfter(hb0, string1, 0) != 0) { fails = true; }  
    if (heapBufferIndexOfAfter(hb0, string0,   0) != 0) { fails = true; }  
         
    if (fails) {
        printf("heapBufferIndexOfAfter FAILS!\n");
        exit(1);
    }
    
    releaseHeapBuffer(hb0);
    releaseHeapBuffer(hb1);
}

void testHeapBufferLastIndexOfBefore()
{
    printf("- testing heapBufferLastIndexOfBefore\n"); 
    
    bool fails = false;
    
    HeapBuffer hb0 = createHeapBufferFromLiteral("");    
    HeapBuffer hb1 = createHeapBufferFromLiteral("123Life is ∆ rock and ∆ like rock123");

    hb1.margin = 3;
    hb1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock and ∆ like rock");
    String string2 = makeStringFromLiteral("∆");
    String string3 = makeStringFromLiteral("∆#");
    
    if (heapBufferLastIndexOfBefore(hb1, string1, -1) !=  0) { fails = true; }
    if (heapBufferLastIndexOfBefore(hb1, string1,  3) !=  0) { fails = true; }
    if (heapBufferLastIndexOfBefore(hb1, string2, 22) !=  9) { fails = true; }
    if (heapBufferLastIndexOfBefore(hb1, string3, 99) !=  0) { fails = true; }
    if (heapBufferLastIndexOfBefore(hb1, string1, 99) !=  1) { fails = true; }
    if (heapBufferLastIndexOfBefore(hb1, string0, 10) !=  0) { fails = true; } 
    if (heapBufferLastIndexOfBefore(hb0, string1, 10) !=  0) { fails = true; } 
    if (heapBufferLastIndexOfBefore(hb0, string0, 10) !=  0) { fails = true; }  
         
    if (fails) {
        printf("heapBufferLastIndexOfBefore FAILS!\n"); 
        exit(1);
    }
    
    releaseHeapBuffer(hb0);
    releaseHeapBuffer(hb1);
}

void testHeapBufferCountOf()
{
    printf("- testing heapBufferCountOf\n"); 
    
    bool fails = false;

    HeapBuffer hb0 = createHeapBufferFromLiteral("");    
    HeapBuffer hb1 = createHeapBufferFromLiteral("123Life is ∆ rock and ∆ like rock123");
    HeapBuffer hb2 = createHeapBufferFromLiteral("∆∆∆");
    HeapBuffer hb3 = createHeapBufferFromLiteral("∆.∆.∆");

    hb1.margin = 3;
    hb1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock and ∆ like rock");
    String string2 = makeStringFromLiteral("∆");
    String string3 = makeStringFromLiteral("∆#");
    
    if (heapBufferCountOf(hb1, string2) != 2) { fails = true; }
    if (heapBufferCountOf(hb1, string3) != 0) { fails = true; }
    if (heapBufferCountOf(hb2, string2) != 3) { fails = true; }
    if (heapBufferCountOf(hb3, string3) != 0) { fails = true; }
    if (heapBufferCountOf(hb1, string0) != 0) { fails = true; }
    if (heapBufferCountOf(hb0, string1) != 0) { fails = true; }
    if (heapBufferCountOf(hb0, string0) != 0) { fails = true; }
         
    if (fails) {
        printf("heapBufferCountOf FAILS!\n"); 
        exit(1);
    }
    
    releaseHeapBuffer(hb0);
    releaseHeapBuffer(hb1);
    releaseHeapBuffer(hb2);
    releaseHeapBuffer(hb3);
}

