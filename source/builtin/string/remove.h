// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


String newStringRemove(String string, String target) // allocates memory (indirectly)
{
    String empty = makeStringEmpty();
    
    return newStringReplace(string, target, empty);
}

String newStringRemoveLast(String string, String target) // allocates memory (indirectly)
{
    String empty = makeStringEmpty();
    
    return newStringReplaceLast(string, target, empty);
}

String newStringRemoveAll(String string, String target) // allocates memory (indirectly)
{
    String empty = makeStringEmpty();
    
    return newStringReplaceAll(string, target, empty);
}

