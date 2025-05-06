// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


String createStringRemove(String string, String target) // allocates heap memory
{
    String empty = makeStringEmpty();
    
    return createStringReplace(string, target, empty);
}

String createStringRemoveLast(String string, String target) // allocates heap memory
{
    String empty = makeStringEmpty();
    
    return createStringReplaceLast(string, target, empty);
}

String createStringRemoveAll(String string, String target) // allocates heap memory
{
    String empty = makeStringEmpty();
    
    return createStringReplaceAll(string, target, empty);
}

