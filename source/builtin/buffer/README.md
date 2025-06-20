
The Buffer creating functions grants that the capacity is 1 or greater .

The Buffer is always created on the heap. Its capacity expands automatically. 

Excepting the function 'bufferByteAt', Buffer functions silently avoid 'index of out bounds' errors. 
(TODO: check all functions about that) 

Unicode characters like '∆' may be corrupted by these functions:
- 'bufferTrim'
- 'bufferTrimStart'
- 'bufferTrimEnd'
- 'bufferReverse' 
- 'bufferSort'
- 'bufferEatStart'
- 'bufferEatEnd' 
- 'bufferToLower'
- 'bufferToUpper'
- 'bufferToOppositeCase'
(TODO: create bufferReverseUnicode, bufferSortUnicode...)

