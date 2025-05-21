// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void stringBufferToLower(StringBuffer sb)
{    
    long start = sb.margin;
    long off = sb.margin + sb.size;
    
    for (long index = start; index < off; index++)   
    {
        sb.address[index] = tolower(sb.address[index]);
    }    
}

void stringBufferToUpper(StringBuffer sb)
{   
    long start = sb.margin;
    long off = sb.margin + sb.size;
     
    for (long index = start; index < off; index++)   
    {
        sb.address[index] = toupper(sb.address[index]);
    }    
}

void stringBufferToOppositeCase(StringBuffer sb)
{
    long start = sb.margin;
    long off = sb.margin + sb.size;
    
    for (long index = start; index < off; index++)   
    {
        sb.address[index] = tolower(sb.address[index]);
    
        char c = sb.address[index];
        
        if (isupper(c)) 
        { 
            sb.address[index] = tolower(c);
        }
        else if (islower(c)) 
        { 
            sb.address[index] = toupper(c);
        }
    }
}

void stringBufferReverse(StringBuffer sb)
{
    long halfLength = sb.size / 2;
     
    for (long position = 0; position < halfLength; position++) 
    {     
        long indexA = sb.margin + position;
        
        long indexB = sb.margin + (sb.size - 1 - position);
        
        char temp = sb.address[indexA];
        
        sb.address[indexA] = sb.address[indexB];
        
        sb.address[indexB] = temp;
    }
}

void stringBufferSort(StringBuffer sb) // TODO: slow
{    
    for (long positionA = 0; positionA < sb.size - 1; positionA++) 
    { 
        for (long positionB = positionA + 1; positionB < sb.size; positionB++) 
        { 
            long indexA = sb.margin + positionA;
            
            long indexB = sb.margin + positionB;
            
            if (sb.address[indexA] <= sb.address[indexB]) { continue; }
            
            char temp = sb.address[indexA];
            
            sb.address[indexA] = sb.address[indexB];
            
            sb.address[indexB] = temp;
        }
    }
}

