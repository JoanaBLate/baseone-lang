// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testStringBufferToLower()
{
    printf("- testing stringBufferToLower\n");
    
    bool fails = false;

    StringBuffer sbEmpty = createStringBufferEmpty();
        
    StringBuffer sbSource = createStringBufferFromLiteral("123Life is ∆ ROCK456");  

    sbSource.margin = 3; sbSource.size -= 6;
          
    stringBufferToLower(sbSource);
    
    String result1 = createStringFromStringBuffer(sbSource);
        
    String expected1 = createStringFromLiteral("life is ∆ rock");
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    stringBufferToLower(sbEmpty);
    
    String result2 = createStringFromStringBuffer(sbEmpty);
        
    String expected2 = makeStringEmpty("");
    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("stringBufferToLower FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(expected1);
    releaseString(result2);
    releaseStringBuffer(sbEmpty);
    releaseStringBuffer(sbSource);
}

void testStringBufferToUpper()
{
    printf("- testing stringBufferToUpper\n");
    
    bool fails = false;

    StringBuffer sbEmpty = createStringBufferEmpty();
        
    StringBuffer sbSource = createStringBufferFromLiteral("123Life is ∆ ROCK456");  

    sbSource.margin = 3; sbSource.size -= 6;
          
    stringBufferToUpper(sbSource);
    
    String result1 = createStringFromStringBuffer(sbSource);
        
    String expected1 = createStringFromLiteral("LIFE IS ∆ ROCK");
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    stringBufferToUpper(sbEmpty);
    
    String result2 = createStringFromStringBuffer(sbEmpty);
        
    String expected2 = makeStringEmpty("");
    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("stringBufferToUpper FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(expected1);
    releaseString(result2);
    releaseStringBuffer(sbEmpty);
    releaseStringBuffer(sbSource);
}

void testStringBufferToOppositeCase()
{
    printf("- testing stringBufferToOppositeCase\n");
    
    bool fails = false;

    StringBuffer sbEmpty = createStringBufferEmpty();
        
    StringBuffer sbSource = createStringBufferFromLiteral("123Life is ∆ ROCK456");  

    sbSource.margin = 3; sbSource.size -= 6;
          
    stringBufferToOppositeCase(sbSource);
    
    String result1 = createStringFromStringBuffer(sbSource);
        
    String expected1 = createStringFromLiteral("LIFE IS ∆ ROCK");
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    stringBufferToOppositeCase(sbEmpty);
    
    String result2 = createStringFromStringBuffer(sbEmpty);
        
    String expected2 = makeStringEmpty("");
    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("stringBufferToOppositeCase FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(expected1);
    releaseString(result2);
    releaseStringBuffer(sbEmpty);
    releaseStringBuffer(sbSource);
}

void testStringBufferReverse()
{
    printf("- testing stringBufferReverse\n");
    
    bool fails = false;

    StringBuffer sbEmpty = createStringBufferEmpty();
        
    StringBuffer sbSource = createStringBufferFromLiteral("123Life is ∆ rock456");  

    sbSource.margin = 3; sbSource.size -= 6;
          
    stringBufferReverse(sbSource);
    
    String result1 = createStringFromStringBuffer(sbSource);
        
    String expected1 = createStringFromLiteral("kcor \x86\x88\xe2 si efiL");
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    stringBufferReverse(sbEmpty);
    
    String result2 = createStringFromStringBuffer(sbEmpty);
        
    String expected2 = makeStringEmpty("");
    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("stringBufferReverse FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(expected1);
    releaseString(result2);
    releaseStringBuffer(sbEmpty);
    releaseStringBuffer(sbSource);
}

void testStringBufferSort()
{
    printf("- testing stringBufferSort\n");
    
    bool fails = false;

    StringBuffer sbEmpty = createStringBufferEmpty();
        
    StringBuffer sbSource = createStringBufferFromLiteral("123Life is ∆ rock456"); 

    sbSource.margin = 3; sbSource.size -= 6;   
      
    stringBufferSort(sbSource);
    
    String result1 = createStringFromStringBuffer(sbSource);
    
    String expected1 = createStringFromLiteral("\x86\x88\xe2   Lcefiikors"); 
    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
      
    stringBufferSort(sbEmpty);
    
    String result2 = createStringFromStringBuffer(sbEmpty);
    
    String expected2 = makeStringEmpty();    
    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    if (fails) { 
        printf("stringBufferSort FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(result2);
    releaseString(expected2);
}

