// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

typedef struct
{
    String key;    
    long value;
    void *next; // linked item that has the same hashcode
} HashmapLongItem;

typedef struct
{
    long capacity;
    long count;
    HashmapLongItem **items;
} HashmapLong;

HashmapLongItem *createHashmapLongItem(String *key, long value)
{
    HashmapLongItem *item = allocateMemory(sizeof(HashmapLongItem));

    item->key = createStringClone(key);
    
    item->value = value;
    
    item->next = NULL;
    
    return item;
}

HashmapLong createHashmapLong(long capacity) 
{
    HashmapLong map = { capacity, 0, NULL };
    
    map.items = calloc(capacity, sizeof(HashmapLongItem *));

    return map;
}

bool addItemToHashmapLongOrSetValue(HashmapLong *map, String *key, long value) // returns true when makes new item
{
    long hashcode = makeHashCode(key, map->capacity);
    
    HashmapLongItem *currentItem = map->items[hashcode];

    if (currentItem == NULL) // ADDING new item directly to the items array
    {     
        HashmapLongItem *newItem = createHashmapLongItem(key, value);

        map->items[hashcode] = newItem;
        
        map->count += 1;

        return true;
    }   
  
    if (stringsAreEqual(key, &currentItem->key)) { currentItem->value = value; return false; } // SETTING item value
    
    while (true) // searching in the chain
    {    
        HashmapLongItem *nextItem = currentItem->next;
    
        if (nextItem == NULL) { break; }
        
        if (stringsAreEqual(key, &nextItem->key)) { nextItem->value = value; return false; } // SETTING item value
        
        currentItem = nextItem;
    }
    
    // ADDING new item in the chain
    
    HashmapLongItem *newItem = createHashmapLongItem(key, value);
    
    currentItem->next = newItem;
    
    map->count += 1;
 
    return true;
}

HashmapLongItem *getItemFromHashmapLong(HashmapLong *map, String *key)
{
    long hashcode = makeHashCode(key, map->capacity);
    
    HashmapLongItem *currentItem = map->items[hashcode];

    if (currentItem == NULL) { return NULL; }
        
    if (stringsAreEqual(key, &currentItem->key)) { return currentItem; }
    
    while (true) // searching in the chain
    {    
        HashmapLongItem *nextItem = currentItem->next;
    
        if (nextItem == NULL) { break; }
        
        if (stringsAreEqual(key, &nextItem->key)) { return nextItem; }
        
        currentItem = nextItem;
    }

    return NULL; 
}

bool deleteItemFromHashmapLong(HashmapLong *map, String *key)
{
    long hashcode = makeHashCode(key, map->capacity);
    
    HashmapLongItem *currentItem = map->items[hashcode];

    if (currentItem == NULL) { return false; }
        
    if (stringsAreEqual(key, &currentItem->key)) 
    { 
        map->items[hashcode] = currentItem->next;
        
        map->count -= 1;
        
        return true;
    }
    
    while (true) // searching in the chain
    {    
        HashmapLongItem *nextItem = currentItem->next;
    
        if (nextItem == NULL) { break; }
        
        if (! stringsAreEqual(key, &nextItem->key)) { currentItem = nextItem; continue; }
        
        currentItem->next = nextItem->next;
        
        map->count -= 1;
        
        return true;
    } 
    
    return false;
}

