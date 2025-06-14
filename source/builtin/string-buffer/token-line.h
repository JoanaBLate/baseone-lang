// # Copyright (c) 2024 - 2025 Feudal Code Limitada - MIT license #


/*String stringEatLine(String* string)
{
    String result = makeStringEmpty();
    
    char* rAddress = NULL;
    char* nAddress = NULL;

    while (true)
    {
        if (string->size == 0) { string->data = NULL; break; }
        
        char c = string->data[0];
        
        if (c == '\r') { rAddress = string->data; }
        
        if (c == '\n') { nAddress = string->data; }
    
        string->data += 1; string->size -= 1;
        
        if (c == '\n') { break; }

        if (result.data == NULL) { result.data = string->data - 1; }
        
        result.size += 1;
    }
    
    if (rAddress == NULL) { return result; }
    if (nAddress == NULL) { return result; }
    
    if (rAddress + 1 != nAddress) { return result; }
    
    result.size -= 1; // removing '\r' at the end (that was windows EOL)
    
    if (result.size == 0) { result.data = NULL; }
    
    return result; 
}

String stringEatToken(String* string) // skips whitespaces, delivers anything else
{
    String result = makeStringEmpty();
   
    while (string->size != 0)
    {
         if (string->data[0] != ' ') { break; }
         
         string->data += 1; string->size -= 1;
    }
    
    if (string->size == 0) { string->data = NULL; return result; }
       
    result.data = string->data; result.size = 1;
         
    char first = (unsigned char) string->data[0];
    
    string->data += 1; string->size -= 1;
    
    if (string->size == 0) { string->data = NULL; return result; }
    
    if (first == '\r'  &&  string->data[0] == '\n') // windows EOL
    { 
        string->data += 1; string->size -= 1; if (string->size == 0) { string->data = NULL; }
        
        result.size += 1; return result;    
    }
    
    if (first < ' ') { return result; } // cannot be whitespace now    

    while (string->size != 0)
    {
         if (string->data[0] <= ' ') { break; }
         
         result.size += 1; 
         
         string->data += 1; string->size -= 1; 
    }
    
    if (string->size == 0) { string->data = NULL; }
    
    return result;
}
*/
