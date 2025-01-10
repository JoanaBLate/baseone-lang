// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testReadTextFile()
{
    printf("- testing readTextFile\n"); 
    
    String filename = { 9, "builtin.h" };        
    String file = readTextFile(&filename);
 // printString(&file);
    String string = createSubstring(&file, 1, 18);
    String expected = { 18, "// # Copyright (c)" };

    if (! stringsAreEqual(&expected, &string)) { 
        printf("readTextFile FAILS!\n"); 
        exit(1);
    }
}
