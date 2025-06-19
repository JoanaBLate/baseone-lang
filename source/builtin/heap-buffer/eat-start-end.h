// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


String heapBufferEatStart(HeapBuffer* hb, long count)
{
    if (count < 1) { return makeStringEmpty(); }
    
    long size = count;
    
    if (size > hb->size) { size = hb->size; }
    
    String token = createStringFromSource(hb->address + hb->margin, size);
    
    hb->margin += size; hb->size -= size;
    
    return token;
}

String heapBufferEatEnd(HeapBuffer* hb, long count)
{
    if (count < 1) { return makeStringEmpty(); }
    
    long size = count;
    
    if (size > hb->size) { size = hb->size; }
    
    String token = createStringFromSource(hb->address + hb->margin + hb->size - size, size);
    
    hb->size -= size;
    
    return token;
}

