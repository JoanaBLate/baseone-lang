
The data of a non literal String is stored on the heap. 

The data of a literal String is stored in the read only section (like in C).

All String functions that start with **createString** allocate heap memory. All other String functions don't.

Excepting the function 'stringCharCodeAt', String functions silently avoid 'index of out bounds' errors. 

Unicode characters like '∆' may be corrupted by these functions:
- 'stringTrim'
- 'stringTrimStart'
- 'stringTrimEnd'
- 'stringReverse' 
- 'stringSort'
- 'stringEatStart'
- 'stringEatEnd' 
- 'stringToLower'
- 'stringToUpper'
- 'stringToOppositeCase'
(TODO: create stringReverseUnicode, stringSortUnicode...)

