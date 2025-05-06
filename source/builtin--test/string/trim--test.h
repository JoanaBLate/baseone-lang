// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testStringTrimStart()
{
    printf("- testing stringTrimStart\n");
    
    bool fails = false;

    String source1 = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   
    String expected1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆! \n ");
    String result1 = stringTrimStart(source1);
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String source2 = makeStringFromLiteral(" \n   \n ");   
    String expected2 = makeStringEmpty();
    String result2 = stringTrimStart(source2);
    if (! stringsAreEqual(result2, expected2)) { fails = true; }

    String source3 = makeStringFromLiteral("");
    String result3 = stringTrimStart(source3);    
    String expected3 = makeStringEmpty();    
    if (! stringsAreEqual(result3, expected3)) { fails = true; }    

    if (fails) { 
        printf("stringTrimStart FAILS!\n");
        exit(1);
    }
  
    releaseString(result1);
    releaseString(result2);
    releaseString(expected2);
    releaseString(result3);
    releaseString(expected3);
}

void testStringTrimEnd()
{
    printf("- testing stringTrimEnd\n");
    
    bool fails = false;

    String source1 = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   
    String expected1 = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆!");
    String result1 = stringTrimEnd(source1);
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String source2 = makeStringFromLiteral(" \n   \n ");   
    String expected2 = makeStringEmpty();
    String result2 = stringTrimEnd(source2);
    if (! stringsAreEqual(result2, expected2)) { fails = true; }

    String source3 = makeStringFromLiteral("");
    String result3 = stringTrimEnd(source3);    
    String expected3 = makeStringEmpty();    
    if (! stringsAreEqual(result3, expected3)) { fails = true; } 
    
    if (fails) { 
        printf("stringTrimEnd FAILS!\n");
        exit(1);
    }
  
    releaseString(result1);
    releaseString(result2);
    releaseString(expected2);
    releaseString(result3);
    releaseString(expected3);
}

void testStringTrim()
{
    printf("- testing stringTrim\n");
    
    bool fails = false;    

    String source1 = makeStringFromLiteral(" \n ∆!∆! Life is ∆ rock ∆!∆! \n ");   
    String expected1 = makeStringFromLiteral("∆!∆! Life is ∆ rock ∆!∆!");
    String result1 = stringTrim(source1);
    if (! stringsAreEqual(result1, expected1)) { fails = true; }
    
    String source2 = makeStringFromLiteral(" \n   \n ");   
    String expected2 = makeStringEmpty();
    String result2 = stringTrim(source2);
    if (! stringsAreEqual(result2, expected2)) { fails = true; }

    String source3 = makeStringFromLiteral("");
    String result3 = stringTrim(source3);    
    String expected3 = makeStringEmpty();    
    if (! stringsAreEqual(result3, expected3)) { fails = true; } 
    
    if (fails) { 
        printf("stringTrim FAILS!\n");
        exit(1);
    }
  
    releaseString(result1);
    releaseString(result2);
    releaseString(expected2);
    releaseString(result3);
    releaseString(expected3);
}

