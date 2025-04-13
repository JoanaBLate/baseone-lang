// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #

typedef struct
{
    String key;    
    String value;
    void *next; // linked item that has the same hashcode
} HashmapStringItem;

typedef struct
{
    long capacity;
    long count;
    HashmapStringItem **items;
} HashmapString;

HashmapStringItem *createHashmapStringItem(String *key, String *value)
{
    HashmapStringItem *item = allocateMemory(sizeof(HashmapStringItem));

    item->key = createStringClone(key);
    
    item->value = createStringClone(value);
    
    item->next = NULL;
    
    return item;
}

HashmapString createHashmapString(long capacity) 
{
    HashmapString map = { capacity, 0, NULL };
    
    map.items = calloc(capacity, sizeof(HashmapStringItem *));

    return map;
}

bool addItemToHashmapStringOrSetValue(HashmapString *map, String *key, String *value) // returns true when makes new item
{
    long hashcode = makeHashCode(key, map->capacity);
    
    HashmapStringItem *currentItem = map->items[hashcode];

    if (currentItem == NULL) // ADDING new item directly to the items array
    {     
        HashmapStringItem *newItem = createHashmapStringItem(key, value);

        map->items[hashcode] = newItem;
        
        map->count += 1;

        return true;
    }   
  
    if (stringsAreEqual(key, &currentItem->key)) { currentItem->value = createStringClone(value); return false; } // SETTING item value
    
    while (true) // searching in the chain
    {    
        HashmapStringItem *nextItem = currentItem->next;
    
        if (nextItem == NULL) { break; }
        
        if (stringsAreEqual(key, &nextItem->key)) { nextItem->value = createStringClone(value); return false; } // SETTING item value
        
        currentItem = nextItem;
    }
    
    // ADDING new item in the chain
    
    HashmapStringItem *newItem = createHashmapStringItem(key, value);
    
    currentItem->next = newItem;
    
    map->count += 1;
 
    return true;
}

HashmapStringItem *getItemFromHashmapString(HashmapString *map, String *key)
{
    long hashcode = makeHashCode(key, map->capacity);
    
    HashmapStringItem *currentItem = map->items[hashcode];

    if (currentItem == NULL) { return NULL; }
        
    if (stringsAreEqual(key, &currentItem->key)) { return currentItem; }
    
    while (true) // searching in the chain
    {    
        HashmapStringItem *nextItem = currentItem->next;
    
        if (nextItem == NULL) { break; }
        
        if (stringsAreEqual(key, &nextItem->key)) { return nextItem; }
        
        currentItem = nextItem;
    }

    return NULL; 
}

bool deleteItemFromHashmapString(HashmapString *map, String *key)
{
    long hashcode = makeHashCode(key, map->capacity);
    
    HashmapStringItem *currentItem = map->items[hashcode];

    if (currentItem == NULL) { return false; }
        
    if (stringsAreEqual(key, &currentItem->key)) 
    { 
        map->items[hashcode] = currentItem->next;
        
        map->count -= 1;
        
        return true;
    }
    
    while (true) // searching in the chain
    {    
        HashmapStringItem *nextItem = currentItem->next;
    
        if (nextItem == NULL) { break; }
        
        if (! stringsAreEqual(key, &nextItem->key)) { currentItem = nextItem; continue; }
        
        currentItem->next = nextItem->next;
        
        map->count -= 1;
        
        return true;
    } 
    
    return false;
}

