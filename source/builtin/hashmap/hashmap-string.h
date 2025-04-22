// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


typedef struct
{
    String key;    
    String value;
    void* next; // linked item that has the same hashcode
} HashmapStringItem;

typedef struct
{
    long capacity;
    long count;
    HashmapStringItem** items;
} HashmapString;

HashmapStringItem* newHashmapStringItem(String key, String value)
{
    HashmapStringItem* item = heapAllocate(sizeof(HashmapStringItem));

    item->key = newStringClone(key);
    
    item->value = newStringClone(value);
    
    item->next = NULL;
    
    return item;
}

HashmapString* newHashmapString(long capacity) 
{
    HashmapString* map = heapAllocate(1 * sizeof(HashmapString));
    
    map->capacity = capacity;
    
    map->count = 0;
    
    map->items = heapAllocateClean(capacity * sizeof(HashmapStringItem*));

    return map;
}

bool addItemToHashmapStringOrSetValue(HashmapString* map, String key, String value) // returns true when makes new item
{
    long hashcode = makeHashCode(key, map->capacity);
    
    HashmapStringItem* item = map->items[hashcode];

    if (item == NULL) // ADDING new item directly to the items array
    {     
        map->items[hashcode] = newHashmapStringItem(key, value);
        
        map->count += 1;

        return true;
    }   
  
    if (stringsAreEqual(key, item->key)) { item->value = newStringClone(value); return false; } // SETTING item value
    
    while (true) // searching in the chain
    {    
        HashmapStringItem* nextItem = item->next;
    
        if (nextItem == NULL) { break; }
        
        if (stringsAreEqual(key, nextItem->key)) { nextItem->value = newStringClone(value); return false; } // SETTING item value
        
        item = nextItem;
    }
    
    // ADDING new item in the chain
    
    item->next = newHashmapStringItem(key, value);
    
    map->count += 1;
 
    return true;
}

HashmapStringItem* getItemFromHashmapString(HashmapString* map, String key)
{
    long hashcode = makeHashCode(key, map->capacity);
    
    HashmapStringItem* item = map->items[hashcode];

    if (item == NULL) { return NULL; }
        
    if (stringsAreEqual(key, item->key)) { return item; }
    
    while (true) // searching in the chain
    {    
        HashmapStringItem* nextItem = item->next;
    
        if (nextItem == NULL) { break; }
        
        if (stringsAreEqual(key, nextItem->key)) { return nextItem; }
        
        item = nextItem;
    }

    return NULL; 
}

bool deleteItemFromHashmapString(HashmapString* map, String key)
{
    long hashcode = makeHashCode(key, map->capacity);
    
    HashmapStringItem* item = map->items[hashcode];

    if (item == NULL) { return false; }
        
    if (stringsAreEqual(key, item->key)) 
    { 
        map->items[hashcode] = item->next;
        
        map->count -= 1;
        
        releaseString(item->key);
        releaseString(item->value);
        
        heapRelease(item);
        
        return true;
    }
    
    while (true) // searching in the chain
    {    
        HashmapStringItem *nextItem = item->next;
    
        if (nextItem == NULL) { return false; }
        
        if (! stringsAreEqual(key, nextItem->key)) { item = nextItem; continue; }
        
        item->next = nextItem->next;
        
        map->count -= 1;
        
        releaseString(item->key);
        releaseString(item->value);
        
        heapRelease(item);
        
        return true;
    } 
    
    return false; // unreachable
}

void deleteHashmapString(HashmapString* map)
{
    for (long mapIndex = 0; mapIndex < map->capacity; mapIndex++)
    {    
        HashmapStringItem* item = map->items[mapIndex];
        
        if (item == NULL) { continue; }
        
        HashmapStringItem* nextItem = item->next;
        
        releaseString(item->key);
        releaseString(item->value);
        
        heapRelease(item);
        
        while (nextItem != NULL)
        {
            item = nextItem;
        
            nextItem = item->next;
            
            releaseString(item->key);
            releaseString(item->value);
            
            heapRelease(item);
        }
    }
    
    heapRelease(map->items);
    
    heapRelease(map);
}

ArrayList* getHashmapStringKeys(HashmapString* map)
{
    ArrayList* list = newArrayList(map->count);
        
    for (long mapIndex = 0; mapIndex < map->capacity; mapIndex++)
    {    
        HashmapStringItem* item = map->items[mapIndex];
        
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

