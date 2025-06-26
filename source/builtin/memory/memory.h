// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


// pointer must be unsigned long, because must be able to access all RAM bytes

void* heapAllocate(long size)
{
    if (size < 1) { return NULL; }
    
    unsigned long* address = malloc(size);
    
    if (address != NULL) { return address; }

    printf("\nERROR: failed to allocate %lu bytes in heap\n", size);
    
    exit(1);
}

void* heapAllocateClean(long size)
{
    if (size < 1) { return NULL; }
    
    unsigned long* address = calloc(1, size);
    
    if (address != NULL) { return address; }

    printf("\nERROR: failed to allocate %lu bytes in heap\n", size);
    
    exit(1);
}

void* heapReallocate(void* address, long size)
{
    if (size < 1) { return NULL; }
    
    unsigned long* newAddress = realloc(address, size);
    
    if (newAddress != NULL) { return newAddress; }

    printf("\nERROR: failed to allocate %lu bytes in heap\n", size);
    
    exit(1);
}

void heapRelease(void* pointer)
{
    if (pointer == NULL) { printf("\nERROR: trying to free NULL pointer\n"); exit(1); }

    free(pointer);
}

void validateString(String string)
{        
    if (string.address != NULL) { return; } // valid, non blank string
    
    if (string.size == 0) { return; } // empty string (not heap allocated)
    
    printf("\nERROR: trying to use already deallocated string\n");
    
    exit(1); 
}

void validateBuffer(Buffer buffer)
{        
    if (buffer.address != NULL) { return; }
    
    printf("\nERROR: trying to use already deallocated buffer\n");
    
    exit(1); 
}

void validateAddress(void* pointer)
{        
    if (pointer != NULL) { return; }
    
    printf("\nERROR: trying to use NULL pointer\n");
    
    exit(1); 
}

