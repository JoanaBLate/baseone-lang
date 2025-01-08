
void testReadTextFile()
{
    struct String filename = { 9, "builtin.h" };        
    struct String file = readTextFile(&filename);
 // printString(&file);
    struct String string = createSubstring(&file, 1, 18);
    struct String expected = { 18, "\n#include <math.h>" };

    if (! stringsAreEqual(&expected, &string)) { 
        printf("testReadTextFile FAILS!\n"); 
        exit(1);
    }
}

void fileTest()
{
    printf("TESTING file\n");
    testReadTextFile();
}

