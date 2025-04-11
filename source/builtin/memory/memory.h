// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

// pointer must be unsigned long, because must be able to access all RAM bytes

void *allocateMemory(unsigned long size)
{
    unsigned long *address = malloc(size);
    
    if (address != NULL) { return address; }

    printf("\nERROR: failed to allocate %lu bytes in heap\n", size);
    
    exit(1);
}
