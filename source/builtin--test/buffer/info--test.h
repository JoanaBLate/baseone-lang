// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testBufferByteAt() 
{
    printf("- testing bufferByteAt\n"); 
    
    Buffer buffer = createBufferFromLiteral("123He@llo123");
    
    buffer.margin = 3;
    buffer.size -= 6;
    
    bool fails = false;
    if (bufferByteAt(&buffer, 3) != 64)   { fails = true; }
    
//  RAISES ERROR 
//  printf("%c\n", bufferByteAt(&buffer, -1));
//  printf("%c\n", bufferByteAt(&buffer, 333));
    
    if (fails) { 
        printf("bufferByteAt FAILS!\n"); 
        exit(1);
    }
    
    releaseBuffer(&buffer);
}

void testBuffersAreEquals()
{
    printf("- testing buffersAreEqual\n"); 
    
    bool fails = false;

    Buffer buffer1 = createBufferFromLiteral("123Life is ∆ rock123");
    Buffer buffer2 = createBufferFromLiteral("Life is ∆ rock");
    Buffer buffer3 = createBufferFromLiteral("Life is ∆ ");
    
    buffer1.margin = 3;
    buffer1.size -= 6;

    if (! buffersAreEqual(&buffer1, &buffer2)) { fails = true; }
    if (buffersAreEqual(&buffer1, &buffer3))   { fails = true; }
    
    Buffer empty1 = createBufferFromLiteral("");    
    Buffer empty2 = createBufferFromLiteral("");
    
    if (! buffersAreEqual(&empty1, &empty2)) { fails = true; }
    if (buffersAreEqual(&empty1, &buffer1))  { fails = true; }
    
    if (fails) { 
        printf("buffersAreEqual FAILS!\n");
        exit(1);
    }
    
    releaseBuffer(&buffer1);
    releaseBuffer(&buffer2);
    releaseBuffer(&buffer3);
    releaseBuffer(&empty1);
    releaseBuffer(&empty2);
}

void testBuffersCompare()
{
    printf("- testing buffersCompare\n"); 
    
    bool fails = false;
    
    Buffer bEmpty1 = createBufferEmpty();
    Buffer bEmpty2 = createBufferEmpty();
    Buffer bSource1 = createBufferFromLiteral("Life is ∆ rock");
    Buffer bSource2 = createBufferFromLiteral("Life is ∆ rock");
    Buffer bSource3 = createBufferFromLiteral("Life is ∆ ");
    Buffer bSource4 = createBufferFromLiteral("LIfe is ∆ ");

    String empty1  = makeStringFromBuffer(&bEmpty1);    
    String empty2  = makeStringFromBuffer(&bEmpty2);
    String source1 = makeStringFromBuffer(&bSource1);
    String source2 = makeStringFromBuffer(&bSource2);
    String source3 = makeStringFromBuffer(&bSource3);
    String source4 = makeStringFromBuffer(&bSource4);

    if (stringsCompare(&empty1,  &empty2)  !=  0) { fails = true; }
    if (stringsCompare(&empty1,  &source2) != -1) { fails = true; }
    if (stringsCompare(&source1, &source2) !=  0) { fails = true; }
    if (stringsCompare(&source1, &source3) != +1) { fails = true; }
    if (stringsCompare(&source4, &source3) != -1) { fails = true; }
    
    if (fails) { 
        printf("buffersCompare FAILS!\n");
        exit(1);
    }
    
    releaseBuffer(&bEmpty1);
    releaseBuffer(&bEmpty2);
    releaseBuffer(&bSource1);
    releaseBuffer(&bSource2);
    releaseBuffer(&bSource3);
    releaseBuffer(&bSource4);
}

void testBufferContains()
{
    printf("- testing bufferContains\n"); 
    
    bool fails = false;

    Buffer buffer0 = createBufferFromLiteral("");    
    Buffer buffer1 = createBufferFromLiteral("123Life is ∆ rock123");

    buffer1.margin = 3;
    buffer1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock");
    String string2 = makeStringFromLiteral("Life is ∆ rock1");
    String string3 = makeStringFromLiteral("ck ∆");
    
    if (! bufferContains(&buffer1, &string1)) { fails = true; }
    if (bufferContains(&buffer1, &string2))   { fails = true; }
    if (bufferContains(&buffer1, &string0))   { fails = true; }
    if (bufferContains(&buffer1, &string3))   { fails = true; }
    if (bufferContains(&buffer0, &string1))   { fails = true; }

    if (fails) { 
        printf("bufferContains FAILS!\n"); 
        exit(1);
    }
    
    releaseBuffer(&buffer0);
    releaseBuffer(&buffer1);
}

void testBufferStartsWith()
{
    printf("- testing bufferStartsWith\n"); 
    
    bool fails = false;
    
    Buffer buffer0 = createBufferFromLiteral("");    
    Buffer buffer1 = createBufferFromLiteral("123Life is ∆ rock123");

    buffer1.margin = 3;
    buffer1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock");
    String string2 = makeStringFromLiteral("Life is ∆");
    String string3 = makeStringFromLiteral("Life rocks");
    
    if (bufferStartsWith(&buffer1, &string0)) { fails = true; }
    if (bufferStartsWith(&buffer0, &string1)) { fails = true; }
    if (bufferStartsWith(&buffer0, &string0)) { fails = true; }
    if (bufferStartsWith(&buffer1, &string3)) { fails = true; }
    if (! bufferStartsWith(&buffer1, &string1)) { fails = true; }
    if (! bufferStartsWith(&buffer1, &string2)) { fails = true; }

    if (fails) { 
        printf("bufferStartsWith FAILS!\n");
        exit(1);
    }
    
    releaseBuffer(&buffer0);
    releaseBuffer(&buffer1);
}

void testBufferEndsWith()
{
    printf("- testing bufferEndsWith\n"); 
    
    bool fails = false;
    
    Buffer buffer0 = createBufferFromLiteral("");    
    Buffer buffer1 = createBufferFromLiteral("123Life is ∆ rock123");

    buffer1.margin = 3;
    buffer1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock");
    String string2 = makeStringFromLiteral("ck ∆");
    String string3 = makeStringFromLiteral("∆ rock");
    
    if (bufferEndsWith(&buffer1, &string0))   { fails = true; }
    if (bufferEndsWith(&buffer0, &string1))   { fails = true; }
    if (bufferEndsWith(&buffer0, &string0))   { fails = true; }
    if (bufferEndsWith(&buffer1, &string2))   { fails = true; }
    if (! bufferEndsWith(&buffer1, &string1)) { fails = true; }
    if (! bufferEndsWith(&buffer1, &string3)) { fails = true; }

    if (fails) { 
        printf("bufferEndsWith FAILS!\n");
        exit(1);
    }
    
    releaseBuffer(&buffer0);
    releaseBuffer(&buffer1);
}

void testBufferIndexOf()
{
    printf("- testing bufferIndexOf\n"); 
    
    bool fails = false;
    
    Buffer buffer0 = createBufferFromLiteral("");    
    Buffer buffer1 = createBufferFromLiteral("123Life is ∆ rock and ∆ like rock123");

    buffer1.margin = 3;
    buffer1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock and ∆ like rock");
    String string2 = makeStringFromLiteral("∆ like");
    String string3 = makeStringFromLiteral("and#");

    if (bufferIndexOf(&buffer1, &string1) !=  1) { fails = true; }
    if (bufferIndexOf(&buffer1, &string2) != 22) { fails = true; }
    if (bufferIndexOf(&buffer1, &string3) !=  0) { fails = true; }
    if (bufferIndexOf(&buffer1, &string0) !=  0) { fails = true; }
    if (bufferIndexOf(&buffer0, &string1) !=  0) { fails = true; }
    if (bufferIndexOf(&buffer0, &string0) !=  0) { fails = true; }
    
    if (fails) {
        printf("bufferIndexOf FAILS!\n");
        exit(1);
    }
    
    releaseBuffer(&buffer0);
    releaseBuffer(&buffer1);
}

void testBufferLastIndexOf()
{
    printf("- testing bufferLastIndexOf\n"); 
    
    bool fails = false;
    
    Buffer buffer0 = createBufferFromLiteral("");    
    Buffer buffer1 = createBufferFromLiteral("123Life is ∆ rock and ∆ like rock123");

    buffer1.margin = 3;
    buffer1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock and ∆ like rock");
    String string2 = makeStringFromLiteral("∆");
    String string3 = makeStringFromLiteral("∆#");

    if (bufferLastIndexOf(&buffer1, &string1) !=  1) { fails = true; }
    if (bufferLastIndexOf(&buffer1, &string2) != 22) { fails = true; }
    if (bufferLastIndexOf(&buffer1, &string3) !=  0) { fails = true; }
    if (bufferLastIndexOf(&buffer1, &string0) !=  0) { fails = true; }
    if (bufferLastIndexOf(&buffer0, &string1) !=  0) { fails = true; }
    if (bufferLastIndexOf(&buffer0, &string0) !=  0) { fails = true; }    
    
    if (fails) {
        printf("bufferLastIndexOf FAILS!\n");
        exit(1);
    }
    
    releaseBuffer(&buffer0);
    releaseBuffer(&buffer1);
}

void testBufferIndexOfAfter()
{
    printf("- testing bufferIndexOfAfter\n"); 
    
    bool fails = false;
    
    Buffer buffer0 = createBufferFromLiteral("");    
    Buffer buffer1 = createBufferFromLiteral("123Life is ∆ rock and ∆ like rock123");

    buffer1.margin = 3;
    buffer1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock and ∆ like rock");
    String string2 = makeStringFromLiteral("∆");
    String string3 = makeStringFromLiteral("∆#");
    
    if (bufferIndexOfAfter(&buffer1, &string1,  0) !=  1) { fails = true; }
    if (bufferIndexOfAfter(&buffer1, &string1, -9) !=  1) { fails = true; }
    if (bufferIndexOfAfter(&buffer1, &string2,  9) != 22) { fails = true; }
    if (bufferIndexOfAfter(&buffer1, &string2, 99) !=  0) { fails = true; }
    if (bufferIndexOfAfter(&buffer1, &string2,  0) !=  9) { fails = true; }
    if (bufferIndexOfAfter(&buffer1, &string3,  0) !=  0) { fails = true; }
    if (bufferIndexOfAfter(&buffer1, &string0, 0) != 0) { fails = true; }  
    if (bufferIndexOfAfter(&buffer0, &string1, 0) != 0) { fails = true; }  
    if (bufferIndexOfAfter(&buffer0, &string0,   0) != 0) { fails = true; }  
         
    if (fails) {
        printf("bufferIndexOfAfter FAILS!\n");
        exit(1);
    }
    
    releaseBuffer(&buffer0);
    releaseBuffer(&buffer1);
}

void testBufferLastIndexOfBefore()
{
    printf("- testing bufferLastIndexOfBefore\n"); 
    
    bool fails = false;
    
    Buffer buffer0 = createBufferFromLiteral("");    
    Buffer buffer1 = createBufferFromLiteral("123Life is ∆ rock and ∆ like rock123");

    buffer1.margin = 3;
    buffer1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock and ∆ like rock");
    String string2 = makeStringFromLiteral("∆");
    String string3 = makeStringFromLiteral("∆#");
    
    if (bufferLastIndexOfBefore(&buffer1, &string1, -1) !=  0) { fails = true; }
    if (bufferLastIndexOfBefore(&buffer1, &string1,  3) !=  0) { fails = true; }
    if (bufferLastIndexOfBefore(&buffer1, &string2, 22) !=  9) { fails = true; }
    if (bufferLastIndexOfBefore(&buffer1, &string3, 99) !=  0) { fails = true; }
    if (bufferLastIndexOfBefore(&buffer1, &string1, 99) !=  1) { fails = true; }
    if (bufferLastIndexOfBefore(&buffer1, &string0, 10) !=  0) { fails = true; } 
    if (bufferLastIndexOfBefore(&buffer0, &string1, 10) !=  0) { fails = true; } 
    if (bufferLastIndexOfBefore(&buffer0, &string0, 10) !=  0) { fails = true; }  
         
    if (fails) {
        printf("bufferLastIndexOfBefore FAILS!\n"); 
        exit(1);
    }
    
    releaseBuffer(&buffer0);
    releaseBuffer(&buffer1);
}

void testBufferCountOf()
{
    printf("- testing bufferCountOf\n"); 
    
    bool fails = false;

    Buffer buffer0 = createBufferFromLiteral("");    
    Buffer buffer1 = createBufferFromLiteral("123Life is ∆ rock and ∆ like rock123");
    Buffer buffer2 = createBufferFromLiteral("∆∆∆");
    Buffer buffer3 = createBufferFromLiteral("∆.∆.∆");

    buffer1.margin = 3;
    buffer1.size -= 6;
    
    String string0 = makeStringEmpty();
    String string1 = makeStringFromLiteral("Life is ∆ rock and ∆ like rock");
    String string2 = makeStringFromLiteral("∆");
    String string3 = makeStringFromLiteral("∆#");
    
    if (bufferCountOf(&buffer1, &string2) != 2) { fails = true; }
    if (bufferCountOf(&buffer1, &string3) != 0) { fails = true; }
    if (bufferCountOf(&buffer2, &string2) != 3) { fails = true; }
    if (bufferCountOf(&buffer3, &string3) != 0) { fails = true; }
    if (bufferCountOf(&buffer1, &string0) != 0) { fails = true; }
    if (bufferCountOf(&buffer0, &string1) != 0) { fails = true; }
    if (bufferCountOf(&buffer0, &string0) != 0) { fails = true; }
         
    if (fails) {
        printf("bufferCountOf FAILS!\n"); 
        exit(1);
    }
    
    releaseBuffer(&buffer0);
    releaseBuffer(&buffer1);
    releaseBuffer(&buffer2);
    releaseBuffer(&buffer3);
}

