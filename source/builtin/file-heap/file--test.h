// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

void testReadTextFileHeap()
{
    printf("- testing readTextFileHeap\n"); 
    
    String filename = { 9, "builtin.h" };        
    String file = readTextFileHeap(&filename);
 // printString(&file);
    String string = createStringSubHeap(&file, 1, 18);
    String expected = { 18, "// # Copyright (c)" };

    if (! stringsAreEqual(&expected, &string)) { 
        printf("readTextFileHeap FAILS!\n"); 
        exit(1);
    }
}
