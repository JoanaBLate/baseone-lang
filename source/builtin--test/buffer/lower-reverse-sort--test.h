// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testBufferToLower()
{
    printf("- testing bufferToLower\n");
    
    bool fails = false;

    Buffer bufferEmpty = createBufferEmpty();
        
    Buffer bufferSource = createBufferFromLiteral("123Life is ∆ ROCK456");  

    bufferSource.margin = 3; bufferSource.size -= 6;
          
    bufferToLower(bufferSource);
    
    String result1 = createStringFromBuffer(bufferSource);
        
    String expected1 = createStringFromLiteral("life is ∆ rock");
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    bufferToLower(bufferEmpty);
    
    String result2 = createStringFromBuffer(bufferEmpty);
        
    String expected2 = makeStringEmpty("");
    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("bufferToLower FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(expected1);
    releaseString(result2);
    releaseBuffer(bufferEmpty);
    releaseBuffer(bufferSource);
}

void testBufferToUpper()
{
    printf("- testing bufferToUpper\n");
    
    bool fails = false;

    Buffer bufferEmpty = createBufferEmpty();
        
    Buffer bufferSource = createBufferFromLiteral("123Life is ∆ ROCK456");  

    bufferSource.margin = 3; bufferSource.size -= 6;
          
    bufferToUpper(bufferSource);
    
    String result1 = createStringFromBuffer(bufferSource);
        
    String expected1 = createStringFromLiteral("LIFE IS ∆ ROCK");
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    bufferToUpper(bufferEmpty);
    
    String result2 = createStringFromBuffer(bufferEmpty);
        
    String expected2 = makeStringEmpty("");
    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("bufferToUpper FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(expected1);
    releaseString(result2);
    releaseBuffer(bufferEmpty);
    releaseBuffer(bufferSource);
}

void testBufferToOppositeCase()
{
    printf("- testing bufferToOppositeCase\n");
    
    bool fails = false;

    Buffer bufferEmpty = createBufferEmpty();
        
    Buffer bufferSource = createBufferFromLiteral("123Life is ∆ ROCK456");  

    bufferSource.margin = 3; bufferSource.size -= 6;
          
    bufferToOppositeCase(bufferSource);
    
    String result1 = createStringFromBuffer(bufferSource);
        
    String expected1 = createStringFromLiteral("LIFE IS ∆ ROCK");
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    bufferToOppositeCase(bufferEmpty);
    
    String result2 = createStringFromBuffer(bufferEmpty);
        
    String expected2 = makeStringEmpty("");
    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("bufferToOppositeCase FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(expected1);
    releaseString(result2);
    releaseBuffer(bufferEmpty);
    releaseBuffer(bufferSource);
}

void testBufferReverse()
{
    printf("- testing bufferReverse\n");
    
    bool fails = false;

    Buffer bufferEmpty = createBufferEmpty();
        
    Buffer bufferSource = createBufferFromLiteral("123Life is ∆ rock456");  

    bufferSource.margin = 3; bufferSource.size -= 6;
          
    bufferReverse(bufferSource);
    
    String result1 = createStringFromBuffer(bufferSource);
        
    String expected1 = createStringFromLiteral("kcor \x86\x88\xe2 si efiL");
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    bufferReverse(bufferEmpty);
    
    String result2 = createStringFromBuffer(bufferEmpty);
        
    String expected2 = makeStringEmpty("");
    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("bufferReverse FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(expected1);
    releaseString(result2);
    releaseBuffer(bufferEmpty);
    releaseBuffer(bufferSource);
}

void testBufferSort()
{
    printf("- testing bufferSort\n");
    
    bool fails = false;

    Buffer bufferEmpty = createBufferEmpty();
        
    Buffer bufferSource = createBufferFromLiteral("123Life is ∆ rock456"); 

    bufferSource.margin = 3; bufferSource.size -= 6;   
      
    bufferSort(bufferSource);
    
    String result1 = createStringFromBuffer(bufferSource);
    
    String expected1 = makeStringFromLiteral("\x86\x88\xe2   Lcefiikors"); 
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
      
    bufferSort(bufferEmpty);
    
    String result2 = createStringFromBuffer(bufferEmpty);
    
    String expected2 = makeStringEmpty();    
    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("bufferSort FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(result2);
    releaseString(expected2);
    releaseBuffer(bufferEmpty);
    releaseBuffer(bufferSource);
}

