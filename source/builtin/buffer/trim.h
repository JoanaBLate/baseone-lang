// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void bufferTrimStart(Buffer* buffer)
{
    while (true)
    {
        if (buffer->size == 0) { return; }
        
        if ((unsigned char) buffer->address[buffer->margin] > ' ') { return; }
        
        buffer->margin += 1; buffer->size -= 1;
    }
}

void bufferTrimEnd(Buffer* buffer)
{
    while (true)
    {
        if (buffer->size == 0) { return; }
        
        long index = buffer->margin + buffer->size - 1;
        
        if ((unsigned char) buffer->address[index] > ' ') { return; }
    
        buffer->size -= 1;          
    }
}

void bufferTrim(Buffer* buffer)
{
    bufferTrimStart(buffer);

    bufferTrimEnd(buffer);
}

///////////////////////////////////////////////////////////////////////////////

void bufferTrimStartTarget(Buffer* buffer, String target)
{
    while (true)
    {
        String virtual = makeStringFromBuffer(*buffer);
        
        if (! stringStartsWith(virtual, target)) { return; }
        
        buffer->margin += target.size; buffer->size -= target.size;
    }
}

void bufferTrimEndTarget(Buffer* buffer, String target)
{
    while (true)
    {
        String virtual = makeStringFromBuffer(*buffer);
        
        if (! stringEndsWith(virtual, target)) { return; }
        
        buffer->size -= target.size;
    }
}

void bufferTrimTarget(Buffer* buffer, String target)
{
    bufferTrimStartTarget(buffer, target);

    bufferTrimEndTarget(buffer, target);
}

///////////////////////////////////////////////////////////////////////////////

void bufferTrimStartAny(Buffer* buffer, String sample)
{
    while (buffer->size > 0)
    {
        char* bufferHead = buffer->address + buffer->margin;
        
        bool changed = false;
        
        for (int n = 0; n < sample.size; n++)
        {
            char c = sample.address[n];
            
            if (*bufferHead != c) { continue; }
        
            buffer->margin += 1; buffer->size -= 1; changed = true; break;
        }
        
        if (! changed) { return; }
    }
}

void bufferTrimEndAny(Buffer* buffer, String sample)
{
    while (buffer->size > 0)
    {
        char* bufferTail = buffer->address + buffer->margin + buffer->size - 1;
        
        bool changed = false;
        
        for (int n = 0; n < sample.size; n++)
        {
            char c = sample.address[n];
            
            if (*bufferTail != c) { continue; }
        
            buffer->size -= 1; changed = true; break;
        }
        
        if (! changed) { return; }
    }
}

void bufferTrimAny(Buffer* buffer, String sample)
{
    bufferTrimStartAny(buffer, sample);
    
    bufferTrimEndAny(buffer, sample);
}

