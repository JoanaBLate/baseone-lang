// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

/*

HeapString newHeapString(long capacity)  
{
    HeapString bs = { 0 };
    
    bs.address = heapAllocate(capacity);
    
    bs.data = bs.address;
    
    bs.capacity = capacity;
    
    bs.isStack = false;
    
    return bs;
}

void releaseHeapString(HeapString bs)
{
    if (bs.isStack) { return; }
    
    heapRelease(bs.address);
}

void adjustHeapStringByString(HeapString bs, String string)
{
    if (string.data < bs.address  ||  string.data + string.size > bs.address + bs.capacity) 
    {
        printf("\nERROR: out of bounds in function 'adjustHeapStringByString'\n"); exit(1);
    }
    
    bs.data = string.data;
    bs.size = string.size;
}



String makePseudoStringFromHeapString(HeapString bs)
{
    return makeString(bs.data, bs.size);
}
*/
