
#include "builtin.h"
#include "file/file--test.h"
#include "string/create--test.h"
#include "string/info--test.h"
#include "string/substr--test.h"
//#include "string/expand--test.h"
//#include "string/reduce--test.h"
//#include "string/same-size--test.h"
#include "string/print--test.h"

int main()
{
    fileTest();
    
    stringCreateTest(); 
    stringInfoTest();
    stringSubstrTest(); 
//    stringExpandTest(); 
//    stringReduceTest(); 
   
   
   // stringPrintTest(); 
        
    return 0;
}

