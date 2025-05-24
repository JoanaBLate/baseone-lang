// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


String stringBufferEatStart(StringBuffer* sb, long count)
{
    if (count < 1) { return makeStringEmpty(); }
    
    long size = count;
    
    if (size > sb->size) { size = sb->size; }
    
    String token = createStringFromSource(sb->address + sb->margin, size);
    
    sb->margin += size; sb->size -= size;
    
    return token;
}

String stringBufferEatEnd(StringBuffer* sb, long count)
{
    if (count < 1) { return makeStringEmpty(); }
    
    long size = count;
    
    if (size > sb->size) { size = sb->size; }
    
    String token = createStringFromSource(sb->address + sb->margin + sb->size - size, size);
    
    sb->size -= size;
    
    return token;
}

