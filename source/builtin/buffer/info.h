// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


long getBufferCapacity(Buffer* buffer)
{        
    return buffer->capacity;
}

long getBufferMargin(Buffer* buffer)
{        
    return buffer->margin;
}

long getBufferSize(Buffer* buffer)
{        
    return buffer->size;
}

unsigned char bufferByteAt(Buffer* buffer, long index) // one base index
{ 
    if (index < 1  ||  index > buffer->size) 
    { 
        printf("\nERROR in function '@bufferByteAt': index (%li) out of bounds\n", index); exit(1);
    }   
    
    return (unsigned char) buffer->address[buffer->margin + index - 1];
}

bool buffersAreEqual(Buffer* bufferA, Buffer* bufferB) // just about the 'visible' part!
{
    String stringA = makeStringFromBuffer(bufferA); // virtual
    String stringB = makeStringFromBuffer(bufferB); // virtual
    
    return stringsAreEqual(&stringA, &stringB);
}

char buffersCompare(Buffer* bufferA, Buffer* bufferB)
{
    String stringA = makeStringFromBuffer(bufferA); // virtual
    String stringB = makeStringFromBuffer(bufferB); // virtual
    
    return stringsCompare(&stringA, &stringB);
}

bool bufferStartsWith(Buffer* buffer, String* target)
{  
    String string = makeStringFromBuffer(buffer); // virtual  
    
    return stringStartsWith(&string, target);
}

bool bufferEndsWith(Buffer* buffer, String* target)
{  
    String string = makeStringFromBuffer(buffer); // virtual  
    
    return stringEndsWith(&string, target);
}

long bufferIndexOf(Buffer* buffer, String* target) // one base index
{  
    String string = makeStringFromBuffer(buffer); // virtual  
    
    return stringIndexOf(&string, target);
}

long bufferIndexOfAfter(Buffer* buffer, String* target, long usedIndex) // one base index
{
    String string = makeStringFromBuffer(buffer); // virtual  
    
    return stringIndexOfAfter(&string, target, usedIndex);
}

long bufferLastIndexOf(Buffer* buffer, String* target) // one base index
{  
    String string = makeStringFromBuffer(buffer); // virtual  
    
    return stringLastIndexOf(&string, target);
}

long bufferLastIndexOfBefore(Buffer* buffer, String* target, long usedIndex) // one base index
{  
    String string = makeStringFromBuffer(buffer); // virtual  
    
    return stringLastIndexOfBefore(&string, target, usedIndex);
}

bool bufferContains(Buffer* buffer, String* target)
{    
    String string = makeStringFromBuffer(buffer); // virtual 
    
    return stringContains(&string, target);
}

bool bufferCountOf(Buffer* buffer, String* target)
{    
    String string = makeStringFromBuffer(buffer); // virtual 
    
    return stringCountOf(&string, target);
}

