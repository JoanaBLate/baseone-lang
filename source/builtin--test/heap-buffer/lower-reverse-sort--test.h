// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testHeapBufferToLower()
{
    printf("- testing heapBufferToLower\n");
    
    bool fails = false;

    HeapBuffer hbEmpty = createHeapBufferEmpty();
        
    HeapBuffer hbSource = createHeapBufferFromLiteral("123Life is ∆ ROCK456");  

    hbSource.margin = 3; hbSource.size -= 6;
          
    heapBufferToLower(hbSource);
    
    String result1 = createStringFromHeapBuffer(hbSource);
        
    String expected1 = createStringFromLiteral("life is ∆ rock");
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    heapBufferToLower(hbEmpty);
    
    String result2 = createStringFromHeapBuffer(hbEmpty);
        
    String expected2 = makeStringEmpty("");
    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("heapBufferToLower FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(expected1);
    releaseString(result2);
    releaseHeapBuffer(hbEmpty);
    releaseHeapBuffer(hbSource);
}

void testHeapBufferToUpper()
{
    printf("- testing heapBufferToUpper\n");
    
    bool fails = false;

    HeapBuffer hbEmpty = createHeapBufferEmpty();
        
    HeapBuffer hbSource = createHeapBufferFromLiteral("123Life is ∆ ROCK456");  

    hbSource.margin = 3; hbSource.size -= 6;
          
    heapBufferToUpper(hbSource);
    
    String result1 = createStringFromHeapBuffer(hbSource);
        
    String expected1 = createStringFromLiteral("LIFE IS ∆ ROCK");
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    heapBufferToUpper(hbEmpty);
    
    String result2 = createStringFromHeapBuffer(hbEmpty);
        
    String expected2 = makeStringEmpty("");
    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("heapBufferToUpper FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(expected1);
    releaseString(result2);
    releaseHeapBuffer(hbEmpty);
    releaseHeapBuffer(hbSource);
}

void testHeapBufferToOppositeCase()
{
    printf("- testing heapBufferToOppositeCase\n");
    
    bool fails = false;

    HeapBuffer hbEmpty = createHeapBufferEmpty();
        
    HeapBuffer hbSource = createHeapBufferFromLiteral("123Life is ∆ ROCK456");  

    hbSource.margin = 3; hbSource.size -= 6;
          
    heapBufferToOppositeCase(hbSource);
    
    String result1 = createStringFromHeapBuffer(hbSource);
        
    String expected1 = createStringFromLiteral("LIFE IS ∆ ROCK");
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    heapBufferToOppositeCase(hbEmpty);
    
    String result2 = createStringFromHeapBuffer(hbEmpty);
        
    String expected2 = makeStringEmpty("");
    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("heapBufferToOppositeCase FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(expected1);
    releaseString(result2);
    releaseHeapBuffer(hbEmpty);
    releaseHeapBuffer(hbSource);
}

void testHeapBufferReverse()
{
    printf("- testing heapBufferReverse\n");
    
    bool fails = false;

    HeapBuffer hbEmpty = createHeapBufferEmpty();
        
    HeapBuffer hbSource = createHeapBufferFromLiteral("123Life is ∆ rock456");  

    hbSource.margin = 3; hbSource.size -= 6;
          
    heapBufferReverse(hbSource);
    
    String result1 = createStringFromHeapBuffer(hbSource);
        
    String expected1 = createStringFromLiteral("kcor \x86\x88\xe2 si efiL");
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    heapBufferReverse(hbEmpty);
    
    String result2 = createStringFromHeapBuffer(hbEmpty);
        
    String expected2 = makeStringEmpty("");
    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("heapBufferReverse FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(expected1);
    releaseString(result2);
    releaseHeapBuffer(hbEmpty);
    releaseHeapBuffer(hbSource);
}

void testHeapBufferSort()
{
    printf("- testing heapBufferSort\n");
    
    bool fails = false;

    HeapBuffer hbEmpty = createHeapBufferEmpty();
        
    HeapBuffer hbSource = createHeapBufferFromLiteral("123Life is ∆ rock456"); 

    hbSource.margin = 3; hbSource.size -= 6;   
      
    heapBufferSort(hbSource);
    
    String result1 = createStringFromHeapBuffer(hbSource);
    
    String expected1 = makeStringFromLiteral("\x86\x88\xe2   Lcefiikors"); 
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
      
    heapBufferSort(hbEmpty);
    
    String result2 = createStringFromHeapBuffer(hbEmpty);
    
    String expected2 = makeStringEmpty();    
    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("heapBufferSort FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(result2);
    releaseString(expected2);
    releaseHeapBuffer(hbEmpty);
    releaseHeapBuffer(hbSource);
}

