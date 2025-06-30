// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void _testBufferPadStart(Buffer* buffer, String* chunk, long count, String* expected) 
{  
    bufferPadStart(buffer, chunk, count);    

    String result = makeStringFromBuffer(buffer);
       
    if (stringsAreEqual(&result, expected)) { return; }
    
    printf("bufferPadStart FAILS!\n"); exit(1);
}

void testBufferPadStart()
{
    printf("- testing bufferPadStart\n");
    
    Buffer buffer = createBufferFromLiteral("Life is ∆ rock");
    String chunk  = makeStringEmpty();
    String expected = makeStringFromLiteral("Life is ∆ rock");    
    _testBufferPadStart(&buffer, &chunk, 10, &expected);
    
    chunk = makeStringFromLiteral("(^-^) ");
    _testBufferPadStart(&buffer, &chunk, 0, &expected);
//    
//    expected = makeStringFromLiteral("(^-^) (^-^) Life is ∆ rock");
//    _testBufferPadStart(&buffer, chunk, 2, expected);
//    
//    releaseBuffer(&buffer);
//
//    buffer = createBufferFromLiteral("123456789012345Life is ∆ rock");
//    buffer.margin = 15;
//    buffer.size -= 15;
//    expected = makeStringFromLiteral("(^-^) (^-^) Life is ∆ rock");
//    _testBufferPadStart(&buffer, chunk, 2, expected);
     
    releaseBuffer(&buffer);

    buffer = createBufferFromLiteral("12Life is ∆ rock!");
    buffer.margin = 2;
    buffer.size -= 2;
    expected = makeStringFromLiteral("(^-^) (^-^) Life is ∆ rock!");
    _testBufferPadStart(&buffer, &chunk, 2, &expected);
    /*
    
    String empty =;    
   
    String result1 = bufferPadStart(source1, source2, 3);
    String expected1 = makeStringFromLiteral("(^-^) (^-^) (^-^) Life is ∆ rock");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String result2 = bufferPadStart(source1, empty, 3);
    String expected2 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    String result3 = bufferPadStart(empty, source2, 3);
    String expected3 = makeStringFromLiteral("(^-^) (^-^) (^-^) ");   
    if (! stringsAreEqual(result3, expected3)) { fails = true; }
    
    String result4 = bufferPadStart(source1, source2, -1);
    String expected4 = makeStringFromLiteral("Life is ∆ rock");   
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    String result5 = bufferPadStart(empty, empty, 3);
    String expected5 = makeStringEmpty();    
    if (! stringsAreEqual(result5, expected5)) { fails = true; }
    
    if (fails) { 
        printf("bufferPadStart FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(result2);
    releaseString(result3);
    releaseString(result4);
    */
    releaseBuffer(&buffer);
}   

void testBufferPadEnd()
{
/*
    printf("- testing bufferPadEnd\n");
    
    bool fails = false;

    String empty = makeStringEmpty();    
    String source1 = makeStringFromLiteral("Life is ∆ rock");   
    String source2 = makeStringFromLiteral(" (^-^)");
   
    String result1 = bufferPadEnd(source1, source2, 3);
    String expected1 = makeStringFromLiteral("Life is ∆ rock (^-^) (^-^) (^-^)");    
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String result2 = bufferPadEnd(source1, empty, 3);
    String expected2 = makeStringFromLiteral("Life is ∆ rock");    
    if (! stringsAreEqual(result2, expected2)) { fails = true; }
    
    String result3 = bufferPadEnd(empty, source2, 3);
    String expected3 = makeStringFromLiteral(" (^-^) (^-^) (^-^)");   
    if (! stringsAreEqual(result3, expected3)) { fails = true; }  
    
    String result4 = bufferPadEnd(source1, source2, -1);
    String expected4 = makeStringFromLiteral("Life is ∆ rock");   
    if (! stringsAreEqual(result4, expected4)) { fails = true; }
    
    String result5 = bufferPadEnd(empty, empty, 3);
    String expected5 = makeStringEmpty();    
    if (! stringsAreEqual(result5, expected5)) { fails = true; }
    
    if (fails) { 
        printf("bufferPadEnd FAILS!\n");
        exit(1);
    }
    
    releaseString(result1);
    releaseString(result2);
    releaseString(result3);
    releaseString(result4);
    releaseString(result5);
    releaseString(expected5);
*/
}

