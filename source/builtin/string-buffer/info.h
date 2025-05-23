// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


long getStringBufferCapacity(StringBuffer sb)
{        
    return sb.capacity;
}

long getStringBufferMargin(StringBuffer sb)
{        
    return sb.margin;
}

long getStringBufferSize(StringBuffer sb)
{        
    return sb.size;
}

unsigned char stringBufferCharCodeAt(StringBuffer sb, long index) // one base index
{ 
    if (index < 1  ||  index > sb.size) 
    { 
        printf("\nERROR in function '@stringBufferCharCodeAt': index (%li) out of bounds\n", index); exit(1);
    }   
    
    return (unsigned char) sb.address[sb.margin + index - 1];
}

bool stringBuffersAreEqual(StringBuffer sbA, StringBuffer sbB)
{
    String stringA = makeStringFromStringBuffer(sbA); // virtual
    String stringB = makeStringFromStringBuffer(sbB); // virtual
    
    return stringsAreEqual(stringA, stringB);
}

bool stringBufferStartsWith(StringBuffer sb, String target)
{  
    String string = makeStringFromStringBuffer(sb); // virtual  
    
    return stringStartsWith(string, target);
}

bool stringBufferEndsWith(StringBuffer sb, String target)
{  
    String string = makeStringFromStringBuffer(sb); // virtual  
    
    return stringEndsWith(string, target);
}

long stringBufferIndexOf(StringBuffer sb, String target) // one base index
{  
    String string = makeStringFromStringBuffer(sb); // virtual  
    
    return stringIndexOf(string, target);
}

long stringBufferIndexOfAfter(StringBuffer sb, String target, long usedIndex) // one base index
{
    String string = makeStringFromStringBuffer(sb); // virtual  
    
    return stringIndexOfAfter(string, target, usedIndex);
}

long stringBufferLastIndexOf(StringBuffer sb, String target) // one base index
{  
    String string = makeStringFromStringBuffer(sb); // virtual  
    
    return stringLastIndexOf(string, target);
}

long stringBufferLastIndexOfBefore(StringBuffer sb, String target, long usedIndex) // one base index
{  
    String string = makeStringFromStringBuffer(sb); // virtual  
    
    return stringLastIndexOfBefore(string, target, usedIndex);
}

bool stringBufferContains(StringBuffer sb, String target)
{    
    String string = makeStringFromStringBuffer(sb); // virtual 
    
    return stringContains(string, target);
}

bool stringBufferCountOf(StringBuffer sb, String target)
{    
    String string = makeStringFromStringBuffer(sb); // virtual 
    
    return stringCountOf(string, target);
}

