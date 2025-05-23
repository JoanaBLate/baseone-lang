
The StringBuffer creating functions grants that the capacity is 1 or greater .

If the StringBuffer is created on the heap, its capacity expands automatically. 

If the StringBuffer is created on the stack, its capacity *cannot* expand.

Excepting the function 'stringBufferCharCodeAt', StringBuffer functions silently avoid 'index of out bounds' errors. (TODO: check all functions about that) 

Function 'stringBufferReverse' and 'stringBufferSort' corrupt runes like '∆'. (TODO: fix that)

