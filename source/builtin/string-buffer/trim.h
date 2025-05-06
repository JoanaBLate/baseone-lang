// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void stringBufferTrimStart(StringBuffer* sb)
{
    while (true)
    {
        if (sb->size == 0) { return; }
        
        if ((unsigned char) sb->address[sb->margin] > ' ') { return; }
        
        sb->margin += 1; sb->size -= 1;
    }
}

void stringBufferTrimEnd(StringBuffer* sb)
{
    while (true)
    {
        if (sb->size == 0) { return; }
        
        long index = sb->margin + sb->size - 1;
        
        if ((unsigned char) sb->address[index] > ' ') { return; }
    
        sb->size -= 1;          
    }
}

void stringBufferTrim(StringBuffer* sb)
{
    stringBufferTrimStart(sb);

    stringBufferTrimEnd(sb);
}

///////////////////////////////////////////////////////////////////////////////

void stringBufferTrimStartTarget(StringBuffer* sb, String target)
{
    while (true)
    {
        String virtual = makeStringFromStringBuffer(*sb);
        
        if (! stringStartsWith(virtual, target)) { return; }
        
        sb->margin += target.size; sb->size -= target.size;
    }
}

void stringBufferTrimEndTarget(StringBuffer* sb, String target)
{
    while (true)
    {
        String virtual = makeStringFromStringBuffer(*sb);
        
        if (! stringEndsWith(virtual, target)) { return; }
        
        sb->size -= target.size;
    }
}

void stringBufferTrimTarget(StringBuffer* sb, String target)
{
    stringBufferTrimStartTarget(sb, target);

    stringBufferTrimEndTarget(sb, target);
}


