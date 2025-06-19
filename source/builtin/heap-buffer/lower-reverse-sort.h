// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


void heapBufferToLower(HeapBuffer hb)
{    
    long start = hb.margin;
    long off = hb.margin + hb.size;
    
    for (long index = start; index < off; index++)   
    {
        hb.address[index] = tolower(hb.address[index]);
    }    
}

void heapBufferToUpper(HeapBuffer hb)
{   
    long start = hb.margin;
    long off = hb.margin + hb.size;
     
    for (long index = start; index < off; index++)   
    {
        hb.address[index] = toupper(hb.address[index]);
    }    
}

void heapBufferToOppositeCase(HeapBuffer hb)
{
    long start = hb.margin;
    long off = hb.margin + hb.size;
    
    for (long index = start; index < off; index++)   
    {
        hb.address[index] = tolower(hb.address[index]);
    
        char c = hb.address[index];
        
        if (isupper(c)) 
        { 
            hb.address[index] = tolower(c);
        }
        else if (islower(c)) 
        { 
            hb.address[index] = toupper(c);
        }
    }
}

void heapBufferReverse(HeapBuffer hb)
{
    long halfLength = hb.size / 2;
     
    for (long position = 0; position < halfLength; position++) 
    {     
        long indexA = hb.margin + position;
        
        long indexB = hb.margin + (hb.size - 1 - position);
        
        char temp = hb.address[indexA];
        
        hb.address[indexA] = hb.address[indexB];
        
        hb.address[indexB] = temp;
    }
}

void heapBufferSort(HeapBuffer hb) // TODO: slow
{    
    for (long positionA = 0; positionA < hb.size - 1; positionA++) 
    { 
        for (long positionB = positionA + 1; positionB < hb.size; positionB++) 
        { 
            long indexA = hb.margin + positionA;
            
            long indexB = hb.margin + positionB;
            
            if (hb.address[indexA] <= hb.address[indexB]) { continue; }
            
            char temp = hb.address[indexA];
            
            hb.address[indexA] = hb.address[indexB];
            
            hb.address[indexB] = temp;
        }
    }
}

