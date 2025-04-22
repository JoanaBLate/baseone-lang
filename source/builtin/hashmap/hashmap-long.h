// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


typedef struct
{
    String key;    
    long value;
    void* next; // linked item that has the same hashcode
} HashmapLongItem;

typedef struct
{
    long capacity;
    long count;
    HashmapLongItem** items;
} HashmapLong;

HashmapLongItem* newHashmapLongItem(String key, long value)
{
    HashmapLongItem* item = heapAllocate(sizeof(HashmapLongItem));

    item->key = newStringClone(key);
    
    item->value = value;
    
    item->next = NULL;
    
    return item;
}

HashmapLong* newHashmapLong(long capacity) 
{
    HashmapLong* map = heapAllocate(1 * sizeof(HashmapLong));
    
    map->capacity = capacity;
    
    map->count = 0;
    
    map->items = heapAllocateClean(capacity * sizeof(HashmapLongItem*));

    return map;
}

bool addItemToHashmapLongOrSetValue(HashmapLong* map, String key, long value) // returns true when makes new item
{
    long hashcode = makeHashCode(key, map->capacity);
    
    HashmapLongItem* item = map->items[hashcode];

    if (item == NULL) // ADDING new item directly to the items array
    {     
        map->items[hashcode] = newHashmapLongItem(key, value);
        
        map->count += 1;

        return true;
    }   
  
    if (stringsAreEqual(key, item->key)) { item->value = value; return false; } // SETTING item value
    
    while (true) // searching in the chain
    {    
        HashmapLongItem* nextItem = item->next;
    
        if (nextItem == NULL) { break; }
        
        if (stringsAreEqual(key, nextItem->key)) { nextItem->value = value; return false; } // SETTING item value
        
        item = nextItem;
    }
    
    // ADDING new item in the chain
    
    item->next = newHashmapLongItem(key, value);
    
    map->count += 1;
 
    return true;
}

HashmapLongItem* getItemFromHashmapLong(HashmapLong* map, String key)
{
    long hashcode = makeHashCode(key, map->capacity);
    
    HashmapLongItem* item = map->items[hashcode];

    if (item == NULL) { return NULL; }
        
    if (stringsAreEqual(key, item->key)) { return item; }
    
    while (true) // searching in the chain
    {    
        HashmapLongItem* nextItem = item->next;
    
        if (nextItem == NULL) { break; }
        
        if (stringsAreEqual(key, nextItem->key)) { return nextItem; }
        
        item = nextItem;
    }

    return NULL; 
}

bool deleteItemFromHashmapLong(HashmapLong* map, String key)
{
    long hashcode = makeHashCode(key, map->capacity);
    
    HashmapLongItem* item = map->items[hashcode];

    if (item == NULL) { return false; }
        
    if (stringsAreEqual(key, item->key)) 
    { 
        map->items[hashcode] = item->next;
        
        map->count -= 1;
        
        releaseString(item->key);
        
        heapRelease(item);
        
        return true;
    }
    
    while (true) // searching in the chain
    {    
        HashmapLongItem *nextItem = item->next;
    
        if (nextItem == NULL) { return false; }
        
        if (! stringsAreEqual(key, nextItem->key)) { item = nextItem; continue; }
        
        item->next = nextItem->next;
        
        map->count -= 1;
        
        releaseString(item->key);
        
        heapRelease(item);
        
        return true;
    } 
    
    return false; // unreachable
}

void deleteHashmapLong(HashmapLong* map)
{
    for (long mapIndex = 0; mapIndex < map->capacity; mapIndex++)
    {    
        HashmapLongItem* item = map->items[mapIndex];
        
        if (item == NULL) { continue; }
        
        HashmapLongItem* nextItem = item->next;
        
        releaseString(item->key);
        
        heapRelease(item);
        
        while (nextItem != NULL)
        {
            item = nextItem;
        
            nextItem = item->next;
            
            releaseString(item->key);
            
            heapRelease(item);
        }
    }
    
    heapRelease(map->items);
    
    heapRelease(map);
}

ArrayList* getHashmapLongKeys(HashmapLong* map)
{
    ArrayList* list = newArrayList(map->count);
        
    for (long mapIndex = 0; mapIndex < map->capacity; mapIndex++)
    {    
        HashmapLongItem* item = map->items[mapIndex];
        
        if (item == NULL) { continue; }
        
        arrayListInclude(list, &item->key);
        
        while (item->next != NULL)
        {
            item = item->next;
            
            arrayListInclude(list, &item->key);
        }
    }

    return list;
}
    
