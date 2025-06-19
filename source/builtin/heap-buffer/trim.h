// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void heapBufferTrimStart(HeapBuffer* hb)
{
    while (true)
    {
        if (hb->size == 0) { return; }
        
        if ((unsigned char) hb->address[hb->margin] > ' ') { return; }
        
        hb->margin += 1; hb->size -= 1;
    }
}

void heapBufferTrimEnd(HeapBuffer* hb)
{
    while (true)
    {
        if (hb->size == 0) { return; }
        
        long index = hb->margin + hb->size - 1;
        
        if ((unsigned char) hb->address[index] > ' ') { return; }
    
        hb->size -= 1;          
    }
}

void heapBufferTrim(HeapBuffer* hb)
{
    heapBufferTrimStart(hb);

    heapBufferTrimEnd(hb);
}

///////////////////////////////////////////////////////////////////////////////

void heapBufferTrimStartTarget(HeapBuffer* hb, String target)
{
    while (true)
    {
        String virtual = makeStringFromHeapBuffer(*hb);
        
        if (! stringStartsWith(virtual, target)) { return; }
        
        hb->margin += target.size; hb->size -= target.size;
    }
}

void heapBufferTrimEndTarget(HeapBuffer* hb, String target)
{
    while (true)
    {
        String virtual = makeStringFromHeapBuffer(*hb);
        
        if (! stringEndsWith(virtual, target)) { return; }
        
        hb->size -= target.size;
    }
}

void heapBufferTrimTarget(HeapBuffer* hb, String target)
{
    heapBufferTrimStartTarget(hb, target);

    heapBufferTrimEndTarget(hb, target);
}

///////////////////////////////////////////////////////////////////////////////

void heapBufferTrimStartAny(HeapBuffer* hb, String sample)
{
    while (hb->size > 0)
    {
        char* hbHead = hb->address + hb->margin;
        
        bool changed = false;
        
        for (int n = 0; n < sample.size; n++)
        {
            char c = sample.address[n];
            
            if (*hbHead != c) { continue; }
        
            hb->margin += 1; hb->size -= 1; changed = true; break;
        }
        
        if (! changed) { return; }
    }
}

void heapBufferTrimEndAny(HeapBuffer* hb, String sample)
{
    while (hb->size > 0)
    {
        char* hbTail = hb->address + hb->margin + hb->size - 1;
        
        bool changed = false;
        
        for (int n = 0; n < sample.size; n++)
        {
            char c = sample.address[n];
            
            if (*hbTail != c) { continue; }
        
            hb->size -= 1; changed = true; break;
        }
        
        if (! changed) { return; }
    }
}

void heapBufferTrimAny(HeapBuffer* hb, String sample)
{
    heapBufferTrimStartAny(hb, sample);
    
    heapBufferTrimEndAny(hb, sample);
}

