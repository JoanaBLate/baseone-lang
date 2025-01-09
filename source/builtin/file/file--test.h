
void testReadTextFile()
{
    printf("- testing readTextFile\n"); 
    
    String filename = { 9, "builtin.h" };        
    String file = readTextFile(&filename);
 // printString(&file);
    String string = createSubstring(&file, 1, 18);
    String expected = { 18, "\n#include <math.h>" };

    if (! stringsAreEqual(&expected, &string)) { 
        printf("readTextFile FAILS!\n"); 
        exit(1);
    }
}
