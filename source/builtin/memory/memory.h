
void *memoryAllocate(size_t size)
{
    size_t *address = malloc(size);
    
    if (address != NULL) { return address; }

    printf("\nERROR: failed to allocate %lu bytes in heap\n", size);
    
    exit(1);
}
