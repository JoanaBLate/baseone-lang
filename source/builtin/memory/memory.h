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

void heapRelease(void* pointer)
{
    free(pointer);
}

