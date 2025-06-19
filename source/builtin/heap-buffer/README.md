
The HeapBuffer creating functions grants that the capacity is 1 or greater .

If the HeapBuffer is created on the heap, its capacity expands automatically. 

If the HeapBuffer is created on the stack, its capacity *cannot* expand.

Excepting the function 'stringBufferCharCodeAt', HeapBuffer functions silently avoid 'index of out bounds' errors. 
(TODO: check all functions about that) 

Unicode characters like '∆' may be corrupted by these functions:
- 'stringBufferReverse' 
- 'stringBufferSort'
- 'stringBufferEatStart'
- 'stringBufferEatEnd' 
(TODO: create stringBufferReverseUnicode and stringBufferSortUnicode)

