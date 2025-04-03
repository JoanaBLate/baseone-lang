// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testCreateStringEmpty() 
{    
    printf("- testing createStringEmpty\n");
    
    String result = createStringEmpty();
    String expected = { 0, "" };
    
    if (! stringsAreEqual(&expected, &result)) {
        printf("createStringEmpty FAILS!\n");
        exit(1);
    }
}

