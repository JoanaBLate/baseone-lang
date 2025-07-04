// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void _testStringParseLong(String* string, long expected, bool isNull) 
{
    NullLong obj = stringParseLong(string);
    
    if (obj.isNull == isNull  &&  obj.value == expected) { return; }
    
    printf("stringParseLong FAILS!\n"); exit(1);
}

void testStringParseLong() 
{
    printf("- testing stringParseLong\n"); 
    
    String string = makeStringFromLiteral("He@llo");
    _testStringParseLong(&string, 0, true); 
    
    string = makeStringFromLiteral("");
    _testStringParseLong(&string, 0, true); 
    
    string = makeStringFromLiteral("- 67");
    _testStringParseLong(&string, 0, true); 
    
    string = makeStringFromLiteral("56");
    _testStringParseLong(&string, 56, false);
    
    string = makeStringFromLiteral("+66");
    _testStringParseLong(&string, 66, false);
     
    string = makeStringFromLiteral("+666");
    _testStringParseLong(&string, 666, false);
     
    string = makeStringFromLiteral("+666r");
    _testStringParseLong(&string, 666, false); 

    string = makeStringFromLiteral("-67");
    _testStringParseLong(&string, -67, false);
    
    string = makeStringFromLiteral("--67");
    _testStringParseLong(&string, 0, true); 
}

