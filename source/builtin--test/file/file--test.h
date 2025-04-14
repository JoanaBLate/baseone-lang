// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void testReadTextFile()
{
    printf("- testing readTextFile\n"); 
    
    String* filename = makeStringFromLiteral("../builtin/builtin.h");        
    String* file = readTextFile(filename);

    String* string = stringSlice(file, 1, 18);
    String* expected = makeStringFromLiteral("// # Copyright (c)");

    if (! stringsAreEqual(expected, string)) { 
        printf("readTextFile FAILS!\n"); 
        exit(1);
    }
}
