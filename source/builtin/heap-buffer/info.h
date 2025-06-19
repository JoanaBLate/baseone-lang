// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


long getHeapBufferCapacity(HeapBuffer hb)
{        
    return hb.capacity;
}

long getHeapBufferMargin(HeapBuffer hb)
{        
    return hb.margin;
}

long getHeapBufferSize(HeapBuffer hb)
{        
    return hb.size;
}

unsigned char heapBufferCharCodeAt(HeapBuffer hb, long index) // one base index
{ 
    if (index < 1  ||  index > hb.size) 
    { 
        printf("\nERROR in function '@heapBufferCharCodeAt': index (%li) out of bounds\n", index); exit(1);
    }   
    
    return (unsigned char) hb.address[hb.margin + index - 1];
}

bool heapBuffersAreEqual(HeapBuffer hbA, HeapBuffer hbB)
{
    String stringA = makeStringFromHeapBuffer(hbA); // virtual
    String stringB = makeStringFromHeapBuffer(hbB); // virtual
    
    return stringsAreEqual(stringA, stringB);
}

bool heapBufferStartsWith(HeapBuffer hb, String target)
{  
    String string = makeStringFromHeapBuffer(hb); // virtual  
    
    return stringStartsWith(string, target);
}

bool heapBufferEndsWith(HeapBuffer hb, String target)
{  
    String string = makeStringFromHeapBuffer(hb); // virtual  
    
    return stringEndsWith(string, target);
}

long heapBufferIndexOf(HeapBuffer hb, String target) // one base index
{  
    String string = makeStringFromHeapBuffer(hb); // virtual  
    
    return stringIndexOf(string, target);
}

long heapBufferIndexOfAfter(HeapBuffer hb, String target, long usedIndex) // one base index
{
    String string = makeStringFromHeapBuffer(hb); // virtual  
    
    return stringIndexOfAfter(string, target, usedIndex);
}

long heapBufferLastIndexOf(HeapBuffer hb, String target) // one base index
{  
    String string = makeStringFromHeapBuffer(hb); // virtual  
    
    return stringLastIndexOf(string, target);
}

long heapBufferLastIndexOfBefore(HeapBuffer hb, String target, long usedIndex) // one base index
{  
    String string = makeStringFromHeapBuffer(hb); // virtual  
    
    return stringLastIndexOfBefore(string, target, usedIndex);
}

bool heapBufferContains(HeapBuffer hb, String target)
{    
    String string = makeStringFromHeapBuffer(hb); // virtual 
    
    return stringContains(string, target);
}

bool heapBufferCountOf(HeapBuffer hb, String target)
{    
    String string = makeStringFromHeapBuffer(hb); // virtual 
    
    return stringCountOf(string, target);
}

