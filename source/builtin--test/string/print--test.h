// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testPrintStringA() 
{
    String empty = makeStringEmpty(); 
     
    printf("\n- printing empty string: ");
    printString(&empty);
    printf("\n");
    
    printf("- printing empty string bytes: ");
    printStringBytes(&empty);
    printf("\n");
    
    printf("- printing empty string runes: ");
    printStringRunes(&empty);
    printf("\n");
}

void testPrintStringB()
{
 // char data[] = { 226, 136, 134, 32, 226, 136, 135, 32, 240, 159, 154, 128 }; // gets pedantic warnings
 // String string = { 12, data };

    String string = makeStringFromLiteral("\xe2\x88\x86 \xe2\x88\x87 \xf0\x9f\x9a\x80");
     
    printf("\n- printing string: ");
    printString(&string);
    printf("\n");
    
    printf("- printing string bytes: ");
    printStringBytes(&string);
    printf("\n");
    
    printf("- printing string runes: ");
    printStringRunes(&string);
    printf("\n");
}

void testPrintStringC()
{
    String string = makeStringFromLiteral("\x7f\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\x8c\x8d\x8e\x8f\x90\x91\x92\x93\x94\x95\x96\x97\x98\x99\x9a\x9b\x9c\x9d\x9e\x9f ¡¢£¤¥¦§¨©ª«¬­®¯°±²³´µ¶·¸¹º»¼½¾¿ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒ\x81\x82ÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþÿ\x83"); 
     
    printf("\n- printing string: ");
    printString(&string);
    printf("\n");
    
    printf("- printing string bytes: ");
    printStringBytes(&string);
    printf("\n");
    
    printf("- printing string runes: ");
    printStringRunes(&string);
    printf("\n\n");
}

