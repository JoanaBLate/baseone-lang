// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void bufferRemove(Buffer* buffer, String target)
{
    String empty = makeStringEmpty();
    
    bufferReplace(buffer, target, empty);
}

void bufferRemoveLast(Buffer* buffer, String target)
{
    String empty = makeStringEmpty();
    
    bufferReplaceLast(buffer, target, empty);
}

void bufferRemoveAll(Buffer* buffer, String target)
{
    String empty = makeStringEmpty();
    
    bufferReplaceAll(buffer, target, empty);
}

